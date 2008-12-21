/*******************************************************************************/
/**
 * @file SkillPoint.cpp.
 * 
 * @brief �X�L���|�C���g�N���X�\�[�X��`.
 *
 * @date 2008/12/15.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/

#include	"SkillPoint.h"
#include	"Player.h"

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 */
SkillPoint::SkillPoint(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player& player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{

}

/*=========================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
SkillPoint::~SkillPoint()
{

}

/*=========================================================================*/
/**
 * @brief ����������.
 * 
 */
void SkillPoint::Initialize()
{
	switch( m_player.GetPlayerParameter().GetPlayerID())
	{
	case(0):
		m_x = m_player.GetPuzzleScreen().GetBlockManager().GetField().GetPosition().x + 30.0f;
		m_y = m_player.GetPuzzleScreen().GetBlockManager().GetField().GetPosition().y + 500.0f;
		break;
	case(1):
		m_x = m_player.GetPuzzleScreen().GetBlockManager().GetField().GetPosition().x + 30.0f;
		m_y = m_player.GetPuzzleScreen().GetBlockManager().GetField().GetPosition().y + 500.0f;
		break;
	}
}

/*=========================================================================*/
/**
 * @brief �I������.
 * 
 */
void SkillPoint::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool SkillPoint::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
 * 
 */
void SkillPoint::RenderObject()
{
	SpriteDesc sd[4];
	sd[0].textureID = TEXTUREID_SKILL;
	sd[1].textureID = TEXTUREID_SKILL;
	sd[2].textureID = TEXTUREID_SKILL;
	sd[3].textureID = TEXTUREID_SKILL;
	
	for( int i = 0; i < 4; i++ )
	{
		sd[i].rect = Rect(m_x + i*60 ,m_y ,m_x+BLOCK_SIZE + i*60 ,m_y+BLOCK_SIZE);
		m_device.GetGraphicDevice().Render( sd[i] );
	}
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void SkillPoint::UpdateObject(float frameTimer)
{

}


/*===== EOF ===================================================================*/
