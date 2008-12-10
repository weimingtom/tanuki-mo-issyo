/*******************************************************************************/
/**
 * @file Animation.cpp.
 * 
 * @brief �A�j���[�V�����f�[�^�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/01.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Animation.h"
#include	"Ngl/FileInputC.h"
#include	<fstream>
#include	<algorithm>
#include	<cassert>

using namespace Ngl;

/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
Animation::Animation()
{}



/*===========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
Animation::~Animation()
{
	// �A�j���[�V�����f�[�^���������
	release();
}



/*=========================================================================*/
/**
 * @brief �A�j���[�V�����e�C�N�f�[�^��ǉ�����
 * 
 * @warning �ǉ������A�j���[�V�����e�C�N�f�[�^��Animation�N���X�ō폜����܂�.
 *
 * @param[in] animationTake �ǉ�����f�[�^.
 * @return �I���^�C�}.
 */
void Animation::addAnimationTake( IBoneframe* animationTake )
{
	animationTakeArray_.push_back( animationTake );
}

	
	
/*===========================================================================*/
/**
 * @brief �w��̃L�[�t���[���f�[�^���擾����
 * 
 * @param[in] no �擾����f�[�^�ԍ�.
 * @param[in] boneNo �擾����{�[���ԍ�.
 * @param[in] globalTime �擾����L�[�̃^�C�}.
 * @param[out] data �L�[�t���[���f�[�^.
 * @return �L�[�t���[���f�[�^.
 */
KeyframeData& Animation::getKeyFrame(unsigned int no, unsigned int boneNo, float globalTime, KeyframeData &data)
{
	// �e�L�[�̒l������������
	data.scale.initialize( 1.0f, 1.0f, 1.0f );
	data.rotate.setIdentity();
	data.position.zero();

	// �{�[���t���[���ԍ����f�[�^�������傫����
	if( isOutOfRange( no ) == true ){
		return data;
	}

	// �w��{�[���̃L�[�t���[�����擾����
	return animationTakeArray_[ no ]->getKeyframe( boneNo, globalTime, data );
}



/*===========================================================================*/
/**
 * @brief �A�j���[�V�����̏I���^�C�}�𒲂ׂ�
 * 
 * @param[in] no �A�j���[�V�����i���o�[.
 * @return �I���^�C�}.
 */
unsigned int Animation::getEndTimer( unsigned int no )
{
	// �w��̃i���o�[���f�[�^������������
	if( isOutOfRange( no ) == true ){
		return 0;
	}

	// �I���^�C���̏�����
	unsigned int endTime = 0;

	// �I���^�C�}�̈�ԑ����L�[����������
	IBoneframe* tmpBoneframe = animationTakeArray_[ no ];
	for( unsigned int i=0; i<tmpBoneframe->getNumKeyframes(); i++ ){
		// �g��k���L�[�̃t���[���^�C���Ɣ�r
		unsigned int numScaleKeys = tmpBoneframe->getNumScaleKeys( i );
		if( numScaleKeys != 0 ){
			endTime = std::max( endTime, tmpBoneframe->getScaleKeyFrameTime( i, numScaleKeys - 1 ) );
		}

		// ��]�L�[�̃t���[���^�C���Ɣ�r
		unsigned int numRotateKeys = tmpBoneframe->getNumRotateKeys( i );
		if( numRotateKeys != 0 ){
			endTime = std::max( endTime, tmpBoneframe->getRotateKeyFrameTime( i, numRotateKeys - 1 ) );
		}

		// ���s�ړ��L�[�̃t���[���^�C���Ɣ�r
		unsigned int numPositionKeys = tmpBoneframe->getNumPositionKeys( i );
		if( numPositionKeys != 0 ){
			endTime = std::max( endTime, tmpBoneframe->getPositionKeyFrameTime( i, numPositionKeys - 1 ) );
		}
	}

	return endTime;
}



/*===========================================================================*/
/**
 * @brief �w��̃A�j���[�V�����̃{�[�����𒲂ׂ�
 * 
 * @param[in] no �f�[�^�ԍ�.
 * @return �{�[����.
 */
unsigned int Animation::getNumBones(unsigned int no)
{
	// �w��̔ԍ����f�[�^�������傫����
	if( isOutOfRange( no ) ){
		return 0;
	}

	return animationTakeArray_[no]->getNumKeyframes();
}



/*===========================================================================*/
/**
 * @brief �A�j���[�V�����f�[�^�̉��
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void Animation::release()
{
	// �A�j���[�V�����e�C�N�z������
	AnimationTakeArray::iterator itor = animationTakeArray_.begin();
	while( itor != animationTakeArray_.end() ){
		delete *itor;
		itor = animationTakeArray_.erase( itor );
	}
}



/*===========================================================================*/
/**
 * @brief �w��i���o�[���{�[���t���[���f�[�^�������傫����
 * 
 * @param[in] boneframeNo �{�[���t���[���ԍ�.
 * @retval true �傫��.
 * @retval false ������.
 */
bool Animation::isOutOfRange(unsigned int boneframeNo)
{
	if( boneframeNo >= animationTakeArray_.size() ){
		return true;
	}
	return false;
}



/*========= EOF =============================================================*/