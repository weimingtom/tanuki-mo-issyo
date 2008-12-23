/*******************************************************************************/
/**
 * @file PlayerAction.cpp.
 * 
 * @brief �v���C���[�A�N�V�����\�[�X��`.
 *
 * @date 2008/12/23.
 *
 * @version 1.00.
 *
 * @author Jun Futagawa.
 */
/*******************************************************************************/

#include "PlayerAction.h"
#include "Player.h"

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 */
PlayerAction::PlayerAction(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player &player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player)
{
}
/*=========================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
PlayerAction::~PlayerAction()
{
}

/*=========================================================================*/
/**
 * @brief ����������.
 * 
 */
void PlayerAction::Initialize()
{

}

/*=========================================================================*/
/**
 * @brief �A�^�b�N.
 * 
 */
void PlayerAction::Attack(Player& player)
{
	player.GetPlayerAction().Damage(m_player.GetPlayerParameter().GetPlayerAttack());
}

/*=========================================================================*/
/**
 * @brief �_���[�W.
 * 
 */
void PlayerAction::Damage(int damage)
{
	m_player.GetPlayerParameter().SetHp(m_player.GetPlayerParameter().GetHp()-damage);
}
/*===== EOF ===================================================================*/
