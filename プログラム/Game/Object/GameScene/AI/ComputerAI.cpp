/*******************************************************************************/
/*
 * @file ComputerAI.cpp.
 * 
 * @brief �R���s���[�^AI��`.
 *
 * @date 2009/04/13.
 *
 * @version 1.00.
 *
 * @author Tsubasa Uragami.
 */
/*******************************************************************************/

/*===== �C���N���[�h ==========================================================*/
#include	"Object/GameScene/AI/ComputerAI.h"
#include	"Object/GameScene/AI/NormalAI.h"
#include	"Object/GameScene/Player.h"
#include	"Object/GameScene/PuzzleScreen.h"
#include	"Object/GameScene/AI/KeyInfo.h"
/*=============================================================================*/
/**
 * @brief �R���X�g���N�^.
 *
 */
ComputerAI::ComputerAI(IGameDevice &device, Player &player):m_device(device), m_player(player)
{
	m_AIRoutine = new NormalAI(device, player, m_keyInfo);
}
/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
ComputerAI::~ComputerAI()
{

}

/*=============================================================================*/
/**
 * @brief �w�肳�ꂽ�L�[�������ꂽ������.
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
 * @brief  �w�肳�ꂽ�L�[��������Ă��邩����.
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
 * @brief  �w�肳�ꂽ�L�[��������Ă��邩����.
 * 
 */
void ComputerAI::Update(float frameTimer)
{
	m_AIRoutine->Update(frameTimer);
}
/*===== EOF ===================================================================*/
