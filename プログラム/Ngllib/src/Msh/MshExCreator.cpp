/*******************************************************************************/
/**
 * @file MshExCreator.cpp.
 * 
 * @brief Msh msh,mshex形式メッシュファイル作成クラスソースファイル.
 *
 * @date 2008/10/11.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Msh/MshExCreator.h"
#include	"Ngl/Mesh.h"
#include	"Ngl/FileInputC.h"
#include	"Ngl/Manipulator.h"
#include	"Ngl/Utility.h"
#include	"Ngl/Vector4.h"
#include	<cassert>

using namespace Ngl;
using namespace Ngl::Msh;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] renderer レンダラー.
 */
MshExCreator::MshExCreator( IRenderer* renderer ):
	renderer_( renderer ),
	textureCreator_( 0 ),
	hasMatrixIndices_( false ),
	hasTextureSpace_( false ),
	numMaterials_( 0 ),
	numFaceGroups_( 0 ),
	numVertices_( 0 ),
	numIndices_( 0 ),
	numWeights_( 0 )
{
	// メッシュ書き込みフラグを初期化
	std::memset( meshFlag, NOTWRITTEN, sizeof( unsigned int ) * MESHFLAG_MAX );
}

	
	
/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
MshExCreator::~MshExCreator()
{
	delete textureCreator_;
}

	
	
/*=========================================================================*/
/**
 * @brief ファイルから作成する
 * 
 * @param[in] fileName ファイル名.
 * @return 作成したメッシュクラス.
 */
IMesh* MshExCreator::createFromFile( std::string fileName )
{
	// ファイルを開く
	FileInputC stream;
	try{
		stream.open( fileName.c_str() );
	}
	catch( FileOpenException& e ){
		e += "[MshExCreator] : [createFromFile]";
		e.outputConsol();
	}

	// 入力ストリームから作成
	return createFromStream( stream );
}



/*=========================================================================*/
/**
 * @brief 入力ストリームから作成する
 * 
 * @param[in] stream 入力ストリーム.
 * @return 作成したメッシュクラス.
 */
IMesh* MshExCreator::createFromStream( IInputStream& stream )
{
	// メッシュデータを作成
	Mesh* mesh = new Mesh( renderer_ );

	try{
		// メッシュデータを読み込む
		loadMeshData( stream );
		
		// マテリアルデータを読み込む
		loadMaterial( stream, mesh );

		// 面データを読み込む
		loadFaceGroup( stream, mesh );

		// インデックスデータを読み込む
		IBuffer* index = loadIndices( stream );
		mesh->setIndexBuffer( index );

		// 頂点データを読み込む
		if( meshFlag[ MESHFLAGTYPE_VERTEX ] == WRITTEN ){
			IBuffer* vertex = loadVertexBuffer( stream, 3 );
			mesh->setBuffer( vertex, STREAM_TYPE_VERTEX );
		}

		// 法線ベクトルデータを読み込む
		if( meshFlag[ MESHFLAGTYPE_NORMAL ] == WRITTEN ){
			IBuffer* normal = loadVertexBuffer( stream, 3 );
			mesh->setBuffer( normal, STREAM_TYPE_NORMAL );
		}

		// 拡散反射光カラー配列の読み込み
		if( meshFlag[ MESHFLAGTYPE_DIFFUSECOLORS ] == WRITTEN ){
			IBuffer* diffuse = loadVertexBuffer( stream, 4 );
			mesh->setBuffer( diffuse, STREAM_TYPE_DIFFUSE );
		}

		// 鏡面反射光カラー配列の読み込み
		if( meshFlag[ MESHFLAGTYPE_SPECULARCOLORS ] == WRITTEN ){
			IBuffer* specular = loadVertexBuffer( stream, 4 );
			mesh->setBuffer( specular, STREAM_TYPE_SPECULAR );
		}
		
		// テクスチャ座標データを読み込む
		if( meshFlag[ MESHFLAGTYPE_NUMTEXCOORDS ] != 0 ){
			IBuffer* texcoord = loadVertexBuffer( stream, 2 );
			mesh->setBuffer( texcoord, STREAM_TYPE_TEXCOORD );
		}

		// 頂点ウェイトデータがあるか
		if( hasMatrixIndices_ == true ){
			// 頂点ウェイトデータを読み込む
			IBuffer* blendWeights = loadVertexWeight( stream );
			mesh->setBuffer( blendWeights, STREAM_TYPE_BLENDWEIGHT );
		}

		// スキン情報があるか
		if( meshFlag[ MESHFLAGTYPE_MATRIXINDICES ] == WRITTEN ){
			// マトリクスインデックスデータを読み込む
			IBuffer* matrixIndices = loadMatrixIndex( stream );
			mesh->setBuffer( matrixIndices, STREAM_TYPE_MATRIXINDEX );
		}

		// テクスチャ座標系情報があるか
		if( hasTextureSpace_ == true ){
			// 接ベクトルデータを読み込む
			IBuffer* tangent = loadVertexBuffer( stream, 3 );
			mesh->setBuffer( tangent, STREAM_TYPE_TANGENT );

			// 従法線ベクトルデータを読み込む
			IBuffer* binormal = loadVertexBuffer( stream,  3 );
			mesh->setBuffer( binormal, STREAM_TYPE_BINORMAL );
		}

		// 頂点フォーマットを設定
		setVertexFormat( mesh );

		// 衝突判定データを作成
		mesh->createCollisionData();
	}
	catch( InputStreamException& e ){
		delete mesh;
		mesh = 0;

		e.add( "MshExCreator", "createFormStream" );
		e.outputConsol();
	}

	return mesh;
}



