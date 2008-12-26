/*******************************************************************************/
/**
 * @file ReadyGo.cpp.
 * 
 * @brief ���f�B�S�[�N���X�\�[�X��`.
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
 * @brief �R���X�g���N�^.
 * 
 */
ReadyGo::ReadyGo(IGameDevice &device, GameSceneState &gameSceneState) :
	m_device(device), m_gameSceneState(gameSceneState), m_isTerminated(false)
{

}

/*=========================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
ReadyGo::~ReadyGo()
{

}

/*=========================================================================*/
/**
 * @brief ����������.
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
 * @brief �I������.
 * 
 */
void ReadyGo::Terminate()
{
	m_gameSceneState.SetGameState(GAME_STATE_MAIN);
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool ReadyGo::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
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
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
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
