/*******************************************************************************/
/**
 * @file Quaternion.cpp.
 * 
 * @brief �N�H�[�^�j�I���\���̃\�[�X�t�@�C��.
 *
 * @date 2007/09/01.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Quaternion.h"
#include	"Ngl/Vector3.h"
#include	"Ngl/Matrix4.h"
#include	"Ngl/MathUtility.h"
#include	<cmath>

using namespace Ngl;


/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
Quaternion::Quaternion()
{
	// �P�ʃN�H�[�^�j�I���ɂ���
	setIdentity();
}



/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] X x����.
 * @param[in] Y y����.
 * @param[in] Z z����.
 * @param[in] W w����.
 */
Quaternion::Quaternion(float X, float Y, float Z, float W):
	x( X ),	// x����
	y( Y ), // y����
	z( Z ),	// z����
	w( W )	// ��]�p�x
{}



/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] aNgle ��]�p�x.
 * @param[in] axis ��.
 */
Quaternion::Quaternion(float aNgle, const Ngl::Vector3 &axis)
{
	// ��]�p�x����N�H�[�^�j�I�����쐬����
	fromRotate( aNgle, axis );
}


	
/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] m ��]�s��.
 */
Quaternion::Quaternion(const Ngl::Matrix4 &m)
{
	// ��]�s�����N�H�[�^�j�I�����쐬����
	setMatrix( m );
}



/*===========================================================================*/
/**
 * @brief �P�ʃN�H�[�^�j�I��������
 * 
 * @param[in] �Ȃ�.
 * @return �P�ʃN�H�[�^�j�I���������N�H�[�^�j�I��.
 */
Quaternion& Quaternion::setIdentity()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 1.0f;

	return *this;
}



/*===========================================================================*/
/**
 * @brief ���K��������
 * 
 * @param[in] �Ȃ�.
 * @return ���K�������N�H�[�^�j�I��.
 */
Quaternion& Quaternion::normalize()
{
	// ���������߂�
	float len = length();
	len = ( len > 0.0f ) ? ( 1.0f / len ) : 0.0f;

	// �e�����Ə�Z����
	x *= len;
	y *= len;
	z *= len;
	w *= len;

	return *this;
}



/*===========================================================================*/
/**
 * @brief ���ς����߂�
 * 
 * @param[in]  q ���ς����߂�N�H�[�^�j�I��.
 * @return ���ς̒l.
 */
float Quaternion::dot(const Ngl::Quaternion &q) const
{
	return x * q.x + y * q.y + z * q.z + w * q.w;
}



/*===========================================================================*/
/**
 * @brief ���������߂�
 * 
 * @param[in] �Ȃ�.
 * @return �����̒l.
 */
float Quaternion::length() const
{
	return dot( *this );
}



/*===========================================================================*/
/**
 * @brief �t�N�H�[�^�j�I��������
 * 
 * @param[in] �Ȃ�.
 * @return �t�N�H�[�^�j�I���������N�H�[�^�j�I��.
 */
Quaternion& Quaternion::inverse()
{
	// ���������߂�
	float len = length();
	len = ( len > 0.0f ) ? ( 1.0f / len ) : 0.0f;

	// �e�����𔽓]���Ē�������Z����
	x = -x * len;
	y = -y * len;
	z = -z * len;
	w = -w * len;

	return *this;
}



/*===========================================================================*/
/**
 * @brief ��]�p�x����N�H�[�^�j�I�����擾����
 * 
 * @param[in] aNgle ��]�p�x.
 * @param[in] vx x����.
 * @param[in] vy y����.
 * @param[in] vz z����.
 * @return �擾�����N�H�[�^�j�I��.
 */
Quaternion& Quaternion::fromRotate(float aNgle, float vx, float vy, float vz)
{
	x = Ngl::sin( aNgle / 2.0f ) * vx;
	y = Ngl::sin( aNgle / 2.0f ) * vy;
	z = Ngl::sin( aNgle / 2.0f ) * vz;
	w = Ngl::cos( aNgle / 2.0f );

	return *this;
}



/*===========================================================================*/
/**
 * @brief ��]�p�x����N�H�[�^�j�I�����擾����
 * 
 * @param[in] aNgle ��]�p�x.
 * @param[in] axis ��.
 * @return �擾�����N�H�[�^�j�I��.
 */
Quaternion& Quaternion::fromRotate(float aNgle, const Ngl::Vector3 &axis)
{
	return fromRotate( aNgle, axis.x, axis.y, axis.z );
}



