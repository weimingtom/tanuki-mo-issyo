/*******************************************************************************/
/**
 * @file IVertexDeclaration.h.
 * 
 * @brief ���_�錾�C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/02.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IVERTEX_DECLARATION_H_
#define _NGL_IVERTEX_DECLARATION_H_

#include	"VertexDeclarationDesc.h"

namespace Ngl{


/**
 * @interface IVertexDeclaration.
 * @brief ���_�錾�C���^�[�t�F�[�X.
 */
class IVertexDeclaration
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IVertexDeclaration(){}

	
	/*=========================================================================*/
	/**
	 * @brief ���_�錾�f�[�^�̌����擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return ��.
	 */
	virtual unsigned int size() const = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �L�q�q���擾
	 * 
	 * @param[in] index �擾����L�q�q�̃C���f�b�N�X�ԍ�.
	 * @return �L�q�q.
	 */
	virtual const VertexDeclarationDesc& desc( unsigned int index ) const = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/