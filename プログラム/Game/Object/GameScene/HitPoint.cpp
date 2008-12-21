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
	SpriteDesc sd;
	sd.textureID = TEXTUREID_HP;
	
	sd.rect = Rect(m_x ,m_y ,m_x+100 ,m_y+20);
	m_device.GetGraphicDevice().Render( sd );
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
