/*******************************************************************************/
/**
 * @file Plane.h.
 * 
 * @brief 平面構造体ヘッダファイル.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_PLANE_H_
#define _NGL_PLANE_H_

#include	"Vector3.h"

namespace Ngl{


/**
 * @struct Plane.
 * @brief 平面構造体．
 */
struct Plane
{
	/** 面法線x成分 */
	float x;

	/** 面法線y成分 */
	float y;

	/** 面法線z成分 */
	float z;

	/** 原点からの距離 */
	float d;

	/**
	 * @enum PlanePositionFlags.
	 * @brief 位置関係列挙型.
	 */
	enum PlanePositionFlags
	{
		FRONT_PLANE = 0,	/**< 平面の前	*/
		BEHIND_PLANE,		/**< 平面の後ろ	*/
		ON_PLANE,			/**< 平面上		*/
		INTERSECTS_PLANE	/**< 平面と交差	*/
	};
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	Plane();


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] other 配列の先頭ポインタ.
	 */
	Plane ( float* other );


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] X 面法線x成分.
	 * @param[in] Y 面法線y成分.
	 * @param[in] Z 面法線z成分.
	 * @param[in] D 原点からの距離.
	 */
	Plane( float X, float Y, float Z, float D );


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] N 法線ベクトル.
	 * @param[in] D 原点からの距離.
	 */
	Plane( const Ngl::Vector3& N, float D );


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] P 平面上の座標.
	 * @param[in] N 法線ベクトル.
	 */
	Plane( const Ngl::Vector3& P, const Ngl::Vector3 N );


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] v1 座標1.
	 * @param[in] v2 座標2.
	 * @param[in] v3 座標3.
	 */
	Plane( const Ngl::Vector3& v1, const Ngl::Vector3& v2, const Ngl::Vector3& v3 );
	
	
	/*=========================================================================*/
	/**
	 * @brief 平面を正規化する
	 * 
	 * @param[in] なし.
	 * @return 正規化した平面.
	 */
	Plane& normalize();


	/*=========================================================================*/
	/**
	 * @brief 平面上の位置を取得する
	 * 
	 * @param[in] なし.
	 * @return 位置座標.
	 */
	Ngl::Vector3 getPoint() const;


	/*=========================================================================*/
	/**
	 * @brief 平面とベクトルの内積を求める
	 * 
	 * @param[in] v 内積を求めるベクトル .
	 * @return 内積.
	 */
	float dot( const Ngl::Vector3& v ) const;

	
	/*=========================================================================*/
	/**
	 * @brief 平面と座標との距離を求める
	 * 
	 * @param[in] v 距離を求めるベクトル .
	 * @return 距離.
	 */
	float distance( const Ngl::Vector3& v ) const;


	/*=========================================================================*/
	/**
	 * @brief 平面と座標の位置関係を返す
	 * 
	 * @param[in] pos 調べる座標.
	 * @return 位置関係.
	 */
	PlanePositionFlags getClassifyPoint( const Ngl::Vector3& pos );


	/*=========================================================================*/
	/**
	 * @brief 平面と球体の位置関係を返す
	 * 
	 * @param[in] center 球体の中心座標.
	 * @param[in] radius 球体の半径.
	 * @return 位置関係.
	 */
	PlanePositionFlags getClassifySphere( const Ngl::Vector3& center, float radius );

	
	/*=========================================================================*/
	/**
	 * @brief 平面と線分が交差するか調べる
	 * 
	 * @param[in] line0 線分の始点.
	 * @param[in] line1 線分の終点.
	 * @return true 交差している, false 交差していない.
	 */
	bool intersectLine( const Ngl::Vector3& line0, const Ngl::Vector3& line1 );


	/*=========================================================================*/
	/**
	 * @brief 平面と線分が交差する座標を求める
	 * 
	 * @param[in] line0 線分の始点.
	 * @param[in] line1 線分の終点.
	 * @param[in] retVec 交差していなかった時に戻るベクトル.
	 * @return 交点座標.
	 */
	Ngl::Vector3 intersectLinePosition
	(
		const Ngl::Vector3& line0,
		const Ngl::Vector3& line1,
		const Ngl::Vector3& retVec
	);
	
	
	/*=========================================================================*/
	/**
	 * @brief 平面とレイが交差するか調べる
	 * 
	 * @param[in] rayPos レイの始点.
	 * @param[in] rayDir レイの方向.
	 * @return true 交差している, false 交差していない.
	 */
	bool intersectRay( const Ngl::Vector3& rayPos, const Ngl::Vector3& rayDir );
	
	
	/*=========================================================================*/
	/**
	 * @brief 平面とレイの交点座標を求める
	 * 
	 * @param[in] rayPos レイの始点.
	 * @param[in] rayDir レイの方向.
	 * @param[in] retVec 交差していなかった時に戻るベクトル.
	 * @return 交点座標.
	 */
	Ngl::Vector3 intersectRayPositon
	(
		const Ngl::Vector3& rayPos,
		const Ngl::Vector3& rayDir,
		const Ngl::Vector3& retVec
	);
	
	
	/*=========================================================================*/
	/**
	 * @brief 平面上の座標と平面の法線ベクトルから平面を作成する
	 * 
	 * @param[in] point 平面状の座標.
	 * @param[in] normal 平面の法線ベクトル.
	 * @return 作成した平面.
	 */
	Plane& createFromPointNormal( const Ngl::Vector3& point, const Ngl::Vector3& normal );


	/*=========================================================================*/
	/**
	 * @brief 平面上の3つの座標から平面を作成する
	 * 
	 * @param[in] v1 座標1.
	 * @param[in] v2 座標2.
	 * @param[in] v3 座標3.
	 * @return 作成した平面.
	 */
	Plane& createFromPoints( const Ngl::Vector3& v1, const Ngl::Vector3& v2, const Ngl::Vector3& v3 );


	/*=========================================================================*/
	/**
	 * @brief == 演算子オーバーロード
	 * 
	 * @param[in] other 演算する平面.
	 * @retval true 一致している.
	 * @retval false 一致していない.
	 */
	bool operator == ( const Ngl::Plane& other );

	
	/*=========================================================================*/
	/**
	 * @brief != 演算子オーバーロード
	 * 
	 * @param[in] other 演算する平面.
	 * @retval true 一致していない.
	 * @retval false 一致している.
	 */
	bool operator != ( const Ngl::Plane& other );

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/