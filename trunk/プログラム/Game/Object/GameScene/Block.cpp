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
	Matrix4 rotate;
	rotate.setTranslate(1.0f,0.5f,0.5f);
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
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void Block::UpdateObject(float frameTimer)
{
	if(m_device.GetInputDevice().GetKeyDown(GAMEKEY_LEFT) == true) 
	{
		m_x += 1.0f;
	}
	if(m_device.GetInputDevice().GetKeyDown(GAMEKEY_RIGHT) == true) 
	{
		m_x -= 1.0f;
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

	m_y += m_speed;
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

/*===== EOF ===================================================================*/