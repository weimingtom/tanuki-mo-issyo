/*******************************************************************************/
/**
 * @file ReadyGo.h.
 * 
 * @brief レディゴークラスヘッダ定義.
 *
 * @date 2008/12/26.
 *
 * @version 1.00.
 *
 * @author Ryoma Kawasue.
 */
/*******************************************************************************/
#ifndef _READYGO_H_
#define _READYGO_H_

#include	"IGameDevice.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"

class ReadyGo : public ObjectBase
{
public:
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ.
	 *
	 */
	ReadyGo(IGameDevice& device, GameSceneState& gameSceneState);

	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~ReadyGo();

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

	float m_x;
	float m_y;

	float m_x2;
	float m_y2;

	float timer;

};

#endif