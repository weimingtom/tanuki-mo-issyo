/*******************************************************************************/
/**
 * @file Avatar.cpp.
 * 
 * @brief アバタークラス定義.
 *
 * @date 2008/12/11.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/

#include	"Object/GameScene/Avatar.h"
#include	"Object/GameScene/Player.h"


/*=========================================================================*/
/**
 * @brief コンストラクタ.
 * 
 */
Avatar::Avatar(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player& player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{

}

/*=========================================================================*/
/**
 * @brief デストラクタ.
 *
 */
Avatar::~Avatar()
{

}

/*=========================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void Avatar::Initialize()
{
	m_x = m_player.GetPosition().x + 300.0f;
	m_y = m_player.GetPosition().y + 100.0f;
}

/*=========================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void Avatar::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool Avatar::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void Avatar::RenderObject()
{
	SpriteDesc sd;
	sd.textureID = m_player.GetPlayerParameter().GetCharacterID();
	
	sd.rect = Rect(m_x ,m_y ,m_x+256 ,m_y+256);
	m_device.GetGraphicDevice().Render( sd );
}

/*=========================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void Avatar::UpdateObject(float frameTimer)
{

}


/*===== EOF ===================================================================*/
