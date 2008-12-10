/*******************************************************************************/
/**
 * @file JoystickDeviceDI8.cpp.
 * 
 * @brief DirectInput ジョイスティック入力デバイスクラスソースファイル.
 *
 * @date 2007/07/26.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/DirectInput/JoystickDeviceDI8.h"
#include	"Ngl/DirectInput/JoystickDI8.h"
#include	<algorithm>
#include	<functional>
#include	<cassert>

using namespace Ngl;
using namespace Ngl::DirectInput;


/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
JoystickDeviceDI8::JoystickDeviceDI8():
	inputDevice_( 0 ),		// DirectInputデバイス
	joyHwnd_( 0 ),			// ウィンドウハンドル
	activeJoystickNo_( 0 )	// アクティブなジョイスティック番号
{}



/*===========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
JoystickDeviceDI8::~JoystickDeviceDI8()
{
	// デバイスを削除
	JoystickList::iterator itor = joystickList_.begin();
	while( itor != joystickList_.end() ){
		delete *itor;
		itor = joystickList_.erase( itor );
	}

	// デバイスが作成されているか
	if( inputDevice_ != 0 ){
		// 解放する
		release();
		inputDevice_ = 0;
	}
}



/*===========================================================================*/
/**
 * @brief 入力デバイスの作成
 * 
 * @param[in] hwnd ウィンドウハンドル.
 * @return なし.
 */
bool JoystickDeviceDI8::create(HWND hwnd)
{
	// ウィンドウハンドルを設定
	joyHwnd_ = hwnd;

	HRESULT hr = DI_OK; // 実行結果

	// DirectInputオブジェクトの作成
	hr = DirectInput8Create( GetModuleHandle( 0 ), DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&inputDevice_, 0 );
	assert( hr == DI_OK );
	
	// コントローラーを列挙する
	hr = inputDevice_->EnumDevices( DI8DEVCLASS_GAMECTRL, JoystickDeviceDI8::enumJoysticksCallback, this, DIEDFL_ATTACHEDONLY );
	assert( hr == DI_OK );

	 return true;
}



/*===========================================================================*/
/**
 * @brief 指定のジョイスティックから軸の状態を読み込む
 * 
 * @param[in] なし.
 * @return 各軸の状態ベクトル.
 */
Vector3 JoystickDeviceDI8::readAxisState()
{
	if( isJoyDeviceExists( activeJoystickNo_ ) ){
		return joystickList_[ activeJoystickNo_ ]->readAxisState();
	}

	return Vector3( 0.0f, 0.0f, 0.0f );
}



/*===========================================================================*/
/**
 * @brief 登録されているジョイスティックの状態を読み込む
 * 
 * @param[in] なし.
 * @return なし.
 */
bool JoystickDeviceDI8::loadKeyState()
{
	std::for_each(
		joystickList_.begin(),
		joystickList_.end(),
		std::mem_fun( &JoystickDI8::loadKeyState )
		);

	return true;
}



/*=========================================================================*/
/**
 * @brief 接続デバイス数を取得
 * 
 * @param[in] なし.
 * @return 接続デバイス数.
 */
unsigned int JoystickDeviceDI8::getConnectDeviceCount()
{
	return getCount();
}



/*=========================================================================*/
/**
 * @brief アクティブにするデバイスを変更する
 * 
 * @param[in] no 変更するデバイス番号.
 * @return なし.
 */
void JoystickDeviceDI8::setActiveDevice( unsigned int no )
{
	if( no < getCount() ){
		activeJoystickNo_ = no;
	}
}



/*=========================================================================*/
/**
 * @brief アクディブになっているデバイス番号を取得する
 * 
 * @param[in] なし.
 * @return アクティブデバイス番号.
 */
unsigned int JoystickDeviceDI8::getActiveDeviceNo()
{
	return activeJoystickNo_;
}
	
	

/*=========================================================================*/
/**
 * @brief 有効キー数を取得
 *
 * @retval true 取得成功.
 * @retval false 取得失敗.
 */
unsigned int JoystickDeviceDI8::getKeyCount()
{
	return JoystickDI8::JOYSTICKKEY_MAX;
}

	
	
/*=========================================================================*/
/**
 * @brief 何かしらのキーが押されているか調べる
 * 
 * @param[in] なし.
 * @retval 1以上 押されている.
 * @retval 0 何も押されていない.
 */
