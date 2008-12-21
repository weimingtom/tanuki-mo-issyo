/*******************************************************************************/
/**
 * @file Defence.cpp.
 * 
 * @brief アタッククラスソース定義.
 *
 * @date 2008/12/21.
 *
 * @version 1.00.
 *
 * @author Ryouma Kawasue.
 */
/*******************************************************************************/

#include "Defence.h"
#include "Player.h"

/*=========================================================================*/
/**
 * @brief コンストラクタ.
 * 
 */
Defence::Defence(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player &player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{
}
/*=========================================================================*/
/**
 * @brief デストラクタ.
 *
 */
	Defence::~Defence()
{
}

/*=========================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void Defence::Initialize()
{
	m_x = m_player.GetPosition().x + 300.0f;
	m_y = m_player.GetPosition().y + 20.0f;

}

/*=========================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void Defence::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool Defence::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void Defence::RenderObject()
{
	SpriteDesc sd;
	sd.textureID = TEXTUREID_POWER;

	sd.rect = Rect( m_x, m_y, m_x + 256, m_y + BLOCK_SIZE );
	m_device.GetGraphicDevice().Render( sd );

}

/*=========================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void Defence::UpdateObject(float frameTimer)
{
}

/*===== EOF ===================================================================*/
