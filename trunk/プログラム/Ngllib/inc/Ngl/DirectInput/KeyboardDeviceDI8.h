/*******************************************************************************/
/**
 * @file KeyboardDeviceDI8.h.
 * 
 * @brief DirectInput キーボード入力デバイスクラスヘッダファイル.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_KEYBOARDUDEVICEDI8_H_
#define _NGL_KEYBOARDUDEVICEDI8_H_

#include	"DirectInput.h"
#include	"Ngl/IInputDevice.h"


namespace Ngl{


namespace DirectInput{


/**
 * @class KeyboardDeviceDI8.
 * @brief DirectInput キーボード入力デバイスクラス．
 */
class KeyboardDeviceDI8 : public IInputDevice
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	KeyboardDeviceDI8();


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~KeyboardDeviceDI8();
	

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
	 * @brief キー情報を読み込む
	 * 
	 * @param[in] なし.
	 * @retval true 取得成功.
	 * @retval false 取得失敗.
	 */
	virtual bool loadKeyState();
	
	
	/*=========================================================================*/
	/**
	 * @brief 軸の状態を読み込む
	 * 
	 * @param[in] なし.
	 * @return 各軸の状態ベクトル.
	 */
	virtual Vector3 readAxisState();
	
	
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

private:

	/*=========================================================================*/
	/**
	 * @brief アクセス権の再取得
	 * 
	 * @param[in] なし.
	 * @return true 取得成功  false 取得失敗.
	 */
	bool getReacquire();


	/*=========================================================================*/
	/**
	 * @brief キーボードデバイスを解放する
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void release();


	/*=========================================================================*/
	/**
	 * @brief キーを変換する
	 * 
	 * @param[in] key 変換するキー.
	 * @return 変換後のキー.
	 */
	unsigned int convertKey( unsigned int key );


	/*=========================================================================*/
	/**
	 * @brief DI8キーに変換する
	 * 
	 * @param[in] key 変換するキー.
	 * @return 変換後のDI8キー.
	 */
	unsigned int convertDI8Key( unsigned int key );

private:

	/** DirectInputキーボードキー数 */
	static const int DIRECTINPUTKEYBOARDKEY_COUNT = 256;

private:

	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ コピー禁止処理
	 * 
	 * @param[in] other コピーするオブジェクト.
	 */
	KeyboardDeviceDI8( KeyboardDeviceDI8& other );


	/*=========================================================================*/
	/**
	 * @brief = 演算子オーバーロード コピー禁止処理
	 * 
	 * @param[in] other コピー元のオブジェクト.
	 * @return コピー結果のオブジェクト.
	 */
	KeyboardDeviceDI8& operator = ( KeyboardDeviceDI8& other );

private:

	/** DirectInputオブジェクト */
	LPDIRECTINPUT8			inputDevice_;

	/** DirectInputDeviceオブジェクト */
	LPDIRECTINPUTDEVICE8	keyDevice_;

	/** 古いキーボードのバッファ */
	BYTE*					oldKeyBuf_;

	/** 新しいキーボードのバッファ */
	BYTE*					newKeyBuf_;

	/** キーボードの状態 */
	BYTE					keyState_[2][DIRECTINPUTKEYBOARDKEY_COUNT];

};

} // namespace DirectInput

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/