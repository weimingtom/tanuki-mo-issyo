/*******************************************************************************/
/**
 * @file Vector4.cpp.
 * 
 * @brief 4�����x�N�g���\���̃\�[�X�t�@�C��.
 *
 * @date 2008/07/02.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Vector4.h"
#include	"Ngl/Vector3.h"
#include	"Ngl/Matrix4.h"
#include	"Ngl/MathUtility.h"

using namespace Ngl;


/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
Vector4::Vector4():
	x( 0.0f ),
	y( 0.0f ),
	z( 0.0f ),
	w( 0.0f )
{}



/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] X x�l.
 * @param[in] Y y�l.
 * @param[in] Z z�l.
 * @param[in] W w�l.
 */
Vector4::Vector4( float X, float Y, float Z, float W ):
	x( X ),
	y( Y ),
	z( Z ),
	w( W )
{}



/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] V 3�����x�N�g��.
 * @param[in] W w�l.
 */
Vector4::Vector4( const Vector3& V, float W ):
	x( V.x ),
	y( V.y ),
	z( V.z ),
	w( W )
{}

	
	
/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] other �������z��.
 */
Vector4::Vector4( float* other ):
	x( other[ 0 ] ),
	y( other[ 1 ] ),
	z( other[ 2 ] ),
	w( other[ 3 ] )
{}



/*=========================================================================*/
/**
 * @brief 0.0�ɏ���������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void Vector4::zero()
{
	initialize( 0.0f, 0.0f, 0.0f, 0.0f );
}



/*=========================================================================*/
/**
 * @brief ����������
 * 
 * @param[in] X x�l.
 * @param[in] Y y�l.
 * @param[in] Z z�l.
 * @param[in] W w�l.
 * @return �Ȃ�.
 */
void Vector4::initialize( float X, float Y, float Z, float W )
{
	x = X;
	y = Y;
	z = Z;
	w = W;
}



/*=========================================================================*/
/**
 * @brief �m���������߂�
 * 
 * @param[in] �Ȃ�.
 * @return �m����.
 */
float Vector4::length() const
{
	return Ngl::sqrt( lengthSq() );
}



/*=========================================================================*/
/**
 * @brief �m���������߂�(���[�g���Ƃ�Ȃ�)
 * 
 * @param[in] �Ȃ�.
 * @return �m����(�Q��a�̂�).
 */
float Vector4::lengthSq() const
{
	return ( x * x + y * y + z * z + w * w );
}



/*=========================================================================*/
/**
 * @brief ���K������
 * 
 * @param[in] �Ȃ�.
 * @return ���K�������x�N�g��.
 */
Vector4& Vector4::normalize()
{
	float len = length();
	if( len != 0.0f ){
		return *this /= len;
	}
	return *this;
}



/*=========================================================================*/
/**
 * @brief ���ς����߂�
 * 
 * @param[in] v �v�Z����x�N�g��.
 * @return ���ς̒l.
 */
float Vector4::dot( const Vector4& v ) const
{
	return ( x * v.x + y * v.y + z * v.z + w * v.w );
}
	
	
	
/*=========================================================================*/
/**
 * @brief �p�ƕ��ʊp����x�N�g�������߂�
 * 
 * @param[in] elevation �p.
 * @param[in] direction ���ʊp.
 * @return ���߂��x�N�g��.
 */
Vector4& Vector4::fromEleDir( float elevation, float direction )
{
	x =  Ngl::cos( elevation ) * Ngl::sin( direction );
	y = -Ngl::sin( elevation );
	z =  Ngl::cos( elevation ) * Ngl::cos( direction );
	w = 1.0f;

	return *this;
}



/*=========================================================================*/
/**
 * @brief �s�b�`�p�ƃ��[�p����x�N�g�������߂�
 * 
 * @param[in] pitch �s�b�`�p.
 * @param[in] yaw ���[�p.
 * @return ���߂��x�N�g��.
 */
Vector4& Vector4::fromPitchYaw( float pitch, float yaw )
{
	return fromEleDir( pitch, yaw );
}



/*=========================================================================*/
/**
 * @brief �x�N�g�����m�̋��������߂�
 * 
 * @param[in] other ���������߂�x�N�g��.
 * @return �x�N�g���̋���.
 */
float Vector4::distance( const Vector4& other )
{
	Vector4 tmp = *this - other;
	return tmp.length();
}



/*=========================================================================*/
/**
 * @brief �x�N�g�����m�̋��������߂�(���[�g�����Ȃ�)
 * 
 * @param[in] other ���������߂�x�N�g��.
 * @return �x�N�g���̋���(�Q��a�̂�).
 */
