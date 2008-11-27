/*******************************************************************************/
/**
 * @file PlaneCollisionReport.h.
 * 
 * @brief �ʃf�[�^�Փˌ��ʍ\���̒�`.
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