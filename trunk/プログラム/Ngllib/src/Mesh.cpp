/*******************************************************************************/
/**
 * @file Mesh.cpp.
 * 
 * @brief メッシュクラスソースファイル.
 *
 * @date 2008/10/09.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Mesh.h"
#include	"Ngl/FileInputC.h"
#include	"Ngl/Manipulator.h"
#include	"Ngl/Utility.h"
#include	"Ngl/Vector4.h"
#include	<cassert>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] renderer レンダラー.
 */
Mesh::Mesh( IRenderer* renderer ):
	renderer_( renderer ),
	meshInfo_( 0 ),
	indexBuffer_( 0 ),
	vertexDeclaration_( 0 )
{
	// 初期値を作成
	bufferList_[ STREAM_TYPE_VERTEX	]		= 0;
	bufferList_[ STREAM_TYPE_NORMAL	]		= 0;
	bufferList_[ STREAM_TYPE_DIFFUSE ]		= 0;
	bufferList_[ STREAM_TYPE_SPECULAR ]		= 0;
	bufferList_[ STREAM_TYPE_TEXCOORD ]		= 0;
	bufferList_[ STREAM_TYPE_BLENDWEIGHT ]	= 0;
	bufferList_[ STREAM_TYPE_MATRIXINDEX ]	= 0;
	bufferList_[ STREAM_TYPE_TANGENT ]		= 0;
	bufferList_[ STREAM_TYPE_BINORMAL ]		= 0;
}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
Mesh::~Mesh()
{
	release();
}



/*=========================================================================*/
/**
 * @brief 頂点フォーマットを設定
 * 
 * @param[in] format 頂点フォーマット構造体.
 * @return なし.
 */
void Mesh::setVertexFormat( const VertexFormat& format )
{
	info_.numVertices		= format.numVertices;
	info_.numIndices		= format.numIndices;
	info_.numWeights		= format.numWeights;
	info_.hasTextureSpace	= format.hasTextureSpace;
	info_.hasMatrixIndices	= format.hasMatrixIndices;
}
	
	
	
/*=========================================================================*/
/**
 * @brief バッファデータを設定
 * 
 * @warning 設定したバッファはMeshクラスで削除されます。
 *
 * @param[in] buf 設定するバッファのポインタ.
 * @param[in] type 設定するバッファのストリームタイプ.
 * @return なし.
 */
void Mesh::setBuffer( IBuffer* buf, StreamType type )
{
	assert( buf != 0 );

	if( bufferList_[ type ] != 0 ){
		delete bufferList_[ type ];
	}

	bufferList_[ type ] = buf;
}

	
	
/*=========================================================================*/
/**
 * @brief インデックスバッファデータを設定
 * 
 * @warning 設定したバッファはMeshクラスで削除されます。
 *
 * @param[in] buf 設定するバッファのポインタ.
 * @return なし.
 */
void Mesh::setIndexBuffer( IBuffer* buf )
{
	assert( buf != 0 );

	if( indexBuffer_ != 0 ){
		delete indexBuffer_;
	}

	indexBuffer_ = buf;
}
	
	
	
/*=========================================================================*/
/**
 * @brief マテリアルデータを設定
 * 
 * Meshクラスに設定した順番で、マテリアル番号が自動的に設定されます。
 *
 * @warning 設定したマテリアルはMeshクラスで削除されます。
 * @warning テクスチャが設定されていた場合は、ともに削除されます。
 *
 * @param[in] material 設定するマテリアルのポインタ.
 * @return なし.
 */
void Mesh::setMaterial( MeshMaterial* material )
{
	materialArray_.push_back( material );

	// テクスチャを持っているか
	if( material->hasTexture == true ){
		info_.hasTexture = true;
	}

	// マテリアル数をカウント
	++info_.numMaterials;
}



/*=========================================================================*/
/**
 * @brief 面データグループを設定
 * 
 * Meshクラスに設定した順番で、面データグループ番号が自動的に設定されます。
 *
 * @warning 設定した面データグループはMeshクラスで削除されます。
 *
 * @param[in] face 設定する面データグループのポインタ.
 * @return なし.
 */
