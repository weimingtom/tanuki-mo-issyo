/*******************************************************************************/
/*
 * @file StatusScreen.cpp.
 * 
 * @brief �X�e�[�^�[�X�X�N���[���\�[�X�t�@�C��.
 *
 * @date 2008/12/15.
 *
 * @version 1.00.
 *
 * @author Ryouma Kawasue.
 */
/*******************************************************************************/

/*===== �C���N���[�h ==========================================================*/
#include	"StatusScreen.h"

/*=============================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 * @param[in] device �Q�[���f�o�C�X.
 * @param[in] objectManager �I�u�W�F�N�g�}�l�[�W��.
 * @param[in] option �Q�[���I�v�V����.
 * @param[in] gameSceneState �Q�[���V�[���X�e�[�g.
 */
StatusScreen::StatusScreen(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player &player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{
}

/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
StatusScreen::~StatusScreen()
{
}

/*=============================================================================*/
/**
 * @brief ����������.
 * 
 */
void StatusScreen::Initialize()
{

}

/*=============================================================================*/
/**
 * @brief �I������.
 * 
 */
void StatusScreen::Terminate()
{
	m_isTerminated = true;
}

/*=============================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool StatusScreen::IsTerminated()
{
	return m_isTerminated;
}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
 * 
 */
void StatusScreen::RenderObject()
{
	float m_x = 400.0f;
	float m_y = 300.0f;

	SpriteDesc sd;
	sd.textureID = TEXTUERID_POWER;

	sd.rect = Rect(m_x, m_y, m_x+256, m_y+256 );
	m_device.GetGraphicDevice().Render( sd );
}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void StatusScreen::UpdateObject(float frameTimer)
{

}

/*===== EOF ===================================================================*/
