/*******************************************************************************/
/**
 * @file InputDeviceImpl.cpp.<br>
 * 
 * @brief 入力デバイス実装クラスソースファイル.<br>
 *
 * @date 2008/07/20.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"InputDeviceImpl.h"
#include	<Ngl/DirectInput/KeyboardDeviceDI8.h>
#include	<Ngl/DirectInput/JoystickDeviceDI8.h>
#include	<Ngl/DirectInput/JoystickKeyDI8.h>
#include	<Ngl/DirectInput/KeyboardKeyDI8.h>
#include	<Ngl/DirectInput/MouseKeyDI8.h>

namespace{
	static const InputDeviceID inputDeviceIDArray[] = {
		INPUTDEVICEID_KEYBOARD,
		INPUTDEVICEID_JOYSTICK
	};

	static const unsigned int joykeys[] = {
		Ngl::DirectInput::JOYSTICKKEYDI8_NONE,		//  GAMEKEY_NONE,		/**<	入力なし	*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_UP,		//  GAMEKEY_UP,			/**<	上			*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_DOWN,		//  GAMEKEY_DOWN,		/**<	下			*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_RIGHT,		//  GAMEKEY_LEFT,		/**<	左			*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_LEFT,		//  GAMEKEY_RIGHT,		/**<	右			*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_LEFTUP,	//  GAMEKEY_LEFTUP,		/**<	左上		*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_RIGHTUP,	//  GAMEKEY_RIGHTUP,	/**<	右上		*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_LEFTDOWN,	//  GAMEKEY_LEFTDOWN,	/**<	左下		*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_RIGHTDOWN,	//  GAMEKEY_RIGHTDOWN,	/**<	右下		*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_BUTTON_1,	//  GAMEKEY_CANNCEL,	/**<	ボタン１	*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_BUTTON_2,	//  GAMEKEY_CIRCLE,		/**<	ボタン２	*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_BUTTON_3,	//  GAMEKEY_TRIANGLE,	/**<	ボタン３	*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_BUTTON_4,	//  GAMEKEY_QUAD,		/**<	ボタン４	*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_BUTTON_5,	//  GAMEKEY_L1,			/**<	ボタン５	*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_BUTTON_6,	//  GAMEKEY_L2,			/**<	ボタン６	*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_BUTTON_7,	//  GAMEKEY_R1,			/**<	ボタン７	*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_BUTTON_8,	//  GAMEKEY_R2,			/**<	ボタン８	*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_BUTTON_9,	//  GAMEKEY_START,		/**<	ボタン９	*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_BUTTON_10	//  GAMEKEY_SELECT,		/**<	ボタン１０	*/ 
	};

	static const unsigned int keyboardkey[] = {
		Ngl::DirectInput::KEYBOARDKEYDI8_NONE,	// GAMEKEY_NONE,		/**<	入力なし	*/
		Ngl::DirectInput::KEYBOARDKEYDI8_UP,	// GAMEKEY_UP,			/**<	上			*/
		Ngl::DirectInput::KEYBOARDKEYDI8_DOWN,	// GAMEKEY_DOWN,		/**<	下			*/
		Ngl::DirectInput::KEYBOARDKEYDI8_RIGHT,	// GAMEKEY_LEFT,		/**<	左			*/
		Ngl::DirectInput::KEYBOARDKEYDI8_LEFT,	// GAMEKEY_RIGHT,		/**<	右			*/
		Ngl::DirectInput::KEYBOARDKEYDI8_LEFT,	// GAMEKEY_LEFTUP,		/**<	左上		*/
		Ngl::DirectInput::KEYBOARDKEYDI8_RIGHT,	// GAMEKEY_RIGHTUP,		/**<	右上		*/
		Ngl::DirectInput::KEYBOARDKEYDI8_LEFT,	// GAMEKEY_LEFTDOWN,	/**<	左下		*/
		Ngl::DirectInput::KEYBOARDKEYDI8_RIGHT,	// GAMEKEY_RIGHTDOWN,	/**<	右下		*/
		Ngl::DirectInput::KEYBOARDKEYDI8_A,		// GAMEKEY_CANNCEL,		/**<	ボタン１	*/
		Ngl::DirectInput::KEYBOARDKEYDI8_S,		// GAMEKEY_CIRCLE,		/**<	ボタン２	*/
		Ngl::DirectInput::KEYBOARDKEYDI8_D,		// GAMEKEY_TRIANGLE,	/**<	ボタン３	*/
		Ngl::DirectInput::KEYBOARDKEYDI8_F,		// GAMEKEY_QUAD,		/**<	ボタン４	*/
		Ngl::DirectInput::KEYBOARDKEYDI8_Z,		// GAMEKEY_L1,			/**<	ボタン５	*/
		Ngl::DirectInput::KEYBOARDKEYDI8_X,		// GAMEKEY_L2,			/**<	ボタン６	*/
		Ngl::DirectInput::KEYBOARDKEYDI8_C,		// GAMEKEY_R1,			/**<	ボタン７	*/
		Ngl::DirectInput::KEYBOARDKEYDI8_V,		// GAMEKEY_R2,			/**<	ボタン８	*/
		Ngl::DirectInput::KEYBOARDKEYDI8_J,		// GAMEKEY_START,		/**<	ボタン９	*/
		Ngl::DirectInput::KEYBOARDKEYDI8_K		// GAMEKEY_SELECT,		/**<	ボタン１０	*/
	};
}

