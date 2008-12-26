/*******************************************************************************/
/**
 * @file BlockDeleteEffect.h.
 * 
 * @brief フォールブロッククラスヘッダ定義.
 *
 * @date 2008/12/8.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/
#ifndef _BLOCK_DELETE_EFFECT_H_
#define _BLOCK_DELETE_EFFECT_H_

#include	"IGameDevice.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"
#include	"Manager/Scene/Option/Option.h"
#include	"Object/ObjectBase.h"
class		Player;

/**
 * @brief ObjectBase．
 */
class BlockDeleteEffect : public ObjectBase
{
public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 *
	 */
	BlockDeleteEffect(IGameDevice& device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState, Player& player, float x, float y,int blockID);

	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 * 
	 */
	~BlockDeleteEffect();

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

	IntPoint GetFieldMatrixPosition(float x, float y);

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

	/**	ブロックID */
	int m_blockID;
	/** 縮小スピード */
	float m_speed;
	/** 描画サイズ */
	float m_size;
	/** 削除タイマ */
	float m_timer;
	/** y座標　*/
	float m_y;
	/** x座標　*/
	float m_x;

};

#endif

/*===== EOF ===================================================================*/
