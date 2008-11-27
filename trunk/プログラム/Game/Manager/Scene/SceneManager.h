/*******************************************************************************/
/**
 * @file SceneManager.h.
 * 
 * @brief シーンマネージャクラス定義.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

/*===== インクルード ==========================================================*/
#include	<vector>
#include	"IGameDevice.h"
#include	"Manager/Scene/SceneManagerMediator.h"
#include	"Manager/Scene/SceneFactory.h"
#include	"Scene/SceneBase.h"
#include	"Manager/Scene/Option/Option.h"


/**
 * @brief SceneManager．
 */
class SceneManager : public SceneManagerMediator
{
public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ.
	 * 
	 * @param[in] device ゲームデバイス.
	 * @param[in] sceneID 初期シーン.
	 */
	SceneManager(IGameDevice& device, int sceneID);
	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~SceneManager();

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
	 * @brief シーンの変更.
	 * 
	 * @param[in] sceneID 変更するシーン.
	 */
	void ChangeScene(int sceneID);
	/*=========================================================================*/
	/**
	 * @brief シーンの呼び出し.
	 * 
	 * @param[in] sceneID 呼び出すシーン.
	 */
	void CallScene(int sceneID);
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
	IGameDevice& m_device;
	/** シーンファクトリ */
	SceneFactory* m_sceneFactory;
	/** 現在のシーン */
	SceneBase* m_currentScene;
	/** ストックしたシーン */
	std::vector<SceneBase*> m_stockScene;
	/** 終了フラグ */
	bool m_isTerminated;
	/** ゲームオプション */
	Option m_option;
};

#endif