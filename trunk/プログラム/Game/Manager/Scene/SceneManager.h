/*******************************************************************************/
/**
 * @file SceneManager.h.
 * 
 * @brief �V�[���}�l�[�W���N���X��`.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

/*===== �C���N���[�h ==========================================================*/
#include	<vector>
#include	"IGameDevice.h"
#include	"Manager/Scene/SceneManagerMediator.h"
#include	"Manager/Scene/SceneFactory.h"
#include	"Scene/SceneBase.h"
#include	"Manager/Scene/Option/Option.h"


/**
 * @brief SceneManager�D
 */
class SceneManager : public SceneManagerMediator
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^.
	 * 
	 * @param[in] device �Q�[���f�o�C�X.
	 * @param[in] sceneID �����V�[��.
	 */
	SceneManager(IGameDevice& device, int sceneID);
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 *
	 */
	~SceneManager();

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
	 * @brief �V�[���̕ύX.
	 * 
	 * @param[in] sceneID �ύX����V�[��.
	 */
	void ChangeScene(int sceneID);
	/*=========================================================================*/
	/**
	 * @brief �V�[���̌Ăяo��.
	 * 
	 * @param[in] sceneID �Ăяo���V�[��.
	 */
	void CallScene(int sceneID);
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
	IGameDevice& m_device;
	/** �V�[���t�@�N�g�� */
	SceneFactory* m_sceneFactory;
	/** ���݂̃V�[�� */
	SceneBase* m_currentScene;
	/** �X�g�b�N�����V�[�� */
	std::vector<SceneBase*> m_stockScene;
	/** �I���t���O */
	bool m_isTerminated;
	/** �Q�[���I�v�V���� */
	Option m_option;
};

#endif