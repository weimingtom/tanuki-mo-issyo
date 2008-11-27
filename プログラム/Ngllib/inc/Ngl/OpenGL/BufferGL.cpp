/*******************************************************************************/
/**
 * @file BufferGL.cpp.
 * 
 * @brief OpenGL �o�b�t�@�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"BufferGL.h"
#include	<memory>

using namespace Ngl;
using namespace Ngl::OpenGL;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] desc �o�b�t�@�쐬�L�q�q.
 * @param[in] data �o�b�t�@�f�[�^.
 */
BufferGL::BufferGL( const BufferDesc& desc, const void* data ):
	desc_( desc ),
	target_( toTarget( desc.type ) ),
	usage_( toUsage( desc.usage ) )
{
	// �o�b�t�@�̍쐬
	glGenBuffersARB( 1, &buffer_ );
	glBindBufferARB( target_, buffer_ );
	glBufferDataARB( target_, desc_.size, data, usage_ );
	glBindBufferARB( target_, 0 );
}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
BufferGL::~BufferGL()
{
	// �o�b�t�@���폜
	glDeleteBuffersARB( 1, &buffer_ );
}



/*=========================================================================*/
/**
 * @brief �L�q�q���擾����
 * 
 * @param[in] �Ȃ�.
 * @return �o�b�t�@�L�q�q.
 */
const BufferDesc& BufferGL::desc() const
{
	return desc_;
}



/*=========================================================================*/
/**
 * @brief �o�b�t�@�f�[�^�̐ݒ�
 * 
 * @param[in] data �ݒ肷��f�[�^.
 * @return �Ȃ�.
 */
void BufferGL::setData( const void* data )
{
	glBindBufferARB( target_, buffer_ );
	void* buf = glMapBufferARB( target_, GL_WRITE_ONLY_ARB );
	std::memcpy( buf, data, desc_.size );
	glUnmapBufferARB( target_ );
	glBindBufferARB( target_, 0 );
}



/*=========================================================================*/
/**
 * @brief �o�b�t�@�f�[�^�̎擾
 * 
 * @param[out] data �o�b�t�@�f�[�^���i�[����f�[�^.
 * @return �Ȃ�.
 */
void BufferGL::getData( void* data ) const
{
	glBindBufferARB( target_, buffer_ );
	void* buf = glMapBufferARB( target_, GL_READ_ONLY_ARB );
	std::memcpy( data, buf, desc_.size );
	glUnmapBufferARB( target_ );
	glBindBufferARB( target_ , 0 );
}



/*=========================================================================*/
/**
 * @brief OepnGL�o�b�t�@�C���f�b�N�X�̎擾
 * 
 * @param[in] �Ȃ�.
 * @return OpenGL�o�b�t�@�C���f�b�N�X.
 */
GLuint BufferGL::buffer() const
{
	return buffer_;
}



/*=========================================================================*/
/**
 * @brief �o�b�t�@�^�C�v��ϊ�
 * 
 * @param[in] �ϊ�����o�b�t�@�^�C�v.
 * @return �ϊ�����OpenGL�o�b�t�@�^�C�v.
 */
GLenum BufferGL::toTarget( BufferType type )
{
	static const GLenum targets[] = {
		GL_ARRAY_BUFFER_ARB,		// BUFFER_TYPE_VERTEX	= 0
		GL_ELEMENT_ARRAY_BUFFER_ARB	// BUFFER_TYPE_INDEX	= 1
	};

	return targets[ type ];
}



/*=========================================================================*/
/**
 * @brief �o�b�t�@�̎g�p���@��ϊ�
 * 
 * @param[out] usage �ϊ�����o�b�t�@�̎g�p���@�t���O.
 * @return �ϊ�����OpenGL�o�b�t�@�g�p���@�t���O.
 */
GLenum BufferGL::toUsage( BufferUsage usage )
{
	static const GLenum usages[] = {
		GL_STREAM_DRAW,		// BUFFER_USAGE_DEFAULT		= 0
		GL_STATIC_DRAW,		// BUFFER_USAGE_IMMUTABLE	= 1
		GL_DYNAMIC_DRAW		// BUFFER_USAGE_DYNAMIC		= 2
	};

	return usages[ usage ];
}



/*===== EOF ==================================================================*/