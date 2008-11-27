/*******************************************************************************/
/**
 * @file Vector3.cpp.
 * 
 * @brief 3�����x�N�g���\���̃\�[�X�t�@�C��.
 *
 * @date 2008/06/23.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	<Ngl/Vector3.h>
#include	<Ngl/Matrix4.h>
#include	<Ngl/MathUtility.h>

using namespace Ngl;

/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] ������ ��������.
 */
Vector3::Vector3() :
	x(0.0f),
	y(0.0f),
	z(0.0f)
{
}



/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] other �z��̃|�C���^.
 */
Vector3::Vector3(const float* other)
{
	x = other[0];
	y = other[1];
	z = other[2];
}



/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] X x�l.
 * @param[in] Y y�l.
 * @param[in] Z z�l.
 */
Vector3::Vector3(float X, float Y, float Z) :
	x(X), y(Y), z(Z)
{}
	
	

/*===========================================================================*/
/**
 * @brief 0.0�ɏ���������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void Vector3::zero()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}



/*===========================================================================*/
/**
 * @brief ����������
 * 
 * @param[in] X x�l.
 * @param[in] Y y�l.
 * @param[in] Z z�l.
 * @return �Ȃ�.
 */
void Vector3::initialize(float X, float Y, float Z)
{
	x = X;
	y = Y;
	z = Z;
}

	
	
/*===========================================================================*/
/**
 * @brief �m���������߂�
 * 
 * @param[in] �Ȃ�.
 * @return �m����.
 */
float Vector3::length() const
{
	return Ngl::sqrt( lengthSq() );
}



/*===========================================================================*/
/**
 * @brief �m���������߂�(���[�g���Ƃ�Ȃ�)
 * 
 * @param[in] �Ȃ�.
 * @return �m����(�Q��a�̂�).
 */
float Vector3::lengthSq() const
{
	return (x * x + y * y + z * z);
}



/*===========================================================================*/
/**
 * @brief ���K������
 * 
 * @param[in] �Ȃ�.
 * @return ���K�������x�N�g��.
 */
Vector3& Vector3::normalize()
{
	float len = length();
	if( len != 0.0f ){
		return *this /= len;
	}
	return *this;
}



/*===========================================================================*/
/**
 * @brief ���ς����߂�
 * 
 * @param[in] v �v�Z����x�N�g��.
 * @return ���ς̒l.
 */
float Vector3::dot(const Vector3& v) const
{
	return x * v.x + y * v.y + z * v.z;
}



/*===========================================================================*/
/**
 * @brief �O�ς̒l�����߂�
 * 
 * @param[in] v �v�Z����x�N�g��.
 * @return �O�ς̒l.
 */
Vector3 Vector3::cross(const Vector3& v) const
{
	Vector3 temp;
	
	temp.x = y * v.z - z * v.y;
	temp.y = z * v.x - x * v.z;
	temp.z = x * v.y - y * v.x;

	return temp;

}



/*===========================================================================*/
/**
 * @brief �p�ƕ��ʊp����x�N�g�������߂�
 * 
 * @param[in] elevation �p.
 * @param[in] direction ���ʊp.
 * @return ���߂��x�N�g��.
 */
Vector3& Vector3::fromEleDir( float elevation, float direction )
{
	x = Ngl::cos( elevation ) * Ngl::sin( direction );
	y = -Ngl::sin( elevation );
	z = Ngl::cos( elevation ) * Ngl::cos( direction );

	return *this;
}



/*===========================================================================*/
/**
 * @brief �s�b�`�p�ƃ��[�p����x�N�g�������߂�
 * 
 * @param[in] pitch �s�b�`�p.
 * @param[in] yaw ���[�p.
 * @return ���߂��x�N�g��.
 */
Vector3& Vector3::fromPitchYaw( float pitch, float yaw )
{
	return fromEleDir( pitch, yaw );
}



/*===========================================================================*/
/**
 * @brief �x�N�g���Ԃ̋��������߂�
 * 
 * @param[in] other ���������߂�x�N�g��.
 * @return ���߂��x�N�g��.
 */
float Vector3::distance( const Vector3& other )
{
	// 2�̃x�N�g���̍������߂�
	Vector3 v = *this - other;

	// �x�N�g���̒�����Ԃ�
	return v.length();
}



/*===========================================================================*/
/**
 * @brief �x�N�g�����m�̋��������߂�(���[�g�����Ȃ�)
 * 
 * @param[in] other ���������߂�x�N�g��.
 * @return �x�N�g���̋���(�Q��a�̂�).
 */
float Vector3::distanceSq(const Vector3 &other)
{
	// 2�̃x�N�g���̍������߂�
	Vector3 v = *this - other;

	return v.lengthSq();
}



