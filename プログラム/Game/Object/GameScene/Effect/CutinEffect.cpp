/*******************************************************************************/
/**
 * @file CutinEffect.cpp.
 * 
 * @brief �J�b�g�C���\�[�X��`.
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
 * @brief �R���X�g���N�^.
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
 * @brief �f�X�g���N�^.
 *
 */
CutinEffect::~CutinEffect()
{

}

/*=========================================================================*/
/**
 * @brief ����������.
 * 
 */
void CutinEffect::Initialize()
{

}

/*=========================================================================*/
/**
 * @brief �I������.
 * 
 */
void CutinEffect::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool CutinEffect::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
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
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
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
