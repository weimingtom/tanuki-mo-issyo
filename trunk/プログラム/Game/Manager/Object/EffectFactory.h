/*******************************************************************************/
/**
 * @file EffectFactory.h.
 * 
 * @brief エフェクト生成基底クラスの定義.
 *
 * @date 2008/12/27.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _EFFECT_FACTORY_H_
#define _EFFECT_FACTORY_H_

/*===== インクルード ==========================================================*/
class ObjectManager;

class	IGameDevice;
class	Option;
class	ObjectBase;
class	GameScene;
class	GameSceneState;
class	Player;

class	BlockDeleteEffect;

/**
 * @brief EffectFactory．
 */
class EffectFactory
{
public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ.
	 * 
	 * @param[in] device ゲームデバイス.
	 * @param[in] ObjectManager オブジェクトマネージャメディエータ.
	 * @param[in] option ゲームオプション.
	 */
	EffectFactory(IGameDevice& device, ObjectManager& objectManager, Option& option);

	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 */
	~EffectFactory();

	/*=========================================================================*/
	/**
	 * @brief オブジェクトの生成.
	 * 
	 * @param[in] objectID 生成するオブジェクトのID.
	 * @return 生成したオブジェクトのポインタ.
	 */
	BlockDeleteEffect* CreateBlockDeleteEffect(GameSceneState& gameSceneState,Player& player,float x, float y, int blockID);

private:

	/** ゲームデバイス */
	IGameDevice& m_device;
	/** オブジェクトマネージャメディエータ */
	ObjectManager& m_objectManager;
	/** ゲームオプション */
	Option& m_option;
};

#endif

/*===== EOF ===================================================================*/
