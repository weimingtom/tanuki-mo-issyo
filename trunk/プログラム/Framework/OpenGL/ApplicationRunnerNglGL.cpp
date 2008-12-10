/*******************************************************************************/
/*
 * @file ApplicationRunnerNglGL.cpp.<br>
 * 
 * @brief NglGLライブラリ アプリケーション実行クラスソースファイル.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"ApplicationRunnerNglGL.h"

/*=========================================================================*/
/**
 * コンストラクタ<br>
 * 
 * @param[in] desc フレームワーク記述子.
 * @param[in] argc コマンドライン引数数.
 * @param[in] argv コマンドライン引数.
 */
ApplicationRunnerNglGL::ApplicationRunnerNglGL( const Ngl::FrameWorkDesc& desc, int argc, char* argv[] ):
	Ngl::OpenGL::FrameWorkGLUT( desc, argc, argv )
{}



/*=========================================================================*/
/**
 * デストラクタ<br>
 * 
 * @param[in] なし.
 */
ApplicationRunnerNglGL::~ApplicationRunnerNglGL()
{}



/*=========================================================================*/
/**
 * アプリケーションの実行<br>
 * 
 * @param[in] なし.
 * @return 終了コード.
 */
int ApplicationRunnerNglGL::runApp()
{
	return run();
}


	
/*=========================================================================*/
/**
 * 初期化処理<br>
 * 
 * @param[in] なし.
 * @return なし.
 */
void ApplicationRunnerNglGL::initialize()
{
	// ゲームデバイスを作成
	device_.Create( *this );

	// ビューポートの設定
	static const ViewportDesc viewportDesc = { 0, 0, desc().windowWidth, desc().windowHeight };
	device_.GetGraphicDevice().Viewport( viewportDesc );

	// ゲームの初期化処理
	game_.Initialize( device_ );
}



/*=========================================================================*/
/**
 * 更新処理<br>
 * 
 * @param[in] deltaTime 処理の補正値.
 * @return なし.
 */
void ApplicationRunnerNglGL::update( float deltaTime )
{
	// ゲームデバイスの更新処理
	device_.Update( deltaTime );

	// ゲームの更新処理
	game_.Update( device_, deltaTime );
}



/*=========================================================================*/
/**
 * 描画処理<br>
 * 
 * @param[in] なし.
 * @return なし.
 */
void ApplicationRunnerNglGL::draw()
{
	// ゲームの描画処理
	game_.Draw( device_ );

	// バックバッファに描画
	device_.GetGraphicDevice().Renderer().flush();
}



/*=========================================================================*/
/**
 * 終了処理<br>
 * 
 * @param[in] なし.
 * @return なし.
 */
void ApplicationRunnerNglGL::end()
{
	// ゲームの終了処理
	game_.Finish( device_ );

	// デバイスの終了処理
	device_.End();
}



/*===== EOF ==================================================================*/