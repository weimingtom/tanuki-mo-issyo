/*******************************************************************************/
/**
 * @file Option.h.
 * 
 * @brief ゲームオプションクラスの定義.
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
 * @brief Option．
 */
class Option
{
public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ.
	 * 
	 */
	Option();
	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~Option();

	/*=========================================================================*/
	/**
	 * @brief SEボリュームの設定.
	 * 
	 * @param[in] value 音量.
	 */
	void SetSEVolume(unsigned int value);
	/*=========================================================================*/
	/**
	 * @brief 現在のSEボリュームを取得.
	 * 
	 * @return 音量.
	 */
	unsigned int GetSEVolume();
	/*=========================================================================*/
	/**
	 * @brief BGMボリュームの設定.
	 * 
	 * @param[in] value 音量.
	 */
	void SetBGMVolume(unsigned int value);
	/*=========================================================================*/
	/**
	 * @brief 現在のBGMボリュームの取得.
	 * 
	 * @return 音量.
	 */
	unsigned int GetBGMVolume();

	void LoadSpriteInfo();

private:

	/** BGM音量 */
	unsigned int m_bgmVolume;
	/** SE音量 */
	unsigned int m_seVolume;

public:

	/* インフォ共 */
	SpriteInfo m_fieldSpriteInfo;

	SpriteInfo m_attackSpriteInfo;

	SpriteInfo m_avaterSpriteInfo;

	SpriteInfo m_defenceSpriteInfo;

	SpriteInfo m_hitPointSpriteInfo;

	SpriteInfo m_nextBlockSpriteInfo;

	SpriteInfo m_playerTimeSpriteInfo;

	SpriteInfo m_skillPoint1SpriteInfo;

	SpriteInfo m_skillPoint2SpriteInfo;

	SpriteInfo m_skillPoint3SpriteInfo;

	SpriteInfo m_skillPoint4SpriteInfo;

	SpriteInfo m_scoreSpriteInfo;
/*
	SpriteInfo m_block1SpriteInfo;
	SpriteInfo m_block2SpriteInfo;
	SpriteInfo m_block3SpriteInfo;
	SpriteInfo m_sblock1SpriteInfo;
	SpriteInfo m_sblock2SpriteInfo;
	SpriteInfo m_sblock3SpriteInfo;
	SpriteInfo m_sblock4SpriteInfo;
*/
};

#endif

/*===== EOF ===================================================================*/