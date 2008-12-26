/*******************************************************************************/
/**
 * @file BackGround.h.
 * 
 * @brief 背景.
 *
 * @date 2008/12/26.
 *
 * @version 1.00.
 *
 * 
 * @author Ryoma Kawasue.
 */
/*******************************************************************************/

#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

/*===== インクルード ==========================================================*/
#include	"IGameDevice.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"

class BackGround : public ObjectBase
{
public:
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ.
	 * 
	 * @param[in] 引数名 引数説明.
	 */

	BackGround(IGameDevice& device, GameSceneState& gameSceneState);

	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~BackGround();

	/*=========================================================================*/
	/**
	 * @brief 関数説明.
	 * 
	 * @param[in] 引数名 引数説明.
	 * @return 戻り値説明.
	 */
	void Initialize();

	void Terminate();

	bool IsTerminated();

	void RenderObject();

	void UpdateObject(float frameTimer);

private:

	/** 変数の説明 */

	/** 終了フラグ */
	bool m_isTerminated;
	/** ゲームデバイス */
	IGameDevice& m_device;
	/** ゲームシーンステート */
	GameSceneState& m_gameSceneState;


};

#endif


/*===== EOF ===================================================================*/