/*===========================================================================*/
/**
 * @brief ���[�E�s�b�`�E���[������N�H�[�^�j�I�����擾����
 * 
 * @param[in] yaw ���[�p.
 * @param[in] pitch �s�b�`�p.
 * @param[in] roll ���[���p.
 * @return �擾�����N�H�[�^�j�I��.
 */
Quaternion& Quaternion::fromYawPitchRoll(float yaw, float pitch, float roll)
{
	// ���[�s�b�`���[���̐����l�����߂�
	float fSinYaw	= Ngl::sin( yaw	/ 2.0f );
	float fSinPitch	= Ngl::sin( pitch	/ 2.0f );
	float fSinRoll	= Ngl::sin( roll	/ 2.0f );
	
	// ���[�s�b�`���[���̗]���l�����߂�
	float fCosYaw	= Ngl::cos( yaw	/ 2.0f );
	float fCosPitch	= Ngl::cos( pitch	/ 2.0f );
	float fCosRoll	= Ngl::cos( roll	/ 2.0f );

	x = fSinRoll * fCosPitch * fCosYaw - fCosRoll * fSinPitch * fSinYaw;
	y = fCosRoll * fSinPitch * fCosYaw + fSinRoll * fCosPitch * fSinYaw;
	z = fCosRoll * fCosPitch * fSinYaw - fSinRoll * fSinPitch * fCosYaw;
	w = fCosRoll * fCosPitch * fCosYaw + fSinRoll * fSinPitch * fSinYaw;

	return *this;
}



/*===========================================================================*/
/**
 * @brief ��]�s���ݒ肷��
 * 
 * @param[in] mat ��]�s��.
 * @return �ݒ肵���N�H�[�^�j�I��.
 */
Quaternion& Quaternion::setMatrix(const Ngl::Matrix4 &mat)
{
	float tr = mat.m[0][0] + mat.m[1][1] + mat.m[2][2] + mat.m[3][3];

	if( tr >= 1.0f ){
		float fourD = 2.0f * Ngl::sqrt( tr );
		w = fourD / 4.0f;
		x = ( mat.m[1][2] - mat.m[2][1] ) / fourD;
		y = ( mat.m[2][0] - mat.m[0][2] ) / fourD;
		z = ( mat.m[0][1] - mat.m[1][0] ) / fourD;
	}
	else{
		float pa[4];
		int i = 0;

		if( mat.m[0][0] > mat.m[1][1] ){
			i = 0;
		}
		else{
			i = 1;
		}
		if( mat.m[2][2] > mat.m[i][i] ){
			i = 2;
		}

		int j = ( i + 1 ) % 3;
		int k = ( j + 1 ) % 3;

		tr = mat.m[i][i] + mat.m[j][j] + mat.m[k][k] + 1.0f;
		float fourD = 2.0f * Ngl::sqrt( tr );

		pa[i] = fourD / 4.0f;
		pa[j] = ( mat.m[j][i] + mat.m[i][j] ) / fourD;
		pa[k] = ( mat.m[k][i] + mat.m[i][k] ) / fourD;
		pa[3] = ( mat.m[j][k] - mat.m[k][j] ) / fourD;

		x = pa[0];
		y = pa[1];
		z = pa[2];
		w = pa[3];
	}

	return *this;
}



/*===========================================================================*/
/**
 * @brief �����擾����
 * 
 * @param[in] �Ȃ�.
 * @return ���̒l.
 */
Ngl::Vector3 Quaternion::getAxis() const
{
	// �p�x���擾����
	float aNgle = getANgle();

	// �����������߂�
	Ngl::Vector3 tmp;
	tmp.x = x / Ngl::sin( aNgle / 2.0f );
	tmp.y = y / Ngl::sin( aNgle / 2.0f );
	tmp.z = z / Ngl::sin( aNgle / 2.0f );

	return tmp;
}



/*===========================================================================*/
/**
 * @brief �p�x���擾����
 * 
 * @param[in] �Ȃ�.
 * @return �p�x�̒l.
 */
float Quaternion::getANgle() const
{
	return Ngl::acos( w ) * 2.0f;
}



/*===========================================================================*/
/**
 * @brief ���[�p���擾����
 * 
 * @param[in] �Ȃ�.
 * @return ���[�p�̒l.
 */
float Quaternion::getYaw() const
{
	return Ngl::atan( 2.0f * ( y*z + w*x ), w*w - x*x - y*y - z*z );
}



/*===========================================================================*/
/**
 * @brief �s�b�`�p���擾����
 * 
 * @param[in] �Ȃ�.
 * @return �s�b�`�p�̒l.
 */
