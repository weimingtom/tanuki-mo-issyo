/*******************************************************************************/
/**
 * @file Sphere.h.
 * 
 * @brief 球体構造体ヘッダファイル.
 *
 * @date 2008/07/08.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_SPHERE_H_
#define _NGL_SPHERE_H_

#include	"Vector3.h"

#ifdef __cplusplus
#include	"CollisionReport.h"

namespace Ngl{
#endif


/**
 * @struct Sphere．
 * @brief 球体構造体.
 */
typedef struct Sphere
{
	/** 中心座標 */
	Vector3		center;

	/** 半径値 */
	float		radius;


#ifdef __cplusplus


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	Sphere();


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] Center 中心座標.
	 * @param[in] Radius 半径値.
	 */
	Sphere( const Vector3& Center, const float Radius );

	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] Center 中心座標配列.
	 * @param[in] Radius 半径値.
	 */
	Sphere( const float* Center, const float Radius );

	
	/*=========================================================================*/
	/**
	 * @brief 初期化する
	 * 
	 * @param[in] X 中心座標のX座標.
	 * @param[in] Y 中心座標のX座標.
	 * @param[in] Z 中心座標のX座標.
	 * @param[in] Radius 半径値.
	 * @return なし.
	 */
	void initialize( float X, float Y, float Z, float Radius );


	/*=========================================================================*/
	/**
	 * @brief 初期化する
	 * 
	 * @param[in] Center 中心座標.
	 * @param[in] Radius 半径値.
	 * @return なし.
	 */
	void initialize( const Vector3& Center, float Radius );

	
	/*=========================================================================*/
	/**
	 * @brief 単位球に設定
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void setIdentity();

	
	/*=========================================================================*/
	/**
	 * @brief 球体との衝突判定
	 * 
	 * @param[in] otherCenter 判定する球体の中心座標.
	 * @param[in] otherRadius 判定する球体の半径値.
	 * @retval true 衝突していた.
	 * @retval false 衝突していない.
	 */
	bool collision( const Vector3& otherCenter, const float otherRadius );


	/*=========================================================================*/
	/**
	 * @brief 球体との衝突判定
	 * 
	 * @param[in] other 判定する球体.
	 * @retval true 衝突していた.
	 * @retval false 衝突していない.
	 */
	bool collision( const Sphere& other );


#endif


} NGLsphere;


#ifdef __cplusplus

/** 単位球 */
static const Sphere SPHERE_IDENTITY = Sphere( VECTOR3_ZERO, 1.0f );


} // namespace Ngl
#endif


#endif


/*===== EOF ==================================================================*/