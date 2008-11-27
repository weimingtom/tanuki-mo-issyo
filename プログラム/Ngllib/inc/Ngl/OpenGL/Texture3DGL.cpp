/*******************************************************************************/
/**
 * @file Texture3DGL.cpp.
 * 
 * @brief OpenGL 3D�e�N�X�`���N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Texture3DGL.h"

using namespace Ngl;
using namespace Ngl::OpenGL;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] desc �e�N�X�`���쐬�L�q�q.
 * @param[in] data �e�N�X�`���C���[�W�f�[�^�z��.
 */
Texture3DGL::Texture3DGL( const TextureDesc& desc, const void* data ):
	TextureGL( desc, data )
{
	initialize( data );
}



/*=========================================================================*/
/**
 * @brief �C���[�W��ݒ�
 * 
 * @param[in] data �ݒ肷��C���[�W�̔z��.
 * @param[in] mipLevel �ݒ��̃~�b�v�}�b�v���x��.
 * @param[in] index �ݒ��̃C���f�b�N�X�ԍ�.
 * @return �Ȃ�.
 */
void Texture3DGL::texImage( const void* data, unsigned int mipLevel, unsigned int index )
{
	// �����k�C���[�W
	glTexImage3D(
		target(index),
		mipLevel,
		pixel().internalFormat,
		mipSize( desc().width, mipLevel ),
		mipSize( desc().height, mipLevel ),
		mipSize( desc().depth, mipLevel ),
		0,
		pixel().format, pixel().type, data
		);
}



/*=========================================================================*/
/**
 * @brief �C���[�W�̍X�V
 * 
 * @param[in] data �X�V����C���[�W�f�[�^�̔z��.
 * @param[in] mipLevel �X�V��̃~�b�v�}�b�v���x��.
 * @param[in] index �X�V��̃C���f�b�N�X�ԍ�.
 * @return OpenGL�^�[�Q�b�g�t���O.
 */
void Texture3DGL::texSubImage( const void* data, unsigned int mipLevel, unsigned int index )
{
	if( pixel().complessedFormat ){
		// ���k�C���[�W
		glCompressedTexSubImage3DARB(
			target( index ),
			mipLevel,
			0, 0, 0,
			mipSize( desc().width, mipLevel ),
			mipSize( desc().height, mipLevel ),
			mipSize( desc().depth, mipLevel ),
			pixel().format,
			imageSize( mipLevel ),
			data
			);
	}
	else{
		// �����k�C���[�W
		glTexSubImage3D(
			target( index ),
			mipLevel,
			0, 0, 0,
			mipSize( desc().width, mipLevel ),
			mipSize( desc().height, mipLevel ),
			mipSize( desc().depth, mipLevel ),
			pixel().format, pixel().type, data
		);
	}
}



/*=========================================================================*/
/**
 * @brief �t���[���o�b�t�@�I�u�W�F�N�g�ւ̃A�^�b�`
 * 
 * @param[in] drawBuffer �`��o�b�t�@�ԍ�.
 * @param[in] index �C���f�b�N�X�ԍ�.
 * @return �Ȃ�.
 */
void Texture3DGL::framebufferTexture( GLuint drawBuffer, unsigned int index )
{
	(void)index;
	glFramebufferTexture3DEXT(
		GL_FRAMEBUFFER_EXT,
		GL_COLOR_ATTACHMENT0_EXT + drawBuffer,
		GL_TEXTURE_3D,
		texture(),
		0,
		index
	);
}



/*===== EOF ==================================================================*/