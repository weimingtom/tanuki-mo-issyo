/*******************************************************************************/
/*
 * @file GameScene.cpp.
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

/*===== �C���N���[�h ==========================================================*/
#include	"Scene/GameScene.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Object/GameScene/Player.h"


/*=============================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 * @param[in] device �Q�[���f�o�C�X.
 * @param[in] sceneManagerMediator �V�[���}�l�[�W�����f�B�G�[�^.
 * @param[in] option �Q�[���I�v�V����.
 */
GameScene::GameScene(IGameDevice& device, SceneManagerMediator& sceneManagerMediator, Option& option) :
	m_device(device), m_sceneManagerMediator(sceneManagerMediator), m_option(option), m_isTerminated(false), m_state()
{
	m_objectManager = new ObjectManager(device,option);
	m_objectManager->AddObject(m_objectManager->GetObjectFactory().CreatePlayer(m_state));
}

/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
GameScene::~GameScene()
{
	delete m_objectManager;
}

/*=============================================================================*/
/**
 * @brief ����������.
 * 
 */
void GameScene::Initialize()
{
	m_objectManager->Initialize();
}

/*=============================================================================*/
/**
 * @brief �I������.
 * 
 */
void GameScene::Terminate()
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
bool GameScene::IsTerminated()
{
	return m_isTerminated;
}

/*=============================================================================*/
/**
 * @brief �V�[���̕`�揈��.
 * 
 */
void GameScene::RenderScene()
{
	m_objectManager->RenderObject();
}

/*=============================================================================*/
/**
 * @brief �V�[���̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void GameScene::UpdateScene(float frameTimer)
{
	m_objectManager->UpdateObject(frameTimer);
}

/*===== EOF ===================================================================*/