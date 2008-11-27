/*******************************************************************************/
/**
 * @file TextureGL.h.
 * 
 * @brief OpenGL �e�N�X�`�����N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_OPENGL_TEXTUREGL_H_
#define _NGL_OPENGL_TEXTUREGL_H_

#include	"Ngl/ITexture.h"
#include	"OpenGL.h"

namespace Ngl{


namespace OpenGL{


/**
 * @class TextureGL�D
 * @brief OpenGL �e�N�X�`�����N���X.
 */
class TextureGL : public ITexture
{
protected:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] desc �e�N�X�`���쐬�L�q�q.
	 * @param[in] data �e�N�X�`���C���[�W�f�[�^�z��.
	 */
	TextureGL( const TextureDesc& desc, const void* data );

	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~TextureGL();

public:

	/*=========================================================================*/
	/**
	 * @brief �L�q�q���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e�N�X�`���L�q�q.
	 */
	const TextureDesc& desc() const;

	
	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`���f�[�^�̐ݒ�
	 * 
	 * @param[in] data �ݒ肷��f�[�^.
	 * @return �Ȃ�.
	 */
	void setData( const void* data );

	
	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`���f�[�^�̎擾
	 * 
	 * @param[out] data �e�N�X�`���f�[�^���i�[����f�[�^.
	 * @return �Ȃ�.
	 */
	void getData( void* data );

	
	/*=========================================================================*/
	/**
	 * @brief �C���[�W�T�C�Y�̎擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �C���[�W�T�C�Y.
	 */
	unsigned int size() const;

	
	/*=========================================================================*/
	/**
	 * @brief OpenGL�e�N�X�`���I�u�W�F�N�g�̎擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return OpenGl�e�N�X�`���I�u�W�F�N�g.
	 */
	GLuint	texture() const;

	
	/*=========================================================================*/
	/**
	 * @brief �f�v�X�X�e���V���o�b�t�@�ւ̃A�^�b�`
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void attachDepthStencil();

	
	/*=========================================================================*/
	/**
	 * @brief �t���[���o�b�t�@�I�u�W�F�N�g�ւ̃A�^�b�`
	 * 
	 * @param[in] drawBuffer �`��o�b�t�@�ԍ�.
	 * @param[in] index �C���f�b�N�X�ԍ�.
	 * @return �Ȃ�.
	 */
	void attachFramebuffer( GLuint drawBuffer, unsigned int index );

	
	/*=========================================================================*/
	/**
	 * @brief �~�b�v�}�b�v�̍쐬
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void generateMipmap();

protected:

	/**
	 * @struct Type.
	 * @brief OpenGL �e�N�X�`���^�C�v�\����
	 */
	struct Type
	{
		GLenum			target;			/**< �^�[�Q�b�g		*/
		GLenum			arrayTarget;	/**< �^�[�Q�b�g�z�� */
		unsigned int	arraySize;		/**< �z��T�C�Y		*/
	};

	/**
	 * @struct Pixel.
	 * @brief OpenGL �s�N�Z���t�H�[�}�b�g�\����.
	 */
	struct Pixel{
		GLenum	internalFormat;		/**< ���\�[�X�̃t�H�[�}�b�g		*/
		GLenum	format;				/**< �t�H�[�}�b�g				*/
		GLenum	type;				/**< �s�N�Z���^�C�v				*/
		GLuint	size;				/**< �f�[�^�T�C�Y				*/
		bool	complessedFormat;	/**< ���k�t�H�[�}�b�g��			*/
		bool	depthFormat;		/**< �f�v�X�p�t�H�[�}�b�g��		*/
		bool	stencilFormat;		/**< �X�e���V���p�t�H�[�}�b�g��	*/
	};

	/*=========================================================================*/
	/**
	 * @brief  ����������
	 * 
	 * @param[in] data �e�N�X�`���f�[�^.
	 * @return �Ȃ�.
	 */
	void initialize( const void* data );

	
	/*=========================================================================*/
	/**
	 * @brief  �s�N�Z���t�H�[�}�b�g�̎擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �s�N�Z���t�H�[�}�b�g�\����.
	 */
	const Pixel& pixel() const;

	
	/*=========================================================================*/
	/**
	 * @brief �C���[�W�T�C�Y�̌v�Z
	 * 
	 * @param[in] mipLevel �~�b�v�}�b�v���x��.
	 * @return �v�Z�����T�C�Y.
	 */
	unsigned int imageSize( unsigned int mipLevel ) const;

	
	/*=========================================================================*/
	/**
	 * @brief �~�b�v�}�b�v�T�C�Y���擾
	 * 
	 * @param[in] size �e�N�X�`���T�C�Y.
	 * @param[in] mipLevel �~�b�v�}�b�v���x��.
	 * @return �~�b�v�}�b�v�T�C�Y.
	 */
	static unsigned int mipSize( unsigned int size, unsigned int mipLevel );

	
	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`���z��T�C�Y�̎擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e�N�X�`���z��T�C�Y.
	 */
	unsigned int arraySize() const;

	
	/*=========================================================================*/
	/**
	 * @brief OpenGL�^�[�Q�b�g�t���O�̎擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return OpenGL�^�[�Q�b�g�t���O.
	 */
	GLenum target() const;

	
	/*=========================================================================*/
	/**
	 * @brief �C���[�W�p��OpenGL�^�[�Q�b�g�t���O���擾
	 * 
	 * @param[in] index �^�[�Q�b�g�ԍ�.
	 * @return OpenGL�^�[�Q�b�g�t���O.
	 */
	GLenum target( unsigned int index ) const;


	/*=========================================================================*/
	/**
	 * @brief �C���[�W���擾
	 * 
	 * @param[out] data �擾�����f�[�^���i�[����z��.
	 * @param[in] mipLevel �擾����C���[�W�̃~�b�v�}�b�v���x��.
	 * @param[in] index �e�N�X�`���C���f�b�N�X.
	 * @return �Ȃ�.
	 */
	void getTexImage( void* data, unsigned int mipLevel, unsigned int index ) const;


	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`���^�C�v��ϊ�
	 * 
	 * @param[in] type �ϊ�����e�N�X�`���^�C�v�t���O.
	 * @param[in] �ϊ������e�N�X�`���^�C�v�\����.
	 * @return �Ȃ�.
	 */
	static const Type& toType( TextureType type );

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
	virtual void texImage( const void* data, unsigned int mipLevel, unsigned int index ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �C���[�W�̍X�V
	 * 
	 * @param[in] data �X�V����C���[�W�f�[�^�̔z��.
	 * @param[in] mipLevel �X�V��̃~�b�v�}�b�v���x��.
	 * @param[in] index �X�V��̃C���f�b�N�X�ԍ�.
	 * @return OpenGL�^�[�Q�b�g�t���O.
	 */
	virtual void texSubImage( const void* data, unsigned int mipLevel, unsigned int index ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �t���[���o�b�t�@�I�u�W�F�N�g�ւ̃A�^�b�`
	 * 
	 * @param[in] drawBuffer �`��o�b�t�@�ԍ�.
	 * @param[in] index �C���f�b�N�X�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void framebufferTexture( GLuint drawBuffer, unsigned int index ) = 0;

private:
	
	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^( �R�s�[�֎~ )
	 * 
	 * @param[in] other �������I�u�W�F�N�g.
	 */
	TextureGL( const TextureGL& other );
	
	
	/*=========================================================================*/
	/**
	 * @brief = ���Z�q�I�[�o�[���[�h( �R�s�[�֎~ )
	 * 
	 * @param[in] other �������I�u�W�F�N�g.
	 * @return ������ʂ̃I�u�W�F�N�g.
	 */
	TextureGL& operator = ( const TextureGL& other );

private:

	/** �e�N�X�`���L�q�q */
	TextureDesc		desc_;

	/** �e�N�X�`���^�C�v */
	Type			type_;

	/** �e�N�X�`���I�u�W�F�N�g */
	GLuint			texture_;

	/** �f�v�X�e�N�X�`�� */
	GLuint			depthTexture_;

	/** �X�e���V���e�N�X�`�� */
	GLuint			stencilTexture_;

};

} // namespace OpenGL

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/