/*=========================================================================*/
/**
 * @brief テクスチャ作成クラスを設定
 * 
 * @warning 設定したクラスはMshExCreatorクラスで削除されます.
 *
 * @param[in] creator テクスチャ作成クラスのポインタ.
 * @return なし.
 */
void MshExCreator::setTextureCreator( ITextureCreator* creator )
{
	delete textureCreator_;

	textureCreator_ = creator;
}

	
	
/*=========================================================================*/
/**
 * @brief メッシュデータを読み込む
 * 
 * @param[in] stream 入力ストリーム.
 * @return なし.
 */
void MshExCreator::loadMeshData( IInputStream& stream )
{
	try{
		// メッシュ情報フラグを読み込む
		unsigned int meshInfo = 0;
		stream >> meshInfo;

		// メッシュフラグ数の読み込み
		unsigned int meshFlagCount = 0;
		stream >> meshFlagCount;

		// メッシュフラグの読み込み
		for( unsigned int i=0; i<meshFlagCount; ++i ){
			stream >> meshFlag[ i ];
		}

		// 頂点ウェイト数を抜き出す
		numWeights_ = meshFlag[ MESHFLAGTYPE_NUMWEIGHTS ];

		// テクスチャ座標系データが存在しているか
		if( meshFlag[ MESHFLAGTYPE_TEXTURESPACE ] == WRITTEN ){
			hasTextureSpace_ = true;
		}
		
		// 行列インデックスデータがあるか
		if( meshFlag[ MESHFLAGTYPE_MATRIXINDICES ] == WRITTEN ){
			hasMatrixIndices_ = true;
		}

		// マテリアルデータ数の読み込み
		stream >> numMaterials_;

		// 面データグループ数の読み込み
		stream >> numFaceGroups_;

		// 頂点インデックスデータ数の読み込み
		stream >> numIndices_;

		// 頂点座標データ数の読み込み
		stream >> numVertices_;
	}
	catch( InputStreamException& e ){
		throw e;
	}
}

	
	
/*=========================================================================*/
/**
 * @brief マテリアルデータを読み込む
 * 
 * @param[in] stream 入力ストリーム.
 * @param[in] mesh メッシュ.
 * @return なし.
 */
