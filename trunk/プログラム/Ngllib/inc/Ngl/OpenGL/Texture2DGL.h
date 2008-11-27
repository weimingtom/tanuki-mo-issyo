/*******************************************************************************/
/**
 * @file Texture2DGL.h.
 * 
 * @brief OpenGL 2D�e�N�X�`���N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_OPENGL_TEXTURE2DGL_H_
#define _NGL_OPENGL_TEXTURE2DGL_H_

#include	"TextureGL.h"

namespace Ngl{


namespace OpenGL{


/**
 * @class Texture2DGL.
 * @brief OpenGL 2D�e�N�X�`���N���X.
 */
class Texture2DGL : public TextureGL
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] desc �e�N�X�`���쐬�L�q�q.
	 * @param[in] data �e�N�X�`���C���[�W�f�[�^�z��.
	 */
	Texture2DGL( const TextureDesc& desc, const void* data=0 );

private:

	/*=========================================================================*/
	/**
	 * @brief �C���[�W��ݒ�
	 * 
	 * @param[in] data �ݒ肷��C���[�W�̔z��.
	 * @param[in] mipLevel �ݒ��̃~�b�v�}�b�v���x��.
	 * @param[in] index �ݒ��̃C���f�b�N�X�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void texImage( const void* data, unsigned int mipLevel, unsigned int index );


	/*=========================================================================*/
	/**
	 * @brief �C���[�W�̍X�V
	 * 
	 * @param[in] data �X�V����C���[�W�f�[�^�̔z��.
	 * @param[in] mipLevel �X�V��̃~�b�v�}�b�v���x��.
	 * @param[in] index �X�V��̃C���f�b�N�X�ԍ�.
	 * @return OpenGL�^�[�Q�b�g�t���O.
	 */
	virtual void texSubImage( const void* data, unsigned int mipLevel, unsigned int index );

	
	/*=========================================================================*/
	/**
	 * @brief �t���[���o�b�t�@�I�u�W�F�N�g�ւ̃A�^�b�`
	 * 
	 * @param[in] drawBuffer �`��o�b�t�@�ԍ�.
	 * @param[in] index �C���f�b�N�X�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void framebufferTexture( GLuint drawBuffer, unsigned int index );
};

} // namespace OpenGL

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/