using namespace Ngl;
using namespace Ngl::DirectInput;

/**
 * purpose : コンストラクタ.
 *
 * param[in] なし.
 */
InputDeviceImpl::InputDeviceImpl()
{}



/**
 * purpose : デストラクタ.
 *
 * param[in] なし.
 */
InputDeviceImpl::~InputDeviceImpl()
{
	inputDeviceManager_.clear();
}



/**
 * purpose : 作成処理<br>
 * 
 * @param[in] hwnd ウィンドウハンドル.
 * @return なし.
 */
void InputDeviceImpl::Create( HWND hwnd )
{
	// 各種入力デバイスを作成
	KeyboardDeviceDI8* key = new KeyboardDeviceDI8();
	key->create( hwnd );

	JoystickDeviceDI8* joy = new JoystickDeviceDI8();
	joy->create( hwnd );

	inputDeviceManager_.regist( INPUTDEVICEID_KEYBOARD, key	);
	inputDeviceManager_.regist( INPUTDEVICEID_JOYSTICK,	joy	);
}



/**
 * purpose : 終了処理<br>
 * 
 * @param[in] なし.
 * @return なし.
 */
void InputDeviceImpl::End()
{
	inputDeviceManager_.clear();
}

	


/**
 * purpose : アクティブのデバイスを変更する<br>
 * 
 * @param[in] connectID アクティブにするデバイスの、変更する接続デバイス番号.
 * @return なし.
 */
void InputDeviceImpl::ChangeActiveDevice( unsigned int connectID )
{
	// 接続デバイスを変更
	inputDeviceManager_.setActiveDevice( INPUTDEVICEID_JOYSTICK );
	inputDeviceManager_.changeActiveConnectDevice( connectID );
}



/**
 * purpose : アクティブの入力デバイスを取得する<br>
 * 
 * @param[in] なし.
 * @return アクティブデバイス番号.
 */
unsigned int InputDeviceImpl::GetActiveInputDeviceNo()
{
	return inputDeviceManager_.getActiveDeviceNo();
}



/**
 * purpose : アクティブの入力デバイスのアクティブな接続デバイス番号を取得<br>
 * 
 * @param[in] なし.
 * @return アクティブの入力デバイスのアクティブな接続デバイス番号.
 */
unsigned int InputDeviceImpl::GetActiveConnectDeviceNo()
{
	return inputDeviceManager_.getActiveConnectDeviceNo();
}



/**
 * purpose : 入力デバイス数を取得<br>
 * 
 * @param[in] なし.
 * @return なし.
 */
unsigned int InputDeviceImpl::GetDeviceCount()
{
	return inputDeviceManager_.getDeviceCount();
}



/**
 * purpose : アクティブデバイスの、接続デバイス数を取得<br>
 * 
 * @param[in] なし.
 * @return 接続デバイス数.
 */
