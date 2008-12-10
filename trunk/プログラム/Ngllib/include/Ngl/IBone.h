/*******************************************************************************/
/**
 * @file IBone.h.
 * 
 * @brief �{�[�����C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/01.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IBONE_H_
#define _NGL_IBONE_H_

#include	"Ngl/Vector3.h"
#include	"Ngl/Matrix4.h"

namespace Ngl{


/**
 * @interface IBone
 * @brief �{�[�����C���^�[�t�F�[�X�D
 */
class IBone
{
public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IBone() {}


	/*=========================================================================*/
	/**
	 * @brief �e�{�[����ݒ肷��
	 * 
	 * @param[in] parent �e�{�[���̃|�C���^.
	 * @return �Ȃ�.
	 */
	virtual void setParent( IBone* parent ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �q�{�[����ݒ肷��
	 * 
	 * @param[in] child �q�{�[���̃|�C���^.
	 * @return �Ȃ�.
	 */
	virtual void setChild( IBone* child ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �{�[���̕ϊ��s��̌v�Z���s��
	 * 
	 * @param[out] outMatrices �ϊ���̒��_�z��.
	 * @param[in] parentMatrix �e�̕ϊ��s��ւ̃|�C���^.
	 * @param[in] animMatrices �A�j���[�V�����p�ϊ��s��.
	 * @return �Ȃ�.
	 */
	virtual void calculateTransformMatrices( Matrix4* outMatrices, const Matrix4* parentMatrix, const Matrix4* animMatrices ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �{�[�������W�ϊ�����
	 * 
	 * @param[in] matrix �ϊ��s��.
	 * @return �Ȃ�.
	 */
	virtual void transform( const Matrix4& matrix ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �{�[��ID���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �{�[��ID
	 */
	virtual unsigned int getBoneID() const = 0;


	/*=========================================================================*/
	/**
	 * @brief �e�{�[��ID���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e�{�[��ID
	 */
	virtual unsigned int getParentBoneID() const = 0;


	/*=========================================================================*/
	/**
	 * @brief �e�{�[������̑��΋������擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e�{�[���Ƃ̑��΋���.
	 */
	virtual const Ngl::Vector3& getParentBoneOffset() const = 0;


	/*=========================================================================*/
	/**
	 * @brief ���[�J�����W�ϊ��s����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���[�J�����W�ϊ��s��.
	 */
	virtual const Ngl::Matrix4& getMatBoneOffset() const = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �e�{�[�����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e�{�[��.
	 */
	virtual IBone* parent() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �Z��{�[�����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Z��{�[��.
	 */
	virtual IBone* sibling() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �q�{�[�����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �q�{�[��.
	 */
	virtual IBone* child() = 0;

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/