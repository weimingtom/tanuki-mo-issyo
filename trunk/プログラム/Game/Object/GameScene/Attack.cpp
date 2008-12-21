/*******************************************************************************/
/**
 * @file Attack.cpp.
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

#include "Attack.h"
#include "Player.h"

/*=========================================================================*/
/**
 * @brief コンストラクタ.
 * 
 */
Attack::Attack(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player &player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{
}
/*=========================================================================*/
/**
 * @brief デストラクタ.
 *
 */
	Attack::~Attack()
{
}

/*=========================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void Attack::Initialize()
{
	switch( m_player.GetPlayerParameter().GetPlayerID() )
	{
	case(0):
		m_x = m_player.GetPosition().x + 300.0f;
		m_y = m_player.GetPosition().y + 60.0f;
		break;
	case(1):
		m_x = m_player.GetPosition().x + 90.0f;
		m_y = m_player.GetPosition().y + 60.0f;
		break;
	}

}

/*=========================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void Attack::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool Attack::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void Attack::RenderObject()
{
	SpriteDesc sd;
	sd.textureID = TEXTUREID_POWER;

	sd.rect = Rect( m_x, m_y, m_x + BLOCK_SIZE, m_y + BLOCK_SIZE );
	m_device.GetGraphicDevice().Render( sd );

}

/*=========================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void Attack::UpdateObject(float frameTimer)
{
}

/*===== EOF ===================================================================*/
