/*******************************************************************************/
/**
 * @file Plane.cpp.
 * 
 * @brief ���ʍ\���̃\�[�X�t�@�C��.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Plane.h"
#include	"Ngl/MathUtility.h"
#include	<cfloat>

using namespace Ngl;

/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
Plane::Plane() :
	x( 0.0f ),
	y( 0.0f ),
	z( 0.0f ),
	d( 0.0f )
{}



/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] other �z��̐擪�|�C���^.
 */
Plane::Plane(float *other)
{
	x = other[0];
	y = other[1];
	z = other[2];
	d = other[3];
}
	
	
	
/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] X �ʖ@��x����.
 * @param[in] Y �ʖ@��y����.
 * @param[in] Z �ʖ@��z����.
 * @param[in] D ���_����̋���.
 */
Plane::Plane(float X, float Y, float Z, float D) :
	x( X ),
	y( Y ),
	z( Z ),
	d( D )
{}



/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] N �@���x�N�g��.
 * @param[in] D ���_����̋���.
 */
Plane::Plane(const Ngl::Vector3 &N, float D) :
	x( N.x ),
	y( N.y ),
	z( N.z ),
	d( D )
{}
	
	
	
/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] P ���ʏ�̍��W.
 * @param[in] N �@���x�N�g��.
 */
Plane::Plane(const Ngl::Vector3 &P, const Ngl::Vector3 N)
{
	createFromPointNormal( P, N );
}
	
	
	
/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] v1 ���W1.
 * @param[in] v2 ���W2.
 * @param[in] v3 ���W3.
 */
Plane::Plane(const Ngl::Vector3 &v1, const Ngl::Vector3 &v2, const Ngl::Vector3 &v3)
{
	createFromPoints( v1, v2, v3 );
}



/*===========================================================================*/
/**
 * @brief ���ʂ𐳋K������
 * 
 * @param[in] �Ȃ� .
 * @return ���K����������.
 */
Plane& Plane::normalize()
{
	// �@���x�N�g���̒��������߂�
	float length =	Ngl::sqr( x )
				  + Ngl::sqr( y )
				  + Ngl::sqr( z );

	// ������0�ȊO��
	if( length != 0 ){
		x /= length;
		y /= length;
		z /= length;
		d /= length;
	}

	return *this;
}


/*===========================================================================*/
/**
 * @brief ���ʏ�̈ʒu���擾����
 * 
 * @param[in] �Ȃ� .
 * @return �ʒu���W.
 */
Ngl::Vector3 Plane::getPoint() const
{
	Ngl::Vector3 tmp;
	tmp.x = x * -d;
	tmp.y = y * -d;
	tmp.z = z * -d;

	return tmp;
}



/*===========================================================================*/
/**
 * @brief ���ʂƃx�N�g���̓��ς����߂�
 * 
 * @param[in] v ���ς����߂�x�N�g�� .
 * @return ����.
 */
float Plane::dot(const Ngl::Vector3 &v) const
{
	return x * v.x + y * v.y + z * v.z;
}



/*===========================================================================*/
/**
 * @brief ���ʂƍ��W�Ƃ̋��������߂�
 * 
 * @param[in] v ���������߂�x�N�g�� .
 * @return ����.
 */
float Plane::distance(const Ngl::Vector3 &v) const
{
	return x * v.x + y * v.y + z * v.z + d;
}



/*===========================================================================*/
/**
 * @brief ���ʂƍ��W�̈ʒu�֌W��Ԃ�
 * 
 * @param[in] pos ���ׂ���W.
 * @return �ʒu�֌W.
 */
Plane::PlanePositionFlags Plane::getClassifyPoint(const Ngl::Vector3 &pos)
{
	// ���W�Ƃ̋��������߂�
	float dis = distance( pos );

	// ���ʂ̑O�ʂɓ_�����݂��邩
	if( dis > FLT_EPSILON ){
		return FRONT_PLANE;
	}

	// ���ʂ̔w�ʂɓ_�����݂��邩
	if( dis < -FLT_EPSILON ){
		return BEHIND_PLANE;
	}

	// ���ʏ�ɓ_�����݂���
	return ON_PLANE;
}



/*===========================================================================*/
/**
 * @brief ���ʂƋ��̂̈ʒu�֌W��Ԃ�
 * 
 * @param[in] center ���̂̒��S���W.
 * @param[in] radius ���̂̔��a.
 * @return �ʒu�֌W.
 */
Plane::PlanePositionFlags Plane::getClassifySphere(const Ngl::Vector3 &center, float radius)
{
	// ���S���W�Ƃ̋��������߂�
	float dis = distance( center );

	// ���ʂƋ��̂��������Ă��邩
	if( Ngl::abs( dis ) < radius ){
		return INTERSECTS_PLANE;
	}

	// ���ʂ̑O�ʂɋ��̂����݂��Ă��邩
	if( dis >= radius ){
		return FRONT_PLANE;
	}

	// ���ʂ̔w��ɋ��̂����݂��Ă���
	return BEHIND_PLANE;
}



/*===========================================================================*/
/**
 * @brief ���ʂƐ������������邩���ׂ�
 * 
 * @param[in] line0 �����̎n�_.
 * @param[in] line1 �����̏I�_.
 * @retval true �������Ă���.
 * @retval false �������Ă��Ȃ�.
 */
