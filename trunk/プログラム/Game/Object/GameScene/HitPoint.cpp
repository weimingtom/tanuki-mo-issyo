/*******************************************************************************/
/**
 * @file HitPoint.cpp.
 * 
 * @brief �q�b�g�|�C���g�N���X�\�[�X��`.
 *
 * @date 2008/12/15.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/

#include	"HitPoint.h"
#include	"Player.h"

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 */
HitPoint::HitPoint(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player& player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{
	m_player.GetPlayerParameter().GetHp();

}

/*=========================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
HitPoint::~HitPoint()
{

}

/*=========================================================================*/
/**
 * @brief ����������.
 * 
 */
void HitPoint::Initialize()
{
	switch( m_player.GetPlayerParameter().GetPlayerID())
	{
	case(0):
		m_x = m_player.GetPosition().x + 300.0f;
		m_y = m_player.GetPosition().y + 100.0f;
		break;
	case(1):
		m_x = m_player.GetPosition().x + 20.0f;
		m_y = m_player.GetPosition().y + 100.0f;
		break;
	}
}

/*=========================================================================*/
/**
 * @brief �I������.
 * 
 */
void HitPoint::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool HitPoint::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
 * 
 */
void HitPoint::RenderObject()
{

/** �g�o�Q�[�W�\�L */
	TextDesc  ht;
	ht.size		= 19;
	ht.position	= Vector2(m_x, m_y);
	ht.code		= FONT_CODE_NORMAL;
	ht.font		= "HG�s����";
	ht.string	= "�g�o";
	m_device.GetGraphicDevice().Render( ht );

	GaugeDesc gd1;
	gd1.size = Vector2(100.0f, 20.0f);
	gd1.position = Vector2(m_x, m_y);
	gd1.textureRec2 = Rect(0,0,128,32);
	gd1.textureRec1 = Rect(0,32,128,64);
	gd1.max = m_player.GetPlayerParameter().GetMaxHp();
	gd1.point = m_player.GetPlayerParameter().GetHp();
	gd1.texture1 = TEXTUREID_HP;
	gd1.texture2 = TEXTUREID_HP;
	m_device.GetGraphicDevice().Render( gd1 );
/*
	SpriteDesc box;
	box.textureID = TEXTUREID_HPBOX;
	box.rect = Rect(m_x - 20.0f ,m_y - 5.0f ,m_x+110.0f ,m_y+25.0f);
	m_device.GetGraphicDevice().Render( box );
*/


}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void HitPoint::UpdateObject(float frameTimer)
{

}


/*===== EOF ===================================================================*/
