/*******************************************************************************/
/**
 * @file IKeyframe.h.
 * 
 * @brief �A�j���[�V�����L�[�t���[���C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/01.
 * 
 * @version 1.00.
 * 
 * @author Kentaru Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IKEYFRAME_H_
#define _NGL_IKEYFRAME_H_

#include	"Ngl/KeyframeData.h"

namespace Ngl{


/**
 * @interface IKeyframe.
 * @brief �A�j���[�V�����L�[�t���[���C���^�[�t�F�[�X�D
 */
class IKeyframe
{	

public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IKeyframe() {}
	
	
	/*=========================================================================*/
	/**
	 * @brief �L�[�t���[���f�[�^�̎擾
	 * 
	 * @param[in] globalTime �擾����L�[�̃^�C�}.
	 * @param[out] data �L�[�t���[���f�[�^.
	 * @return �L�[�t���[���f�[�^.
	 */
	virtual KeyframeData& getKey( float globalTime, KeyframeData& data ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �w��̊g��k���L�[�̃t���[���^�C�����擾����
	 * 
	 * @param[in] no �g��k���L�[�ԍ�.
	 * @return �t���[���^�C�}.
	 */
	virtual unsigned int getScaleKeyFrameTime( unsigned int no ) const = 0;


	/*=========================================================================*/
	/**
	 * @brief �w��̉�]�L�[�̃t���[���^�C�����擾����
	 * 
	 * @param[in] no ��]�L�[�ԍ�.
	 * @return �t���[���^�C�}.
	 */
	virtual unsigned int getRotateKeyFrameTime( unsigned int no ) const = 0;


	/*=========================================================================*/
	/**
	 * @brief �w��̕��s�ړ��L�[�̃t���[���^�C�����擾����
	 * 
	 * @param[in] no ���s�ړ��L�[�ԍ�.
	 * @return �t���[���^�C�}.
	 */
	virtual unsigned int getPositionKeyFrameTime( unsigned int no ) const = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �g��k���L�[�����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �g��k���L�[��.
	 */
	virtual unsigned int getNumScaleKeys() const = 0;


	/*=========================================================================*/
	/**
	 * @brief ��]�L�[�����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return ��]�L�[��.
	 */
	virtual unsigned int getNumRotateKeys() const = 0;
	

	/*=========================================================================*/
	/**
	 * @brief ���s�ړ��L�[�����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���s�ړ��L�[��.
	 */
	virtual unsigned int getNumPositionKeys() const = 0;

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/