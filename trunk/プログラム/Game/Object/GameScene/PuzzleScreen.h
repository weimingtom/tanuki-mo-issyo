/*******************************************************************************/
/**
 * @file PuzzleScreen.h.
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

#ifndef _PUZZLESCREEN_H_
#define _PUZZLESCREEN_H_

#include	"IGameDevice.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"
#include	"Manager/Scene/Option/Option.h"
#include	"Object/GameScene/BlockManager.h"
#include "Object/ObjectBase.h"
class		Player;

class PuzzleScreen : public ObjectBase
{
public:
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^.
	 *
	 */
	PuzzleScreen(IGameDevice& device, ObjectManager& objectManager, 
				 Option& option, GameSceneState& gameSceneState , Player& player);
	/*=========================================================================*/

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 *
	 */
	~PuzzleScreen();				//�_�C���n�E�X
	/*=========================================================================*/

	/*=========================================================================*/
	/**
	 * @brief .����������
	 *
	 */
	void Initialize();
	/*=========================================================================*/


	/*=========================================================================*/
	/**
	 * @brief �I�����Ă��邩�ǂ���.
	 *
	 * @return �I���t���O
	 */
	bool IsTerminated();
	/*=========================================================================*/


	/*=========================================================================*/
	/**
	 * @brief �I�u�W�F�N�g�̕`�揈��.
	 *
	 */
	void RenderObject();
	/*=========================================================================*/


	/*=========================================================================*/
	/**
	 * @brief �I������.
	 *
	 */
	void Terminate();
	/*=========================================================================*/

	/*=========================================================================*/
	/**
	 * @brief �I�u�W�F�N�g�̍X�V����.
	 *
	 * @param[in] frameTimer �X�V�喃
	 */
	void UpdateObject(float frameTimer);
	/*=========================================================================*/

	BlockManager&	GetBlockManager(); 

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

	/** �u���b�N�}�l�[�W�� */
	BlockManager m_blockManager;



};

#endif

/*===== EOF ===================================================================*/