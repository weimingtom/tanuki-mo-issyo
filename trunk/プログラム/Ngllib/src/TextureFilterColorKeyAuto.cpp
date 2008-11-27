/*******************************************************************************/
/**
 * @file TextureFilterColorKeyAuto.cpp.
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
#include	"Ngl/TextureFilterColorKeyAuto.h"

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
TextureFilterColorKeyAuto::TextureFilterColorKeyAuto():
	r_( 0 ),
	g_( 0 ),
	b_( 0 ),
	a_( 255 ),
	setFlag_( false )
{}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
TextureFilterColorKeyAuto::~TextureFilterColorKeyAuto()
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
void TextureFilterColorKeyAuto::operator () ( unsigned char* texel )
{
	// �J���[�L�[���ݒ肳��Ă��Ȃ���
	if( setFlag_ == false ){
		// �J���[�L�[��ݒ�
		r_ = texel[ 0 ];
		g_ = texel[ 1 ];
		b_ = texel[ 2 ];
		a_ = texel[ 3 ];
		setFlag_ = true;
	}

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