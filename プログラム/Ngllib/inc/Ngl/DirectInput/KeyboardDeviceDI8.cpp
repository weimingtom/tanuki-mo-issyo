/*******************************************************************************/
/**
 * @file KeyboardDeviceDI8.cpp.
 * 
 * @brief DirectInput キーボード入力デバイスクラスソースファイル.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"KeyboardDeviceDI8.h"
#include	<cassert>


namespace {

	/** キー定数配列 */
	static const unsigned int KeyboardKeys[] = {
		0,					/**< 0		何も押されていない			*/
		DIK_ESCAPE,			/**< 1		エスケープキー				*/
		DIK_1,				/**< 2		1キー						*/
		DIK_2,				/**< 3		2キー						*/
		DIK_3,				/**< 4		3キー						*/
		DIK_4,				/**< 5		4キー						*/
		DIK_5,				/**< 6		5キー						*/
		DIK_6,				/**< 7		6キー						*/
		DIK_7,				/**< 8		7キー						*/
		DIK_8,				/**< 9		8キー						*/
		DIK_9,				/**< 10		9キー						*/
		DIK_0,				/**< 11		0キー						*/
		DIK_MINUS,			/**< 12		-キー						*/
		DIK_EQUALS,			/**< 13		=キー						*/
		DIK_BACK,			/**< 14		バックスペースキー			*/
		DIK_TAB,			/**< 15		タブキー					*/
		DIK_Q,				/**< 16		qキー						*/
		DIK_W,				/**< 17		wキー						*/
		DIK_E,				/**< 18		eキー						*/
		DIK_R,				/**< 19		rキー						*/
		DIK_T,				/**< 20		tキー						*/
		DIK_Y,				/**< 21		yキー						*/
		DIK_U,				/**< 22		uキー						*/
		DIK_I,				/**< 23		iキー						*/
		DIK_O,				/**< 24		oキー						*/
		DIK_P,				/**< 25		pキー						*/
		DIK_LBRACKET,		/**< 26		左角括弧					*/
		DIK_RBRACKET,		/**< 27		右角括弧					*/
		DIK_RETURN,			/**< 28		リターンキー				*/
		DIK_LCONTROL,		/**< 29		左Ctrlキー					*/
		DIK_A,				/**< 30		aキー						*/
		DIK_S,				/**< 31		sキー						*/
		DIK_D,				/**< 32		dキー						*/
		DIK_F,				/**< 33		fキー						*/
		DIK_G,				/**< 34		gキー						*/
		DIK_H,				/**< 35		hキー						*/
		DIK_J,				/**< 36		jキー						*/
		DIK_K,				/**< 37		kキー						*/
		DIK_L,				/**< 38		lキー						*/
		DIK_SEMICOLON,		/**< 39		,キー						*/
		DIK_APOSTROPHE,		/**< 40		:キー						*/
		DIK_GRAVE,			/**< 41		`キー						*/
		DIK_LSHIFT,			/**< 42		左SHIFTキー					*/
		DIK_BACKSLASH,		/**< 43		\キー						*/
		DIK_Z,				/**< 44		zキー						*/
		DIK_X,				/**< 45		xキー						*/
		DIK_C,				/**< 46		cキー						*/
		DIK_V,				/**< 47		vキー						*/
		DIK_B,				/**< 48		bキー						*/
		DIK_N,				/**< 49		nキー						*/
		DIK_M,				/**< 50		mキー						*/
		DIK_COMMA,			/**< 51		,キー						*/
		DIK_PERIOD,			/**< 52		.キー						*/
		DIK_SLASH,			/**< 53		/キー						*/
		DIK_RSHIFT,			/**< 54		右SHIFTキー					*/
		DIK_MULTIPLY,		/**< 55		テンキーの*キー				*/
		DIK_LMENU,			/**< 56		左Altキー					*/
		DIK_SPACE,			/**< 57		スペースキー				*/
		DIK_CAPITAL,		/**< 58		CapsLockキー				*/
		DIK_F1,				/**< 59		F1キー						*/
		DIK_F2,				/**< 60		F2キー						*/
		DIK_F3,				/**< 61		F3キー						*/
		DIK_F4,				/**< 62		F4キー						*/
		DIK_F5,				/**< 63		F5キー						*/
		DIK_F6,				/**< 64		F6キー						*/
		DIK_F7,				/**< 65		F7キー						*/
		DIK_F8,				/**< 66		F8キー						*/
		DIK_F9,				/**< 67		F9キー						*/
		DIK_F10,			/**< 68		F10キー						*/
		DIK_NUMLOCK,		/**< 69		NumLockキー					*/
		DIK_SCROLL,			/**< 70		スクロールキー				*/
		DIK_NUMPAD7,		/**< 71		テンキーの7					*/
		DIK_NUMPAD8,		/**< 72		テンキーの8					*/
		DIK_NUMPAD9,		/**< 73		テンキーの9					*/
		DIK_SUBTRACT,		/**< 74		テンキーのーキー			*/
		DIK_NUMPAD4,		/**< 75		テンキーの4					*/
		DIK_NUMPAD5,		/**< 76		テンキーの5					*/
		DIK_NUMPAD6,		/**< 77		テンキーの6					*/
		DIK_ADD,			/**< 78		テンキーの＋キー			*/
		DIK_NUMPAD1,		/**< 79		テンキーの1					*/
		DIK_NUMPAD2,		/**< 80		テンキーの2					*/
		DIK_NUMPAD3,		/**< 81		テンキーの3					*/
		DIK_NUMPAD0,		/**< 82		テンキーの0					*/
		DIK_DECIMAL,		/**< 83		テンキーの.キー				*/
		DIK_OEM_102,		/**< 84		英語＆独語の102キーボード	*/
		DIK_F11,			/**< 85		F11キー						*/
		DIK_F12,			/**< 86		F12キー						*/
		DIK_F13,			/**< 87		F13キー(NEC-PC98用)			*/
		DIK_F14,			/**< 88		F14キー(NEC-PC98用)			*/
		DIK_F15,			/**< 89		F15キー(NEC-PC98用)			*/
		DIK_KANA,			/**< 90		カナキー					*/
		DIK_CONVERT,		/**< 91		日本語キーボードのキー		*/
		DIK_NOCONVERT,		/**< 92		日本語キーボードのキー		*/
		DIK_YEN,			/**< 93		\キー						*/
		DIK_NUMPADEQUALS,	/**< 94		PC98テンキーのキー			*/
		DIK_PREVTRACK,		/**< 95		前のトラックキー			*/
		DIK_AT,				/**< 96		日本語キーボードのキー		*/
		DIK_COLON,			/**< 97		日本語キーボードのキー		*/
		DIK_UNDERLINE,		/**< 98		_キー						*/
		DIK_KANJI,			/**< 99		漢字キー					*/
		DIK_STOP,			/**< 100	PC98用キー					*/
		DIK_AX,				/**< 101	日本語キーボードのキー		*/
		DIK_UNLABELED,		/**< 102	日本語キーボードのキー		*/
		DIK_NEXTTRACK,		/**< 103	次のトラックキー			*/
		DIK_NUMPADENTER,	/**< 104	テンキーのエンターキー		*/
		DIK_RCONTROL,		/**< 105	右Ctrlキー					*/
		DIK_MUTE,			/**< 106	ミュートキー				*/
		DIK_CALCULATOR,		/**< 107	電卓キー					*/
		DIK_PLAYPAUSE,		/**< 108	一時停止キー				*/
		DIK_MEDIASTOP,		/**< 109	メディア停止キー			*/
		DIK_VOLUMEDOWN,		/**< 110	音量ダウンキー				*/
		DIK_VOLUMEUP,		/**< 111	音量アップキー				*/
		DIK_WEBHOME,		/**< 112	ウェブホームページキー		*/
		DIK_NUMPADCOMMA,	/**< 113	テンキーの.キー				*/
		DIK_DIVIDE,			/**< 114	テンキーの/キー				*/
		DIK_SYSRQ,			/**< 115	SysRqキー					*/
		DIK_RMENU,			/**< 116	右メニューキー				*/
		DIK_PAUSE,			/**< 117	ポーズキー					*/
		DIK_HOME,			/**< 118	ホームキー					*/
		DIK_UP,				/**< 119	↑キー						*/
		DIK_PRIOR,			/**< 120	PageUpキー					*/
		DIK_LEFT,			/**< 121	←キー						*/
		DIK_RIGHT,			/**< 122	→キー						*/
		DIK_END,			/**< 123	Endキー						*/
		DIK_DOWN,			/**< 124	↓キー						*/
		DIK_NEXT,			/**< 125	Nextキー					*/
		DIK_INSERT,			/**< 126	Insertキー					*/
		DIK_DELETE,			/**< 127	デリートキー				*/
		DIK_LWIN,			/**< 128	左Windowsキー				*/
		DIK_RWIN,			/**< 129	右Windowsキー				*/
		DIK_APPS,			/**< 130	アプリケーションキー		*/
		DIK_POWER,			/**< 131	電源キー					*/
		DIK_SLEEP,			/**< 132	スリープキー				*/
		DIK_WAKE,			/**< 133	ウェークアップキー			*/
		DIK_WEBSEARCH,		/**< 134	WEB検索キー					*/
		DIK_WEBFAVORITES,	/**< 135	お気に入りキー				*/
		DIK_WEBREFRESH,		/**< 136	ウェブリフレッシュキー		*/
		DIK_WEBSTOP,		/**< 137	メディア選択キー			*/
		DIK_WEBFORWARD,		/**< 138	ウェブ先に進むキー			*/
		DIK_WEBBACK,		/**< 139	ウェブ前に戻るキー			*/
		DIK_MYCOMPUTER,		/**< 140	マイコンピュータキー		*/
		DIK_MAIL,			/**< 141	メールキー					*/
		DIK_MEDIASELECT,	/**< 142	メディア選択キー			*/
	};

	/** キー総数 */
	static const unsigned int KEYBOARDKEY_COUNT = sizeof( KeyboardKeys ) / sizeof( unsigned int );
}

