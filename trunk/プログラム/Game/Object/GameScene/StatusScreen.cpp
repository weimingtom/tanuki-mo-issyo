/*******************************************************************************/
/*
 * @file StatusScreen.cpp.
 * 
 * @brief ステーターススクリーンソースファイル.
 *
 * @date 2008/12/15.
 *
 * @version 1.00.
 *
 * @author Ryouma Kawasue.
 */
/*******************************************************************************/

/*===== インクルード ==========================================================*/
#include	"StatusScreen.h"

/*=============================================================================*/
/**
 * @brief コンストラクタ.
 * 
 * @param[in] device ゲームデバイス.
 * @param[in] objectManager オブジェクトマネージャ.
 * @param[in] option ゲームオプション.
 * @param[in] gameSceneState ゲームシーンステート.
 */
StatusScreen::StatusScreen(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player &player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{
}

/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
StatusScreen::~StatusScreen()
{
}

/*=============================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void StatusScreen::Initialize()
{

}

/*=============================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void StatusScreen::Terminate()
{
	m_isTerminated = true;
}

/*=============================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool StatusScreen::IsTerminated()
{
	return m_isTerminated;
}

/*=============================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void StatusScreen::RenderObject()
{
	float m_x = 400.0f;
	float m_y = 300.0f;

	SpriteDesc sd;
	sd.textureID = TEXTUERID_POWER;

	sd.rect = Rect(m_x, m_y, m_x+256, m_y+256 );
	m_device.GetGraphicDevice().Render( sd );
}

/*=============================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void StatusScreen::UpdateObject(float frameTimer)
{

}

/*===== EOF ===================================================================*/
