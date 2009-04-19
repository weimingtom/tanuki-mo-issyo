/*******************************************************************************/
/*
 * @file PlayerAI.cpp.
 * 
 * @brief �v���C���[AI��`.
 *
 * @date 2008/12/15.
 *
 * @version 1.00.
 *
 * @author Tsubasa Uragami.
 */
/*******************************************************************************/

/*===== �C���N���[�h ==========================================================*/
#include	"Object/GameScene/AI/PlayerAI.h"

/*=============================================================================*/
/**
 * @brief �R���X�g���N�^.
 *
 */
PlayerAI::PlayerAI(IGameDevice &device, Player &player):m_device(device), m_player(player)
{
}
/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
PlayerAI::~PlayerAI()
{

}

/*=============================================================================*/
/**
 * @brief �w�肳�ꂽ�L�[�������ꂽ������.
 * 
 */
bool PlayerAI::GetKeyTrigger(unsigned int key)
{
	return	m_device.GetInputDevice().GetKeyTrigger(key);
}

/*=============================================================================*/
/**
 * @brief  �w�肳�ꂽ�L�[��������Ă��邩����.
 * 
 */
bool PlayerAI::GetKeyDown(unsigned int key)
{
	return m_device.GetInputDevice().GetKeyDown(key);
}

/*=============================================================================*/
/**
 * @brief	.
 * 
 */
void PlayerAI::Update(float frameTimer)
{

}
/*===== EOF ===================================================================*/