void Mesh::setFaceGroup( FaceGroup* face )
{
	faceGroupArray_.push_back( face );

	// 面データグループ数をカウント
	++info_.numSubsets;
}

	
	
/*=========================================================================*/
/**
 * @brief 衝突判定データを作成する
 *
 * 設定されている頂点バッファとインデックスバッファから衝突判定データを作成します。
 * どちらかのバッファが設定されていない場合は、作成されません。
 *
 * @param[in] なし.
 * @return なし.
 */
void Mesh::createCollisionData()
{
	assert( bufferList_[ STREAM_TYPE_VERTEX ] != 0 && indexBuffer_ != 0 );

	// メッシュ衝突判定データを作成
	collision_.create( info_, bufferList_[ STREAM_TYPE_VERTEX ], indexBuffer_ );
}
	
	
	
/*=========================================================================*/
/**
 * @brief 解放処理
 * 
 * @param[in] なし.
 * @return なし.
 */
void Mesh::release()
{
	// 頂点宣言データを削除
	delete vertexDeclaration_;

	// 面データを配列を削除
	FaceGroupArray::iterator itor = faceGroupArray_.begin();
	while( itor != faceGroupArray_.end() ){
		delete *itor;
		itor = faceGroupArray_.erase( itor );
	}

	// マテリアルデータを配列を削除
	MaterialArray::iterator matItor = materialArray_.begin();
	while( matItor != materialArray_.end() ){
		// テクスチャが張られているか
		if( (*matItor)->hasTexture == true ){
			// テクスチャを削除
			delete (*matItor)->texture;
		}
		delete *matItor;
		matItor = materialArray_.erase( matItor );
	}

	// バッファリストを削除
	BufferList::iterator bufItor = bufferList_.begin();
	while( bufItor != bufferList_.end() )
	{
		delete bufItor->second;
		bufItor = bufferList_.erase( bufItor );
	}

	// インデックスバッファを削除
	delete indexBuffer_;
}
	
	
	
/*=========================================================================*/
/**
 * @brief 描画処理
 * 
 * @param[in] effect エフェクトのポインタ.
 * @return なし.
 */
void Mesh::draw( IEffect* effect )
{	
	// 面データを描画する
	for( unsigned int face=0; face<info_.numSubsets; ++face ){
		// サブセットを描画する
		drawSubset( face, effect );
	}
}



/*=========================================================================*/
/**
 * @brief サブセットを描画
 * 
 * @param[in] faceNo 面データ番号.
 * @param[in] effect エフェクト.
 * @return なし.
 */
void Mesh::drawSubset( unsigned int faceNo, IEffect* effect )
{
	assert( effect != 0 );
	
	// 頂点ストリームを設定
	renderer_->setVertexBuffer( &streamDescArray_[ 0 ], (unsigned int)streamDescArray_.size() );
	
	// 頂点宣言データを設定
	renderer_->setVertexDeclaration( vertexDeclaration_ );

	// インデックスバッファの設定
	renderer_->setIndexBuffer( indexBuffer_, INDEX_TYPE_USHORT );

	// マテリアル番号を取得
	int matNo = faceGroupArray_[ faceNo ]->materialNo;

	// マテリアルデータをエフェクトに出力する
	if( effectOutputDesc().isOutMaterial == true ){
		effect->setVector( effectOutputDesc_.matAmbientName.c_str(), materialArray_[ matNo ]->material.ambient.r, materialArray_[ matNo ]->material.ambient.g, materialArray_[ matNo ]->material.ambient.b, materialArray_[ matNo ]->material.ambient.a );
		effect->setVector( effectOutputDesc_.matDiffuseName.c_str(), materialArray_[ matNo ]->material.diffuse.r, materialArray_[ matNo ]->material.diffuse.g, materialArray_[ matNo ]->material.diffuse.b, materialArray_[ matNo ]->material.diffuse.a );
		effect->setVector( effectOutputDesc_.matSpecularName.c_str(), materialArray_[ matNo ]->material.specular.r, materialArray_[ matNo ]->material.specular.g, materialArray_[ matNo ]->material.specular.b, materialArray_[ matNo ]->material.specular.a );
		effect->setVector( effectOutputDesc_.matEmissiveName.c_str(), materialArray_[ matNo ]->material.emissive.r, materialArray_[ matNo ]->material.emissive.g, materialArray_[ matNo ]->material.emissive.b, materialArray_[ matNo ]->material.emissive.a );
		effect->setScalar( effectOutputDesc_.matShininessName.c_str(), materialArray_[ matNo ]->material.power );
	}

	// テクスチャをエフェクトに出力する
	if( materialArray_[ matNo ]->hasTexture == true && effectOutputDesc().isOutTexture == true ){
		effect->setTexture( effectOutputDesc_.textureName.c_str(), materialArray_[ matNo ]->texture );
	}

	// パスの回数分レンダリング
	for( int pass=0; pass<effect->getNumPass(); ++pass ){
		// エフェクトを開始する
		effect->begin( pass );

		// 頂点インデックスを利用して描画
		renderer_->setPrimitive( PRIMITIVE_TYPE_TRIANGLE_LIST );
		renderer_->drawIndexed( faceGroupArray_[ faceNo ]->numIndices, faceGroupArray_[ faceNo ]->startIndices );

		// エフェクトの終了
		effect->end();
	}
}

	

