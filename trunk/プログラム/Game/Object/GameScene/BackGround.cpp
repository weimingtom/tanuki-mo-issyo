/*******************************************************************************/
/*
 * @file BackGround.cpp.
 * 
 * @brief �w�i.
 *
 * @date 2008/12/26.
 *
 * @version 1.00.
 *
 * @author Ryoma Kawasue.
 */
/*******************************************************************************/

/*===== �C���N���[�h ==========================================================*/
#include	"BackGround.h"

/*=============================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 * @param[in] ������ ��������.
 */
BackGround::BackGround(IGameDevice& device, GameSceneState& gameSceneState):
	m_device(device),m_gameSceneState(gameSceneState),m_isTerminated(false)
{
}

/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
BackGround::~BackGround()
{
}

/*=============================================================================*/
/**
 * @brief �֐�����.
 * 
 * @param[in] ������ ��������.
 * @return �߂�l����.
 */

void BackGround::Initialize()
{
}

void BackGround::Terminate()
{
	m_isTerminated = true;
}

bool BackGround::IsTerminated()
{
	return m_isTerminated;
}

void BackGround::RenderObject()
{
	SpriteDesc sd;
	sd.rect = Rect(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);
	sd.textureID = TEXTUREID_BACKGROUND;
	m_device.GetGraphicDevice().Render( sd );
	
}

void BackGround::UpdateObject(float frameTimer)
{
}

/*===== EOF ===================================================================*/