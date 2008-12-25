/*******************************************************************************/
/**
 * @file RendererGL.cpp.
 * 
 * @brief OpenGL �����_���[�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/OpenGL/RendererGL.h"
#include	"Ngl/OpenGL/BufferGL.h"
#include	"Ngl/OpenGL/VertexDeclarationGL.h"
#include	"Ngl/OpenGL/EffectCgGL.h"
#include	"Ngl/OpenGL/Texture1DGL.h"
#include	"Ngl/OpenGL/Texture2DGL.h"
#include	"Ngl/OpenGL/Texture3DGL.h"
#include	<cassert>

using namespace Ngl;
using namespace Ngl::OpenGL;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
RendererGL::RendererGL():
	vertexDeclaration_( 0 ),
	indexBuffer_( 0 ),
	indexFormat_( toIndexFormat( INDEX_TYPE_USHORT ) ),
	indexOffset_( 0 ),
	primitiveMode_( toPrimitiveMode( PRIMITIVE_TYPE_TRIANGLE_LIST ) ),
	framebufferObject_( 0 )
{
	// �t���[���o�b�t�@�I�u�W�F�N�g�̍쐬
	glGenFramebuffersEXT( 1, &framebufferObject_ );

	// ����������
	initialize();
}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
RendererGL::~RendererGL()
{
	// ��Ԃ�����������
	clearState();

	// �t���[���o�b�t�@�I�u�W�F�N�g�̍폜
	glDeleteFramebuffersEXT( 1, &framebufferObject_ );
}



/*=========================================================================*/
/**
 * @brief ����������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void RendererGL::initialize()
{
	// �ʃJ�����O�̐ݒ�
	//glEnable( GL_CULL_FACE );
	//glCullFace( GL_BACK );
	//glFrontFace( GL_CCW );
	
	// �f�v�X�o�b�t�@��1.0�ŃN���A����
	glEnable( GL_DEPTH_TEST );
	glDepthFunc( GL_LESS );

	// �A���t�@�e�X�g�̐ݒ�
	glEnable( GL_ALPHA_TEST  );
	glAlphaFunc( GL_GREATER, 0.0f );

	// �u�����h�X�e�[�g�̐ݒ�
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	// �p�[�X�y�N�e�B�u�␳���s��
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
}



/*=========================================================================*/
/**
 * @brief �r���[�|�[�g�̐ݒ�
 * 
 * @param[in] desc �r���[�|�[�g�L�q�q.
 * @return �Ȃ�.
 */
void RendererGL::setViewport( const ViewportDesc& desc )
{
	glViewport( desc.x, desc.y, desc.width, desc.height );
	viewport_ = desc;
}



/*=========================================================================*/
/**
 * @brief �r���[�|�[�g�̎擾
 * 
 * @param[in] �Ȃ�.
 * @return �r���[�|�[�g�L�q�q.
 */
const ViewportDesc& RendererGL::getViewport() const
{
	return viewport_;
}



/*=========================================================================*/
/**
 * @brief �J���[�o�b�t�@����
 * 
 * @param[in] r �N���A�J���[�Ԑ���.
 * @param[in] g �N���A�J���[�ΐ���.
 * @param[in] b �N���A�J���[����.
 * @param[in] a �N���A�J���[�A���t�@����.	 
 * @return �Ȃ�.
 */
void RendererGL::clearColorBuffer( float r, float g, float b, float a )
{
	// �N���A�J���[��ݒ肷��
	glClearColor( r, g, b, a );

	// �J���[�o�b�t�@�̏���
	glClear( GL_COLOR_BUFFER_BIT );

}



/*=========================================================================*/
/**
 * @brief �f�v�X�X�e���V���o�b�t�@������
 * 
 * @param[in] depth �f�v�X�o�b�t�@���������邩.
 * @param[in] stencil �X�e���V���o�b�t�@���������邩.
 * @return �Ȃ�.
 */
void RendererGL::clearDepthStencilBuffer( bool depth, bool stencil )
{
	GLbitfield mask = 0;

	if( depth ){
		mask |= GL_DEPTH_BUFFER_BIT;
	}

	if( stencil ){
		mask |= GL_STENCIL_BUFFER_BIT;
	}

	glClear( mask );
}