float Quaternion::getPitch() const
{
	return Ngl::degreeNormalize( Ngl::asin( -2.0f * ( x*z  - w*y  ) ) );
}



/*===========================================================================*/
/**
 * @brief ���[���p���擾����
 * 
 * @param[in] �Ȃ�.
 * @return ���[���p�̒l.
 */
float Quaternion::getRoll() const
{
	return Ngl::atan( 2.0f * ( x*y + w*z ), w*w - x*x - y*y - z*z );
}



/*===========================================================================*/
/**
 * @brief ���`��Ԃ���
 * 
 * @param[in] q1 ��ԗv�f�̃N�H�[�^�j�I���P.
 * @param[in] q2 ��ԗv�f�̃N�H�[�^�j�I���Q.
 * @param[in] t ��Ԓl.
 * @return �Ȃ�.
 */
Quaternion& Quaternion::lerp(const Ngl::Quaternion &q1, const Ngl::Quaternion &q2, float t)
{
	x = Ngl::leap( t, q1.x, q2.x );
	y = Ngl::leap( t, q1.y, q2.y );
	z = Ngl::leap( t, q1.z, q2.z );
	w = Ngl::leap( t, q1.w, q2.w );

	return *this;
}



/*===========================================================================*/
/**
 * @brief ���`���`��Ԃ���
 * 
 * @param[in] q1 ��ԗv�f�̃N�H�[�^�j�I���P.
 * @param[in] q2 ��ԗv�f�̃N�H�[�^�j�I���Q.
 * @param[in] t ��Ԓl.
 * @return �Ȃ�.
 */
Quaternion& Quaternion::slerp( const Quaternion& q1, const Quaternion& q2, float t )
{
	float fCosTheta = q1.x * q2.x + q1.y * q2.y + q1.z * q2.z + q1.w * q2.w;

	Quaternion tb;
	if( fCosTheta < 0.0f ){
		fCosTheta	= -fCosTheta;
		tb.x		= -q2.x;
		tb.y		= -q2.y;
		tb.z		= -q2.z;
		tb.w		= -q2.w;
	}
	else{
		tb = q2;
	}

	float fBeta = 1.0f - t;

	if( ( 1.0f - fCosTheta ) > 0.001f ){
		float fTheta = (float)std::acos( fCosTheta );

		fBeta	= (float)( std::sin( fTheta * fBeta ) / std::sin( fTheta ) );
		t		= (float)( std::sin( fTheta * t		) / std::sin( fTheta ) );
	}

	x = fBeta * q1.x + t * tb.x;
	y = fBeta * q1.y + t * tb.y;
	z = fBeta * q1.z + t * tb.z;
	w = fBeta * q1.w + t * tb.w;

	(*this).normalize();

	return *this;
}



/*===========================================================================*/
/**
 * @brief 2����Ԃ���
 * 
 * @param[in] q1 ��ԗv�f�̃N�H�[�^�j�I��1.
 * @param[in] q2 ��ԗv�f�̃N�H�[�^�j�I��2.
 * @param[in] q3 ��ԗv�f�̃N�H�[�^�j�I��3.
 * @param[in] t �⊮�x.
 * @return �⊮�����N�H�[�^�j�I��.
 */
Quaternion& Quaternion::quadratic(const Ngl::Quaternion &q1, const Ngl::Quaternion &q2, const Ngl::Quaternion &q3, float t)
{
	x = Ngl::quadratic( t, q1.x, q2.x, q3.x );
	y = Ngl::quadratic( t, q1.y, q2.y, q3.y );
	z = Ngl::quadratic( t, q1.z, q2.z, q3.z );
	w = Ngl::quadratic( t, q1.w, q2.w, q3.w );

	return *this;
}


/*===========================================================================*/
/**
 * @brief + ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] �Ȃ�.
 * @return ���Z���ʂ̃N�H�[�^�j�I��.
 */
Quaternion Quaternion::operator +() const
{
	return *this;
}



/*===========================================================================*/
/**
 * @brief - ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] �Ȃ�.
 * @return ���Z���ʂ̃N�H�[�^�j�I��.
 */
Quaternion Quaternion::operator -() const
{
	return Quaternion( -x, -y, -z, -w );
}



/*===========================================================================*/
/**
 * @brief += ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] q ���Z����N�H�[�^�j�I��.
 * @return ���Z���ʂ̃N�H�[�^�j�I��.
 */
Quaternion& Quaternion::operator +=(const Ngl::Quaternion &q)
{
	x = x + q.x;
	y = y + q.y;
	z = z + q.z;
	w = w + q.w;

	return *this;
}



