/*******************************************************************************/
/**
 * @file GameScene.h.
 * 
 * @brief �Q�[���V�[���N���X��`.
 *
 * @date 2008/11/27.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

/*===== �C���N���[�h ==========================================================*/
#include	"Scene/SceneBase.h"
#include	"IGameDevice.h"
#include	"Manager/Scene/SceneManagerMediator.h"
#include	"Manager/Scene/Option/Option.h"
#include	"Scene/GameSceneState.h"


/**
 * @brief GameScene�D
 */
class GameScene : public SceneBase
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^.
	 * 
	 * @param[in] device �Q�[���f�o�C�X.
	 * @param[in] sceneManagerMediator �V�[���}�l�[�W�����f�B�G�[�^.
	 * @param[in] option �Q�[���I�v�V����.
	 */
	GameScene(IGameDevice& device, SceneManagerMediator& sceneManagerMediator, Option& option);
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 *
	 */
	~GameScene();

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
	 * @brief �V�[���̕`�揈��.
	 * 
	 */
	void RenderScene();
	/*=========================================================================*/
	/**
	 * @brief �V�[���̍X�V����.
	 * 
	 * @param[in] frameTimer �X�V�^�C�}.
	 */
	void UpdateScene(float frameTimer);

private:

	/** �Q�[���f�o�C�X */
	IGameDevice&					m_device;
	/** �V�[���}�l�[�W�����f�B�G�[�^ */
	SceneManagerMediator&			m_sceneManagerMediator;
	/** �Q�[���I�v�V���� */
	Option&							m_option;
	/** �I���t���O */
	bool							m_isTerminated;
	/** �V�[���X�e�[�g */
	GameSceneState					m_state;

};

#endif

/*===== EOF ===================================================================*/