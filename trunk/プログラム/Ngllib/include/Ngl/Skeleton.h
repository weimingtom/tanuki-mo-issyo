/*******************************************************************************/
/**
 * @file Skeleton.h.
 * 
 * @brief �X�P���g�����N���X�w�b�_�t�@�C��.
 *
 * @date 2008/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_SKELTON_H_
#define _NGL_SKELTON_H_

#include	"Ngl/ISkeleton.h"
#include	<vector>

namespace Ngl{


/**
 * @class Skeleton.
 * @brief �X�P���g�����N���X�D
 */
class Skeleton : public ISkeleton
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	Skeleton();


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~Skeleton();
	
	
	/*=========================================================================*/
	/**
	 * @brief �{�[����ǉ�����
	 * 
	 * @warning �ǉ������{�[����Skeleton�N���X�ō폜����܂�.
	 *
	 * @param[in] bone �ǉ�����{�[��.
	 * @return �Ȃ�.
	 */
	void addBone( IBone* bone );
	
	
	/*=========================================================================*/
	/**
	 * @brief �{�[���̃����N������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void linkBone();

	
	/*=========================================================================*/
	/**
	 * @brief �X�P���g�����̉��
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void release();

public:

	/*=========================================================================*/
	/**
	 * @brief �p���ϊ��s������߂�
	 * 
	 * @param[out] outMatrices ���W�ϊ��s��̔z��.
	 * @param[in] parentMatrix �e�̕ϊ��s��ւ̃|�C���^.
	 * @param[in] animMatrices �A�j���[�V�����p�ϊ��s��z��.
	 * @return �Ȃ�.
	 */
	virtual void calculateOrientation( Matrix4* outMatrices, const Matrix4* parentMatrix, const Matrix4* animMatrices );

	
	/*=========================================================================*/
	/**
	 * @brief ���W�ϊ��s��̌v�Z���s��
	 * 
	 * @param[out] outMatrices ���W�ϊ��s��̔z��
	 * @param[in] orientMatrices �p���ϊ��s��.
	 * @return �Ȃ�.
	 */
	virtual void calculateTransform( Matrix4* outMatrices, Matrix4* orientMatrices );


	/*=========================================================================*/
	/**
	 * @brief �{�[�����擾����
	 * 
	 * @param[in] no �擾����{�[���ԍ�.
	 * @return �{�[���̃|�C���^.
	 */
	virtual IBone* getBones( unsigned int no );
	
	
	/*=========================================================================*/
	/**
	 * @brief �{�[���̐����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �{�[����.
	 */
	virtual unsigned int getNumBones() const;

private:

	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^( �R�s�[�֎~ �j
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 * @return �Ȃ�.
	 */
	Skeleton( const Skeleton& other );


	/*=========================================================================*/
	/**
	 * @brief =���Z�q�I�[�o�[���[�h�i �R�s�[�֎~ �j
	 * 
	 * @param[in] other �������I�u�W�F�N�g.
	 * @return ������ʂ̃I�u�W�F�N�g.
	 */
	Skeleton& operator = ( const Skeleton& other );
	

	/*=========================================================================*/
	/**
	 * @brief �e�{�[���Ǝq�{�[���������N����
	 * 
	 * @param[in] parent �e�{�[��.
	 * @param[in] child �q�{�[��.
	 * @return �Ȃ�.
	 */
	void addChild( IBone* parent, IBone* child );

private:

	/** �{�[�����z��^ */
	typedef std::vector< IBone* >	BoneArray;

private:

	/** �{�[���z��ւ̃|�C���^ */
	BoneArray		bones_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/