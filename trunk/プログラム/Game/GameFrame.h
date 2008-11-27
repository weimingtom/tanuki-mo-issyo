/*******************************************************************************/
/*
 * @file GameFrame.h.<br>
 * 
 * @brief ゲームフレームクラスヘッダファイル.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _GAMEFRAME_H_
#define _GAMEFRAME_H_

#include	"IGameDevice.h"
#include	"Manager/Scene/SceneManager.h"

/**
 * @brief ゲームフレームクラス．
 */
class GameFrame
{
public:

	/**
	 * コンストラクタ
	 */
	GameFrame();

	
	/**
	 * 初期化処理<br>
	 * 
	 * @param[in] device ゲームデバイス.
	 * @return なし.
	 */
	void Initialize( IGameDevice& device );

	
	/**
	 * 更新処理<br>
	 * 
	 * @param[in] device ゲームデバイス.
	 * @param[in] frameTimer フレーム処理時間.
	 * @return なし.
	 */
	void Update( IGameDevice& device, float frameTimer );


	/**
	 * 描画処理<br>
	 * 
	 * @param[in] device ゲームデバイス.
	 * @return なし.
	 */
	void Draw( IGameDevice& device );

	
	/**
	 * 終了処理<br>
	 * 
	 * @param[in] device ゲームデバイス.
	 * @return なし.
	 */
	void Finish( IGameDevice& device );

private:
	// !< 変数の簡易説明
	SceneManager* m_sceneManager;

};

#endif

/*===== EOF ==================================================================*/