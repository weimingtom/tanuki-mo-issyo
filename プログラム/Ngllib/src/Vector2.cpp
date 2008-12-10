/*******************************************************************************/
/**
 * @file Vector2.cpp.
 * 
 * @brief �Q�����x�N�g���\���̃\�[�X�t�@�C��.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	<Ngl/Vector2.h>
#include	<Ngl/MathUtility.h>

using namespace Ngl;

/*==== �萔�錾 =============================================================*/

/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
Vector2::Vector2() :
	x( 0.0f ),
	y( 0.0f )
{}



/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] other �z��̃|�C���^.
 */
Vector2::Vector2(const float *other)
{
	x = other[0];
	y = other[1];
}

	
	
/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] X x����.
 * @param[in] Y y����.
 */
Vector2::Vector2( float X, float Y ) :
	x( X ), y( Y )
{
}



/*===========================================================================*/
/**
 * @brief 0.0�ɏ���������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void Vector2::zero()
{
	x = 0.0f;
	y = 0.0f;
}


	
/*===========================================================================*/
/**
 * @brief ����������
 * 
 * @param[in] X x����.
 * @param[in] Y y����.
 * @return �Ȃ�.
 */
void Vector2::initialize(float X, float Y)
{
	x = X;
	y = Y;
}

	
	
/*===========================================================================*/
/**
 * @brief �m���������߂�
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
float Vector2::length() const
{
	return	Ngl::sqrt( x * x + y * y );
}



/*===========================================================================*/
/**
 * @brief ���K������
 * 
 * @param[in] �Ȃ�.
 * @return ���K�������x�N�g��.
 */
Vector2& Vector2::normalize()
{
	float len = length();
	if ( len != 0 ) {
		return *this /= length();
	}
	return *this;
}



/*===========================================================================*/
/**
 * @brief ���ς����߂�
 * 
 * @param[in] v ���ς����߂�x�N�g��.
 * @return ����.
 */
float Vector2::dot( const Vector2& v ) const
{
	return	x * v.x + y * v.y;
}



/*===========================================================================*/
/**
 * @brief �x�N�g���Ԃ̋��������߂�
 * 
 * @param[in] other ���������߂�x�N�g��.
 * @return ���߂��x�N�g��.
 */
float Vector2::distance( const Ngl::Vector2& other )
{
	// 2�̃x�N�g���̍������߂�
	Vector2 v = *this - other;

	// �x�N�g���̒�����Ԃ�
	return v.length();
}



/*===========================================================================*/
/**
 * @brief �x�N�g���̐��`��Ԃ��s��
 * 
 * @param[in] min �ŏ��l.
 * @param[in] max �ő�l.
 * @param[in] t ��Ԓl( 0.0f�`1.0f ).
 * @return ���ʂ̃x�N�g��.
 */
Vector2& Vector2::lerp(const Vector2 &min, const Vector2 &max, float t)
{
	x = Ngl::lerp( t, min.x, max.x );
	y = Ngl::lerp( t, min.y, max.y );

	return *this;
}



/*===========================================================================*/
/**
 * @brief �x�N�g����2����Ԃ��s��
 * 
 * @param[in] v1 ��ԗv�f2�����x�N�g��.
 * @param[in] v2 ��ԗv�f2�����x�N�g��.
 * @param[in] v3 2�����x�N�g��.
 * @param[in] t ��Ԓl( 0.0f�`1.0f ).
 * @return ���ʂ̃x�N�g��.
 */
Vector2& Vector2::quadratic(const Vector2 &v1, const Vector2 &v2, const Vector2 &v3, float t)
{
	x = Ngl::quadratic( t, v1.x, v2.x, v3.x );
	y = Ngl::quadratic( t, v1.y, v2.y, v3.y );

	return *this;
}



/*===========================================================================*/
/**
 * @brief + ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
Vector2 Vector2::operator + () const
{
	return	*this;
}



/*===========================================================================*/
/**
 * @brief - ���Z�q�I�[�o�[���[�h �t�x�N�g�������߂�
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
Vector2 Vector2::operator - () const
{
	return	Vector2( -x, -y );
}



/*===========================================================================*/
/**
 * @brief += ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v ���Z����x�N�g��.
 * @return ���Z���ʂ̃x�N�g��.
 */
Vector2& Vector2::operator += ( const Vector2& v )
{
	x += v.x;
	y += v.y;
	return	*this;
}



/*===========================================================================*/
/**
 * @brief -= ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v ���Z����x�N�g��.
 * @return ���Z���ʂ̃x�N�g��.
 */
Vector2& Vector2::operator -= ( const Vector2& v )
{
	x -= v.x;
	y -= v.y;
	return	*this;
}



/*===========================================================================*/
/**
 * @brief *=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v ��Z����x�N�g��.
 * @return ���Z���ʂ̃x�N�g��.
 */
