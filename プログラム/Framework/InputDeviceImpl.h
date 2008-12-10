/*******************************************************************************/
/**
 * @file InputDeviceImpl.h.<br>
 * 
 * @brief 入力デバイス実装クラスヘッダファイル.<br>
 *
 * @date 2008/07/20.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _INPUTDEVICEIMPL_H_
#define _INPUTDEVICEIMPL_H_

#include	"IInputDevice.h"
#include	<Ngl/InputDeviceManager.h>
#include	<windows.h>

/**
 * @brief 入力デバイス実装クラス.
 */
class InputDeviceImpl : public IInputDevice
{
public:

	
	/**
	 * @brief コンストラクタ.
	 *
	 * param[in] なし.
	 */
	InputDeviceImpl();

	
	/**
	 * @brief デストラクタ.
	 *
	 * param[in] なし.
	 */
	virtual ~InputDeviceImpl();

	
	/**
	 * @brief 作成処理<br>
	 * 
	 * @param[in] hwnd ウィンドウハンドル.
	 * @return なし.
	 */
	void Create( HWND hwnd );
	
	
	/**
	 * @brief 終了処理<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void End();
	
	
	/**
	 * @brief アクティブのデバイスを変更する<br>
	 * 
	 * @param[in] connectID アクティブにするデバイスの、変更する接続デバイス番号.
	 * @return なし.
	 */
	virtual void ChangeActiveDevice( unsigned int connectID=0 );

	
	/**
	 * @brief アクティブの入力デバイスを取得する<br>
	 * 
	 * @param[in] なし.
	 * @return アクティブデバイス番号.
	 */
	virtual unsigned int GetActiveInputDeviceNo();
	
	
	/**
	 * @brief アクティブの入力デバイスのアクティブな接続デバイス番号を取得<br>
	 * 
	 * @param[in] なし.
	 * @return アクティブの入力デバイスのアクティブな接続デバイス番号.
	 */
	virtual unsigned int GetActiveConnectDeviceNo();
	
	
	/**
	 * @brief 入力デバイス数を取得<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual unsigned int GetDeviceCount();
	
	
	/**
	 * @brief アクティブデバイスの、接続デバイス数を取得<br>
	 * 
	 * @param[in] なし.
	 * @return 接続デバイス数.
	 */
	virtual unsigned int GetConnectDeviceCount();
	
	
	/**
	 * @brief 何かしらのキーが押されているか調べる<br>
	 * 
	 * @param[in] なし.
	 * @retval 1以上 押されている.
	 * @retval 0 何も押されていない.
	 */
	virtual bool GetKeyDown();

	
	/**
	 * @brief 指定したキーが押されているか調べる<br>
	 * 
	 * @param[in] key 調べるキー.
	 * @retval true 押されていた.
	 * @retval false 押されていなかった.
	 */
	virtual bool GetKeyDown( unsigned int key );

	
	/**
	 * @brief 押されているキーを調べる<br>
	 * 
	 * @param[in] なし.
	 * @retval 1以上 押されているキー.
	 * @retval 0 何も押されていない.
	 */
	virtual unsigned int GetDownKey();


	/**
	 * @brief 何かしらのキーが離されたか調べる<br>
	 * 
	 * @param[in] なし.
	 * @retval true 離された.
	 * @retval false 離されていない.
	 */
	virtual bool GetKeyRelease();

	
	/**
	 * @brief 指定したキーが離されたか調べる<br>
	 * 
	 * @param[in] key 調べるキー.
	 * @retval true 離された.
	 * @retval false 離されていない.
	 */
	virtual bool GetKeyRelease( unsigned int key );

	
	/**
	 * @brief 離されたキーを調べる<br>
	 * 
	 * @param[in] なし.
	 * @retval 1以上 離されたキー.
	 * @retval 0 離されていない。
	 */
	virtual unsigned int GetReleaseKey();

	
	/**
	 * @brief なにかしらのキーがタイプされたか<br>
	 * 
	 * @param[in] なし.
	 * @retval true タイプされた.
	 : @retval false タイプされていない.
	 */
	virtual bool GetKeyTrigger();

	
	/**
	 * @brief 指定のキーがタイプされたか調べる<br>
	 * 
	 * @param[in] key 調べるキー.
	 * @retval true タイプされた.
	 * @retval false タイプされていない.
	 */
	virtual bool GetKeyTrigger( unsigned int key );

	
	/**
	 * @brief タイプされたキーを取得する<br>
	 * 
	 * @param[in] なし.
	 * @retval 1以上 タイプされたキー.
	 * @retval 0 タイプされていない.
	 */
	virtual unsigned int GetTriggerKey();

	
	/**
	 * @brief 入力を更新する<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void Reload();
	
	
	/**
	 * @brief 終了キーが押されたか<br>
	 * 
	 * @param[in] なし.
	 * @retval true 押された.
	 * @retval false 押されていない.
	 */
	virtual bool IsInputEndKey();

private:

	/**
	 * @brief キーをゲームキーに変換する<br>
	 * 
	 * @param[in] key 変換するジョイスティックキー定数.
	 * @return 変換後のゲームキー.
	 */
	unsigned int ConvertKey( unsigned int key );
	
	/**
	 * @brief ゲームキーから変換する<br>
	 * 
	 * @param[in] key 変換するゲームキー定数.
	 * @return 変換後のキー.
	 */
	unsigned int ConvertGameKey( unsigned int key );
	
	/**
	 * @brief ジョイスティックキーをゲームキーに変換する<br>
	 * 
	 * @param[in] key 変換するジョイスティックキー定数.
	 * @return 変換後のゲームキー.
	 */
	unsigned int ConvertJoystickKey( unsigned int key );


	/**
	 * @brief キーボードキーをゲームキーに変換する<br>
	 * 
	 * @param[in] key 変換するキーボードキー定数.
	 * @return 変換後のゲームキー.
	 */
	unsigned int ConvertKeyboardKey( unsigned int key );

private:

	/**
	 * @brief コピーコンストラクタ( コピー禁止 )<br>
	 * 
	 * @param[in] other コピーするオブジェクト.
	 */
	InputDeviceImpl( const InputDeviceImpl& other );


	/**
	 * @brief = 演算子オーバーロード( コピー禁止 )<br>
	 * 
	 * @param[in] other 代入するオブジェクト.
	 * @return 代入結果のオブジェクト
	 */
	InputDeviceImpl& operator = ( const InputDeviceImpl& other );
	
private:

	/** 入力デバイス管理者 */
	Ngl::InputDeviceManager		inputDeviceManager_;
};

#endif

/*========= End of File =====================================================*/