bool JoystickDeviceDI8::getKeyDown()
{
	if( isJoyDeviceExists( activeJoystickNo_ ) ){
		return joystickList_[ activeJoystickNo_ ]->getKeyDown();
	}

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
bool JoystickDeviceDI8::getKeyDown( unsigned int key )
{
	if( isJoyDeviceExists( activeJoystickNo_ ) ){
		return joystickList_[ activeJoystickNo_ ]->getKeyDown( key );
	}

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
unsigned int JoystickDeviceDI8::getDownKey()
{
	if( isJoyDeviceExists( activeJoystickNo_ ) ){
		return joystickList_[ activeJoystickNo_ ]->getDownKey();
	}
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
bool JoystickDeviceDI8::getKeyRelease()
{
	if( isJoyDeviceExists( activeJoystickNo_ ) ){
		return joystickList_[ activeJoystickNo_ ]->getKeyRelease();
	}
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
bool JoystickDeviceDI8::getKeyRelease( unsigned int key )
{
	if( isJoyDeviceExists( activeJoystickNo_ ) ){
		return joystickList_[ activeJoystickNo_ ]->getKeyRelease( key );
	}
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
unsigned int JoystickDeviceDI8::getReleaseKey()
{
	if( isJoyDeviceExists( activeJoystickNo_ ) ){
		return joystickList_[ activeJoystickNo_ ]->getReleaseKey();
	}
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
bool JoystickDeviceDI8::getKeyTrigger()

{
	if( isJoyDeviceExists( activeJoystickNo_ ) ){
		return joystickList_[ activeJoystickNo_ ]->getKeyTrigger();
	}
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
bool JoystickDeviceDI8::getKeyTrigger( unsigned int key )
{
	if( isJoyDeviceExists( activeJoystickNo_ ) ){
		return joystickList_[ activeJoystickNo_ ]->getKeyTrigger( key );
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
unsigned int JoystickDeviceDI8::getTriggerKey()
{
	if( isJoyDeviceExists( activeJoystickNo_ ) ){
		return joystickList_[ activeJoystickNo_ ]->getTriggerKey();
	}
	return 0;
}



/*===========================================================================*/
/**
 * @brief 接続されているジョイスティックの数を調べる
 * 
 * @param[in] なし.
 * @return パッドの数.
 */
/*===========================================================================*/
unsigned int JoystickDeviceDI8::getCount()
{
	return static_cast< unsigned int >( joystickList_.size() );
}



/*===========================================================================*/
/**
 * @brief 指定番号のジョイスティックが存在しているか調べる
 * 
 * @param[in] no 調べるジョイスティック番号.
 * @retval true 存在してる.
 * @retval false 存在していない.
 */
/*===========================================================================*/
bool JoystickDeviceDI8::isJoyDeviceExists(unsigned int no)
{
	// リスト全体の要素数と比較する
	if( static_cast< int >( joystickList_.size() ) > no ){
		// 存在していた
		return true;
	}
	// 存在していない
	return false;
}



/*===========================================================================*/
/**
 * @brief ジョイスティックデバイスを解放する
 * 
 * @param[in] なし.
 * @return なし.
 */
/*===========================================================================*/
void JoystickDeviceDI8::release()
{
	// 登録されているジョイスティックを解放する
	JoystickList::iterator i = joystickList_.begin();
	while( i != joystickList_.end() ){
		delete *i;

		i = joystickList_.erase( i );
	}

	// DirectXインプットデバイスオブジェクトを解放する
	inputDevice_->Release();
	inputDevice_ = 0;
}



/*===========================================================================*/
/**
 * @brief 登録されているジョイスティックのアクセス権の再取得
 * 
 * @param[in] なし.
 * @return なし.
 */
/*===========================================================================*/
void JoystickDeviceDI8::getReacquire()
{
	std::for_each(
		joystickList_.begin(),
		joystickList_.end(),
		std::mem_fun( &JoystickDI8::getReacquire )
		);
}



/*===========================================================================*/
/**
 * @brief デバイスを作成する
 * 
 * @param[in] pdinst インスタンス.
 * @param[in] hnd ハンドル.
 * @return DIENUM_CONTINUE 列挙を続ける.
 */
/*===========================================================================*/
BOOL FAR PASCAL JoystickDeviceDI8::enumJoysticksCallback(LPCDIDEVICEINSTANCE pdinst, LPVOID hnd)
{
	JoystickDeviceDI8*	inputDevice	= static_cast< JoystickDeviceDI8* >( hnd );
	LPDIRECTINPUT8		pdi			= inputDevice->inputDevice_;

	// デバイスクラスを作成する
	JoystickDI8* device = new JoystickDI8();
	if( device->create( pdi, pdinst, inputDevice->joyHwnd_ ) == false ){
		return DIENUM_CONTINUE;
	}

	// 登録数が最大数を超えていないか
	if( inputDevice->joystickList_.size() < JOYSTIC_MAX ){
		// リストに登録する
		inputDevice->joystickList_.push_back( device );
	}
	else{
		delete device;

		return DIENUM_CONTINUE;
	}

	// データフォーマットの設定
    return DIENUM_CONTINUE;
}



/*========= EOF =============================================================*/