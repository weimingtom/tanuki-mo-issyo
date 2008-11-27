/*******************************************************************************/
/**
 * @file MapMeshOct.cpp.
 * 
 * @brief Oct Oct形式マップメッシュクラスソースファイル.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Oct/MapMeshOct.h"
#include	"Ngl/Manipulator.h"
#include	"Ngl/FileInputC.h"
#include	"Ngl/Utility.h"
#include	"Ngl/MathUtility.h"
#include	<cassert>

using namespace Ngl;
using namespace Ngl::Oct;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] renderer レンダラークラスのポインタ.
 * @param[in] creator メッシュ作成者.
 */
MapMeshOct::MapMeshOct( IRenderer* renderer, IMeshCreator* creator ):
	renderer_( renderer ),
	meshCreator_( creator ),
	mesh_( NULL ),
	nodeCount_( 0 ),
	nodes_( 0 )
{}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
MapMeshOct::~MapMeshOct()
{
	release();
}



/*=========================================================================*/
/**
 * @brief ファイルからデータを読み込む
 * 
 * @param[in] fileName ファイル名.
 * @return なし.
 */
void MapMeshOct::loadFromFile( std::string fileName )
{
	// ファイルを開く
	FileInputC stream;
	try{
		stream.open( fileName.c_str() );
	}
	catch( FileOpenException& e ){
		ADDEXCEPTIONINFO_FILELINE( e );
		e.outputConsol();
	}

	// 入力ストリームから読み込む
	loadFromStream( stream );
}



/*=========================================================================*/
/**
 * @brief 入力ストリームからデータを読み込む
 * 
 * @param[in] stream 入力ストリーム.
 * @return なし.
 */
void MapMeshOct::loadFromStream( IInputStream& stream )
{
	try{
		// オクツリーファイル情報の読み込み
		unsigned int octree_mshInfo = 0;
		stream >> octree_mshInfo;

		// メッシュファイル名の読み込み
		std::string meshFileName;
		stream >> meshFileName;

		// ファイルパスを分解する
		std::string Drive;
		std::string Dir;
		Drive = Utility::getFilePathDrave( stream.streamName().c_str() );
		Dir = Utility::getFilePathDir( stream.streamName().c_str() );

		// フルパスのファイル名を作成
		std::string meshFileNamePass;
		meshFileNamePass = Drive + Dir;
		meshFileName = meshFileNamePass + meshFileName;

		// メッシュデータを生成
		IMesh* mesh = meshCreator_->createFromFile( meshFileName );
		
		// オクツリーをクリーンアップする
		release();

		// 新しいメッシュを設定する
		mesh_ = mesh;
		
		// ノード数の読み込み
		stream >> nodeCount_;

		// ノードの配列を生成する
		nodes_ = new MapMeshOct::Node[ nodeCount_ ];

		// ノードの配列を読み込む
		for( unsigned int i=0; i<nodeCount_; i++ ){
			loadNodeData( stream, &nodes_[ i ] );
		}
	}
	catch( InputStreamException& e ){
		ADDEXCEPTIONINFO_FILELINE( e );
		e.outputConsol();
	}
}



/*=========================================================================*/
/**
 * @brief 頂点宣言データを作成
 * 
 * @param[in] inputSignature 入力シグネチャ記述子の参照.
 * @return なし.
 */
void MapMeshOct::setVertexDeclaration( const InputSignatureDesc& inputSignature )
{
	mesh_->setVertexDeclaration( inputSignature );
}


	
/*=========================================================================*/
/**
 * @brief 描画処理
 * 
 * @param[in] effect エフェクトのポインタ.
 * @param[in] matProj 4x4透視変換行列構造体の参照.
 * @param[in] matView 4x4視野変換行列構造体の参照.
 * @return なし.
 */
void MapMeshOct::draw( IEffect* effect, const Matrix4& matProj, const Matrix4& matView )
{
	// 視錐台を作成
	frustum_.createFromMatrices( matView, matProj );

	// ノードを描画する
	drawNode( effect, nodes_[ 0 ] );
}



/*===========================================================================*/
/**
 * @brief 線分との衝突判定
 * 
 * @param[in] line0 線分の始点.
 * @param[in] line1 線分の終点.
 * @return 面データ衝突結果構造体の参照.
 */
const PlaneCollisionReport& MapMeshOct::collisionLine( const float* line0, const float* line1 )
{
	// ノードと線分との衝突判定をする
	return collisionNodeAndLine( nodes_[0], line0, line1 );
}



