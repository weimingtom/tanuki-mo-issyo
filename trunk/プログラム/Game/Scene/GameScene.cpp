/*******************************************************************************/
/*
 * @file GameScene.cpp.
 * 
 * @brief ゲームシーンクラス定義.
 *
 * @date 2008/11/27.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/

/*===== インクルード ==========================================================*/
#include	"Scene/GameScene.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Object/GameScene/Player.h"


/*=============================================================================*/
/**
 * @brief コンストラクタ.
 * 
 * @param[in] device ゲームデバイス.
 * @param[in] sceneManagerMediator シーンマネージャメディエータ.
 * @param[in] option ゲームオプション.
 */
GameScene::GameScene(IGameDevice& device, SceneManagerMediator& sceneManagerMediator, Option& option) :
	m_device(device), m_sceneManagerMediator(sceneManagerMediator), m_option(option), m_isTerminated(false), m_state()
{
	m_objectManager = new ObjectManager(device,option);
	m_objectManager->AddObject(m_objectManager->GetObjectFactory().CreatePlayer(m_state));
}

/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
GameScene::~GameScene()
{
	delete m_objectManager;
}

/*=============================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void GameScene::Initialize()
{
	m_objectManager->Initialize();
}

/*=============================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void GameScene::Terminate()
{
	m_objectManager->Terminate();
	m_isTerminated = true;
}

/*=============================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool GameScene::IsTerminated()
{
	return m_isTerminated;
}

/*=============================================================================*/
/**
 * @brief シーンの描画処理.
 * 
 */
void GameScene::RenderScene()
{
	m_objectManager->RenderObject();
}

/*=============================================================================*/
/**
 * @brief シーンの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void GameScene::UpdateScene(float frameTimer)
{
	m_objectManager->UpdateObject(frameTimer);
}

/*===== EOF ===================================================================*/