/*=========================================================================*/
/**
 * @brief �o�b�t�@���쐬
 * 
 * @param[in] desc �o�b�t�@�L�q�q.
 * @param[in] data �o�b�t�@�f�[�^.
 * @return �쐬�����o�b�t�@�C���^�[�t�F�[�X�̃|�C���^.
 */
IBuffer* RendererGL::createBuffer( const BufferDesc& desc, const void* data )
{
	return new BufferGL( desc, data );
}



/*=========================================================================*/
/**
 * @brief �e�N�X�`�����쐬
 * 
 * @param[in] desc �e�N�X�`���L�q�q.
 * @param[in] data �e�N�X�`���f�[�^.
 * @return �쐬�����e�N�X�`���C���^�[�t�F�[�X�̃|�C���^.
 */
ITexture* RendererGL::createTexture( const TextureDesc& desc, const void* data )
{
	TextureGL* texture = 0;
	switch( desc.type ){
		case TEXTURE_TYPE_1D:
			texture = new Texture1DGL( desc, data );
			break;
		case TEXTURE_TYPE_2D:
			texture = new Texture2DGL( desc, data );
			break;
		case TEXTURE_TYPE_3D:
			texture = new Texture3DGL( desc, data );
			break;
		case TEXTURE_TYPE_CUBE:
			texture = new Texture2DGL( desc, data );
	}

	return texture;
}



/*=========================================================================*/
/**
 * @brief ���_�錾���쐬
 * 
 * @param[in] desc ���_�錾�L�q�q�̔z��.
 * @param[in] numDesc ���_�錾�L�q�q�z��̗v�f��.
 * @param[in] inputSignature ���̓V�O�l�`���L�q�q.
 * @return �쐬�������_�錾�C���^�[�t�F�[�X�̃|�C���^.
 */
IVertexDeclaration* RendererGL::createVertexDeclaration( const VertexDeclarationDesc desc[], unsigned int numDesc, const InputSignatureDesc& inputSignature )
{
	(void)inputSignature;	// OpenGL�ł͎g�p���Ȃ�
	return new VertexDeclarationGL( desc, numDesc );
}



/*=========================================================================*/
/**
 * @brief �G�t�F�N�g�̍쐬
 * 
 * @param[in] fileName �G�t�F�N�g�t�@�C����.
 * @return �쐬�����G�t�F�N�g�C���^�[�t�F�[�X�̃|�C���^.
 */
IEffect* RendererGL::createEffect( const char* fileName )
{
	return new EffectCgGL( fileName );
}



/*=========================================================================*/
/**
 * @brief ���_�錾�f�[�^��ݒ�
 * 
 * @param[in] layout �ݒ肷�钸�_�錾�f�[�^�̃|�C���^.
 * @return �Ȃ�.
 */
void RendererGL::setVertexDeclaration( IVertexDeclaration* layout )
{
	vertexDeclaration_ = static_cast< VertexDeclarationGL* >( layout );
}



/*=========================================================================*/
/**
 * @brief �o�b�t�@��ݒ�
 * 
 * @param[in] stream ���_�X�g���[���L�q�q�z��.
 * @param[in] numStream ���_�X�g���[���L�q�q�z��̗v�f��.
 * @param[in] offset �I�t�Z�b�g�l.
 * @return �Ȃ�.
 */
void RendererGL::setVertexBuffer( const VertexStreamDesc stream[], unsigned int numStream, unsigned int offset )
{
	for( unsigned int i=0; i<numStream; ++i ){
		vertexStream_[i+offset] = stream[i];
	}
}



/*=========================================================================*/
/**
 * @brief �C���f�b�N�X�o�b�t�@��ݒ�
 * 
 * @param[in] buffer �C���f�b�N�X�o�b�t�@�̃|�C���^.
 * @param[in] type ���_�^�C�v.
 * @param[in] offset �I�t�Z�b�g�l.
 * @return �Ȃ�.
 */
void RendererGL::setIndexBuffer( IBuffer* buffer, IndexType type, unsigned int offset )
{
	indexBuffer_ = static_cast< BufferGL* >( buffer );
	indexFormat_ = toIndexFormat( type );
	indexOffset_ = offset;
}



/*=========================================================================*/
/**
 * @brief �~�b�v�}�b�v�̍쐬
 * 
 * @param[in] texture �~�b�v�}�b�v���쐬����e�N�X�`���̃|�C���^.
 * @return �Ȃ�.
 */
