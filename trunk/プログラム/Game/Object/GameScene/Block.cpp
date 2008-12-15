/*******************************************************************************/
/*
 * @file Block.cpp.
 * 
 * @brief �u���b�N�N���X��`.
 *
 * @date 2008/12/01.
 *
 * @version 1.00.
 *
 * @author Tsubasa Uragami.
 */
/*******************************************************************************/

/*===== �C���N���[�h ==========================================================*/
#include	"Object/GameScene/Block.h"
#include	"Define/TextureID.h"
#include	"Define/EffectID.h"
#include "Object/GameScene/Player.h"


/*=============================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 * @param[in] device �Q�[���f�o�C�X.
 * @param[in] objectManager �I�u�W�F�N�g�}�l�[�W��.
 * @param[in] option �Q�[���I�v�V����.
 * @param[in] gameSceneState �Q�[���V�[���X�e�[�g.
 * @param[in] blockCID ���̃u���b�N��ID.
 * @param[in] blockMID �T�u�̃u���b�N��ID.
 */
Block::Block(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player &player, int blockCID, int blockMID) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{
	m_blockID[0] = blockCID;
	m_blockID[1] = blockMID;
	InitializeMatrix();
	m_speed = 1.0f;
	m_timer = 60;
}

/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
Block::~Block()
{

}

/*=============================================================================*/
/**
 * @brief ����������.
 * 
 */
void Block::Initialize()
{
	m_x = m_player.GetPosition().x + (BLOCK_SIZE * FIELD_WIDTH / 2);
	m_y = m_player.GetPosition().y;
	m_tx = m_x;
	m_ty = m_y;
	m_angle = 0;
}

/*=============================================================================*/
/**
 * @brief �I������.
 * 
 */
void Block::Terminate()
{
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(m_blockMatrix[i][j] != 0 ){
				m_player.GetPuzzleScreen().GetBlockManager().AddFallBlock(new FallBlock(m_device,m_objectManager,m_option,m_gameSceneState,m_player,m_tx+(BLOCK_SIZE*(j-1)),m_ty+(BLOCK_SIZE*(i-1)),m_blockMatrix[i][j]));
			}
		}
	}
	m_isTerminated = true;
}

/*=============================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool Block::IsTerminated()
{
	return m_isTerminated;
}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
 * 
 */
void Block::RenderObject()
{

	SpriteDesc sd;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(m_blockMatrix[i][j] != 0 ){
				sd.rect = Rect(m_x+(BLOCK_SIZE*j)-(BLOCK_SIZE*1.5f),m_y+(BLOCK_SIZE*i)-(BLOCK_SIZE*1.5f),m_x+(BLOCK_SIZE*(j+1)-(BLOCK_SIZE*1.5f)),m_y+(BLOCK_SIZE*(i+1)-(BLOCK_SIZE*1.5f)));
				sd.textureID = m_blockMatrix[i][j];
				m_device.GetGraphicDevice().Render( sd );
			}
		}
	}
}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void Block::UpdateObject(float frameTimer)
{
	m_player.GetPuzzleScreen().GetBlockManager().GetField().GetFieldBlockMatrix(&frame);
	

	IntPoint MatrixPosition;
	MatrixPosition.x = GetFieldMatrixPosition(m_tx, m_ty + (BLOCK_SIZE/2)).x;
	MatrixPosition.y = GetFieldMatrixPosition(m_tx, m_ty + (BLOCK_SIZE/2)).y;

	float m_bspeed = 5.0f;

	if(m_player.GetAI().GetKeyTrigger(GAMEKEY_LEFT) == true ) 
	{
		if(!ColisionMatrix(frame,MatrixPosition.x+1,MatrixPosition.y)){
			m_tx += BLOCK_SIZE;
		}
	}
	if(m_player.GetAI().GetKeyTrigger(GAMEKEY_RIGHT) == true ) 
	{
		if(!ColisionMatrix(frame,MatrixPosition.x-1,MatrixPosition.y)){
			m_tx -= BLOCK_SIZE;
		}
	}
	if(m_player.GetAI().GetKeyDown(GAMEKEY_UP) == true) 
	{
		m_ty = m_player.GetPosition().y;
	}
	if(m_player.GetAI().GetKeyDown(GAMEKEY_DOWN) == true) 
	{
		if(!ColisionMatrix(frame,MatrixPosition.x,MatrixPosition.y+1)){
			m_ty += 1.0f;
		} else
		{
			m_timer = 0;
		}
	}

	if(!ColisionMatrix(frame,MatrixPosition.x,GetFieldMatrixPosition(m_tx, m_ty + m_speed + (BLOCK_SIZE/2)).y)) 
	{
		m_ty += m_speed;
	} else
	{
		m_timer --;
		if(m_timer < 0) Terminate();
		m_ty = m_player.GetPuzzleScreen().GetBlockManager().GetField().GetPosition().y + ((GetFieldMatrixPosition(m_tx, m_ty + m_speed + (BLOCK_SIZE/2)).y)*BLOCK_SIZE) - (BLOCK_SIZE/2) -0.01f;
	}

	if(m_device.GetInputDevice().GetKeyTrigger(GAMEKEY_CIRCLE) == true)
	{
	
		SpinBlock(SPINBLOCK_RIGHT);
	}
	if(m_device.GetInputDevice().GetKeyTrigger(GAMEKEY_TRIANGLE) == true)
	{
		SpinBlock(SPINBLOCK_LEFT);
	}


	if(m_x<m_tx)
	{
		m_x += m_bspeed;
		if(m_x>m_tx)
		{
			m_x = m_tx;
		}
	}
	else if(m_x>m_tx)
	{
		m_x -= m_bspeed;
		if(m_x<m_tx)
		{
			m_x = m_tx;
		}
	}

	if(m_y<m_ty)
	{
		m_y += m_bspeed;
		if(m_y>m_ty)
		{
			m_y = m_ty;
		}
	}
	else if(m_y>m_ty)
	{
		m_y -= m_bspeed;
		if(m_y<m_ty)
		{
			m_y = m_ty;
		}
	}


}

