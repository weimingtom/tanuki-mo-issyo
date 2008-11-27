/*******************************************************************************/
/**
 * @file TextureFilterColorKeyAuto.h.
 * 
 * @brief �J���[�L�[�e�N�X�`���t�B���^�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/08/23.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_TEXTUREFILTERCOLORKEYAUTO_H_
#define _NGL_TEXTUREFILTERCOLORKEYAUTO_H_

#include	"ITextureFilter.h"

namespace Ngl{


/**
 * @class TextureFilterColorKeyAuto�D
 * @brief �J���[�L�[�e�N�X�`���t�B���^�N���X.
 *
 * �摜����̃s�N�Z�����J���[�L�[�Ƃ��Đݒ肵�܂��B
 */
class TextureFilterColorKeyAuto : public ITextureFilter
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	TextureFilterColorKeyAuto();


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~TextureFilterColorKeyAuto();


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

private:

	/** �J���[�L�[�Ԑ��� */
	unsigned char	r_;

	/** �J���[�L�[�ΐ��� */
	unsigned char	g_;

	/** �J���[�L�[���� */
	unsigned char	b_;

	/** �J���[�L�[�A���t�@���� */
	unsigned char	a_;

	/** �J���[�L�[�ݒ�t���O */
	bool			setFlag_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/