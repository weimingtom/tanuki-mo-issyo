/*******************************************************************************/
/**
 * @file StattusScreen.h.
 * 
 * @brief �X�e�[�^�X�X�N���[���w�b�_�t�@�C��.
 *
 * @date 2008/12/15.
 *
 * @version 1.00.
 *
 * @author Ryoma Kawasue.
 */
/*******************************************************************************/

#ifndef _STATUS_SCREEN_H_
#define _STATUS_SCREEN_H_

/*===== �C���N���[�h ==========================================================*/
#include	"IGameDevice.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"
#include	"Manager/Scene/Option/Option.h"
class		Player;
#include	"Object/GameScene/SkillPoint.h"
#include	"Object/GameScene/HitPoint.h"
#include	"Object/GameScene/Score.h"
#include    "Object/GameScene/PlayerTime.h"
#include	"Object/GameScene/NextBlock.h"


class StatusScreen : public ObjectBase
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
	StatusScreen(IGameDevice &device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState, Player& player);

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 *
	 */
	~StatusScreen();

	/*=========================================================================*/
	/**
	 * @brief ����������.
	 * 
	 */
	void Initialize();

	/*=========================================================================*/
	/**
	 * @brief �I������.
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
	void UpdateObject( float frameTimer );

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
	GameSceneState& m_gameSceneState;
	/** �v���[�� */
	Player& m_player;

	/** �X�L���|�C���g */
	SkillPoint	m_skillPoint;
	/** �q�b�g�|�C���g */
	HitPoint	m_hitPoint;
	/** �X�R�A */
	Score		m_score;
	/** �v���C���[�^�C�� */
	PlayerTime	m_playerTime;

	/** �l�N�X�g�u���b�N */
	NextBlock	m_nextBlock;

};

#endif

/*===== EOF ===================================================================*/