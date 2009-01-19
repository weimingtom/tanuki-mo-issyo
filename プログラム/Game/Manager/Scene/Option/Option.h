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

	void LoadSpriteInfo();

private:

	/** BGM���� */
	unsigned int m_bgmVolume;
	/** SE���� */
	unsigned int m_seVolume;

	/* �C���t�H�� */
	SpriteInfo fieldSpriteInfo;

	SpriteInfo m_attackSpriteInfo;

	SpriteInfo m_avaterSpriteInfo;

	SpriteInfo m_defenceSpriteInfo;

	SpriteInfo m_hitPointSpriteInfo;

	SpriteInfo m_nextBlockSpriteInfo;

	SpriteInfo m_playerTimeSpriteInfo;

	SpriteInfo m_skillPointRedSpriteInfo;

	SpriteInfo m_skillPointBlueSpriteInfo;

	SpriteInfo m_skillPointYellowSpriteInfo;

	SpriteInfo m_skillPointWhiteSpriteInfo;

	SpriteInfo m_scoreSpriteInfo;

};

#endif

/*===== EOF ===================================================================*/