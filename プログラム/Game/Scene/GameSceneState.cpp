/*******************************************************************************/
/*
 * @file GameSceneState.cpp.
 * 
 * @brief ゲームシーン状態クラス定義.
 *
 * @date 2008/11/27.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/

/*===== インクルード ==========================================================*/
#include	"Scene/GameSceneState.h"
#include	"Object/GameScene/Player.h"
#include	"Object/GameScene/PlayerParameter.h"

/*=============================================================================*/
/**
 * @brief コンストラクタ.
 * 
 */
GameSceneState::GameSceneState(ObjectManager& objectManager) :
	m_objectManager(objectManager)
{
	m_playerList.clear();
}

/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
GameSceneState::~GameSceneState()
{

}

/*=============================================================================*/
/**
 * @brief プレーヤをリストに追加.
 * 
 * @param[in] player 追加するプレーヤ.
 * @return 追加したプレーヤの番号.
 */
int GameSceneState::AddPlayer(Player *player)
{
	m_playerList.push_back(player);
	return (m_playerList.size() - 1);
}

/*=============================================================================*/
/**
 * @brief プレーヤをリストから削除.
 * 
 * @param[in] player 削除するプレーヤ.
 */
void GameSceneState::DelPlayer(Player* player)
{
	for(std::vector<Player*>::iterator i = m_playerList.begin();i != m_playerList.end();i++)
	{
		if((*i) == player)
		{
			m_playerList.erase(i);
			return;
		}
	}
}

/*=============================================================================*/
/**
 * @brief プレーヤリストのクリア.
 * 
 */
void GameSceneState::ClearPlayer()
{
	m_playerList.clear();
}

/*=============================================================================*/
/**
 * @brief プレーヤの取得.
 * 
 * @param[in] num 取得するプレーヤの番号.
 * @return 取得したプレーヤ.
 */
Player* GameSceneState::GetPlayer(int num)
{
	int k = 0;
	for(std::vector<Player*>::iterator i = m_playerList.begin();i != m_playerList.end(); i++)
	{
		if(k == num)
		{
			return (*i);
		}
		k++;
	}
	return NULL;
}

/*=============================================================================*/
/**
 * @brief 登録されたプレーヤの人数を取得.
 * 
 * @return プレーヤ人数.
 */
int GameSceneState::GetPlayerNum()
{
	return m_playerList.size();
}

int GameSceneState::GetGameState()
{
	return m_gameState;
}

void GameSceneState::SetGameState(int state)
{
	m_gameState = state;
}

Player* GameSceneState::GetTargetPlayer(Player *player)
{
	if(player->GetPlayerParameter().GetPlayerID() != GetPlayer(0)->GetPlayerParameter().GetPlayerID())
	{
		return GetPlayer(0);
	} else
	{
		return GetPlayer(1);
	}
}

/*===== EOF ===================================================================*/