/*******************************************************************************/
/**
 * @file TextureGL.cpp.
 * 
 * @brief OpenGL �e�N�X�`�����N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/OpenGL/TextureGL.h"

using namespace Ngl;
using namespace Ngl::OpenGL;


/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] desc �e�N�X�`���쐬�L�q�q.
 * @param[in] data �e�N�X�`���C���[�W�f�[�^�z��.
 */
TextureGL::TextureGL( const TextureDesc& desc, const void* data ):
	desc_( desc ),
	type_( toType( desc.type ) ),
	texture_( 0 ),
	depthTexture_( 0 ),
	stencilTexture_( 0 )
{
	// �e�N�X�`�����쐬����
	glGenTextures( 1, &texture_ );

	// �f�v�X�o�b�t�@�Ŏg�p���邩
	if( pixel().depthFormat ){
		depthTexture_		= texture_;
		type_.target		= GL_TEXTURE_2D;
		type_.arrayTarget	= GL_TEXTURE_2D;
		type_.arraySize		= 1;
	}

	// �X�e���V���o�b�t�@�Ŏg�p���邩
	if( pixel().stencilFormat ){
		stencilTexture_		= texture_;
		type_.target		= GL_TEXTURE_2D;
		type_.arrayTarget	= GL_TEXTURE_2D;
		type_.arraySize		= 1;
	}
}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
TextureGL::~TextureGL()
{
	glDeleteTextures( 1, &texture_ );
}



/*=========================================================================*/
/**
 * @brief �L�q�q���擾����
 * 
 * @param[in] �Ȃ�.
 * @return �e�N�X�`���L�q�q.
 */
const TextureDesc& TextureGL::desc() const
{
	return desc_;
}



/*=========================================================================*/
/**
 * @brief �e�N�X�`���f�[�^�̐ݒ�
 * 
 * @param[in] data �ݒ肷��f�[�^.
 * @return �Ȃ�.
 */
void TextureGL::setData( const void* data )
{
	glBindTexture( target(), texture_ );
	const GLubyte* base = static_cast< const GLubyte* >( data );
	for( unsigned int i=0; i<arraySize(); ++i ){
		for( unsigned int mip=0; mip<desc().mipLevels; ++mip ){
			texImage( base, mip, i );
			if( data != 0 ){
				base += imageSize( mip );
			}
		}
	}

	glBindTexture( target(), 0 );
}



/*=========================================================================*/
/**
 * @brief �e�N�X�`���f�[�^�̎擾
 * 
 * @param[out] data �e�N�X�`���f�[�^���i�[����f�[�^.
 * @return �Ȃ�.
 */
void TextureGL::getData( void* data )
{
	// �e�N�X�`�����o�C���h����
	glBindTexture( target(), texture_ );

	// �C���[�W�̎擾
	GLubyte* base = static_cast< GLubyte* >( data );
	for( unsigned int i=0; i<arraySize(); ++i ){
		for( unsigned int mip=0; mip<desc().mipLevels; ++mip ){
			// �e�N�X�`���C���[�W���擾
			getTexImage( base, mip, i );
			base += imageSize( mip );
		}
	}

	// �o�C���h������������
	glBindTexture( target(), 0 );
}



/*=========================================================================*/
/**
 * @brief �C���[�W�T�C�Y�̎擾
 * 
 * @param[in] �Ȃ�.
 * @return �C���[�W�T�C�Y.
 */
unsigned int TextureGL::size() const
{
	unsigned int size = 0;
	for( unsigned int mip=0; mip<desc_.mipLevels; ++mip ){
		size += imageSize( mip );
	}

	return size;
}



/*=========================================================================*/
/**
 * @brief OpenGL�e�N�X�`���I�u�W�F�N�g�̎擾
 * 
 * @param[in] �Ȃ�.
 * @return OpenGl�e�N�X�`���I�u�W�F�N�g.
 */
GLuint	TextureGL::texture() const
{
	return texture_;
}



