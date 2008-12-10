/*******************************************************************************/
/**
 * @file CollisionReport.h.
 * 
 * @brief �Փˌ��ʍ\���̒�`.
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
 * @struct CollisionReport�D
 * @brief �Փˌ��ʍ\����.
 */
struct CollisionReport
{
	/** �Փ˂����� */
	bool	isCollision;

	/** ��_���W */
	Vector3	intersect;
};


/** �Փ˂��Ă��Ȃ��Փˌ��ʍ\���� */
static const CollisionReport COLLISIONREPORT_NOT_COLLISION = { false, VECTOR3_ZERO };



/*=============================================================================*
 *
 * struct LineCollisionReport
 *
 *=============================================================================*/

/**
 * @struct LineCollisionReport�D
 * @brief 3D�����Փˌ��ʍ\����.
 */
struct LineCollisionReport
{
	/** �Փ˂����� */
	bool	isCollision;

	/** ����a��̐���b�ɍł��߂����W */
	Vector3	intersectPosA;

	/** ����b��̐���a�ɍł��߂����W */
	Vector3 intersectPosB;
};


/** �Փ˂��Ă��Ȃ�3D�����Փ˔��茋�ʍ\���� */
static const LineCollisionReport LINECOLLISIONREPORT_NOT_COLLISION = { false, VECTOR3_ZERO, VECTOR3_ZERO };



/*=============================================================================*
 *
 * struct PlaneCollisionReport
 *
 *=============================================================================*/

/**
 * @struct PlaneCollisionReport�D
 * @brief �ʃf�[�^�Փˌ��ʍ\����.
 */
struct PlaneCollisionReport
{
	/** �Փ˂����� */
	bool	isCollision;

	/** ��_���W */
	Vector3	intersect;

	/** ��_���W�܂ł̋��� */
	float	distanceSq;

	/** �Փ˖ʃf�[�^��� */
	Plane	planeParam;
};


/** �Փ˂��Ă��Ȃ��ʃf�[�^�Փˌ��ʍ\���� */
static const PlaneCollisionReport PLANECOLLISIONREPORT_NOT_COLLISION = { false, Vector3( 0.0f, 0.0f, 0.0f ), 0.0f, Plane( 0.0f, 0.0f, 0.0f, 0.0f ) };


} // namespace Ngl

#endif

/*===== EOF ==================================================================*/