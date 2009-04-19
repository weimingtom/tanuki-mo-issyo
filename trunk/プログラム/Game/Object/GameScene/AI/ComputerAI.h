/*******************************************************************************/
/**
 * @file ComputerAI.h.
 * 
 * @brief コンピュータAI定義.
 *
 * @date 2009/04/13.
 *
 * @version 1.00.
 *
 * @author Tsubasa Uragami.
 */
/*******************************************************************************/
#ifndef _COMPUTERAI_H_
#define _COMPUTERAI_H_

/*===== インクルード ==========================================================*/
#include	"Object/GameScene/AI/AIBase.h"
#include	"IGameDevice.h"
#include	"Object/GameScene/AI/KeyInfo.h"
#include	"Object/GameScene/AI/AIRoutineBase.h"

class		Player;

class	ComputerAI : public AIBase
{
public:
	ComputerAI(IGameDevice& device, Player& player);
	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~ComputerAI();
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
	/*=========================================================================*/
	/**
	 * @brief 指定されたキーが押されているか判定.
	 * 
	 */
	void Update(float frameTime);
private:
	IGameDevice&	m_device;
	Player&			m_player;
	KeyInfo			m_keyInfo;
	AIRoutineBase*	m_AIRoutine;
};

#endif