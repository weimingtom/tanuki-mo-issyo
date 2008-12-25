/*******************************************************************************/
/**
 * @file CharacterScreen.h.
 * 
 * @brief キャラクタースクリーンヘッダ.
 *
 * @date 2008/12/11.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/
#ifndef _CHARACTER_SCREEN_H_
#define _CHARACTER_SCREEN_H_

#include	"IGameDevice.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"
#include	"Manager/Scene/Option/Option.h"
#include	"Object/GameScene/Avatar.h"
class		Player;


/**
 * @brief CharacterScreen．
 */
class CharacterScreen : public ObjectBase
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
	CharacterScreen(IGameDevice& device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState, Player& player);

	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~CharacterScreen();

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

	Avatar& GetAvatar();

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
	GameSceneState& m_gameSceneState;
	/** プレーヤ */
	Player&		m_player;

	Avatar		m_avatar;

};

#endif

/*===== EOF ===================================================================*/
