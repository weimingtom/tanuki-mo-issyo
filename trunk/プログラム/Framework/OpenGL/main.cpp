/*******************************************************************************/
/**
 * @file main.cpp.<br>
 * 
 * @brief メイン関数定義ファイル.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"ApplicationRunnerNglGL.h"

// メモリリークチェック設定
#ifdef _DEBUG
#include	<crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#endif

#pragma comment( linker, "/entry:mainCRTStartup" )

/*=========================================================================*/
/**
 * メイン関数<br>
 * 
 * @param[in] argc コマンド引数数.
 * @param[in] argv コマンド引数.
 * @return 0.
 */
int main( int argc, char* argv[] )
{
	// メモリリークチェックを有効にする
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	// ゲームフレーム記述子を設定
	Ngl::FrameWorkDesc desc;
	desc.windowWidth		= WINDOW_WIDTH;
	desc.windowHeight		= WINDOW_HEIGHT;
	desc.windowTitle		= "GameFrame";
	
	// フルスクリーンに設定
	//desc.isFullScreenMode	= true;
	
	ApplicationRunnerNglGL app( desc, argc, argv );

	// ゲームを開始
	app.runApp();

	return 0;
}



/*===== EOF ==================================================================*/