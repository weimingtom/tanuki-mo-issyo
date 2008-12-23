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
	switch( m_player.GetPlayerParameter().GetPlayerID())
	{
	case(0):
		m_x = m_player.GetPosition().x + 300.0f;
		m_y = m_player.GetPosition().y + 130.0f;
		break;
	case(1):
		m_x = m_player.GetPosition().x + 20.0f;
		m_y = m_player.GetPosition().y + 130.0f;
		break;
	}
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
	GaugeDesc gd1;
	gd1.size = Vector2(100.0f, 20.0f);
	gd1.position = Vector2(m_x, m_y);
	gd1.textureRec1 = Rect(0,0,100,20);
	gd1.textureRec2 = Rect(0,0,100,20);
	gd1.max = 100;
	gd1.point = m_player.GetPlayerParameter().GetPlayerTime();
	gd1.texture1 = TEXTUREID_MAXHP;
	gd1.texture2 = TEXTUREID_HP;
	m_device.GetGraphicDevice().Render( gd1 );

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
