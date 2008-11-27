/*******************************************************************************/
/**
 * @file TextureFilterColorKey.h.
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
#ifndef _NGL_TEXTUREFILTERCOLORKEY_H_
#define _NGL_TEXTUREFILTERCOLORKEY_H_

#include	"ITextureFilter.h"

namespace Ngl{


// �J���[�^
struct Color4;

/**
 * @class TextureFilterColorKey�D
 * @brief �J���[�L�[�e�N�X�`���t�B���^�N���X.
 */
class TextureFilterColorKey : public ITextureFilter
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] r �J���[�L�[�Ԑ���( �����l 0�`255 or 16�i�� 0x00�`0xff ).
	 * @param[in] g �J���[�L�[�ΐ���( �����l 0�`255 or 16�i�� 0x00�`0xff ).
	 * @param[in] b �J���[�L�[����( �����l 0�`255 or 16�i�� 0x00�`0xff ).
	 * @param[in] a �J���[�L�[�A���t�@����( �����l 0�`255 or 16�i�� 0x00�`0xff  ).
	 */
	TextureFilterColorKey( unsigned char r=0, unsigned char g=0, unsigned char b=0, unsigned char a=255 );


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] color �J���[�L�[( ���������_�l 0.0f�`1.0f ).
	 */
	TextureFilterColorKey( const Color4& color );

	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~TextureFilterColorKey();


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
	unsigned char r_;

	/** �J���[�L�[�ΐ��� */
	unsigned char g_;

	/** �J���[�L�[���� */
	unsigned char b_;

	/** �J���[�L�[�A���t�@���� */
	unsigned char a_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/