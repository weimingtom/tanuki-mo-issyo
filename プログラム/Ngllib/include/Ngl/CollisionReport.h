/*******************************************************************************/
/**
 * @file CollisionReport.h.
 * 
 * @brief 衝突結果構造体定義.
 *
 * @date 2008/07/17.
 * 
 * @version 1.02.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_COLLISIONREPORT_H_
#define _NGL_COLLISIONREPORT_H_

#include	"Vector3.h"
#include	"Plane.h"

namespace Ngl{


/*=============================================================================*
 *
 * struct CollisionReport
 *
 *=============================================================================*/

/**
 * @struct CollisionReport．
 * @brief 衝突結果構造体.
 */
struct CollisionReport
{
	/** 衝突したか */
	bool	isCollision;

	/** 交点座標 */
	Vector3	intersect;
};


/** 衝突していない衝突結果構造体 */
static const CollisionReport COLLISIONREPORT_NOT_COLLISION = { false, VECTOR3_ZERO };



/*=============================================================================*
 *
 * struct LineCollisionReport
 *
 *=============================================================================*/

/**
 * @struct LineCollisionReport．
 * @brief 3D線分衝突結果構造体.
 */
struct LineCollisionReport
{
	/** 衝突したか */
	bool	isCollision;

	/** 線分a上の線分bに最も近い座標 */
	Vector3	intersectPosA;

	/** 線分b上の線分aに最も近い座標 */
	Vector3 intersectPosB;
};


/** 衝突していない3D線分衝突判定結果構造体 */
static const LineCollisionReport LINECOLLISIONREPORT_NOT_COLLISION = { false, VECTOR3_ZERO, VECTOR3_ZERO };



/*=============================================================================*
 *
 * struct PlaneCollisionReport
 *
 *=============================================================================*/

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