bool Plane::intersectLine(const Ngl::Vector3 &line0, const Ngl::Vector3 &line1)
{
	// ���ʂƎn�_�Ƃ̋��������߂�
	float distance1 = distance( line0 );

	// ���ʂƏI�_�Ƃ̋��������߂�
	float distance2 = distance( line1 );

	// �n�_�ƏI�_�̋������������̏ꍇ�͌������Ȃ�
	if( ( distance1 * distance2 ) > 0 ){
		return false;
	}

	return true;
}



/*===========================================================================*/
/**
 * @brief ���ʂƐ������������邩���ׂ�
 * 
 * @param[in] line0 �����̎n�_.
 * @param[in] line1 �����̏I�_.
 * @retval true �������Ă���.
 * @retval false �������Ă��Ȃ�.
 */
Ngl::Vector3 Plane::intersectLinePosition
(
	const Ngl::Vector3 &line0,
	const Ngl::Vector3 &line1,
	const Ngl::Vector3 &retVec
)
{
	// ���ʂƐ�������_�������Ȃ���
	if( intersectLine( line0, line1 ) == false ){
		return retVec;
	}

	// �����̕��������߂�
	Ngl::Vector3 dir = line1 - line0;

	// ���ʂƐ����Ƃ̌�_�����߂�
	return intersectRayPositon( line0, dir, retVec );
}



/*===========================================================================*/
/**
 * @brief ���ʂƃ��C���������邩���ׂ�
 * 
 * @param[in] rayPos ���C�̎n�_.
 * @param[in] rayDir ���C�̕���.
 * @retval true �������Ă���.
 * @retval false �������Ă��Ȃ�.
 */
bool Plane::intersectRay(const Ngl::Vector3 &rayPos, const Ngl::Vector3 &rayDir)
{
	// ���C�̕����𐳋K������
	Ngl::Vector3 normal( rayDir );
	normal.normalize();

	// ���ʂƒ��������s��
	if( dot( normal ) == 0.0f ){
		return false;
	}

	return true;
}



/*===========================================================================*/
/**
 * @brief ���ʂƃ��C�̌�_���W�����߂�
 * 
 * @param[in] rayPos ���C�̎n�_.
 * @param[in] rayDir ���C�̕���.
 * @param[in] retVec �������Ă��Ȃ��������ɖ߂�x�N�g��.
 * @retval true �������Ă���.
 * @retval false �������Ă��Ȃ�.
 */
Ngl::Vector3 Plane::intersectRayPositon
(
	const Ngl::Vector3 &rayPos,
	const Ngl::Vector3 &rayDir,
	const Ngl::Vector3 &retVec
)
{
	// ���C�̕����𐳋K������
	Ngl::Vector3 normal( rayDir );
	normal.normalize();

	// ��������߂�
	float denominator = dot( normal );

	// ���ʂƒ��������s��
	if( denominator == 0.0f ){
		return retVec;
	}

	// ���q�����߂�
	float numerator = -distance( rayPos );

	// �n�_�ƕ��ʂ̋��������߂�
	float dis = numerator / denominator;

	// ��_�����߂�
	Ngl::Vector3 intersect;
	intersect.linearEquation( rayPos, normal, dis );

	return intersect;
}



/*===========================================================================*/
/**
 * @brief ���ʏ�̍��W�ƕ��ʂ̖@���x�N�g�����畽�ʂ��쐬����
 * 
 * @param[in] point ���ʏ�̍��W.
 * @param[in] normal ���ʂ̖@���x�N�g��.
 * @return �쐬��������.
 */
Plane& Plane::createFromPointNormal(const Ngl::Vector3 &point, const Ngl::Vector3 &normal)
{
	x = normal.x;
	y = normal.y;
	z = normal.z;
	d = -normal.dot( point );

	return *this;
}



/*===========================================================================*/
/**
 * @brief ���ʏ��3�̍��W���畽�ʂ��쐬����
 * 
 * @param[in] v1 ���W1.
 * @param[in] v2 ���W2.
 * @param[in] v3 ���W3.
 * @return �쐬��������.
 */
Plane& Plane::createFromPoints(const Ngl::Vector3 &v1, const Ngl::Vector3 &v2, const Ngl::Vector3 &v3)
{
	// �@���x�N�g�������߂�
	Ngl::Vector3 normal = v1;
	normal = normal.calculateNoamal( v2, v3 );

	// �@���x�N�g���ƍ��W���畽�ʂ����߂�
	return createFromPointNormal( v1, normal );
}



/*===========================================================================*/
/**
 * @brief == ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] other ���Z���镽��.
 * @retval true ��v���Ă���.
 * @retval false ��v���Ă��Ȃ�.
 */
bool Plane::operator ==(const Ngl::Plane &other)
{
	return ( x == other.x && y == other.y && z == other.z && d == other.d );
}



/*===========================================================================*/
/**
 * @brief != ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] other ���Z���镽��.
 * @retval true ��v���Ă��Ȃ�.
 * @retval false ��v���Ă���.
 */
bool Plane::operator !=(const Ngl::Plane &other)
{
	return !(*this == other);
}



/*========= EOF =============================================================*/