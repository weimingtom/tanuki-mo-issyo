/*******************************************************************************/
/**
 * @file PlayerAction.h.
 * 
 * @brief �p�Y���X�N���[���N���X�w�b�_�t�@�C��.
 *
 * @date 2008/12/4.
 *
 * @version 1.00.
 *
 * @author ryoma kawasue.
 */
/*******************************************************************************/

#ifndef _PLAYERACTION_H_
#define _PLAYERACTION_H_

#include	"IGameDevice.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Scene/GameSceneState.h"
#include	"Manager/Scene/Option/Option.h"
class		Player;

class PlayerAction
{
public:
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^.
	 *
	 */
	PlayerAction(IGameDevice& device, ObjectManager& objectManager, 
				 Option& option, GameSceneState& gameSceneState , Player& player);
	/*=========================================================================*/

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 *
	 */
	~PlayerAction();				//�_�C���n�E�X
	/*=========================================================================*/

	/*=========================================================================*/
	/**
	 * @brief .����������
	 *
	 */
	void Initialize();
	/*=========================================================================*/

	void Attack(Player& player);
	void Damage(int damage);

private:

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