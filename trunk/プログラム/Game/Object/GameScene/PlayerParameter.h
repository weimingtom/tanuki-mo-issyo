/*******************************************************************************/
/**
 * @file PlayerParameter.h.
 * 
 * @brief プレイヤーパラメータークラスヘッダ定義.
 *
 * @date 2008/12/18.
 *
 * @version 1.00.
 *
 * @author Jun Futagawa.
 */
/*******************************************************************************/
#ifndef _PLAYERPARAMETER_H_
#define _PLAYERPARAMETER_H_

#include	"IGameDevice.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"
#include	"Manager/Scene/Option/Option.h"

class PlayerParameter 
{
public:
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ.
	 *
	 */
	PlayerParameter(int hp, int skillPoint[], int playerTime,
					int characterID, int score, int playerID,
					int playerLV, int playerAttack, int playerDefence,
					int playerType, int cblock, int mblock,int maxHp);

	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~PlayerParameter();

	int GetHp();
	void SetHp(int hp); 

	int GetSkillPoint();
	void SetSkillPoint(int skillPoint[]);
	
	int GetPlayerTime();
	void SetPlayerTime(int playerTime);

	int GetCharacterID();
	void SetCharacterID(int characterID);

	int GetScore();
	void SetScore(int Score);

	int GetPlayerID();
	void SetPlayerID(int playerID);

	int GetPlayerLV();
	void SetPlayerLV(int playerLV);

	int GetPlayerAttack();
	void SetPlayerAttack(int playerAttack);

	int GetPlayerDefence();
	void SetPlayerDefence(int playerDefence);

	int GetPlayerType();
	void SetPlayerType(int playerType);

	int GetNextCBlock();
	int GetNextMBlock();

	void SetNextBlock(int cblock, int mblock);

	int GetMaxHp();
	void SetMaxHp(int maxHp);

private:

	/** HP */
	int m_hp;
	/** スキルポイント */
	int m_skillPoint[4];
	/** プレイヤータイム */
	int m_playerTime;
	/** キャラクターＩＤ */
	int m_characterID;
	/** スコア */
	int m_score;
	/** プレイヤーＩＤ */
	int m_playerID;
	/** プレイヤーＬＶ */
	int m_playerLV;
	/** プレイヤー攻撃力 */
	int m_playerAttack;
	/** プレイヤー防御力 */
	int m_playerDefence;
	/** プレイヤー属性 */
	int m_playerType;
	/** 次のブロックの軸ID */
	int m_nextCBlock;
	/** 次のブロックのサブID */
	int m_nextMBlock;
	/** マックスＨＰ */
	int m_maxHp;

};

#endif