Vector2& Vector2::operator *=(const Ngl::Vector2 &v)
{
	x *= v.x;
	y *= v.y;

	return *this;
}


/*===========================================================================*/
/**
 * @brief *= ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] s ��Z����X�J���[�l.
 * @return ��Z���ʂ̃x�N�g��.
 */
Vector2& Vector2::operator *= ( float s )
{
	x *= s;
	y *= s;
	return	*this;
}



/*===========================================================================*/
/**
 * @brief /=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v ���Z����x�N�g��.
 * @return ���Z���ʂ̃x�N�g��.
 */
Vector2& Vector2::operator /=(const Ngl::Vector2 &v)
{
	x /= v.x;
	y /= v.y;

	return *this;
}



/*===========================================================================*/
/**
 * @brief /= ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] s ���Z����X�J���[�l.
 * @return ���Z���ʂ̃x�N�g��.
 */
Vector2& Vector2::operator /= ( float s )
{
	x /= s;
	y /= s;
	return	*this;
}


/*===========================================================================*/
/**
 * @brief float*���Z�q�I�[�o�[���[�h
 * 
 * @param[in] �Ȃ�.
 * @return �L���X�g�����l.
 */
Vector2::operator float *() const
{
	return ( float* )this;
}



/*===========================================================================*/
/**
 * @brief float*���Z�q�I�[�o�[���[�h
 * 
 * @param[in] �Ȃ�.
 * @return �L���X�g�����l.
 */
Vector2::operator const float *() const
{
	return ( const float* )this;
}



/*===========================================================================*/
/**
 * @brief + ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ���Z����x�N�g��1.
 * @param[in] v2 ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Vector2 operator + ( const Vector2& v1, const Vector2& v2 )
{
	Vector2	temp(v1);
	return	temp += v2;
}



/*===========================================================================*/
/**
 * @brief - ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ���Z����x�N�g��1.
 * @param[in] v2 ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Vector2 operator - ( const Vector2& v1, const Vector2& v2 )
{
	Vector2	temp(v1);
	return	temp -= v2;
}



/*===========================================================================*/
/**
 * @brief *���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v1 ���Z����x�N�g��1.
 * @param[in] v2 ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Vector2 operator * (const Vector2 &v1, const Vector2 &v2)
{
	Vector2 temp(v1);
	return temp *= v2;
}



/*===========================================================================*/
/**
 * @brief * ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v ��Z����x�N�g��.
 * @param[in] s ��Z����X�J���[�l.
 * @return ��Z���ʂ̃x�N�g��.
 */
const Vector2 operator * ( const Vector2& v, float s )
{
	Vector2	temp(v);
	return	temp *= s;
}



/*===========================================================================*/
/**
 * @brief * ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] s ��Z����X�J���[.
 * @param[in] v ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Vector2 operator * ( float s, const Vector2& v )
{
	return	v * s;
}



/*===========================================================================*/
/**
 * @brief /���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v1 ���Z����x�N�g��1.
 * @param[in] v2 ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Vector2 operator / (const Vector2 &v1, const Vector2 &v2)
{
	Vector2 temp( v1 );
	return temp /= v2;
}


/*===========================================================================*/
/**
 * @brief / ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v ���Z����x�N�g��.
 * @param[in] s ���Z����X�J���[.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Vector2 operator / ( const Vector2& v, float s )
{
	Vector2	temp(v);
	return	temp /= s;
}



/*===========================================================================*/
/**
 * @brief ==���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l, false �Ⴄ�l.
 */
bool operator == (const Vector2 &v1, const Vector2 &v2)
{
	return ( v1.x == v2.x && v1.y == v2.y );
}



/*===========================================================================*/
/**
 * @brief !=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l, false �Ⴄ�l.
 */
bool operator != (const Vector2 &v1, const Vector2 &v2)
{
	return !( v1 == v2 );
}



/*===========================================================================*/
/**
 * @brief <���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l,
 */
bool operator < (const Vector2 &v1, const Vector2 &v2)
{
	if( v1.x >= v2.x ) return false;
	if( v1.y >= v2.y ) return false;

	return true;
}



/*===========================================================================*/
/**
 * @brief <���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l,
 */
bool operator > (const Vector2 &v1, const Vector2 &v2)
{
	if ( v1.x <= v2.x ) return false;
	if ( v1.y <= v2.y ) return false;

	return	true;
}



/*===========================================================================*/
/**
 * @brief <=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l,
 */
bool operator <= (const Vector2 &v1, const Vector2 &v2)
{
	return !( v1 > v2 );
}



/*===========================================================================*/
/**
 * @brief >=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l,
 */
bool operator >= (const Vector2 &v1, const Vector2 &v2)
{
	return !( v1 < v2 );
}



/*========= EOF =============================================================*/