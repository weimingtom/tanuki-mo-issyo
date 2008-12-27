/*******************************************************************************/
/**
 * @file CutinEffect.h.
 * 
 * @brief カットインヘッダ定義.
 *
 * @date 2008/12/27.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/
#ifndef _CutinEffect_H_
#define _CutinEffect_H_

#include	"IGameDevice.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"

class CutinEffect : public ObjectBase
{
public:
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ.
	 *
	 */
	CutinEffect(IGameDevice& device, GameSceneState& gameSceneState, int id);

	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~CutinEffect();

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

	int m_id;

	float m_x;
	float m_y;
	float m_speed;
	float m_vspeed;
	int m_time;
	Vector2 m_size;


};

#endif