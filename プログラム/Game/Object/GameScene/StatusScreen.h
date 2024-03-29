/*******************************************************************************/
/**
 * @file StattusScreen.h.
 * 
 * @brief ステータススクリーンヘッダファイル.
 *
 * @date 2008/12/15.
 *
 * @version 1.00.
 *
 * @author Ryoma Kawasue.
 */
/*******************************************************************************/

#ifndef _STATUS_SCREEN_H_
#define _STATUS_SCREEN_H_

/*===== インクルード ==========================================================*/
#include	"IGameDevice.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"
#include	"Manager/Scene/Option/Option.h"
class		Player;
#include	"Object/GameScene/SkillPoint.h"
#include	"Object/GameScene/HitPoint.h"
#include	"Object/GameScene/Score.h"
#include    "Object/GameScene/PlayerTime.h"
#include	"Object/GameScene/NextBlock.h"
#include	"Object/GameScene/CharacterType.h"
#include	"Object/GameScene/Skill.h"
#include    "Object/GameScene/Attack.h"
#include    "Object/GameScene/Defence.h"


class StatusScreen : public ObjectBase
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
	StatusScreen(IGameDevice &device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState, Player& player);

	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~StatusScreen();

	/*=========================================================================*/
	/**
	 * @brief 初期化処理.
	 * 
	 */
	void Initialize();

	/*=========================================================================*/
	/**
	 * @brief 終了処理.
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
	void UpdateObject( float frameTimer );

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
	Player& m_player;

	/** スキルポイント */
	SkillPoint	m_skillPoint;
	/** ヒットポイント */
	HitPoint	m_hitPoint;
	/** スコア */
	Score		m_score;
	/** プレイヤータイム */
	PlayerTime	m_playerTime;
	/** ネクストブロック */
	NextBlock	m_nextBlock;
	/** キャラクタタイプ */
	CharacterType	m_characterType;
	/** 攻撃力 */
	Attack		m_attack;
	/** 防御壁 */
	Defence		m_defence;

};

#endif

/*===== EOF ===================================================================*/
