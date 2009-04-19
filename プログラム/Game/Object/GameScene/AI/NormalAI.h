/*******************************************************************************/
/**
 * @file NormalAI.h.
 * 
 * @brief com.�m�[�}��AI��`.
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

/*===== �C���N���[�h ==========================================================*/
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
	 * @brief �f�X�g���N�^.
	 *
	 */
	~NormalAI();
	/*=========================================================================*/
	/**
	 * @brief ����.
	 * 
	 */
	void Update(float frameTime);

private:
	IGameDevice&	m_device;
	Player&			m_player;
	KeyInfo&		m_keyinfo;
};

#endif