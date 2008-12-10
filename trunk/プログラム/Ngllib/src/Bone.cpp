/*******************************************************************************/
/**
 * @file Bone.cpp.
 * 
 * @brief �{�[�����N���X�\�[�X�t�@�C��.
 *
 * @date 2008/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Bone.h"
#include	<cassert>

using namespace Ngl;

/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
Bone::Bone():
	boneID_( 0 ),
	parentBoneID_( 0 ),
	parent_( 0 ),
	sibling_( 0 ),
	child_( 0 )
{
	// ���[�J���̍��W�ϊ��s���P�ʍs��ɂ���
	matBoneOffset_.setIdentitiy();
}



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
void Bone::create( unsigned int ID, unsigned int parentID, const Vector3& parentOffset, const Matrix4& matOffset )
{
	boneID_				= ID;
	parentBoneID_		= parentID;
	parentBoneOffset_	= parentOffset;
	matBoneOffset_		= matOffset;
}


	
/*=========================================================================*/
/**
 * @brief �e�{�[����ݒ肷��
 * 
 * @param[in] parent �e�{�[���̃|�C���^.
 * @return �Ȃ�.
 */
void Bone::setParent( IBone* parent )
{
	parent_ = parent;

	// �Z��{�[����ݒ肷��
	sibling_ = parent->child();
}


	
/*=========================================================================*/
/**
 * @brief �q�{�[����ݒ肷��
 * 
 * @param[in] child �q�{�[���̃|�C���^.
 * @return �Ȃ�.
 */
void Bone::setChild( IBone* child )
{
	child_ = child;
}
	
	

/*===========================================================================*/
/**
 * @brief �{�[���̕ϊ��s��̌v�Z���s��
 * 
 * @param[out] outMatrices �ϊ���̒��_�z��.
 * @param[in] parentMatrix �e�̕ϊ��s��ւ̃|�C���^,
 * @param[in] animMatrices �A�j���[�V�����p�ϊ��s��.
 * @return �Ȃ�.
 */
void Bone::calculateTransformMatrices( Matrix4* outMatrices, const Matrix4* parentMatrix, const Matrix4* animMatrices )
{
	// �ϊ���̍s����擾����
	Matrix4* outMatrix = &outMatrices[ boneID_ ];
	
	// �s�������������
	outMatrix->setIdentitiy();

	// �e�̍s�񂪐ݒ肳��Ă��邩
	if( parentMatrix != 0 ){
		// �A�j���[�V�����ϊ��s�񂪐ݒ肳��Ă��邩
		if( animMatrices != 0 ){
			// �A�j���[�V�����ϊ��s��̎擾
			*outMatrix = animMatrices[ boneID_ ];
		}

		// �e����̑��΍��W�����f�����O�ϊ��s��ɉ��Z����
		outMatrix->m[3][0] += parentBoneOffset_.x;
		outMatrix->m[3][1] += parentBoneOffset_.y;
		outMatrix->m[3][2] += parentBoneOffset_.z;

		// �e�̕ϊ��s��ƍ���
		*outMatrix *= *parentMatrix;
	}

	// �Z��������Ă��邩
	if( sibling_ != 0 ){
		// �Z����v�Z������
		sibling_->calculateTransformMatrices( outMatrices, parentMatrix, animMatrices );
	}

	// �q���������Ă��邩
	if( child_ != 0 ){
		child_->calculateTransformMatrices( outMatrices, outMatrix, animMatrices );
	}
}



/*=========================================================================*/
/**
 * @brief �{�[�������W�ϊ�����
 * 
 * @param[in] matrix �ϊ��s��.
 * @return �Ȃ�.
 */
void Bone::transform(const Matrix4 &matrix)
{
	// �Z�킪���邩
	if( sibling_ != 0 ){
		sibling_->transform( matrix );
	}

	// �q�������邩
	if( child_ != 0 ){
		child_->transform( matrix );
	}
}



/*=========================================================================*/
/**
 * @brief �{�[��ID���擾����
 * 
 * @param[in] �Ȃ�.
 * @return �{�[��ID
 */
unsigned int Bone::getBoneID() const
{
	return boneID_;
}


/*=========================================================================*/
/**
 * @brief �e�{�[��ID���擾����
 * 
 * @param[in] �Ȃ�.
 * @return �e�{�[��ID
 */
unsigned int Bone::getParentBoneID() const
{
	return parentBoneID_;
}


/*=========================================================================*/
/**
 * @brief �e�{�[������̑��΋������擾����
 * 
 * @param[in] �Ȃ�.
 * @return �e�{�[���Ƃ̑��΋���.
 */
const Ngl::Vector3& Bone::getParentBoneOffset() const
{
	return parentBoneOffset_;
}


/*=========================================================================*/
/**
 * @brief ���[�J�����W�ϊ��s����擾����
 * 
 * @param[in] �Ȃ�.
 * @return ���[�J�����W�ϊ��s��.
 */
const Ngl::Matrix4& Bone::getMatBoneOffset() const
{
	return matBoneOffset_;
}


/*=========================================================================*/
/**
 * @brief �Z��{�[�����擾����
 * 
 * @param[in] �Ȃ�.
 * @return �Z��{�[��.
 */
IBone* Bone::sibling()
{
	return sibling_;
}



/*=========================================================================*/
/**
 * @brief �e�{�[�����擾����
 * 
 * @param[in] �Ȃ�.
 * @return �e�{�[��.
 */
IBone* Bone::parent()
{
	return parent_;
}



/*=========================================================================*/
/**
 * @brief �q�{�[�����擾����
 * 
 * @param[in] �Ȃ�.
 * @return �q�{�[��.
 */
IBone* Bone::child()
{
	return child_;
}

	
	
/*========= EOF =============================================================*/