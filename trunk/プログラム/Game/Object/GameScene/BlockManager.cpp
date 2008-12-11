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
BlockManager::BlockManager(IGameDevice& device, ObjectManager& objectManager, Option &option, GameSceneState& gameSceneState, Player& player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false),
		m_field(device, objectManager, option, gameSceneState, player)
{
	m_block = new Block(device, objectManager, option, gameSceneState, player,1,1 );
	m_fallBlock = new FallBlock(device, objectManager, option, gameSceneState, player);
}

/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
BlockManager::~BlockManager()
{
	if(m_block){
		delete m_block;
	}
	if(m_fallBlock){
		delete m_fallBlock;
	}
}

/*=============================================================================*/
/**
 * @brief ����������.
 * 
 */
void BlockManager::Initialize()
{
	if(m_block){
		m_block->Initialize();
	}
	if(m_fallBlock){
		m_fallBlock->Initialize();
	}
	m_field.Initialize();
}

/*=============================================================================*/
/**
 * @brief �I������.
 * 
 */
void BlockManager::Terminate()
{
	m_isTerminated = true;
	if(m_block){
		m_block->Terminate();
	}
	if(m_fallBlock){
		m_fallBlock->Terminate();
	}
	m_field.Terminate();
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
	if(m_block){
		m_block->RenderObject();
	}
	if(m_fallBlock){
		m_fallBlock->RenderObject();
	}
	m_field.RenderObject();
}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void BlockManager::UpdateObject(float frameTimer)
{
	if(m_block){
		m_block->UpdateObject(frameTimer);
	}
	if(m_fallBlock){
		m_fallBlock->UpdateObject(frameTimer);
	}
	m_field.UpdateObject(frameTimer);
}

/*===== EOF ===================================================================*/