float Vector4::distanceSq( const Vector4& other )
{
	Vector4 tmp = *this - other;
	return tmp.lengthSq();
}


	
/*=========================================================================*/
/**
 * @brief �x�N�g�����m�����p�x�����߂�
 * 
 * @param[in] other �p�x�����߂鑊��x�N�g��.
 * @return �p�x.
 */
float Vector4::innerDegree( const Vector3& other )
{
	float cos_theta = dot( other ) / ( length() * other.length() );

	float angle = Ngl::acos( Ngl::clamp( cos_theta, -1.0f, 1.0f ) );

	return	angle;
}

	
	
/*=========================================================================*/
/**
 * @brief �����̕������̌v�Z���s��
 * 
 * @param[in] p �x�N�g��1.
 * @param[in] v �x�N�g��2.
 * @param[in] t �W��.
 * @return ���ʂ̃x�N�g��.
 */
Vector4 Vector4::linearEquation( const Vector4& p, const Vector4& v, float t )
{
	x = v.x * t + p.x;
	y = v.y * t + p.y;
	z = v.z * t + p.z;
	w = v.w * t + p.w;

	return	*this;
}

	
	
/*=========================================================================*/
/**
 * @brief �x�N�g���̐��`��Ԃ��s��
 * 
 * @param[in] min �ŏ��l.
 * @param[in] max �ő�l.
 * @param[in] t ��Ԓl( 0.0f�`1.0f ).
 * @return ���ʂ̃x�N�g��.
 */
Vector4& Vector4::lerp( const Vector4& min, const Vector4& max, float t )
{
	x = Ngl::leap( t, min.x, max.x );
	y = Ngl::leap( t, min.y, max.y );
	z = Ngl::leap( t, min.z, max.z );
	w = Ngl::leap( t, min.w, max.w );

	return	*this;
}



/*=========================================================================*/
/**
 * @brief �x�N�g����2����Ԃ��s��
 * 
 * @param[in] v1 ��ԗv�f4�����x�N�g��.
 * @param[in] v2 ��ԗv�f4�����x�N�g��.
 * @param[in] v3 ��ԗv�f4�����x�N�g��.
 * @param[in] t ��Ԓl( 0.0f�`1.0f ).
 * @return ���ʂ̃x�N�g��.
 */
Vector4& Vector4::quadratic( const Vector4& v1, const Vector4& v2, const Vector4& v3, float t )
{
	x = Ngl::quadratic( t, v1.x, v2.x, v3.x );
	y = Ngl::quadratic( t, v1.y, v2.y, v3.y );
	z = Ngl::quadratic( t, v1.z, v2.z, v3.z );
	w = Ngl::quadratic( t, v1.w, v2.w, v3.w );

	return	*this;
}



/*=========================================================================*/
/**
 * @brief �x�N�g�������W�ϊ�����
 * 
 * @param[in] matrix �ϊ��s��.
 * @return ����.
 */
Vector4& Vector4::transform( const Matrix4& matrix )
{
	Vector4	v;

	v.x = x * matrix.m[0][0]
	    + y * matrix.m[1][0]
	    + z * matrix.m[2][0]
	    + w * matrix.m[3][0];

	v.y = x * matrix.m[0][1]
	    + y * matrix.m[1][1]
	    + z * matrix.m[2][1]
	    + w * matrix.m[3][1];

	v.z = x * matrix.m[0][2]
	    + y * matrix.m[1][2]
	    + z * matrix.m[2][2]
	    + w * matrix.m[3][2];

	v.w = x * matrix.m[0][3]
	    + y * matrix.m[1][3]
	    + z * matrix.m[2][3]
	    + w * matrix.m[3][3];

	*this = v;

	return	*this;
}


	
/*=========================================================================*/
/**
 * @brief �{���Z�q�I�[�o�[���[�h
 * 
 * @param[in] �Ȃ�.
 * @return �Ӗ��Ȃ�.
 */
Vector4	Vector4::operator + () const
{
	return *this;
}



/*=========================================================================*/
/**
 * @brief -���Z�q�I�[�o�[���[�h
 * 
 * @param[in] �Ȃ�.
 * @return �t�x�N�g��.
 */
Vector4	Vector4::operator - () const
{
	return Vector4( -x, -y, -z, -w );
}



/*=========================================================================*/
/**
 * @brief +=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v ���Z����x�N�g��.
 * @return ���Z���ʂ̃x�N�g��.
 */
Vector4& Vector4::operator += ( const Vector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;

	return *this;
}



/*=========================================================================*/
/**
 * @brief -=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v ���Z����x�N�g��.
 * @return ���Z���ʂ̃x�N�g��.
 */
Vector4& Vector4::operator -= ( const Vector4& v )
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;

	return *this;
}



