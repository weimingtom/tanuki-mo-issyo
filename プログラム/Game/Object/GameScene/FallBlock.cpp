/*******************************************************************************/
/**
 * @file FallBlock.h.
 * 
 * @brief �t�H�[���u���b�N�N���X��`.
 *
 * @date 2008/12/8.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/

#include "FallBlock.h"
#include "Object/GameScene/Player.h"


/*=========================================================================*/
/**
* @brief �R���X�g���N�^
*/
FallBlock::FallBlock(IGameDevice& device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState, Player& player, float x, float y, int blockID) :
m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false), m_x(x), m_y(y), m_blockID(blockID)
{
	m_speed	= 2.0f;
}
/*=========================================================================*/
/**
 * @brief �f�X�g���N�^.
 * 
 */
FallBlock::~FallBlock()
{

}

/*=========================================================================*/
/**
 * @brief ����������.
 * 
 */
void FallBlock::Initialize()
{

}

/*=========================================================================*/
/**
 * @brief �I������.
 * 
 */
void FallBlock::Terminate()
{
	IntPoint pos = GetFieldMatrixPosition(m_x, m_y);
	m_player.GetPuzzleScreen().GetBlockManager().GetField().SetBlock(pos.x, pos.y, m_blockID);
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool FallBlock::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
 * 
 */
void FallBlock::RenderObject()
{
	SpriteDesc sd;
	sd.textureID = m_blockID;
	
	sd.rect = Rect(m_x,m_y,m_x+(BLOCK_SIZE),m_y+(BLOCK_SIZE));
	m_device.GetGraphicDevice().Render( sd );
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void FallBlock::UpdateObject(float frameTimer)
{
	if(m_gameSceneState.GetGameState() != GAME_STATE_MAIN)
	{
		return;
	}
	FieldMatrix frame;
	IntPoint pos = GetFieldMatrixPosition(m_x, m_y + m_speed + (BLOCK_SIZE));
	m_player.GetPuzzleScreen().GetBlockManager().GetField().GetFieldBlockMatrix(&frame);
	if(!ColisionMatrix(frame,pos.x,pos.y)) 
	{
		m_y += m_speed;
	} else
	{
		m_y = m_player.GetPuzzleScreen().GetBlockManager().GetField().GetPosition().y + ((pos.y)*BLOCK_SIZE) - (BLOCK_SIZE);
		Terminate();
	}
}

/*=============================================================================*/
/**
 * @brief �t�B�[���h����z���
 * 
 * @param[in] x ���̈ʒu.
 * @param[in] y �c�̈ʒu.
 *
 * @return �z��̔ԍ�.
 */
IntPoint FallBlock::GetFieldMatrixPosition(float x, float y)
{
	IntPoint tmp;
	Vector2 fieldPosition = m_player.GetPuzzleScreen().GetBlockManager().GetField().GetPosition();
	tmp.x = (int)((x-fieldPosition.x) / BLOCK_SIZE);
	tmp.y = (int)((y-fieldPosition.y) / BLOCK_SIZE);

	return tmp;
}

/*=============================================================================*/
/**
 * @brief �u���b�N�̉��Ƀu���b�N�����邩
 * 
 * @param[in] matrix �z��.
 * @param[in] x ���̈ʒu.
 * @param[in] y �c�̈ʒu.
 */
bool FallBlock::ColisionMatrix(FieldMatrix matrix, int x, int y)
{
	if(matrix.matrix[x][y] != 0)
	{
		return true;
	}

	return	false;
}
