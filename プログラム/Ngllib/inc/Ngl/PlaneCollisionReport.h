/*******************************************************************************/
/**
 * @file PlaneCollisionReport.h.
 * 
 * @brief 面データ衝突結果構造体定義.
 *
 * @date 2008/07/17.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_PLANECOLLISIONREPORT_H_
#define _NGL_PLANECOLLISIONREPORT_H_

#include	"Vector3.h"
#include	"Plane.h"

namespace Ngl{


/**
 * @struct PlaneCollisionReport．
 * @brief 面データ衝突結果構造体.
 */
struct PlaneCollisionReport
{
	/** 衝突したか */
	bool	isCollision;

	/** 交点座標 */
	Vector3	intersect;

	/** 交点座標までの距離 */
	float	distanceSq;

	/** 衝突面データ情報 */
	Plane	planeParam;
};


/** 衝突していない面データ衝突結果構造体 */
static const PlaneCollisionReport PLANECOLLISIONREPORT_NOT_COLLISION = { false, Vector3( 0.0f, 0.0f, 0.0f ), 0.0f, Plane( 0.0f, 0.0f, 0.0f, 0.0f ) };

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/