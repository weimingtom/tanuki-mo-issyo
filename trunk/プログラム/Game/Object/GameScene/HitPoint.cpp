/*******************************************************************************/
/**
 * @file HitPoint.cpp.
 * 
 * @brief ヒットポイントクラスソース定義.
 *
 * @date 2008/12/15.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/

#include	"HitPoint.h"
#include	"Player.h"

/*=========================================================================*/
/**
 * @brief コンストラクタ.
 * 
 */
HitPoint::HitPoint(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player& player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{
	m_player.GetPlayerParameter().GetHp();

}

/*=========================================================================*/
/**
 * @brief デストラクタ.
 *
 */
HitPoint::~HitPoint()
{

}

/*=========================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void HitPoint::Initialize()
{
	switch( m_player.GetPlayerParameter().GetPlayerID())
	{
	case(0):
		m_x = m_player.GetPosition().x + 300.0f;
		m_y = m_player.GetPosition().y + 100.0f;
		break;
	case(1):
		m_x = m_player.GetPosition().x + 20.0f;
		m_y = m_player.GetPosition().y + 100.0f;
		break;
	}
}

/*=========================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void HitPoint::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool HitPoint::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void HitPoint::RenderObject()
{

/** ＨＰゲージ表記 */
	TextDesc  ht;
	ht.size		= 19;
	ht.position	= Vector2(m_x, m_y);
	ht.code		= FONT_CODE_NORMAL;
	ht.font		= "HG行書体";
	ht.string	= "ＨＰ";
	m_device.GetGraphicDevice().Render( ht );

	GaugeDesc gd1;
	gd1.size = Vector2(100.0f, 20.0f);
	gd1.position = Vector2(m_x, m_y);
	gd1.textureRec2 = Rect(0,0,128,32);
	gd1.textureRec1 = Rect(0,32,128,64);
	gd1.max = m_player.GetPlayerParameter().GetMaxHp();
	gd1.point = m_player.GetPlayerParameter().GetHp();
	gd1.texture1 = TEXTUREID_HP;
	gd1.texture2 = TEXTUREID_HP;
	m_device.GetGraphicDevice().Render( gd1 );
/*
	SpriteDesc box;
	box.textureID = TEXTUREID_HPBOX;
	box.rect = Rect(m_x - 20.0f ,m_y - 5.0f ,m_x+110.0f ,m_y+25.0f);
	m_device.GetGraphicDevice().Render( box );
*/


}

/*=========================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void HitPoint::UpdateObject(float frameTimer)
{

}


/*===== EOF ===================================================================*/
