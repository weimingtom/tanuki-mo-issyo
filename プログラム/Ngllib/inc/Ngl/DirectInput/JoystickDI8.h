/*******************************************************************************/
/**
 * @file JoystickDI8.h.
 * 
 * @brief DirectInput ジョイスティッククラスヘッダファイル.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_INPUT_JOYSTICKDI8_H_
#define _NGL_INPUT_JOYSTICKDI8_H_

#include	"DirectInput.h"
#include	"Ngl/Vector3.h"
#include	<vector>

namespace Ngl{


namespace DirectInput{

/**
 * @class JoystickDI8.
 * @brief DirectInput ジョイスティッククラス．
 */
class JoystickDI8
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	JoystickDI8();


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~JoystickDI8();
	
	
	/*=========================================================================*/
	/**
	 * @brief デバイスを作成する
	 * 
	 * @param[in] di インプットデバイス.
	 * @param[in] inst インスタンス.
	 * @param[in] hwnd ウィンドウハンドル.
	 * @retval true 取得成功.
	 * @retval false 取得失敗.
	 */
	bool create( LPDIRECTINPUT8 di, LPCDIDEVICEINSTANCE inst, HWND hwnd );
	
	
	/*=========================================================================*/
	/**
	 * @brief 状態を読み込む
	 * 
	 * @param[in] なし.
	 * @retval true 成功.
	 * @retval false 失敗.
	 */
	bool loadKeyState();
	
	
	/*=========================================================================*/
	/**
	 * @brief 軸の状態を読み込む
	 * 
	 * @param[in] なし.
	 * @return 各軸の状態ベクトル.
	 */
	Vector3 readAxisState();

	
	/*=========================================================================*/
	/**
	 * @brief 何かしらのキーが押されているか調べる
	 * 
	 * @param[in] なし.
	 * @retval 1以上 押されている.
	 * @retval 0 何も押されていない.
	 */
	bool getKeyDown();


	/*=========================================================================*/
	/**
	 * @brief 指定したキーが押されているか調べる
	 * 
	 * @param[in] key 調べるキー.
	 * @retval true 押されていた.
	 * @retval false 押されていなかった.
	 */
	bool getKeyDown( unsigned int key );
	
	
	/*=========================================================================*/
	/**
	 * @brief 押されているキーを調べる
	 * 
	 * @param[in] なし.
	 * @retval 1以上 押されているキー.
	 * @retval 0 何も押されていない.
	 */
	unsigned int getDownKey();


	/*=========================================================================*/
	/**
	 * @brief 何かしらのキーが離されたか調べる
	 * 
	 * @param[in] なし.
	 * @retval true 離された.
	 * @retval false 離されていない.
	 */
	bool getKeyRelease();


	/*=========================================================================*/
	/**
	 * @brief 指定したキーが離されたか調べる
	 * 
	 * @param[in] key 調べるキー.
	 * @retval true 離された.
	 * @retval false 離されていない.
	 */
	bool getKeyRelease( unsigned int key );


	/*=========================================================================*/
	/**
	 * @brief 離されたキーを調べる
	 * 
	 * @param[in] なし.
	 * @retval 1以上 離されたキー.
	 * @retval 0 離されていない。
	 */
	unsigned int getReleaseKey();


	/*=========================================================================*/
	/**
	 * @brief なにかしらのキーがタイプされたか
	 * 
	 * @param[in] なし.
	 * @retval true タイプされた.
	 : @retval false タイプされていない.
	 */
	bool getKeyTrigger();


	/*=========================================================================*/
	/**
	 * @brief 指定のキーがタイプされたか調べる
	 * 
	 * @param[in] key 調べるキー.
	 * @retval true タイプされた.
	 * @retval false タイプされていない.
	 */
	bool getKeyTrigger( unsigned int key );


	/*=========================================================================*/
	/**
	 * @brief タイプされたキーを取得する
	 * 
	 * @param[in] なし.
	 * @retval 1以上 タイプされたキー.
	 * @retval 0 タイプされていない.
	 */
	unsigned int getTriggerKey();
	
	
	/*=========================================================================*/
	/**
	 * @brief アクセス権の再取得
	 * 
	 * @param[in] なし.
	 * @retval true 取得成功.
	 * @retval false 取得失敗.
	 */
	bool getReacquire();

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
	 * @brief プロパティの設定
	 * 
	 * @param[in] guid 設定対象の識別子.
	 * @param[in] obj 設定する項目.
	 * @param[in] how 設定値の方法.
	 * @param[in] val 設定値.
	 * @return なし.
	 */
	HRESULT setDevProperty( REFGUID guid, DWORD obj, DWORD how, DWORD val );


	/*=========================================================================*/
	/**
	 * @brief 斜め入力判定
	 * 
	 * @param[in] buf 判定するバッファ.
	 * @return 入力されたキー.
	 */
	int judgementDiagonalKey( int buf );


	/*=========================================================================*/
	/**
	 * @brief 入力されたキーを変換する
	 * 
	 * @param[in] key 変換するキー.
	 * @return 変換後のキー.
	 */
	unsigned int convertKey( unsigned int key );

private:

	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ コピー禁止処理
	 * 
	 * @param[in] other コピー元のオブジェクト.
	 */
	JoystickDI8( const JoystickDI8& other );


	/*=========================================================================*/
	/**
	 * @brief = 演算子オーバーロード コピー禁止処理
	 * 
	 * @param[in] other コピー元のオブジェクト.
	 * @return コピー結果のオブジェクト.
	 */
	JoystickDI8& operator = ( const JoystickDI8& other );

public:

	/** 最大ジョイスティックボタン数 */
	static const int BUTTON_MAX = 10;

	/** 十字キー数最大数 */
	static const int CROSSKEY_MAX = 4;

	/** 斜め十時キー数最大数 */
	static const int DIAGONALCROSSKEY_MAX = 4;

	/** キーの合計数 */
	static const int JOYSTICKKEY_MAX = BUTTON_MAX + CROSSKEY_MAX + DIAGONALCROSSKEY_MAX;

private:

	/** DirectInputDeviceオブジェクト */
	LPDIRECTINPUTDEVICE8	padDevice_;

	/** 古いジョイスティｯクのバッファ */
	int*					oldBuf_;

	/** 新しいジョイスティｯクのバッファ */
	int*					newBuf_;

	/** ジョイスティｯクの状態 */
	int						state_[2];

};

}	// namespace DirectInput

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/