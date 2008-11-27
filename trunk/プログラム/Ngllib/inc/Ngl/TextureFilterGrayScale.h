/*******************************************************************************/
/**
 * @file TextureFilterGrayScale.h.
 * 
 * @brief �O���[�X�P�[���e�N�X�`���t�B���^�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/08/24.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_TEXTUREFILTERGRAYSCALE_H_
#define _NGL_TEXTUREFILTERGRAYSCALE_H_

#include	"ITextureFilter.h"

namespace Ngl{


/**
 * @class TextureFilterGrayScale�D
 * @brief �O���[�X�P�[���e�N�X�`���t�B���^�N���X.
 */
class TextureFilterGrayScale : public ITextureFilter
{

public:

	/*=========================================================================*/
	/**
	 * @brief () ���Z�q�I�[�o�[���[�h
	 * 
	 * �s�N�Z�������H����.
	 *
	 * @param[in] texel ���H����s�N�Z���l.
	 * @return �Ȃ�.
	 */
	virtual void operator () ( unsigned char* texel );

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/