using namespace Ngl;
using namespace Ngl::DirectInput;

/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
KeyboardDeviceDI8::KeyboardDeviceDI8() :
	inputDevice_( 0 ),	// DirectInputデバイス
	keyDevice_( 0 )		// キーボードデバイス
{}



/*===========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
KeyboardDeviceDI8::~KeyboardDeviceDI8()
{
	release();
}

	
	
/*===========================================================================*/
/**
 * @brief 入力デバイスの作成
 * 
 * @param[in] hwnd ウィンドウハンドル.
 * @return なし.
 */
bool KeyboardDeviceDI8::create( HWND hwnd )
{
	// バッファを確保
	ZeroMemory( keyState_, sizeof( keyState_ ) );
	newKeyBuf_ = keyState_[0];
	oldKeyBuf_ = keyState_[1];

	HRESULT hr = DI_OK;

	// DirectInputオブジェクトの作成
	hr = DirectInput8Create( GetModuleHandle( 0 ), DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&inputDevice_, 0 );
	assert( hr == DI_OK );

	// DirectInputDeviceオブジェクトの作成
	hr = inputDevice_->CreateDevice( GUID_SysKeyboard, &keyDevice_, 0 );
	assert( hr == DI_OK );

	// デバイスをキーボードに設定
	hr = keyDevice_->SetDataFormat( &c_dfDIKeyboard );
	assert( hr == DI_OK );

	// 強調レベルの設定
	hr = keyDevice_->SetCooperativeLevel( hwnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND );
	assert( hr == DI_OK );

	// デバイスを取得する
	keyDevice_->Acquire();

	return true;
}



