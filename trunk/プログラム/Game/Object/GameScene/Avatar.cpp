/*******************************************************************************/
/**
 * @file Avatar.cpp.
 * 
 * @brief �A�o�^�[�N���X��`.
 *
 * @date 2008/12/11.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/

#include	"Object/GameScene/Avatar.h"
#include	"Object/GameScene/Player.h"


/*=========================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 */
Avatar::Avatar(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player& player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{

}

/*=========================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
Avatar::~Avatar()
{

}

/*=========================================================================*/
/**
 * @brief ����������.
 * 
 */
void Avatar::Initialize()
{
	m_x = m_player.GetPosition().x + 300.0f;
	m_y = m_player.GetPosition().y + 100.0f;
}

/*=========================================================================*/
/**
 * @brief �I������.
 * 
 */
void Avatar::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool Avatar::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
 * 
 */
void Avatar::RenderObject()
{
	SpriteDesc sd;
	sd.textureID = m_player.GetPlayerParameter().GetCharacterID();
	
	sd.rect = Rect(m_x ,m_y ,m_x+256 ,m_y+256);
	m_device.GetGraphicDevice().Render( sd );
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void Avatar::UpdateObject(float frameTimer)
{

}


/*===== EOF ===================================================================*/
