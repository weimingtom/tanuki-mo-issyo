/*******************************************************************************/
/**
 * @file IGameDevice.h.<br>
 * 
 * @brief ゲームデバイスインターフェース定義.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _IGAMEDEVICE_H_
#define _IGAMEDEVICE_H_

#include	"IGraphicDevice.h"
#include	"IInputDevice.h"
#include	"ISoundDevice.h"
#include	"Define/Define.h"
#include	<string>

class IMovieScene;

/**
 * @brief ゲームデバイスインターフェース
 */
class IGameDevice
{
protected:

	/**
	 * @brief デストラクタ<br>
	 * 
	 * @param[in] なし.
	 */
	virtual ~IGameDevice() {}

public:
	
	/**
	 * @brief グラフィックデバイスを取得<br>
	 * 
	 * @param[in] なし.
	 * @return グラフィックデバイス.
	 */
	virtual IGraphicDevice& GetGraphicDevice() = 0;

	
	/**
	 * @brief サウンドデバイスを取得<br>
	 * 
	 * @param[in] なし.
	 * @return サウンドデバイス.
	 */
	virtual ISoundDevice& GetSoundDevice() = 0;

	
	/**
	 * @brief 入力デバイスを取得<br>
	 * 
	 * @param[in] なし.
	 * @return 入力デバイス.
	 */
	virtual IInputDevice& GetInputDevice() = 0;

	
	/**
	 * @brief ウィンドウハンドルを取得<br>
	 * 
	 * @param[in] なし.
	 * @return ウィンドウハンドル.
	 */
	virtual void* GetHWND() = 0;

	
	/**
	 * @brief ウィンドウ幅を取得<br>
	 * 
	 * @param[in] なし.
	 * @return ウィンドウ幅.
	 */
	virtual int GetWindowWidth() = 0;

	
	/**
	 * @brief ウィンドウの高さを取得<br>
	 * 
	 * @param[in] なし.
	 * @return ウィンドウの高さ.
	 */
	virtual int GetWindowHeight() = 0;


	/**
	 * @brief ゲームを終了する<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void Exit() = 0;

};

#endif

/*===== EOF ==================================================================*/