unsigned int InputDeviceImpl::GetConnectDeviceCount()
{
	return inputDeviceManager_.getConnectDeviceCount();
}



/**
 * purpose : 何かしらのキーが押されているか調べる<br>
 * 
 * @param[in] なし.
 * @retval 1以上 押されている.
 * @retval 0 何も押されていない.
 */
bool InputDeviceImpl::GetKeyDown()
{
	for( int i=0; i<2; i++ ){
		inputDeviceManager_.setActiveDevice( inputDeviceIDArray[ i ] );
		bool result = inputDeviceManager_.getKeyDown();
		if( result == true ){
			return true;
		}
	}
	return false;
}



/**
 * purpose : 指定したキーが押されているか調べる<br>
 * 
 * @param[in] key 調べるキー.
 * @retval true 押されていた.
 * @retval false 押されていなかった.
 */
bool InputDeviceImpl::GetKeyDown( unsigned int key )
{
	for( int i=0; i<2; i++ ){
		inputDeviceManager_.setActiveDevice( inputDeviceIDArray[ i ] );
		bool result = inputDeviceManager_.getKeyDown( ConvertGameKey( key ) );
		if( result == true ){
			return true;
		}
	}
	return false;
}



/**
 * purpose : 押されているキーを調べる<br>
 * 
 * @param[in] なし.
 * @retval 1以上 押されているキー.
 * @retval 0 何も押されていない.
 */
unsigned int InputDeviceImpl::GetDownKey()
{
	for( int i=0; i<2; i++ ){
		inputDeviceManager_.setActiveDevice( inputDeviceIDArray[ i ] );
		unsigned int key = ConvertKey( inputDeviceManager_.getDownKey() );
		if( key != GAMEKEY_NONE ){
			return key;
		}
	}
	return GAMEKEY_NONE;
}



/**
 * purpose : 何かしらのキーが離されたか調べる<br>
 * 
 * @param[in] なし.
 * @retval true 離された.
 * @retval false 離されていない.
 */
bool InputDeviceImpl::GetKeyRelease()
{
	for( int i=0; i<2; i++ ){
		inputDeviceManager_.setActiveDevice( inputDeviceIDArray[ i ] );
		bool result = inputDeviceManager_.getKeyRelease();
		if( result == true ){
			return true;
		}
	}
	return false;
}



/**
 * purpose : 指定したキーが離されたか調べる<br>
 * 
 * @param[in] key 調べるキー.
 * @retval true 離された.
 * @retval false 離されていない.
 */
bool InputDeviceImpl::GetKeyRelease( unsigned int key )
{
	for( int i=0; i<2; i++ ){
		inputDeviceManager_.setActiveDevice( inputDeviceIDArray[ i ] );
		bool result = inputDeviceManager_.getKeyRelease( ConvertGameKey( key ) );
		if( result == true ){
			return true;
		}
	}
	return false;
}



/**
 * purpose : 離されたキーを調べる<br>
 * 
 * @param[in] なし.
 * @retval 1以上 離されたキー.
 * @retval 0 離されていない。
 */
unsigned int InputDeviceImpl::GetReleaseKey()
{
	for( int i=0; i<2; i++ ){
		inputDeviceManager_.setActiveDevice( inputDeviceIDArray[ i ] );
		unsigned int key = ConvertKey( inputDeviceManager_.getReleaseKey() );
		if( key != GAMEKEY_NONE ){
			return key;
		}
	}
	return GAMEKEY_NONE;
}



/**
 * purpose : なにかしらのキーがタイプされたか<br>
 * 
 * @param[in] なし.
 * @retval true タイプされた.
 : @retval false タイプされていない.
 */
bool InputDeviceImpl::GetKeyTrigger()
{
	for( int i=0; i<2; i++ ){
		inputDeviceManager_.setActiveDevice( inputDeviceIDArray[ i ] );
		bool result = inputDeviceManager_.getKeyTrigger();
		if( result == true ){
			return true;
		}
	}
	return false;
}



/**
 * purpose : 指定のキーがタイプされたか調べる<br>
 * 
 * @param[in] key 調べるキー.
 * @retval true タイプされた.
 * @retval false タイプされていない.
 */
