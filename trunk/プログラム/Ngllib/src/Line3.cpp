/*******************************************************************************/
/**
 * @file Line3.cpp.
 * 
 * @brief 3���������\���̃\�[�X�t�@�C��.
 *
 * @date 2008/07/12.
 * 
 * @version 2.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Line3.h"
#include	"Ngl/Collision.h"
#include	"Ngl/Vector3.h"
#include	"Ngl/MathUtility.h"
#include	<cfloat>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
Line3::Line3()
{}



/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] Begin �J�n�ʒu3D���W.
 * @param[in] End �I���ʒu3D���W.
 */
Line3::Line3( const Vector3& Begin, const Vector3& End ):
	begin( Begin ),
	end( End )
{}
	
	

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] Begin �J�n�ʒu���W�z��.
 * @param[in] End �I���ʒu���W�z��.
 */
Line3::Line3( const float* Begin, const float* End )
{
	begin.initialize( Begin[ 0 ], Begin[ 1 ], Begin[ 2 ] );
	end.initialize( End[ 0 ], End[ 1 ], End[ 2 ] );
}

	
		
/*=========================================================================*/
/**
 * @brief ����������
 * 
 * @param[in] x �n�_x���W.
 * @param[in] y �n�_y���W.
 * @param[in] z �n�_z���W.
 * @param[in] eX �I�_x���W.
 * @param[in] eY �I�_y���W.
 * @param[in] eZ �I�_z���W.
 * @return �Ȃ�.
 */
void Line3::initialize( float x, float y, float z, float eX, float eY, float eZ )
{
	begin.initialize( x, y, z );
	end.initialize( eX, eY, eZ );
}


	
/*=========================================================================*/
/**
 * @brief ����������
 * 
 * @param[in] Begin �J�n�ʒu3D���W.
 * @param[in] End �I���ʒu3D���W.
 * @return �Ȃ�.
 */
void Line3::initialize( const Vector3& Begin, const Vector3& End )
{
	begin = Begin;
	end = End;
}
	
	

/*=========================================================================*/
/**
 * @brief �����̃x�N�g�������߂�
 * 
 * @param[in] �Ȃ�.
 * @return �����̃x�N�g��.
 */
Vector3 Line3::getVector()
{
	Vector3 result = begin - end;
	return result;
}	
	
	
	
/*=========================================================================*/
/**
 * @brief 3D�����Ƃ̏Փ˔���
 * 
 * @param[in] otherBegin ���肷��3D�����̎n�_���W.
 * @param[in] otherEnd ���肷��3D�����̏I�_���W.
 * @param[in] epsilon �����臒l.
 * @return �Փ˔��茋�ʍ\����.
 */
const LineCollisionReport& Line3::collision( const Vector3& otherBegin, const Vector3& otherEnd, float epsilon )
{
	Collision collision;
	return collision.lineAndLine( begin, end, otherBegin, otherEnd, false, epsilon );
}

	
	
/*=========================================================================*/
/**
 * @brief 3D�����Ƃ̏Փ˔���
 * 
 * @param[in] other ���肷��3D����.
 * @param[in] epsilon �����臒l.
 * @return �Փ˔��茋�ʍ\����.
 */
const LineCollisionReport&  Line3::collision( const Line3& other, float epsilon )
{
	return collision( other.begin, other.end, epsilon );
}

	
	
/*=========================================================================*/
/**
 * @brief �����ƁA�w����W�̍ł��אڂ��������̍��W�p�����[�^�����߂�
 * 
 * @param[in] x, ���߂���W��x���W.
 * @param[in] y, ���߂���W��y���W.
 * @param[in] z, ���߂���W��z���W.
 * @return ���W�p�����[�^.
 */
float Line3::getNearestPointParameter( float x, float y, float z )
{
	// �����̃x�N�g�������߂�
	Vector3 vec = getVector();

	// �x�N�g���̒��������߂�
	float length = vec.lengthSq();

	// �����̒�����臒l������������
	if( length < FLT_EPSILON ){
		return 0.0f;
	}

	// �����̎n�_����w����W�ւ̃x�N�g�������߂�
	Vector3 point( x, y, z );
	Vector3 lp = point - begin;

	// ���ׂ������W�ɍł��߂����W�ւ̃p�����[�^�����߂�
	float t = vec.dot( lp ) / length;

	// �p�����[�^���N�����v
	return clamp( t, 0.0f, 1.0f );
}



/*=========================================================================*/
/**
 * @brief �����ƁA�w����W�ɍł��אڂ��������̍��W�����߂�
 * 
 * @param[in] x, ���߂���W��x���W.
 * @param[in] y, ���߂���W��y���W.
 * @param[in] z, ���߂���W��z���W.
 * @return �ł��אڂ�����W.
 */
Vector3 Line3::findNearestPoint( float x, float y, float z )
{
	// �ł��߂����W�ւ̃p�����[�^�����߂�
	float t = getNearestPointParameter( x, y, z );

	// ���߂��p�����[�^����ł��߂����W�����߂�
	Vector3 result;
	result.linearEquation( begin, getVector(), t );

	return result;
}

	
	
/*===== EOF ==================================================================*/