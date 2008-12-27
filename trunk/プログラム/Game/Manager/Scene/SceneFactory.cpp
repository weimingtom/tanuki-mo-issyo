/*******************************************************************************/
/*
 * @file SceneFactory.cpp.
 * 
 * @brief シーンファクトリクラス.
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
 * @brief コンストラクタ.
 * 
 * @param[in] device ゲームデバイス.
 * @param[in] sceneManagerMediator シーンマネージャメディエータ.
 * @param[in] Option オプション.
 */
SceneFactory::SceneFactory(IGameDevice &device, SceneManagerMediator &sceneManagerMediator, Option &option) :
	m_device(device), m_sceneManagerMediator(sceneManagerMediator), m_option(option)
{

}

/*=============================================================================*/
/**
 * @brief デストラクタ.
 */
SceneFactory::~SceneFactory()
{

}

/*=============================================================================*/
/**
 * @brief シーンの生成.
 * 
 * @param[in] sceneID 生成するシーン.
 * @return 生成したシーン.
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