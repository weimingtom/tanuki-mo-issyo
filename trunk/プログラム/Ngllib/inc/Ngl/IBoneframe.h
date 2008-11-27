/*******************************************************************************/
/**
 * @file IBoneframe.h.
 * 
 * @brief �A�j���[�V�����{�[���t���[���f�[�^�C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/01.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IBONEFRAME_H_
#define _NGL_IBONEFRAME_H_

#include	"KeyframeData.h"

namespace Ngl{


/**
 * @interface IBoneframe.
 * @brief �A�j���[�V�����{�[���t���[���f�[�^�C���^�[�t�F�[�X�D
 */
class IBoneframe
{

public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IBoneframe() {}
	
	
	/*=========================================================================*/
	/**
	 * @brief �w��ԍ��̃L�[�t���[�����擾����
	 * 
	 * @param[in] boneNo �擾����{�[��ID.
	 * @param[in] globalTime �擾����L�[�̃^�C�}.
	 * @param[out] data �L�[�t���[�����.
	 * @return �L�[�t���[�����.
	 */
	virtual KeyframeData& getKeyframe( unsigned int boneNo, float globalTime, KeyframeData& data ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �w��̃L�[�t���[���̊g��k���L�[�����擾����
	 * 
	 * @param[in] no �擾����L�[�t���[���ԍ�.
	 * @return �g��k���L�[��.
	 */
	virtual unsigned int getNumScaleKeys( unsigned int no ) = 0;


	/*=========================================================================*/
	/**
	 * @brief �w��̃L�[�t���[���̉�]�L�[�����擾����
	 * 
	 * @param[in] no �擾����L�[�t���[���ԍ�.
	 * @return ��]�L�[��.
	 */
	virtual unsigned int getNumRotateKeys( unsigned int no ) = 0;


	/*=========================================================================*/
	/**
	 * @brief �w��̃L�[�t���[���̕��s�ړ��L�[�����擾����
	 * 
	 * @param[in] no �擾����L�[�t���[���ԍ�.
	 * @return ���s�ړ��L�[��.
	 */
	virtual unsigned int getNumPositionKeys( unsigned int no ) = 0;


	/*=========================================================================*/
	/**
	 * @brief �w��̃L�[�t���[���̊g��k���L�[����t���[���^�C�����擾����
	 * 
	 * @param[in] frameNo �擾����L�[�t���[���ԍ�.
	 * @param[in] keyNo �L�[�ԍ�.
	 * @return �t���[���^�C��.
	 */
	virtual unsigned int getScaleKeyFrameTime( unsigned int frameNo, unsigned int keyNo  ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �w��̃L�[�t���[���̉�]�L�[����t���[���^�C�����擾����
	 * 
	 * @param[in] frameNo �擾����L�[�t���[���ԍ�.
	 * @param[in] keyNo �L�[�ԍ�.
	 * @return �t���[���^�C��.
	 */
	virtual unsigned int getRotateKeyFrameTime( unsigned int frameNo, unsigned int keyNo ) = 0;


	/*=========================================================================*/
	/**
	 * @brief �w��̃L�[�t���[���̕��s�ړ��L�[����t���[���^�C�����擾����
	 * 
	 * @param[in] frameNo �擾����L�[�t���[���ԍ�.
	 * @param[in] keyNo �L�[�ԍ�.
	 * @return �t���[���^�C��.
	 */
	virtual unsigned int getPositionKeyFrameTime( unsigned int frameNo, unsigned int keyNo ) = 0;


	/*=========================================================================*/
	/**
	 * @brief �L�[�t���[�������擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual unsigned int getNumKeyframes() const = 0;

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/