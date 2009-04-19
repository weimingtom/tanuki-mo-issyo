/*******************************************************************************/
/*
 * @file NormalAI.cpp.
 * 
 * @brief com.ノーマルクラス定義.
 *
 * @date 2009/04/17.
 *
 * @version 1.00.
 *
 * @author Thubasa Uragami.
 */
/*******************************************************************************/

/*===== インクルード ==========================================================*/
#include	"Object/GameScene/AI/NormalAI.h"
#include	"Object/GameScene/Player.h"
#include	"Define/GameDefine.h"
#include	"IGameDevice.h"
/*=============================================================================*/
/**
 * @brief コンストラクタ.
 *
 */
NormalAI::NormalAI(IGameDevice &device, Player &player, KeyInfo &keyinfo):m_device(device), m_player(player), m_keyinfo(keyinfo)
{
}
/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
NormalAI::~NormalAI()
{

}

/*=============================================================================*/
/**
 * @brief	.
 * 
 */
void NormalAI::Update(float frameTimer)
{
	if(m_player.GetAI().GetIsThinking()==true)
	{
	FieldMatrix* field;
	bool	findBlock = false;
	m_player.GetPuzzleScreen().GetBlockManager().GetField().GetFieldBlockMatrix(field);
		
	for(int i=1; i<FIELD_WIDTH; i++)
	{
		if(field->matrix[i][FIELD_HEIGHT-2]!=0)
		{
			findBlock = true;
			break;
		}
	}
	if(findBlock==false)
	{
		m_player.GetAI().SetTargetAngle(Random.randi(0,3));
		int i=1,j=FIELD_WIDTH-2;
		if(m_player.GetAI().GetTargetAngle() == 1)
		{
			j--;
		}
		if(m_player.GetAI().GetTargetAngle() == 3)
		{
			i++;
		}
		m_player.GetAI().SetTargetPosition(Random.randi(i,j));
		m_player.GetAI().SetIsThinking(false);
	}
	}
	else
	{
		
	}
}
/*===== EOF ===================================================================*/

