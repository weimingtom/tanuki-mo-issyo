/*******************************************************************************/
/**
 * @file RendererGL.h.
 * 
 * @brief OpenGL �����_���[�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_OPENGL_RENDERERGL_H_
#define _NGL_OPENGL_RENDERERGL_H_

#include	"Ngl/IRenderer.h"
#include	"OpenGL.h"

namespace Ngl{



namespace OpenGL{


// �o�b�t�@�N���X
class BufferGL;

// ���_�錾�N���X
class VertexDeclarationGL;


/**
 * @class RendererGL.
 * @brief OpenGL �����_���[�N���X.
 */
class RendererGL : public IRenderer
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	RendererGL();

	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~RendererGL();

	
	/*=========================================================================*/
	/**
	 * @brief ����������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void initialize();

	
	/*=========================================================================*/
	/**
	 * @brief �r���[�|�[�g�̐ݒ�
	 * 
	 * @param[in] desc �r���[�|�[�g�L�q�q.
	 * @return �Ȃ�.
	 */
	virtual void setViewport( const ViewportDesc& desc );

	
	/*=========================================================================*/
	/**
	 * @brief �r���[�|�[�g�̎擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �r���[�|�[�g�L�q�q.
	 */
	virtual const ViewportDesc& getViewport() const;

	
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
	virtual void clearColorBuffer( float r=0.0f, float g=0.0f, float b=0.0f, float a=0.0f );

	
	/*=========================================================================*/
	/**
	 * @brief �f�v�X�X�e���V���o�b�t�@������
	 * 
	 * @param[in] depth �f�v�X�o�b�t�@���������邩.
	 * @param[in] stencil �X�e���V���o�b�t�@���������邩.
	 * @return �Ȃ�.
	 */
	virtual void clearDepthStencilBuffer( bool depth=true, bool stencil=false );

	
	/*=========================================================================*/
	/**
	 * @brief �o�b�t�@���쐬
	 * 
	 * @param[in] desc �o�b�t�@�L�q�q.
	 * @param[in] data �o�b�t�@�f�[�^.
	 * @return �쐬�����o�b�t�@�C���^�[�t�F�[�X�̃|�C���^.
	 */
	virtual IBuffer* createBuffer( const BufferDesc& desc, const void* data=0 );

	
	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`�����쐬
	 * 
	 * @param[in] desc �e�N�X�`���L�q�q.
	 * @param[in] data �e�N�X�`���f�[�^.
	 * @return �쐬�����e�N�X�`���C���^�[�t�F�[�X�̃|�C���^.
	 */
	virtual ITexture* createTexture( const TextureDesc& desc, const void* data=0 );

	
	/*=========================================================================*/
	/**
	 * @brief ���_�錾���쐬
	 * 
	 * @param[in] desc ���_�錾�L�q�q�̔z��.
	 * @param[in] numDesc ���_�錾�L�q�q�z��̗v�f��.
	 * @param[in] inputSignature ���̓V�O�l�`���L�q�q.
	 * @return �쐬�������_�錾�C���^�[�t�F�[�X�̃|�C���^.
	 */
	virtual IVertexDeclaration* createVertexDeclaration( const VertexDeclarationDesc desc[], unsigned int numDesc, const InputSignatureDesc& inputSignature );

	
	/*=========================================================================*/
	/**
	 * @brief �G�t�F�N�g�̍쐬
	 * 
	 * @param[in] fileName �G�t�F�N�g�t�@�C����.
	 * @return �쐬�����G�t�F�N�g�C���^�[�t�F�[�X�̃|�C���^.
	 */
	virtual IEffect* createEffect( const char* fileName );

	
	/*=========================================================================*/
	/**
	 * @brief ���_�錾�f�[�^��ݒ�
	 * 
	 * @param[in] layout �ݒ肷�钸�_�錾�f�[�^�̃|�C���^.
	 * @return �Ȃ�.
	 */
	virtual void setVertexDeclaration( IVertexDeclaration* layout );

	
	/*=========================================================================*/
	/**
	 * @brief �o�b�t�@��ݒ�
	 * 
	 * @param[in] stream ���_�X�g���[���L�q�q�z��.
	 * @param[in] numStream ���_�X�g���[���L�q�q�z��̗v�f��.
	 * @param[in] offset �I�t�Z�b�g�l.
	 * @return �Ȃ�.
	 */
	virtual void setVertexBuffer( const VertexStreamDesc stream[], unsigned int numStream=1, unsigned int offset=0 );

	
	/*=========================================================================*/
	/**
	 * @brief �C���f�b�N�X�o�b�t�@��ݒ�
	 * 
	 * @param[in] buffer �C���f�b�N�X�o�b�t�@�̃|�C���^.
	 * @param[in] type ���_�^�C�v.
	 * @param[in] offset �I�t�Z�b�g�l.
	 * @return �Ȃ�.
	 */
	virtual void setIndexBuffer( IBuffer* buffer, IndexType type, unsigned int offset=0 );

	
	/*=========================================================================*/
	/**
	 * @brief �~�b�v�}�b�v�̍쐬
	 * 
	 * @param[in] texture �~�b�v�}�b�v���쐬����e�N�X�`���̃|�C���^.
	 * @return �Ȃ�.
	 */
	virtual void generateMipmap( ITexture* texture );

	
	/*=========================================================================*/
	/**
	 * @brief �`�悷��v���~�e�B�u��ݒ�
	 * 
	 * @param[in] primitive �v���~�e�B�u�^�C�v.
	 * @return �Ȃ�.
	 */
	virtual void setPrimitive( PrimitiveType primitive );

	
	/*=========================================================================*/
	/**
	 * @brief ���_�o�b�t�@��`��
	 * 
	 * @param[in] numVertex �`�悷�钸�_��.
	 * @param[in] start �J�n���_�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void draw( unsigned int numVertex, unsigned int start=0 );

	
	/*=========================================================================*/
	/**
	 * @brief �C���f�b�N�X�o�b�t�@���g�p���ĕ`�悷��
	 * 
	 * @param[in] numIndices �C���f�b�N�X��.
	 * @param[in] startIndex �J�n�C���f�b�N�X�ԍ�.
	 * @param[in] startVertex �J�n���_�ԍ�
	 * @return �Ȃ�.
	 */
	virtual void drawIndexed( unsigned int numIndices, unsigned int startIndex=0, unsigned int startVertex=0 );

	
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
	virtual void setRenderTargets( ITexture* targets[], unsigned int numTargets, ITexture* depthStencil, unsigned int index=0 );

	
	/*=========================================================================*/
	/**
	 * @brief �����_�[�^�[�Q�b�g�����Z�b�g
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void resetRenderTargets();


	/*=========================================================================*/
	/**
	 * @brief �����_���[���t���b�V��
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void flush();

	
	/*=========================================================================*/
	/**
	 * @brief �����_���[�̏�Ԃ��N���A
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void clearState();

private:

	/**
	 * @struct IndexFormat.
	 * @brief OpenGL �C���f�b�N�X�o�b�t�@�t�H�[�}�b�g�\����.
	 */
	struct IndexFormat
	{
		GLenum	type;	/**< �C���f�b�N�X�^�C�v	*/
		GLenum	size;	/**< �f�[�^�T�C�Y		*/
	};

private:

	/*=========================================================================*/
	/**
	 * @brief �C���f�b�N�X�^�C�v�̕ϊ�
	 * 
	 * @param[in] format �ϊ�����C���f�b�N�X�^�C�v�t���O.
	 * @return �ϊ���̃C���f�b�N�X�t�H�[�}�b�g�\����.
	 */
	static const IndexFormat& toIndexFormat( IndexType format );

	
	/*=========================================================================*/
	/**
	 * @brief �v���~�e�B�u�^�C�v�̕ϊ�
	 * 
	 * @param[in] primitive �ϊ�����v���~�e�B�u�^�C�v�t���O.
	 * @return �ϊ����OpenGL�v���~�e�B�u�t���O.
	 */
	static GLenum toPrimitiveMode( PrimitiveType primitive );

private:

	/** �����_�����O�^�[�Q�b�g�̍ő吔 */
	static const unsigned int RENDER_TARGET_MAX	= 8;

	/** ���_�o�b�t�@�X�g���[���̍ő吔 */
	static const unsigned int VERTEX_STREAM_MAX	= 16;

private:

	/** �r���[�|�[�g */
	ViewportDesc			viewport_;

	/** ���_�o�b�t�@�X�g���[�� */
	VertexStreamDesc		vertexStream_[ VERTEX_STREAM_MAX ];

	/** ���_�錾 */
	VertexDeclarationGL*		vertexDeclaration_;

	/** �C���f�b�N�X�o�b�t�@ */
	BufferGL*				indexBuffer_;

	/** �C���f�b�N�X�o�b�t�@�t�H�[�}�b�g */
	IndexFormat				indexFormat_;

	/** �C���f�b�N�X�o�b�t�@�I�t�Z�b�g */
	unsigned int			indexOffset_;

	/** �v���~�e�B�u���[�h */
	GLenum					primitiveMode_;

	/** �t���[���o�b�t�@�I�u�W�F�N�g */
	GLuint					framebufferObject_;

};

} // namespace OpenGL

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/