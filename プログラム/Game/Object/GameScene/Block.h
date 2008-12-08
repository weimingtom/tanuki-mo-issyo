/*******************************************************************************/
/**
 * @file Block.h.
 * 
 * @brief ブロッククラス定義.
 *
 * @date 2008/12/01.
 *
 * @version 1.00.
 *
 * @author Tsubasa Uragami.
 */
/*******************************************************************************/
#ifndef _BLOCK_H_
#define _BLOCK_H_

/*===== インクルード ==========================================================*/
#include	"IGameDevice.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"
#include	"Manager/Scene/Option/Option.h"
class		IGameDevice;


/**
 * @brief SPINBLOCK．
 */
enum SPINBLOCK
{
	SPINBLOCK_RIGHT = 0,
	SPINBLOCK_LEFT,
};

/**
 * @brief Block．
 */
class  Block : public ObjectBase
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
	 * @param[in] blockCID 軸のブロックのID.
	 * @param[in] blockMID サブのブロックのID.
	 */
	Block(IGameDevice& device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState, int blockCID, int blockMID);
	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~Block();

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
	/*=========================================================================*/
	/**
	 * @brief ブロック配列の初期化.
	 * 
	 */
	void InitializeMatrix();
	/*=========================================================================*/
	/**
	 * @brief ブロックの回転.
	 * 
	 * @param[in] direction 回転方向定数.
	 */
	void SpinBlock(int direction);
	Vector2 GetFieldMatrixPosition();

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
	/** ブロックの配列 */
	int m_blockMatrix[3][3];
	/** ブロックのID */
	int m_blockID[2];
	/** スピード */
	float m_speed;

	/** X位置 */
	float m_x;
	/** Y位置 */
	float m_y;
	/** ブロックのサイズ */
	float m_size;

	/**	目的のx座標 */
	float m_tx;

	/** フレーム */
	int frame[9][16];
};

#endif