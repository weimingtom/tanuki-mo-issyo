/*******************************************************************************/
/*
 * @file CharacterSelectScene.cpp.
 * 
 * @brief ゲームシーンクラス定義.
 *
 * @date 2008/11/27.
 *
 * @version 1.00.
 *
 * @author Ryoma Kawasue.
 */
/*******************************************************************************/

/*===== インクルード ==========================================================*/
#include	"Scene/CharacterSelectScene.h"
	
/*=============================================================================*/
/**
 * @brief コンストラクタ.
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
 * @brief デストラクタ.
 *
 */
CharacterSelectScene::~CharacterSelectScene()
{
	delete m_objectManager;
	delete m_characterSelectSceneState;
}

/*=============================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void CharacterSelectScene::Initialize()
{
	m_objectManager->Initialize();
}

/*=============================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void CharacterSelectScene::Terminate()
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
bool CharacterSelectScene::IsTerminated()
{
	return m_isTerminated;
}

/*=============================================================================*/
/**
 * @brief シーンの描画処理.
 * 
 */
void CharacterSelectScene::RenderScene()
{
	m_objectManager->RenderObject();
	m_objectManager->RenderEffect();
}

/*=============================================================================*/
/**
 * @brief シーンの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void CharacterSelectScene::UpdateScene(float frameTimer)
{
	m_objectManager->UpdateObject(frameTimer);
	m_objectManager->UpdateEffect(frameTimer);
}

/*===== EOF ===================================================================*/