/*=============================================================================*/
/**
 * @brief �u���b�N�z��̏�����.
 * 
 */
void Block::InitializeMatrix()
{
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			m_blockMatrix[i][j] = 0;
		}
	}
	m_blockMatrix[1][1] = m_blockID[0];
	m_blockMatrix[2][1] = m_blockID[1];
}

/*=============================================================================*/
/**
 * @brief �u���b�N�̉�].
 * 
 * @param[in] direction ��]�����萔.
 */
void Block::SpinBlock(int direction)
{
	int buf[3][3];
	for(int x=0; x<3; x++)
	{
		for(int y=0; y<3; y++)
		{
			buf[y][x] = 0;
			if(direction == SPINBLOCK_LEFT)
			{
				m_angle --;
				if(m_angle < 0 )
				{
					m_angle = 3;
				}
				buf[y][x] = m_blockMatrix[x][2 - y];
			} else
			{
				m_angle ++;
				if(m_angle > 3 )
				{
					m_angle = 0;
				}
				buf[y][x] = m_blockMatrix[2 - x][y];
			}
		}
	}

	for(int x=0; x<3; x++)
	{
		for(int y=0; y<3; y++)
		{
			m_blockMatrix[y][x] = buf[y][x];
		}
	}
	
	IntPoint MatrixPosition;
	MatrixPosition.x = GetFieldMatrixPosition(m_tx, m_ty + (BLOCK_SIZE/2)).x;
	MatrixPosition.y = GetFieldMatrixPosition(m_tx, m_ty + (BLOCK_SIZE/2)).y;

	if(ColisionMatrix(frame,MatrixPosition.x,MatrixPosition.y))
	{
			switch(m_angle)
			{
			case 0:
				m_ty -= BLOCK_SIZE;
				if(ColisionMatrix(frame,GetFieldMatrixPosition(m_tx, m_ty + (BLOCK_SIZE/2)).x,GetFieldMatrixPosition(m_tx, m_ty + (BLOCK_SIZE/2)).y))
				{
					m_ty += BLOCK_SIZE;
					SpinBlock(direction);
				}
				break;
			case 1:
				m_tx += BLOCK_SIZE;
				if(ColisionMatrix(frame,GetFieldMatrixPosition(m_tx, m_ty + (BLOCK_SIZE/2)).x,GetFieldMatrixPosition(m_tx, m_ty + (BLOCK_SIZE/2)).y))
				{
					m_tx -= BLOCK_SIZE;
					SpinBlock(direction);
				}
				break;
			case 3:
				m_tx -= BLOCK_SIZE;
				if(ColisionMatrix(frame,GetFieldMatrixPosition(m_tx, m_ty + (BLOCK_SIZE/2)).x,GetFieldMatrixPosition(m_tx, m_ty + (BLOCK_SIZE/2)).y))
				{
					m_tx += BLOCK_SIZE;
					SpinBlock(direction);
				}
				break;
			}
	}
}

/*=============================================================================*/
/**
 * @brief �t�B�[���h��̃u���b�N�̌��݈ʒu�̃C���f�b�N�X���擾����.
 * 
 */
IntPoint Block::GetFieldMatrixPosition(float x, float y)
{
	IntPoint tmp;
	Vector2 fieldPosition = m_player.GetPuzzleScreen().GetBlockManager().GetField().GetPosition();
	tmp.x = (int)((x-fieldPosition.x) / BLOCK_SIZE);
	tmp.y = (int)((y-fieldPosition.y) / BLOCK_SIZE);

	return tmp;
}

bool	Block::ColisionMatrix(FieldMatrix matrix,int x,int y)
{
	for(int ax=0;ax<3;ax++)
	{
		for(int ay=0;ay<3;ay++)
		{
			if((matrix.matrix[x-1+ax][y-1+ay] != 0) && (m_blockMatrix[ay][ax] != 0))
			{
				return true;
			}
		}
	}

	return	false;
}

/*===== EOF ===================================================================*/
