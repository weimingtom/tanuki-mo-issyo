/*******************************************************************************/
/**
 * @file IMeshCollision.h.
 * 
 * @brief ���b�V���f�[�^�Փ˔���N���X�C���^�[�t�F�[�X��`.
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
 * @class IMeshCollision�D
 * @brief ���b�V���f�[�^�Փ˔���N���X�C���^�[�t�F�[�X.
 */
class IMeshCollision
{

public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~IMeshCollision() {}


	/*===========================================================================*/
	/**
	 * @brief �����Ƃ̏Փ˔���
	 * 
	 * @param[in] line0 �����̎n�_.
	 * @param[in] line1 �����̏I�_.
	 * @return �Փˌ��ʍ\���̂̎Q��.
	 */
	virtual const PlaneCollisionReport& line( const float* line0, const float* line1 ) = 0;


	/*===========================================================================*/
	/**
	 * @brief �w��̃|���S���Ɛ����Ƃ̏Փ˔���
	 * 
	 * @param[in] polygonNo �|���S���f�[�^�ԍ�.
	 * @param[in] line0 �����̎n�_.
	 * @param[in] line1 �����̏I�_.
	 * @return �Փˌ��ʍ\���̂̎Q��.
	 */
	virtual const PlaneCollisionReport& polygonAndLine( int polygonNo, const float* line0, const float* line1 ) = 0;


	/*===========================================================================*/
	/**
	 * @brief 3D���Ƃ̏Փ˔���
	 * 
	 * @param[in] rayPos 3D���̎n�_���W.
	 * @param[in] rayDir 3D���̕���.
	 * @return �ʃf�[�^�Փ˃p�����[�^�[.
	 */
	virtual const PlaneCollisionReport& ray( const float* rayPos, const float* rayDir ) = 0;


	/*===========================================================================*/
	/**
	 * @brief �w��̃|���S����3D���Ƃ̏Փ˔���
	 * 
	 * @param[in] polygonNo �|���S���f�[�^�ԍ�.
	 * @param[in] rayPos 3D���̎n�_���W.
	 * @param[in] rayDir 3D���̕���.
	 * @return �ʃf�[�^�Փ˃p�����[�^�[.
	 */
	virtual const PlaneCollisionReport& polygonAndRay( int polygonNo, const float* rayPos, const float* rayDir ) = 0;


	/*===========================================================================*/
	/**
	 * @brief ���̂Ƃ̏Փ˔���
	 * 
	 * @param[in] center ���̂̒��S�ʒu.
	 * @param[in] radius ���̂̔��a.
	 * @return �ʃf�[�^�Փ˃p�����[�^�[.
	 */
	virtual const PlaneCollisionReport& sphere( const float* center, float radius ) = 0;


	/*===========================================================================*/
	/**
	 * @brief �w��̃|���S���Ƌ��̂Ƃ̏Փ˔���
	 * 
	 * @param[in] polygonNo �|���S���f�[�^�ԍ�.
	 * @param[in] center ���̂̒��S�ʒu.
	 * @param[in] radius ���̂̔��a.
	 * @return �ʃf�[�^�Փ˃p�����[�^�[.
	 */
	virtual const PlaneCollisionReport& polygonAndSphere( int polygonNo, const float* center, float radius ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/