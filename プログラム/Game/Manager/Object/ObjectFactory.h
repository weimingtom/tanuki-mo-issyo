/*******************************************************************************/
/**
 * @file ObjectFactory.h.
 * 
 * @brief オブジェクト生成基底クラスの定義.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _OBJECT_FACTORY_H_
#define _OBJECT_FACTORY_H_

/*===== インクルード ==========================================================*/
class ObjectManager;

class	IGameDevice;
class	Option;
class	ObjectBase;
class	GameScene;
class	GameSceneState;
class Player;
class Block;


/**
 * @brief ObjectFactory．
 */
class ObjectFactory
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
	ObjectFactory(IGameDevice& device, ObjectManager& objectManager, Option& option);

	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 */
	~ObjectFactory();

	/*=========================================================================*/
	/**
	 * @brief オブジェクトの生成.
	 * 
	 * @param[in] objectID 生成するオブジェクトのID.
	 * @return 生成したオブジェクトのポインタ.
	 */

	Player* CreatePlayer(GameSceneState& gameSceneState, float x, float y, int hp, int skillpoint[],
		int playerTime, int characterID, int score, int playerID, int playerLV, int playerAttack,
		int playerDefence, int playerType,int maxHp);

	Block* CreateBlock(GameSceneState& gameSceneState,Player& player, int blockCID, int blockMID);

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