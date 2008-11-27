/*******************************************************************************/
/**
 * @file Collision.h.
 * 
 * @brief 衝突判定クラスヘッダファイル.
 *
 * @date 2008/07/12.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_COLLISION_H_
#define _NGL_COLLISION_H_

#include	"CollisionReport.h"

namespace Ngl{


/**
 * @class Collision．
 * @brief 衝突判定クラス.
 */
class Collision
{

public:

	/*=========================================================================*/
	/**
	 * @brief 球体と球体の衝突判定
	 * 
	 * @param[in] center1 球体1の3D頂点座標.
	 * @param[in] radius1 球体1の半径値.	
	 * @param[in] center2 球体2の3D頂点座標.
	 * @param[in] radius2 球体2の半径値.	
	 * @retval true 衝突していた.
	 * @retval false 衝突していなかった.
	 */
	bool sphereAndSphere
	(
		const Ngl::Vector3&	center1, 
		float				radius1, 
		const Ngl::Vector3&	center2, 
		float				radius2
	);


	/*===========================================================================*/
	/**
	 * @brief 球体を衝突しない座標へ補正する
	 * 
	 * @param[out] center 球体の3D中心位置座標.
	 * @param[in] radius 球体の半径.
	 * @param[in] intersect 3D交点座標. 
	 * @return なし.
	 */
	void Collision::sphereRevisePosition
	( 
		Ngl::Vector3&		center, 
		float				radius,
		const Ngl::Vector3&	intersect
	);


	/*=========================================================================*/
	/**
	 * @brief 球体と3D線の衝突判定
	 * 
	 * @param[in] center 球体の3D頂点座標配列.
	 * @param[in] radius 球体の半径値.	
	 * @param[in] rayPos 線の3D位置座標配列.
	 * @param[in] rayDir 線の方向3Dベクトル配列.	
	 * @retval true 衝突していた.
	 * @retval false 衝突していなかった.
	 */
	bool sphereAndRay
	(
		const Ngl::Vector3&	center, 
		float				radius, 
		const Ngl::Vector3&	rayPos, 
		const Ngl::Vector3&	rayDir
	);


	/*=========================================================================*/
	/**
	 * @brief 3D線分と3D線分の衝突判定
	 * 
	 * @param[in] a1 判定する線分1の始点3D座標.
	 * @param[in] a2 判定する線分1の終点3D座標.
	 * @param[in] b1 判定する線分2の始点3D座標.
	 * @param[in] b2 判定する線分2の終点3D座標.
	 * @param[in] isRay 無限線分かどうか.
	 * @param[in] epsilon 閾値.
	 * @return 衝突判定結果構造体.
	 */
	const LineCollisionReport& lineAndLine
	(
		const Ngl::Vector3& a1, 
		const Ngl::Vector3& a2, 
		const Ngl::Vector3& b1, 
		const Ngl::Vector3& b2,
		bool				isRay,
		float				epsilon
	);


	/*=========================================================================*/
	/**
	 * @brief 3D線分と、指定座標の最も隣接する線分上の座標を求める
	 * 
	 * @param[in] linePos 線分の座標.
	 * @param[in] lineVec 線分の方向.
	 * @param[in] point 調べたい座標.
	 * @param[in] isRay 無限線分か.
	 * @param[out] np 線分上の隣接する座標.
	 * @param[out] parameter 直線の方程式パラメータ.
	 * @return なし.
	 */
	void findNearestPointOnLineSegment
	(
		const Ngl::Vector3& linePos,
		const Ngl::Vector3& lineVec,
		const Ngl::Vector3& point,
		bool				isRay,
		Ngl::Vector3&		np,
		float&				parameter
	);
	

