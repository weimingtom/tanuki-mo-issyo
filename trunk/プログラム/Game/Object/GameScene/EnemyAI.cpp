/*******************************************************************************/
/*
 * @file EnemyAI.cpp
 * 
 * @brief エネミーAI定義
 *
 * @date 2009/01/26
 *
 * @version 1.00
 *
 * @author Ryosuke Ogawa
 */
/*******************************************************************************/

/*===== インクルード ==========================================================*/
#include	"Object/GameScene/EnemyAI.h"

/*=============================================================================*/
/**
 * @brief コンストラクタ.
 *
 */
EnemyAI::EnemyAI(IGameDevice &device/*, Field& field */, Player &player) : 
	m_device(device)/*,m_field(field)*/, m_player(player) 
{
}
/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
EnemyAI::~EnemyAI()
{

}

/*=============================================================================*/
/**
 * @brief  .
 * 
 */
bool EnemyAI::GetKeyTrigger(unsigned int key)
{
	for( int i = 0; i < FIELD_WIDTH; i++ )
	{
		for( int j = 0; j < FIELD_HEIGHT; j++ )
		{
			//if( m_player.GetPuzzleScreen(). )
			//{

			//}
		}
	}
	
	return	m_device.GetInputDevice().GetKeyTrigger(key);
}

/*=============================================================================*/
/**
 * @brief  .
 * 
 */
bool EnemyAI::GetKeyDown(unsigned int key)
{
	return m_device.GetInputDevice().GetKeyDown(key);
}

/*===== EOF ===================================================================*/