bool InputDeviceImpl::GetKeyTrigger( unsigned int key )
{
	for( int i=0; i<2; i++ ){
		inputDeviceManager_.setActiveDevice( inputDeviceIDArray[ i ] );
		bool result = inputDeviceManager_.getKeyTrigger( ConvertGameKey( key ) );
		if( result == true ){
			return true;
		}
	}
	return false;
}



/**
 * purpose : タイプされたキーを取得する<br>
 * 
 * @param[in] なし.
 * @retval 1以上 タイプされたキー.
 * @retval 0 タイプされていない.
 */
unsigned int InputDeviceImpl::GetTriggerKey()
{
	for( int i=0; i<2; i++ ){
		inputDeviceManager_.setActiveDevice( inputDeviceIDArray[ i ] );
		unsigned int key = ConvertKey( inputDeviceManager_.getTriggerKey() );
		if( key != GAMEKEY_NONE ){
			return key;
		}
	}
	return GAMEKEY_NONE;
}



/**
 * purpose : 入力を更新する<br>
 * 
 * @param[in] なし.
 * @return なし.
 */
void InputDeviceImpl::Reload()
{
	inputDeviceManager_.loadKeyState();	
}



/**
 * purpose : 終了キーが押されたか<br>
 * 
 * @param[in] なし.
 * @retval true 押された.
 * @retval false 押されていない.
 */
bool InputDeviceImpl::IsInputEndKey()
{
	// 入力デバイスをジョイパッドに設定
	int active = inputDeviceManager_.getActiveDeviceNo();
	inputDeviceManager_.setActiveDevice( INPUTDEVICEID_JOYSTICK );

	// パッドの9番ボタンと10番ボタンが同時押しされているか
	bool result = false;
	if( inputDeviceManager_.getKeyDown( JOYSTICKKEYDI8_BUTTON_10 ) == true ){
		if( inputDeviceManager_.getKeyDown( JOYSTICKKEYDI8_BUTTON_9 ) == true ){
			result = true;
		}
	}

	// 入力デバイスをアクティブに戻す
	inputDeviceManager_.setActiveDevice( active );

	// 結果を返す
	return result;
}



/**
 * purpose : キーをゲームキーに変換する<br>
 * 
 * @param[in] key 変換するジョイスティックキー定数.
 * @return 変換後のゲームキー.
 */
unsigned int InputDeviceImpl::ConvertKey( unsigned int key )
{
	if( GetActiveInputDeviceNo() == INPUTDEVICEID_KEYBOARD ){
		return ConvertKeyboardKey( key );
	}
	else{
		return ConvertJoystickKey( key );
	}
}


	
/**
 * purpose : ゲームキーから変換する<br>
 * 
 * @param[in] key 変換するゲームキー定数.
 * @return 変換後のキー.
 */
unsigned int InputDeviceImpl::ConvertGameKey( unsigned int key )
{
	if( GetActiveInputDeviceNo() == INPUTDEVICEID_KEYBOARD ){
		return keyboardkey[ key ];
	}
	else{
		return joykeys[ key ];
	}
}

	
	
/**
 * purpose : ジョイスティックキーをゲームキーを変換する<br>
 * 
 * @param[in] key 変換するジョイスティックキー定数.
 * @return 変換後のゲームキー.
 */
unsigned int InputDeviceImpl::ConvertJoystickKey( unsigned int key )
{
	

	for( int i=0; i<GAMEKEY_COUNT; ++i ){
		if( joykeys[ i ] == key ){
			return i;
		}
	}

	return GAMEKEY_NONE;
}

	
	
/**
 * purpose : キーボードキーをゲームキーに変換する<br>
 * 
 * @param[in] key 変換するキーボードキー定数.
 * @return 変換後のゲームキー.
 */
unsigned int InputDeviceImpl::ConvertKeyboardKey( unsigned int key )
{
	for( int i=1; i<GAMEKEY_COUNT; ++i ){
		if( keyboardkey[ i ] == key ){
			return i;
		}
	}

	return GAMEKEY_NONE;
}

	
	
/*========= End of File =====================================================*/