/*=========================================================================*/
/**
 * @brief メッシュ情報を取得
 * 
 * @param[in] なし.
 * @return メッシュ情報構造体.
 */
const MeshInfo& Mesh::info() const
{
	return info_;
}



/*=========================================================================*/
/**
 * @brief エフェクト出力記述子を取得
 * 
 * @param[in] なし.
 * @return エフェクト出力記述子.
 */
const EffectOutputDesc& Mesh::effectOutputDesc() const
{
	return effectOutputDesc_;
}



/*=========================================================================*/
/**
 * @brief エフェクト出力記述子を設定
 * 
 * @param[in] desc エフェクト出力記述子.
 * @return なし.
 */
void Mesh::effectOutputDesc( const EffectOutputDesc& desc )
{
	effectOutputDesc_ = desc;
}

	
	
/*=========================================================================*/
/**
 * @brief 指定面データを取得する
 *
 * @param[in] faceNo 取得する面データ番号.
 * @return 面データ構造体.
 */
const FaceGroup& Mesh::getFaceGroups( unsigned int faceNo )
{
	return *faceGroupArray_[ faceNo ];
}



/*=========================================================================*/
/**
 * @brief 指定メッシュマテリアルデータを取得する
 *
 * @param[in] matNo 取得するメッシュマテリアル番号.
 * @return メッシュマテリアル構造体.
 */
const MeshMaterial& Mesh::getMaterial( unsigned int matNo )
{
	return *materialArray_[ matNo ];
}
	
	
	
/*=========================================================================*/
/**
 * @brief インデックスバッファを取得
 * 
 * @param[in] なし.
 * @return インデックスバッファポインタ.
 */
IBuffer* Mesh::getIndexBuffer()
{
	return indexBuffer_;
}



/*=========================================================================*/
/**
 * @brief 頂点バッファを取得
 * 
 * @param[in] stream 取得するバッファの種類.
 * @return 頂点バッファポインタ.
 */
IBuffer* Mesh::getVertexBuffer( StreamType stream )
{
	return bufferList_[ stream ];
}

	
	
/*=========================================================================*/
/**
 * @brief 頂点宣言データを作成
 * 
 * @param[in] inputSignature 入力シグネチャ記述子の参照.
 * @return なし.
 */
void Mesh::setVertexDeclaration( const InputSignatureDesc& inputSignature )
{
	// 頂点宣言データがすでに存在するか
	if( vertexDeclaration_ != 0 ){
		delete vertexDeclaration_;
	}

	// ストリームタイプ配列を設定
	setStreamType();

	// レイアウトデータを作成する
	std::vector< VertexDeclarationDesc > layout;	// 頂点レイアウト
	for( unsigned int streamNo=0; streamNo<streamTypeArray_.size(); ++streamNo ){
		StreamType type = streamTypeArray_[ streamNo ];
		VertexDeclarationDesc decl = { getSemantic( type ), 0, getType( type ), 0, streamNo };
		
		// データを設定
		layout.push_back( decl );
	}

	// 頂点宣言データを作成する
	vertexDeclaration_ = renderer_->createVertexDeclaration( &layout[ 0 ], (unsigned int)layout.size(), inputSignature );
	assert( vertexDeclaration_ != 0 );

	// 頂点ストリームを設定
	setVertexStream();
}



