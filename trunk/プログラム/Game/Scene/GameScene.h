/*******************************************************************************/
/**
 * @file GameScene.h.
 * 
 * @brief ゲームシーンクラス定義.
 *
 * @date 2008/11/27.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

/*===== インクルード ==========================================================*/
#include	"Scene/SceneBase.h"
#include	"IGameDevice.h"
#include	"Manager/Scene/SceneManagerMediator.h"
#include	"Manager/Scene/Option/Option.h"
#include	"Scene/GameSceneState.h"


/**
 * @brief GameScene．
 */
class GameScene : public SceneBase
{
public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ.
	 * 
	 * @param[in] device ゲームデバイス.
	 * @param[in] sceneManagerMediator シーンマネージャメディエータ.
	 * @param[in] option ゲームオプション.
	 */
	GameScene(IGameDevice& device, SceneManagerMediator& sceneManagerMediator, Option& option);
	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~GameScene();

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
	 * @brief シーンの描画処理.
	 * 
	 */
	void RenderScene();
	/*=========================================================================*/
	/**
	 * @brief シーンの更新処理.
	 * 
	 * @param[in] frameTimer 更新タイマ.
	 */
	void UpdateScene(float frameTimer);

private:

	/** ゲームデバイス */
	IGameDevice&					m_device;
	/** シーンマネージャメディエータ */
	SceneManagerMediator&			m_sceneManagerMediator;
	/** ゲームオプション */
	Option&							m_option;
	/** 終了フラグ */
	bool							m_isTerminated;
	/** シーンステート */
	GameSceneState					m_state;

};

#endif

/*===== EOF ===================================================================*/