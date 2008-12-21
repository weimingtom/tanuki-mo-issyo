/*******************************************************************************/
/**
 * @file StatusScreen.cpp.
 * 
 * @brief ステータススクリーンクラスソース定義.
 *
 * @date 2008/12/15.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
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
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false),
		m_skillPoint(device,objectManager,option,gameSceneState, m_player),
		m_hitPoint(device,objectManager,option,gameSceneState, m_player),
		m_score(device,objectManager,option,gameSceneState, m_player),
		m_playerTime(device,objectManager,option,gameSceneState, m_player),
		m_nextBlock(device, objectManager, option, gameSceneState, m_player),
		m_attack(device, objectManager, option, gameSceneState, m_player),
		m_defence(device, objectManager, option, gameSceneState, m_player)
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
	m_skillPoint.Initialize();
	m_hitPoint.Initialize();
	m_score.Initialize();
	m_playerTime.Initialize();
	m_nextBlock.Initialize();
	m_attack.Initialize();
	m_defence.Initialize();
}

/*=============================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void StatusScreen::Terminate()
{
	m_skillPoint.Terminate();
	m_hitPoint.Terminate();
	m_score.Terminate();
	m_playerTime.Terminate();
	m_nextBlock.Terminate();
	m_attack.Terminate();
	m_defence.Terminate();
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
	m_skillPoint.RenderObject();
	m_hitPoint.RenderObject();
	m_score.RenderObject();
	m_playerTime.RenderObject();
	m_nextBlock.RenderObject();
	m_attack.RenderObject();
	m_defence.RenderObject();
}

/*=============================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void StatusScreen::UpdateObject(float frameTimer)
{
	m_skillPoint.UpdateObject(frameTimer);
	m_hitPoint.UpdateObject(frameTimer);
	m_score.UpdateObject(frameTimer);
	m_playerTime.UpdateObject(frameTimer);
	m_nextBlock.UpdateObject(frameTimer);
	m_attack.UpdateObject(frameTimer);
	m_defence.UpdateObject(frameTimer);
}


/*===== EOF ===================================================================*/
