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
Block::Block(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, int blockCID, int blockMID) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_isTerminated(false)
{
	m_x = 400.0f;
	m_y = 0.0f;
	m_size = 50.0f;
	m_blockID[0] = blockCID;
	m_blockID[1] = blockMID;
	InitializeMatrix();
	m_speed = 1.0f;
	m_tx = m_x;
	for(int i=0; i<16; i++){
		for(int j=0; j<9; j++){
			frame[i][j] = 0;
			if(j==0||j==9||i==16){
				frame[i][j]=1;
			}
		}
	}

	device.GetGraphicDevice().LoadTexture(TEXTUREID_TEST,"block.dds",COLORKEYFLAG_NONE);
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

}

/*=============================================================================*/
/**
 * @brief �I������.
 * 
 */
void Block::Terminate()
{
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
	Matrix4 rotate;
	SpriteDesc sd;
	sd.textureID = TEXTUREID_TEST;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			sd.rect = Rect(m_x-(m_size*j),m_y+(m_size*i),m_x+(m_size*(j+1)),m_y+(m_size*(i+1)));
			if(m_blockMatrix[i][j] != 0 ){
				sd.rect = Rect(m_x+(m_size*j)-(m_size*1.5f),m_y+(m_size*i)-(m_size*1.5f),m_x+(m_size*(j+1)-(m_size*1.5f)),m_y+(m_size*(i+1)-(m_size*1.5f)));
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
	float m_bspeed = 7.0f;

	if(m_device.GetInputDevice().GetKeyTrigger(GAMEKEY_LEFT) == true) 
	{
		m_tx += m_size;
	}
	if(m_device.GetInputDevice().GetKeyTrigger(GAMEKEY_RIGHT) == true) 
	{
		m_tx -= m_size;
	}
	if(m_device.GetInputDevice().GetKeyDown(GAMEKEY_UP) == true) 
	{
		m_y -= 1.0f;
	}
	if(m_device.GetInputDevice().GetKeyDown(GAMEKEY_DOWN) == true) 
	{
		m_y += 1.0f;
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
	m_y += m_speed;

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
			if(direction == SPINBLOCK_LEFT) buf[y][x] = m_blockMatrix[x][2 - y];
			else  buf[y][x] = m_blockMatrix[2 - x][y];
		}
	}

	for(int x=0; x<3; x++)
	{
		for(int y=0; y<3; y++)
		{
			m_blockMatrix[y][x] = buf[y][x];
		}
	}
}

/*=============================================================================*/
/**
 * @brief �t�B�[���h��̃u���b�N�̌��݈ʒu�̃C���f�b�N�X���擾����.
 * 
 */
Vector2 Block::GetFieldMatrixPosition()
{
	Vector2 tmp;
	Vector2 fieldPosition = Vector2(300,0);
	tmp.x = (m_tx-fieldPosition.x)/m_size;
	tmp.y = (m_y-fieldPosition.y)/m_size;

	return tmp;
}
/*===== EOF ===================================================================*/