/*===========================================================================*/
/**
 * @brief �x�N�g�����m�����p�x�����߂�
 * 
 * @param[in] other �p�x�����߂鑊��x�N�g��.
 * @return �p�x.
 */
float Vector3::innerDegree(const Vector3& other)
{
	float cos_Theta = dot( other ) / length() * other.length();

	float angle = Ngl::acos( Ngl::clamp( cos_Theta, -1.0f, 1.0f ) );

	return angle;
}


/*===========================================================================*/
/**
 * @brief �ʖ@�������߂�
 * 
 * @param[in] vec1 ���_.
 * @param[in] vec2 ���_.
 * @return �@���x�N�g��.
 */
Vector3 Vector3::calculateNoamal(const Vector3 &vec1, const Vector3 &vec2)
{
	Vector3 vv1 = *this - vec1;
	Vector3 vv2 = vec1 - vec2;

	// �x�N�g���̊O�ς����߂�
	Vector3 c = vv1.cross( vv2 );

	// �x�N�g���𐳋K������
	c = c.normalize();

	return c;
}



/*===========================================================================*/
/**
 * @brief �����̕������̌v�Z���s��
 * 
 * @param[in] p �x�N�g��1.
 * @param[in] v �x�N�g��2.
 * @param[in] t �W��.
 * @return ���ʂ̃x�N�g��.
 */
