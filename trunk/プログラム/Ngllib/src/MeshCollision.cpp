/*******************************************************************************/
/**
 * @file MeshCollision.cpp.
 * 
 * @brief メッシュデータ衝突判定クラスソースファイル.
 *
 * @date 2008/07/18.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/MeshCollision.h"
#include	<cassert>

using namespace Ngl;


/** 非衝突 */
const PlaneCollisionReport MeshCollision::NOT_COLLISION = PLANECOLLISIONREPORT_NOT_COLLISION;


/*===========================================================================*/
/**
 * @brief 衝突判定データを作成する
 *
 * @param[in] info メッシュ情報構造体の参照.
 * @param[in] vertices 頂点バッファデータのポインタ.
 * @param[in] indices インデックスバッファデータのポインタ
 * @return なし.
 */
void MeshCollision::create( const MeshInfo& info, IBuffer* vertices, IBuffer* indices )
{
	assert( vertices != NULL );
	assert( indices != NULL );

	// 面データ情報を設定
	info_ = info;

	// すでに平面が生成されている場合はクリアする
	if( planeArray_.empty() == false ){
		planeArray_.clear();
	}

	// 配列のサイズを設定
	planeArray_.resize( sizeof( Plane ) * ( info_.numIndices/ 3 ) );

	// 頂点データを取得
	vertices_.resize( sizeof( Vector3 ) * info_.numVertices );
	vertices->getData( (void*)&vertices_[ 0 ] );

	// インデックスデータを取得
	indices_.resize( sizeof( unsigned short ) * info_.numIndices );
	indices->getData( (void*)&indices_[ 0 ] );

	// ポリゴンを作成する
	for( unsigned int i=0; i<( info_.numIndices/3 ); i++ ){
		// ポリゴンの3頂点を取得する
		planeArray_[i].createFromPoints(
			vertices_[ indices_[ i*3+0 ] ],
			vertices_[ indices_[ i*3+1 ] ],
			vertices_[ indices_[ i*3+2 ] ]
		);
	}
}



/*===========================================================================*/
/**
 * @brief 線分との衝突判定
 * 
 * @param[in] line0 線分の始点.
 * @param[in] line1 線分の終点.
 * @return 衝突結果構造体の参照.
 */
const PlaneCollisionReport& MeshCollision::line( const float* line0, const float* line1 )
{
	// すべてのポリゴンと線分との衝突判定を行う
	for( unsigned int i=0; i<info_.numIndices/3; ++i ){
		const PlaneCollisionReport& param = polygonAndLine( i, line0, line1 );
		
		// 衝突していたか
		if( param.isCollision == true ){
			return param;
		}
	}

	return NOT_COLLISION;
}



/*===========================================================================*/
/**
 * @brief 指定のポリゴンと線分との衝突判定
 * 
 * @param[in] polygonNo ポリゴンデータ番号.
 * @param[in] line0 線分の始点.
 * @param[in] line1 線分の終点.
 * @return 衝突結果構造体の参照.
 */
const PlaneCollisionReport& MeshCollision::polygonAndLine( int polygonNo, const float* line0, const float* line1 )
{
	// 裏面のポリゴンとは衝突判定しない
	if( planeArray_[ polygonNo ].getClassifyPoint( line0 ) == Plane::BEHIND_PLANE ){
		return NOT_COLLISION;
	}

	// ポリゴンの3頂点を取得する
	Vector3 vert[3];
	vert[0] = vertices_[ indices_[ polygonNo*3+0 ] ];
	vert[1] = vertices_[ indices_[ polygonNo*3+1 ] ];
	vert[2] = vertices_[ indices_[ polygonNo*3+2 ] ];

	// ポリゴンと線分の衝突判定を行う
	return collision_.polygonAndLine( vert, 3, planeArray_[polygonNo], line0, line1 );
}

	
	
