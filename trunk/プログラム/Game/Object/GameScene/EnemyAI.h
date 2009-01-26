/*******************************************************************************/
/**
 * @file PlayerAI.h
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
#ifndef _ENEMY_AI_H_
#define _ENEMY_AI_H_

/*===== インクルード ==========================================================*/
#include	"Object/GameScene/AIBase.h"
#include	"Object/GameScene/Field.h"
#include	"IGameDevice.h"

class		Player;

class	EnemyAI : public AIBase
{
public:
	EnemyAI(IGameDevice& device/*, Field& field*/, Player& player);
	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~EnemyAI();
	/*=========================================================================*/
	/**
	 * @brief 指定されたキーが押されたか判定.
	 * 
	 */
	bool GetKeyTrigger(unsigned int key);
	/*=========================================================================*/
	/**
	 * @brief 指定されたキーが押されているか判定.
	 * 
	 */
	bool GetKeyDown(unsigned int key);

private:
	IGameDevice&	m_device;
	//Field			m_field;
	Player&			m_player;
};

#endif