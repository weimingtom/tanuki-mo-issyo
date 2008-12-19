/*******************************************************************************/
/**
 * @file PlayerParameter.h.
 * 
 * @brief �v���C���[�p�����[�^�[�N���X�w�b�_��`.
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
	 * @brief �R���X�g���N�^.
	 *
	 */
	PlayerParameter(int hp, int skillPoint[], int playerTime,
					int characterID, int score, int playerID,
					int playerLV, int playerAttack, int playerDefence,
					int playerType);

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
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


private:

	/** HP */
	int m_hp;
	/** �X�L���|�C���g */
	int m_skillPoint[4];
	/** �v���C���[�^�C�� */
	int m_playerTime;
	/** �L�����N�^�[�h�c */
	int m_characterID;
	/** �X�R�A */
	int m_score;
	/** �v���C���[�h�c */
	int m_playerID;
	/** �v���C���[�k�u */
	int m_playerLV;
	/** �v���C���[�U���� */
	int m_playerAttack;
	/** �v���C���[�h��� */
	int m_playerDefence;
	/** �v���C���[���� */
	int m_playerType;
	
	

};

#endif