void MshExCreator::loadMaterial( IInputStream& stream, Mesh* mesh )
{
	for( unsigned int i=0; i<numMaterials_; ++i ){
		MeshMaterial* mat = new MeshMaterial;
		
		// 面情報フラグを読み込む
		unsigned int bMaterial = 0;
		stream >> bMaterial;

		// 環境光カラーを読み込む
		stream >> Color4Input( mat->material.ambient );

		// 拡散反射光カラーを読み込む
		stream >> Color4Input( mat->material.diffuse );

		// 鏡面反射光カラーを読み込む
		stream >> Color4Input( mat->material.specular );

		// 放射光カラーを読み込む
		stream >> Color4Input( mat->material.emissive );

		// 鏡面反射率の読み込み
		stream >> mat->material.power;

		// テクスチャが張られているか
		if( ( bMaterial & TEXTUREMAPPED ) != 0 ){
			// テクスチャファイルを読み込む
			std::string fileName;
			stream >> fileName;

			// ファイルパスを分解する
			std::string texFileNamePass;
			std::string drive	= Utility::getFilePathDrave( stream.streamName().c_str() );
			std::string dir		= Utility::getFilePathDir( stream.streamName().c_str() );

			// ファイルパスに連結
			texFileNamePass = drive + dir;

			// ファイル名に連結
			fileName = texFileNamePass + fileName;

			// テクスチャを生成
			assert( textureCreator_ != NULL );
			textureCreator_->setRenderer( renderer_ );
			mat->texture = textureCreator_->create( fileName );
			assert( mat->texture != NULL );

			// ミップマップを作成
			renderer_->generateMipmap( mat->texture );
	
			mat->hasTexture = true;
		}

		// 作成したマテリアルを設定
		mesh->setMaterial( mat );
	}
}



/*=========================================================================*/
/**
 * @brief 面データを読み込む
 * 
 * @param[in] stream 入力ストリーム.
 * @param[in] mesh メッシュ.
 * @return なし.
 */
void MshExCreator::loadFaceGroup( IInputStream& stream, Mesh* mesh )
{
	for( unsigned int i=0; i<numFaceGroups_; ++i ){
		FaceGroup* facegroup = new FaceGroup;

		// 面情報フラグの読み込み
		stream >> facegroup->faceInfo;

		// マテリアルインデックスの読み込み
		stream >> facegroup->materialNo;

		// 頂点インデックスの開始位置の読み込み
		stream >> facegroup->startIndices;

		// 頂点インデックス数の読み込み
		stream >> facegroup->numIndices;

		// 面データを登録
		mesh->setFaceGroup( facegroup );
	}
}



/*=========================================================================*/
/**
 * @brief インデックスデータを読み込む
 * 
 * @param[in] stream 入力ストリーム.
 * @return 作成したバッファ.
 */
IBuffer* MshExCreator::loadIndices( IInputStream& stream )
{
	std::vector< unsigned short > indices;

	// インデックスデータを読み込む
	for( unsigned int i=0; i<numIndices_; ++i ){
		unsigned short ent = 0;
		stream >> ent;
		indices.push_back( ent );
	}

	// インデックスバッファの作成
	BufferDesc indexBufferDesc;
	indexBufferDesc.type		= BUFFER_TYPE_INDEX;
	indexBufferDesc.size		= sizeof( unsigned short ) * (unsigned int)indices.size();
	indexBufferDesc.usage		= BUFFER_USAGE_DEFAULT;

	IBuffer* tmp = renderer_->createBuffer( indexBufferDesc, &indices[ 0 ] );
	assert( tmp != NULL );

	return tmp;
}



/*=========================================================================*/
/**
 * @brief 頂点データを読み込む
 * 
 * @param[in] stream 入力ストリーム.
 * @param[in] numElements 1要素の要素数.
 * @return 作成したバッファ.
 */
IBuffer* MshExCreator::loadVertexBuffer( IInputStream& stream, unsigned int numElements )
{
	std::vector< float > vertices;
	
	// 頂点データを読み込む
	for( unsigned int i=0; i<numVertices_ * numElements; i++ ){
		float ent = 0.0f;
		stream >> ent;
		vertices.push_back( ent );
	}

	// 頂点バッファを作成
	BufferDesc vertexBufferDesc;
	vertexBufferDesc.type		= BUFFER_TYPE_VERTEX;
	vertexBufferDesc.size		= sizeof( float ) * (unsigned int)vertices.size();
	vertexBufferDesc.usage		= BUFFER_USAGE_DEFAULT;

	IBuffer* tmp  = renderer_->createBuffer( vertexBufferDesc, &vertices[ 0 ] ); 
	assert( tmp != NULL );

	return tmp;
}



