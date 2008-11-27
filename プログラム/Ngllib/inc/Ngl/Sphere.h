/*******************************************************************************/
/**
 * @file Sphere.h.
 * 
 * @brief ���̍\���̃w�b�_�t�@�C��.
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
 * @struct Sphere�D
 * @brief ���̍\����.
 */
typedef struct Sphere
{
	/** ���S���W */
	Vector3		center;

	/** ���a�l */
	float		radius;


#ifdef __cplusplus


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	Sphere();


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] Center ���S���W.
	 * @param[in] Radius ���a�l.
	 */
	Sphere( const Vector3& Center, const float Radius );

	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] Center ���S���W�z��.
	 * @param[in] Radius ���a�l.
	 */
	Sphere( const float* Center, const float Radius );

	
	/*=========================================================================*/
	/**
	 * @brief ����������
	 * 
	 * @param[in] X ���S���W��X���W.
	 * @param[in] Y ���S���W��X���W.
	 * @param[in] Z ���S���W��X���W.
	 * @param[in] Radius ���a�l.
	 * @return �Ȃ�.
	 */
	void initialize( float X, float Y, float Z, float Radius );


	/*=========================================================================*/
	/**
	 * @brief ����������
	 * 
	 * @param[in] Center ���S���W.
	 * @param[in] Radius ���a�l.
	 * @return �Ȃ�.
	 */
	void initialize( const Vector3& Center, float Radius );

	
	/*=========================================================================*/
	/**
	 * @brief �P�ʋ��ɐݒ�
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void setIdentity();

	
	/*=========================================================================*/
	/**
	 * @brief ���̂Ƃ̏Փ˔���
	 * 
	 * @param[in] otherCenter ���肷�鋅�̂̒��S���W.
	 * @param[in] otherRadius ���肷�鋅�̂̔��a�l.
	 * @retval true �Փ˂��Ă���.
	 * @retval false �Փ˂��Ă��Ȃ�.
	 */
	bool collision( const Vector3& otherCenter, const float otherRadius );


	/*=========================================================================*/
	/**
	 * @brief ���̂Ƃ̏Փ˔���
	 * 
	 * @param[in] other ���肷�鋅��.
	 * @retval true �Փ˂��Ă���.
	 * @retval false �Փ˂��Ă��Ȃ�.
	 */
	bool collision( const Sphere& other );


#endif


} NGLsphere;


#ifdef __cplusplus

/** �P�ʋ� */
static const Sphere SPHERE_IDENTITY = Sphere( VECTOR3_ZERO, 1.0f );


} // namespace Ngl
#endif


#endif


/*===== EOF ==================================================================*/