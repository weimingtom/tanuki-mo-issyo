/*******************************************************************************/
/*
 * @file TitleScene.cpp.
 * 
 * @brief タイトルシーンクラス定義.
 *
 * @date 2008/12/27.
 *
 * @version 1.00.
 *
 * @author Jun futagawa.
 */
/*******************************************************************************/

/*===== インクルード ==========================================================*/
#include	"Scene/TitleScene.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Define/GameDefine.h"
	
/*=============================================================================*/
/**
 * @brief コンストラクタ.
 * 
 * @param[in] device ゲームデバイス.
 * @param[in] sceneManagerMediator シーンマネージャメディエータ.
 * @param[in] option ゲームオプション.
 */
TitleScene::TitleScene(IGameDevice& device, SceneManagerMediator& sceneManagerMediator, Option& option) :
m_device(device), m_sceneManagerMediator(sceneManagerMediator), m_option(option), m_isTerminated(false)
{
	
}

/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
TitleScene::~TitleScene()
{
	delete m_objectManager;

}

/*=============================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void TitleScene::Initialize()
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
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_MAXHP,"maxhp.dds",COLORKEYFLAG_NONE);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_HP,"gauge_www.dds",COLORKEYFLAG_AUTO);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_HPBOX,"box360.dds",COLORKEYFLAG_NONE);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_SKILL,"skill.dds",COLORKEYFLAG_NONE);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_SCORE,"score.dds",COLORKEYFLAG_NONE);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_POWER,"power.dds",COLORKEYFLAG_NONE);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_GAUGE_FRONT,"gauge.dds",COLORKEYFLAG_NONE);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_GAUGE_BACK,"gaugeback.dds",COLORKEYFLAG_NONE);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_FIELD_BACKGROUND,"fd.dds",COLORKEYFLAG_NONE);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_STAND,"standtest.dds",COLORKEYFLAG_AUTO);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_BACKGROUND,"bg.dds",COLORKEYFLAG_NONE);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_ATTACK,"attacktest.dds",COLORKEYFLAG_AUTO);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_DAMAGE,"damagetest.dds",COLORKEYFLAG_AUTO);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_JUDGE,"Judge.dds",COLORKEYFLAG_AUTO);
	m_device.GetGraphicDevice().LoadTexture(TEXTUREID_READY_GO,"ReadyGo.dds",COLORKEYFLAG_AUTO);

	m_objectManager->Initialize();
//	m_backGround->Initialize();

}

/*=============================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void TitleScene::Terminate()
{
	m_objectManager->Terminate();
//	m_backGround->Terminate();
	m_isTerminated = true;
}

/*=============================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool TitleScene::IsTerminated()
{
	return m_isTerminated;
}

/*=============================================================================*/
/**
 * @brief シーンの描画処理.
 * 
 */
void TitleScene::RenderScene()
{
//	m_backGround->RenderObject();
	m_objectManager->RenderObject();

}

/*=============================================================================*/
/**
 * @brief シーンの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void TitleScene::UpdateScene(float frameTimer)
{
	m_objectManager->UpdateObject(frameTimer);
//	m_backGround->UpdateObject(frameTimer);
}

/*===== EOF ===================================================================*/
