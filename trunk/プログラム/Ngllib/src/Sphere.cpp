/*******************************************************************************/
/**
 * @file Sphere.cpp.
 * 
 * @brief ���̍\���̃\�[�X�t�@�C��.
 *
 * @date 2008/07/08.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Sphere.h"
#include	"Ngl/Collision.h"

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
Sphere::Sphere():
	radius( 0.0f )
{}



/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] Center ���S���W.
 * @param[in] Radius ���a�l.
 */
Sphere::Sphere( const Vector3& Center, const float Radius ):
	center( Center ),
	radius( Radius )
{}

	
	
/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] Center ���S���W�z��.
 * @param[in] Radius ���a�l.
 */
Sphere::Sphere( const float* Center, const float Radius ):
	center( Center ),
	radius( Radius )
{}

	
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
void Sphere::initialize( float X, float Y, float Z, float Radius )
{
	center.initialize( X, Y, Z );
	radius = Radius;
}
	
	
	
/*=========================================================================*/
/**
 * @brief ����������
 * 
 * @param[in] Center ���S���W.
 * @param[in] Radius ���a�l.
 * @return �Ȃ�.
 */
void Sphere::initialize( const Vector3& Center, float Radius )
{
	center = Center;
	radius = Radius;
}

	
	
/*=========================================================================*/
/**
 * @brief �P�ʋ��ɐݒ�
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void Sphere::setIdentity()
{
	// ���S�ʒu�����_�ɐݒ�
	center = VECTOR3_ZERO;

	// ���a��1.0f�ɐݒ�
	radius = 1.0f;
}

	
	
/*=========================================================================*/
/**
 * @brief ���̂Ƃ̏Փ˔���
 * 
 * @param[in] otherCenter ���肷�鋅�̂̒��S���W.
 * @param[in] otherRadius ���肷�鋅�̂̔��a�l.
 * @retval true �Փ˂��Ă���.
 * @retval false �Փ˂��Ă��Ȃ�.
 */
bool Sphere::collision( const Vector3& otherCenter, const float otherRadius )
{
	Collision collision;
	return collision.sphereAndSphere( center, radius, otherCenter, otherRadius );
}


	
/*=========================================================================*/
/**
 * @brief ���̂Ƃ̏Փ˔���
 * 
 * @param[in] other ���肷�鋅��.
 * @retval true �Փ˂��Ă���.
 * @retval false �Փ˂��Ă��Ȃ�.
 */
bool Sphere::collision( const Sphere& other )
{
	return collision( other.center, other.radius );
}

	
	
/*===== EOF ==================================================================*/