/*******************************************************************************/
/**
 * @file FallBlock.h.
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

#include "FallBlock.h"
#include "Object/GameScene/Player.h"


/*=========================================================================*/
/**
* @brief コンストラクタ
*/
FallBlock::FallBlock(IGameDevice& device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState, Player& player, float x, float y, int blockID) :
m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false), m_x(x), m_y(y), m_blockID(blockID)
{
	m_speed	= 2.0f;
}
/*=========================================================================*/
/**
 * @brief デストラクタ.
 * 
 */
FallBlock::~FallBlock()
{

}

/*=========================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void FallBlock::Initialize()
{

}

/*=========================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void FallBlock::Terminate()
{
	IntPoint pos = GetFieldMatrixPosition(m_x, m_y);
	m_player.GetPuzzleScreen().GetBlockManager().GetField().SetBlock(pos.x, pos.y, m_blockID);
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool FallBlock::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void FallBlock::RenderObject()
{
	SpriteDesc sd;
	sd.textureID = m_blockID;
	
	sd.rect = Rect(m_x - (BLOCK_SIZE/2),m_y - (BLOCK_SIZE/2),m_x+(BLOCK_SIZE/2),m_y+(BLOCK_SIZE/2));
	m_device.GetGraphicDevice().Render( sd );
}

/*=========================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void FallBlock::UpdateObject(float frameTimer)
{
	FieldMatrix frame;
	IntPoint pos = GetFieldMatrixPosition(m_x, m_y + m_speed + (BLOCK_SIZE/2));
	m_player.GetPuzzleScreen().GetBlockManager().GetField().GetFieldBlockMatrix(&frame);
	if(!ColisionMatrix(frame,pos.x,pos.y)) 
	{
		m_y += m_speed;
	} else
	{
		m_y = m_player.GetPuzzleScreen().GetBlockManager().GetField().GetPosition().y + ((pos.y)*BLOCK_SIZE) - (BLOCK_SIZE/2);
		Terminate();
	}
}

IntPoint FallBlock::GetFieldMatrixPosition(float x, float y)
{
	IntPoint tmp;
	Vector2 fieldPosition = m_player.GetPuzzleScreen().GetBlockManager().GetField().GetPosition();
	tmp.x = (int)((x-fieldPosition.x) / BLOCK_SIZE);
	tmp.y = (int)((y-fieldPosition.y) / BLOCK_SIZE);

	return tmp;
}

bool FallBlock::ColisionMatrix(FieldMatrix matrix, int x, int y)
{
	if(matrix.matrix[x][y] != 0)
	{
		return true;
	}

	return	false;
}
