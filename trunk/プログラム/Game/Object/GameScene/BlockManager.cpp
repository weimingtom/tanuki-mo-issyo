/*******************************************************************************/
/*
 * @file BlockManager.cpp.
 * 
 * @brief ブロックマネージャークラス(空).
 *
 * @date 2008/12/04.
 *
 * @version 1.00.
 *
 * @author Tsubasa Uragami.
 */
/*******************************************************************************/

/*===== インクルード ==========================================================*/

#include	"BlockManager.h"

/*=============================================================================*/
/**
 * @brief コンストラクタ.
 * 
 * @param[in] device ゲームデバイス.
 * @param[in] objectManager オブジェクトマネージャ.
 * @param[in] option ゲームオプション.
 * @param[in] gameSceneState ゲームシーンステート.
 */
BlockManager::BlockManager(IGameDevice& device, ObjectManager& objectManager, Option &option, GameSceneState& gameSceneState) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_isTerminated(false)
{
}

/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
BlockManager::~BlockManager()
{
}

/*=============================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void BlockManager::Initialize()
{
}

/*=============================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void BlockManager::Terminate()
{
	m_isTerminated = true;
}

/*=============================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool BlockManager::IsTerminated()
{
	return m_isTerminated;
}

/*=============================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void BlockManager::RenderObject()
{
}

/*=============================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void BlockManager::UpdateObject(float frameTimer)
{
}

/*===== EOF ===================================================================*/