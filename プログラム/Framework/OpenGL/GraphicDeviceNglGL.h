/*******************************************************************************/
/**
 * @file GraphicDeviceNglGL.h.<br>
 * 
 * @brief NGLライブラリOpenGLグラフィックデバイスクラスヘッダファイル.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _GRAPHICDEVICENGLGL_H_
#define _GRAPHICDEVICENGLGL_H_

#include	"GraphicDeviceBase.h"
#include	<Ngl/OpenGL/FrameWorkGLUT.h>

/**
 * @brief NGLライブラリOpenGLグラフィックデバイスクラス.
 */
class GraphicDeviceNglGL : public GraphicDeviceBase
{
public:

	/*=========================================================================*/
	/**
	 * コンストラクタ<br>
	 * 
	 * @param[in] frame フレームワーク.
	 */
	GraphicDeviceNglGL( Ngl::OpenGL::FrameWorkGLUT& frame );

	
	/*=========================================================================*/
	/**
	 * デストラクタ<br>
	 * 
	 * @param[in] なし.
	 */
	virtual ~GraphicDeviceNglGL();

	
	/*=========================================================================*/
	/**
	 * 作成処理<br>
	 * 
	 * @param[in] frame フレームワーク.
	 * @return なし.
	 */
	void Create( Ngl::IFrameWork* frame );

};


#endif

/*===== EOF ==================================================================*/