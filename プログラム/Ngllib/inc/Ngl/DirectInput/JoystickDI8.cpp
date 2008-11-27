/*******************************************************************************/
/**
 * @file JoystickDI8.cpp.
 * 
 * @brief DirectInput ジョイスティッククラスソースファイル.
 *
 * @date 2007/07/26.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"JoystickDI8.h"
#include	<cassert>

namespace{

	/** ジョイスティックキー */
	const static int JOY_NONE		= 0x0000U;				/**< 何も押されていない			*/
	const static int JOY_LEFT 		= 0x8000U;				/**< ジョイスティック軸左		*/
	const static int JOY_RIGHT		= 0x4000U;				/**< ジョイスティック軸右		*/
	const static int JOY_UP			= 0x2000U;				/**< ジョイスティック軸上		*/
	const static int JOY_DOWN		= 0x1000U;				/**< ジョイスティック軸下		*/
	const static int JOY_LEFTDOWN	= JOY_DOWN | JOY_LEFT;	/**< ジョイスティック左斜め下	*/
	const static int JOY_RIGHTDOWN	= JOY_DOWN | JOY_RIGHT;	/**< ジョイスティック右斜め下	*/
	const static int JOY_LEFTUP		= JOY_UP   | JOY_LEFT;	/**< ジョイスティック左斜め上	*/
	const static int JOY_RIGHTUP	= JOY_UP   | JOY_RIGHT;	/**< ジョイスティック左斜め下	*/
	const static int JOY_BUTTON_1	= 0x0001U;				/**< ジョイスティックボタン1	*/
	const static int JOY_BUTTON_2	= 0x0002U;				/**< ジョイスティックボタン2	*/
	const static int JOY_BUTTON_3	= 0x0004U;				/**< ジョイスティックボタン3	*/
	const static int JOY_BUTTON_4	= 0x0008U;				/**< ジョイスティックボタン4	*/
	const static int JOY_BUTTON_5	= 0x0010U;				/**< ジョイスティックボタン5	*/
	const static int JOY_BUTTON_6	= 0x0020U;				/**< ジョイスティックボタン6	*/
	const static int JOY_BUTTON_7	= 0x0040U;				/**< ジョイスティックボタン7	*/
	const static int JOY_BUTTON_8	= 0x0080U;				/**< ジョイスティックボタン8	*/
	const static int JOY_BUTTON_9	= 0x0100U;				/**< ジョイスティックボタン9	*/
	const static int JOY_BUTTON_10	= 0x0200U;				/**< ジョイスティックボタン10	*/

	/** 変換キー配列 */
	static const unsigned int joystickKey[] = {
		JOY_NONE,		/**< 0  何も押されていない			*/
		JOY_LEFT,		/**< 1  ジョイスティック軸左		*/
		JOY_RIGHT,		/**< 2  ジョイスティック軸右		*/
		JOY_UP,			/**< 3  ジョイスティック軸上		*/
		JOY_DOWN,		/**< 4  ジョイスティック軸下		*/
		JOY_LEFTDOWN,	/**< 5  ジョイスティック左斜め下	*/
		JOY_RIGHTDOWN,	/**< 6  ジョイスティック右斜め下	*/
		JOY_LEFTUP,		/**< 7  ジョイスティック左斜め上	*/
		JOY_RIGHTUP,	/**< 8  ジョイスティック左斜め下	*/
		JOY_BUTTON_1,	/**< 9  ジョイスティックボタン1		*/
		JOY_BUTTON_2,	/**< 10 ジョイスティックボタン2		*/
		JOY_BUTTON_3,	/**< 11 ジョイスティックボタン3		*/
		JOY_BUTTON_4,	/**< 12 ジョイスティックボタン4		*/
		JOY_BUTTON_5,	/**< 13 ジョイスティックボタン5		*/
		JOY_BUTTON_6,	/**< 14 ジョイスティックボタン6		*/
		JOY_BUTTON_7,	/**< 15 ジョイスティックボタン7		*/
		JOY_BUTTON_8,	/**< 16 ジョイスティックボタン8		*/
		JOY_BUTTON_9,	/**< 17 ジョイスティックボタン9		*/
		JOY_BUTTON_10	/**< 18 ジョイスティックボタン10	*/
	};

	/** 判定する斜めキーリスト */
	static const unsigned int diagonalKeyList[] = {
		5, 6, 7, 8
	};
}

