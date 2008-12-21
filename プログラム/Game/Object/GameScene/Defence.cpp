/*******************************************************************************/
/**
 * @file Defence.cpp.
 * 
 * @brief �A�^�b�N�N���X�\�[�X��`.
 *
 * @date 2008/12/21.
 *
 * @version 1.00.
 *
 * @author Ryouma Kawasue.
 */
/*******************************************************************************/

#include "Defence.h"
#include "Player.h"

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 */
Defence::Defence(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player &player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{
}
/*=========================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
	Defence::~Defence()
{
}

/*=========================================================================*/
/**
 * @brief ����������.
 * 
 */
void Defence::Initialize()
{
	m_x = m_player.GetPosition().x + 300.0f;
	m_y = m_player.GetPosition().y + 20.0f;

}

/*=========================================================================*/
/**
 * @brief �I������.
 * 
 */
void Defence::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool Defence::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
 * 
 */
void Defence::RenderObject()
{
	SpriteDesc sd;
	sd.textureID = TEXTUREID_POWER;

	sd.rect = Rect( m_x, m_y, m_x + 256, m_y + BLOCK_SIZE );
	m_device.GetGraphicDevice().Render( sd );

}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void Defence::UpdateObject(float frameTimer)
{
}

/*===== EOF ===================================================================*/
