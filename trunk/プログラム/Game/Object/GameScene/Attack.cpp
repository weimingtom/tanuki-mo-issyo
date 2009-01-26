/*******************************************************************************/
/**
 * @file Attack.cpp.
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

#include "Attack.h"
#include "Player.h"

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 */
Attack::Attack(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player &player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{
}
/*=========================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
	Attack::~Attack()
{
}

/*=========================================================================*/
/**
 * @brief ����������.
 * 
 */
void Attack::Initialize()
{
	switch( m_player.GetPlayerParameter().GetPlayerID() )
	{
	case(0):
		/*
		m_x = m_player.GetPosition().x + 300.0f;
		m_y = m_player.GetPosition().y + 60.0f;
		*/
		m_x = m_option.m_attackSpriteInfo.position.x;
		m_y = m_option.m_attackSpriteInfo.position.y;
		break;
	case(1):
		m_x = m_player.GetPosition().x + 20.0f;
		m_y = m_player.GetPosition().y + 60.0f;
		break;
	}

}

/*=========================================================================*/
/**
 * @brief �I������.
 * 
 */
void Attack::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool Attack::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
 * 
 */
void Attack::RenderObject()
{
	//�A�^�b�N�Q�[�W

	TextDesc at1;
	at1.code = FONT_CODE_NORMAL;
	at1.font = "HGP����B";
	at1.position = Vector2(m_x+22.5f,m_y);
	at1.size = 20;
	at1.string = "�U����";
	m_device.GetGraphicDevice().Render( at1 );


	GaugeDesc gd1;
	gd1.size = Vector2(m_option.m_attackSpriteInfo.size.x, m_option.m_attackSpriteInfo.size.y);
	gd1.position = Vector2(m_x, m_y);
	gd1.textureRec2 = Rect(0,0,128,32);
	gd1.textureRec1 = Rect(0,32,128,64);
	gd1.max = 100;
	gd1.point = (float)m_player.GetPlayerParameter().GetPlayerAttack();
	gd1.texture1 = TEXTUREID_HP;
	gd1.texture2 = TEXTUREID_HP;
	m_device.GetGraphicDevice().Render( gd1 );

	

}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void Attack::UpdateObject(float frameTimer)
{
}

/*===== EOF ===================================================================*/
