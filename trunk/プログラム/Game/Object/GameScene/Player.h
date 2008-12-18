/*******************************************************************************/
/**
 * @file Player.h.
 * 
 * @brief �v���[���[�N���X��`.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _PLAYER_H_
#define _PLAYER_H_

/*===== �C���N���[�h ==========================================================*/
#include	"IGameDevice.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"
#include	"Manager/Scene/Option/Option.h"
class		IGameDevice;

#include    "Object/GameScene/PuzzleScreen.h"
#include    "Object/GameScene/CharacterScreen.h"
#include	"Object/GameScene/StatusScreen.h"
#include	"Object/GameScene/Player.h"
#include	"Object/GameScene/AIBase.h"
#include	"Object/GameScene/PlayerAI.h"
#include	"Object/GameScene/PlayerParameter.h"

/**
 * @brief Player�D
 */
class Player : public ObjectBase
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^.
	 * 
	 * @param[in] device �Q�[���f�o�C�X.
	 * @param[in] objectManager �I�u�W�F�N�g�}�l�[�W��.
	 * @param[in] option �Q�[���I�v�V����.
	 * @param[in] gameSceneState �Q�[���V�[���X�e�[�g.
	 */
	Player(IGameDevice& device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState, float x, float y,
			int hp, int skillPoint[], int playerTime,int characterID, int score, int playerID,int playerLV, int playerAttack,
			int playerDefence,int playerType);
	

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 *
	 */
	~Player();

	/*=========================================================================*/
	/**
	 * @brief ����������.
	 * 
	 */
	void Initialize();
	/*=========================================================================*/
	/**
	 * @brief �I������.
	 * 
	 */
	void Terminate();
	/*=========================================================================*/
	/**
	 * @brief �I�����Ă��邩�ǂ���.
	 * 
	 * @return �I���t���O.
	 */
	bool IsTerminated();

	/*=========================================================================*/
	/**
	 * @brief �I�u�W�F�N�g�̕`�揈��.
	 * 
	 */
	void RenderObject();
	/*=========================================================================*/
	/**
	 * @brief �I�u�W�F�N�g�̍X�V����.
	 * 
	 * @param[in] frameTimer �X�V�^�C�}.
	 */
	void UpdateObject(float frameTimer);

	Vector2 GetPosition();
	PuzzleScreen& GetPuzzleScreen();

	AIBase& GetAI();
	void SetAI(AIBase* ai);

private:

	/** �I���t���O */
	bool m_isTerminated;
	/** �Q�[���f�o�C�X */
	IGameDevice& m_device;
	/** �I�u�W�F�N�g�}�l�[�W�����f�B�G�[�^ */
	ObjectManager& m_objectManager;
	/** �Q�[���I�v�V���� */
	Option& m_option;
	/** �Q�[���V�[���X�e�[�g */
	GameSceneState m_gameSceneState;
	/** �v���C���[�p�����[�^ */
	PlayerParameter m_playerParameter;

	PuzzleScreen	m_puzzleScreen;
	CharacterScreen	m_characterScreen;
	AIBase*			m_AI;
	StatusScreen	m_statusScreen;

	float m_x;
	float m_y;

};

#endif

/*===== EOF ===================================================================*/
