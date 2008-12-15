/*******************************************************************************/
/**
 * @file PlayerAI.h.
 * 
 * @brief プレイヤーAI定義.
 *
 * @date 2008/12/15.
 *
 * @version 1.00.
 *
 * @author Tsubasa Uragami.
 */
/*******************************************************************************/
#ifndef _PLAYERAI_H_
#define _PLAYERAI_H_

/*===== インクルード ==========================================================*/
#include	"Object/GameScene/AIBase.h"
#include	"IGameDevice.h"

class		Player;

class	PlayerAI : public AIBase
{
public:
	PlayerAI(IGameDevice& device, Player& player);
	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~PlayerAI();
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
	Player&			m_player;
};

#endif