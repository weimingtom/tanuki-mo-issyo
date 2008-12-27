/*******************************************************************************/
/*
 * @file CharacterSelectScene.cpp.
 * 
 * @brief �Q�[���V�[���N���X��`.
 *
 * @date 2008/11/27.
 *
 * @version 1.00.
 *
 * @author Ryoma Kawasue.
 */
/*******************************************************************************/

/*===== �C���N���[�h ==========================================================*/
#include	"Scene/CharacterSelectScene.h"
	
/*=============================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 

 */
CharacterSelectScene::CharacterSelectScene(IGameDevice& device, SceneManagerMediator& sceneManagerMediator, Option& option) :
	m_device(device), m_isTerminated(false), m_sceneManagerMediator(sceneManagerMediator), m_option(option)

{
	m_objectManager = new ObjectManager(device, option);
	m_characterSelectSceneState = new CharacterSelectSceneState(*m_objectManager);
}

/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
CharacterSelectScene::~CharacterSelectScene()
{
	delete m_objectManager;
	delete m_characterSelectSceneState;
}

/*=============================================================================*/
/**
 * @brief ����������.
 * 
 */
void CharacterSelectScene::Initialize()
{
	m_objectManager->Initialize();
}

/*=============================================================================*/
/**
 * @brief �I������.
 * 
 */
void CharacterSelectScene::Terminate()
{
	m_objectManager->Terminate();
	m_isTerminated = true;
}

/*=============================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool CharacterSelectScene::IsTerminated()
{
	return m_isTerminated;
}

/*=============================================================================*/
/**
 * @brief �V�[���̕`�揈��.
 * 
 */
void CharacterSelectScene::RenderScene()
{
	m_objectManager->RenderObject();
	m_objectManager->RenderEffect();
}

/*=============================================================================*/
/**
 * @brief �V�[���̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void CharacterSelectScene::UpdateScene(float frameTimer)
{
	m_objectManager->UpdateObject(frameTimer);
	m_objectManager->UpdateEffect(frameTimer);
}

/*===== EOF ===================================================================*/
