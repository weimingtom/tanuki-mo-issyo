/*******************************************************************************/
/**
 * @file Option.h.
 * 
 * @brief �Q�[���I�v�V�����N���X�̒�`.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _OPTION_H_
#define _OPTION_H_

#include "Define/SpriteInfo.h"

/**
 * @brief Option�D
 */
class Option
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^.
	 * 
	 */
	Option();
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 *
	 */
	~Option();

	/*=========================================================================*/
	/**
	 * @brief SE�{�����[���̐ݒ�.
	 * 
	 * @param[in] value ����.
	 */
	void SetSEVolume(unsigned int value);
	/*=========================================================================*/
	/**
	 * @brief ���݂�SE�{�����[�����擾.
	 * 
	 * @return ����.
	 */
	unsigned int GetSEVolume();
	/*=========================================================================*/
	/**
	 * @brief BGM�{�����[���̐ݒ�.
	 * 
	 * @param[in] value ����.
	 */
	void SetBGMVolume(unsigned int value);
	/*=========================================================================*/
	/**
	 * @brief ���݂�BGM�{�����[���̎擾.
	 * 
	 * @return ����.
	 */
	unsigned int GetBGMVolume();

private:

	/** BGM���� */
	unsigned int m_bgmVolume;
	/** SE���� */
	unsigned int m_seVolume;

	/* �C���t�H�� */
	SpriteInfo fieldSpriteInfo;

	SpriteInfo attackSpriteInfo;

	SpriteInfo avaterSpriteInfo;

	SpriteInfo defenceSpriteInfo;

	SpriteInfo hitPointSpriteInfo;

	SpriteInfo nextBlockSpriteInfo;

	SpriteInfo playerTimeSpriteInfo;

	SpriteInfo skillPointRedSpriteInfo;

	SpriteInfo skillPointBlueSpriteInfo;

	SpriteInfo skillPointYellowSpriteInfo;

	SpriteInfo skillPointWhiteSpriteInfo;

	SpriteInfo scoreSpriteInfo;

};

#endif

/*===== EOF ===================================================================*/