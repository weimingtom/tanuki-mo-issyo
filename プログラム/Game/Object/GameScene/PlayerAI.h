/*******************************************************************************/
/**
 * @file PlayerAI.h.
 * 
 * @brief �v���C���[AI��`.
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

/*===== �C���N���[�h ==========================================================*/
#include	"Object/GameScene/AIBase.h"
#include	"IGameDevice.h"

class		Player;

class	PlayerAI : public AIBase
{
public:
	PlayerAI(IGameDevice& device, Player& player);
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 *
	 */
	~PlayerAI();
	/*=========================================================================*/
	/**
	 * @brief �w�肳�ꂽ�L�[�������ꂽ������.
	 * 
	 */
	bool GetKeyTrigger(unsigned int key);
	/*=========================================================================*/
	/**
	 * @brief �w�肳�ꂽ�L�[��������Ă��邩����.
	 * 
	 */
	bool GetKeyDown(unsigned int key);

private:
	IGameDevice&	m_device;
	Player&			m_player;
};

#endif