	/*=========================================================================*/
	/**
	 * @brief 3D線分同士が交差しない場合の、線分同士で最も近い点を求める
	 * 
	 * @param[in] a1 判定する線分aの始点3D座標.
	 * @param[in] a2 判定する線分aの終点3D座標.
	 * @param[in] va 線分aの始点から終点へのベクトル.
	 * @param[in] b1 判定する線分bの始点3D座標.
	 * @param[in] b2 判定する線分bの終点3D座標.
	 * @param[in] vb 線分bの始点から終点へのベクトル.
	 * @param[in] isRay 無限線分かどうか.
	 * @param[out] pa 線分a上の、線分bに最も近い3D座標.
	 * @param[out] pb 線分b上の、線分aに最も近い3D座標.
	 * @return なし.
	 */
	void findNearestPointOfParallelLineSegments
	(
		const Ngl::Vector3& a1, 
		const Ngl::Vector3& a2,
		const Ngl::Vector3& va,
		const Ngl::Vector3& b1, 
		const Ngl::Vector3& b2,
		const Ngl::Vector3& vb,
		bool				isRay,
		Ngl::Vector3&		pa,
		Ngl::Vector3&		pb
	);

	
	/*=========================================================================*/
	/**
	 * @brief 3D線分同士の、最も近い座標の調整をする
	 * 
	 * @param[in] a1 判定する線分aの始点3D座標.
	 * @param[in] va 線分aの始点から終点へのベクトル.
	 * @param[in] b1 判定する線分bの始点3D座標.
	 * @param[in] vb 線分bの始点から終点へのベクトル.
	 * @param[in] s 線分aの直線方程式パラメータ.
	 * @param[in] t 線分bの直線方程式パラメータ.
	 * @param[out] pa 線分a上の、線分bに最も近い3D座標.
	 * @param[out] pb 線分b上の、線分aに最も近い3D座標.
	 * @return なし.
	 */
	void adjustNearestPoint
	(
		const Ngl::Vector3& a1,
		const Ngl::Vector3& va,
		const Ngl::Vector3& b1,
		const Ngl::Vector3& vb,
		float				s,
		float				t,
		Ngl::Vector3&		pa,
		Ngl::Vector3&		pb
	);
	
	
	/*===========================================================================*/
	/**
	 * @brief 3D線分がボックス内に存在するかチェックする
	 * 
	 * @param[in] min ボックスの最小座標.
	 * @param[in] max ボックスの最大座標.
	 * @param[in] line0 線分の始点.
	 * @param[in] line1 線分の終点.
	 * @retval true 存在する.
	 * @retval false 存在しない.
	 */
	bool lineIsInsideBox
	(
		const Vector3& min,
		const Vector3& max,
		const Vector3& line0,
		const Vector3& line1
	);


	/*===========================================================================*/
	/**
	 * @brief 3D線分がボックスの外にあるかチェックする
	 * 
	 * @param[in] min ボックスの最小座標.
	 * @param[in] max ボックスの最大座標.
	 * @param[in] line0 線分の始点.
	 * @param[in] line1 線分の終点.
	 * @retval true 存在する.
	 * @retval false 存在しない.
	 */
	bool lineIsOutsideBox
	(
		const Vector3& min,
		const Vector3& max,
		const Vector3& line0,
		const Vector3& line1
	);

	
	/*===========================================================================*/
	/**
	 * @brief 3D線とボックスが交差するかチェックする
	 * 
	 * @param[in] min ボックスの最小座標.
	 * @param[in] max ボックスの最大座標.
	 * @param[in] rayPos レイの位置.
	 * @param[in] rayDir レイの方向.
	 * @retval true 交差する.
	 * @retval false 交差しない.
	 */
	bool rayIsIntersectBox
	(
		const Vector3& min,
		const Vector3& max,
		const Vector3& rayPos,
		const Vector3& rayDir
	);


	/*===========================================================================*/
	/**
	 * @brief レイとボックスの何らかの面が交差するかチェックする
	 * 
	 * @param[in] min ボックスの最小座標.
	 * @param[in] max ボックスの最大座標.
	 * @param[in] rayPos レイの位置.
	 * @param[in] rayDir レイの方向.
	 * @param[in] numerator 分子.
	 * @param[in] denominator 分母.
	 * @retval true 交差する.
	 * @retval false 交差しない.
	 */
	bool isIntersect
	(
		const Vector3&	min,
		const Vector3&	max,
		const Vector3&	rayPos,
		const Vector3&	rayDir,
		float			numerator,
		float			denominator
	);