/*===========================================================================*/
/**
 * @brief 3D線との衝突判定
 * 
 * @param[in] rayPos 3D線の始点座標.
 * @param[in] rayDir 3D線の方向.
 * @return 面データ衝突パラメーター.
 */
const PlaneCollisionReport& MeshCollision::ray( const float* rayPos, const float* rayDir )
{
	// 全ポリゴンとレイの衝突判定をする
	for( unsigned int i=0; i<info_.numIndices/3; i++ ){
		const PlaneCollisionReport& param = polygonAndRay( i, rayPos, rayDir );
		
		// 衝突していた
		if( param.isCollision == true ){
			return param;
		}
	}

	// 衝突していなかった
	return NOT_COLLISION;
}



/*===========================================================================*/
/**
 * @brief 指定のポリゴンと3D線との衝突判定
 * 
 * @param[in] polygonNo ポリゴンデータ番号.
 * @param[in] rayPos 3D線の始点座標.
 * @param[in] rayDir 3D線の方向.
 * @return 面データ衝突パラメーター.
 */
const PlaneCollisionReport& MeshCollision::polygonAndRay( int polygonNo, const float* rayPos, const float* rayDir )
{
	// 裏面のポリゴンとは衝突判定をしない
	if( planeArray_[ polygonNo ].getClassifyPoint( rayPos ) == Plane::BEHIND_PLANE ){
		return NOT_COLLISION;
	}

	// ポリゴンの3頂点を取得する
	Vector3 vert[3];
	vert[0] = vertices_[ indices_[ polygonNo*3+0 ] ];
	vert[1] = vertices_[ indices_[ polygonNo*3+1 ] ];
	vert[2] = vertices_[ indices_[ polygonNo*3+2 ] ];

	// ポリゴンとレイの衝突判定を行う
	return collision_.polygonAndRay( vert, 3, planeArray_[ polygonNo ], rayPos, rayDir );
}

	
	
/*===========================================================================*/
/**
 * @brief 球体との衝突判定
 * 
 * @param[in] center 球体の中心位置.
 * @param[in] radius 球体の半径.
 * @return 面データ衝突パラメーター.
 */
const PlaneCollisionReport& MeshCollision::sphere( const float* center, float radius )
{
	// 全ポリゴンと球体との衝突判定を行う
	for( unsigned int i = 0; i<info_.numIndices/3; i++ ){
		const PlaneCollisionReport& param = polygonAndSphere( i, center, radius );
		
		// 衝突していたか
		if( param.isCollision == true ){
			return param;
		}
	}

	// 衝突していなかった
	return NOT_COLLISION;
}



/*===========================================================================*/
/**
 * @brief 指定のポリゴンと球体との衝突判定
 * 
 * @param[in] polygonNo ポリゴンデータ番号.
 * @param[in] center 球体の中心位置.
 * @param[in] radius 球体の半径.
 * @return 面データ衝突パラメーター.
 */
const PlaneCollisionReport& MeshCollision::polygonAndSphere( int polygonNo, const float* center, float radius )
{
	// 球体がポリゴンと交差しないか調べる
	if( planeArray_[ polygonNo ].getClassifySphere( center, radius ) != Plane::INTERSECTS_PLANE ){
		return NOT_COLLISION;
	}

	// ポリゴンの3頂点を取得する
	Vector3 vert[3] = {
		vertices_[ indices_[ polygonNo*3+0 ] ],
		vertices_[ indices_[ polygonNo*3+1 ] ],
		vertices_[ indices_[ polygonNo*3+2 ] ]
	};

	// ポリゴンと球体が衝突しているか
	const PlaneCollisionReport& param = collision_.polygonAndSphere( vert, 3, planeArray_[ polygonNo ], center, radius );

	// 衝突しているか
	if( param.isCollision == true ){
		// 衝突していた
		return param;
	}

	// ポリゴンのエッジと球体が衝突しているか
	return collision_.polygonEdgeAndSphere( vert, 3, center, radius );
}


	
/*===== EOF ==================================================================*/