/*===========================================================================*/
/**
 * @brief 3D線との衝突判定
 * 
 * @param[in] rayPos レイの始点.
 * @param[in] rayDir レイの方向.
 * @return 面データ衝突結果構造体の参照.
 */
const PlaneCollisionReport& MapMeshOct::collisionRay( const float* rayPos, const float* rayDir )
{
	// ノードとレイの衝突判定をする
	return collisionNodeAndRay( nodes_[0], rayPos, rayDir );
}



/*===========================================================================*/
/**
 * @brief 球体との衝突判定
 * 
 * @param[in] center 球体の中心座標.
 * @param[in] radius 球体の半径.
 * @return 面データ衝突結果構造体の参照.
 */
const PlaneCollisionReport& MapMeshOct::collisionSphere( const float* center, float radius )
{
	// ノードと球体との衝突判定をする
	return collisionNodeAndSphere( nodes_[0], center, radius );
}



/*=========================================================================*/
/**
 * @brief ノードデータを読み込む
 * 
 * @param[in] stream 入力ストリームの参照.
 * @param[in] node データを設定するオクツリーノードのポインタ.
 * @return なし.
 */
void MapMeshOct::loadNodeData( IInputStream& stream, MapMeshOct::Node* node )
{
	// ノードのデータを読み込む
	unsigned int leafNodeFlag;
	stream >> leafNodeFlag;

	// リーフノードだった
	if( leafNodeFlag == LEAFNODE_FLAG ){
		node->leafNodeFlag = true;
	}
	else{
		node->leafNodeFlag = false;
	}

	// ノードの幅と中心点を読み込む
	stream >> Vector3Input( node->posMin );
	stream >> Vector3Input( node->posMax );

	// 面データグループの数を読み込む
	stream >> node->info.faceGroupCount;

	// 面データグループ番号を読み込む
	stream >> node->info.faceGroupIndex;

	// 子ノードを読み込む
	for( int j=0; j<8; ++j ){
		unsigned int nodeID = 0;
		stream >> nodeID;

		// 子ノードを設定
		if( static_cast<int>( nodeID ) != -1 ){
			node->nodes[ j ] = &nodes_[ nodeID ];
		}
		else{
			node->nodes[ j ] = 0;
		}
	}

	// リーフノードの場合はノード用のメッシュデータを設定する
	node->mesh = NULL;
	if( node->leafNodeFlag == LEAFNODE_FLAG ){
		node->mesh = mesh_;
	}
}

	
	

/*=========================================================================*/
/**
 * @brief ノードを描画
 * 
 * @param[in] effect エフェクトのポインタ.
 * @param[in] node 描画するノード構造体の参照.
 * @return なし.
 */
void MapMeshOct::drawNode( IEffect* effect, MapMeshOct::Node& node )
{
	// ノードが視錐台に入っているか
	if( frustum_.isBoxInside( node.posMin, node.posMax ) == false ){
		return;
	}

	// リーフノードか
	if( node.leafNodeFlag == true ){
		// メッシュを描画する
		for( int i=0; i<node.info.faceGroupCount; ++i ){
			node.mesh->drawSubset( node.info.faceGroupIndex+i, effect );
		}
	}

	// 子ノードをすべて描画する
	for( int i=0; i<8; i++ ){
		if( node.nodes[i] != 0 ){
			drawNode( effect, *node.nodes[i] );
		}
	}
}
	
	

/*=========================================================================*/
/**
 * @brief 解放処理
 * 
 * @param[in] なし.
 * @return なし.
 */
void MapMeshOct::release()
{
	// オクツリーのノードを削除
	if( nodes_ != NULL ){
		for( unsigned int i=0; i<nodeCount_; i++ ){
			// リーフノードか
			if( nodes_[i].leafNodeFlag == true ){
				// ノードのメッシュをクリア
				nodes_[i].mesh = NULL;
			}
		}
		// ノードを削除
		delete[] nodes_;
		nodes_ = NULL;
	}

	// ノード数を初期化
	nodeCount_ = 0;

	// メッシュを削除
	if( mesh_ != NULL ){
		delete mesh_;
		mesh_ = NULL;
	}
}

	
	
/*===========================================================================*/
/**
 * @brief ノードと線分の衝突判定
 * 
 * @param[in] node オクツリーノードの参照.
 * @param[in] line0 線分の始点.
 * @param[in] line1 線分の終点.
 * @return 面データ衝突結果構造体の参照.
 */
