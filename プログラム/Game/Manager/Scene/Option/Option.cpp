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

	m_attackSpriteInfo = loader.LoadSpriteInfo("attacktest.dds");

}

/*===== EOF ===================================================================*/