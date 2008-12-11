/*******************************************************************************/
/*
 * @file Block.cpp.
 * 
 * @brief ブロッククラス定義.
 *
 * @date 2008/12/01.
 *
 * @version 1.00.
 *
 * @author Tsubasa Uragami.
 */
/*******************************************************************************/

/*===== インクルード ==========================================================*/
#include	"Object/GameScene/Block.h"
#include	"Define/TextureID.h"
#include	"Define/EffectID.h"
#include "Object/GameScene/Player.h"

#include <iostream>


/*=============================================================================*/
/**
 * @brief コンストラクタ.
 * 
 * @param[in] device ゲームデバイス.
 * @param[in] objectManager オブジェクトマネージャ.
 * @param[in] option ゲームオプション.
 * @param[in] gameSceneState ゲームシーンステート.
 * @param[in] blockCID 軸のブロックのID.
 * @param[in] blockMID サブのブロックのID.
 */
Block::Block(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player &player, int blockCID, int blockMID) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{
	m_blockID[0] = blockCID;
	m_blockID[1] = blockMID;
	InitializeMatrix();
	m_speed = 1.0f;
	
	for(int i=0; i<FIELD_WIDTH;i++)
	{
		for(int j=0;j<FIELD_HEIGHT;j++)
		{
			frame.matrix[i][j] = 0;
		}
	}
	for(int i=0; i<FIELD_HEIGHT; i++)
	{
		frame.matrix[0][i] = 255;
		frame.matrix[FIELD_WIDTH - 1][i] = 255;
	}
	for(int i=1; i<FIELD_WIDTH - 1; i++)
	{
		frame.matrix[i][FIELD_HEIGHT - 1] = 255;
	}
	

	device.GetGraphicDevice().LoadTexture(TEXTUREID_TEST,"block.dds",COLORKEYFLAG_NONE);
}

/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
Block::~Block()
{

}

/*=============================================================================*/
/**
 * @brief 初期化処理.
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
 * @brief 終了処理.
 * 
 */
void Block::Terminate()
{
	m_isTerminated = true;
}

/*=============================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool Block::IsTerminated()
{
	return m_isTerminated;
}

/*=============================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void Block::RenderObject()
{

	SpriteDesc sd;
	sd.textureID = TEXTUREID_TEST;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			sd.rect = Rect(m_x-(BLOCK_SIZE*j),m_y+(BLOCK_SIZE*i),m_x+(BLOCK_SIZE*(j+1)),m_y+(BLOCK_SIZE*(i+1)));
			if(m_blockMatrix[i][j] != 0 ){
				sd.rect = Rect(m_x+(BLOCK_SIZE*j)-(BLOCK_SIZE*1.5f),m_y+(BLOCK_SIZE*i)-(BLOCK_SIZE*1.5f),m_x+(BLOCK_SIZE*(j+1)-(BLOCK_SIZE*1.5f)),m_y+(BLOCK_SIZE*(i+1)-(BLOCK_SIZE*1.5f)));
				m_device.GetGraphicDevice().Render( sd );
			}
		}
	}
}

/*=============================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void Block::UpdateObject(float frameTimer)
{
	m_player.GetPuzzleScreen().GetBlockManager().GetField().GetFieldBlockMatrix(&frame);
	

	Vector2	MatrixPosition;
	MatrixPosition.x = (int)((m_tx - m_player.GetPuzzleScreen().GetBlockManager().GetField().GetPosition().x) / BLOCK_SIZE);
	MatrixPosition.y = (int)((m_y - m_player.GetPuzzleScreen().GetBlockManager().GetField().GetPosition().y + (BLOCK_SIZE/2)) / BLOCK_SIZE);

	float m_bspeed = 5.0f;

	std::cout << m_angle<< std::endl;

	if(m_device.GetInputDevice().GetKeyTrigger(GAMEKEY_LEFT) == true ) 
	{
		if(!ColisionMatrix(frame,MatrixPosition.x+1,MatrixPosition.y)){
			m_tx += BLOCK_SIZE;
		}
	}
	if(m_device.GetInputDevice().GetKeyTrigger(GAMEKEY_RIGHT) == true ) 
	{
		if(!ColisionMatrix(frame,MatrixPosition.x-1,MatrixPosition.y)){
			m_tx -= BLOCK_SIZE;
		}
	}
	if(m_device.GetInputDevice().GetKeyDown(GAMEKEY_UP) == true) 
	{
		m_ty -= 1.0f;
	}
	if(m_device.GetInputDevice().GetKeyDown(GAMEKEY_DOWN) == true) 
	{
		if(!ColisionMatrix(frame,MatrixPosition.x,MatrixPosition.y+1)){
			m_ty += 1.0f;
		}
	}
	if(m_device.GetInputDevice().GetKeyTrigger(GAMEKEY_CIRCLE) == true)
	{
		SpinBlock(SPINBLOCK_RIGHT);
		if(ColisionMatrix(frame,MatrixPosition.x,MatrixPosition.y))
		{
			switch(m_angle)
			{
			case 0:
				m_ty -= BLOCK_SIZE;
				break;
			case 1:
				m_tx += BLOCK_SIZE;
				break;
			case 3:
				m_tx -= BLOCK_SIZE;
				break;
			}
		}
	}
	if(m_device.GetInputDevice().GetKeyTrigger(GAMEKEY_TRIANGLE) == true)
	{
		SpinBlock(SPINBLOCK_LEFT);
		if(ColisionMatrix(frame,MatrixPosition.x,MatrixPosition.y))
		{
			switch(m_angle)
			{
			case 0:
				m_ty -= BLOCK_SIZE;
				break;
			case 1:
				m_tx += BLOCK_SIZE;
				break;
			case 3:
				m_tx -= BLOCK_SIZE;
				break;
			}
		}
	}

	if(!ColisionMatrix(frame,MatrixPosition.x,
		(int)((m_y - m_player.GetPuzzleScreen().GetBlockManager().GetField().GetPosition().y + (BLOCK_SIZE/2) + m_speed) / BLOCK_SIZE))) 
	{
		m_ty += m_speed;
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
 * @brief ブロック配列の初期化.
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
 * @brief ブロックの回転.
 * 
 * @param[in] direction 回転方向定数.
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
}

/*=============================================================================*/
/**
 * @brief フィールド上のブロックの現在位置のインデックスを取得する.
 * 
 */
Vector2 Block::GetFieldMatrixPosition()
{
	Vector2 tmp;
	Vector2 fieldPosition = Vector2(300,0);
	tmp.x = (m_tx-fieldPosition.x)/BLOCK_SIZE;
	tmp.y = (m_y-fieldPosition.y)/BLOCK_SIZE;

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