/*=========================================================================*/
/**
 * @brief *=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v ��Z����x�N�g��.
 * @return ���Z���ʂ̃x�N�g��.
 */
Vector4& Vector4::operator *= ( const Vector4& v )
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	w *= v.w;

	return *this;
}



/*=========================================================================*/
/**
 * @brief *=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] s ��Z����X�J���[.
 * @return ���Z���ʂ̃x�N�g��.
 */
Vector4& Vector4::operator *= ( float s )
{
	x *= s;
	y *= s;
	z *= s;
	w *= s;

	return *this;
}



/*=========================================================================*/
/**
 * @brief /=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v ���Z����x�N�g��.
 * @return ���Z���ʂ̃x�N�g��.
 */
Vector4& Vector4::operator /= ( const Vector4& v )
{
	x /= v.x;
	y /= v.y;
	z /= v.z;
	w /= v.w;

	return *this;
}



/*=========================================================================*/
/**
 * @brief /=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] s ���Z����X�J���[.
 * @return ���Z���ʂ̃x�N�g��.
 */
Vector4& Vector4::operator /= ( float s )
{
	x /= s;
	y /= s;
	z /= s;
	w /= s;

	return *this;
}


	
/*=========================================================================*/
/**
 * @brief float*���Z�q�I�[�o�[���[�h
 * 
 * @param[in] �Ȃ�.
 * @return �L���X�g�����l.
 */
Vector4::operator float* () const
{
	return (float*)this;
}



/*=========================================================================*/
/**
 * @brief const float*���Z�q�I�[�o�[���[�h
 * 
 * @param[in] �Ȃ�.
 * @return �L���X�g�����l.
 */
Vector4::operator const float* () const
{
	return (const float*)this;
}



/*===========================================================================*/
/**
 * @brief +���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v1 ���Z����x�N�g��1.
 * @param[in] v2 ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector4 operator + ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 )
{
	Vector4 tmp( v1 );
	return tmp += v2;
}



/*===========================================================================*/
/**
 * @brief -���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v1 ���Z����x�N�g��1.
 * @param[in] v2 ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector4 operator - ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 )
{
	Vector4 tmp( v1 );
	return tmp -= v2;
}



/*===========================================================================*/
/**
 * @brief *���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v1 ���Z����x�N�g��1.
 * @param[in] v2 ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector4 operator * ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 )
{
	Vector4 tmp( v1 );
	return tmp *= v2;
}



/*===========================================================================*/
/**
 * @brief *���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v ���Z����x�N�g��1.
 * @param[in] s ���Z����X�J���[.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector4 operator * ( const Ngl::Vector4& v, float s )
{
	Vector4 tmp( v );
	return tmp *= s;
}



/*===========================================================================*/
/**
 * @brief *���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] s ���Z����X�J���[.
 * @param[in] v ���Z����x�N�g��.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector4 operator * ( float s, const Ngl::Vector4& v )
{
	return v * s;
}



/*===========================================================================*/
/**
 * @brief /���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v1 ���Z����x�N�g��1.
 * @param[in] v2 ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector4 operator / ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 )
{
	Vector4 tmp( v1 );
	return tmp /= v2;
}



/*===========================================================================*/
/**
 * @brief /���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v ���Z����x�N�g��.
 * @param[in] s ���Z����X�J���[.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector4 operator / ( const Ngl::Vector4& v, float s )
{
	Vector4 tmp( v );
	return tmp /= s;
}



/*=========================================================================*/
/**
 * @brief ==���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l, false �Ⴄ�l.
 */
bool operator == ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 )
{
	return ( v1.x == v2.x && v1.y == v2.y && v1.z == v2.z && v1.w == v2.w );
}



/*=========================================================================*/
/**
 * @brief !=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l, false �Ⴄ�l.
 */
bool operator != ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 )
{
	return !( v1 == v2 );
}



/*=========================================================================*/
/**
 * @brief <���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l,
 */
bool operator < ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 )
{
	if( v1.x >= v2.x ) return false;
	if( v1.y >= v2.y ) return false;
	if( v1.z >= v2.z ) return false;
	if( v1.w >= v2.w ) return false;

	return true;
}



/*=========================================================================*/
/**
 * @brief <���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l,
 */
bool operator > ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 )
{
	if ( v1.x <= v2.x ) return false;
	if ( v1.y <= v2.y ) return false;
	if ( v1.z <= v2.z ) return false;
	if ( v1.w <= v2.w ) return false; 

	return	true;
}



/*=========================================================================*/
/**
 * @brief <=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l,
 */
bool operator <= ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 )
{
	return !( v1 > v2 );
}



/*=========================================================================*/
/**
 * @brief >=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l,
 */
bool operator >= ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 )
{
	return !( v1 < v2 );
}



/*===== EOF ==================================================================*/