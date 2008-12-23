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
	switch( m_player.GetPlayerParameter().GetPlayerID())
	{
	case(0):
		m_x = m_player.GetPosition().x + 300.0f;
		m_y = m_player.GetPosition().y + 130.0f;
		break;
	case(1):
		m_x = m_player.GetPosition().x + 20.0f;
		m_y = m_player.GetPosition().y + 130.0f;
		break;
	}
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
	GaugeDesc gd1;
	gd1.size = Vector2(100.0f, 20.0f);
	gd1.position = Vector2(m_x, m_y);
	gd1.textureRec1 = Rect(0,0,100,20);
	gd1.textureRec2 = Rect(0,0,100,20);
	gd1.max = 100;
	gd1.point = m_player.GetPlayerParameter().GetPlayerTime();
	gd1.texture1 = TEXTUREID_MAXHP;
	gd1.texture2 = TEXTUREID_HP;
	m_device.GetGraphicDevice().Render( gd1 );

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
