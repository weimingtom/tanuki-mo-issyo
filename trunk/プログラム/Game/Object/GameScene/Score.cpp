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
#include	<sstream>

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
	switch( m_player.GetPlayerParameter().GetPlayerID())
	{
	case(0):
		m_x = m_player.GetPosition().x + 300.0f;
		m_y = m_player.GetPosition().y + 0.0f;
		break;
	case(1):
		m_x = m_player.GetPosition().x + 20.0f;
		m_y = m_player.GetPosition().y + 0.0f;
		break;
	}
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
	TextDesc td;
	std::stringstream ss;

	td.code = FONT_CODE_NORMAL;
	td.font = "ＭＳ ゴシック";
	td.position = Vector2(m_x, m_y);
	td.size = 15;
	ss << "Score:" << m_player.GetPlayerParameter().GetScore();
	td.string = ss.str();
	m_device.GetGraphicDevice().Render( td );
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


