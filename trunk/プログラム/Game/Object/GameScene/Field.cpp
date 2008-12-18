/*******************************************************************************/
/*
 * @file Field.cpp.
 * 
 * @brief ファイル説明.
 *
 * @date 2008/12/08.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/

/*===== インクルード ==========================================================*/
#include "Object/GameScene/Field.h"
#include "Object/GameScene/Player.h"
#include "Define/GameDefine.h"

/*===== 定数宣言 ==============================================================*/


/*=============================================================================*/
/**
 * @brief コンストラクタ.
 * 
 * @param[in] device ゲームデバイス.
 * @param[in] objectManager オブジェクトマネージャ.
 * @param[in] option ゲームオプション.
 * @param[in] gameSceneState ゲームシーンステート.
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
 * @brief デストラクタ.
 *
 */
Field::~Field()
{

}

/*=============================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void Field::Initialize()
{
	m_x = m_player.GetPosition().x;
	m_y = m_player.GetPosition().y;
}

/*=============================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void Field::Terminate()
{
	m_isTerminated = true;
}

/*=============================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool Field::IsTerminated()
{
	return m_isTerminated;

}

/*=============================================================================*/
/**
 * @brief オブジェクトの描画処理.
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
					//continue;
					sd.textureID = TEXTUERID_SBLOCK4;
				}
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
void Field::UpdateObject(float frameTimer)
{

	if(m_player.GetPuzzleScreen().GetBlockManager().GetFallBlockNum() == 0)
	{
		CheckBlock();

		m_player.GetPuzzleScreen().GetBlockManager().CreateBlock();
	}

}

/*=============================================================================*/
/**
 * @brief フィールドのブロックの配列を返す.
 * 
 * @param[in] fieldmatrix フィールドの状態.
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
 * @brief フィールドのもっているステートを返す.
 * 
 * @param[in] fieldmatrix フィールドの状態.
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
 * @brief フィールドのポジションを返す.
 * 
 *@return 座標.
 */
Vector2 Field::GetPosition()
{
	return Vector2(m_x,m_y);
}

/*=============================================================================*/
/**
 * @brief ブロックを置く.
 * 
 * @param[in] x 横の位置.
 * @param[in] y 縦の位置.
 * @param[in] id ブロックのＩＤ.
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
 * @brief ブロックのチェック1.
 * 
 * @return 無し
 */
void Field::CheckBlock( void )
{
	CheckMatrix checkMatrix;

	for( int i = 0; i < FIELD_WIDTH; i++ ){
			for( int j = 0 ; j < FIELD_HEIGHT; j++  ){
				if( m_fieldBlock[i][j] != 0 ){
					int id;
					int	num = 0;
					id = m_fieldBlock[i][j];
					num = BlockCount( i, j, id, num , checkMatrix);

			}
		}
	}
}

/*=============================================================================*/
/**
 * @brief ブロックのチェック2.
 * 
 * @return 無し
 */
int Field::BlockCount(int x ,int y ,int id , int num, CheckMatrix & checkMatrix)
{

	if( m_fieldBlock[x][y+1] == id ){
		num++;
		checkMatrix.checkedmatrix[x][y+1] = true;
		num = BlockCount(x, y+1, id, num, checkMatrix);
		if( num >= 4 ){
			checkMatrix.deleteflagmatrix[x][y+1] = true;
		}
	}

	if( m_fieldBlock[x][y-1] == id ){
		num++;
		checkMatrix.checkedmatrix[x][y-1] = true;
		num = BlockCount(x, y-1, id, num, checkMatrix);
		if( num >= 4 ){
			checkMatrix.deleteflagmatrix[x][y-1] = true;
		}
	}

	if( m_fieldBlock[x+1][y] == id ){
		num++;
		checkMatrix.checkedmatrix[x+1][y] = true;
		num = BlockCount(x+1, y, id, num, checkMatrix);
		if( num >= 4 ){
			checkMatrix.deleteflagmatrix[x+1][y] = true;
		}
	}

	if( m_fieldBlock[x-1][y] == id ){
		num++;
		checkMatrix.checkedmatrix[x-1][y] = true;
		num = BlockCount(x-1, y, id, num, checkMatrix);
		if( num >= 4 ){
			checkMatrix.deleteflagmatrix[x-1][y] = true;
		}
	}

	return num;
}

/*===== EOF ===================================================================*/