/*******************************************************************************/
/*
 * @file EnemyAI.cpp
 * 
 * @brief �G�l�~�[AI��`
 *
 * @date 2009/01/26
 *
 * @version 1.00
 *
 * @author Ryosuke Ogawa
 */
/*******************************************************************************/

/*===== �C���N���[�h ==========================================================*/
#include	"Object/GameScene/EnemyAI.h"

/*=============================================================================*/
/**
 * @brief �R���X�g���N�^.
 *
 */
EnemyAI::EnemyAI(IGameDevice &device/*, Field& field */, Player &player) : 
	m_device(device)/*,m_field(field)*/, m_player(player) 
{
}
/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
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
