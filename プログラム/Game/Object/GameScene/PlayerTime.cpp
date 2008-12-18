/*******************************************************************************/
/**
 * @file PlayerTime.cpp.
 * 
 * @brief プレイヤータイムクラスソース定義.
 *
 * @date 2008/12/18.
 *
 * @version 1.00.
 *
 * @author Ryouma Kawasue.
 */
/*******************************************************************************/

#include "PlayerTime.h"
#include "Player.h"

/*=========================================================================*/
/**
 * @brief コンストラクタ.
 * 
 */
PlayerTime::PlayerTime(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player &player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{
}
/*=========================================================================*/
/**
 * @brief デストラクタ.
 *
 */
PlayerTime::~PlayerTime()
{
}

/*=========================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void PlayerTime::Initialize()
{
	m_x = m_player.GetPosition().x + 305.0f;
	m_y = m_player.GetPosition().y + 450.0f;

}

/*=========================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void PlayerTime::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool PlayerTime::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void PlayerTime::RenderObject()
{
	SpriteDesc sd;
	sd.textureID = TEXTUREID_AVATAR1;

	sd.rect = Rect( m_x, m_y, m_x + BLOCK_SIZE, m_y + BLOCK_SIZE );
	m_device.GetGraphicDevice().Render( sd );

}

/*=========================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void PlayerTime::UpdateObject(float frameTimer)
{
}

/*===== EOF ===================================================================*/
