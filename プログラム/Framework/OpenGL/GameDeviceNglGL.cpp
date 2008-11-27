/*******************************************************************************/
/**
 * @file GameDeviceNglGL.cpp.<br>
 * 
 * @brief NGLライブラリOpenGLゲームデバイス実装クラスソースファイル.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"GameDeviceNglGL.h"
#include	<cassert>

/*=========================================================================*/
/**
 * コンストラクタ<br>
 * 
 * @param[in] 引数名 引数説明.
 */
GameDeviceNglGL::GameDeviceNglGL()
{}
	
	
	
/*=========================================================================*/
/**
 * 作成処理<br>
 * 
 * @param[in] frame フレームワーク.
 * @return なし.
 */
void GameDeviceNglGL::CreateDevice( Ngl::IFrameWork& frame )
{
	graphics_ = new GraphicDeviceNglGL( static_cast< Ngl::OpenGL::FrameWorkGLUT& >( frame ) );
	graphics_->Create( &frame );

	sound_ = new SoundDeviceDS();
	sound_->Create( static_cast< HWND >( frame.getHWND() ) );

	input_ = new InputDeviceImpl();
	input_->Create( static_cast< HWND >( frame.getHWND() ) );
}



/*===== EOF ==================================================================*/