using namespace Ngl;
using namespace Ngl::DirectInput;


/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
JoystickDI8::JoystickDI8():
	padDevice_( NULL ),
	oldBuf_( 0 ),
	newBuf_( 0 )
{
	for( int i=0; i<2; ++i ){
		state_[i] = 0;
	}
}



/*===========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
JoystickDI8::~JoystickDI8()
{
	// 解放する
	release();
}



/*===========================================================================*/
/**
 * @brief デバイスを作成する
 * 
 * @param[in] di インプットデバイス.
 * @param[in] inst インスタンス.
 * @param[in] hwnd ウィンドウハンドル.
 * @retval true 取得成功.
 * @retval false 取得失敗.
 */
bool JoystickDI8::create(LPDIRECTINPUT8 di, LPCDIDEVICEINSTANCE inst, HWND hwnd)
{
	HRESULT hr = DI_OK; // 実行結果

	// 「DirectInputデバイス」オブジェクトの作成
    hr = di->CreateDevice( inst->guidInstance, &padDevice_, 0 );
	assert( hr == DI_OK );

	// バッファを確保
	ZeroMemory( state_, sizeof( state_ ) );
	newBuf_ = &state_[0];
	oldBuf_ = &state_[1];

	// データフォーマットの設定
	hr = padDevice_->SetDataFormat( &c_dfDIJoystick2 );
	assert( hr == DI_OK );

	// 強調レベルの設定
	hr = padDevice_->SetCooperativeLevel( hwnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND );
	assert( hr == DI_OK );
	
	// ジョイスティックのＸ軸の設定
	DIPROPRANGE	prop;
	prop.diph.dwSize		= sizeof( prop );
	prop.diph.dwHeaderSize	= sizeof( prop.diph );
	prop.diph.dwObj			= DIJOFS_X;
	prop.diph.dwHow			= DIPH_BYOFFSET;
	prop.lMin				= -1000;
	prop.lMax				= +1000;
	hr = padDevice_->SetProperty( DIPROP_RANGE, &prop.diph );
	assert( hr == DI_OK );

	// ジョイスティックのＹ軸の設定
	prop.diph.dwObj			= DIJOFS_Y;
	hr = padDevice_->SetProperty( DIPROP_RANGE, &prop.diph );
	assert( hr == DI_OK );
	
	// x軸の無効ソーンの設定
	hr = setDevProperty( DIPROP_DEADZONE, DIJOFS_X, DIPH_BYOFFSET, 5000 );
	assert( hr == DI_OK );

	// y軸の無効ゾーンの設定
	hr = setDevProperty( DIPROP_DEADZONE, DIJOFS_Y, DIPH_BYOFFSET, 5000 );
	assert( hr == DI_OK );

	// アクセス権の取得を行う
	getReacquire();

	// 作成成功
    return true;
}



/*===========================================================================*/
/**
 * @brief 状態を読み込む
 * 
 * @param[in] なし.
 * @retval true 成功.
 : @retval false 失敗.
 */