/*=========================================================================*/
/**
 * @brief �f�v�X�X�e���V���o�b�t�@�ւ̃A�^�b�`
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void TextureGL::attachDepthStencil()
{
	// �f�v�X�o�b�t�@�p�̃e�N�X�`����ݒ�
	glFramebufferTexture2DEXT(
		GL_FRAMEBUFFER_EXT,
		GL_DEPTH_ATTACHMENT_EXT,
		GL_TEXTURE_2D,
		depthTexture_,
		0
		);

	// �X�e���V���o�b�t�@�p�̃e�N�X�`����ݒ�
	glFramebufferTexture2DEXT(
		GL_FRAMEBUFFER_EXT,
		GL_STENCIL_ATTACHMENT_EXT,
		GL_TEXTURE_2D,
		stencilTexture_,
		0
		);
}



/*=========================================================================*/
/**
 * @brief �t���[���o�b�t�@�I�u�W�F�N�g�ւ̃A�^�b�`
 * 
 * @param[in] drawBuffer �`��o�b�t�@�ԍ�.
 * @param[in] index �C���f�b�N�X�ԍ�.
 * @return �Ȃ�.
 */
void TextureGL::attachFramebuffer( GLuint drawBuffer, unsigned int index )
{
	framebufferTexture( drawBuffer, index );
}



/*=========================================================================*/
/**
 * @brief �~�b�v�}�b�v�̍쐬
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void TextureGL::generateMipmap()
{
	glEnable( target() );
	glBindTexture( target(), texture_ );
	glGenerateMipmapEXT( target() );
	glBindTexture( target(), 0 );
	glDisable( target() );
}

	

/*=========================================================================*/
/**
 * @brief  ����������
 * 
 * @param[in] data �e�N�X�`���f�[�^.
 * @return �Ȃ�.
 */
