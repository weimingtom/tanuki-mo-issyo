/*******************************************************************************/
/*
 * @file ComputerAI.cpp.
 * 
 * @brief コンピュータAI定義.
 *
 * @date 2009/04/13.
 *
 * @version 1.00.
 *
 * @author Tsubasa Uragami.
 */
/*******************************************************************************/

/*===== インクルード ==========================================================*/
#include	"Object/GameScene/AI/ComputerAI.h"
#include	"Object/GameScene/AI/NormalAI.h"
#include	"Object/GameScene/Player.h"
#include	"Object/GameScene/PuzzleScreen.h"
#include	"Object/GameScene/AI/KeyInfo.h"
/*=============================================================================*/
/**
 * @brief コンストラクタ.
 *
 */
ComputerAI::ComputerAI(IGameDevice &device, Player &player):m_device(device), m_player(player)
{
	m_AIRoutine = new NormalAI(device, player, m_keyInfo);
}
/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
ComputerAI::~ComputerAI()
{

}

/*=============================================================================*/
/**
 * @brief 指定されたキーが押されたか判定.
 * 
 */
bool ComputerAI::GetKeyTrigger(unsigned int key)
{
	switch(key)
	{
	case GAMEKEY_UP :
		if(m_keyInfo.keyTrigger_up==true) return true;
		else return false;
	case GAMEKEY_DOWN :
		if(m_keyInfo.keyTrigger_down==true) return true;
		else return false;
	case GAMEKEY_RIGHT :
		if(m_keyInfo.keyTrigger_right==true) return true;
		else return false;
	case GAMEKEY_LEFT :
		if(m_keyInfo.keyTrigger_left==true) return true;
		else return false;
	default:
		return false;
	}
}

/*=============================================================================*/
/**
 * @brief  指定されたキーが押されているか判定.
 * 
 */
bool ComputerAI::GetKeyDown(unsigned int key)
{
	switch(key)
	{
	case GAMEKEY_UP :
		if(m_keyInfo.keyDown_up==true) return true;
		else return false;
	case GAMEKEY_DOWN :
		if(m_keyInfo.keyDown_down==true) return true;
		else return false;
	case GAMEKEY_RIGHT :
		if(m_keyInfo.keyDown_right==true) return true;
		else return false;
	case GAMEKEY_LEFT :
		if(m_keyInfo.keyDown_left==true) return true;
		else return false;
	default:
		return false;
	}
}

/*=============================================================================*/
/**
 * @brief  指定されたキーが押されているか判定.
 * 
 */
void ComputerAI::Update(float frameTimer)
{
	m_AIRoutine->Update(frameTimer);
}
/*===== EOF ===================================================================*/
