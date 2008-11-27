/*******************************************************************************/
/**
 * @file VertexDeclarationGL.h.
 * 
 * @brief OpenGL ���_�錾�f�[�^�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_OPENGL_VERTEXDECLARATIONGL_H_
#define _NGL_OPENGL_VERTEXDECLARATIONGL_H_

#include	"Ngl/IVertexDeclaration.h"
#include	"Ngl/VertexStreamDesc.h"
#include	"OpenGL.h"
#include	<vector>

namespace Ngl{


namespace OpenGL{


/**
 * @class VertexDeclarationGL.
 * @brief OpenGL ���_�錾�f�[�^�N���X.
 */
class VertexDeclarationGL : public IVertexDeclaration
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] desc ���_�錾�f�[�^�L�q�q�̔z��.
	 * @param[in] numDesc ���_�錾�f�[�^�L�q�q�z��̗v�f��.
	 */
	VertexDeclarationGL( const VertexDeclarationDesc desc[], unsigned int numDesc );

	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~VertexDeclarationGL();


	/*=========================================================================*/
	/**
	 * @brief ���_�錾�f�[�^�̌����擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return ��.
	 */
	virtual unsigned int size() const;

	
	/*=========================================================================*/
	/**
	 * @brief �L�q�q���擾
	 * 
	 * @param[in] index �擾����L�q�q�̃C���f�b�N�X�ԍ�.
	 * @return �L�q�q.
	 */
	virtual const VertexDeclarationDesc& desc( unsigned int index ) const;

	
	/*=========================================================================*/
	/**
	 * @brief ���_�o�b�t�@�X�g���[���̐ݒ�
	 * 
	 * @param[in] streams �ݒ肷�钸�_�X�g���[���L�q�q�z��.
	 * @param[in] start �ݒ�J�n�z��ʒu.
	 * @return �Ȃ�.
	 */
	void setVertexStream( const VertexStreamDesc streams[], unsigned int start=0 );

	
	/*=========================================================================*/
	/**
	 * @brief ���_�o�b�t�@�X�g���[���̃��Z�b�g
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void resetVertexStream();

private:

	/**
	 * @struct VertexFormat.
	 * @brief OpenGL ���_�t�H�[�}�b�g�\����.
	 */
	struct VertexFormat
	{
		GLuint		type;		/**< ���_�^�C�v			*/
		GLint		size;		/**< ���_�f�[�^�T�C�Y	*/
		GLboolean	normalized;	/**< ���K���f�[�^��		*/
	};

	/**
	 * @struct Element.
	 * @brief OpenGL ���_�錾�v�f�\����.
	 */
	struct Element
	{
		GLuint			attrib;	/**< ����			*/
		VertexFormat	format;	/**< �t�H�[�}�b�g	*/
		GLuint			offset;	/**< �I�t�Z�b�g�l	*/
		unsigned int	stream;	/**< �X�g���[���ԍ�	*/
	};

private:

	/*=========================================================================*/
	/**
	 * @brief ���_�o�b�t�@�̐ݒ�
	 * 
	 * @param[in] element ���_�錾�v�f�\����.
	 * @param[in] stream ���_�X�g���[���L�q�q.
	 * @param[in] start �J�n�ʒu.
	 * @return �Ȃ�.
	 */
	void setVertexBuffer( const Element& element, const VertexStreamDesc& stream, unsigned int start );

	
	/*=========================================================================*/
	/**
	 * @brief ���_�錾�L�q�q��ϊ�
	 * 
	 * @param[in] desc �ϊ����钸�_�錾�L�q�q�\����.
	 * @return �ϊ���̒��_�錾�v�f�\����.
	 */
	static Element toElement( const VertexDeclarationDesc& desc );

	
	/*=========================================================================*/
	/**
	 * @brief ���_�Z�}���e�B�b�N��ϊ�
	 * 
	 * @param[in] semantic �ϊ����钸�_�Z�}���e�B�b�N�t���O.
	 * @return �ϊ����OpenGL���_�Z�}���e�B�b�N.
	 */
	static GLuint toAttrib( VertexSemantic semantic );

	
	/*=========================================================================*/
	/**
	 * @brief ���_�^�C�v��ϊ�
	 * 
	 * @param[in] type �ϊ����钸�_�^�C�v�t���O.
	 * @return �ϊ���̒��_�t�H�[�}�b�g�\����.
	 */
	static const VertexFormat& toVertexFormat( VertexType type );

private:

	/** �L�q�q�z��^ */
	typedef std::vector< VertexDeclarationDesc >	VertexDeclarationDescArray;

	/** ���_���C�A�E�g�z��^ */
	typedef std::vector< Element >					VertexDeclarationArray;

private:

	/** �L�q�q�z�� */
	VertexDeclarationDescArray	desc_;

	/** ���_���C�A�E�g�z�� */
	VertexDeclarationArray		elements_;
};

} // namespace OpenGL

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/