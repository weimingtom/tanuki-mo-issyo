/*******************************************************************************/
/**
 * @file IInputDevice.h.<br>
 * 
 * @brief 入力デバイスインターフェース.<br>
 *
 * @date 2008/07/20.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _IINPUTDEVICE_H_
#define _IINPUTDEVICE_H_

#include "Define/Define.h"

/**
 * @enum InputDeviceID
 * @brief 入力デバイスID列挙型.
 */
enum InputDeviceID
{
	INPUTDEVICEID_KEYBOARD	= 0,	/**< キーボードデバイス			*/
	INPUTDEVICEID_JOYSTICK	= 1,	/**< ジョイスティックデバイス	*/
};

/**
 * @brief 入力デバイスインターフェース.
 */
class IInputDevice
{
protected:

	/**
	 * @brief デストラクタ.
	 */
	virtual ~IInputDevice(){}

public:
	
	/**
	 * @brief アクティブのデバイスを変更する<br>
	 * 
	 * @param[in] connectID アクティブにするデバイスの、変更する接続デバイス番号.
	 * @return なし.
	 */
	virtual void ChangeActiveDevice( unsigned int connectID=0 ) = 0;

	
	/**
	 * @brief アクティブの入力デバイスを取得する<br>
	 * 
	 * @param[in] なし.
	 * @return アクティブデバイス番号.
	 */
	virtual unsigned int GetActiveInputDeviceNo() = 0;
	
	
	/**
	 * @brief アクティブの入力デバイスのアクティブな接続デバイス番号を取得<br>
	 * 
	 * @param[in] なし.
	 * @return アクティブの入力デバイスのアクティブな接続デバイス番号.
	 */
	virtual unsigned int GetActiveConnectDeviceNo() = 0;
	
	
	/**
	 * @brief 入力デバイス数を取得<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual unsigned int GetDeviceCount() = 0;
	
	
	/**
	 * @brief アクティブデバイスの、接続デバイス数を取得<br>
	 * 
	 * @param[in] なし.
	 * @return 接続デバイス数.
	 */
	virtual unsigned int GetConnectDeviceCount() = 0;
	
		
	/**
	 * @brief 何かしらのキーが押されているか調べる<br>
	 * 
	 * @param[in] なし.
	 * @retval 1以上 押されている.
	 * @retval 0 何も押されていない.
	 */
	virtual bool GetKeyDown() = 0;


	/**
	 * @brief 指定したキーが押されているか調べる<br>
	 * 
	 * @param[in] key 調べるキー.
	 * @retval true 押されていた.
	 * @retval false 押されていなかった.
	 */
	virtual bool GetKeyDown( unsigned int key ) = 0;


	/**
	 * @brief 押されているキーを調べる<br>
	 * 
	 * @param[in] なし.
	 * @retval 1以上 押されているキー.
	 * @retval 0 何も押されていない.
	 */
	virtual unsigned int GetDownKey() = 0;


	/**
	 * @brief 何かしらのキーが離されたか調べる<br>
	 * 
	 * @param[in] なし.
	 * @retval true 離された.
	 * @retval false 離されていない.
	 */
	virtual bool GetKeyRelease() = 0;


	/**
	 * @brief 指定したキーが離されたか調べる<br>
	 * 
	 * @param[in] key 調べるキー.
	 * @retval true 離された.
	 * @retval false 離されていない.
	 */
	virtual bool GetKeyRelease( unsigned int key ) = 0;


	/**
	 * @brief 離されたキーを調べる<br>
	 * 
	 * @param[in] なし.
	 * @retval 1以上 離されたキー.
	 * @retval 0 離されていない。
	 */
	virtual unsigned int GetReleaseKey() = 0;


	/**
	 * @brief なにかしらのキーがタイプされたか<br>
	 * 
	 * @param[in] なし.
	 * @retval true タイプされた.
	 : @retval false タイプされていない.
	 */
	virtual bool GetKeyTrigger() = 0;


	/**
	 * @brief 指定のキーがタイプされたか調べる<br>
	 * 
	 * @param[in] key 調べるキー.
	 * @retval true タイプされた.
	 * @retval false タイプされていない.
	 */
	virtual bool GetKeyTrigger( unsigned int key ) = 0;


	/**
	 * @brief タイプされたキーを取得する<br>
	 * 
	 * @param[in] なし.
	 * @retval 1以上 タイプされたキー.
	 * @retval 0 タイプされていない.
	 */
	virtual unsigned int GetTriggerKey() = 0;

	
	/**
	 * @brief 入力を更新する<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void Reload() = 0;

	
	/**
	 * @brief 終了キーが押されたか<br>
	 * 
	 * @param[in] なし.
	 * @retval true 押された.
	 * @retval false 押されていない.
	 */
	virtual bool IsInputEndKey() = 0;
};

#endif

/*========= End of File =====================================================*/