Vector3 Vector3::linearEquation(const Vector3 &p, const Vector3 &v, float t )
{
	x = v.x * t + p.x;
	y = v.y * t + p.y;
	z = v.z * t + p.z;

	return *this;
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
Vector3& Vector3::lerp(const Vector3 &min, const Vector3 &max, float t)
{
	x = Ngl::leap( t, min.x, max.x );
	y = Ngl::leap( t, min.y, max.y );
	z = Ngl::leap( t, min.z, max.z );

	return *this;
}



/*===========================================================================*/
/**
 * @brief �x�N�g����2����Ԃ��s��
 * 
 * @param[in] v1 ��ԗv�f3�����x�N�g��.
 * @param[in] v2 ��ԗv�f3�����x�N�g��.
 * @param[in] v3 3�����x�N�g��.
 * @param[in] t ��Ԓl( 0.0f�`1.0f ).
 * @return ���ʂ̃x�N�g��.
 */
Vector3& Vector3::quadratic(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3, float t)
{
	x = Ngl::quadratic( t, v1.x, v2.x, v3.x );
	y = Ngl::quadratic( t, v1.y, v2.y, v3.y );
	z = Ngl::quadratic( t, v1.z, v2.z, v3.z );

	return *this;
}



/*===========================================================================*/
/**
 * @brief �x�N�g�������W�ϊ�����
 * 
 * @param[in] matrix �ϊ��s��.
 * @return ����.
 */
Vector3& Vector3::transform(const Matrix4 &matrix)
{
	Ngl::Vector3 v;

	// �e���������W�ϊ�
	v.x = x * matrix.m[0][0] +
		  y * matrix.m[1][0] +
		  z * matrix.m[2][0] +
		  matrix.m[3][0];

	v.y = x * matrix.m[0][1] +
		  y * matrix.m[1][1] +
		  z * matrix.m[2][1] +
		  matrix.m[3][1];

	v.z = x * matrix.m[0][2] +
		  y * matrix.m[1][2] +
		  z * matrix.m[2][2] +
		  matrix.m[3][2];

	// �x�N�g����ݒ�
	*this = v;

	return *this;
}



/*===========================================================================*/
/**
 * @brief �@���x�N�g�������W�ϊ�����
 * 
 * @param[in] matrix �ϊ��s��.
 * @return ����.
 */
Vector3& Vector3::transformNormal(const Matrix4 &matrix)
{
	Vector3 v;

	// �e���������W�ϊ�
	v.x = x * matrix.m[0][0] +
		  y * matrix.m[1][0] +
		  z * matrix.m[2][0];

	v.y = x * matrix.m[0][1] +
		  y * matrix.m[1][1] +
		  z * matrix.m[2][1];

	v.z = x * matrix.m[0][2] +
		  y * matrix.m[1][2] +
		  z * matrix.m[2][2];

	// �x�N�g����ݒ�
	*this = v;

	return *this;
}



/*===========================================================================*/
/**
 * @brief �{���Z�q�I�[�o�[���[�h
 * 
 * @param[in] �Ȃ�.
 * @return �Ӗ��Ȃ�.
 */
Vector3 Vector3::operator + () const
{
	return *this;
}



/*===========================================================================*/
/**
 * @brief -���Z�q�I�[�o�[���[�h
 * 
 * @param[in] �Ȃ�.
 * @return �t�x�N�g��.
 */
Vector3 Vector3::operator - () const
{
	return Vector3(-x, -y, -z);
}



/*===========================================================================*/
/**
 * @brief +=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v ���Z����x�N�g��.
 * @return ���Z���ʂ̃x�N�g��.
 */
Vector3& Vector3::operator += (const Vector3& v)
{
	x += v.x;
	y += v.y;
	z += v.z;

	return *this;
}



/*===========================================================================*/
/**
 * @brief -=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v ���Z����x�N�g��.
 * @return ���Z���ʂ̃x�N�g��.
 */
Vector3& Vector3::operator -= (const Vector3& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;

	return *this;
}



/*===========================================================================*/
/**
 * @brief *=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v ��Z����x�N�g��.
 * @return ���Z���ʂ̃x�N�g��.
 */
Vector3& Vector3::operator *=(const Ngl::Vector3 &v)
{
	x *= v.x;
	y *= v.y;
	z *= v.z;

	return *this;
}


/*===========================================================================*/
/**
 * @brief *=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] s ��Z����X�J���[.
 * @return ���Z���ʂ̃x�N�g��.
 */
Vector3& Vector3::operator *= (float s)
{
	x *= s;
	y *= s;
	z *= s;

	return *this;
}



/*===========================================================================*/
/**
 * @brief /=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v ���Z����x�N�g��.
 * @return ���Z���ʂ̃x�N�g��.
 */
Vector3& Vector3::operator /=(const Ngl::Vector3 &v)
{
	x /= v.x;
	y /= v.y;
	z /= v.z;

	return *this;
}



/*===========================================================================*/
/**
 * @brief /=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] s ���Z����X�J���[.
 * @return ���Z���ʂ̃x�N�g��.
 */
Vector3& Vector3::operator /= (float s)
{
	x /= s;
	y /= s;
	z /= s;

	return *this;
}



/*===========================================================================*/
/**
 * @brief float*���Z�q�I�[�o�[���[�h
 * 
 * @param[in] �Ȃ�.
 * @return �L���X�g�����l.
 */
Vector3::operator float *() const
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
Vector3::operator const float *() const
{
	return ( const float* )this;
}



/*===========================================================================*/
/**
 * @brief +���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v1 ���Z����x�N�g��1.
 * @param[in] v2 ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Vector3 operator + (const Vector3& v1, const Vector3& v2)
{
	Vector3 temp(v1);
	return temp += v2;
}



/*===========================================================================*/
/**
 * @brief -���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v1 ���Z����x�N�g��1.
 * @param[in] v2 ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Vector3 operator - (const Vector3& v1, const Vector3& v2)
{
	Vector3 temp(v1);
	return temp -= v2;
}



/*===========================================================================*/
/**
 * @brief *���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v1 ���Z����x�N�g��1.
 * @param[in] v2 ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Vector3 operator * (const Vector3 &v1, const Vector3 &v2)
{
	Vector3 temp(v1);
	return temp *= v2;
}



/*===========================================================================*/
/**
 * @brief *���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v ���Z����x�N�g��1.
 * @param[in] s ���Z����X�J���[.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Vector3 operator * (const Vector3& v, float s)
{
	Vector3 temp(v);
	return temp *= s;
}



/*===========================================================================*/
/**
 * @brief *���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] s ���Z����X�J���[.
 * @param[in] v ���Z����x�N�g��.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Vector3 operator * (float s, const Vector3& v)
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
const Vector3 operator / (const Vector3 &v1, const Vector3 &v2)
{
	Vector3 tmp( v1 );
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
const Vector3 operator / (const Vector3& v, float s)
{
	Vector3 temp(v);
	return temp /= s;
}



/*===========================================================================*/
/**
 * @brief ==���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l, false �Ⴄ�l.
 */
bool operator == (const Vector3 &v1, const Vector3 &v2)
{
	return ( v1.x == v2.x && v1.y == v2.y && v1.z == v2.z );
}



/*===========================================================================*/
/**
 * @brief !=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l, false �Ⴄ�l.
 */
bool operator != (const Vector3 &v1, const Vector3 &v2)
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
bool operator < (const Vector3 &v1, const Vector3 &v2)
{
	if( v1.x >= v2.x ) return false;
	if( v1.y >= v2.y ) return false;
	if( v1.z >= v2.z ) return false;

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
bool operator > (const Vector3 &v1, const Vector3 &v2)
{
	if ( v1.x <= v2.x ) return false;
	if ( v1.y <= v2.y ) return false;
	if ( v1.z <= v2.z ) return false;

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
bool operator <= (const Vector3 &v1, const Vector3 &v2)
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
bool operator >= (const Vector3 &v1, const Vector3 &v2)
{
	return !( v1 < v2 );
}



/*========= EOF =============================================================*/