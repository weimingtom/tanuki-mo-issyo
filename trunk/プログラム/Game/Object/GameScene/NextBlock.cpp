/*******************************************************************************/
/**
 * @file NextBlock.cpp.
 * 
 * @brief �l�N�X�g�u���b�N�N���X�\�[�X��`.
 *
 * @date 2008/12/19.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/

#include	"NextBlock.h"
#include	"Player.h"

/*=============================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 * @param[in] device �Q�[���f�o�C�X.
 * @param[in] objectManager �I�u�W�F�N�g�}�l�[�W��.
 * @param[in] option �Q�[���I�v�V����.
 * @param[in] gameSceneState �Q�[���V�[���X�e�[�g.
 */
NextBlock::NextBlock(IGameDevice& device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState, Player& player)	:
		m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{

	
}

/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
NextBlock::~NextBlock()
{

}

/*=============================================================================*/
/**
 * @brief ����������.
 * 
 */
void NextBlock::Initialize()
{
	switch( m_player.GetPlayerParameter().GetPlayerID())
	{
	case(0):
		m_x = m_player.GetPosition().x + 360.0f;
		m_y = m_player.GetPosition().y + 200.0f;
		break;
	case(1):
		m_x = m_player.GetPosition().x + 30.0f;
		m_y = m_player.GetPosition().y + 200.0f;
		break;
	}
}

/*=============================================================================*/
/**
 * @brief �I������.
 * 
 */
void NextBlock::Terminate()
{

}

/*=============================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool NextBlock::IsTerminated()
{
	return m_isTerminated;

}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
 * 
 */
void NextBlock::RenderObject()
{
	SpriteDesc sd[2];
	sd[0].textureID = m_player.GetPlayerParameter().GetNextCBlock();
	sd[1].textureID = m_player.GetPlayerParameter().GetNextMBlock();

	for( int i = 0; i < 2; i++ ){
		sd[i].rect = Rect(m_x ,m_y + i*30 ,m_x+BLOCK_SIZE ,m_y+BLOCK_SIZE + i*30);
		m_device.GetGraphicDevice().Render( sd[i] );
	}
}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void NextBlock::UpdateObject(float frameTimer)
{

}


/*===== EOF ===================================================================*/
