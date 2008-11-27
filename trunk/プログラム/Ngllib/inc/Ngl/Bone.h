/*******************************************************************************/
/**
 * @file Bone.h.
 * 
 * @brief �{�[�����N���X�w�b�_�t�@�C��.
 *
 * @date 2008/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_BONE_H_
#define _NGL_BONE_H_

#include	"IBone.h"

namespace Ngl{


/**
 * @class Bone.
 * @brief �{�[�����N���X�D
 */
class Bone : public IBone
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	Bone();


	/*=========================================================================*/
	/**
	 * @brief �{�[������ݒ肷��
	 * 
	 * @param[in] ID �{�[���h�c.
	 * @param[in] parentID �e�{�[���h�c.
	 * @param[in] parentOffset �e�{�[������̑��΍��W.
	 * @param[in] matOffset ���[�J�����W�ϊ��s��.
	 * @return �Ȃ�.
	 */
	void create( unsigned int ID, unsigned int parentID, const Vector3& parentOffset, const Matrix4& matOffset );
	
public:
	
	/*=========================================================================*/
	/**
	 * @brief �e�{�[����ݒ肷��
	 * 
	 * @param[in] parent �e�{�[���̃|�C���^.
	 * @return �Ȃ�.
	 */
	virtual void setParent( IBone* parent );

	
	/*=========================================================================*/
	/**
	 * @brief �q�{�[����ݒ肷��
	 * 
	 * @param[in] child �q�{�[���̃|�C���^.
	 * @return �Ȃ�.
	 */
	virtual void setChild( IBone* child );


	/*=========================================================================*/
	/**
	 * @brief �{�[���̕ϊ��s��̌v�Z���s��
	 * 
	 * @param[out] outMatrices �ϊ���̒��_�z��.
	 * @param[in] parentMatrix �e�̕ϊ��s��ւ̃|�C���^.
	 * @param[in] animMatrices �A�j���[�V�����p�ϊ��s��.
	 * @return �Ȃ�.
	 */
	virtual void calculateTransformMatrices( Matrix4* outMatrices, const Matrix4* parentMatrix, const Matrix4* animMatrices );

	
	/*=========================================================================*/
	/**
	 * @brief �{�[�������W�ϊ�����
	 * 
	 * @param[in] matrix �ϊ��s��.
	 * @return �Ȃ�.
	 */
	virtual void transform( const Matrix4& matrix );
	
	
	/*=========================================================================*/
	/**
	 * @brief �{�[��ID���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �{�[��ID
	 */
	virtual unsigned int getBoneID() const;


	/*=========================================================================*/
	/**
	 * @brief �e�{�[��ID���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e�{�[��ID
	 */
	virtual unsigned int getParentBoneID() const;


	/*=========================================================================*/
	/**
	 * @brief �e�{�[������̑��΋������擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e�{�[���Ƃ̑��΋���.
	 */
	virtual const Ngl::Vector3& getParentBoneOffset() const;


	/*=========================================================================*/
	/**
	 * @brief ���[�J�����W�ϊ��s����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���[�J�����W�ϊ��s��.
	 */
	virtual const Ngl::Matrix4& getMatBoneOffset() const;
	
	
	/*=========================================================================*/
	/**
	 * @brief �e�{�[�����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e�{�[��.
	 */
	virtual IBone* parent();
	
	
	/*=========================================================================*/
	/**
	 * @brief �Z��{�[�����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Z��{�[��.
	 */
	virtual IBone* sibling();
	
	
	/*=========================================================================*/
	/**
	 * @brief �q�{�[�����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �q�{�[��.
	 */
	virtual IBone* child();

private:

	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^( �R�s�[�֎~ �j
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 * @return �Ȃ�.
	 */
	Bone( const Bone& other );


	/*=========================================================================*/
	/**
	 * @brief =���Z�q�I�[�o�[���[�h�i �R�s�[�֎~ �j
	 * 
	 * @param[in] other �������I�u�W�F�N�g.
	 * @return ������ʂ̃I�u�W�F�N�g.
	 */
	Bone& operator = ( const Bone& other );

private:

	/** �{�[��ID */
	unsigned int	boneID_;

	/** �e�{�[��ID */
	unsigned int	parentBoneID_;

	/** �e�{�[������̑��΍��W */
	Ngl::Vector3	parentBoneOffset_;

	/** ���[�J�����W�ϊ��s�� */
	Ngl::Matrix4	matBoneOffset_;

	/** �e�{�[���ւ̃|�C���^ */
	IBone*			parent_;

	/** �Z��{�[���ւ̃|�C���^ */
	IBone*			sibling_;

	/** �q�{�[���ւ̃|�C���^ */
	IBone*			child_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/