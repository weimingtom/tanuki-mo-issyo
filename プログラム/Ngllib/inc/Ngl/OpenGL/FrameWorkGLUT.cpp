/*******************************************************************************/
/**
 * @file FrameWorkGLUT.cpp.
 * 
 * @brief OpenGL GLUTフレームワーククラスソースファイル.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"FrameWorkGLUT.h"
#include	"GL/glut.h"
#include	<windows.h>
#include	<sstream>
#include	<cassert>

using namespace Ngl;
using namespace Ngl::OpenGL;


// 自分自身のインスタンスを初期化
FrameWorkGLUT* FrameWorkGLUT::instance_ = 0;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] desc フレームワーク記述子.
 * @param[in] argc コマンドライン引数数.
 * @param[in] argv コマンドライン引数.
 */
FrameWorkGLUT::FrameWorkGLUT( const FrameWorkDesc& desc, int argc, char* argv[] ):
	desc_( desc )	// フレームワーク記述子
{
	// 自分のインスタンスを設定
	instance_ = this;

	// GULTを初期化
	glutInit( &argc, argv );
}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
FrameWorkGLUT::~FrameWorkGLUT()
{}



/*=========================================================================*/
/**
 * @brief アプリケーションの実行
 * 
 * @param[in] なし.
 * @return 終了コード.
 */
int FrameWorkGLUT::run()
{
	// GLUTウィンドウの設定
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
	glutInitWindowPosition( desc().posX, desc().posY );
	glutInitWindowSize( desc().windowWidth, desc().windowHeight );

	// フルスクリーンモードか？
	if( desc().isFullScreenMode == true ){
		// フルスクリーンモード設定文字列を作成
		std::ostringstream mode;
		mode << desc().windowWidth << "x" << desc().windowHeight << "@60";

		// フルスクリーンモードに設定
		glutGameModeString( mode.str().c_str() );
		glutEnterGameMode();

		// マウスカーソルを消去
		glutSetCursor( GLUT_CURSOR_NONE );
	}
	else{
		glutCreateWindow( desc().windowTitle.c_str() );
	}

	// Vsyncを有効にする
	setSwapInterval( 1 );

	// 初期化処理を実行
	initialize();

	// コールバックを登録
	_glutDestroyFunc( onDestroy );
	glutReshapeFunc( onReshape );
	glutDisplayFunc( onDisplay );
	glutIdleFunc( onIdle );
	_glutActivateFunc( onActivate );

	// フレームタイマーをリセット
	frameTimer_.reset();

	// メインループ処理を行う
	glutMainLoop();

	// 実行終了
	return 0;
}



/*=========================================================================*/
/**
 * @brief アプリケーションの終了
 * 
 * @param[in] なし.
 * @return なし.
 */
void FrameWorkGLUT::exit()
{
	// フルスクリーンモードか
	if( instance_->desc().isFullScreenMode == true ){
		// アプリケーションを終了する
		glutLeaveGameMode();
	}
	else{
		// 終了処理を呼ぶ
		instance_->end();
	}

	// 強制終了する
	std::exit( 0 );
}
	
	

/*=========================================================================*/
/**
 * @brief フレームワーク記述子を取得
 * 
 * @param[in] なし.
 * @return フレームワーク記述子.
 */
const FrameWorkDesc& FrameWorkGLUT::desc() const
{
	return desc_;
}



/*=========================================================================*/
/**
 * @brief ウィンドウハンドルを取得する
 * 
 * @param[in] なし.
 * @return ウィンドウハンドル.
 */
void* FrameWorkGLUT::getHWND()
{
	return  _glutGetHWND();
}



/*=========================================================================*/
/**
 * @brief アクティブになったときに呼ばれる処理
 * 
 * 1 アクティブになった
 * 0 非アクティブになった
 *
 * @param[in] state 状態フラグ.
 * @return なし.
 */
void FrameWorkGLUT::onActivate( int state )
{
	// アクティブ時の処理を呼ぶ
	instance_->activate( state );
}



/*=========================================================================*/
/**
 * @brief 描画されるときに呼ばれる処理
 * 
 * @param[in] なし.
 * @return なし.
 */
void FrameWorkGLUT::onDisplay()
{
	// 描画処理
	instance_->draw();

	// ダブルバッファの切り替え
	glutSwapBuffers();

	// タイマーウェイトを行う
	instance_->frameTimer_.wait();
}



/*=========================================================================*/
/**
 * @brief アイドル処理時に呼ばれる処理
 * 
 * @param[in] なし.
 * @return なし.
 */
void FrameWorkGLUT::onIdle()
{
	// フレームタイマーの更新
	instance_->frameTimer_.update();

	do{
		// 更新処理を実行
		instance_->update( instance_->frameTimer_.getTime() );

		// エスケープキーが押されたか
		if( GetAsyncKeyState( VK_ESCAPE ) != 0 ){
			// 終了処理
			instance_->exit();
		}
	}while( instance_->frameTimer_.isSkipFrame() == true );

	// 描画処理を呼ぶ
	glutPostRedisplay();
}



/*=========================================================================*/
/**
 * @brief ウィンドウサイズが変更されたときに呼ばれる処理
 * 
 * @param[in] width 変更されたウィンドウ幅.
 * @param[in] height 変更されたウィンドウ高さ.
 * @return なし.
 */
void FrameWorkGLUT::onReshape( int width, int height )
{
	// 高さが0にならないように調整
	height = ( height == 0 ) ? 1 : height;

	// ビューポートの設定
	glViewport( 0, 0, width, height );

	// 幅と高さを更新
	instance_->desc_.windowWidth	= width;
	instance_->desc_.windowHeight	= height;
}



/*=========================================================================*/
/**
 * @brief 削除時に呼ばれる処理
 * 
 * @param[in] なし.
 * @return なし.
 */
void FrameWorkGLUT::onDestroy()
{
	// 終了処理を実行
	instance_->end();
}



/*=========================================================================*/
/**
 * @brief Vsyncを設定する
 * 
 * @param[in] interval 更新間隔.
 * @return なし.
 */
void FrameWorkGLUT::setSwapInterval( int interval )
{
	// wglSwapIntervalEXT拡張関数のポインタ型
	typedef BOOL ( WINAPI * LPFNWGLSWAPINTERVALEXTPROC )( int interval );
	LPFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = NULL;

	// 拡張関数の関数ポインタを取得
	wglSwapIntervalEXT = ( LPFNWGLSWAPINTERVALEXTPROC )wglGetProcAddress( "wglSwapIntervalEXT" );

	// 取得できたか
	assert( wglSwapIntervalEXT != NULL );
	if( wglSwapIntervalEXT != NULL ){
		// スワップのインターバルを設定
		wglSwapIntervalEXT( interval );
	}
}

	
	
/*===== EOF ==================================================================*/