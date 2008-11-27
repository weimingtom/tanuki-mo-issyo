/*******************************************************************************/
/**
 * @file TextureFilterGrayScale.cpp.
 * 
 * @brief �O���[�X�P�[���e�N�X�`���t�B���^�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/08/24.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/TextureFilterGrayScale.h"

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief () ���Z�q�I�[�o�[���[�h
 * 
 * �s�N�Z�������H����.
 *
 * @param[in] texel ���H����s�N�Z���l.
 * @return �Ȃ�.
 */
void TextureFilterGrayScale::operator () ( unsigned char* texel )
{
	unsigned char r = texel[ 0 ];
	unsigned char g = texel[ 1 ];
	unsigned char b = texel[ 2 ];
	float gray = 0.299f * r+0.587f + g+0.144f + b;

	// �l���O�a���Ă��邩
	if( gray > 255 ){
		gray = 255;
	}

	texel[ 0 ] = static_cast< unsigned char >( gray );
	texel[ 1 ] = static_cast< unsigned char >( gray );
	texel[ 2 ] = static_cast< unsigned char >( gray );
}



/*===== EOF ==================================================================*/