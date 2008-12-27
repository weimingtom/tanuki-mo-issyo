/*******************************************************************************/
/*
 * @file EffectFactory.cpp.
 * 
 * @brief ゲームシーンのエフェクト生成クラス定義.
 *
 * @date 2008/12/26.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/

/*===== インクルード ==========================================================*/

#include	"Manager/Object/EffectFactory.h"

#include	"Object/GameScene/Player.h"
#include	"Manager/Object/ObjectManager.h"

#include	"Object/GameScene/Effect/BlockDeleteEffect.h"
#include	"Object/GameScene/Effect/CutinEffect.h"


/*=============================================================================*/
/**
 * @brief コンストラクタ.
 * 
 * @param[in] device ゲームデバイス.
 * @param[in] ObjectManager オブジェクトマネージャメディエータ.
 * @param[in] option ゲームオプション.
 * @param[in] State ゲームシーンステート.
 */
EffectFactory::EffectFactory(IGameDevice &device, ObjectManager &ObjectManager, Option &option) :
	m_device(device), m_objectManager(ObjectManager), m_option(option)
{

}

/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
EffectFactory::~EffectFactory()
{

}

/*=============================================================================*/
/**
 * @brief オブジェクトの生成.
 * 
 * @param[in] objectID 生成するオブジェクトのID.
 * @return 生成したオブジェクトのポインタ.
 */
BlockDeleteEffect* EffectFactory::CreateBlockDeleteEffect(GameSceneState& gameSceneState,Player& player,float x, float y, int blockID)
{
	BlockDeleteEffect* object;
	object = new BlockDeleteEffect(m_device, m_objectManager, m_option, gameSceneState, player, x, y, blockID);
	return object;
}

/*=============================================================================*/
/**
 * @brief オブジェクトの生成.
 * 
 * @param[in] objectID 生成するオブジェクトのID.
 * @return 生成したオブジェクトのポインタ.
 */
CutinEffect* EffectFactory::CreateCutinEffect(GameSceneState &gameSceneState, int id)
{
	CutinEffect*	object;
	object = new CutinEffect( m_device, gameSceneState , id);
	return object;
}


/*===== EOF ===================================================================*/
