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
#include	"Scene/Factory/GameSceneObjectFactory.h"
#include	"Object/GameScene/Player.h"
#include	"Define/GameSceneObjectID.h"


/*=============================================================================*/
/**
 * @brief コンストラクタ.
 * 
 * @param[in] device ゲームデバイス.
 * @param[in] sceneManagerMediator シーンマネージャメディエータ.
 * @param[in] option ゲームオプション.
 */
GameScene::GameScene(IGameDevice &device, SceneManagerMediator &sceneManagerMediator, Option &option) :
	m_device(device), m_sceneManagerMediator(sceneManagerMediator), m_option(option), m_isTerminated(false)
{
	m_objectManager.SetFactory(new GameSceneObjectFactory(device,m_objectManager,m_option,m_state));
	m_objectManager.AddObject(GAME_SCENE_OBJECT_ID_PLAYER);
}

/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
GameScene::~GameScene()
{

}

/*=============================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void GameScene::Initialize()
{
	m_objectManager.Initialize();
}

/*=============================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void GameScene::Terminate()
{
	m_objectManager.Terminate();
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
	m_objectManager.RenderObject();
}

/*=============================================================================*/
/**
 * @brief シーンの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void GameScene::UpdateScene(float frameTimer)
{
	m_objectManager.UpdateObject(frameTimer);
}

/*===== EOF ===================================================================*/