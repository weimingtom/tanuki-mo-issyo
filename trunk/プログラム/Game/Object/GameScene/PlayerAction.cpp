/*******************************************************************************/
/**
 * @file PlayerAction.cpp.
 * 
 * @brief プレイヤーアクションソース定義.
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
 * @brief コンストラクタ.
 * 
 */
PlayerAction::PlayerAction(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player &player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player)
{
}
/*=========================================================================*/
/**
 * @brief デストラクタ.
 *
 */
PlayerAction::~PlayerAction()
{
}

/*=========================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void PlayerAction::Initialize()
{

}

/*=========================================================================*/
/**
 * @brief アタック.
 * 
 */
void PlayerAction::Attack(Player& player)
{
	player.GetPlayerAction().Damage(m_player.GetPlayerParameter().GetPlayerAttack());
}

/*=========================================================================*/
/**
 * @brief ダメージ.
 * 
 */
void PlayerAction::Damage(int damage)
{
	m_player.GetPlayerParameter().SetHp(m_player.GetPlayerParameter().GetHp()-damage);
}
/*===== EOF ===================================================================*/
