/*******************************************************************************/
/**
 * @file Ray.cpp.
 * 
 * @brief 3�������������\���̒�`�\�[�X�t�@�C��.
 *
 * @date 2008/07/12.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Ray.h"
#include	"Ngl/Sphere.h"
#include	"Ngl/Collision.h"
#include	"Ngl/Vector3.h"
#include	<cfloat>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
Ray::Ray()
{}



/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] pos �n�_���W.
 * @param[in] dir �����x�N�g��.
 */
Ray::Ray( const Vector3& pos, const Vector3& dir ):
	position( pos ),
	direction( dir )
{}

	
	
/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] pos �n�_���W�z��.
 * @param[in] dir �����x�N�g���z��.
 */
Ray::Ray( const float* pos, const float* dir ):
	position( pos ),
	direction( dir )
{}

	
	
/*=========================================================================*/
/**
 * @brief ����������
 * 
 * @param[in] x �n�_x���W.
 * @param[in] y �n�_y���W.
 * @param[in] z �n�_z���W.
 * @param[in] DirX �����x�N�g��x���W.
 * @param[in] DirY �����x�N�g��y���W.
 * @param[in] DirZ �����x�N�g��z���W.
 * @return �Ȃ�.
 */
void Ray::initialize( float x, float y, float z, float DirX, float DirY, float DirZ )
{
	// �ʒu���W��������
	position.initialize( x, y, z );

	// ������������
	direction.initialize( DirX, DirY ,DirZ );
}



/*=========================================================================*/
/**
 * @brief ����������
 * 
 * @param[in] pos �n�_���W.
 * @param[in] dir �����x�N�g��.
 * @return �Ȃ�.
 */
void Ray::initialize( const Vector3& pos, const Vector3& dir )
{
	position = pos;
	direction = dir;
}


	
/*=========================================================================*/
/**
 * @brief ���̂Ƃ̏Փ˔���
 * 
 * @param[in] center ���肷�鋅�̂̒��S���W.
 * @param[in] radius ���肷�鋅�̂̔��a.
 * @retval true �Փ˂��Ă���.
 * @retval false �Փ˂��Ă��Ȃ�.
 */
bool Ray::collision( const Vector3& center, float radius )
{
	Collision collision;
	return collision.sphereAndRay( center, radius, position, direction );
}

	
	
/*=========================================================================*/
/**
 * @brief ���̂Ƃ̏Փ˔���
 * 
 * @param[in] sphere ���肷�鋅��.
 * @retval true �Փ˂��Ă���.
 * @retval false �Փ˂��Ă��Ȃ�.
 */
bool Ray::collision( const Sphere& sphere )
{
	return collision( sphere.center, sphere.radius );
}

	
	
/*=========================================================================*/
/**
 * @brief 3D���Ƃ̏Փ˔���
 * 
 * @param[in] pos ���肷��3D���̈ʒu.
 * @param[in] dir ���肷��.
 * @param[in] epsilon 臒l.
 * @return �Փ˔��茋�ʍ\����.
 */
const LineCollisionReport&  Ray::collision( const Vector3& pos, const Vector3& dir, float epsilon )
{
	Collision collision;
	return collision.lineAndLine( position, direction, pos, dir, true, epsilon );
}

	
	
/*=========================================================================*/
/**
 * @brief 3D���Ƃ̏Փ˔���
 * 
 * @param[in] other ���肷��3D��.
 * @param[in] epsilon 臒l.
 * @return �Փ˔��茋�ʍ\����.
 */
const LineCollisionReport& Ray::collision( const Ray& other, float epsilon )
{
	return collision( other.position, other.direction, epsilon );
}

	
	
/*=========================================================================*/
/**
 * @brief ���������Ǝw����W�̂����Ƃ��߂����������̍��W�����߂�
 * 
 * @param[in] x ���߂����ʒu��x���W.
 * @param[in] y ���߂����ʒu��y���W.
 * @param[in] z ���߂����ʒu��z���W.
 * @return �ł��߂����W.
 */
Vector3 Ray::findNearestPosition( float x, float y, float z )
{
	// ���������̒��������߂�
	float length = direction.lengthSq();

	// �����̃x�N�g���̒�����臒l������������
	if( length < FLT_EPSILON ){
		// �n�_����ԋ߂�
		return position;
	}

	// ���������̎n�_����w����W�ւ̃x�N�g�������߂�
	Vector3 point = Vector3( x, y, z );
	Vector3 lp =  point - position;

	// ����������̒��ׂ������W�ɍł��߂����W�����߂�
	float t = direction.dot( lp ) / length;
	Vector3 result;
	return result.linearEquation( point, direction, t );
}

	
	
/*===== EOF ==================================================================*/