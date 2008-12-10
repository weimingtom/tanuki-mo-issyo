/*******************************************************************************/
/**
 * @file Color4.cpp.
 * 
 * @brief RGBA�J���[�\���̃\�[�X�t�@�C��.
 *
 * @date 2007/06/04.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include		"Ngl/Color4.h"
#include		<algorithm>

using namespace Ngl;


/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
Color4::Color4():
	r( 0.0f ),
	g( 0.0f ),
	b( 0.0f ),
	a( 1.0f )
{
}



/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] R �Ԑ���.
 * @param[in] G �ΐ���.
 * @param[in] B ����.
 * @param[in] A �A���t�@����
 */
Color4::Color4(float R, float G, float B, float A):
			r(R), g(G), b(B), a(A)
{
}



/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] other �J���[�z��̃|�C���^.
 */
Color4::Color4(float *other)
{
	r = other[0];
	g = other[1];
	b = other[2];
	a = other[3];
}
			


/*===========================================================================*/
/**
 * @brief 0.0�ɏ���������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void Color4::zero()
{
	r = 0.0f;
	g = 0.0f;
	b = 0.0f;
	a = 0.0f;
}

	
	
/*===========================================================================*/
/**
 * @brief ����������
 * 
 * @param[in] R �Ԑ���.
 * @param[in] G �ΐ���.
 * @param[in] B ����.
 * @param[in] A �A���t�@����
 * @return �Ȃ�.
 */
void Color4::initialize(float R, float G, float B, float A)
{
	r = R;
	g = G;
	b = B;
	a = A;
}



/*===========================================================================*/
/**
 * @brief 255�`0�͈̔͂ɃN�����v
 * 
 * @param[in] �Ȃ�.
 * @return �N�����v���ꂽcolor.
 */
Color4& Color4::saturate()
{
	r = std::min( 1.0f, std::max( 0.0f, r ) );
	g = std::min( 1.0f, std::max( 0.0f, g ) );
	b = std::min( 1.0f, std::max( 0.0f, b ) );
	a = std::min( 1.0f, std::max( 0.0f, a ) );

	return *this;
}



/*===========================================================================*/
/**
 * @brief 16�i���̒l�ɕϊ�
 * 
 * @param[in] �Ȃ�.
 * @return �ϊ������l.
 */
unsigned long Color4::changeHexaDecimal() const
{
	// �����o�ϐ���int�^�ɕϊ�
	int iA = static_cast<unsigned int>( 255 * a );
	int iR = static_cast<unsigned int>( 255 * r );
	int iG = static_cast<unsigned int>( 255 * g );
	int iB = static_cast<unsigned int>( 255 * b );

	// 16�i���ɕϊ�
	return ((unsigned long)(((iA&0xff)<<24)|((iR&0xff)<<16)|((iG&0xff)<<8)|(iB&0xff)));
}



/*===========================================================================*/
/**
 * @brief RGB�l����J���[��ݒ肷��
 * @param[in] R �Ԑ���.
 * @param[in] G �ΐ���.
 * @param[in] B ����.
 * @return �ϊ������l.
 */
Color4& Color4::setColorOfRGB( int R, int G, int B )
{
	r = static_cast<float>( R / 255.0f );
	g = static_cast<float>( G / 255.0f );
	b = static_cast<float>( B / 255.0f );

	return *this;
}
	


/*===========================================================================*/
/**
 * @brief RGBA�l����J���[��ݒ肷��
 * @param[in] R �Ԑ���.
 * @param[in] G �ΐ���.
 * @param[in] B ����.
 * @param[in] A �A���t�@����.
 * @return �ϊ������l.
 */
Color4& Color4::setColorOfRGBA( int R, int G, int B, int A )
{
	setColorOfRGB( R, G, B );

	// �A���t�@�l��ϊ�
	a = static_cast<float>( A / 255.0f );

	return *this;
}
	

	
/*===========================================================================*/
/**
 * @brief + ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] �Ȃ�.
 * @return ���Z����color�̒l.
 */
Color4 Color4::operator + () const
{
	return *this;
}



/*===========================================================================*/
/**
 * @brief - ���Z�q�I�[�o�[���[�h, ��F�����߂�
 * 
 * @param[in] �Ȃ�.
 * @return ���Z����color�̒l.
 */
Color4 Color4::operator - () const
{
	return Color4( 1.0f - r, 1.0f - g, 1.0f - b, 1.0f - a );
}



/*===========================================================================*/
/**
 * @brief += ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] c2 ���Z����J���[.
 * @return ���Z����color�̒l.
 */
Color4& Color4::operator += ( const Color4& c2 )
{
	r += c2.r;
	g += c2.g;
	b += c2.b;
	a += c2.a;

	// �l���N�����v
	(*this).saturate();

	return *this;
}



/*===========================================================================*/
/**
 * @brief -= ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] c2 ���Z����J���[.
 * @return ���Z����color�̒l.
 */
Color4& Color4::operator -= ( const Color4& c2 )
{
	r = r - c2.r;
	g = g - c2.g;
	b = b - c2.b;
	a = a - c2.a;

	return *this;
}



/*===========================================================================*/
/**
 * @brief *= ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] c2 ���Z����J���[.
 * @return ���Z����color�̒l.
 */
Color4& Color4::operator *= ( const Color4& c2 )
{	
	r = r * c2.r;
	g = g * c2.g;
	b = b * c2.b;
	a = a * c2.a;

	// �l���N�����v
	(*this).saturate();

	return *this;
}



/*===========================================================================*/
/**
 * @brief *= ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] s ���Z����l.
 * @return ���Z����color�̒l.
 */
Color4& Color4::operator *= ( float s )
{
	r *= s;
	g *= s;
	b *= s;
	a *= s;

	// �l���N�����v
	(*this).saturate();

	return *this;
}


	
/*===========================================================================*/
/**
 * @brief *= ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] s ���Z����l.
 * @return ���Z����color�̒l.
 */
Color4& Color4::operator *= ( int s )
{	
	r *= s;
	g *= s;
	b *= s;
	a *= s;

	// �l���N�����v
	(*this).saturate();

	return *this;
}



/*===========================================================================*/
/**
 * @brief /= ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] c2 ���Z����J���[.
 * @return ���Z����color�̒l.
 */
Color4& Color4::operator /= ( const Color4& c2 )
{	
	r = r / c2.r;
	g = g / c2.g;
	b = b / c2.b;
	a = a / c2.a;

	(*this).saturate();

	return *this;
}



/*===========================================================================*/
/**
 * @brief /= ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] s ���Z����l.
 * @return ���Z����color�̒l.
 */
Color4& Color4::operator /= ( int s )
{
	r /= s;
	g /= s;
	b /= s;
	a /= s;

	// �l���N�����v
	(*this).saturate();

	return *this;
}



/*===========================================================================*/
/**
 * @brief float* ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] �Ȃ�.
 * @return �L���X�g����float�^�̒l.
 */
Color4::operator float *() const
{
	return ( float* )this;
}



/*===========================================================================*/
/**
 * @brief const float* ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] �Ȃ�.
 * @return �L���X�g����const float*�^�̒l.
 */
Color4::operator const float *() const
{
	return ( const float* )this;
}



/*===========================================================================*/
/**
 * @brief + ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] c1 ���Z����J���[.
 * @param[in] c2 ���Z����J���[.
 * @return ���Z��������.
 */
const Color4 operator + ( const Color4& c1, const Color4& c2 )
{
	Color4 tmp(c1);
	return tmp += c2;
}



/*===========================================================================*/
/**
 * @brief - ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] c1 ���Z����J���[.
 * @param[in] c2 ���Z����J���[.
 * @return ���Z��������.
 */
const Color4 operator - ( const Color4& c1, const Color4& c2 )
{
	Color4 tmp(c1);
	return tmp -= c2;
}



/*===========================================================================*/
/**
 * @brief * ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] c1 ���Z����J���[.
 * @param[in] c2 ���Z����J���[.
 * @return ���Z��������.
 */
const Color4 operator * ( const Color4& c1, const Color4& c2 )
{
	Color4 tmp(c1);
	return tmp *= c2;
}



/*===========================================================================*/
/**
 * @brief * ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] s ���Z����l.
 * @param[in] c ���Z����J���[.
 * @return ���Z��������.
 */
const Color4 operator * ( float s, const Color4& c )
{
	return c * s;
}



/*===========================================================================*/
/**
 * @brief * ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] c ���Z����J���[.
 * @param[in] s ���Z����l.
 * @return ���Z��������.
 */
const Color4 operator * ( const Color4& c, float s )
{
	Color4 tmp(c);
	return tmp *= s;
}



/*===========================================================================*/
/**
 * @brief * ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] s ���Z����l.
 * @param[in] c ���Z����J���[.
 * @return ���Z��������.
 */
const Color4 operator * ( int s, const Color4& c )
{
	return c * s;
}



/*===========================================================================*/
/**
 * @brief * ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] c ���Z����J���[.
 * @param[in] s ���Z����l.
 * @return ���Z��������.
 */
const Color4 operator * ( const Color4& c, int s )
{
	Color4 tmp(c);
	return tmp *= s;
}



/*===========================================================================*/
/**
 * @brief / ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] c ���Z����J���[.
 * @param[in] s ���Z����l.
 * @return ���Z��������.
 */
const Color4 operator / ( const Color4& c, int s )
{
	Color4 tmp( c );
	return tmp /= s;
}



/*========= EOF =============================================================*/