void TextureGL::initialize( const void* data )
{
	// �e�N�X�`�����o�C���h
	glBindTexture( target(), texture_ );

	// �e�N�X�`���C���[�W�̐ݒ�
	const GLubyte* base = static_cast< const GLubyte* >( data );
	for( unsigned int i=0; i<arraySize(); ++i ){
		for( unsigned int mip=0; mip<desc().mipLevels; ++mip ){
			texImage( base, mip, i );
			if( data != 0 ){
				base += imageSize( mip );
			}
		}
	}

	// �f�t�H���g�̃e�N�X�`���p�����[�^
	glTexParameteri( target(), GL_TEXTURE_MAG_FILTER, GL_NEAREST );
	glTexParameteri( target(), GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glBindTexture( target(), 0 );
}



/*=========================================================================*/
/**
 * @brief  �s�N�Z���t�H�[�}�b�g�̎擾
 * 
 * @param[in] �Ȃ�.
 * @return �s�N�Z���t�H�[�}�b�g�\����.
 */
const TextureGL::Pixel& TextureGL::pixel() const
{
	static const Pixel pixelFormat[] = {
		{ GL_INTENSITY8,					GL_LUMINANCE,			GL_UNSIGNED_BYTE,						sizeof( GLubyte ) * 1,		false,	false,	false },	// TEXTURE_FORMAT_I8			= 0
		{ GL_LUMINANCE8_ALPHA8,				GL_LUMINANCE_ALPHA,		GL_UNSIGNED_BYTE,						sizeof( GLubyte ) * 2,		false,	false,	false },	// TEXTURE_FORMAT_IA8			= 1
		{ GL_RGBA8,							GL_RGBA,				GL_UNSIGNED_BYTE,						sizeof( GLubyte ) * 4,		false,	false,	false },	// TEXTURE_FORMAT_RGBA8			= 2
		{ GL_INTENSITY16,					GL_LUMINANCE,			GL_UNSIGNED_SHORT,						sizeof( GLushort ) * 1,		false,	false,	false },	// TEXTURE_FORMAT_I16			= 3
		{ GL_LUMINANCE16_ALPHA16,			GL_LUMINANCE_ALPHA,		GL_UNSIGNED_SHORT,						sizeof( GLushort ) * 2,		false,	false,	false },	// TEXTURE_FORMAT_IA16			= 4
		{ GL_RGBA16,						GL_RGBA,				GL_UNSIGNED_SHORT,						sizeof( GLushort ) * 4,		false,	false,	false },	// TEXTURE_FORMAT_RGBA16		= 5
		{ GL_INTENSITY16F_ARB,				GL_LUMINANCE,			GL_HALF_FLOAT_ARB,						sizeof( GLfloat ) / 2 * 1,	false,	false,	false },	// TEXTURE_FORMAT_I16F			= 6
		{ GL_LUMINANCE_ALPHA16F_ARB,		GL_LUMINANCE_ALPHA,		GL_HALF_FLOAT_ARB,						sizeof( GLfloat ) / 2 * 2,	false,	false,	false },	// TEXTURE_FORMAT_IA16F			= 7,
		{ GL_RGBA16F_ARB,					GL_RGBA,				GL_HALF_FLOAT_ARB,						sizeof( GLfloat ) / 2 * 4,	false,	false,	false },	// TEXTURE_FORMAT_RGBA16F		= 8,
		{ GL_INTENSITY32F_ARB,				GL_LUMINANCE,			GL_FLOAT,								sizeof( GLfloat ) * 1,		false,	false,	false },	// TEXTURE_FORMAT_I32F			= 9,
		{ GL_LUMINANCE_ALPHA32F_ARB,		GL_LUMINANCE_ALPHA,		GL_FLOAT,								sizeof( GLfloat ) * 2,		false,	false,	false },	// TEXTURE_FORMAT_IA32F			= 10
		{ GL_RGB32F_ARB,					GL_RGB,					GL_FLOAT,								sizeof( GLfloat ) * 3,		false,	false,	false },	// TEXTURE_FORMAT_RGB32F		= 11
		{ GL_RGBA32F_ARB,					GL_RGBA,				GL_FLOAT,								sizeof( GLfloat ) * 4,		false,	false,	false },	// TEXTURE_FORMAT_RGBA32F		= 12
		{ GL_R11F_G11F_B10F_EXT,			GL_RGB,					GL_UNSIGNED_INT_10F_11F_11F_REV_EXT,	sizeof( GLuint ),			false,	false,	false },	// TEXTURE_FORMAT_R11G11B10F	= 13
		{ GL_COMPRESSED_RGB_S3TC_DXT1_EXT,	GL_RGB,					GL_UNSIGNED_BYTE,						sizeof( GLubyte ) * 8,		true,	false,	false },	// TEXTURE_FORMAT_DXT1			= 14
		{ GL_COMPRESSED_RGBA_S3TC_DXT3_EXT,	GL_RGBA,				GL_UNSIGNED_BYTE,						sizeof( GLubyte ) * 16,		true,	false,	false },	// TEXTURE_FORMAT_DXT3			= 15
		{ GL_COMPRESSED_RGBA_S3TC_DXT5_EXT,	GL_RGBA,				GL_UNSIGNED_BYTE,						sizeof( GLubyte ) * 16,		true,	false,	false },	// TEXTURE_FORMAT_DXT5			= 16
		{ GL_DEPTH_COMPONENT16,				GL_DEPTH_COMPONENT,		GL_UNSIGNED_SHORT,						sizeof( GLushort ) * 1,		false,	true,	false },	// TEXTIRE_FORMAT_D16			= 17
		{ GL_DEPTH_COMPONENT32,				GL_DEPTH_COMPONENT,		GL_FLOAT,								sizeof( GLfloat ) * 1,		false,	true,	false },	// TEXTURE_FORMAT_D32F			= 18
		{ GL_DEPTH24_STENCIL8_EXT,			GL_DEPTH_STENCIL_EXT,	GL_UNSIGNED_INT_24_8_EXT,				sizeof( GLubyte ) * 4,		false,	true,	true  }		// TEXTURE_FORMAT_D24S8			= 19
	};

	return pixelFormat[ desc_.format ];
}



/*=========================================================================*/
/**
 * @brief �C���[�W�T�C�Y�̌v�Z
 * 
 * @param[in] mipLevel �~�b�v�}�b�v���x��.
 * @return �v�Z�����T�C�Y.
 */
unsigned int TextureGL::imageSize( unsigned int mipLevel ) const
{
	// �~�b�v���x���ɍ��킹���T�C�Y�����߂�
	unsigned int w = mipSize( desc().width, mipLevel );
	unsigned int h = mipSize( desc().height, mipLevel );
	unsigned int d = mipSize( desc().depth, mipLevel );

	// DXT�t�H�[�}�b�g��
	if( pixel().complessedFormat == true ){
		// DXT�̃u���b�N�T�C�Y�ɕύX
		w = ( w + 3 ) / 4;
		h = ( h + 3 ) / 4;
	}

	// �C���[�W�T�C�Y�̌v�Z
	return w * h * d * pixel().size;
}



/*=========================================================================*/
/**
 * @brief �~�b�v�}�b�v�T�C�Y���擾
 * 
 * @param[in] size �e�N�X�`���T�C�Y.
 * @param[in] mipLevel �~�b�v�}�b�v���x��.
 * @return �~�b�v�}�b�v�T�C�Y.
 */
unsigned int TextureGL::mipSize( unsigned int size, unsigned int mipLevel )
{
	return ( ( size >> mipLevel ) <= 0 ) ? 1 : ( size >> mipLevel );
}



/*=========================================================================*/
/**
 * @brief �e�N�X�`���z��T�C�Y�̎擾
 * 
 * @param[in] �Ȃ�.
 * @return �e�N�X�`���z��T�C�Y.
 */
unsigned int TextureGL::arraySize() const
{
	return type_.arraySize;
}



/*=========================================================================*/
/**
 * @brief OpenGL�^�[�Q�b�g�t���O�̎擾
 * 
 * @param[in] �Ȃ�.
 * @return OpenGL�^�[�Q�b�g�t���O.
 */
GLenum TextureGL::target() const
{
	return type_.target;
}



/*=========================================================================*/
/**
 * @brief �C���[�W�p��OpenGL�^�[�Q�b�g�t���O���擾
 * 
 * @param[in] index �^�[�Q�b�g�ԍ�.
 * @return OpenGL�^�[�Q�b�g�t���O.
 */
GLenum TextureGL::target( unsigned int index ) const
{
	return type_.arrayTarget + index;
}



/*=========================================================================*/
/**
 * @brief �C���[�W���擾
 * 
 * @param[out] data �擾�����f�[�^���i�[����z��.
 * @param[in] mipLevel �擾����C���[�W�̃~�b�v�}�b�v���x��.
 * @param[in] index �e�N�X�`���C���f�b�N�X.
 * @return �Ȃ�.
 */
void TextureGL::getTexImage( void* data, unsigned int mipLevel, unsigned int index ) const
{
	glGetTexImage(
		target( index ),
		mipLevel,
		pixel().format, pixel().type, data
	);
}



/*=========================================================================*/
/**
 * @brief �e�N�X�`���^�C�v��ϊ�
 * 
 * @param[in] type �ϊ�����e�N�X�`���^�C�v�t���O.
 * @param[in] �ϊ������e�N�X�`���^�C�v�\����.
 * @return �Ȃ�.
 */
const TextureGL::Type& TextureGL::toType( TextureType type )
{
	// ����͂Q�c�̂�
	static const Type types[] = {
		{ GL_TEXTURE_1D,		GL_TEXTURE_1D,					1 },	// TEXTURE_TYPE_1D		= 0
		{ GL_TEXTURE_2D,		GL_TEXTURE_2D,					1 },	// TEXTURE_TUPE_2D		= 1
		{ GL_TEXTURE_3D,		GL_TEXTURE_3D,					1 },	// TEXTURE_TYPE_3D		= 2
		{ GL_TEXTURE_CUBE_MAP,	GL_TEXTURE_CUBE_MAP_POSITIVE_X,	6 }		// TEXTURE_TYPE_CUBE	= 3
	};

	return types[type];
}



/*===== EOF ==================================================================*/