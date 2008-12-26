/*******************************************************************************/
/**
 * @file Result.h.
 * 
 * @brief リザルトクラスヘッダ定義.
 *
 * @date 2008/12/26.
 *
 * @version 1.00.
 *
 * @author Jun Futagawa.
 */
/*******************************************************************************/
#ifndef _RESULT_H_
#define _RESULT_H_

#include	"IGameDevice.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"

class Result : public ObjectBase
{
public:
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ.
	 *
	 */
	Result(IGameDevice& device, GameSceneState& gameSceneState);

	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~Result();

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

	private:
	/** 終了フラグ */
	bool m_isTerminated;
	/** ゲームデバイス */
	IGameDevice& m_device;
	/** ゲームシーンステート */
	GameSceneState& m_gameSceneState;

};

#endif

/*===== EOF ===================================================================*/