const PlaneCollisionReport& MapMeshOct::collisionNodeAndLine( MapMeshOct::Node& node, const float* line0, const float* line1 )
{		
	// ノードの中に線分が存在するかチェックする
	if( collision_.lineIsInsideBox( node.posMin, node.posMax, line0, line1 ) == false ){
		return PLANECOLLISIONREPORT_NOT_COLLISION;
	}

	// リーフノードの場合はメッシュとの衝突判定を行う
	if( node.leafNodeFlag == true ){
		for( int i=0; i<node.info.faceGroupCount; ++i ){
			const PlaneCollisionReport& param = node.mesh->collisionFaceAndLine( node.info.faceGroupIndex+i, line0, line1 );
			// 衝突しているか
			if( param.isCollision == true ){
				return param;
			}
			return param;
		}
	}

	// 全ての子ノードとの衝突判定を行う
	for( int i=0; i<8; i++ ){
		if( node.nodes[i] != 0 ){
			const PlaneCollisionReport& param = collisionNodeAndLine( *node.nodes[i], line0, line1 );
			if( param.isCollision == true ){
				return param;
			}
		}
	}
	// 非衝突
	return PLANECOLLISIONREPORT_NOT_COLLISION;
}

	
	
/*===========================================================================*/
/**
 * @brief ノードとレイの衝突判定
 * 
 * @param[in] node ノード.
 * @param[in] rayPos レイの位置.
 * @param[in] rayDir レイの方向.
 * @return 面データ衝突結果構造体の参照.
 */
const PlaneCollisionReport& MapMeshOct::collisionNodeAndRay( MapMeshOct::Node& node, const float* rayPos, const float* rayDir )
{
	// ノードの中にレイが存在するか調べる
	if( collision_.rayIsIntersectBox( node.posMin, node.posMax, rayPos, rayDir ) == false ){
		return PLANECOLLISIONREPORT_NOT_COLLISION;
	}

	// リーフノードの場合はメッシュとの衝突判定をする
	if( node.leafNodeFlag == true ){
		for( int i=0; i<node.info.faceGroupCount; ++i ){ 
			const PlaneCollisionReport& param = node.mesh->collisionFaceAndRay( node.info.faceGroupIndex+i, rayPos, rayDir );
			
			// 衝突していたか
			if( param.isCollision == true ){
				return param;
			}

			return param;
		}
	}

	// すべての子ノードとの衝突判定をする
	for( int i=0; i<8; i++ ){
		if( node.nodes[i] != 0 ){
			const PlaneCollisionReport& param = collisionNodeAndRay( *node.nodes[i], rayPos, rayDir );
			if( param.isCollision == true ){
				return param;
			}
		}
	}

	// 非衝突
	return PLANECOLLISIONREPORT_NOT_COLLISION;
}



/*===========================================================================*/
/**
 * @brief ノードと球体の衝突判定
 * 
 * @param[in] node ノード.
 * @param[in] center 球体の中心座標.
 * @param[in] radius 球体の半径.
 * @return 面データ衝突結果構造体の参照.
 */
const PlaneCollisionReport& MapMeshOct::collisionNodeAndSphere( MapMeshOct::Node& node, const float* center, float radius )
{
	// ノードの中に球体が存在しないかチェックする
	if( collision_.sphereIsInsideBox( node.posMin, node.posMax, center, radius ) == false ){
		return PLANECOLLISIONREPORT_NOT_COLLISION;
	}

	// リーフノードか
	if( node.leafNodeFlag == true ){
		for( int i=0; i<node.info.faceGroupCount; ++i ){
			// メッシュと球体の衝突判定を行う
			const PlaneCollisionReport& param = node.mesh->collisionFaceAndSphere( node.info.faceGroupIndex+i, center, radius );
			if( param.isCollision == true ){
				return param;
			}
		}
	}

	// 全ての子ノードとの衝突判定を行う
	for( int i=0; i<8; i++ ){
		if( node.nodes[i] != 0 ){
			const PlaneCollisionReport& param = collisionNodeAndSphere( *node.nodes[i], center, radius );
			if( param.isCollision == true ){
				return param;
			}
		}
	}

	// 非衝突
	return PLANECOLLISIONREPORT_NOT_COLLISION;
}



/*===== EOF ==================================================================*/