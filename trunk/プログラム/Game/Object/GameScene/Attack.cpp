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
		/*
		m_x = m_player.GetPosition().x + 300.0f;
		m_y = m_player.GetPosition().y + 60.0f;
		*/
		m_x = m_option.m_attackSpriteInfo.position.x;
		m_y = m_option.m_attackSpriteInfo.position.y;
		break;
	case(1):
		m_x = m_player.GetPosition().x + 20.0f;
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
	//アタックゲージ

	TextDesc at1;
	at1.code = FONT_CODE_NORMAL;
	at1.font = "HGP明朝B";
	at1.position = Vector2(m_x+22.5f,m_y);
	at1.size = 20;
	at1.string = "攻撃力";
	m_device.GetGraphicDevice().Render( at1 );


	GaugeDesc gd1;
	gd1.size = Vector2(m_option.m_attackSpriteInfo.size.x, m_option.m_attackSpriteInfo.size.y);
	gd1.position = Vector2(m_x, m_y);
	gd1.textureRec2 = Rect(0,0,128,32);
	gd1.textureRec1 = Rect(0,32,128,64);
	gd1.max = 100;
	gd1.point = (float)m_player.GetPlayerParameter().GetPlayerAttack();
	gd1.texture1 = TEXTUREID_HP;
	gd1.texture2 = TEXTUREID_HP;
	m_device.GetGraphicDevice().Render( gd1 );

	

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
