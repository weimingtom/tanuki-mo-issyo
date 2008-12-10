/*******************************************************************************/
/**
 * @file GraphicDeviceNglGL.cpp.<br>
 * 
 * @brief NGLライブラリOpenGLグラフィックデバイスクラスソースファイル.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"GraphicDeviceNglGL.h"
#include	<Ngl/OpenGL/RendererGL.h>
#include	<cassert>


/*=========================================================================*/
/**
 * コンストラクタ<br>
 * 
 * @param[in] frame フレームワーク.
 */
GraphicDeviceNglGL::GraphicDeviceNglGL( Ngl::OpenGL::FrameWorkGLUT& frame ):
GraphicDeviceBase( frame )
{}



/*=========================================================================*/
/**
 * デストラクタ<br>
 * 
 * @param[in] なし.
 */
GraphicDeviceNglGL::~GraphicDeviceNglGL()
{}



/*=========================================================================*/
/**
 * 作成処理<br>
 * 
 * @param[in] frame フレームワーク.
 * @return なし.
 */
void GraphicDeviceNglGL::Create( Ngl::IFrameWork* frame )
{
	// レンダラーを作成
	renderer_ = new Ngl::OpenGL::RendererGL;
	assert( renderer_ != NULL );
	renderer_->initialize();

	// ビューポートを初期化
	Ngl::ViewportDesc viewport = { 0, 0, frame->desc().windowWidth, frame->desc().windowHeight };
	renderer_->setViewport( viewport );

	// エフェクトの拡張子を設定
	effectExtName_ = ".cgfx";

	// 四角形ポリゴンを作成
	quad_.create( renderer_  );
}
	
	

/*===== EOF ==================================================================*/