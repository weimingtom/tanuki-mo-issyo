/*******************************************************************************/
/**
 * @file MouseDeviceDI8.cpp.
 * 
 * @brief DirectInput マウス入力デバイスクラスソースファイル.
 *
 * @date 2007/06/23.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"MouseDeviceDI8.h"
#include	<cassert>

namespace {

	/** マウスのボタン定数 */
	const static int MOUSEBUTTON_NONE	= 0x0000U;	/**< 何も押されていない	*/
	const static int MOUSEBUTTON_1		= 0x0001U;	/**< 左ボタン			*/
	const static int MOUSEBUTTON_2		= 0x0002U;	/**< 右ボタン			*/
	const static int MOUSEBUTTON_3		= 0x0004U;	/**< ホイール			*/
	const static int MOUSEBUTTON_4		= 0x0008U;	/**< 拡張ボタン1		*/

	/** @brief 変換キー配列 */
	static const unsigned int mouseKeys[] = {
		MOUSEBUTTON_NONE,	/**< 0 何も押されていない	*/
		MOUSEBUTTON_1,		/**< 1 左ボタン				*/
		MOUSEBUTTON_2,		/**< 2 右ボタン				*/
		MOUSEBUTTON_3,		/**< 3 ホイール				*/
		MOUSEBUTTON_4		/**< 4 拡張ボタン1			*/
	};

	/** マウスキー総数 */
	static const unsigned int MOUSEKEY_COUNT = sizeof( mouseKeys ) / sizeof( unsigned int );

}

using namespace Ngl;
using namespace Ngl::DirectInput;

/*==== 定数宣言 =============================================================*/

const float MouseDeviceDI8::RATIO_DEFAULT = 1.0f;	// デフォルトのマウス移動比率


/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
MouseDeviceDI8::MouseDeviceDI8() :
	inputDevice_( 0 ),			// Directインプットデバイス
	mouseDevice_( 0 ),			// Mouseインプットデバイス
	nowBtn_( 0 ),				// 今のマウスの状態
	oldBtn_( 0 ),				// 前のマウスの状態
	clip_( 0, 0, 640, 480 ),	// マウスの移動可能範囲
	ratio_( RATIO_DEFAULT )		// マウスの移動比率
{}



/*===========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
MouseDeviceDI8::~MouseDeviceDI8()
{
	release();
}



/*===========================================================================*/
/**
 * @brief マウス入力デバイスの作成
 * 
 * @param[in] hwnd ウィンドウハンドル.
 * @retval true 作成成功.
 * @retval false 作成失敗.
 */
bool MouseDeviceDI8::create(HWND hwnd)
{
	HRESULT hr = DI_OK;	// 実行結果
	
	// DirectInputオブジェクトの作成
	hr = DirectInput8Create( GetModuleHandle( 0 ), DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&inputDevice_, 0 );
	assert( hr == DI_OK );
	
	// DiRectInputDeviceオブジェクトの作成
	hr = inputDevice_->CreateDevice( GUID_SysMouse, &mouseDevice_, NULL );
	assert( hr == DI_OK );

	// デバイスをマウスに設定
	hr = mouseDevice_->SetDataFormat( &c_dfDIMouse2 );
	assert( hr == DI_OK );
	 
	// 協調レベルの設定
	hr = mouseDevice_->SetCooperativeLevel( hwnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND );
	assert( hr == DI_OK );
	 
	// アクセス権を取得する
	 mouseDevice_->Acquire();

	return true;
}




/*=========================================================================*/
/**
 * @brief キー情報を読み込む
 * 
 * @param[in] なし.
 * @retval true 取得成功.
 * @retval false 取得失敗.
 */
bool MouseDeviceDI8::loadKeyState()
{
	// マウス情報の読み取り
	readMouseData();

	// 移動量を計算して座標を設定する
	position_.x += ( ltm_.x * ratio_ );
	position_.y += ( ltm_.y * ratio_ );
	position_.z += ( ltm_.z * ratio_ );

	// マウス位置をクリッピング
	clipMouseCursor();

	return true;
}



/*=========================================================================*/
/**
 * @brief 軸の状態を読み込む
 * 
 * @param[in] なし.
 * @return 各軸の状態ベクトル.
 */
Vector3 MouseDeviceDI8::readAxisState()
{
	// マウスカーソルの位置座標を返す
	return getMouseCursorPosition();
}



/*=========================================================================*/
/**
 * @brief 接続デバイス数を取得
 * 
 * @param[in] なし.
 * @return 接続デバイス数.
 */