void RendererGL::generateMipmap( ITexture* texture )
{
	TextureGL* tex = static_cast< TextureGL* >( texture );
	tex->generateMipmap();
}



/*=========================================================================*/
/**
 * @brief �`�悷��v���~�e�B�u��ݒ�
 * 
 * @param[in] primitive �v���~�e�B�u�^�C�v.
 * @return �Ȃ�.
 */
void RendererGL::setPrimitive( PrimitiveType primitive )
{
	primitiveMode_ = toPrimitiveMode( primitive );
}



/*=========================================================================*/
/**
 * @brief ���_�o�b�t�@��`��
 * 
 * @param[in] numVertex �`�悷�钸�_��.
 * @param[in] start �J�n���_�ԍ�.
 * @return �Ȃ�.
 */
void RendererGL::draw( unsigned int numVertex, unsigned int start )
{
	// ���_�錾��ݒ�
	vertexDeclaration_->setVertexStream( vertexStream_, start );

	// ���_�o�b�t�@�̕`��
	glDrawArrays( primitiveMode_, 0, numVertex );

	// ���_�o�b�t�@�����Z�b�g����
	vertexDeclaration_->resetVertexStream();
}



/*=========================================================================*/
/**
 * @brief �C���f�b�N�X�o�b�t�@���g�p���ĕ`�悷��
 * 
 * @param[in] numIndices �C���f�b�N�X��.
 * @param[in] startIndex �J�n�C���f�b�N�X�ԍ�.
 * @param[in] startVertex �J�n���_�ԍ�
 * @return �Ȃ�.
 */
void RendererGL::drawIndexed( unsigned int numIndices, unsigned int startIndex, unsigned int startVertex )
{
	// ���_�o�b�t�@��ݒ肷��
	vertexDeclaration_->setVertexStream( vertexStream_, startVertex );

	// �C���f�b�N�X�o�b�t�@���o�C���h����
	glBindBufferARB( GL_ELEMENT_ARRAY_BUFFER_ARB, indexBuffer_->buffer() );

	GLubyte* base = 0;
	glDrawElements( 
		primitiveMode_,
		numIndices,
		indexFormat_.type,
		&base[ ( indexOffset_ + startIndex ) * indexFormat_.size ]
	);

	// �C���f�b�N�X�o�b�t�@�����Z�b�g����
	glBindBufferARB( GL_ELEMENT_ARRAY_BUFFER_ARB, 0 );

	// ���_�o�b�t�@�����Z�b�g����
	vertexDeclaration_->resetVertexStream();
}



/*=========================================================================*/
/**
 * @brief �e�N�X�`���������_�[�^�[�Q�b�g�ɐݒ�
 * 
 * @param[in] targets �ݒ肷��e�N�X�`���̔z��.
 * @param[in] numTargets �e�N�X�`���z��̗v�f��.
 * @param[in] depthStencil �f�v�X�X�e���V���o�b�t�@�Ƃ��Ďg�p����e�N�X�`���̃|�C���^.
 * @param[in] index �J�n�C���f�b�N�X�ԍ�.
 * @return �Ȃ�.
 */
void RendererGL::setRenderTargets( ITexture* targets[], unsigned int numTargets, ITexture* depthStencil, unsigned int index )
{
	// �����_�[�^�[�Q�b�g�����Z�b�g����
	resetRenderTargets();

	// �����ݒ肳��Ă��Ȃ��ꍇ�̓��Z�b�g�̂�
	if( targets == 0 && depthStencil == 0 ){
		return;
	}

	// �t���[���o�b�t�@�I�u�W�F�N�g�̃o�C���h
	glBindFramebufferEXT( GL_FRAMEBUFFER_EXT, framebufferObject_ );

	// �f�v�X�X�e���V���o�b�t�@�̐ݒ�
	TextureGL* depthStencilBuffer = static_cast< TextureGL* >( depthStencil );
	if( depthStencilBuffer != 0 ){
		// �f�v�X�X�e���V���o�b�t�@�ɃA�^�b�`
		depthStencilBuffer->attachDepthStencil();
	}

	// �����_�[�^�[�Q�b�g�̐ݒ�
	GLenum drawBuffers[ RENDER_TARGET_MAX ];
	for( GLuint i=0; i<numTargets; ++i ){
		// �e�N�X�`�����t���[���o�b�t�@�I�u�W�F�N�g�ɃA�^�b�`
		static_cast< TextureGL* >( targets[i] )->attachFramebuffer( i, index );

		// �`��o�b�t�@�̐ݒ�
		drawBuffers[i] = GL_COLOR_ATTACHMENT0_EXT + i;
	}

	// �����_�[�^�[�Q�b�g�����݂��邩
	if( numTargets > 0 ){
		// �`��o�b�t�@�̐ݒ�
		glDrawBuffersARB( numTargets, drawBuffers );
	}
	else{
		// �`��o�b�t�@�ւ̏������݂����Ȃ��悤�ɂ���
		glDrawBuffer( GL_NONE );
		glReadBuffer( GL_NONE );
	}

	assert( glCheckFramebufferStatusEXT( GL_FRAMEBUFFER_EXT ) == GL_FRAMEBUFFER_COMPLETE_EXT );
}



