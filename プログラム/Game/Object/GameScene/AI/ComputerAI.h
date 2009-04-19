/*******************************************************************************/
/**
 * @file ComputerAI.h.
 * 
 * @brief �R���s���[�^AI��`.
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

/*===== �C���N���[�h ==========================================================*/
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
	 * @brief �f�X�g���N�^.
	 *
	 */
	~ComputerAI();
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
	/*=========================================================================*/
	/**
	 * @brief �w�肳�ꂽ�L�[��������Ă��邩����.
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