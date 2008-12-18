/*******************************************************************************/
/*
 * @file ObjectFactory.cpp.
 * 
 * @brief ゲームシーンのオブジェクト生成クラス定義.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/

/*===== インクルード ==========================================================*/

#include	"Manager/Object/ObjectFactory.h"

#include	"Object/GameScene/Player.h"
#include	"Object/GameScene/Block.h"
#include	"Manager/Object/ObjectManager.h"

/*=============================================================================*/
/**
 * @brief コンストラクタ.
 * 
 * @param[in] device ゲームデバイス.
 * @param[in] ObjectManager オブジェクトマネージャメディエータ.
 * @param[in] option ゲームオプション.
 * @param[in] State ゲームシーンステート.
 */
ObjectFactory::ObjectFactory(IGameDevice &device, ObjectManager &ObjectManager, Option &option) :
	m_device(device), m_objectManager(ObjectManager), m_option(option)
{

}

/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
ObjectFactory::~ObjectFactory()
{

}

/*=============================================================================*/
/**
 * @brief オブジェクトの生成.
 * 
 * @param[in] objectID 生成するオブジェクトのID.
 * @return 生成したオブジェクトのポインタ.
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