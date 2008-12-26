/*******************************************************************************/
/**
 * @file BlockDeleteEffect.h.
 * 
 * @brief フォールブロッククラス定義.
 *
 * @date 2008/12/8.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/

#include "BlockDeleteEffect.h"
#include "Object/GameScene/Player.h"


/*=========================================================================*/
/**
* @brief コンストラクタ
*/
BlockDeleteEffect::BlockDeleteEffect(IGameDevice& device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState, Player& player, float x, float y, int blockID) :
m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false), m_x(x), m_y(y), m_blockID(blockID)
{
	m_speed = 0.5f;
	m_timer = 30.0f;
	m_size = 0.0f;
}
/*=========================================================================*/
/**
 * @brief デストラクタ.
 * 
 */
BlockDeleteEffect::~BlockDeleteEffect()
{

}

/*=========================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void BlockDeleteEffect::Initialize()
{

}

/*=========================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void BlockDeleteEffect::Terminate()
{
	//IntPoint pos = GetFieldMatrixPosition(m_x, m_y);
	//m_player.GetPuzzleScreen().GetBlockManager().GetField().SetBlock(pos.x, pos.y, m_blockID);
	m_isTerminated = true;
	m_player.GetPlayerParameter().SetIsCreateBlock(true);
}

/*=========================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool BlockDeleteEffect::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void BlockDeleteEffect::RenderObject()
{
	SpriteDesc sd;
	sd.textureID = m_blockID;
	
	sd.rect = Rect(m_x + m_size,m_y + m_size,m_x + BLOCK_SIZE - m_size,m_y + BLOCK_SIZE - m_size);
	m_device.GetGraphicDevice().Render( sd );
}

/*=========================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void BlockDeleteEffect::UpdateObject(float frameTimer)
{
	if(m_gameSceneState.GetGameState() != GAME_STATE_MAIN)
	{
		return;
	}
	m_timer --;
	if(m_timer <= 0)
	{
		Terminate();
	}
	m_size += m_speed;
}

/*=============================================================================*/
/**
 * @brief フィールドから配列へ
 * 
 * @param[in] x 横の位置.
 * @param[in] y 縦の位置.
 *
 * @return 配列の番号.
 */
IntPoint BlockDeleteEffect::GetFieldMatrixPosition(float x, float y)
{
	IntPoint tmp;
	Vector2 fieldPosition = m_player.GetPuzzleScreen().GetBlockManager().GetField().GetPosition();
	tmp.x = (int)((x-fieldPosition.x) / BLOCK_SIZE);
	tmp.y = (int)((y-fieldPosition.y) / BLOCK_SIZE);

	return tmp;
}

