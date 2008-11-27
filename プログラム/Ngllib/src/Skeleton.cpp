/*******************************************************************************/
/**
 * @file Skeleton.cpp.
 * 
 * @brief �X�P���g�����N���X�\�[�X�t�@�C��.
 *
 * @date 2008/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Skeleton.h"
#include	"Ngl/Bone.h"
#include	<cassert>

using namespace Ngl;

/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
Skeleton::Skeleton()
{}



/*===========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
Skeleton::~Skeleton()
{
	// �{�[�����������
	release();
}

	
	
/*=========================================================================*/
/**
 * @brief �{�[����ǉ�����
 * 
 * @warning �ǉ������{�[����Skeleton�N���X�ō폜����܂�.
 *
 * @param[in] bone �ǉ�����{�[��.
 * @return �Ȃ�.
 */
void Skeleton::addBone( IBone* bone )
{
	bones_.push_back( bone );
}

	
	
/*===========================================================================*/
/**
 * @brief �{�[���̃����N������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void Skeleton::linkBone()
{
	for( unsigned int i=0; i<bones_.size(); i++ ){
		// �e�{�[�����擾����
		IBone* tmpParent = bones_[i];
		for( unsigned int j=1; j<bones_.size(); j++ ){
			// �q�{�[�����擾����
			IBone* tmpChild = bones_[j];

			// �e�{�[����ID�������Ă���q�{�[����
			if( tmpParent->getBoneID() == tmpChild->getParentBoneID() ){
				// �e�{�[���Ɏq�{�[���������N������
				addChild( tmpParent, tmpChild );
			}
		}
	}
}



/*===========================================================================*/
/**
 * @brief �X�P���g�����̉��
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void Skeleton::release()
{
	BoneArray::iterator itor = bones_.begin();
	while( itor != bones_.end() ){
		delete *itor;
		itor = bones_.erase( itor );
	}
}



/*===========================================================================*/
/**
 * @brief �p���ϊ��s������߂�
 * 
 * @param[out] outMatrices ���W�ϊ��s��̔z��.
 * @param[in] parentMatrix �e�̕ϊ��s��ւ̃|�C���^.
 * @param[in] animMatrices �A�j���[�V�����p�ϊ��s��z��.
 * @return �Ȃ�.
 */
void Skeleton::calculateOrientation( Matrix4* outMatrices, const Matrix4* parentMatrix, const Matrix4* animMatrices )
{
	// �e�{�[���̍��W�ϊ����s��
	bones_[0]->calculateTransformMatrices( outMatrices, parentMatrix, animMatrices );
}



/*===========================================================================*/
/**
 * @brief ���W�ϊ��s��̌v�Z���s��
 * 
 * @param[out] outMatrices ���W�ϊ��s��̔z��
 * @param[in] orientMatrices �p���ϊ��s��.
 * @return �Ȃ�.
 */
void Skeleton::calculateTransform( Matrix4* outMatrices, Matrix4* orientMatrices )
{
	// ���[�J�����W�ϊ��s��Ǝp���ϊ��s�����������
	for( unsigned int i=0; i<bones_.size(); i++ ){
		outMatrices[i] = bones_[i]->getMatBoneOffset() * orientMatrices[i];
	}
}



/*=========================================================================*/
/**
 * @brief �{�[���̐����擾����
 * 
 * @param[in] �Ȃ�.
 * @return �{�[����.
 */
unsigned int Skeleton::getNumBones() const
{
	return static_cast< unsigned int >( bones_.size() );
}

	

/*===========================================================================*/
/**
 * @brief �e�{�[���Ǝq�{�[���������N����
 * 
 * @param[in] parent �e�{�[��.
 * @param[in] child �q�{�[��.
 * @return �Ȃ�.
 */
void Skeleton::addChild(IBone *parent, IBone *child)
{
	// �e�|�C���^�̃����N������
	child->setParent( parent );
	parent->setChild( child );
}



/*========= EOF =============================================================*/