bool JoystickDI8::loadKeyState()
{
	// デバイスが作成できていないか
	assert( padDevice_ != NULL );

	// ジョイスティックにポーリングの指示を出す
	padDevice_->Poll();

	// ジョイスティックデーターの読み込み
	DIJOYSTATE2 js;
	HRESULT hr = padDevice_->GetDeviceState( sizeof( js ), &js );

	// 読み込めなかったか
	if( hr != DI_OK ){
		// 指定のエラーか
		if( ( hr == DIERR_INPUTLOST ) || ( hr == DIERR_NOTACQUIRED ) ){
			// アクセス権を再取得する
			getReacquire();
		}

		return false;
	}

	int joy_state = 0;	// 入力状態変数

	// 方向キーのチェック
	if ( js.lX < 0 ) 
	{
		// 左が押された
		joy_state |= JOY_LEFT;
	}
	else if ( js.lX > 0 )
	{
		// 右が押された
		joy_state |= JOY_RIGHT;
	}
	if ( js.lY < 0 )
	{
		// 上が押された
		joy_state |= JOY_UP;
	}
	else if ( js.lY > 0 )
	{
		// 下が押された
		joy_state |= JOY_DOWN;
	}

	// ボタンのチェック
	int bmask = JOY_BUTTON_1;
	for ( int i = 0; i < BUTTON_MAX; i++ )
	{
		if ( ( js.rgbButtons[i] & 0x80 ) != 0 )
		{
			joy_state |= bmask;
		}
		bmask <<= 1;
	}

	// バッファの入れ替え
	int* tmp	= newBuf_;
	newBuf_		= oldBuf_;
	oldBuf_		= tmp;

	// 状態を保存する
	*newBuf_ = joy_state;

	return true;
}



/*===========================================================================*/
/**
 * @brief 軸の状態を読み込む
 * 
 * @param[in] なし.
 * @return 各軸の状態ベクトル.
 */
Vector3 JoystickDI8::readAxisState()
{
	// ジョイスティクにポーリングの指示を出す
	padDevice_->Poll();

	// ジョイスティックのデータを読み込む
	DIJOYSTATE js;
	HRESULT hr = padDevice_->GetDeviceState( sizeof( DIJOYSTATE ), &js );

	// 正しく読み込めなかったか
	if( hr != DI_OK ){
		if( ( hr == DIERR_INPUTLOST ) || ( hr == DIERR_NOTACQUIRED ) ){
			// アクセス権を再取得する
			getReacquire();

			return Vector3( 0.0f, 0.0f, 0.0f );
		}
	}

	// 軸の状態を取得する
	Vector3 tmp;
	tmp.x = static_cast<float>(js.lX);
	tmp.y = static_cast<float>(js.lY);
	tmp.z = static_cast<float>(js.lZ);

	// 作成したベクトルを返す
	return tmp;
}



/*=========================================================================*/
/**
 * @brief 何かしらのキーが押されているか調べる
 * 
 * @param[in] なし.
 * @retval 1以上 押されている.
 * @retval 0 何も押されていない.
 */
bool JoystickDI8::getKeyDown()
{
	// 入力されているか調べる
	for( int i=0; i<JOYSTICKKEY_MAX; i++ ){
		if( getKeyDown( i ) == true ){
			// 入力されていた
			return true;
		}
	}
	// 何も入力されていなかった
	return false;
}



/*=========================================================================*/
/**
 * @brief 指定したキーが押されているか調べる
 * 
 * @param[in] key 調べるキー.
 * @retval true 押されていた.
 * @retval false 押されていなかった.
 */
bool JoystickDI8::getKeyDown( unsigned int key )
{
	// キーを変換する
	int conKey = convertKey( key );

	// 斜めキーか調べる
	bool isDia = false;
	for( int i=0; i<DIAGONALCROSSKEY_MAX; i++ ){
		if( key == diagonalKeyList[i] ){
			isDia = true;
		}
	}

	// 斜めキー判定
	for( int i=0; i<DIAGONALCROSSKEY_MAX; i++ ){
		if( isDia == true && judgementDiagonalKey( *newBuf_ ) == conKey ){
			return true;
		}
	}

	// ほかのキー判定
	if( isDia == false && ( *newBuf_ & conKey ) != 0 ){
		// 押されていた
		return true;
	}

	// 押されていない
	return false;
}



/*=========================================================================*/
/**
 * @brief 押されているキーを調べる
 * 
 * @param[in] なし.
 * @retval 1以上 押されているキー.
 * @retval 0 何も押されていない.
 */
