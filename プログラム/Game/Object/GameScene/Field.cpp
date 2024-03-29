/*******************************************************************************/
/*
 * @file Field.cpp.
 * 
 * @brief フィールドソース.
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
#include <iostream>
#include "Object/GameScene/Effect/BlockDeleteEffect.h"

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

	SpriteDesc sd_p;

	sd_p.rect = Rect(m_x + BLOCK_SIZE, m_y, m_x + (BLOCK_SIZE * (FIELD_WIDTH - 1)), m_y + (BLOCK_SIZE * (FIELD_HEIGHT - 1)));
	sd_p.textureID = TEXTUREID_FIELD_BACKGROUND;
	sd_p.color = Color4(1.0f,1.0f,1.0f,0.8f);
	m_device.GetGraphicDevice().Render( sd_p );

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
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void Field::UpdateObject(float frameTimer)
{
	if(m_gameSceneState.GetGameState() != GAME_STATE_MAIN)
	{
		return;
	}
	//if((m_player.GetPuzzleScreen().GetBlockManager().GetFallBlockNum() == 0) && (m_player.GetPlayerParameter().GetIsCreateBlock() == true))
	if(m_player.GetPlayerParameter().GetEffectCount() == 0 )
	{
		CheckBlock();
		if(!m_player.GetPlayerParameter().GetIsCreateBlock())
		{
			return;
		}
		ChangeToFallBlock();

		if((m_fieldBlock[(int)(FIELD_WIDTH/2)][0] != 0 ) || (m_fieldBlock[(int)(FIELD_WIDTH/2)+1][0] != 0))
		{
			m_player.GetPlayerAction().PlayerLose();
			return;
		}

		if((m_player.GetPuzzleScreen().GetBlockManager().GetFallBlockNum() == 0) && 
			(m_player.GetCharacterScreen().GetAvatar().GetAnimationState() == AVATAR_ANIMATION_STATE_STAND) &&
			(m_gameSceneState.GetTargetPlayer(&m_player)->GetCharacterScreen().GetAvatar().GetAnimationState() == AVATAR_ANIMATION_STATE_STAND))
		{
			if(m_player.GetPlayerParameter().GetPlayerTime() <= 0)
			{
				m_player.GetPlayerAction().Attack(m_gameSceneState.GetTargetPlayer(&m_player));
				return;
			}
			m_player.GetPuzzleScreen().GetBlockManager().CreateBlock();
		}
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
					if(num >= 3)
					{
						m_player.GetPlayerParameter().SetIsCreateBlock(false);
						int* skill;
						skill = m_player.GetPlayerParameter().GetSkillPoint();
						switch(m_fieldBlock[i][j])
						{
						case TEXTUREID_BLOCK1:
							m_player.GetPlayerAction().AddAttack(10);
							break;
						case TEXTUREID_BLOCK2:
							m_player.GetPlayerAction().AddDefence(10);
							break;
						case TEXTUREID_BLOCK3:
							m_player.GetPlayerAction().AddHP(10);
							break;
						case TEXTUREID_SBLOCK1:
							m_player.GetPlayerAction().AddSkillPoint(0);
							break;
						case TEXTUREID_SBLOCK2:
							m_player.GetPlayerAction().AddSkillPoint(1);
							break;
						case TEXTUREID_SBLOCK3:
							m_player.GetPlayerAction().AddSkillPoint(2);
							break;
						case TEXTUREID_SBLOCK4:
							m_player.GetPlayerAction().AddSkillPoint(3);
							break;
						}
						BlockDelete(i, j);
						m_player.GetPlayerAction().AddScore(10 * num);
					}
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

/** ブロック消滅 */
void Field::BlockDelete(int x ,int y)
{
	m_player.GetPlayerParameter().SetIsCreateBlock(false);
	
	int id = m_fieldBlock[x][y];
	m_fieldBlock[x][y] = 0;
	m_objectManager.AddEffect(m_objectManager.GetEffectFactory().CreateBlockDeleteEffect(m_gameSceneState, m_player, m_x + (BLOCK_SIZE*x), m_y + (BLOCK_SIZE*y), id));

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
/** ブロック消滅後の落下処理 */
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