/*===========================================================================*/
/**
 * @brief キー情報を読み込む
 * 
 * @param[in] なし.
 * @retval true 取得成功.
 * @retval false 取得失敗.
 */
bool KeyboardDeviceDI8::loadKeyState()
{
	// アクセス権を取得できたか？
	if( getReacquire() == true ){
		HRESULT result; // 取得結果

		// 古いバッファと新しいバッファを入れ替える
		BYTE* tmp	= newKeyBuf_;
		newKeyBuf_	= oldKeyBuf_;
		oldKeyBuf_	= tmp;

		// キーの状態を取得する
		result = keyDevice_->GetDeviceState(
			sizeof(BYTE)*DIRECTINPUTKEYBOARDKEY_COUNT,	// データサイズ
			(LPVOID)newKeyBuf_							// キーバッファ
			);

		// 取得できたか
		if( SUCCEEDED( result ) ){
			// 取得完了
			return true;
		}
		else{
			// 取得失敗
			return false;
		}
	}

	// 取得できなかった
	return false;
}



/*=========================================================================*/
/**
 * @brief 軸の状態を読み込む
 * 
 * @param[in] なし.
 * @return 各軸の状態ベクトル.
 */
Vector3 KeyboardDeviceDI8::readAxisState()
{
	return Vector3( 0.0f, 0.0f, 0.0f );
}
	
	
	