unsigned int JoystickDI8::getDownKey()
{
	// 入力されているか調べる
	for( int i=0; i<JOYSTICKKEY_MAX; i++ ){
		if( getKeyDown( i ) == true ){
			// 入力を返す
			return i;
		}
	}
	// 何も入力されていなかった
	return 0;
}



/*=========================================================================*/
/**
 * @brief 何かしらのキーが離されたか調べる
 * 
 * @param[in] なし.
 * @retval true 離された.
 * @retval false 離されていない.
 */
bool JoystickDI8::getKeyRelease()
{
	// 入力されているか調べる
	for( int i=0; i<JOYSTICKKEY_MAX; i++ ){
		if( getKeyRelease( i ) == true ){
			// 入力されていた
			return true;
		}
	}
	// 何も入力されていなかった
	return false;
}



/*=========================================================================*/
/**
 * @brief 指定したキーが離されたか調べる
 * 
 * @param[in] key 調べるキー.
 * @retval true 離された.
 * @retval false 離されていない.
 */
bool JoystickDI8::getKeyRelease( unsigned int key )
{
	int conKey = convertKey( key );

	// 斜めキーか調べる
	bool isDia = false;
	for( int i=0; i<DIAGONALCROSSKEY_MAX; i++ ){
		if( key == diagonalKeyList[i] ){
			isDia = true;
		}
	}

	// 判定バッファを作成
	int tmp = *oldBuf_ & ~*newBuf_;

	// 斜めキー判定
	for( int i=0; i<DIAGONALCROSSKEY_MAX; i++ ){
		if( isDia == true && judgementDiagonalKey( tmp ) == conKey ){
			return true;
		}
	}

	// ほかのキー判定
	if( isDia == false && ( tmp & conKey ) != 0 ){
		// 離されていた
		return true;
	}
	// 離されていない
	return false;
}



/*=========================================================================*/
/**
 * @brief 離されたキーを調べる
 * 
 * @param[in] なし.
 * @retval 1以上 離されたキー.
 * @retval 0 離されていない。
 */
unsigned int JoystickDI8::getReleaseKey()
{
	// 入力されているか調べる
	for( int i=0; i<JOYSTICKKEY_MAX; i++ ){
		if( getKeyRelease( i ) == true ){
			// 入力を返す
			return i;
		}
	}
	// 何も入力されていなかった
	return 0;
}



/*=========================================================================*/
/**
 * @brief なにかしらのキーがタイプされたか
 * 
 * @param[in] なし.
 * @retval true タイプされた.
 : @retval false タイプされていない.
 */
bool JoystickDI8::getKeyTrigger()
{
	// 入力されているか調べる
	for( int i=0; i<JOYSTICKKEY_MAX; i++ ){
		if( getKeyTrigger( i ) == true ){
			// 入力されていた
			return true;
		}
	}
	// 何も入力されていなかった
	return false;
}



/*=========================================================================*/
/**
 * @brief 指定のキーがタイプされたか調べる
 * 
 * @param[in] key 調べるキー.
 * @retval true タイプされた.
 * @retval false タイプされていない.
 */
bool JoystickDI8::getKeyTrigger( unsigned int key )
{
	int conKey = convertKey( key );

	// 斜めキーか調べる
	bool isDia = false;
	for( int i=0; i<DIAGONALCROSSKEY_MAX; i++ ){
		if( key == diagonalKeyList[i] ){
			isDia = true;
		}
	}

	// 判定バッファを作成
	int tmp = ~*oldBuf_ & *newBuf_;

	// 斜めキー判定
	for( int i=0; i<DIAGONALCROSSKEY_MAX; i++ ){
		if( isDia == true && judgementDiagonalKey( tmp ) == conKey ){
			return true;
		}
	}
	
	// その他のキー判定
	if( isDia == false && ( tmp & conKey ) != 0 ){
		// タイプされていた
		return true;
	}
	// タイプされていない
	return false;
}



