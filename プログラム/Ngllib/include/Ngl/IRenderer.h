/*******************************************************************************/
/**
 * @file IRenderer.h.
 * 
 * @brief �����_���[�C���^�[�t�F�[�X��`.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IRENDERER_H_
#define _NGL_IRENDERER_H_

#include	"IBuffer.h"
#include	"ITexture.h"
#include	"IVertexDeclaration.h"
#include	"IEffect.h"
#include	"VertexStreamDesc.h"
#include	"ViewportDesc.h"

namespace Ngl{


/**
 * @enum PrimitiveType.
 * @brief �v���~�e�B�u�^�C�v�񋓌^.
 */
enum PrimitiveType
{
	PRIMITIVE_TYPE_POINT_LIST		= 0,	/** �_���X�g			*/
	PRIMITIVE_TYPE_LINE_LIST		= 1,	/** �������X�g			*/
	PRIMITIVE_TYPE_LINE_STRIP		= 2,	/** �����X�g���b�v		*/
	PRIMITIVE_TYPE_TRIANGLE_LIST	= 3,	/** �O�p�`���X�g		*/
	PRIMITIVE_TYPE_TRIANGLE_STRIP	= 4		/** �O�p�`�X�g���b�v	*/
};


/**
 * @enum IndexType
 * @brief ���_�C���f�b�N�X�^�C�v�񋓌^.
 */
enum IndexType{
	INDEX_TYPE_USHORT	= 0,	/**< unsigned short�^	*/
	INDEX_TYPE_UINT		= 1		/**< unsigned int�^		*/
};


/**
 * @interface IRenderer.
 * @brief �����_���[�C���^�[�t�F�[�X
 */
class IRenderer
{
public:
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IRenderer(){}

	
	/*=========================================================================*/
	/**
	 * @brief ����������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void initialize() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �r���[�|�[�g�̐ݒ�
	 * 
	 * @param[in] desc �r���[�|�[�g�L�q�q.
	 * @return �Ȃ�.
	 */
	virtual void setViewport( const ViewportDesc& desc ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �r���[�|�[�g�̎擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �r���[�|�[�g�L�q�q.
	 */
	virtual const ViewportDesc& getViewport() const = 0;

	
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
	virtual void clearColorBuffer( float r=0.0f, float g=0.0f, float b=0.0f, float a=0.0f ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �f�v�X�X�e���V���o�b�t�@������
	 * 
	 * @param[in] depth �f�v�X�o�b�t�@���������邩.
	 * @param[in] stencil �X�e���V���o�b�t�@���������邩.
	 * @return �Ȃ�.
	 */
	virtual void clearDepthStencilBuffer( bool depth=true, bool stencil=false ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �o�b�t�@���쐬
	 * 
	 * @param[in] desc �o�b�t�@�L�q�q.
	 * @param[in] data �o�b�t�@�f�[�^.
	 * @return �쐬�����o�b�t�@�C���^�[�t�F�[�X�̃|�C���^.
	 */
	virtual IBuffer* createBuffer( const BufferDesc& desc, const void* data=0 ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`�����쐬
	 * 
	 * @param[in] desc �e�N�X�`���L�q�q.
	 * @param[in] data �e�N�X�`���f�[�^.
	 * @return �쐬�����e�N�X�`���C���^�[�t�F�[�X�̃|�C���^.
	 */
	virtual ITexture* createTexture( const TextureDesc& desc, const void* data=0 ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief ���_�錾���쐬
	 * 
	 * @param[in] desc ���_�錾�L�q�q�̔z��.
	 * @param[in] numDesc ���_�錾�L�q�q�z��̗v�f��.
	 * @param[in] inputSignature ���̓V�O�l�`���L�q�q.
	 * @return �쐬�������_�錾�C���^�[�t�F�[�X�̃|�C���^.
	 */
	virtual IVertexDeclaration* createVertexDeclaration( const VertexDeclarationDesc desc[], unsigned int numDesc, const InputSignatureDesc& inputSignature ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �G�t�F�N�g�̍쐬
	 * 
	 * @param[in] fileName �G�t�F�N�g�t�@�C����.
	 * @return �쐬�����G�t�F�N�g�C���^�[�t�F�[�X�̃|�C���^.
	 */
	virtual IEffect* createEffect( const char* fileName ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief ���_�錾�f�[�^��ݒ�
	 * 
	 * @param[in] layout �ݒ肷�钸�_�錾�f�[�^�̃|�C���^.
	 * @return �Ȃ�.
	 */
	virtual void setVertexDeclaration( IVertexDeclaration* layout ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �o�b�t�@��ݒ�
	 * 
	 * @param[in] stream ���_�X�g���[���L�q�q�z��.
	 * @param[in] numStream ���_�X�g���[���L�q�q�z��̗v�f��.
	 * @param[in] offset �I�t�Z�b�g�l.
	 * @return �Ȃ�.
	 */
	virtual void setVertexBuffer( const VertexStreamDesc stream[], unsigned int numStream=1, unsigned int offset=0 ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �C���f�b�N�X�o�b�t�@��ݒ�
	 * 
	 * @param[in] buffer �C���f�b�N�X�o�b�t�@�̃|�C���^.
	 * @param[in] type ���_�^�C�v.
	 * @param[in] offset �I�t�Z�b�g�l.
	 * @return �Ȃ�.
	 */
	virtual void setIndexBuffer( IBuffer* buffer, IndexType type, unsigned int offset=0 ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �~�b�v�}�b�v�̍쐬
	 * 
	 * @param[in] texture �~�b�v�}�b�v���쐬����e�N�X�`���̃|�C���^.
	 * @return �Ȃ�.
	 */
	virtual void generateMipmap( ITexture* texture ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �`�悷��v���~�e�B�u��ݒ�
	 * 
	 * @param[in] primitiveType �v���~�e�B�u�^�C�v.
	 * @return �Ȃ�.
	 */
	virtual void setPrimitive( PrimitiveType primitiveType ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief ���_�o�b�t�@��`��
	 * 
	 * @param[in] numVertex �`�悷�钸�_��.
	 * @param[in] start �J�n���_�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void draw( unsigned int numVertex, unsigned int start=0 ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �C���f�b�N�X�o�b�t�@���g�p���ĕ`�悷��
	 * 
	 * @param[in] numIndices �C���f�b�N�X��.
	 * @param[in] startIndex �J�n�C���f�b�N�X�ԍ�.
	 * @param[in] startVertex �J�n���_�ԍ�
	 * @return �Ȃ�.
	 */
	virtual void drawIndexed( unsigned int numIndices, unsigned int startIndex=0, unsigned int startVertex=0 ) = 0;

	
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
	virtual void setRenderTargets( ITexture* targets[], unsigned int numTargets, ITexture* depthStencil, unsigned int index=0 ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �����_�[�^�[�Q�b�g�����Z�b�g
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void resetRenderTargets() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �����_���[���t���b�V��
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void flush() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �����_���[�̏�Ԃ��N���A
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void clearState() = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/