/*******************************************************************************/
/**
 * @file PuzzleScreen.h.
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

#ifndef _PUZZLESCREEN_H_
#define _PUZZLESCREEN_H_

#include	"IGameDevice.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"
#include	"Manager/Scene/Option/Option.h"
#include	"Object/GameScene/BlockManager.h"
#include "Object/ObjectBase.h"
class		Player;

class PuzzleScreen : public ObjectBase
{
public:
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ.
	 *
	 */
	PuzzleScreen(IGameDevice& device, ObjectManager& objectManager, 
				 Option& option, GameSceneState& gameSceneState , Player& player);
	/*=========================================================================*/

	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~PuzzleScreen();				//ダイワハウス
	/*=========================================================================*/

	/*=========================================================================*/
	/**
	 * @brief .初期化処理
	 *
	 */
	void Initialize();
	/*=========================================================================*/


	/*=========================================================================*/
	/**
	 * @brief 終了しているかどうか.
	 *
	 * @return 終了フラグ
	 */
	bool IsTerminated();
	/*=========================================================================*/


	/*=========================================================================*/
	/**
	 * @brief オブジェクトの描画処理.
	 *
	 */
	void RenderObject();
	/*=========================================================================*/


	/*=========================================================================*/
	/**
	 * @brief 終了処理.
	 *
	 */
	void Terminate();
	/*=========================================================================*/

	/*=========================================================================*/
	/**
	 * @brief オブジェクトの更新処理.
	 *
	 * @param[in] frameTimer 更新大麻
	 */
	void UpdateObject(float frameTimer);
	/*=========================================================================*/

	BlockManager&	GetBlockManager(); 

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

	/** ブロックマネージャ */
	BlockManager m_blockManager;



};

#endif

/*===== EOF ===================================================================*/