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
	switch( m_player.GetPlayerParameter().GetPlayerID() )
	{
	case(0):
		m_x = m_player.GetPosition().x + 300.0f;
		m_y = m_player.GetPosition().y + 30.0f;
		break;
	case(1):
		m_x = m_player.GetPosition().x + 20.0f;
		m_y = m_player.GetPosition().y + 30.0f;
		break;
	}

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

	TextDesc  dt;
	dt.size		= 20;
	dt.position	= Vector2(m_x, m_y);
	dt.code		= FONT_CODE_NORMAL;
	dt.font		= "HG行書体";
	dt.string	= "防御力";
	m_device.GetGraphicDevice().Render( dt );

	GaugeDesc gd1;
	gd1.size = Vector2(100.0f, 20.0f);
	gd1.position = Vector2(m_x, m_y);
	gd1.textureRec2 = Rect(0,0,128,32);
	gd1.textureRec1 = Rect(0,32,128,64);
	gd1.max = 100;
	gd1.point = m_player.GetPlayerParameter().GetPlayerDefence();
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
void Defence::UpdateObject(float frameTimer)
{
}

/*===== EOF ===================================================================*/