/*=========================================================================*/
/**
 * @brief 頂点ウェイトデータを読み込む
 * 
 * @param[in] stream 入力ストリーム.
 * @return 作成したバッファ.
 */
IBuffer* MshExCreator::loadVertexWeight( IInputStream& stream )
{
	// 末尾用ウェイト配列を作成
	float* fWeights = new float[ numVertices_ ];
	std::memset( fWeights, 1, sizeof( float ) * numVertices_ );

	// ファイルからデータを読み込む
	Vector4* blendWeights = new Vector4[ numVertices_ ];
	for( unsigned int i=0; i<numWeights_; ++i ){
		for( unsigned int j=0; j<numVertices_; ++j ){
			float* tmp = (float*)blendWeights[ j ];
			float weight = 0.0f;
			stream >> weight;

			tmp[ i ] = weight;
			fWeights[ j ] += weight;
		}
	}

	// 末尾のウェイト値を設定
	for( unsigned int i=0; i<numVertices_; ++i ){
		float* tmp = (float*)blendWeights[ i ];
		tmp[ numWeights_ ] = 1.0f - fWeights[ i ];
	}

	// バッファデータを作成する
	BufferDesc vertexBufferDesc;
	vertexBufferDesc.type		= BUFFER_TYPE_VERTEX;
	vertexBufferDesc.size		= sizeof( Vector4 ) * numVertices_;
	vertexBufferDesc.usage		= BUFFER_USAGE_DEFAULT;
	IBuffer* tmp = renderer_->createBuffer( vertexBufferDesc, blendWeights );

	// 作成した頂点ウェイト配列の消滅
	delete[] blendWeights;

	// 末尾用ウェイト配列を削除
	delete[] fWeights;

	assert( tmp != NULL );
	return tmp;
}



/*=========================================================================*/
/**
 * @brief マトリクスインデックスデータを読み込む
 * 
 * @param[in] stream 入力ストリーム.
 * @return 作成したバッファ.
 */
IBuffer* MshExCreator::loadMatrixIndex( IInputStream& stream )
{
	// ファイルからデータを読み込む
	Vector4* indexData = new Vector4[ numVertices_ ];
	for( unsigned int i=0; i<numVertices_; ++i ){
		float* tmp = (float*)indexData[ i ];
		unsigned int j=0;

		// データを読み込む
		unsigned int index=0;
		stream >> Ngl::hex >> index;
		stream.readType( STREAM_READ_TYPE_10 );
		
		// マトリクスインデックスを取り出す
		for( j=0; j<numWeights_; ++j ){
			tmp[ j ] = static_cast< float >( ( index >> ( j*8 ) ) & 0xff );
		}
		tmp[ numWeights_ ] = static_cast< float >( ( index >> ( j*8 ) ) & 0xff );
	}

	// バッファデータを作成する
	BufferDesc vertexBufferDesc;
	vertexBufferDesc.type		= BUFFER_TYPE_VERTEX;
	vertexBufferDesc.size		= sizeof( Vector4 ) * numVertices_;
	vertexBufferDesc.usage		= BUFFER_USAGE_DEFAULT;
	IBuffer* tmp = renderer_->createBuffer( vertexBufferDesc, indexData );
	
	// 展開データを削除
	delete[] indexData;

	assert( tmp != NULL );
	return tmp;
}



/*=========================================================================*/
/**
 * @brief 頂点フォーマットを設定
 * 
 * @param[in] mesh メッシュ.
 * @return なし.
 */
void MshExCreator::setVertexFormat( Mesh* mesh )
{
	// 頂点フォーマット
	Mesh::VertexFormat vertexFormat = {
		numVertices_,		// 頂点データ数
		numIndices_,		// インデックスデータ数
		numWeights_,		// 頂点ウェイト数
		hasMatrixIndices_,	// 行列インデックスデータを持っているか
		hasTextureSpace_	// テクスチャ座標系データを持っているか
	};

	mesh->setVertexFormat( vertexFormat );
}

	
	
/*===== EOF ==================================================================*/