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
void PlayerAction::Attack(Player* player)
{
	player->GetPlayerAction().Damage(m_player.GetPlayerParameter().GetPlayerAttack());
	m_player.GetCharacterScreen().GetAvatar().SetAnimationState(AVATAR_ANIMATION_STATE_ATTACK);
}

/*=========================================================================*/
/**
 * @brief ダメージ.
 * 
 */
void PlayerAction::Damage(int damage)
{
	m_player.GetPlayerParameter().SetHp(m_player.GetPlayerParameter().GetHp()-damage);
	m_player.GetCharacterScreen().GetAvatar().SetAnimationState(AVATAR_ANIMATION_STATE_DAMAGE);
}

void PlayerAction::AddSkillPoint(int id)
{
	int* skill;
	skill = m_player.GetPlayerParameter().GetSkillPoint();
	skill[id]++;
	m_player.GetPlayerParameter().SetSkillPoint(skill);
}

void PlayerAction::ClearSkillPoint()
{
	int skill[4] = {0, 0, 0, 0};
	m_player.GetPlayerParameter().SetSkillPoint(skill);
}

void PlayerAction::AddHP(int num)
{
	m_player.GetPlayerParameter().SetHp(m_player.GetPlayerParameter().GetHp() + num);
}

void PlayerAction::AddAttack(int num)
{
	m_player.GetPlayerParameter().SetPlayerAttack(m_player.GetPlayerParameter().GetPlayerAttack() + num);
}

void PlayerAction::AddDefence(int num)
{
	m_player.GetPlayerParameter().SetPlayerDefence(m_player.GetPlayerParameter().GetPlayerDefence() + num);
}

void PlayerAction::AddScore(int num)
{
	m_player.GetPlayerParameter().SetScore(m_player.GetPlayerParameter().GetScore() + num);
}

void PlayerAction::AddTime(int num)
{
	m_player.GetPlayerParameter().SetPlayerTime(m_player.GetPlayerParameter().GetPlayerTime() + num);
}

void PlayerAction::SubTime(int num)
{
	m_player.GetPlayerParameter().SetPlayerTime(m_player.GetPlayerParameter().GetPlayerTime() - num);
}
/*===== EOF ===================================================================*/
