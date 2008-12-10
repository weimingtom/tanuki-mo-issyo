/*******************************************************************************/
/**
 * @file AnimationTake.cpp.
 * 
 * @brief �A�j���[�V�����e�C�N�f�[�^�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/AnimationTake.h"
#include	<cassert>

using namespace Ngl;

/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
AnimationTake::AnimationTake()
{}



/*===========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
AnimationTake::~AnimationTake()
{
	// �{�[���t���[�����������
	release();
}



/*=========================================================================*/
/**
 * @brief �L�[�t���[����ǉ�����
 * 
 * @warning �ǉ������L�[�t���[����AnimatinTake�N���X�ō폜����܂�.
 *
 * @param[in] keyframe �ǉ�����L�[�t���[��.
 * @return �Ȃ�.
 */
void AnimationTake::addKeyFrame( IKeyframe* keyframe )
{
	keyFrameArray_.push_back( keyframe );
}

	
	
/*===========================================================================*/
/**
 * @brief �w��ԍ��̃L�[�t���[�����擾����
 * 
 * @param[in] boneNo �擾����{�[��ID.
 * @param[in] globalTime �擾����L�[�̃^�C�}.
 * @param[out] data �L�[�t���[�����.
 * @return �L�[�t���[�����.
 */
KeyframeData& AnimationTake::getKeyframe(unsigned int boneNo, float globalTime, Ngl::KeyframeData &data)
{
	// �{�[���i���o�[���L�[�t���[���������傫����
	if( isOutOfRange( boneNo ) ){
		return data;
	}

	// �L�[�t���[���f�[�^����e�l���擾����
	return keyFrameArray_[ boneNo ]->getKey( globalTime, data );
}



/*===========================================================================*/
/**
 * @brief �{�[���t���[�����������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void AnimationTake::release()
{
	// �L�[�t���[���z������
	KeyFrameArray::iterator itor = keyFrameArray_.begin();
	while( itor != keyFrameArray_.end() ){
		delete *itor;
		itor = keyFrameArray_.erase( itor );
	}
}



/*===========================================================================*/
/**
 * @brief �w��̃L�[�t���[���̊g��k���L�[�����擾����
 * 
 * @param[in] no �擾����L�[�t���[���ԍ�.
 * @return �g��k���L�[��.
 */
unsigned int AnimationTake::getNumScaleKeys(unsigned int no)
{
	// �w��̔ԍ����f�[�^�������傫����
	if( isOutOfRange( no ) ){
		return 0;
	}

	// �L�[�t���[������g��k���L�[�����擾����
	return keyFrameArray_[no]->getNumScaleKeys();
}



/*===========================================================================*/
/**
 * @brief �w��̃L�[�t���[���̉�]�L�[�����擾����
 * 
 * @param[in] no �擾����L�[�t���[���ԍ�.
 * @return ��]�L�[��.
 */
unsigned int AnimationTake::getNumRotateKeys(unsigned int no)
{
	// �w��̔ԍ����f�[�^�������傫����
	if( isOutOfRange( no ) ){
		return 0;
	}

	// �L�[�t���[�������]�L�[�����擾����
	return keyFrameArray_[no]->getNumRotateKeys();
}



/*===========================================================================*/
/**
 * @brief �w��̃L�[�t���[���̕��s�ړ��L�[�����擾����
 * 
 * @param[in] no �擾����L�[�t���[���ԍ�.
 * @return ���s�ړ��L�[��.
 */
unsigned int AnimationTake::getNumPositionKeys(unsigned int no)
{
	// �w��̔ԍ����f�[�^�������傫����
	if( isOutOfRange( no ) ){
		return 0;
	}

	// �L�[�t���[�����畽�s�ړ��L�[�����擾����
	return keyFrameArray_[no]->getNumPositionKeys();
}



/*===========================================================================*/
/**
 * @brief �w��̃L�[�t���[���̊g��k���L�[����t���[���^�C�����擾����
 * 
 * @param[in] frameNo �擾����L�[�t���[���ԍ�.
 * @param[in] keyNo �L�[�ԍ�.
 * @return �t���[���^�C��.
 */
unsigned int AnimationTake::getScaleKeyFrameTime(unsigned int frameNo, unsigned int keyNo)
{
	// �w��̔ԍ����f�[�^�������傫����
	if( isOutOfRange( frameNo ) ){
		return 0;
	}

	// �t���[���^�C�����擾����
	return keyFrameArray_[frameNo]->getScaleKeyFrameTime( keyNo );
}



/*===========================================================================*/
/**
 * @brief �w��̃L�[�t���[���̉�]�L�[����t���[���^�C�����擾����
 * 
 * @param[in] frameNo �擾����L�[�t���[���ԍ�.
 * @param[in] keyNo �L�[�ԍ�.
 * @return �t���[���^�C��.
 */
unsigned int AnimationTake::getRotateKeyFrameTime(unsigned int frameNo, unsigned int keyNo)
{
	// �w��̔ԍ����f�[�^�������傫����
	if( isOutOfRange( frameNo ) ){
		return 0;
	}

	// �t���[���^�C�����擾����
	return keyFrameArray_[frameNo]->getRotateKeyFrameTime( keyNo );
}



/*===========================================================================*/
/**
 * @brief �w��̃L�[�t���[���̕��s�ړ��L�[����t���[���^�C�����擾����
 * 
 * @param[in] frameNo �擾����L�[�t���[���ԍ�.
 * @param[in] keyNo �L�[�ԍ�.
 * @return �t���[���^�C��.
 */
unsigned int AnimationTake::getPositionKeyFrameTime( unsigned int frameNo, unsigned int keyNo )
{
	// �w��̔ԍ����f�[�^�������傫����
	if( isOutOfRange( frameNo ) ){
		return 0;
	}

	// �t���[���^�C�����擾����
	return keyFrameArray_[frameNo]->getPositionKeyFrameTime( keyNo );
}



/*=========================================================================*/
/**
 * @brief �L�[�t���[�������擾����
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
unsigned int AnimationTake::getNumKeyframes() const
{
	return (unsigned int)keyFrameArray_.size();
}
	


/*===========================================================================*/
/**
 * @brief �w��̔ԍ����f�[�^���𒴂��Ă��邩
 * 
 * @param[in] no �ԍ�.
 * @retval true �����Ă���.
 * @retval false �����Ă��Ȃ�.
 */
bool AnimationTake::isOutOfRange( unsigned int no )
{
	if( no > keyFrameArray_.size() ){
		return true;
	}
	return false;
}



/*========= EOF =============================================================*/