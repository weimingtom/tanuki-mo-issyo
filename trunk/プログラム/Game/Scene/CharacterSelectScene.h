/*******************************************************************************/
/**
 * @file CharacterSelectScene.h.
 * 
 * @brief キャラクターセレクトシーンクラスヘッダ定義.
 *
 * @date 2008/12/27.
 *
 * @version 1.00.
 *
 * @author Ryoma Kawasue.
 */
/*******************************************************************************/
#ifndef _CHARACTER_SELECT_SCENE_H_
#define _CHARACTER_SELECT_SCENE_H_

/*===== インクルード ==========================================================*/
#include	"Scene/SceneBase.h"
#include	"IGameDevice.h"
#include	"Manager/Scene/SceneManagerMediator.h"
#include	"Manager/Scene/Option/Option.h"
#include	"Scene/CharacterSelectSceneState.h"
#include	"Manager/Object/ObjectManager.h"

/**
 * @brief CharacterSelectScene．
 */
class CharacterSelectScene : public SceneBase
{
public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ.
	 */
	CharacterSelectScene(IGameDevice& device, SceneManagerMediator& sceneManagerMediator, Option& option);
	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~CharacterSelectScene();

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
	/** 終了フラグ */
	bool							m_isTerminated;
	/** シーンマネージャメディエータ */
	SceneManagerMediator&			m_sceneManagerMediator;
	/** ゲームオプション */
	Option&							m_option;
	/** オブジェクトマネージャ */
	ObjectManager*					m_objectManager;
	/**キャラクターセレクトシーンステート　*/
	CharacterSelectSceneState*		m_characterSelectSceneState;

};

#endif

/*===== EOF ===================================================================*/