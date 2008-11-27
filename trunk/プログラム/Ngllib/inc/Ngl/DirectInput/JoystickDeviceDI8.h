/*******************************************************************************/
/**
 * @file JoystickDeviceDI8.h.
 * 
 * @brief DirectInput ジョイスティック入力デバイスクラスヘッダファイル.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DIRECTINPUT_JOYSTICKDEVICEDI8_H_
#define _NGL_DIRECTINPUT_JOYSTICKDEVICEDI8_H_

#include	"DirectInput.h"
#include	"JoystickDI8.h"
#include	"Ngl/IInputDevice.h"
#include	"Ngl/Vector3.h"
#include	<vector>

namespace Ngl{


namespace DirectInput{


/**
 * @class JoystickDeviceDI8.
 * @brief DirectInput ジョイスティック入力デバイスクラス．
 */
class JoystickDeviceDI8 : public IInputDevice
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	JoystickDeviceDI8();


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~JoystickDeviceDI8();


	/*=========================================================================*/
	/**
	 * @brief 入力デバイスの作成
	 * 
	 * @param[in] hwnd ウィンドウハンドル.
	 * @return なし.
	 */
	bool create( HWND hwnd );


	/*=========================================================================*/
	/**
	 * @brief 指定のジョイスティックから軸の状態を読み込む
	 * 
	 * @param[in] なし.
	 * @return 各軸の状態ベクトル.
	 */
	virtual Vector3 readAxisState();

	
	/*=========================================================================*/
	/**
	 * @brief キー情報を読み込む
	 * 
	 * @param[in] なし.
	 * @retval true 取得成功.
	 * @retval false 取得失敗.
	 */
	virtual bool loadKeyState();
	
	
	/*=========================================================================*/
	/**
	 * @brief 接続デバイス数を取得
	 * 
	 * @param[in] なし.
	 * @return 接続デバイス数.
	 */
	virtual unsigned int getConnectDeviceCount();

	
	/*=========================================================================*/
	/**
	 * @brief アクティブにするデバイスを変更する
	 * 
	 * @param[in] no 変更するデバイス番号.
	 * @return なし.
	 */
	virtual void setActiveDevice( unsigned int no );
	
	
	/*=========================================================================*/
	/**
	 * @brief アクディブになっているデバイス番号を取得する
	 * 
	 * @param[in] なし.
	 * @return アクティブデバイス番号.
	 */
	virtual unsigned int getActiveDeviceNo();
	
	
	/*=========================================================================*/
	/**
	 * @brief 有効キー数を取得
	 *
	 * @retval true 取得成功.
	 * @retval false 取得失敗.
	 */
	virtual unsigned int getKeyCount();
	
	
	/*=========================================================================*/
	/**
	 * @brief 何かしらのキーが押されているか調べる
	 * 
	 * @param[in] なし.
	 * @retval 1以上 押されている.
	 * @retval 0 何も押されていない.
	 */
	virtual bool getKeyDown();


	/*=========================================================================*/
	/**
	 * @brief 指定したキーが押されているか調べる
	 * 
	 * @param[in] key 調べるキー.
	 * @retval true 押されていた.
	 * @retval false 押されていなかった.
	 */
	virtual bool getKeyDown( unsigned int key );


	/*=========================================================================*/
	/**
	 * @brief 押されているキーを調べる
	 * 
	 * @param[in] なし.
	 * @retval 1以上 押されているキー.
	 * @retval 0 何も押されていない.
	 */
	virtual unsigned int getDownKey();


	/*=========================================================================*/
	/**
	 * @brief 何かしらのキーが離されたか調べる
	 * 
	 * @param[in] なし.
	 * @retval true 離された.
	 * @retval false 離されていない.
	 */
	virtual bool getKeyRelease();


	/*=========================================================================*/
	/**
	 * @brief 指定したキーが離されたか調べる
	 * 
	 * @param[in] key 調べるキー.
	 * @retval true 離された.
	 * @retval false 離されていない.
	 */
	virtual bool getKeyRelease( unsigned int key );


	/*=========================================================================*/
	/**
	 * @brief 離されたキーを調べる
	 * 
	 * @param[in] なし.
	 * @retval 1以上 離されたキー.
	 * @retval 0 離されていない。
	 */
	virtual unsigned int getReleaseKey();


	/*=========================================================================*/
	/**
	 * @brief なにかしらのキーがタイプされたか
	 * 
	 * @param[in] なし.
	 * @retval true タイプされた.
	 : @retval false タイプされていない.
	 */
	virtual bool getKeyTrigger();


	/*=========================================================================*/
	/**
	 * @brief 指定のキーがタイプされたか調べる
	 * 
	 * @param[in] key 調べるキー.
	 * @retval true タイプされた.
	 * @retval false タイプされていない.
	 */
	virtual bool getKeyTrigger( unsigned int key );


	/*=========================================================================*/
	/**
	 * @brief タイプされたキーを取得する
	 * 
	 * @param[in] なし.
	 * @retval 1以上 タイプされたキー.
	 * @retval 0 タイプされていない.
	 */
	virtual unsigned int getTriggerKey();
	
	
	/*=========================================================================*/
	/**
	 * @brief 接続されているジョイスティックの数を調べる
	 * 
	 * @param[in] なし.
	 * @return パッドの数.
	 */
	virtual unsigned int getCount();


	/*=========================================================================*/
	/**
	 * @brief 指定番号のジョイスティックが存在しているか調べる
	 * 
	 * @param[in] no 調べるジョイスティック番号.
	 * @retval true 存在してる.
	 * @retval false 存在していない.
	 */
	virtual bool isJoyDeviceExists( unsigned int no );

private:
	
	/*=========================================================================*/
	/**
	 * @brief ジョイスティックデバイスを解放する
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void release();


	/*=========================================================================*/
	/**
	 * @brief 登録されているジョイスティックのアクセス権の再取得
	 * 
	 * @param[in] なし.
	 * @retval true 取得成功.
	 * @retval false 取得失敗.
	 */
	void getReacquire();
	
	
	/*=========================================================================*/
	/**
	* @brief デバイスを作成する
	* 
	* @param[in] pdinst インスタンス.
	* @param[in] hnd ハンドル.
	* @return DIENUM_CONTINUE 列挙を続ける.
	*/
	static BOOL FAR PASCAL enumJoysticksCallback( LPCDIDEVICEINSTANCE pdinst, LPVOID hnd );

private:

	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ コピー禁止処理
	 * 
	 * @param[in] other コピーするオブジェクト.
	 */
	JoystickDeviceDI8( JoystickDeviceDI8& other );


	/*=========================================================================*/
	/**
	 * @brief = 演算子オーバーロード コピー禁止処理
	 * 
	 * @param[in] other コピー元のオブジェクト.
	 * @return コピー結果のオブジェクト.
	 */
	JoystickDeviceDI8& operator = ( JoystickDeviceDI8& other );

public:

	/** ジョイスティックデバイスの最大数 */
	static const int JOYSTIC_MAX = 8;

private:

	/** ジョイスティック配列型 */
	typedef std::vector< JoystickDI8* >	JoystickList;

private:

	/** DirectInputオブジェクト */
	LPDIRECTINPUT8		inputDevice_;

	/** ジョイスティックリスト */
	JoystickList		joystickList_;

	/** ウィンドウハンドル */
	HWND				joyHwnd_;

	/** アクティブなジョイスティック番号 */
	unsigned int		activeJoystickNo_;

};

}	// namespace DirectInput

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/