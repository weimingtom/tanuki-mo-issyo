/*******************************************************************************/
/*
 * @file Field.cpp.
 * 
 * @brief �t�@�C������.
 *
 * @date 2008/12/08.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/

/*===== �C���N���[�h ==========================================================*/
#include "Object/GameScene/Field.h"
#include "Object/GameScene/Player.h"
#include "Define/GameDefine.h"
#include <iostream>

/*===== �萔�錾 ==============================================================*/


/*=============================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 * @param[in] device �Q�[���f�o�C�X.
 * @param[in] objectManager �I�u�W�F�N�g�}�l�[�W��.
 * @param[in] option �Q�[���I�v�V����.
 * @param[in] gameSceneState �Q�[���V�[���X�e�[�g.
 */
Field::Field(IGameDevice& device, ObjectManager& objectManager, Option &option, GameSceneState& gameSceneState, Player &player) :
m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{
	for(int i=0; i<FIELD_WIDTH;i++)
	{
		for(int j=0;j<FIELD_HEIGHT;j++)
		{
			m_fieldBlock[i][j] = 0;
		}
	}
	for(int i=0; i<FIELD_HEIGHT; i++)
	{
		m_fieldBlock[0][i] = 255;
		m_fieldBlock[FIELD_WIDTH - 1][i] = 255;
	}
	for(int i=1; i<FIELD_WIDTH - 1; i++)
	{
		m_fieldBlock[i][FIELD_HEIGHT - 1] = 255;
	}

}

/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
Field::~Field()
{

}

/*=============================================================================*/
/**
 * @brief ����������.
 * 
 */
void Field::Initialize()
{
	switch( m_player.GetPlayerParameter().GetPlayerID())
	{
	case(0):
		m_x = m_player.GetPosition().x + 0.0f;
		m_y = m_player.GetPosition().y + 0.0f;
		break;
	case(1):
		m_x = m_player.GetPosition().x + 150.0f;
		m_y = m_player.GetPosition().y + 0.0f;
		break;
	}
}

/*=============================================================================*/
/**
 * @brief �I������.
 * 
 */
void Field::Terminate()
{
	m_isTerminated = true;
}

/*=============================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool Field::IsTerminated()
{
	return m_isTerminated;

}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
 * 
 */
