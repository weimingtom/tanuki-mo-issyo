/*******************************************************************************/
/*
 * @file SceneFactory.cpp.
 * 
 * @brief �V�[���t�@�N�g���N���X.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#include	"Manager/Scene/SceneFactory.h"
#include	"Define/SceneID.h"
#include	"Scene/GameScene.h"
#include	"Scene/TitleScene.h"


/*=============================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 * @param[in] device �Q�[���f�o�C�X.
 * @param[in] sceneManagerMediator �V�[���}�l�[�W�����f�B�G�[�^.
 * @param[in] Option �I�v�V����.
 */
SceneFactory::SceneFactory(IGameDevice &device, SceneManagerMediator &sceneManagerMediator, Option &option) :
	m_device(device), m_sceneManagerMediator(sceneManagerMediator), m_option(option)
{

}

/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
 */
SceneFactory::~SceneFactory()
{

}

/*=============================================================================*/
/**
 * @brief �V�[���̐���.
 * 
 * @param[in] sceneID ��������V�[��.
 * @return ���������V�[��.
 */
SceneBase* SceneFactory::CreateScene(int sceneID)
{
	SceneBase* scene = 0;
	switch(sceneID)
	{
	case SCENE_ID_GAME:
		scene = new GameScene(m_device, m_sceneManagerMediator, m_option);
		break;
	case SCENE_ID_TITLE:
		scene = new TitleScene(m_device, m_sceneManagerMediator, m_option);
		break;
	default:
		return scene;
	}
	scene->Initialize();
	return scene;
}

/*===== EOF ===================================================================*/