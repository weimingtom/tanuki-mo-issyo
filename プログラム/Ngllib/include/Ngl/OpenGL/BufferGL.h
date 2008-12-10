/*******************************************************************************/
/**
 * @file BufferGL.h.
 * 
 * @brief OpenGL �o�b�t�@�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_OPENGL_BUFFERGL_H_
#define _NGL_OPENGL_BUFFERGL_H_

#include	"Ngl/IBuffer.h"
#include	"OpenGL.h"

namespace Ngl{


namespace OpenGL{


/**
 * @class BufferGL�D
 * @brief OpenGL �o�b�t�@�N���X.
 */
class BufferGL : public IBuffer
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] desc �o�b�t�@�쐬�L�q�q.
	 * @param[in] data �o�b�t�@�f�[�^.
	 */
	BufferGL( const BufferDesc& desc, const void* data=0 );

	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~BufferGL();

	
	/*=========================================================================*/
	/**
	 * @brief �L�q�q���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �o�b�t�@�L�q�q.
	 */
	const BufferDesc& desc() const;

	
	/*=========================================================================*/
	/**
	 * @brief �o�b�t�@�f�[�^�̐ݒ�
	 * 
	 * @param[in] data �ݒ肷��f�[�^.
	 * @return �Ȃ�.
	 */
	void setData( const void* data );

	
	/*=========================================================================*/
	/**
	 * @brief �o�b�t�@�f�[�^�̎擾
	 * 
	 * @param[out] data �o�b�t�@�f�[�^���i�[����f�[�^.
	 * @return �Ȃ�.
	 */
	void getData( void* data ) const;

	
	/*=========================================================================*/
	/**
	 * @brief OepnGL�o�b�t�@�C���f�b�N�X�̎擾
	 * 
	 * @param[out] �Ȃ�.
	 * @return OpenGL�o�b�t�@�C���f�b�N�X.
	 */
	GLuint buffer() const;

private:

	/*=========================================================================*/
	/**
	 * @brief �o�b�t�@�^�C�v��ϊ�
	 * 
	 * @param[in] type �ϊ�����o�b�t�@�^�C�v.
	 * @return �ϊ�����OpenGL�o�b�t�@�^�C�v.
	 */
	static GLenum toTarget( BufferType type );

	
	/*=========================================================================*/
	/**
	 * @brief �o�b�t�@�̎g�p���@��ϊ�
	 * 
	 * @param[in] usage �ϊ�����o�b�t�@�̎g�p���@�t���O.
	 * @return �ϊ�����OpenGL�o�b�t�@�g�p���@�t���O.
	 */
	static GLenum toUsage( BufferUsage usage );

private:

	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^( �R�s�[�֎~ )
	 * 
	 * @param[in] other �������I�u�W�F�N�g.
	 */
	BufferGL( const BufferGL& other );
	
	
	/*=========================================================================*/
	/**
	 * @brief = ���Z�q�I�[�o�[���[�h( �R�s�[�֎~ )
	 * 
	 * @param[in] other �������I�u�W�F�N�g.
	 * @return ������ʂ̃I�u�W�F�N�g.
	 */
	BufferGL& operator = ( const BufferGL& other );

private:

	/** �L�q�q */
	BufferDesc	desc_;

	/** �o�b�t�@�I�u�W�F�N�g */
	GLuint		buffer_;

	/** �^�[�Q�b�g */
	GLenum		target_;

	/** �g�p���@ */
	GLenum		usage_;

};

} // namespace OpenGL

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/