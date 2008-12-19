/*******************************************************************************/
/**
 * @file Gauge.cpp.
 * 
 * @brief ゲージクラスソース定義.
 *
 * @date 2008/12/18.
 *
 * @version 1.00.
 *
 * @author Ryouma Kawasue.
 */
/*******************************************************************************/

#include "Gauge.h"
#include "Player.h"

/*=========================================================================*/
/**
 * @brief コンストラクタ.
 * 
 */
Gauge::Gauge(IGameDevice &device,int tex1, int tex2, Vector2 position, Vector2 size, float max, float point,Rect texRec1,Rect texRec2) :
m_device(device),m_texture1(tex1),m_texture2(tex2),m_position(position),m_size(size),m_max(max),m_point(point),m_textureRec1(texRec1),m_textureRec2(texRec2),m_isTerminated(false)
{
	
}
/*=========================================================================*/
/**
 * @brief デストラクタ.
 *
 */
Gauge::~Gauge()
{

}

/*=========================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void Gauge::Initialize()
{


}

/*=========================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void Gauge::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool Gauge::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void Gauge::RenderObject()
{
	SpriteDesc sd;

	sd.textureID = m_texture1;
	
	sd.rect = Rect(m_position.x,m_position.y,m_position.x+(m_max/m_size.x*m_point),m_position.y+m_size.y);
	sd.srcRect = Rect(m_textureRec1.left,m_textureRec1.top,m_textureRec1.left+(m_max/(m_textureRec1.right-m_textureRec1.left)*m_point),m_textureRec1.bottom);
	m_device.GetGraphicDevice().Render( sd );

	sd.textureID = m_texture2;
	
	sd.rect = Rect(m_position.x,m_position.y,m_position.x+m_size.x,m_position.y+m_size.y);
	sd.srcRect = Rect(m_textureRec2.left,m_textureRec2.top,m_textureRec2.right,m_textureRec2.bottom);
	m_device.GetGraphicDevice().Render( sd );

	


}

/*=========================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void Gauge::UpdateObject(float frameTimer)
{
}

void Gauge::SetTexture(int tex1, int tex2 )
{
	m_texture1 = tex1;
	m_texture2 = tex2;
}

void Gauge::SetMax(float max)
{
	m_max = max;
}
void Gauge::SetPoint(float point)
{
	m_point = point;
}
void Gauge::SetPosition(Vector2 position)
{
	m_position = position;
}

void Gauge::SetSize(Vector2 size)
{
	m_size = size;
}

void Gauge::SetRect(Rect texRec1, Rect texRec2)
{
	m_textureRec1 = texRec1;
	m_textureRec2 = texRec2;
}
/*===== EOF ===================================================================*/
