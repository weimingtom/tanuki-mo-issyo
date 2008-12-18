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
Gauge::Gauge(IGameDevice &device,int tex1, int tex2, Vector2 position, Vector2 size, float max, float point) :
	m_device(device)
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
}
/*===== EOF ===================================================================*/
