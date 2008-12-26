/*******************************************************************************/
/**
 * @file ReadyGo.cpp.
 * 
 * @brief レディゴークラスソース定義.
 *
 * @date 2008/12/26.
 *
 * @version 1.00.
 *
 * @author Ryoma Kawasue.
 */
/*******************************************************************************/

#include	"ReadyGo.h"

/*=========================================================================*/
/**
 * @brief コンストラクタ.
 * 
 */
ReadyGo::ReadyGo(IGameDevice &device, GameSceneState &gameSceneState) :
	m_device(device), m_gameSceneState(gameSceneState), m_isTerminated(false)
{

}

/*=========================================================================*/
/**
 * @brief デストラクタ.
 *
 */
ReadyGo::~ReadyGo()
{

}

/*=========================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void ReadyGo::Initialize()
{
	m_x = -10.0f;
	m_y = 300.0f;

	m_x2 = WINDOW_WIDTH - 190.0f;
	m_y2 = m_y + 50.0f; 

	timer = 60.0f;

}

/*=========================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void ReadyGo::Terminate()
{
	m_gameSceneState.SetGameState(GAME_STATE_MAIN);
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool ReadyGo::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void ReadyGo::RenderObject()
{
	SpriteDesc sd1;
	sd1.rect = Rect(m_x, m_y, m_x+200, m_y+50);
	sd1.srcRect = Rect(0, 0, 512, 128);
	sd1.textureID = TEXTUREID_READY_GO;
	
	m_device.GetGraphicDevice().Render( sd1 );

	SpriteDesc sd2;
	sd2.rect = Rect(m_x2, m_y2, m_x2+80, m_y2+50);
	sd2.srcRect = Rect(0, 128, 207, 256);
	sd2.textureID = TEXTUREID_READY_GO;
	
	m_device.GetGraphicDevice().Render( sd2 );

}

/*=========================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void ReadyGo::UpdateObject(float frameTimer)
{
	if( m_x >= 380.0f && m_x2 >= 320.0f )
	{
		if(timer > 0.0f)
		{
			timer = timer - 1.0f;
		}
		if( timer <= 0.0f)
		{
			m_x += 10.0f;
			m_x2 -= 10.0f;
		}
	}
	else
	{
		m_x += 10.0f;
		m_x2 -= 10.0f;
	}

	if( m_x > WINDOW_WIDTH + 50.0f )
	{
		Terminate();
	}

}


/*===== EOF ===================================================================*/
