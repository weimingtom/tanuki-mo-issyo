/*******************************************************************************/
/**
 * @file Frustum.h.
 * 
 * @brief 視錐台クラスヘッダファイル.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_FRUSTUM_H_
#define _NGL_FRUSTUM_H_

#include	"Plane.h"

namespace Ngl{


// 3次元ベクトル構造体の前方参照
struct Vector3;

// 行列構造体の前方参照
struct Matrix4;


/**
 * @class Frustum.
 * @brief 視錐台クラス．
 */
class Frustum
{

public:

	/*=========================================================================*/
	/**
	 * @brief 視野変換行列、透視変換行列から視錐台を作成する
	 * 
	 * @param[in] view 視野変換行列.
	 * @param[in] proj 透視変換行列.
	 * @return なし.
	 */
	void createFromMatrices( const Matrix4& view, const Matrix4& proj );


	/*=========================================================================*/
	/**
	 * @brief 点が視錐台内に存在するか調べる
	 * 
	 * @param[in] point 調べる点.
	 * @retval true 存在している,
	 * @retval false 存在していない.
	 */
	bool isPointInside( const Vector3& point );


	/*=========================================================================*/
	/**
	 * @brief ボックスが視錐台内にあるか調べる
	 * 
	 * @param[in] p1 ボックスの座標1.
	 * @param[in] p2 ボックスの座標2.
	 * @retval true 存在している.
	 * @retval false 存在していない.
	 */
	bool isBoxInside( const Vector3& p1, const Vector3& p2 );


	/*=========================================================================*/
	/**
	 * @brief 球体が視錐台内にあるか調べる
	 * 
	 * @param[in] center 球体の中心座標.
	 * @param[in] radius 球体の半径.
	 * @retval true 存在している.
	 * @retval false 存在していない.
	 */
	bool isSphereInside( const Vector3& center, float radius );

public:

	/**
	 * @enum Frustum::ClipingPlane.
	 * @brief クリッピングプレーン列挙型.
	 */
	enum ClipingPlane
	{
		CLIP_PLANE_LEFT = 0,	/**< 左側面			*/
		CLIP_PLANE_RIGHT,		/**< 右側面			*/
		CLIP_PLANE_TOP,			/**< 上側面			*/
		CLIP_PLANE_BOTTOM,		/**< 下側面			*/
		CLIP_PLANE_NEAR,		/**< 近クリップ面	*/
		CLIP_PLANE_FAR			/**< 遠クリップ面	*/
	};

private:

	/** 視錐台平面配列 */
	Plane	mPlanes[6];

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/