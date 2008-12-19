/*******************************************************************************/
/**
 * @file Score.cpp.
 * 
 * @brief �X�R�A�N���X�\�[�X��`.
 *
 * @date 2008/12/15.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/

#include	"Score.h"
#include	"Player.h"

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 */
Score::Score(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player& player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{

}

/*=========================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
Score::~Score()
{

}

/*=========================================================================*/
/**
 * @brief ����������.
 * 
 */
void Score::Initialize()
{
	m_x = m_player.GetPosition().x + 300.0f;
	m_y = m_player.GetPosition().y + 370.0f;
}

/*=========================================================================*/
/**
 * @brief �I������.
 * 
 */
void Score::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool Score::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
 * 
 */
void Score::RenderObject()
{
	SpriteDesc sd;
	sd.textureID = TEXTUREID_SCORE;
	
	sd.rect = Rect(m_x ,m_y ,m_x+100 ,m_y+20);
	m_device.GetGraphicDevice().Render( sd );
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void Score::UpdateObject(float frameTimer)
{

}


/*===== EOF ===================================================================*/


