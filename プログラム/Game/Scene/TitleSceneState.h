/*******************************************************************************/
/**
 * @file TitleSceneState.h.
 * 
 * @brief �^�C�g���V�[����ԃN���X��`.
 *
 * @date 2008/12/27.
 *
 * @version 1.00.
 *
 * @author Jun Futagawa.
 */
/*******************************************************************************/
#ifndef _TITLE_SCENE_STATE_H_
#define _TITLE_SCENE_STATE_H_

/*===== �C���N���[�h ==========================================================*/
#include	<vector>
class		Player;
#include	"Manager/Object/ObjectManager.h"


/**
 * @brief TitleSceneState�D
 */
class TitleSceneState
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^.
	 * 
	 */
	TitleSceneState(ObjectManager& objectManager);
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 *
	 */
	~TitleSceneState();




private:

	/** �I�u�W�F�N�g�}�l�[�W�� */
	ObjectManager& m_objectManager;


	/** �Q�[���X�e�[�g */
	int m_titleState;
};

#endif

/*===== EOF ===================================================================*/