/*=========================================================================*/
/**
 * @brief �����_�[�^�[�Q�b�g�����Z�b�g
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void RendererGL::resetRenderTargets()
{
	glBindFramebufferEXT( GL_FRAMEBUFFER_EXT, framebufferObject_ );

	// �f�v�X�X�e���V���o�b�t�@�̃��Z�b�g
	glFramebufferTexture2DEXT( GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT,   GL_TEXTURE_2D, 0, 0 );
	glFramebufferTexture2DEXT( GL_FRAMEBUFFER_EXT, GL_STENCIL_ATTACHMENT_EXT, GL_TEXTURE_2D, 0, 0 );

	// �����_�[�^�[�Q�b�g�̃��Z�b�g
	GLint maxDrawBuffer;
	glGetIntegerv( GL_MAX_DRAW_BUFFERS, &maxDrawBuffer );
	for( GLint i=0; i<maxDrawBuffer; ++i ){
		glFramebufferTexture2DEXT( GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT+i, GL_TEXTURE_2D, 0, 0 );
	}

	// �`��E�ǂݍ��݃o�b�t�@�̃��Z�b�g
	glDrawBuffer( GL_COLOR_ATTACHMENT0_EXT );
	glReadBuffer( GL_COLOR_ATTACHMENT0_EXT );

	// �t���[���o�b�t�@�I�u�W�F�N�g�����Z�b�g����
	glBindFramebufferEXT( GL_FRAMEBUFFER_EXT, 0 );
}



/*=========================================================================*/
/**
 * @brief �����_���[���t���b�V��
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void RendererGL::flush()
{
	glFlush();
}



/*=========================================================================*/
/**
 * @brief �����_���[�̏�Ԃ��N���A
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void RendererGL::clearState()
{
	resetRenderTargets();

	initialize();
}



/*=========================================================================*/
/**
 * @brief �C���f�b�N�X�^�C�v�̕ϊ�
 * 
 * @param[in] format �ϊ�����C���f�b�N�X�^�C�v�t���O.
 * @return �ϊ���̃C���f�b�N�X�t�H�[�}�b�g�\����.
 */
const RendererGL::IndexFormat& RendererGL::toIndexFormat( IndexType format )
{
	static const RendererGL::IndexFormat indexFormats[] = {
		{ GL_UNSIGNED_SHORT,	sizeof( GLushort )	},
		{ GL_UNSIGNED_INT,		sizeof( GLuint )	}
	};

	return indexFormats[ format ];
}



/*=========================================================================*/
/**
 * @brief �v���~�e�B�u�^�C�v�̕ϊ�
 * 
 * @param[in] primitive �ϊ�����v���~�e�B�u�^�C�v�t���O.
 * @return �ϊ����OpenGL�v���~�e�B�u�t���O.
 */
GLenum RendererGL::toPrimitiveMode( PrimitiveType primitive )
{
	static const GLenum primitiveModels[] = {
		GL_POINTS,			// PRIMITIVE_TYPE_POINTLIST		 = 0
		GL_LINES,			// PRIMITIVE_TYPE_LINELIST		 = 1
		GL_LINE_STRIP,		// PRIMITIVE_TYPE_LINESTRIP		 = 2
		GL_TRIANGLES,		// PRIMITIVE_TYPE_TRIGNALE_LIST	 = 3
		GL_TRIANGLE_STRIP	// PRIMITIVE_TYPE_TRIANGLE_STRIP = 4
	};
	
	return primitiveModels[ primitive ];
}



/*===== EOF ==================================================================*/