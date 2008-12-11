/*******************************************************************************/
/**
 * @file PuzzleScreen.cpp.
 * 
 * @brief �p�Y���X�N���[���N���X�\�[�X�t�@�C��.
 *
 * @date 2008/12/4.
 *
 * @version 1.00.
 *
 * @author ryoma kawasue.
 */
/*******************************************************************************/

#include "PuzzleScreen.h"

PuzzleScreen::PuzzleScreen(IGameDevice& device, ObjectManager& objectManager, Option &option, GameSceneState& gameSceneState, Player &player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false),
	m_blockManager(device, objectManager, option, gameSceneState, player)
{
}

/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
PuzzleScreen::~PuzzleScreen()
{
}

/*=============================================================================*/
/**
 * @brief ����������.
 *
 */
void PuzzleScreen::Initialize()
{
	m_blockManager.Initialize();
}

/*=============================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 *
 */
bool PuzzleScreen::IsTerminated()
{
	return m_isTerminated;
}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
 *
 */
void PuzzleScreen::RenderObject()
{
	m_blockManager.RenderObject();
}

/*=============================================================================*/
/**
 * @brief �I������.
 *
 */
void PuzzleScreen::Terminate()
{
	m_isTerminated = true; 
}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍X�V����.
 *
 */
void PuzzleScreen::UpdateObject(float frameTimer)
{
	m_blockManager.UpdateObject(frameTimer);
}

BlockManager&	PuzzleScreen::GetBlockManager()
{
	return	m_blockManager;
}
/*===== EOF ===================================================================*/