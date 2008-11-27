/*******************************************************************************/
/*
 * @file Player.cpp.
 * 
 * @brief �v���[���[�N���X��`.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/

/*===== �C���N���[�h ==========================================================*/
#include	"Object/GameScene/Player.h"


/*=============================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 * @param[in] device �Q�[���f�o�C�X.
 * @param[in] objectManagerMediator �I�u�W�F�N�g�}�l�[�W�����f�B�G�[�^.
 * @param[in] option �Q�[���I�v�V����.
 * @param[in] gameSceneState �Q�[���V�[���X�e�[�g.
 */
Player::Player(IGameDevice& device, ObjectManagerMediator& objectManagerMediator, Option &option, GameSceneState& gameSceneState) :
	m_device(device), m_objectManagerMediator(objectManagerMediator), m_option(option), m_gameSceneState(gameSceneState), m_isTerminated(false)
{
	m_gameSceneState.AddPlayer(this);
	m_block = new Block(device,objectManagerMediator,option,gameSceneState);
}

/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
Player::~Player()
{
	delete m_block;
}

/*=============================================================================*/
/**
 * @brief ����������.
 * 
 */
void Player::Initialize()
{
	m_block->Initialize();
}

/*=============================================================================*/
/**
 * @brief �I������.
 * 
 */
void Player::Terminate()
{
	m_block->Terminate();
	m_isTerminated = true;
}

/*=============================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool Player::IsTerminated()
{
	return m_isTerminated;
}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
 * 
 */
void Player::RenderObject()
{
	m_block->RenderObject();
}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void Player::UpdateObject(float frameTimer)
{
	m_block->UpdateObject(frameTimer);
}

/*===== EOF ===================================================================*/