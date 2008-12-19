/*******************************************************************************/
/**
 * @file Gauge.cpp.
 * 
 * @brief �Q�[�W�N���X�\�[�X��`.
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
 * @brief �R���X�g���N�^.
 * 
 */
Gauge::Gauge(IGameDevice &device,int tex1, int tex2, Vector2 position, Vector2 size, float max, float point,Rect texRec1,Rect texRec2) :
m_device(device),m_texture1(tex1),m_texture2(tex2),m_position(position),m_size(size),m_max(max),m_point(point),m_textureRec1(texRec1),m_textureRec2(texRec2),m_isTerminated(false)
{
	
}
/*=========================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
Gauge::~Gauge()
{

}

/*=========================================================================*/
/**
 * @brief ����������.
 * 
 */
void Gauge::Initialize()
{


}

/*=========================================================================*/
/**
 * @brief �I������.
 * 
 */
void Gauge::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool Gauge::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
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
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
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
