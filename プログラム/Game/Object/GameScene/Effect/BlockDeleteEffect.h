/*******************************************************************************/
/**
 * @file BlockDeleteEffect.h.
 * 
 * @brief �t�H�[���u���b�N�N���X�w�b�_��`.
 *
 * @date 2008/12/8.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/
#ifndef _BLOCK_DELETE_EFFECT_H_
#define _BLOCK_DELETE_EFFECT_H_

#include	"IGameDevice.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"
#include	"Manager/Scene/Option/Option.h"
#include	"Object/ObjectBase.h"
class		Player;

/**
 * @brief ObjectBase�D
 */
class BlockDeleteEffect : public ObjectBase
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 *
	 */
	BlockDeleteEffect(IGameDevice& device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState, Player& player, float x, float y,int blockID);

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 * 
	 */
	~BlockDeleteEffect();

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

	IntPoint GetFieldMatrixPosition(float x, float y);

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

	/**	�u���b�NID */
	int m_blockID;
	/** �k���X�s�[�h */
	float m_speed;
	/** �`��T�C�Y */
	float m_size;
	/** �폜�^�C�} */
	float m_timer;
	/** y���W�@*/
	float m_y;
	/** x���W�@*/
	float m_x;

};

#endif

/*===== EOF ===================================================================*/
