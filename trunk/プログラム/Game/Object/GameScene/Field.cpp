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


	device.GetGraphicDevice().LoadTexture(TEXTUERID_BLOCK2,"block2.dds",COLORKEYFLAG_NONE);
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
	m_x = m_player.GetPosition().x;
	m_y = m_player.GetPosition().y;
}

/*=============================================================================*/
/**
 * @brief �I������.
 * 
 */
void Field::Terminate()
{

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
	sd.textureID = TEXTUERID_BLOCK2;
	for(int x=0; x<FIELD_WIDTH; x++){
		for(int y=0; y<FIELD_HEIGHT; y++){
			if(m_fieldBlock[x][y] != 0 ){
				sd.rect = Rect(m_x+(BLOCK_SIZE*x),m_y+(BLOCK_SIZE*y),m_x+(BLOCK_SIZE*(x+1)),m_y+(BLOCK_SIZE*(y+1)));
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

}

void Field::GetFieldBlockMatrix(FieldMatrix* fieldMatrix)
{
	for(int x=0; x<FIELD_WIDTH; x++){
		for(int y=0; y<FIELD_HEIGHT; y++){
			fieldMatrix->matrix[x][y] = m_fieldBlock[x][y];
		}
	}
}

void Field::GetFieldStateMatrix(FieldMatrix* fieldMatrix)
{
	for(int x=0; x<FIELD_WIDTH; x++){
		for(int y=0; y<FIELD_HEIGHT; y++){
			fieldMatrix->matrix[x][y] = m_fieldState[x][y];
		}
	}
}

Vector2 Field::GetPosition()
{
	return Vector2(m_x,m_y);
}
/*===== EOF ===================================================================*/