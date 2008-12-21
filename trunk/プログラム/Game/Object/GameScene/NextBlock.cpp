/*******************************************************************************/
/**
 * @file NextBlock.cpp.
 * 
 * @brief ネクストブロッククラスソース定義.
 *
 * @date 2008/12/19.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/

#include	"NextBlock.h"
#include	"Player.h"

/*=============================================================================*/
/**
 * @brief コンストラクタ.
 * 
 * @param[in] device ゲームデバイス.
 * @param[in] objectManager オブジェクトマネージャ.
 * @param[in] option ゲームオプション.
 * @param[in] gameSceneState ゲームシーンステート.
 */
NextBlock::NextBlock(IGameDevice& device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState, Player& player)	:
		m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{

	
}

/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
NextBlock::~NextBlock()
{

}

/*=============================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void NextBlock::Initialize()
{
	switch( m_player.GetPlayerParameter().GetPlayerID())
	{
	case(0):
		m_x = m_player.GetPosition().x + 360.0f;
		m_y = m_player.GetPosition().y + 200.0f;
		break;
	case(1):
		m_x = m_player.GetPosition().x + 30.0f;
		m_y = m_player.GetPosition().y + 200.0f;
		break;
	}
}

/*=============================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void NextBlock::Terminate()
{

}

/*=============================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool NextBlock::IsTerminated()
{
	return m_isTerminated;

}

/*=============================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void NextBlock::RenderObject()
{
	SpriteDesc sd[2];
	sd[0].textureID = m_player.GetPlayerParameter().GetNextCBlock();
	sd[1].textureID = m_player.GetPlayerParameter().GetNextMBlock();

	for( int i = 0; i < 2; i++ ){
		sd[i].rect = Rect(m_x ,m_y + i*30 ,m_x+BLOCK_SIZE ,m_y+BLOCK_SIZE + i*30);
		m_device.GetGraphicDevice().Render( sd[i] );
	}
}

/*=============================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void NextBlock::UpdateObject(float frameTimer)
{

}


/*===== EOF ===================================================================*/