/*===========================================================================*/
/**
 * @brief 線分との衝突判定
 * 
 * @param[in] line0 線分の始点.
 * @param[in] line1 線分の終点.
 * @return 衝突結果構造体の参照.
 */
const PlaneCollisionReport& Mesh::collisionLine( const float* line0, const float* line1 )
{
	return collision_.line( line0, line1 );
}

	
	
/*===========================================================================*/
/**
 * @brief 指定の面データグループと線分との衝突判定
 * 
 * @param[in] faceNo 面データグループ番号.
 * @param[in] line0 線分の始点.
 * @param[in] line1 線分の終点.
 * @return 衝突結果構造体の参照.
 */
const PlaneCollisionReport& Mesh::collisionFaceAndLine( int faceNo, const float* line0, const float* line1 )
{
	// 開始ポリゴンデータ番号を求める
	int planeNo = faceGroupArray_[ faceNo ]->startIndices / 3; 

	// ポリゴンと線分の衝突判定
	for( unsigned int i=0; i<faceGroupArray_[ faceNo ]->numIndices/3; ++i ){
		const PlaneCollisionReport& report = collision_.polygonAndLine( planeNo, line0, line1 );
		if( report.isCollision == true ){
			return report;
		}

		// ポリゴンデータ番号を更新
		planeNo++;
	}

	return PLANECOLLISIONREPORT_NOT_COLLISION;
}

	
	
/*===========================================================================*/
/**
 * @brief 3D線との衝突判定
 * 
 * @param[in] rayPos 3D線の始点座標.
 * @param[in] rayDir 3D線の方向.
 * @return 面データ衝突パラメーター.
 */
const PlaneCollisionReport& Mesh::collisionRay( const float* rayPos, const float* rayDir )
{
	return collision_.ray( rayPos, rayDir );
}



/*===========================================================================*/
/**
 * @brief 指定の面データグループと3D線との衝突判定
 * 
 * @param[in] faceNo 面データグループ番号.
 * @param[in] rayPos 3D線の始点座標.
 * @param[in] rayDir 3D線の方向.
 * @return 面データ衝突パラメーター.
 */
const PlaneCollisionReport& Mesh::collisionFaceAndRay( int faceNo, const float* rayPos, const float* rayDir )
{
	// 開始ポリゴンデータ番号を求める
	int planeNo = faceGroupArray_[ faceNo ]->startIndices / 3; 

	// ポリゴンと線分の衝突判定
	for( unsigned int i=0; i<faceGroupArray_[ faceNo ]->numIndices/3; ++i ){
		const PlaneCollisionReport& report = collision_.polygonAndRay( planeNo, rayPos, rayDir );
		if( report.isCollision == true ){
			return report;
		}

		// ポリゴンデータ番号を更新
		planeNo++;
	}

	return PLANECOLLISIONREPORT_NOT_COLLISION;
}

	
	
/*===========================================================================*/
/**
 * @brief 球体との衝突判定
 * 
 * @param[in] center 球体の中心位置.
 * @param[in] radius 球体の半径.
 * @return 面データ衝突パラメーター.
 */
const PlaneCollisionReport& Mesh::collisionSphere( const float* center, float radius )
{
	return collision_.sphere( center, radius );
}



/*===========================================================================*/
/**
 * @brief 指定の面データグループと球体との衝突判定
 * 
 * @param[in] faceNo 面データグループ番号.
 * @param[in] center 球体の中心位置.
 * @param[in] radius 球体の半径.
 * @return 面データ衝突パラメーター.
 */
