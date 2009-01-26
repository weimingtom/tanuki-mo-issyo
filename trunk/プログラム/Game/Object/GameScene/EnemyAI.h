/*******************************************************************************/
/**
 * @file PlayerAI.h
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
#ifndef _ENEMY_AI_H_
#define _ENEMY_AI_H_

/*===== �C���N���[�h ==========================================================*/
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
	 * @brief �f�X�g���N�^.
	 *
	 */
	~EnemyAI();
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
	//Field			m_field;
	Player&			m_player;
};

#endif