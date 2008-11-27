/*******************************************************************************/
/**
 * @file AnimationTake.h.
 * 
 * @brief �A�j���[�V�����e�C�N�f�[�^�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ANIMATIONTAKE_H_
#define _NGL_ANIMATIONTAKE_H_

#include	"Ngl/IBoneframe.h"
#include	"Ngl/IKeyframe.h"
#include	<vector>

namespace Ngl{


/**
 * @class AnimationTake.
 * @brief �A�j���[�V�����e�C�N�f�[�^�N���X�D
 */
class AnimationTake : public IBoneframe
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	AnimationTake();


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~AnimationTake();


	/*=========================================================================*/
	/**
	 * @brief �L�[�t���[����ǉ�����
	 * 
	 * @warning �ǉ������L�[�t���[����AnimatinTake�N���X�ō폜����܂�.
	 *
	 * @param[in] keyframe �ǉ�����L�[�t���[��.
	 * @return �Ȃ�.
	 */
	void addKeyFrame( IKeyframe* keyframe );

public:
	
	/*=========================================================================*/
	/**
	 * @brief �w��ԍ��̃L�[�t���[�����擾����
	 * 
	 * @param[in] boneNo �擾����{�[��ID.
	 * @param[in] globalTime �擾����L�[�̃^�C�}.
	 * @param[out] data �L�[�t���[�����.
	 * @return �L�[�t���[�����.
	 */
	virtual KeyframeData& getKeyframe( unsigned int boneNo, float globalTime, KeyframeData& data );
	
	
	/*=========================================================================*/
	/**
	 * @brief �w��̃L�[�t���[���̊g��k���L�[�����擾����
	 * 
	 * @param[in] no �擾����L�[�t���[���ԍ�.
	 * @return �g��k���L�[��.
	 */
	virtual unsigned int getNumScaleKeys( unsigned int no );


	/*=========================================================================*/
	/**
	 * @brief �w��̃L�[�t���[���̉�]�L�[�����擾����
	 * 
	 * @param[in] no �擾����L�[�t���[���ԍ�.
	 * @return ��]�L�[��.
	 */
	virtual unsigned int getNumRotateKeys( unsigned int no );


	/*=========================================================================*/
	/**
	 * @brief �w��̃L�[�t���[���̕��s�ړ��L�[�����擾����
	 * 
	 * @param[in] no �擾����L�[�t���[���ԍ�.
	 * @return ���s�ړ��L�[��.
	 */
	virtual unsigned int getNumPositionKeys( unsigned int no );


	/*=========================================================================*/
	/**
	 * @brief �w��̃L�[�t���[���̊g��k���L�[����t���[���^�C�����擾����
	 * 
	 * @param[in] frameNo �擾����L�[�t���[���ԍ�.
	 * @param[in] keyNo �L�[�ԍ�.
	 * @return �t���[���^�C��.
	 */
	virtual unsigned int getScaleKeyFrameTime( unsigned int frameNo, unsigned int keyNo  );
	
	
	/*=========================================================================*/
	/**
	 * @brief �w��̃L�[�t���[���̉�]�L�[����t���[���^�C�����擾����
	 * 
	 * @param[in] frameNo �擾����L�[�t���[���ԍ�.
	 * @param[in] keyNo �L�[�ԍ�.
	 * @return �t���[���^�C��.
	 */
	virtual unsigned int getRotateKeyFrameTime( unsigned int frameNo, unsigned int keyNo );


	/*=========================================================================*/
	/**
	 * @brief �w��̃L�[�t���[���̕��s�ړ��L�[����t���[���^�C�����擾����
	 * 
	 * @param[in] frameNo �擾����L�[�t���[���ԍ�.
	 * @param[in] keyNo �L�[�ԍ�.
	 * @return �t���[���^�C��.
	 */
	virtual unsigned int getPositionKeyFrameTime( unsigned int frameNo, unsigned int keyNo );


	/*=========================================================================*/
	/**
	 * @brief �L�[�t���[�������擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual unsigned int getNumKeyframes() const;

private:
	
	/*=========================================================================*/
	/**
	 * @brief �{�[���t���[�����������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void release();


	/*=========================================================================*/
	/**
	 * @brief �w��̔ԍ����f�[�^���𒴂��Ă��邩
	 * 
	 * @param[in] no �ԍ�.
	 * @retval true �����Ă���.
	 * @retval false �����Ă��Ȃ�.
	 */
	bool isOutOfRange( unsigned int no );

private:

	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^(�R�s�[�֎~)
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 * @return �Ȃ�.
	 */
	AnimationTake( const AnimationTake& other );


	/*=========================================================================*/
	/**
	 * @brief = ���Z�q�I�[�o�[���[�h(�R�s�[�֎~)
	 * 
	 * @param[in] other ������邷��I�u�W�F�N�g.
	 * @return ������ʂ̃I�u�W�F�N�g.
	 */
	AnimationTake& operator = ( const AnimationTake& other );

private:

	/** �L�[�t���[���z��^ */
	typedef std::vector< IKeyframe* >	KeyFrameArray;

private:

	/** �L�[�t���[���z�� */
	KeyFrameArray	keyFrameArray_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/