	/*===========================================================================*/
	/**
	 * @brief 球体がボックス内に存在するかチェックする
	 * 
	 * @param[in] min ボックスの最小座標.
	 * @param[in] max ボックスの最大座標.
	 * @param[in] center 球体の中心座標.
	 * @param[in] radius 球体の半径.
	 * @retval true 存在する.
	 * @retval false 存在しない.
	 */
	bool sphereIsInsideBox
	(
		const Vector3&	min,
		const Vector3&	max,
		const Vector3&	center,
		float			radius
	);

	
	/*===========================================================================*/
	/**
	 * @brief ポリゴンと線分との衝突判定
	 * 
	 * @param[in] vert 頂点配列へのポインタ.
	 * @param[in] numVertices 頂点数.
	 * @param[in] planeParam 平面方程式パラメーター.
	 * @param[in] line0 線分の始点.
	 * @param[in] line1 線分の終点
	 * return param 衝突パラメーター
	 */
	const PlaneCollisionReport& polygonAndLine
	(
		const Vector3*	vert,
		unsigned int	numVertices,
		Plane&			planeParam,
		const Vector3&	line0,
		const Vector3&	line1
	);


	/*===========================================================================*/
	/**
	 * @brief ポリゴンと3D線との衝突判定
	 * 
	 * @param[in] vert 頂点配列へのポインタ.
	 * @param[in] numVertices 頂点数.
	 * @param[in] planeParam 平面方程式パラメーター.
	 * @param[in] rayPos レイの始点.
	 * @param[in] rayDir レイの方向.
	 * @return 平面データ衝突パラメーター.
	 */
	const PlaneCollisionReport& polygonAndRay
	(
		const Vector3*	vert,
		unsigned int	numVertices,
		Plane&			planeParam,
		const Vector3&	rayPos,
		const Vector3&	rayDir
	);


	/*===========================================================================*/
	/**
	 * @brief ポリゴンと球体との衝突判定
	 * 
	 * @param[in] vert 頂点配列へのポインタ.
	 * @param[in] numVertices 頂点数.
	 * @param[in] planeParam 平面方程式パラメーター.
	 * @param[in] center 球体の中心位置.
	 * @param[in] radius 球体の半径.
	 * @return 平面データ衝突パラメーター.
	 */
	const PlaneCollisionReport& polygonAndSphere
	(
		const Vector3*	vert,
		unsigned int	numVertices,
		Plane&			planeParam,
		const Vector3&	center,
		float			radius
	);


	/*===========================================================================*/
	/**
	 * @brief ポリゴンのエッジと球体との衝突判定
	 * 
	 * @param[in] vert 頂点配列へのポインタ.
	 * @param[in] numVertices 頂点数.
	 * @param[in] center 球体の中心位置.
	 * @param[in] radius 球体の半径.
	 * @return 平面データ衝突パラメーター.
	 */
	const PlaneCollisionReport& Collision::polygonEdgeAndSphere
	(
		const Vector3*	vert,
		unsigned int	numVertices,
		const Vector3&	center,
		float			radius
	);


	/*===========================================================================*/
	/**
	 * @brief ポリゴン内部に交点が存在するか
	 * 
	 * @param[in] vert 頂点配列へのポインタ.
	 * @param[in] numVertices 頂点数.
	 * @param[out] point 交点座標. 
	 * @retval true 存在する.
	 * @retval false 存在しない.
	 */
	bool isInsidePolygon
	(
		const Vector3*	vert,
		unsigned int	numVertices,
		const Vector3&	point
	);

private:

	/** 衝突判定結果構造体 */
	CollisionReport			report_;

	/** 3D線分衝突判定結果構造体 */
	LineCollisionReport		lineReport_;

	/** 面データ衝突判定構造体 */
	PlaneCollisionReport	planeReport_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/