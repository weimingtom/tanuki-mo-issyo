/*******************************************************************************/
/**
 * @file Result.cpp.
 * 
 * @brief リザルトクラスソース定義.
 *
 * @date 2008/12/18.
 *
 * @version 1.00.
 *
 * @author Jun Futagawa.
 */
/*******************************************************************************/

#include "Result.h"
#include "Object/GameScene/Player.h"

/*=========================================================================*/
/**
 * @brief コンストラクタ.
 * 
 */
Result::Result(IGameDevice &device, GameSceneState &gameSceneState) :
	m_device(device), m_gameSceneState(gameSceneState), m_isTerminated(false)
{
}
/*=========================================================================*/
/**
 * @brief デストラクタ.
 *
 */
Result::~Result()
{
}

/*=========================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void Result::Initialize()
{

}

/*=========================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void Result::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool Result::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void Result::RenderObject()
{

/** 勝ち負け表示 */

	Vector2 position;
	SpriteDesc sd;

	sd.textureID = TEXTUREID_JUDGE;
	for(int i=0; i<2; i++)
	{
		position = m_gameSceneState.GetPlayer(i)->GetPuzzleScreen().GetBlockManager().GetField().GetPosition();
		sd.rect = Rect(position.x+40.0f,position.y+150.0f,position.x+240.0f,position.y+250.0f);
		if(m_gameSceneState.GetPlayer(i)->GetPlayerParameter().GetPlayerJudge() == PLAYER_JUDGE_LOSE)
		{
			sd.srcRect = Rect(0,0,512.0f,117.0f);
		} else
		{
			sd.srcRect = Rect(0,120.0f,512.0f,256.0f);
		}
		m_device.GetGraphicDevice().Render( sd );
	}
}

/*=========================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void Result::UpdateObject(float frameTimer)
{
}

/*===== EOF ===================================================================*/
