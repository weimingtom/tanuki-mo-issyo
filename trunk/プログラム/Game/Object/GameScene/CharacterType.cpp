/*******************************************************************************/
/**
 * @file CharacterType.cpp.
 * 
 * @brief �L�����N�^�^�C�v�\�[�X��`.
 *
 * @date 2008/12/21.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/

#include	"Object/GameScene/CharacterType.h"
#include	"Object/GameScene/Player.h"

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 */
CharacterType::CharacterType(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player& player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{

}

/*=========================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
CharacterType::~CharacterType()
{

}

/*=========================================================================*/
/**
 * @brief ����������.
 * 
 */
void CharacterType::Initialize()
{
	switch( m_player.GetPlayerParameter().GetPlayerID() )
	{
	case(0):
		m_x = m_player.GetPosition().x + 300.0f;
		m_y = m_player.GetPosition().y + 140.0f;
		break;
	case(1):
		m_x = m_player.GetPosition().x + 90.0f;
		m_y = m_player.GetPosition().y + 140.0f;
		break;
	}
}

/*=========================================================================*/
/**
 * @brief �I������.
 * 
 */
void CharacterType::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool CharacterType::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
 * 
 */
void CharacterType::RenderObject()
{
	SpriteDesc sd;
	sd.textureID = m_player.GetPlayerParameter().GetCharacterID();
	
	sd.rect = Rect(m_x ,m_y ,m_x+BLOCK_SIZE ,m_y+BLOCK_SIZE);
	m_device.GetGraphicDevice().Render( sd );
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void CharacterType::UpdateObject(float frameTimer)
{

}


/*===== EOF ===================================================================*/
