/*******************************************************************************/
/**
 * @file PlayerParameter.cpp.
 * 
 * @brief プレイヤーパラメータークラスソース定義.
 *
 * @date 2008/12/18.
 *
 * @version 1.00.
 *
 * @author Jun Futagawa.
 */
/*******************************************************************************/

#include	"PlayerParameter.h"
#include	"Player.h"

/*=========================================================================*/
/**
 * @brief コンストラクタ.
 * 
 */
PlayerParameter::PlayerParameter(int hp, int skillPoint[], int playerTime,
					int characterID, int score, int playerID,
					int playerLV, int playerAttack, int playerDefence,
					int playerType)
{
	m_hp = hp;
	m_skillPoint[4] = skillPoint[4];
	m_playerTime = playerTime;
	m_characterID = characterID;
	m_score = score;
	m_playerID = playerID;
	m_playerLV = playerLV;
	m_playerAttack = playerAttack;
	m_playerDefence = playerDefence;
	m_playerType = playerType; 

}

/*=========================================================================*/
/**
 * @brief デストラクタ.
 *
 */
PlayerParameter::~PlayerParameter()
{


}

int PlayerParameter::GetHp()
{
	return m_hp;
}
void PlayerParameter::SetHp(int hp)
{
	m_hp = hp;
}


int PlayerParameter::GetSkillPoint()
{
	return m_skillPoint[4];
}
void PlayerParameter::SetSkillPoint(int skillPoint[])
{
	m_skillPoint[4] = skillPoint[4];
}


int PlayerParameter::GetPlayerTime()
{
	return m_playerTime;
}
void PlayerParameter::SetPlayerTime(int playerTime)
{
	m_playerTime = playerTime;
}


int PlayerParameter::GetCharacterID()
{
	return m_characterID;
}
void PlayerParameter::SetCharacterID(int characterID)
{
	m_characterID = characterID;
}


int PlayerParameter::GetScore()
{
	return m_score;
}
void PlayerParameter::SetScore(int score)
{
	m_score = score;
}


int PlayerParameter::GetPlayerID()
{
	return m_playerID;
}
void PlayerParameter::SetPlayerID(int playerID)
{
	m_playerID = playerID;
}


int PlayerParameter::GetPlayerLV()
{
	return m_playerLV;
}
void PlayerParameter::SetPlayerLV(int playerLV)
{
	m_playerLV = playerLV;
}


int PlayerParameter::GetPlayerAttack()
{
	return m_playerAttack;
}
void PlayerParameter::SetPlayerAttack(int playerAttack)
{
	m_playerAttack = playerAttack;
}


int PlayerParameter::GetPlayerDefence()
{
	return m_playerDefence;
}
void PlayerParameter::SetPlayerDefence(int playerDefence)
{
	m_playerDefence = playerDefence;
}


int PlayerParameter::GetPlayerType()
{
	return m_playerType;
}
void PlayerParameter::SetPlayerType(int playerType)
{
	m_playerType = playerType;
}





/*===== EOF ===================================================================*/