/*=========================================================================*/
/**
 * @brief 接続デバイス数を取得
 * 
 * @param[in] なし.
 * @return 接続デバイス数.
 */
unsigned int KeyboardDeviceDI8::getConnectDeviceCount()
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
void KeyboardDeviceDI8::setActiveDevice( unsigned int no )
{
	// 1つしか接続がないので、変更処理をしない。
}

	
	
/*=========================================================================*/
/**
 * @brief アクディブになっているデバイス番号を取得する
 * 
 * @param[in] なし.
 * @return アクティブデバイス番号.
 */
unsigned int KeyboardDeviceDI8::getActiveDeviceNo()
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
unsigned int KeyboardDeviceDI8::getKeyCount()
{
	return KEYBOARDKEY_COUNT;
}

	
	
/*===========================================================================*/
/**
 * @brief 何かしらのキーが押されているか調べる
 * 
 * @param[in] なし.
 * @return 押されている  0 何も押されていない.
 */
bool KeyboardDeviceDI8::getKeyDown()
{
	// キーが押されているか調べる
	if( getDownKey() != 0 ){
		// 何か押されていた。
		return true;
	}

	// 何も押されていなかった
	return false;
}



/*===========================================================================*/
/**
 * @brief 指定したキーが押されているか調べる
 * 
 * @param[in] なし.
 * @return true 押されていた  false 押されていなかった.
 */
bool KeyboardDeviceDI8::getKeyDown( unsigned int key )
{
	// キー数を超えているか
	if( key >= KEYBOARDKEY_COUNT ){
		return false;
	}

	// キーを変換
	key = convertKey( key );

	// 押されているか？
	if( ( newKeyBuf_[key] & 0x80 ) != 0 ){
		// 押されていた
		return true;
	}

	// 押されていなかった
	return false;
}



/*===========================================================================*/
/**
 * @brief 押されているキーを調べる
 * 
 * @param[in] なし.
 * @return 押されているキー  0 何も押されていない場合.
 */
unsigned int KeyboardDeviceDI8::getDownKey()
{
	// 全キーと判定
	for( int i=0; i<DIRECTINPUTKEYBOARDKEY_COUNT; i++ ){
		// 押されているか
		if( ( newKeyBuf_[i] & 0x80 ) != 0 ){
			// 押されていた
			return convertDI8Key( i );
		}
	}

	// 押されていなかった
	return 0;
}



/*===========================================================================*/
/**
 * @brief 何かしらのキーが離されたか調べる
 * 
 * @param[in] なし.
 * @return true 離された, false 離されていない.
 */
bool KeyboardDeviceDI8::getKeyRelease()
{
	// 離されているキーがあるか調べる
	int key = getReleaseKey();

	// 離されたキーがあるか
	if( key != 0 ){
		return true;
	}

	// 離されていなかった
	return false;
}



/*===========================================================================*/
/**
 * @brief 指定したキーが離されたか調べる
 * 
 * @param[in] key 調べるキー.
 * @return true 離された, false 離されていない.
 */
bool KeyboardDeviceDI8::getKeyRelease( unsigned int key )
{
	if( key >= KEYBOARDKEY_COUNT ){
		return false;
	}

	// キーを変換
	key = convertKey( key );

	// キーを調べる
	if( ( oldKeyBuf_[ key ] & ~newKeyBuf_[ key ] & 0x80 ) != 0 ){
		// 離されていた
		return true;
	}

	// 離されていない
	return false;
}