const PlaneCollisionReport& Mesh::collisionFaceAndSphere( int faceNo, const float* center, float radius )
{
	// 開始ポリゴンデータ番号を求める
	int planeNo = faceGroupArray_[ faceNo ]->startIndices / 3; 

	// ポリゴンと線分の衝突判定
	for( unsigned int i=0; i<faceGroupArray_[ faceNo ]->numIndices/3; ++i ){
		const PlaneCollisionReport& report = collision_.polygonAndSphere( planeNo, center, radius );
		if( report.isCollision == true ){
			return report;
		}

		// ポリゴンデータ番号を更新
		planeNo++;
	}

	return PLANECOLLISIONREPORT_NOT_COLLISION;
}

	

/*=========================================================================*/
/**
 * @brief 頂点ストリームデータを設定
 * 
 * @param[in] なし.
 * @return なし.
 */
void Mesh::setVertexStream()
{
	// 以前のデータを削除
	streamDescArray_.clear();

	IBuffer* buffers[] = {		// バッファのポインタ配列
		bufferList_[ STREAM_TYPE_VERTEX	],			// STREAM_TYPE_VERTEX		= 0,
		bufferList_[ STREAM_TYPE_NORMAL	],			// STREAM_TYPE_NORMAL		= 1,
		bufferList_[ STREAM_TYPE_DIFFUSE ],			// STREAM_TYPE_DIFFUSE		= 2,
		bufferList_[ STREAM_TYPE_SPECULAR ],		// STREAM_TYPE_SPECULAR		= 3,
		bufferList_[ STREAM_TYPE_TEXCOORD ],		// STREAM_TYPE_TEXCOORD		= 4,
		bufferList_[ STREAM_TYPE_BLENDWEIGHT ],		// STREAM_TYPE_BLENDWEIGHT	= 5,
		bufferList_[ STREAM_TYPE_MATRIXINDEX ],		// STREAM_TYPE_MATRIXINDEX	= 6,
		bufferList_[ STREAM_TYPE_TANGENT ],			// STREAM_TYPE_TANGENT		= 7,
		bufferList_[ STREAM_TYPE_BINORMAL ]			// STREAM_TYPE_BINORMAL		= 8
	};

	// ストリームを設定
	VertexStreamDesc streamDesc;
	for( unsigned int streamNo=0; streamNo<streamTypeArray_.size(); ++streamNo ){
		streamDesc.buffer	= buffers[ streamTypeArray_[ streamNo ] ];
		streamDesc.offset	= 0;
		streamDesc.stride	= getStride( streamTypeArray_[ streamNo ] );
		streamDescArray_.push_back( streamDesc );
	}
}

	
	
/*=========================================================================*/
/**
 * @brief ストリームタイプを設定する
 * 
 * @param[in] なし.
 * @return なし.
 */
void Mesh::setStreamType()
{
	// 以前のデータをクリア
	streamTypeArray_.clear();

	// 位置座標レイアウトの設定
	streamTypeArray_.push_back( STREAM_TYPE_VERTEX );

	// 法線ベクトルレイアウトの設定
	streamTypeArray_.push_back( STREAM_TYPE_NORMAL );

	// 拡散反射光カラー成分があるか
	if( bufferList_[ STREAM_TYPE_DIFFUSE ] != 0 ){
		streamTypeArray_.push_back( STREAM_TYPE_DIFFUSE );
	}

	// 鏡面反射光カラー成分があるか
	if( bufferList_[ STREAM_TYPE_SPECULAR ] != 0 ){
		streamTypeArray_.push_back( STREAM_TYPE_SPECULAR );
	}

	// テクスチャ座標が設定されているか
	if( bufferList_[ STREAM_TYPE_TEXCOORD ] != 0 ){
		// テクスチャ座標レイアウトの設定
		streamTypeArray_.push_back( STREAM_TYPE_TEXCOORD );
	}

	// スキンデータがあるか
	if( info_.numWeights != 0 ){
		// スキンウェイトレイアウトの設定
		streamTypeArray_.push_back( STREAM_TYPE_BLENDWEIGHT );
	}

	// 行列インデックスデータがあるか
	if( info_.hasMatrixIndices == true ){
		// マトリクスインデックスレイアウトの設定
		streamTypeArray_.push_back( STREAM_TYPE_MATRIXINDEX );
	}

	// テクスチャ座標系データがあるか
	if( info_.hasTextureSpace == true ){
		// 接ベクトルレイアウトの設定
		streamTypeArray_.push_back( STREAM_TYPE_TANGENT );

		// 従法線ベクトルレイアウトの設定
		streamTypeArray_.push_back( STREAM_TYPE_BINORMAL );
	}
}


	
/*=========================================================================*/
/**
 * @brief ストリームタイプからセマンティックを取得
 * 
 * @param[in] type ストリームタイプ.
 * @return なし.
 */
