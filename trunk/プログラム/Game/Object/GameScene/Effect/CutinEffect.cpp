/*******************************************************************************/
/**
 * @file CutinEffect.cpp.
 * 
 * @brief カットインソース定義.
 *
 * @date 2008/12/27.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/

#include	"CutinEffect.h"

/*=========================================================================*/
/**
 * @brief コンストラクタ.
 * 
 */
CutinEffect::CutinEffect(IGameDevice &device, GameSceneState &gameSceneState,int id) :
	m_device(device), m_gameSceneState(gameSceneState), m_isTerminated(false), m_id(id)
{
	m_size.x = 200.0f;
	m_size.y = 80.0f;
	m_y = 200.0f;
	m_speed = 17.0f;
	m_vspeed = 0.5f;
	m_time = 80;

	if(id == CUTIN_LEFT)
	{
		m_x =  -m_size.x;
	} else
	{
		m_x = WINDOW_WIDTH;
	}
}

/*=========================================================================*/
/**
 * @brief デストラクタ.
 *
 */
CutinEffect::~CutinEffect()
{

}

/*=========================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void CutinEffect::Initialize()
{

}

/*=========================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void CutinEffect::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool CutinEffect::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void CutinEffect::RenderObject()
{
	SpriteDesc sd;
	sd.rect = Rect(m_x, m_y, m_x + m_size.x, m_y + m_size.y);
//	sd1.srcRect = Rect(0, 0, 512, 128);
	sd.textureID = TEXTUREID_CUTIN;
	m_device.GetGraphicDevice().Render( sd );

}

/*=========================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void CutinEffect::UpdateObject(float frameTimer)
{
	m_time--;
	if(m_time <= 0)
	{
		Terminate();
	}
	if(m_id == CUTIN_LEFT)
	{
		m_x += m_speed;
	} else
	{
		m_x -= m_speed;
	}

	if(m_speed - m_vspeed >0)
	{
		m_speed -= m_vspeed;
	}
}


/*===== EOF ===================================================================*/
