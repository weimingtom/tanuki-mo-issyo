/*******************************************************************************/
/**
 * @file MouseDeviceDI8.h.
 * 
 * @brief DirectInput マウス入力デバイスクラスヘッダファイル.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DIRECTINPUT_MOUSEDEVICEDI8_H_
#define _NGL_DIRECTINPUT_MOUSEDEVICEDI8_H_

#include	"DirectInput.h"
#include	"Ngl/IInputDevice.h"
#include	"Ngl/Vector3.h"
#include	"Ngl/Rect.h"


namespace Ngl{


namespace DirectInput{


/**
 * @class MouseDeviceDI8.
 * @brief DirectInput マウス入力デバイスクラス．
 */
class MouseDeviceDI8 : public IInputDevice
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	MouseDeviceDI8();


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~MouseDeviceDI8();


	/*=========================================================================*/
	/**
	 * @brief マウス入力デバイスの作成
	 * 
	 * @param[in] hwnd ウィンドウハンドル.
	 * @retval true 作成成功.
	 * @retval false 作成失敗.
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
	
	
	/*=========================================================================*/
	/**
	 * @brief マウスカーソルの移動可能範囲を設定する
	 * 
	 * @param[in] clip 移動可能範囲.
	 * @return なし.
	 */
	void setMouseCursorClip( const Rect& clip );


	/*=========================================================================*/
	/**
	 * @brief マウスの移動比率を設定する
	 * 
	 * @param[in] ratio 移動比率.
	 * @return なし.
	 */
	void setMouseCursorRatio( float ratio );


	/*=========================================================================*/
	/**
	 * @brief マウスの位置座標を設定する
	 * 
	 * @param[in] x x座標.
	 * @param[in] y y座標.
	 * @param[in] z z座標.
	 * @return なし.
	 */
	void setMousePosition( int x, int y, int z );
	
	
	/*=========================================================================*/
	/**
	 * @brief マウスカーソルの移動量を取得する
	 * 
	 * @param[in] なし.
	 * @return カーソルの各成分の移動量.
	 */
	inline Ngl::Vector3& getCursorVelocity()
	{
		return ltm_;
	}


	/*=========================================================================*/
	/**
	 * @brief マウスカーソルの位置を取得する
	 * 
	 * @param[in] なし.
	 * @return カーソルの位置座標.
	 */
	inline Ngl::Vector3& getMouseCursorPosition()
	{
		return position_;
	}


	/*=========================================================================*/
	/**
	 * @brief マウスカーソルの移動可能範囲を取得する
	 * 
	 * @param[in] なし.
	 * @return カーソルの移動可能範囲.
	 */
	inline Ngl::Rect& getMouseCursorClip()
	{
		return clip_;
	}


	/*=========================================================================*/
	/**
	 * @brief マウスの移動比率を取得する
	 * 
	 * @param[in] なし.
	 * @return マウスの移動比率.
	 */
	inline float getMouseCursorRatio()
	{
		return ratio_;
	}

private:

	/*=========================================================================*/
	/**
	 * @brief マウス入力情報の取得
	 * 
	 * @param[in] なし.
	 * @retval true 取得成功.
	 * @retval false 取得失敗.
	 */
	void readMouseData();
	
	
	/*=========================================================================*/
	/**
	 * @brief マウス座標をクリッピング
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void clipMouseCursor();
	
	
	/*=========================================================================*/
	/**
	 * @brief マウスのアクセス権の再取得
	 * 
	 * @param[in] なし.
	 * @retval true 取得成功.
	 * @retval false 取得失敗.
	 */
	bool getReacquire();


	/*=========================================================================*/
	/**
	 * @brief マウスデバイスを解放する
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

private:

	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ (コピー禁止処理)
	 * 
	 * @param[in] other コピーするオブジェクト.
	 */
	MouseDeviceDI8( MouseDeviceDI8& other );


	/*=========================================================================*/
	/**
	 * @brief = 演算子オーバーロード (コピー禁止処理)
	 * 
	 * @param[in] other コピー元のMouseDeviceDI8.
	 * @return コピー結果のMouseDeviceDI8.
	 */
	MouseDeviceDI8& operator = ( MouseDeviceDI8& other );

public:

	/** マウスのデフォルトの移動比率 */
	static const float RATIO_DEFAULT;

private:

	/** DirectInputオブジェクト */
	LPDIRECTINPUT8			inputDevice_;

	/** DirectInputDeviceオブジェクト */
	LPDIRECTINPUTDEVICE8	mouseDevice_;

	/** 現在のマウスカーソル位置座標 */
	Ngl::Vector3			position_;

	/** 前回からのカーソル移動量 */
	Ngl::Vector3			ltm_;

	/** 現在のマウスボタンの状態 */
	int						nowBtn_;

	/** 前回のマウスボタンの状態 */
	int						oldBtn_;

	/** マウスの移動範囲 */
	Ngl::Rect				clip_;

	/** マウスカーソルの移動比率 */
	float					ratio_;

};

}	// namespace DirectInput

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/