void Field::RenderObject()
{
	
	SpriteDesc sd;
	for(int x=0; x<FIELD_WIDTH; x++){
		for(int y=0; y<FIELD_HEIGHT; y++){
			if(m_fieldBlock[x][y] != 0 ){
				sd.rect = Rect(m_x+(BLOCK_SIZE*x),m_y+(BLOCK_SIZE*y),m_x+(BLOCK_SIZE*(x+1)),m_y+(BLOCK_SIZE*(y+1)));
				if(m_fieldBlock[x][y] != 255)
				{
					sd.textureID = m_fieldBlock[x][y];
				} else
				{
					continue;
					sd.textureID = TEXTUREID_SBLOCK4;
				}
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
void Field::UpdateObject(float frameTimer)
{

	if(m_player.GetPuzzleScreen().GetBlockManager().GetFallBlockNum() == 0)
	{
		CheckBlock();

		ChangeToFallBlock();
		if(m_player.GetPuzzleScreen().GetBlockManager().GetFallBlockNum() == 0)
		{
			m_player.GetPuzzleScreen().GetBlockManager().CreateBlock();
		}
	}

}

/*=============================================================================*/
/**
 * @brief �t�B�[���h�̃u���b�N�̔z���Ԃ�.
 * 
 * @param[in] fieldmatrix �t�B�[���h�̏��.
 */
void Field::GetFieldBlockMatrix(FieldMatrix* fieldMatrix)
{
	for(int x=0; x<FIELD_WIDTH; x++){
		for(int y=0; y<FIELD_HEIGHT; y++){
			fieldMatrix->matrix[x][y] = m_fieldBlock[x][y];
		}
	}
}

/*=============================================================================*/
/**
 * @brief �t�B�[���h�̂����Ă���X�e�[�g��Ԃ�.
 * 
 * @param[in] fieldmatrix �t�B�[���h�̏��.
 */
void Field::GetFieldStateMatrix(FieldMatrix* fieldMatrix)
{
	for(int x=0; x<FIELD_WIDTH; x++){
		for(int y=0; y<FIELD_HEIGHT; y++){
			fieldMatrix->matrix[x][y] = m_fieldState[x][y];
		}
	}
}

/*=============================================================================*/
/**
 * @brief �t�B�[���h�̃|�W�V������Ԃ�.
 * 
 *@return ���W.
 */
Vector2 Field::GetPosition()
{
	return Vector2(m_x,m_y);
}

/*=============================================================================*/
/**
 * @brief �u���b�N��u��.
 * 
 * @param[in] x ���̈ʒu.
 * @param[in] y �c�̈ʒu.
 * @param[in] id �u���b�N�̂h�c.
 */
void Field::SetBlock(int x, int y, int id)
{
	if((FIELD_WIDTH <= x) || (FIELD_HEIGHT <= y) ||
		(x < 0) || (y < 0 ))
	{
		return;
	}
	m_fieldBlock[x][y] = id;
}

/*=============================================================================*/
/**
 * @brief �u���b�N�̃`�F�b�N1.
 * 
 * @return ����
 */
void Field::CheckBlock( void )
{
	CheckMatrix checkMatrix;
	for(int x=0; x< FIELD_WIDTH; x++)
	{
		for(int y=0; y<FIELD_HEIGHT; y++)
		{
			checkMatrix.checkedmatrix[x][y] = false;
		}
	}

	for( int i = 0; i < FIELD_WIDTH; i++ ){
			for( int j = 0 ; j < FIELD_HEIGHT; j++  ){
				if( (m_fieldBlock[i][j] != 0) && (m_fieldBlock[i][j] != 255) ){
					int	num = 0;
						BlockCount( i, j, m_fieldBlock[i][j], num , checkMatrix);
					if(num >= 4)
					{
						int* skill;
						skill = m_player.GetPlayerParameter().GetSkillPoint();
						switch(m_fieldBlock[i][j])
						{
						case TEXTUREID_BLOCK1:
							m_player.GetPlayerParameter().SetPlayerAttack(m_player.GetPlayerParameter().GetPlayerAttack() + 10);
							break;
						case TEXTUREID_BLOCK2:
							m_player.GetPlayerParameter().SetPlayerDefence(m_player.GetPlayerParameter().GetPlayerDefence() + 10);
							break;
						case TEXTUREID_BLOCK3:
							m_player.GetPlayerParameter().SetHp(m_player.GetPlayerParameter().GetHp() + 10);
							break;
						case TEXTUREID_SBLOCK1:
							skill[0] ++;
							m_player.GetPlayerParameter().SetSkillPoint(skill);
							break;
						case TEXTUREID_SBLOCK2:
							skill[1] ++;
							m_player.GetPlayerParameter().SetSkillPoint(skill);
							break;
						case TEXTUREID_SBLOCK3:
							skill[2] ++;
							m_player.GetPlayerParameter().SetSkillPoint(skill);
							break;
						case TEXTUREID_SBLOCK4:
							skill[3] ++;
							m_player.GetPlayerParameter().SetSkillPoint(skill);
							break;
						}
						BlockDelete(i, j);
						m_player.GetPlayerParameter().SetScore(m_player.GetPlayerParameter().GetScore() + (num * 10));
					}
			}
		}
	}
}

/*=============================================================================*/
/**
 * @brief �u���b�N�̃`�F�b�N2.
 * 
 * @return ����
 */
void Field::BlockCount(int x ,int y ,int id , int &num, CheckMatrix & checkMatrix)
{
	if(checkMatrix.checkedmatrix[x][y])
	{
		return;
	}
	int buf = m_fieldBlock[x][y];
	m_fieldBlock[x][y] = 0;
	checkMatrix.checkedmatrix[x][y] = true;
	num++;

	if(m_fieldBlock[x][y+1] == id ){
		BlockCount(x, y+1, id, num, checkMatrix);
	}

	if(m_fieldBlock[x][y-1] == id ){
		BlockCount(x, y-1, id, num, checkMatrix);
	}

	if(m_fieldBlock[x+1][y] == id ){
		BlockCount(x+1, y, id, num, checkMatrix);
	}

	if(m_fieldBlock[x-1][y] == id ){
		BlockCount(x-1, y, id, num, checkMatrix);
	}

	m_fieldBlock[x][y] = buf;
}

void Field::BlockDelete(int x ,int y)
{
	int id = m_fieldBlock[x][y];
	m_fieldBlock[x][y] = 0;

	if(m_fieldBlock[x][y+1] == id ){
		BlockDelete(x, y+1);
	}

	if(m_fieldBlock[x][y-1] == id ){
		BlockDelete(x, y-1);
	}

	if(m_fieldBlock[x+1][y] == id ){
		BlockDelete(x+1, y);
	}

	if(m_fieldBlock[x-1][y] == id ){
		BlockDelete(x-1, y);
	}
}

void Field::ChangeToFallBlock()
{
	for(int x=0; x<FIELD_WIDTH; x++)
	{
		bool isFloat = false;
		for(int y=FIELD_HEIGHT-1; y>=0; y--)
		{
			if(m_fieldBlock[x][y] == 0)
			{
				isFloat = true;
			}
			if((isFloat) && (m_fieldBlock[x][y] != 0))
			{
				m_player.GetPuzzleScreen().GetBlockManager().AddFallBlock(new FallBlock(
					m_device,m_objectManager,m_option,m_gameSceneState,m_player,
					m_x + (BLOCK_SIZE * x) ,m_y + (BLOCK_SIZE * y),m_fieldBlock[x][y]));
				m_fieldBlock[x][y] = 0;
			}
		}
	}
}

/*===== EOF ===================================================================*/