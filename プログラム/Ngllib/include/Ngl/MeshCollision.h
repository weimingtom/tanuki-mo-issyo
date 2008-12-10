/*******************************************************************************/
/**
 * @file MeshCollision.h.
 * 
 * @brief メッシュデータ衝突判定クラスヘッダファイル.
 *
 * @date 2008/07/18.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MESHCOLLISION_H_
#define _NGL_MESHCOLLISION_H_

#include	"IMeshCollision.h"
#include	"IBuffer.h"
#include	"MeshInfo.h"
#include	"Collision.h"
#include	"Plane.h"
#include	"Vector3.h"
#include	<vector>

namespace Ngl{


/**
 * @class MeshCollision．
 * @brief メッシュデータ衝突判定クラス.
 */
class MeshCollision : public IMeshCollision
{

public:

	/*===========================================================================*/
	/**
	 * @brief 衝突判定データを作成する
	 * 
	 * @param[in] info メッシュ情報構造体の参照.
	 * @param[in] vertices 頂点バッファデータのポインタ.
	 * @param[in] indices インデックスバッファデータのポインタ
	 * @return なし.
	 */
	void create( const MeshInfo& info, IBuffer* vertices, IBuffer* indices );
	
	
	/*===========================================================================*/
	/**
	 * @brief 線分との衝突判定
	 * 
	 * @param[in] line0 線分の始点.
	 * @param[in] line1 線分の終点.
	 * @return 衝突結果構造体の参照.
	 */
	virtual const PlaneCollisionReport& line( const float* line0, const float* line1 );


	/*===========================================================================*/
	/**
	 * @brief 指定のポリゴンと線分との衝突判定
	 * 
	 * @param[in] polygonNo ポリゴンデータ番号.
	 * @param[in] line0 線分の始点.
	 * @param[in] line1 線分の終点.
	 * @return 衝突結果構造体の参照.
	 */
	virtual const PlaneCollisionReport& polygonAndLine( int polygonNo, const float* line0, const float* line1 );


	/*===========================================================================*/
	/**
	 * @brief 3D線との衝突判定<b指定のr>
	 * 
	 * @param[in] rayPos 3D線の始点座標.
	 * @param[in] rayDir 3D線の方向.
	 * @return 面データ衝突パラメーター.
	 */
	virtual const PlaneCollisionReport& ray( const float* rayPos, const float* rayDir );


	/*===========================================================================*/
	/**
	 * @brief 指定のポリゴンと3D線との衝突判定
	 * 
	 * @param[in] polygonNo ポリゴンデータ番号.
	 * @param[in] rayPos 3D線の始点座標.
	 * @param[in] rayDir 3D線の方向.
	 * @return 面データ衝突パラメーター.
	 */
	virtual const PlaneCollisionReport& polygonAndRay( int polygonNo, const float* rayPos, const float* rayDir );


	/*===========================================================================*/
	/**
	 * @brief 球体との衝突判定
	 * 
	 * @param[in] center 球体の中心位置.
	 * @param[in] radius 球体の半径.
	 * @return 面データ衝突パラメーター.
	 */
	virtual const PlaneCollisionReport& sphere( const float* center, float radius );


	/*===========================================================================*/
	/**
	 * @brief 指定のポリゴンと球体との衝突判定
	 * 
	 * @param[in] polygonNo ポリゴンデータ番号.
	 * @param[in] center 球体の中心位置.
	 * @param[in] radius 球体の半径.
	 * @return 面データ衝突パラメーター.
	 */
	virtual const PlaneCollisionReport& polygonAndSphere( int polygonNo, const float* center, float radius );

private:

	/** 非衝突 */
	static const PlaneCollisionReport NOT_COLLISION;

private:

	/** 頂点データ配列型 */
	typedef std::vector< Vector3 >			VertexArray;

	/** インデックスデータ配列型 */
	typedef std::vector< unsigned short >	IndexArray;

	/** 平面情報配列型 */
	typedef std::vector< Plane >			PlaneArray;

private:

	/** メッシュ情報 */
	MeshInfo			info_;

	/** 頂点データ配列 */
	VertexArray			vertices_;

	/** インデックスデータ配列 */
	IndexArray			indices_;

	/** 平面情報配列 */
	PlaneArray			planeArray_;

	/** 衝突判定クラス */
	Collision			collision_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/