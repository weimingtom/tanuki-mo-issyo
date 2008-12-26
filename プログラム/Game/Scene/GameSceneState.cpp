/*******************************************************************************/
/*
 * @file GameSceneState.cpp.
 * 
 * @brief �Q�[���V�[����ԃN���X��`.
 *
 * @date 2008/11/27.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/

/*===== �C���N���[�h ==========================================================*/
#include	"Scene/GameSceneState.h"
#include	"Object/GameScene/Player.h"
#include	"Object/GameScene/PlayerParameter.h"

/*=============================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 */
GameSceneState::GameSceneState(ObjectManager& objectManager) :
	m_objectManager(objectManager)
{
	m_playerList.clear();
}

/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
GameSceneState::~GameSceneState()
{

}

/*=============================================================================*/
/**
 * @brief �v���[�������X�g�ɒǉ�.
 * 
 * @param[in] player �ǉ�����v���[��.
 * @return �ǉ������v���[���̔ԍ�.
 */
int GameSceneState::AddPlayer(Player *player)
{
	m_playerList.push_back(player);
	return (m_playerList.size() - 1);
}

/*=============================================================================*/
/**
 * @brief �v���[�������X�g����폜.
 * 
 * @param[in] player �폜����v���[��.
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
 * @brief �v���[�����X�g�̃N���A.
 * 
 */
void GameSceneState::ClearPlayer()
{
	m_playerList.clear();
}

/*=============================================================================*/
/**
 * @brief �v���[���̎擾.
 * 
 * @param[in] num �擾����v���[���̔ԍ�.
 * @return �擾�����v���[��.
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
 * @brief �o�^���ꂽ�v���[���̐l�����擾.
 * 
 * @return �v���[���l��.
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