VertexSemantic Mesh::getSemantic( StreamType type )
{
	static const VertexSemantic semantics[] = {
		VERTEX_SEMANTIC_POSITION,			// STREAM_TYPE_VERTEX		= 0,
		VERTEX_SEMANTIC_NORMAL,				// STREAM_TYPE_NORMAL		= 1,
		VERTEX_SEMANTIC_DIFFUSE,			// STREAM_TYPE_DIFFUSE		= 2,
		VERTEX_SEMANTIC_SPECULAR,			// STREAM_TYPE_SPECULAR		= 3,
		VERTEX_SEMANTIC_TEXCOORD,			// STREAM_TYPE_TEXCOORD		= 4,
		VERTEX_SEMANTIC_BLENDWEIGHT,		// STREAM_TYPE_BLENDWEIGHT	= 5,
		VERTEX_SEMANTIC_BLENDINDICES,		// STREAM_TYPE_MATRIXINDEX	= 6,
		VERTEX_SEMANTIC_TANGENT,			// STREAM_TYPE_TANGENT		= 7,
		VERTEX_SEMANTIC_BINORMAL			// STREAM_TYPE_BINORMAL		= 8

	};

	return semantics[ type ];
}



/*=========================================================================*/
/**
 * @brief ストリームタイプから頂点セマンティックを取得
 * 
 * @param[in] type ストリームタイプ.
 * @return なし.
 */
VertexType Mesh::getType( StreamType type )
{
	static const VertexType types[] = {
		VERTEX_TYPE_FLOAT3,		// STREAM_TYPE_VERTEX		= 0,
		VERTEX_TYPE_FLOAT3,		// STREAM_TYPE_NORMAL		= 1,
		VERTEX_TYPE_FLOAT4,		// STREAM_TYPE_DIFFUSE		= 2,
		VERTEX_TYPE_FLOAT4,		// STREAM_TYPE_SPECULAR		= 3,
		VERTEX_TYPE_FLOAT2,		// STREAM_TYPE_TEXCOORD		= 4,
		VERTEX_TYPE_FLOAT4,		// STREAM_TYPE_BLENDWEIGHT	= 5,
		VERTEX_TYPE_FLOAT4,		// STREAM_TYPE_MATRIXINDEX	= 6,
		VERTEX_TYPE_FLOAT3,		// STREAM_TYPE_TANGENT		= 7,
		VERTEX_TYPE_FLOAT3		// STREAM_TYPE_BINORMAL		= 8

	};

	return types[ type ];
}

	

/*=========================================================================*/
/**
 * @brief ストリームタイプから1要素の要素数を取得
 * 
 * @param[in] type ストリームタイプ.
 * @return なし.
 */
unsigned int Mesh::getStride( StreamType type )
{
	static const unsigned int strides[] = {
		sizeof( float ) * 3,	// STREAM_TYPE_VERTEX		= 0,
		sizeof( float ) * 3,	// STREAM_TYPE_NORMAL		= 1,
		sizeof( float ) * 4,	// STREAM_TYPE_DIFFUSE		= 2,
		sizeof( float ) * 4,	// STREAM_TYPE_SPECULAR		= 3,
		sizeof( float ) * 2,	// STREAM_TYPE_TEXCOORD		= 4,
		sizeof( float ) * 4,	// STREAM_TYPE_BLENDWEIGHT	= 5,
		sizeof( float ) * 4,	// STREAM_TYPE_MATRIXINDEX	= 6,
		sizeof( float ) * 3,	// STREAM_TYPE_TANGENT		= 7,
		sizeof( float ) * 3		// STREAM_TYPE_BINORMAL		= 8

	};

	return strides[ type ];
}



/*===== EOF ==================================================================*/