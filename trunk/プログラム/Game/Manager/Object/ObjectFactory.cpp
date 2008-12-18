/*******************************************************************************/
/*
 * @file ObjectFactory.cpp.
 * 
 * @brief �Q�[���V�[���̃I�u�W�F�N�g�����N���X��`.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/

/*===== �C���N���[�h ==========================================================*/

#include	"Manager/Object/ObjectFactory.h"

#include	"Object/GameScene/Player.h"
#include	"Object/GameScene/Block.h"
#include	"Manager/Object/ObjectManager.h"

/*=============================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 * @param[in] device �Q�[���f�o�C�X.
 * @param[in] ObjectManager �I�u�W�F�N�g�}�l�[�W�����f�B�G�[�^.
 * @param[in] option �Q�[���I�v�V����.
 * @param[in] State �Q�[���V�[���X�e�[�g.
 */
ObjectFactory::ObjectFactory(IGameDevice &device, ObjectManager &ObjectManager, Option &option) :
	m_device(device), m_objectManager(ObjectManager), m_option(option)
{

}

/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
ObjectFactory::~ObjectFactory()
{

}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̐���.
 * 
 * @param[in] objectID ��������I�u�W�F�N�g��ID.
 * @return ���������I�u�W�F�N�g�̃|�C���^.
 */

Player* ObjectFactory::CreatePlayer(GameSceneState& gameSceneState)
{
	Player* object;
	int skill[4] = {0,1,2,3};
	object = new Player(m_device, m_objectManager, m_option, gameSceneState, 100.0f,20.0f,
		1,skill,3,4,5,6,7,8,9,0);
	//m_objectManager.AddObject(object);
	return object;
}

Block* ObjectFactory::CreateBlock(GameSceneState& gameSceneState, Player& player, int blockCID, int blockMID)
{
	Block* object;
	object = new Block(m_device, m_objectManager, m_option, gameSceneState, player, blockCID, blockMID);
	//m_objectManager.AddObject(object);
	return object;
}

/*===== EOF ===================================================================*/