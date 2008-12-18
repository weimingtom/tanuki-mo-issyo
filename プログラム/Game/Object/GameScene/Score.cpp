/*******************************************************************************/
/**
 * @file Score.cpp.
 * 
 * @brief スコアクラスソース定義.
 *
 * @date 2008/12/15.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/

#include	"Score.h"
#include	"Player.h"

/*=========================================================================*/
/**
 * @brief コンストラクタ.
 * 
 */
Score::Score(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player& player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{

}

/*=========================================================================*/
/**
 * @brief デストラクタ.
 *
 */
Score::~Score()
{

}

/*=========================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void Score::Initialize()
{
	m_x = m_player.GetPosition().x + 305.0f;
	m_y = m_player.GetPosition().y + 390.0f;
}

/*=========================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void Score::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool Score::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void Score::RenderObject()
{
	SpriteDesc sd;
	sd.textureID = TEXTUREID_AVATAR1;
	
	sd.rect = Rect(m_x ,m_y ,m_x+BLOCK_SIZE ,m_y+BLOCK_SIZE);
	m_device.GetGraphicDevice().Render( sd );
}

/*=========================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void Score::UpdateObject(float frameTimer)
{

}


/*===== EOF ===================================================================*/