/*=========================================================================*/
/**
 * @brief タイプされたキーを取得する
 * 
 * @param[in] なし.
 * @retval 1以上 タイプされたキー.
 * @retval 0 タイプされていない.
 */
unsigned int JoystickDI8::getTriggerKey()
{	
	// 入力されているか調べる
	for( int i=0; i<JOYSTICKKEY_MAX; i++ ){
		if( getKeyTrigger( i ) == true ){
			// 入力を返す
			return i;
		}
	}
	// 何も入力されていなかった
	return 0;
}



/*===========================================================================*/
/**
 * @brief アクセス権の再取得
 * 
 * @param[in] なし.
 * @retval true 取得成功.
 * @retval false 取得失敗.
 */
bool JoystickDI8::getReacquire()
{
	HRESULT hr = DI_OK;	// 結果

	if( padDevice_ != 0 ){
		// DirectXジョイスティックデバイスのサクセス権を取得する
		hr = padDevice_->Acquire();

		// 成功したか
		if( hr == DI_OK ){
			// 取得に成功した
			return true;
		}
		// 取得に失敗した
		else{
			if( hr == DIERR_NOTINITIALIZED ){
				MessageBoxA( 0, "Device is not initialized", 0, MB_OK );
			}
			return false;
		}
	}
	// 取得失敗
	return false;
}



/*===========================================================================*/
/**
 * @brief ジョイスティックデバイスを解放する
 * 
 * @param[in] なし.
 * @return なし.
 */
void JoystickDI8::release()
{
	// デバイスが設定されているか
	if( padDevice_ != 0 ){
		// アクセスから解放する
		padDevice_->Unacquire();

		// デバイスを解放する
		padDevice_->Release();

		padDevice_ = 0;
	}
}



/*===========================================================================*/
/**
 * @brief プロパティの設定
 * 
 * @param[in] guid 設定対象の識別子.
 * @param[in] obj 設定する項目.
 * @param[in] how 設定値の方法.
 * @param[in] val 設定値.
 * @return 結果.
 */
HRESULT JoystickDI8::setDevProperty( REFGUID guid, DWORD obj, DWORD how, DWORD val )
{
	DIPROPDWORD dipdw;
	dipdw.diph.dwSize		= sizeof( dipdw );
	dipdw.diph.dwHeaderSize	= sizeof( dipdw.diph );
	dipdw.diph.dwObj		= obj;
	dipdw.diph.dwHow		= how;
	dipdw.dwData			= val;

	return padDevice_->SetProperty( guid, &dipdw.diph );
}



/*=========================================================================*/
/**
 * @brief 斜め入力判定
 * 
 * @param[in] buf 判定するバッファ.
 * @return 押されていたキー.
 */
int JoystickDI8::judgementDiagonalKey( int buf )
{
	// 左斜め上が押されているか
	if( JOY_LEFT & buf && JOY_UP & buf ){
		return JOY_LEFTUP;
	}

	// 左斜め下が押されているか
	if( JOY_LEFT & buf && JOY_DOWN & buf ){
		return JOY_LEFTDOWN;
	}

	// 右斜め上が押されているか
	if( JOY_RIGHT & buf && JOY_UP & buf ){
		return JOY_RIGHTUP;
	}

	// 右斜め下が押されているか
	if( JOY_RIGHT & buf && JOY_DOWN & buf ){
		return JOY_RIGHTDOWN;
	}

	// 斜めは押されていなかった
	return 0;
}

	
	
/*=========================================================================*/
/**
 * @brief 入力されたキーを変換する
 * 
 * @param[in] key 変換するキー.
 * @return 変換後のキー.
 */
unsigned int JoystickDI8::convertKey( unsigned int key )
{
	// 最大数を超えているか
	if( key >= JOYSTICKKEYDI8_COUNT ){
		return 0;
	}

	return joystickKey[ key ];
}

	
	
/*========= EOF =============================================================*/