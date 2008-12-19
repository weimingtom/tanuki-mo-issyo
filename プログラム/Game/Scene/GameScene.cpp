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
#include	"Object/GameScene/FallBlock.h"
#include	"Define/GameDefine.h"
	
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
	int skill[4] = {1,2,3,4};
	m_objectManager->AddObject(m_objectManager->GetObjectFactory().CreatePlayer(
		m_state,100.0f, 50.0f, 500, skill, 30, TEXTUREID_AVATAR2, 12000, 0, 5, 15, 20, TEXTUREID_SBLOCK1));
	
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

	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_AVATAR1, "avatar1.dds", COLORKEYFLAG_NONE);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_AVATAR2, "avatar2.dds", COLORKEYFLAG_NONE);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_BLOCK1,"block1.dds",COLORKEYFLAG_NONE);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_BLOCK2,"block2.dds",COLORKEYFLAG_NONE);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_BLOCK3,"block3.dds",COLORKEYFLAG_NONE);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_SBLOCK1,"sblock1.dds",COLORKEYFLAG_NONE);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_SBLOCK2,"sblock2.dds",COLORKEYFLAG_NONE);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_SBLOCK3,"sblock3.dds",COLORKEYFLAG_NONE);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_SBLOCK4,"sblock4.dds",COLORKEYFLAG_NONE);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_HP,"hp.dds",COLORKEYFLAG_NONE);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_SKILL,"skill.dds",COLORKEYFLAG_NONE);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_SCORE,"score.dds",COLORKEYFLAG_NONE);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_POWER,"power.dds",COLORKEYFLAG_NONE);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_GAUGE_FRONT,"gauge.dds",COLORKEYFLAG_NONE);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_GAUGE_BACK,"gaugeback.dds",COLORKEYFLAG_NONE);

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
