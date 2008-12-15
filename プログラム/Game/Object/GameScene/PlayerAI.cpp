/*******************************************************************************/
/*
 * @file PlayerAI.cpp.
 * 
 * @brief プレイヤーAI定義.
 *
 * @date 2008/12/15.
 *
 * @version 1.00.
 *
 * @author Tsubasa Uragami.
 */
/*******************************************************************************/

/*===== インクルード ==========================================================*/
#include	"Object/GameScene/PlayerAI.h"

/*=============================================================================*/
/**
 * @brief コンストラクタ.
 *
 */
PlayerAI::PlayerAI(IGameDevice &device, Player &player):m_device(device), m_player(player)
{
}
/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
PlayerAI::~PlayerAI()
{

}

/*=============================================================================*/
/**
 * @brief 指定されたキーが押されたか判定.
 * 
 */
bool PlayerAI::GetKeyTrigger(unsigned int key)
{
	return	m_device.GetInputDevice().GetKeyTrigger(key);
}

/*=============================================================================*/
/**
 * @brief  指定されたキーが押されているか判定.
 * 
 */
bool PlayerAI::GetKeyDown(unsigned int key)
{
	return m_device.GetInputDevice().GetKeyDown(key);
}

/*===== EOF ===================================================================*/
