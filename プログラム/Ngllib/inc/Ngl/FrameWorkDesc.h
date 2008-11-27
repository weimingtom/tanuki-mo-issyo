/*******************************************************************************/
/**
 * @file FrameWorkDesc.h.
 * 
 * @brief フレームワーク記述子構造体定義.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_FRAMEWORKDESC_H_
#define _NGL_FRAMEWORKDESC_H_

#include	<string>

namespace Ngl{

static const int FRAMEWORK_DEFAULT_WIDTH	= 640;	/**< デフォルトのウィンドウの幅		*/
static const int FRAMEWORK_DEFAULT_HEIGHT	= 480;	/**< デフォルトのウィンドウの高さ	*/

/**
 * @struct FrameWorkDesc．
 * @brief フレームワーク記述子構造体.
 */
struct FrameWorkDesc
{

	/** ウィンドウタイトル */
	std::string	windowTitle;

	/** ウィンドウのx座標 */
	int			posX;

	/** ウィンドウのy座標 */
	int			posY;

	/** ウィンドウの幅 */
	int			windowWidth;

	/** ウィンドウの高さ */
	int			windowHeight;

	/** フルスクリーンモード */
	bool		isFullScreenMode;


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	FrameWorkDesc():
		posX( 0 ),
		posY( 0 ),
		windowWidth( FRAMEWORK_DEFAULT_WIDTH ),
		windowHeight( FRAMEWORK_DEFAULT_HEIGHT ),
		isFullScreenMode( false )
	{}

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/