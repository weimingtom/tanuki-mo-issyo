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
 * @param[in] objectManager �I�u�W�F�N�g�}�l�[�W��.
 * @param[in] option �Q�[���I�v�V����.
 * @param[in] gameSceneState �Q�[���V�[���X�e�[�g.
 */
Player::Player(IGameDevice& device, ObjectManager& objectManager, Option &option, GameSceneState& gameSceneState, float x, float y) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_isTerminated(false), m_x(x), m_y(y),
		m_puzzleScreen(device,objectManager,option,gameSceneState, *this),
		m_characterScreen(device,objectManager,option,gameSceneState, *this),
		m_statusScreen(device,objectManager,option,gameSceneState, *this)
		
{
	m_gameSceneState.AddPlayer(this);
	
}

/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
Player::~Player()
{
	
}

/*=============================================================================*/
/**
 * @brief ����������.
 * 
 */
void Player::Initialize()
{

	m_puzzleScreen.Initialize();
	m_characterScreen.Initialize();
	m_statusScreen.Initialize();
}

/*=============================================================================*/
/**
 * @brief �I������.
 * 
 */
void Player::Terminate()
{

	m_puzzleScreen.Terminate();
	m_characterScreen.Terminate();
	m_statusScreen.Terminate();
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
	m_puzzleScreen.RenderObject();
	m_characterScreen.RenderObject();
	m_statusScreen.RenderObject();
}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void Player::UpdateObject(float frameTimer)
{

	m_puzzleScreen.UpdateObject(frameTimer);
	m_characterScreen.UpdateObject(frameTimer);
	m_statusScreen.UpdateObject(frameTimer);

}

Vector2 Player::GetPosition()
{
	return Vector2(m_x,m_y);
}

PuzzleScreen& Player::GetPuzzleScreen()
{
	return m_puzzleScreen;
}

/*===== EOF ===================================================================*/