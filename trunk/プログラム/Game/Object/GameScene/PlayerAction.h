/*******************************************************************************/
/**
 * @file PlayerAction.h.
 * 
 * @brief パズルスクリーンクラスヘッダファイル.
 *
 * @date 2008/12/4.
 *
 * @version 1.00.
 *
 * @author ryoma kawasue.
 */
/*******************************************************************************/

#ifndef _PLAYERACTION_H_
#define _PLAYERACTION_H_

#include	"IGameDevice.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Scene/GameSceneState.h"
#include	"Manager/Scene/Option/Option.h"
class		Player;

class PlayerAction
{
public:
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ.
	 *
	 */
	PlayerAction(IGameDevice& device, ObjectManager& objectManager, 
				 Option& option, GameSceneState& gameSceneState , Player& player);
	/*=========================================================================*/

	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~PlayerAction();				//ダイワハウス
	/*=========================================================================*/

	/*=========================================================================*/
	/**
	 * @brief .初期化処理
	 *
	 */
	void Initialize();
	/*=========================================================================*/

	void Attack(Player& player);
	void Damage(int damage);

private:

	/** ゲームデバイス */
	IGameDevice& m_device;
	/** オブジェクトマネージャメディエータ */
	ObjectManager& m_objectManager;
	/** ゲームオプション */
	Option& m_option;
	/** ゲームシーンステート */
	GameSceneState& m_gameSceneState;
	/** プレーヤ */
	Player& m_player;

};

#endif

/*===== EOF ===================================================================*/