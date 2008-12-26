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

	Vector2 position1;
	Vector2 position2;
	SpriteDesc re1;
	SpriteDesc re2;
	position1 = m_gameSceneState.GetPlayer(0)->GetPuzzleScreen().GetBlockManager().GetField().GetPosition();
	position2 = m_gameSceneState.GetPlayer(1)->GetPuzzleScreen().GetBlockManager().GetField().GetPosition();
	re1.rect = Rect(position1.x+40.0f,position1.y+150.0f,position1.x+240.0f,position1.y+250.0f);
	re2.rect = Rect(position2.x+40.0f,position2.y+150.0f,position2.x+240.0f,position2.y+250.0f);
	//if(m_player.GetPlayerParameter().getplayerjudge() == JUDGLE_WIN)
	//{
	//if(m_gameSceneState.GetPlayer(0)->GetPlayerParameter() 
		re1.srcRect = Rect(0,0,512.0f,117.0f);
	//} else
	//{
		re1.srcRect = Rect(0,120.0f,512.0f,256.0f);
	//}

	//if(m_gameSceneState.GetPlayer(1)->GetPlayerParameter() 
		re2.srcRect = Rect(0,0,512.0f,117.0f);
	//} else
	//{
		re2.srcRect = Rect(0,120.0f,512.0f,256.0f);
	//}

	re1.textureID = TEXTUREID_JUDGE;
	re2.textureID = TEXTUREID_JUDGE;

	m_device.GetGraphicDevice().Render( re1 );
	m_device.GetGraphicDevice().Render( re2 );

	
	

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
