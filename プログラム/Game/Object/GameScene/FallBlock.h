/*******************************************************************************/
/**
 * @file FallBlock.h.
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
#ifndef _FALL_BLOCK_H_
#define _FALL_BLOCK_H_

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
class FallBlock : public ObjectBase
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 *
	 */
	FallBlock(IGameDevice& device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState, Player& player);

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 * 
	 */
	~FallBlock();

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
	int blockID;
	/** �����X�s�[�h */
	float m_speed;
	/** y���W�@*/
	float m_y;
	/** x���W�@*/
	float m_x;

};

#endif

/*===== EOF ===================================================================*/
