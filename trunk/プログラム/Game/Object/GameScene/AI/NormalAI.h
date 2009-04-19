/*******************************************************************************/
/**
 * @file NormalAI.h.
 * 
 * @brief com.ノーマルAI定義.
 *
 * @date 2009/04/17.
 *
 * @version 1.00.
 *
 * @author Tsubasa Uragami.
 */
/*******************************************************************************/
#ifndef _NORMALAI_H_
#define _NORMALAI_H_

/*===== インクルード ==========================================================*/
#include	"Object/GameScene/AI/KeyInfo.h"
#include	"Object/GameScene/AI/AIRoutineBase.h"
#include	"IGameDevice.h"


class Player;

class	NormalAI : public AIRoutineBase
{
public:
	NormalAI(IGameDevice& device, Player& player, KeyInfo& keyinfo);
	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~NormalAI();
	/*=========================================================================*/
	/**
	 * @brief 判定.
	 * 
	 */
	void Update(float frameTime);

private:
	IGameDevice&	m_device;
	Player&			m_player;
	KeyInfo&		m_keyinfo;
};

#endif