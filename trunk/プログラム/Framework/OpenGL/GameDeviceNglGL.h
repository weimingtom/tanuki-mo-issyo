/*******************************************************************************/
/**
 * @file GameDeviceNglGL.h.<br>
 * 
 * @brief NGLライブラリOpenGLゲームデバイス実装クラスヘッダファイル.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _GAMEDEVICENGLGL_H_
#define _GAMEDEVICENGLGL_H_

#include	<Ngl/OpenGL/FrameWorkGLUT.h>
#include	"GameDeviceBase.h"
#include	"GraphicDeviceNglGL.h"
#include	"SoundDeviceDS.h"
#include	"InputDeviceImpl.h"
#include	"IGameDevice.h"
#include	"Define/GaugeDesc.h"
#include	"Define/TextDesc.h"

/**
 * @brief NGLライブラリOpenGLゲームデバイス実装クラス.
 */
class GameDeviceNglGL : public GameDeviceBase< GraphicDeviceNglGL, InputDeviceImpl, SoundDeviceDS >
{
public:

	/*=========================================================================*/
	/**
	 * コンストラクタ<br>
	 * 
	 * @param[in] 引数名 引数説明.
	 */
	GameDeviceNglGL();
	
	
	/*=========================================================================*/
	/**
	 * 作成処理<br>
	 * 
	 * @param[in] frame フレームワーク.
	 * @return なし.
	 */
	virtual void CreateDevice( Ngl::IFrameWork& frame );

private:

	/*=========================================================================*/
	/**
	 * コピーコンストラクタ( コピー禁止 )<br>
	 * 
	 * @param[in] other コピーするオブジェクト.
	 */
	GameDeviceNglGL( const GameDeviceNglGL& other );


	/*=========================================================================*/
	/**
	 * = 演算子オーバーロード( コピー禁止 )<br>
	 * 
	 * @param[in] other 代入するオブジェクト.
	 * @return 代入結果のオブジェクト
	 */
	GameDeviceNglGL& operator = ( const GameDeviceNglGL& other );

};

#endif

/*===== EOF ==================================================================*/