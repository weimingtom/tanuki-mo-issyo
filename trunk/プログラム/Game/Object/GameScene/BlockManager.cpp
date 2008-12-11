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
BlockManager::BlockManager(IGameDevice& device, ObjectManager& objectManager, Option &option, GameSceneState& gameSceneState, Player& player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false),
		m_field(device, objectManager, option, gameSceneState, player)
{
	m_block = new Block(device, objectManager, option, gameSceneState, player,1,1 );
	m_fallBlock = new FallBlock(device, objectManager, option, gameSceneState, player);
}

/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
BlockManager::~BlockManager()
{
	if(m_block){
		delete m_block;
	}
	if(m_fallBlock){
		delete m_fallBlock;
	}
}

/*=============================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void BlockManager::Initialize()
{
	if(m_block){
		m_block->Initialize();
	}
	if(m_fallBlock){
		m_fallBlock->Initialize();
	}
	m_field.Initialize();
}

/*=============================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void BlockManager::Terminate()
{
	m_isTerminated = true;
	if(m_block){
		m_block->Terminate();
	}
	if(m_fallBlock){
		m_fallBlock->Terminate();
	}
	m_field.Terminate();
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
	if(m_block){
		m_block->RenderObject();
	}
	if(m_fallBlock){
		m_fallBlock->RenderObject();
	}
	m_field.RenderObject();
}

/*=============================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void BlockManager::UpdateObject(float frameTimer)
{
	if(m_block){
		m_block->UpdateObject(frameTimer);
	}
	if(m_fallBlock){
		m_fallBlock->UpdateObject(frameTimer);
	}
	m_field.UpdateObject(frameTimer);
}

/*===== EOF ===================================================================*/