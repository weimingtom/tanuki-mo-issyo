/*******************************************************************************/
/*
 * @file BlockManager.cpp.
 * 
 * @brief �u���b�N�}�l�[�W���[�N���X(��).
 *
 * @date 2008/12/04.
 *
 * @version 1.00.
 *
 * @author Tsubasa Uragami.
 */
/*******************************************************************************/

/*===== �C���N���[�h ==========================================================*/

#include	"BlockManager.h"

/*=============================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 * @param[in] device �Q�[���f�o�C�X.
 * @param[in] objectManager �I�u�W�F�N�g�}�l�[�W��.
 * @param[in] option �Q�[���I�v�V����.
 * @param[in] gameSceneState �Q�[���V�[���X�e�[�g.
 */
BlockManager::BlockManager(IGameDevice& device, ObjectManager& objectManager, Option &option, GameSceneState& gameSceneState) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_isTerminated(false)
{
}

/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
BlockManager::~BlockManager()
{
}

/*=============================================================================*/
/**
 * @brief ����������.
 * 
 */
void BlockManager::Initialize()
{
}

/*=============================================================================*/
/**
 * @brief �I������.
 * 
 */
void BlockManager::Terminate()
{
	m_isTerminated = true;
}

/*=============================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool BlockManager::IsTerminated()
{
	return m_isTerminated;
}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
 * 
 */
void BlockManager::RenderObject()
{
}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void BlockManager::UpdateObject(float frameTimer)
{
}

/*===== EOF ===================================================================*/