/*******************************************************************************/
/**
 * @file Avatar.h.
 * 
 * @brief �A�o�^�[�N���X�w�b�_.
 *
 * @date 2008/12/11.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/
#ifndef _AVATAR_H_
#define _AVATAR_H_

#include	"IGameDevice.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"
#include	"Manager/Scene/Option/Option.h"
class		Player;


/**
 * @brief Avater�D
 */
class Avatar : public ObjectBase
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^.
	 *
	 */
	Avatar(IGameDevice& device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState, Player& player);

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 *
	 */
	~Avatar();

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

};

#endif

/*===== EOF ===================================================================*/
