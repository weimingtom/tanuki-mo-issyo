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
Gauge::Gauge(IGameDevice &device,int tex1, int tex2, Vector2 position, Vector2 size, float max, float point) :
	m_device(device)
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
}
/*===== EOF ===================================================================*/
