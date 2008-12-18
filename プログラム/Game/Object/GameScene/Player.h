/*******************************************************************************/
/**
 * @file Player.h.
 * 
 * @brief プレーヤークラス定義.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _PLAYER_H_
#define _PLAYER_H_

/*===== インクルード ==========================================================*/
#include	"IGameDevice.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"
#include	"Manager/Scene/Option/Option.h"
class		IGameDevice;

#include    "Object/GameScene/PuzzleScreen.h"
#include    "Object/GameScene/CharacterScreen.h"
#include	"Object/GameScene/StatusScreen.h"
#include	"Object/GameScene/Player.h"
#include	"Object/GameScene/AIBase.h"
#include	"Object/GameScene/PlayerAI.h"
#include	"Object/GameScene/PlayerParameter.h"

/**
 * @brief Player．
 */
class Player : public ObjectBase
{
public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ.
	 * 
	 * @param[in] device ゲームデバイス.
	 * @param[in] objectManager オブジェクトマネージャ.
	 * @param[in] option ゲームオプション.
	 * @param[in] gameSceneState ゲームシーンステート.
	 */
	Player(IGameDevice& device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState, float x, float y,
			int hp, int skillPoint[], int playerTime,int characterID, int score, int playerID,int playerLV, int playerAttack,
			int playerDefence,int playerType);
	

	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~Player();

	/*=========================================================================*/
	/**
	 * @brief 初期化処理.
	 * 
	 */
	void Initialize();
	/*=========================================================================*/
	/**
	 * @brief 終了処理.
	 * 
	 */
	void Terminate();
	/*=========================================================================*/
	/**
	 * @brief 終了しているかどうか.
	 * 
	 * @return 終了フラグ.
	 */
	bool IsTerminated();

	/*=========================================================================*/
	/**
	 * @brief オブジェクトの描画処理.
	 * 
	 */
	void RenderObject();
	/*=========================================================================*/
	/**
	 * @brief オブジェクトの更新処理.
	 * 
	 * @param[in] frameTimer 更新タイマ.
	 */
	void UpdateObject(float frameTimer);

	Vector2 GetPosition();
	PuzzleScreen& GetPuzzleScreen();

	AIBase& GetAI();
	void SetAI(AIBase* ai);

private:

	/** 終了フラグ */
	bool m_isTerminated;
	/** ゲームデバイス */
	IGameDevice& m_device;
	/** オブジェクトマネージャメディエータ */
	ObjectManager& m_objectManager;
	/** ゲームオプション */
	Option& m_option;
	/** ゲームシーンステート */
	GameSceneState m_gameSceneState;
	/** プレイヤーパラメータ */
	PlayerParameter m_playerParameter;

	PuzzleScreen	m_puzzleScreen;
	CharacterScreen	m_characterScreen;
	AIBase*			m_AI;
	StatusScreen	m_statusScreen;

	float m_x;
	float m_y;

};

#endif

/*===== EOF ===================================================================*/
