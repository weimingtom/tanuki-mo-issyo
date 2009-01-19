/*******************************************************************************/
/*
 * @file Option.cpp.
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

/*===== インクルード ==========================================================*/
#include	"Manager/Scene/Option/Option.h"
#include	"Manager/Scene/Option/XMLLoader.h"


/*=============================================================================*/
/**
 * @brief コンストラクタ.
 * 
 */
Option::Option()
{

}

/*=============================================================================*/
/**
 * @brief デストラクタ.
 */
Option::~Option()
{

}

/*=============================================================================*/
/**
 * @brief SEボリュームの設定.
 * 
 * @param[in] value 音量.
 */
void Option::SetSEVolume(unsigned int value)
{
	m_seVolume = value;
}

/*=============================================================================*/
/**
 * @brief 現在のSEボリュームを取得.
 * 
 * @return 音量.
 */
unsigned int Option::GetSEVolume()
{
	return m_seVolume;
}

/*=============================================================================*/
/**
 * @brief BGMボリュームの設定.
 * 
 * @param[in] value 音量.
 */
void Option::SetBGMVolume(unsigned int value)
{
	m_bgmVolume = value;
}

/*=============================================================================*/
/**
 * @brief 現在のBGMボリュームの取得.
 * 
 * @return 音量.
 */
unsigned int Option::GetBGMVolume()
{
	return m_bgmVolume;
}

void Option::LoadSpriteInfo()
{
	XMLLoader loader;

	m_attackSpriteInfo			= loader.LoadSpriteInfo("attack");
	m_defenceSpriteInfo			= loader.LoadSpriteInfo("defence");
	m_fieldSpriteInfo			= loader.LoadSpriteInfo("field");
	m_avaterSpriteInfo			= loader.LoadSpriteInfo("avater");
	m_hitPointSpriteInfo		= loader.LoadSpriteInfo("hitpoint");
	m_nextBlockSpriteInfo		= loader.LoadSpriteInfo("nextblock");
	m_playerTimeSpriteInfo		= loader.LoadSpriteInfo("playertime");
	m_skillPoint1SpriteInfo		= loader.LoadSpriteInfo("skillpoint1");
	m_skillPoint2SpriteInfo		= loader.LoadSpriteInfo("skillpoint2");
	m_skillPoint3SpriteInfo		= loader.LoadSpriteInfo("skillpoint3");
	m_skillPoint4SpriteInfo		= loader.LoadSpriteInfo("skillpoint4");
	m_scoreSpriteInfo			= loader.LoadSpriteInfo("score");

}

/*===== EOF ===================================================================*/