/*******************************************************************************/
/**
 * @file Texture2DGL.cpp.
 * 
 * @brief OpenGL 2D�e�N�X�`���N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/OpenGL/Texture2DGL.h"

using namespace Ngl;
using namespace Ngl::OpenGL;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] desc �e�N�X�`���쐬�L�q�q.
 * @param[in] data �e�N�X�`���C���[�W�f�[�^�z��.
 */
Texture2DGL::Texture2DGL( const TextureDesc& desc, const void* data ):
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
void Texture2DGL::texImage( const void* data, unsigned int mipLevel, unsigned int index )
{
	if( pixel().complessedFormat ){
		// ���k�C���[�W
		glCompressedTexImage2DARB(
			target( index ),
			mipLevel,
			pixel().internalFormat,
			mipSize( desc().width, mipLevel ),
			mipSize( desc().height, mipLevel ),
			0,
			imageSize( mipLevel ),
			data
			);
	}
	else{
		// �����k�C���[�W
		glTexImage2D(
			target(index),
			mipLevel,
			pixel().internalFormat,
			mipSize( desc().width, mipLevel ),
			mipSize( desc().height, mipLevel ),
			0,
			pixel().format, pixel().type, data
			);
	}
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
void Texture2DGL::texSubImage( const void* data, unsigned int mipLevel, unsigned int index )
{
	if( pixel().complessedFormat ){
		// ���k�C���[�W
		glCompressedTexSubImage2DARB(
			target( index ),
			mipLevel,
			0, 0,
			mipSize( desc().width, mipLevel ),
			mipSize( desc().height, mipLevel ),
			pixel().format,
			imageSize( mipLevel ),
			data
			);
	}
	else{
		// �����k�C���[�W
		glTexSubImage2D(
			target( index ),
			mipLevel,
			0, 0,
			mipSize( desc().width, mipLevel ),
			mipSize( desc().height, mipLevel ),
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
void Texture2DGL::framebufferTexture( GLuint drawBuffer, unsigned int index )
{
	(void)index;
	glFramebufferTexture2DEXT(
		GL_FRAMEBUFFER_EXT,
		GL_COLOR_ATTACHMENT0_EXT + drawBuffer,
		target( index ),
		texture(),
		0
	);
}



/*===== EOF ==================================================================*/