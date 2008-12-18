/*******************************************************************************/
/**
 * @file PlayerTime.cpp.
 * 
 * @brief �v���C���[�^�C���N���X�\�[�X��`.
 *
 * @date 2008/12/18.
 *
 * @version 1.00.
 *
 * @author Ryouma Kawasue.
 */
/*******************************************************************************/

#include "PlayerTime.h"
#include "Player.h"

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 */
PlayerTime::PlayerTime(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player &player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{
}
/*=========================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
PlayerTime::~PlayerTime()
{
}

/*=========================================================================*/
/**
 * @brief ����������.
 * 
 */
void PlayerTime::Initialize()
{
	m_x = m_player.GetPosition().x + 305.0f;
	m_y = m_player.GetPosition().y + 450.0f;

}

/*=========================================================================*/
/**
 * @brief �I������.
 * 
 */
void PlayerTime::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool PlayerTime::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
 * 
 */
void PlayerTime::RenderObject()
{
	SpriteDesc sd;
	sd.textureID = TEXTUREID_AVATAR1;

	sd.rect = Rect( m_x, m_y, m_x + BLOCK_SIZE, m_y + BLOCK_SIZE );
	m_device.GetGraphicDevice().Render( sd );

}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void PlayerTime::UpdateObject(float frameTimer)
{
}

/*===== EOF ===================================================================*/
