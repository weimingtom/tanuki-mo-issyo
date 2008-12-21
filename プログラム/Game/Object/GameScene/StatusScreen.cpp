/*******************************************************************************/
/**
 * @file StatusScreen.cpp.
 * 
 * @brief �X�e�[�^�X�X�N���[���N���X�\�[�X��`.
 *
 * @date 2008/12/15.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
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
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false),
		m_skillPoint(device,objectManager,option,gameSceneState, m_player),
		m_hitPoint(device,objectManager,option,gameSceneState, m_player),
		m_score(device,objectManager,option,gameSceneState, m_player),
		m_playerTime(device,objectManager,option,gameSceneState, m_player),
		m_nextBlock(device, objectManager, option, gameSceneState, m_player),
		m_attack(device, objectManager, option, gameSceneState, m_player),
		m_defence(device, objectManager, option, gameSceneState, m_player)
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
	m_skillPoint.Initialize();
	m_hitPoint.Initialize();
	m_score.Initialize();
	m_playerTime.Initialize();
	m_nextBlock.Initialize();
	m_attack.Initialize();
	m_defence.Initialize();
}

/*=============================================================================*/
/**
 * @brief �I������.
 * 
 */
void StatusScreen::Terminate()
{
	m_skillPoint.Terminate();
	m_hitPoint.Terminate();
	m_score.Terminate();
	m_playerTime.Terminate();
	m_nextBlock.Terminate();
	m_attack.Terminate();
	m_defence.Terminate();
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
	m_skillPoint.RenderObject();
	m_hitPoint.RenderObject();
	m_score.RenderObject();
	m_playerTime.RenderObject();
	m_nextBlock.RenderObject();
	m_attack.RenderObject();
	m_defence.RenderObject();
}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void StatusScreen::UpdateObject(float frameTimer)
{
	m_skillPoint.UpdateObject(frameTimer);
	m_hitPoint.UpdateObject(frameTimer);
	m_score.UpdateObject(frameTimer);
	m_playerTime.UpdateObject(frameTimer);
	m_nextBlock.UpdateObject(frameTimer);
	m_attack.UpdateObject(frameTimer);
	m_defence.UpdateObject(frameTimer);
}


/*===== EOF ===================================================================*/
