/*******************************************************************************/
/**
 * @file Ray.h.
 * 
 * @brief 3次元無限線分構造体ヘッダファイル.
 *
 * @date 2008/07/12.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_RAY_H_
#define _NGL_RAY_H_

#include	"Vector3.h"

#ifdef __cplusplus
#include "CollisionReport.h"

namespace Ngl{


// 球体構造体
struct Sphere;
#endif


/**
 * @struct Ray．
 * @brief 3次元無限線分構造体.
 */
typedef struct Ray
{
	/** 始点座標 */
	Vector3	position;

	/** 方向 */
	Vector3	direction;
	

#ifdef __cplusplus


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	Ray();

	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] pos 始点座標.
	 * @param[in] dir 方向ベクトル.
	 */
	Ray( const Vector3& pos, const Vector3& dir );
	
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] pos 始点座標配列.
	 * @param[in] dir 方向ベクトル配列.
	 */
	Ray( const float* pos, const float* dir );
	
	
	/*=========================================================================*/
	/**
	 * @brief 初期化する
	 * 
	 * @param[in] x 始点x座標.
	 * @param[in] y 始点y座標.
	 * @param[in] z 始点z座標.
	 * @param[in] DirX 方向ベクトルx座標.
	 * @param[in] DirY 方向ベクトルy座標.
	 * @param[in] DirZ 方向ベクトルz座標.
	 * @return なし.
	 */
	void initialize( float x, float y, float z, float DirX, float DirY, float DirZ );


	/*=========================================================================*/
	/**
	 * @brief 初期化する
	 * 
	 * @param[in] pos 始点座標.
	 * @param[in] dir 方向ベクトル.
	 * @return なし.
	 */
	void initialize( const Vector3& pos, const Vector3& dir );

	
	/*=========================================================================*/
	/**
	 * @brief 球体との衝突判定
	 * 
	 * @param[in] center 判定する球体の中心座標.
	 * @param[in] radius 判定する球体の半径.
	 * @retval true 衝突している.
	 * @retval false 衝突していない.
	 */
	bool collision( const Vector3& center, float radius );
		
		
	/*=========================================================================*/
	/**
	 * @brief 球体との衝突判定
	 * 
	 * @param[in] sphere 判定する球体.
	 * @retval true 衝突している.
	 * @retval false 衝突していない.
	 */
	bool collision( const Sphere& sphere );
	
	
	/*=========================================================================*/
	/**
	 * @brief 3D線との衝突判定
	 * 
	 * @param[in] pos 判定する3D線の位置.
	 * @param[in] dir 判定する.
	 * @param[in] epsilon 閾値.
	 * @return 衝突判定結果構造体.
	 */
	const LineCollisionReport& collision( const Vector3& pos, const Vector3& dir, float epsilon );
	
	
	/*=========================================================================*/
	/**
	 * @brief 3D線との衝突判定
	 * 
	 * @param[in] other 判定する3D線.
	 * @param[in] epsilon 閾値.
	 * @return 衝突判定結果構造体.
	 */
	const LineCollisionReport& collision( const Ray& other, float epsilon );
	
	
	/*=========================================================================*/
	/**
	 * @brief 無限直線と指定座標のもっとも近い無限直線の座標を求める
	 * 
	 * @param[in] x 求めたい位置のx座標.
	 * @param[in] y 求めたい位置のy座標.
	 * @param[in] z 求めたい位置のz座標.
	 * @return 最も近い座標.
	 */
	Vector3 findNearestPosition( float x, float y, float z );

#endif


} NGLray;


#ifdef __cplusplus
} // namespace Ngl
#endif


#endif

/*===== EOF ==================================================================*/