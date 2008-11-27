/*******************************************************************************/
/*
 * @file GameSceneObjectFactory.cpp.
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
#include	"Scene/Factory/GameSceneObjectFactory.h"
#include	"Object/GameScene/Player.h"
#include	"Define/GameSceneObjectID.h"

/*=============================================================================*/
/**
 * @brief コンストラクタ.
 * 
 * @param[in] device ゲームデバイス.
 * @param[in] objectManagerMediator オブジェクトマネージャメディエータ.
 * @param[in] option ゲームオプション.
 * @param[in] gameSceneState ゲームシーンステート.
 */
GameSceneObjectFactory::GameSceneObjectFactory(IGameDevice &device, ObjectManagerMediator &objectManagerMediator, Option &option, GameSceneState &gameSceneState) :
	m_device(device), m_objectManagerMediator(objectManagerMediator), m_option(option), m_gameSceneState(gameSceneState)
{

}

/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
GameSceneObjectFactory::~GameSceneObjectFactory()
{

}

/*=============================================================================*/
/**
 * @brief オブジェクトの生成.
 * 
 * @param[in] objectID 生成するオブジェクトのID.
 * @return 生成したオブジェクトのポインタ.
 */
ObjectBase* GameSceneObjectFactory::CreateObject(int objectID)
{
	ObjectBase* object = 0;
	switch(objectID)
	{
	case GAME_SCENE_OBJECT_ID_PLAYER:
		object = new Player(m_device, m_objectManagerMediator, m_option, m_gameSceneState);
	}
	return object;
}

/*===== EOF ===================================================================*/