/*===========================================================================*/
/**
 * @brief 離されたキーを調べる
 * 
 * @param[in] なし.
 * @return key 離されたキー.
 */
unsigned int KeyboardDeviceDI8::getReleaseKey()
{
	// すべてのキーで調べる
	for( int i=0; i<DIRECTINPUTKEYBOARDKEY_COUNT; i++ ){
		// 離されていたか
		if( getKeyRelease( i ) == true ){
			return i;
		}
	}

	// 何も離されていないので0を返す
	return 0;
}



/*===========================================================================*/
/**
 * @brief なにかしらのキーがタイプされたか
 * 
 * @param[in] なし.
 * @return true タイプされた, false タイプされていない.
 */
bool KeyboardDeviceDI8::getKeyTrigger()
{
	// 離されているキーがあるか調べる
	int key = getTriggerKey();

	// 離されたキーがあるか
	if( key != 0 ){
		return true;
	}

	// 離されていなかった
	return false;
}



/*===========================================================================*/
/**
 * @brief 指定のキーがタイプされたか調べる
 * 
 * @param[in] 調べるキー.
 * @return true タイプされた, false タイプされていない.
 */
bool KeyboardDeviceDI8::getKeyTrigger( unsigned int key )
{
	if( key >= KEYBOARDKEY_COUNT ){
		return false;
	}

	// キーを変換
	key = convertKey( key );

	// キーを調べる
	if( ( ~oldKeyBuf_[ key ] & newKeyBuf_[ key ] & 0x80 ) != 0 ){
		// 離されていた
		return true;
	}

	// タイプされていない
	return false;
}



/*===========================================================================*/
/**
 * @brief タイプされたキーを取得する
 * 
 * @param[in] なし.
 * @return タイプされたキー.
 */
unsigned int KeyboardDeviceDI8::getTriggerKey()
{
	// すべてのキーで調べる
	for( int i=0; i<KEYBOARDKEY_COUNT; i++ ){
		// 離されていたか
		if( getKeyTrigger( i ) == true ){
			return i;
		}
	}

	// 何も離されていないので0を返す
	return 0;
}



/*===========================================================================*/
/**
 * @brief アクセス権の再取得
 * 
 * @param[in] なし.
 * @return true 取得成功  false 取得失敗.
 */
bool KeyboardDeviceDI8::getReacquire()
{
	HRESULT result;

	// アクセス権を取得する
	result = keyDevice_->Acquire();

	if( SUCCEEDED( result ) ){
		return true;
	}

	return false;
}



/*===========================================================================*/
/**
 * @brief キーボードデバイスを解放する
 * 
 * @param[in] なし.
 * @return なし.
 */
void KeyboardDeviceDI8::release()
{
	// キーボードデバイスを解放
	if( keyDevice_ != 0 ) {
		keyDevice_->Unacquire();
		keyDevice_->Release();
		keyDevice_ = 0;
	}

	// 入力デバイスを解放
	if( inputDevice_ != 0 ){
		inputDevice_->Release();
		inputDevice_ = 0;
	}
}



/*=========================================================================*/
/**
 * @brief キーを変換する
 * 
 * @param[in] key 変換するキー.
 * @return 変換後のキー.
 */
unsigned int KeyboardDeviceDI8::convertKey( unsigned int key )
{
	// キー数をオーバーしているか
	if( key >= KEYBOARDKEY_COUNT ){
		return 0;
	}

	return KeyboardKeys[ key ];
}



/*=========================================================================*/
/**
 * @brief DI8キーに変換する
 * 
 * @param[in] key 変換するキー.
 * @return 変換後のDI8キー.
 */
unsigned int KeyboardDeviceDI8::convertDI8Key( unsigned int key )
{
	// キー数をオーバーしているか
	if( key >= DIRECTINPUTKEYBOARDKEY_COUNT ){
		return 0;
	}

	// キーを検索
	for( int i=0; i<KEYBOARDKEY_COUNT; ++i ){
		if( KeyboardKeys[ i ] == key ){
			return i;
		}
	}

	return KEYBOARDKEYDI8_NONE;
}

	
	
/*========= EOF =============================================================*/