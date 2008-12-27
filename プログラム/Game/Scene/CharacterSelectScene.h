/*******************************************************************************/
/**
 * @file CharacterSelectScene.h.
 * 
 * @brief �L�����N�^�[�Z���N�g�V�[���N���X�w�b�_��`.
 *
 * @date 2008/12/27.
 *
 * @version 1.00.
 *
 * @author Ryoma Kawasue.
 */
/*******************************************************************************/
#ifndef _CHARACTER_SELECT_SCENE_H_
#define _CHARACTER_SELECT_SCENE_H_

/*===== �C���N���[�h ==========================================================*/
#include	"Scene/SceneBase.h"
#include	"IGameDevice.h"
#include	"Manager/Scene/SceneManagerMediator.h"
#include	"Manager/Scene/Option/Option.h"
#include	"Scene/CharacterSelectSceneState.h"
#include	"Manager/Object/ObjectManager.h"

/**
 * @brief CharacterSelectScene�D
 */
class CharacterSelectScene : public SceneBase
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^.
	 */
	CharacterSelectScene(IGameDevice& device, SceneManagerMediator& sceneManagerMediator, Option& option);
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 *
	 */
	~CharacterSelectScene();

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
	/** �I���t���O */
	bool							m_isTerminated;
	/** �V�[���}�l�[�W�����f�B�G�[�^ */
	SceneManagerMediator&			m_sceneManagerMediator;
	/** �Q�[���I�v�V���� */
	Option&							m_option;
	/** �I�u�W�F�N�g�}�l�[�W�� */
	ObjectManager*					m_objectManager;
	/**�L�����N�^�[�Z���N�g�V�[���X�e�[�g�@*/
	CharacterSelectSceneState*		m_characterSelectSceneState;

};

#endif

/*===== EOF ===================================================================*/