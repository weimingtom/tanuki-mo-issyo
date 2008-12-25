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
#include	<sstream>

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
	switch( m_player.GetPlayerParameter().GetPlayerID())
	{
	case(0):
		m_x = m_player.GetPosition().x + 300.0f;
		m_y = m_player.GetPosition().y + 0.0f;
		break;
	case(1):
		m_x = m_player.GetPosition().x + 20.0f;
		m_y = m_player.GetPosition().y + 0.0f;
		break;
	}
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
	TextDesc td;
	std::stringstream ss;

	td.code = FONT_CODE_NORMAL;
	td.font = "�l�r �S�V�b�N";
	td.position = Vector2(m_x, m_y);
	td.size = 15;
	ss << "Score:" << m_player.GetPlayerParameter().GetScore();
	td.string = ss.str();
	m_device.GetGraphicDevice().Render( td );
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


