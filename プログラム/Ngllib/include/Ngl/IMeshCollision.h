/*******************************************************************************/
/**
 * @file IMeshCollision.h.
 * 
 * @brief メッシュデータ衝突判定クラスインターフェース定義.
 *
 * @date 2008/07/19.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IMESHCOLLISION_H_
#define _NGL_IMESHCOLLISION_H_

#include	"CollisionReport.h"

namespace Ngl{


/**
 * @class IMeshCollision．
 * @brief メッシュデータ衝突判定クラスインターフェース.
 */
class IMeshCollision
{

public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~IMeshCollision() {}


	/*===========================================================================*/
	/**
	 * @brief 線分との衝突判定
	 * 
	 * @param[in] line0 線分の始点.
	 * @param[in] line1 線分の終点.
	 * @return 衝突結果構造体の参照.
	 */
	virtual const PlaneCollisionReport& line( const float* line0, const float* line1 ) = 0;


	/*===========================================================================*/
	/**
	 * @brief 指定のポリゴンと線分との衝突判定
	 * 
	 * @param[in] polygonNo ポリゴンデータ番号.
	 * @param[in] line0 線分の始点.
	 * @param[in] line1 線分の終点.
	 * @return 衝突結果構造体の参照.
	 */
	virtual const PlaneCollisionReport& polygonAndLine( int polygonNo, const float* line0, const float* line1 ) = 0;


	/*===========================================================================*/
	/**
	 * @brief 3D線との衝突判定
	 * 
	 * @param[in] rayPos 3D線の始点座標.
	 * @param[in] rayDir 3D線の方向.
	 * @return 面データ衝突パラメーター.
	 */
	virtual const PlaneCollisionReport& ray( const float* rayPos, const float* rayDir ) = 0;


	/*===========================================================================*/
	/**
	 * @brief 指定のポリゴンと3D線との衝突判定
	 * 
	 * @param[in] polygonNo ポリゴンデータ番号.
	 * @param[in] rayPos 3D線の始点座標.
	 * @param[in] rayDir 3D線の方向.
	 * @return 面データ衝突パラメーター.
	 */
	virtual const PlaneCollisionReport& polygonAndRay( int polygonNo, const float* rayPos, const float* rayDir ) = 0;


	/*===========================================================================*/
	/**
	 * @brief 球体との衝突判定
	 * 
	 * @param[in] center 球体の中心位置.
	 * @param[in] radius 球体の半径.
	 * @return 面データ衝突パラメーター.
	 */
	virtual const PlaneCollisionReport& sphere( const float* center, float radius ) = 0;


	/*===========================================================================*/
	/**
	 * @brief 指定のポリゴンと球体との衝突判定
	 * 
	 * @param[in] polygonNo ポリゴンデータ番号.
	 * @param[in] center 球体の中心位置.
	 * @param[in] radius 球体の半径.
	 * @return 面データ衝突パラメーター.
	 */
	virtual const PlaneCollisionReport& polygonAndSphere( int polygonNo, const float* center, float radius ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/