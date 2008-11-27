/*******************************************************************************/
/*
 * @file Player.cpp.
 * 
 * @brief プレーヤークラス定義.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/

/*===== インクルード ==========================================================*/
#include	"Object/GameScene/Player.h"


/*=============================================================================*/
/**
 * @brief コンストラクタ.
 * 
 * @param[in] device ゲームデバイス.
 * @param[in] objectManagerMediator オブジェクトマネージャメディエータ.
 * @param[in] option ゲームオプション.
 * @param[in] gameSceneState ゲームシーンステート.
 */
Player::Player(IGameDevice& device, ObjectManagerMediator& objectManagerMediator, Option &option, GameSceneState& gameSceneState) :
	m_device(device), m_objectManagerMediator(objectManagerMediator), m_option(option), m_gameSceneState(gameSceneState), m_isTerminated(false)
{
	m_gameSceneState.AddPlayer(this);
	m_block = new Block(device,objectManagerMediator,option,gameSceneState);
}

/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
Player::~Player()
{
	delete m_block;
}

/*=============================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void Player::Initialize()
{
	m_block->Initialize();
}

/*=============================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void Player::Terminate()
{
	m_block->Terminate();
	m_isTerminated = true;
}

/*=============================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool Player::IsTerminated()
{
	return m_isTerminated;
}

/*=============================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void Player::RenderObject()
{
	m_block->RenderObject();
}

/*=============================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void Player::UpdateObject(float frameTimer)
{
	m_block->UpdateObject(frameTimer);
}

/*===== EOF ===================================================================*/