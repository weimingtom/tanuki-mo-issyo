/*******************************************************************************/
/**
 * @file TextureFilterColorKey.cpp.
 * 
 * @brief �J���[�L�[�e�N�X�`���t�B���^�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/08/23.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/TextureFilterColorKey.h"
#include	"Ngl/Color4.h"

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] r �J���[�L�[�Ԑ���( �����l 0�`255 or 16�i�� 0x00�`0xff ).
 * @param[in] g �J���[�L�[�ΐ���( �����l 0�`255 or 16�i�� 0x00�`0xff ).
 * @param[in] b �J���[�L�[����( �����l 0�`255 or 16�i�� 0x00�`0xff ).
 * @param[in] a �J���[�L�[�A���t�@����( �����l 0�`255 or 16�i�� 0x00�`0xff  ).
 */
TextureFilterColorKey::TextureFilterColorKey( unsigned char r, unsigned char g, unsigned char b, unsigned char a ):
	r_( r ),
	g_( g ),
	b_( b ),
	a_( a )
{}



/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] color �J���[�L�[( ���������_�l 0.0f�`1.0f ).
 */
TextureFilterColorKey::TextureFilterColorKey( const Color4& color ):
	r_( static_cast< unsigned char >( 255.0f * color.r ) ),
	g_( static_cast< unsigned char >( 255.0f * color.g ) ),
	b_( static_cast< unsigned char >( 255.0f * color.b ) ),
	a_( static_cast< unsigned char >( 255.0f * color.a ) )
{}

	
	
/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
TextureFilterColorKey::~TextureFilterColorKey()
{}



/*=========================================================================*/
/**
 * @brief () ���Z�q�I�[�o�[���[�h
 * 
 * �s�N�Z�������H����.
 *
 * @param[in] texel ���H����s�N�Z���l.
 * @return �Ȃ�.
 */
void TextureFilterColorKey::operator () ( unsigned char* texel )
{
	// �J���[�L�[�Ɠ����s�N�Z�������ׂ�
	if( texel[ 0 ] == r_ &&
		texel[ 1 ] == g_ &&
		texel[ 2 ] == b_ &&
		texel[ 3 ] == a_
		){

		// �e�N�Z���l��0�ɂ���
		texel[ 0 ] = 0x00;
		texel[ 1 ] = 0x00;
		texel[ 2 ] = 0x00;
		texel[ 3 ] = 0x00;
	}
}



/*===== EOF ==================================================================*/