/*===========================================================================*/
/**
 * @brief -= ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] q ���Z����N�H�[�^�j�I��.
 * @return ���Z���ʂ̃N�H�[�^�j�I��.
 */
Quaternion& Quaternion::operator -=(const Ngl::Quaternion &q)
{
	x = x - q.x;
	y = y - q.y;
	z = z - q.z;
	w = w - q.w;

	return *this;
}



/*===========================================================================*/
/**
 * @brief *= ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] q ���Z����N�H�[�^�j�I��.
 * @return ���Z���ʂ̃N�H�[�^�j�I��.
 */
Quaternion& Quaternion::operator *=(const Ngl::Quaternion &q)
{
	x =  x * q.w + y * q.z + z * q.y + w * q.x;
	y = -x * q.z + y * q.w + z * q.x + w * q.y;
	z =  x * q.y + y * q.x + z * q.w + w * q.z;
	w = -x * q.x + y * q.y + z * q.z + w * q.w;

	return *this;
}



/*===========================================================================*/
/**
 * @brief *= ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] s ���Z����X�J���[.
 * @return ���Z���ʂ̃N�H�[�^�j�I��.
 */
Quaternion& Quaternion::operator *=(float s)
{
	x = x * s;
	y = y * s;
	z = z * s;
	w = w * s;

	return *this;
}



/*===========================================================================*/
/**
 * @brief /= ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] s ���Z����X�J���[.
 * @return ���Z���ʂ̃N�H�[�^�j�I��.
 */
Quaternion& Quaternion::operator /=(float s)
{
	return ( *this *= ( 1.0f / s ) );
}



/*=========================================================================*/
/**
 * @brief + ���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] q1 ���Z����N�H�[�^�j�I��1.
 * @param[in] q2 ���Z����N�H�[�^�j�I��2.
 * @return ���Z���ʂ̃N�H�[�^�j�I��.
 */
Quaternion operator + ( const Quaternion& q1, const Quaternion& q2 )
{
	Quaternion tmp( q1 );
	return tmp += q2;
}



/*=========================================================================*/
/**
 * @brief - ���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] q1 ���Z����N�H�[�^�j�I��1.
 * @param[in] q2 ���Z����N�H�[�^�j�I��2.
 * @return ���Z���ʂ̃N�H�[�^�j�I��.
 */
Quaternion operator - ( const Quaternion& q1, const Quaternion& q2 )
{
	Quaternion tmp( q1 );
	return tmp -= q2;
}



/*=========================================================================*/
/**
 * @brief * ���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] q1 ���Z����N�H�[�^�j�I��1.
 * @param[in] q2 ���Z����N�H�[�^�j�I��2.
 * @return ���Z���ʂ̃N�H�[�^�j�I��.
 */
Quaternion operator * ( const Quaternion& q1, const Quaternion& q2 )
{
	Quaternion tmp( q1 );
	return tmp *= q2;
}



/*=========================================================================*/
/**
 * @brief * ���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] q ���Z����N�H�[�^�j�I��.
 * @param[in] s ���Z����X�J���[.
 * @return ���Z���ʂ̃N�H�[�^�j�I��.
 */
Quaternion operator * ( const Quaternion& q, float s )
{
	Quaternion tmp( q );
	return tmp *= s;
}



/*=========================================================================*/
/**
 * @brief += ���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] s ���Z����X�J���[.
 * @param[in] q ���Z����N�H�[�^�j�I��.
 * @return ���Z���ʂ̃N�H�[�^�j�I��.
 */
Quaternion operator * ( float s, const Quaternion& q )
{
	return q * s;
}



/*=========================================================================*/
/**
 * @brief == ���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] q1 ���Z����N�H�[�^�j�I��1.
 * @param[in] q2 ���Z����N�H�[�^�j�I��2.
 * @return true ��v���Ă��� false ��v���Ă��Ȃ�.
 */
bool operator == ( const Quaternion& q1, const Quaternion& q2 )
{
	return ( q1.x == q2.x && q1.y == q2.y && q1.z == q2.z && q1.w == q2.w );
}



/*=========================================================================*/
/**
 * @brief != ���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] q1 ���Z����N�H�[�^�j�I��1.
 * @param[in] q2 ���Z����N�H�[�^�j�I��2.
 * @return true ��v���Ă��Ȃ� false ��v���Ă���.
 */
bool operator != ( const Quaternion& q1, const Quaternion& q2 )
{
	return !( q1 == q2 );
}



/*========= EOF =============================================================*/