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
 * @param[in] objectManager オブジェクトマネージャ.
 * @param[in] option ゲームオプション.
 * @param[in] gameSceneState ゲームシーンステート.
 */
Player::Player(IGameDevice& device, ObjectManager& objectManager, Option &option, GameSceneState& gameSceneState, float x, float y) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_isTerminated(false), m_x(x), m_y(y),
		m_puzzleScreen(device,objectManager,option,gameSceneState, *this),
		m_characterScreen(device,objectManager,option,gameSceneState, *this),
		m_statusScreen(device,objectManager,option,gameSceneState, *this)
		
{
	m_gameSceneState.AddPlayer(this);
	
}

/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
Player::~Player()
{
	
}

/*=============================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void Player::Initialize()
{

	m_puzzleScreen.Initialize();
	m_characterScreen.Initialize();
	m_statusScreen.Initialize();
}

/*=============================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void Player::Terminate()
{

	m_puzzleScreen.Terminate();
	m_characterScreen.Terminate();
	m_statusScreen.Terminate();
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
	m_puzzleScreen.RenderObject();
	m_characterScreen.RenderObject();
	m_statusScreen.RenderObject();
}

/*=============================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void Player::UpdateObject(float frameTimer)
{

	m_puzzleScreen.UpdateObject(frameTimer);
	m_characterScreen.UpdateObject(frameTimer);
	m_statusScreen.UpdateObject(frameTimer);

}

Vector2 Player::GetPosition()
{
	return Vector2(m_x,m_y);
}

PuzzleScreen& Player::GetPuzzleScreen()
{
	return m_puzzleScreen;
}

/*===== EOF ===================================================================*/