unsigned int MouseDeviceDI8::getConnectDeviceCount()
{
	// 1つしか接続がないので、常に1を返す.
	return 1;
}



/*=========================================================================*/
/**
 * @brief アクティブにするデバイスを変更する
 * 
 * @param[in] no 変更するデバイス番号.
 * @return なし.
 */
void MouseDeviceDI8::setActiveDevice( unsigned int no )
{
	// デバイスが1つなので、変更処理をしない.
}



/*=========================================================================*/
/**
 * @brief アクディブになっているデバイス番号を取得する
 * 
 * @param[in] なし.
 * @return アクティブデバイス番号.
 */
unsigned int MouseDeviceDI8::getActiveDeviceNo()
{
	// 1つしか接続がないので、常に0を返す.
	return 0;
}


	
/*=========================================================================*/
/**
 * @brief 有効キー数を取得
 *
 * @retval true 取得成功.
 * @retval false 取得失敗.
 */
unsigned int MouseDeviceDI8::getKeyCount()
{
	return MOUSEKEY_COUNT;
}


	
/*=========================================================================*/
/**
 * @brief 何かしらのキーが押されているか調べる
 * 
 * @param[in] なし.
 * @retval 1以上 押されている.
 * @retval 0 何も押されていない.
 */
bool MouseDeviceDI8::getKeyDown()
{
	// 押されたボタンが存在するか調べる
	if( getDownKey() != MOUSEBUTTON_NONE ){
		// 押されたボタンがある
		return true;
	}
	// 押されたボタンが存在しない
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
bool MouseDeviceDI8::getKeyDown( unsigned int key )
{
	// キーを変換
	unsigned int conKey = convertKey( key );

	// キー情報と判定
	if( ( nowBtn_ & conKey ) != 0 ){
		// 押されていた
		return true;
	}
	// 押されていなかった
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
unsigned int MouseDeviceDI8::getDownKey()
{
	// 押されたボタンがあるか調べる
	for( int i=0; i<MOUSEKEY_COUNT; ++i ){
		// 押されているか調べる
		if( getKeyDown( i ) == true ){
			return i;
		}
	}
	// 何も押されていなかった
	return MOUSEBUTTON_NONE;
}



/*=========================================================================*/
/**
 * @brief 何かしらのキーが離されたか調べる
 * 
 * @param[in] なし.
 * @retval true 離された.
 * @retval false 離されていない.
 */
bool MouseDeviceDI8::getKeyRelease()
{
	// 離されたボタンがあるか
	if( getReleaseKey() != MOUSEBUTTON_NONE ){
		// 離されたボタンがあった
		return true;
	}
	// 離されたボタンが無かった
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
bool MouseDeviceDI8::getKeyRelease( unsigned int key )
{
	// キーを変換する
	unsigned int conKey = convertKey( key );

	if( ( ( oldBtn_ & ~nowBtn_ ) & conKey ) != 0 ){
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
unsigned int MouseDeviceDI8::getReleaseKey()
{
	for( int i=0; i<MOUSEKEY_COUNT; ++i ){
		// 押されているか調べる
		if( getKeyRelease( i ) == true ){
			return i;
		}
	}
	// 何も押されていなかった
	return MOUSEBUTTON_NONE;
}



/*=========================================================================*/
/**
 * @brief なにかしらのキーがタイプされたか
 * 
 * @param[in] なし.
 * @retval true タイプされた.
 : @retval false タイプされていない.
 */
bool MouseDeviceDI8::getKeyTrigger()
{
	// 離されたボタンがあるか
	if( getTriggerKey() != MOUSEBUTTON_NONE ){
		// 離されたボタンがあった
		return true;
	}
	// 離されたボタンが無かった
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
bool MouseDeviceDI8::getKeyTrigger( unsigned int key )
{
	// キーを変換する
	unsigned int conKey = convertKey( key );

	if( ( ( ~oldBtn_ & nowBtn_ ) & conKey ) != 0 ){
		return true;
	}
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
unsigned int MouseDeviceDI8::getTriggerKey()
{
	for( int i=0; i<MOUSEKEY_COUNT; ++i ){
		// 押されているか調べる
		if( getKeyTrigger( i ) == true ){
			return i;
		}
	}
	// 何も押されていなかった
	return MOUSEBUTTON_NONE;
}



/*===========================================================================*/
/**
 * @brief マウスカーソルの移動可能範囲を設定する
 * 
 * @param[in] clip 移動可能範囲.
 * @return なし.
 */
void MouseDeviceDI8::setMouseCursorClip(const Rect& clip)
{
	clip_ = clip;
}



/*===========================================================================*/
/**
 * @brief マウスの移動比率を設定する
 * 
 * @param[in] ratio 移動比率.
 * @return なし.
 */
void MouseDeviceDI8::setMouseCursorRatio(float ratio)
{
	ratio_ = ratio;
}



/*===========================================================================*/
/**
 * @brief マウスの位置座標を設定する
 * 
 * @param[in] x x座標.
 * @param[in] y y座標.
 * @param[in] z z座標.
 * @return なし.
 */
void MouseDeviceDI8::setMousePosition(int x, int y, int z)
{
	position_.x = static_cast< float >( x );
	position_.y = static_cast< float >( y );
	position_.z = static_cast< float >( z );
}



/*===========================================================================*/
/**
 * @brief マウス入力情報の取得
 * 
 * @param[in] なし.
 * @retval true 取得成功.
 * @retval false 取得失敗.
 */
void MouseDeviceDI8::readMouseData()
{
	// 前回の状態を保存
	oldBtn_ = nowBtn_;

	DIMOUSESTATE2 dims = {}; // マウスデータ構造体

	// マウスの情報が取得できたか
	HRESULT result = mouseDevice_->GetDeviceState( sizeof( DIMOUSESTATE2 ), &dims );
	if( result == DI_OK ){
		// 移動量を取得する
		ltm_.x = static_cast< float >( dims.lX );
		ltm_.y = static_cast< float >( dims.lY );
		ltm_.z = static_cast< float >( dims.lZ );

		// 押されたボタンを取得する
		nowBtn_ = 0;
		if( ( dims.rgbButtons[0] & 0x80 ) != 0 ){
			nowBtn_ |= MOUSEBUTTON_1;
		}
		if( ( dims.rgbButtons[1] & 0x80 ) != 0 ){
			nowBtn_ |= MOUSEBUTTON_2;
		}
		if( ( dims.rgbButtons[2] & 0x80 ) != 0 ){
			nowBtn_ |= MOUSEBUTTON_3;
		}
		if( ( dims.rgbButtons[3] & 0x80 ) != 0 ){
			nowBtn_ |= MOUSEBUTTON_4;
		}

	}
	// 読み取りに失敗した
	else{
		// アクセス権を再取得する
		getReacquire();

		// ボタンを読み取り不可に設定
		nowBtn_ = MOUSEBUTTON_NONE;
	}
}



/*===========================================================================*/
/**
 * @brief マウス座標をクリッピング
 * 
 * @param[in] なし.
 * @return なし.
 */
void MouseDeviceDI8::clipMouseCursor()
{
	// x座標をクリップする
	if( position_.x < clip_.left ){
		position_.x = static_cast< float >( clip_.left );
	}
	else if( position_.x > clip_.right ){
		position_.x = static_cast< float >( clip_.right );
	}

	// y座標をクリップする
	if( position_.y < clip_.top ){
		position_.y = static_cast< float >( clip_.top );
	}
	else if( position_.y > clip_.bottom ){
		position_.y = static_cast< float >( clip_.bottom );
	}
}



/*===========================================================================*/
/**
 * @brief マウスのアクセス権の再取得
 * 
 * @param[in] なし.
 * @retval true 取得成功.
 * @retval false 取得失敗.
 */
bool MouseDeviceDI8::getReacquire()
{
	HRESULT result;

	// アクセス権を取得する
	result = mouseDevice_->Acquire();

	if( SUCCEEDED( result ) ){
		return true;
	}

	return false;
}



/*===========================================================================*/
/**
 * @brief マウスデバイスを解放する
 * 
 * @param[in] なし.
 * @return なし.
 */
void MouseDeviceDI8::release()
{
	// DirectInputDeviceオブジェクトの解放
	if( mouseDevice_ != NULL ){
		mouseDevice_->Unacquire();
		mouseDevice_->Release();
		mouseDevice_ = NULL;
	}

	// デバイスを解放
	if( inputDevice_ != NULL ){
		inputDevice_->Release();
		inputDevice_ = NULL;
	}
}



/*=========================================================================*/
/**
 * @brief キーを変換する
 * 
 * @param[in] key 変換するキー.
 * @return 変換後のキー.
 */
unsigned int MouseDeviceDI8::convertKey( unsigned int key )
{
	if( key >= MOUSEKEY_COUNT ){
		return 0;
	}

	return mouseKeys[ key ];
}

	
	
/*========= EOF =============================================================*/