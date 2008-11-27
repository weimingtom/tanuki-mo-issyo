/*******************************************************************************/
/**
 * @file GameSceneObjectFactory.h.
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
#ifndef _GAME_SCENE_OBJECT_FACTORY_H_
#define _GAME_SCENE_OBJECT_FACTORY_H_

/*===== インクルード ==========================================================*/
#include	"IGameDevice.h"
#include	"Manager/Object/ObjectFactoryBase.h"
#include	"Manager/Object/ObjectManagerMediator.h"
#include	"Manager/Scene/Option/Option.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"


/**
 * @brief クラス名．
 */
class GameSceneObjectFactory : public ObjectFactoryBase
{
public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ.
	 * 
	 * @param[in] device ゲームデバイス.
	 * @param[in] objectManagerMediator オブジェクトマネージャメディエータ.
	 * @param[in] option ゲームオプション.
	 * @param[in] gameSceneState ゲームシーンステート.
	 */
	GameSceneObjectFactory(IGameDevice& device, ObjectManagerMediator& objectManagerMediator, Option& option, GameSceneState& gameSceneState);
	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~GameSceneObjectFactory();

	/*=========================================================================*/
	/**
	 * @brief オブジェクトの生成.
	 * 
	 * @param[in] objectID 生成するオブジェクトのID.
	 * @return 生成したオブジェクトのポインタ.
	 */
	ObjectBase* CreateObject(int objectID);

private:
	
	/** ゲームデバイス */
	IGameDevice& m_device;
	/** オブジェクトマネージャメディエータ */
	ObjectManagerMediator& m_objectManagerMediator;
	/** ゲームシーンステート */
	GameSceneState& m_gameSceneState;
	/** ゲームオプション */
	Option& m_option;
};

#endif

/*===== EOF ===================================================================*/