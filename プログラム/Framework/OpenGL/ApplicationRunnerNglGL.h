/*******************************************************************************/
/*
 * @file ApplicationRunnerNglGL.h.<br>
 * 
 * @brief NglGLライブラリ アプリケーション実行クラスヘッダファイル.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _APPLICATIONRUNNERNGLGL_H_
#define _APPLICATIONRUNNERNGLGL_H_

#include	"GameFrame.h"
#include	"GameDeviceNglGL.h"
#include	"IApplicationRunner.h"
#include	<Ngl/OpenGL/FrameWorkGLUT.h>

/**
 * @class ApplicationRunner．
 * @briefアプリケーション実行クラス.
 */
class ApplicationRunnerNglGL : public Ngl::OpenGL::FrameWorkGLUT, public IApplicationRunner
{

public:

	/*=========================================================================*/
	/**
	 * コンストラクタ<br>
	 * 
	 * @param[in] desc フレームワーク記述子.
	 * @param[in] argc コマンドライン引数数.
	 * @param[in] argv コマンドライン引数.
	 */
	ApplicationRunnerNglGL( const Ngl::FrameWorkDesc& desc, int argc, char* argv[] );


	/*=========================================================================*/
	/**
	 * デストラクタ<br>
	 * 
	 * @param[in] なし.
	 */
	virtual ~ApplicationRunnerNglGL();


	/*=========================================================================*/
	/**
	 * アプリケーションの実行<br>
	 * 
	 * @param[in] なし.
	 * @return 終了コード.
	 */
	virtual int runApp();
	
private:
	
	/*=========================================================================*/
	/**
	 * 初期化処理<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void initialize();


	/*=========================================================================*/
	/**
	 * 更新処理<br>
	 * 
	 * @param[in] deltaTime 処理の補正値.
	 * @return なし.
	 */
	virtual void update( float deltaTime );


	/*=========================================================================*/
	/**
	 * 描画処理<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void draw();


	/*=========================================================================*/
	/**
	 * 終了処理<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void end();

private:

	/** ゲームデバイス */
	GameDeviceNglGL		device_;

	/** ゲーム */
	GameFrame			game_;

};

#endif

/*===== EOF ==================================================================*/