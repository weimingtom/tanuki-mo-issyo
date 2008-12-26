/*******************************************************************************/
/**
 * @file GameSceneState.h.
 * 
 * @brief ゲームシーン状態クラス定義.
 *
 * @date 2008/11/27.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _GAME_SCENE_STATE_H_
#define _GAME_SCENE_STATE_H_

/*===== インクルード ==========================================================*/
#include	<vector>
class		Player;
#include	"Manager/Object/ObjectManager.h"


/**
 * @brief GameSceneState．
 */
class GameSceneState
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ.
	 * 
	 */
	GameSceneState(ObjectManager& objectManager);
	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~GameSceneState();

	/*=========================================================================*/
	/**
	 * @brief プレーヤをリストに追加.
	 * 
	 * @param[in] player 追加するプレーヤ.
	 * @return 追加したプレーヤの番号.
	 */
	int AddPlayer(Player* player);
	/*=========================================================================*/
	/**
	 * @brief プレーヤをリストから削除.
	 * 
	 * @param[in] player 削除するプレーヤ.
	 */
	void DelPlayer(Player* player);
	/*=========================================================================*/
	/**
	 * @brief プレーヤリストのクリア.
	 * 
	 */
	void ClearPlayer();
	/*=========================================================================*/
	/**
	 * @brief プレーヤの取得.
	 * 
	 * @param[in] num 取得するプレーヤの番号.
	 * @return 取得したプレーヤ.
	 */
	Player* GetPlayer(int num);
	/*=========================================================================*/
	/**
	 * @brief 登録されたプレーヤの人数を取得.
	 * 
	 * @return プレーヤ人数.
	 */
	int GetPlayerNum();

	int GetGameState();
	void SetGameState(int state);

	Player* GetTargetPlayer(Player* player);

private:

	/** オブジェクトマネージャ */
	ObjectManager& m_objectManager;

	/** プレーヤリスト */
	std::vector<Player*> m_playerList;

	/** ゲームステート */
	int m_gameState;
};

#endif

/*===== EOF ===================================================================*/