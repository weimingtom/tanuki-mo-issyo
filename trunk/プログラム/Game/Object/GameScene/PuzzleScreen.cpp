/*******************************************************************************/
/**
 * @file PuzzleScreen.cpp.
 * 
 * @brief パズルスクリーンクラスソースファイル.
 *
 * @date 2008/12/4.
 *
 * @version 1.00.
 *
 * @author ryoma kawasue.
 */
/*******************************************************************************/

#include "PuzzleScreen.h"

PuzzleScreen::PuzzleScreen(IGameDevice& device, ObjectManager& objectManager, Option &option, GameSceneState& gameSceneState, Player &player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false),
	m_blockManager(device, objectManager, option, gameSceneState, player)
{
}

/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
PuzzleScreen::~PuzzleScreen()
{
}

/*=============================================================================*/
/**
 * @brief 初期化処理.
 *
 */
void PuzzleScreen::Initialize()
{
	m_blockManager.Initialize();
}

/*=============================================================================*/
/**
 * @brief 終了しているかどうか.
 *
 */
bool PuzzleScreen::IsTerminated()
{
	return m_isTerminated;
}

/*=============================================================================*/
/**
 * @brief オブジェクトの描画処理.
 *
 */
void PuzzleScreen::RenderObject()
{
	m_blockManager.RenderObject();
}

/*=============================================================================*/
/**
 * @brief 終了処理.
 *
 */
void PuzzleScreen::Terminate()
{
	m_isTerminated = true; 
}

/*=============================================================================*/
/**
 * @brief オブジェクトの更新処理.
 *
 */
void PuzzleScreen::UpdateObject(float frameTimer)
{
	m_blockManager.UpdateObject(frameTimer);
}

BlockManager&	PuzzleScreen::GetBlockManager()
{
	return	m_blockManager;
}
/*===== EOF ===================================================================*/