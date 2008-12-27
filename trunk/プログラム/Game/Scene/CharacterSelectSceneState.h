/*******************************************************************************/
/**
 * @file CharacterSelectSceneState.h.
 * 
 * @brief �Q�[���Z���N�g�V�[����ԃN���X��`.
 *
 * @date 2008/12/27.
 *
 * @version 1.00.
 *
 * @author Ryoma Kawasue.
 */
/*******************************************************************************/
#ifndef _CHARACTER_SELECT_SCENE_STATE_H_
#define _CHARACTER_SELECT_SCENE_STATE_H_

/*===== �C���N���[�h ==========================================================*/
#include	<vector>
#include	"Manager/Object/ObjectManager.h"


/**
 * @brief CharacterSelectSceneState�D
 */
class CharacterSelectSceneState
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^.
	 * 
	 */
	CharacterSelectSceneState(ObjectManager& objectManager);
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 *
	 */
	~CharacterSelectSceneState();

private:

	/** �I�u�W�F�N�g�}�l�[�W�� */
	ObjectManager& m_objectManager;

};

#endif

/*===== EOF ===================================================================*/