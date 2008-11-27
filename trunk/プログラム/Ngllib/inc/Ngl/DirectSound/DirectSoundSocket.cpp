/*******************************************************************************/
/**
 * @file DirectSoundSocket.cpp.
 * 
 * @brief DirectSound ソケットクラスソースファイル.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentaru Nishimura.
 */
/******************************************************************************/
#include	"DirectSoundSocket.h"
#include	<cassert>

using namespace Ngl;
using namespace Ngl::DirectSound;


/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
DirectSoundSocket::DirectSoundSocket():
	buffer_( NULL ),		// ダイレクトサウンドオブジェクト
	buffer3D_( NULL ),		// ダイレクト３Dサウンドオブジェクト
	listener3D_( NULL ),	// ダイレクト３Dリスナーオブジェクト
	waveFormat_( NULL ),	// DirectSoundSocketファイルフォーマット
	waveDataSize_( NULL )	// DirectSoundSocketデータサイズ
{}



/*===========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
DirectSoundSocket::~DirectSoundSocket()
{
	// 解放する
	release();
}



/*===========================================================================*/
/**
 * @brief 作成する
 * 
 * @param[in] fileName ファイル名.
 * @param[in] ds ダイレクトサウンドオブジェクト.
 * @param[in] rg リソースクラスのポインタ.
 * @retval true 作成成功.
 * @retval false 作成失敗.
 */
bool DirectSoundSocket::create( const char *fileName, IDirectSound8* ds, IDirectSoundResource* rg )
{
	// ソースからバッファを作成する
	buffer_ = rg->create( fileName, ds );
	assert( buffer_ != NULL );

	// 3Dバッファを取得する
	HRESULT hr = DS_OK;
	hr = buffer_->QueryInterface( IID_IDirectSound3DBuffer8, (VOID**)&buffer3D_ );
	if( hr != DS_OK ){
		// 3D再生が不可能
		return false;
	}
	
	// プライマリーバッファを取得
	LPDIRECTSOUNDBUFFER primary = NULL;
	DSBUFFERDESC dsbd;
	ZeroMemory( &dsbd, sizeof( DSBUFFERDESC ) );
	dsbd.dwSize		= sizeof( DSBUFFERDESC );
	dsbd.dwFlags	= DSBCAPS_CTRL3D | DSBCAPS_PRIMARYBUFFER;
	ds->CreateSoundBuffer( &dsbd, &primary, NULL );
	assert( primary != NULL );

	// リスナーオブジェクトを取得する
	primary->QueryInterface( IID_IDirectSound3DListener8, (VOID**)&listener3D_ );
	primary->Release();
	assert( listener3D_ != NULL );

	// 作成成功
	return true;
}



/*===========================================================================*/
/**
 * @brief 消滅させる
 * 
 * @param[in] なし.
 * @return なし.
 */
void DirectSoundSocket::release()
{
	// 3Dサウンドバッファをクリア
	buffer3D_	= NULL;
	listener3D_	= NULL;

	// バッファが作成されているか
	if( buffer_ != 0 ){
		// フォーマット情報を削除
		delete waveFormat_;
		waveFormat_;

		// バッファを開放する
		buffer_->Release();
		buffer_;
	}
}



/*===========================================================================*/
/**
 * @brief 再生する
 * 
 * @param[in] なし.
 * @return なし.
 */
void DirectSoundSocket::play()
{
	// 作成されているか
	assert( buffer_ != NULL );

	DWORD dwStatus	= 0;	// 再生状態

	// サウンドバッファの状態を取得する
	if( buffer_->GetStatus( &dwStatus ) != DS_OK ){
		return;
	}

	// サウンドバッファが失われているかチェックする
	if( ( dwStatus & DSBSTATUS_BUFFERLOST ) == DSBSTATUS_BUFFERLOST ){
		// サウンドバッファを復元する
		if( buffer_->Restore() != DS_OK ){
			return;
		}
	}

	// 再生中のチェック
	if( ( dwStatus & DSBSTATUS_PLAYING ) == DSBSTATUS_PLAYING ){
		// サウンドを停止する
		stop();
	}

	// 再生位置を設定
	buffer_->SetCurrentPosition( static_cast< DWORD >( soundState_.currentTime ) );

	// サウンドを再生する
	if( buffer_->Play( 0, 0, 0 ) != DS_OK ){
		return;
	}
}



/*===========================================================================*/
/**
 * @brief 再生中か調べる
 * 
 * @param[in] なし.
 * @retval true 再生中.
 * @retval false 停止中.
 */
bool DirectSoundSocket::isPlay()
{
	DWORD dwStatus;	// バッファの状態

	// サウンドバッファの状態を取得する
	if( buffer_->GetStatus( &dwStatus ) != DS_OK ){
		return false;
	}

	// 再生中かチェックする
	if( (  dwStatus & DSBSTATUS_PLAYING ) == DSBSTATUS_PLAYING ){
		// 再生中だった
		return true;
	}
	
	// 再生していなかった
	return false;
}



/*=========================================================================*/
/**
 * @brief 一時停止
 * 
 * @param[in] なし.
 * @return なし.
 */
void DirectSoundSocket::pause()
{
	buffer_->GetCurrentPosition( (LPDWORD)&soundState_.currentTime, NULL );

	// 停止する
	buffer_->Stop();
}

	
	
/*===========================================================================*/
/**
 * @brief 停止する
 * 
 * @param[in] なし.
 * @return なし.
 */
void DirectSoundSocket::stop()
{
	// 停止する
	buffer_->Stop();
	
	// 再生位置を初期化
	soundState_.currentTime = 0.0f;
}



/*=========================================================================*/
/**
 * @brief 状態記述子を取得
 * 
 * @param[in] なし.
 * @return サウンド状態記述子.
 */
SoundStateDesc& DirectSoundSocket::soundState()
{
	// 現在の再生位置を取得
	buffer_->GetCurrentPosition( reinterpret_cast< LPDWORD >( &soundState_.currentTime ), 0 );
	
	// DirectSoundでは曲の長さを取得できないので、0を設定
	soundState_.endTime = 0;

	// パンの値を取得
	long pan = 0;
	buffer_->GetPan( &pan );
	soundState_.pan = static_cast< int >( pan );

	// ボリュームの値を取得
	long volume = 0;
	buffer_->GetVolume( &volume );
	soundState_.volume = static_cast< unsigned int >( volume ) + ( SOUND_VOLUME_MAX * 100 );

	return soundState_;
}



/*=========================================================================*/
/**
 * @brief 曲の再生タイプを設定
 * 
 * @param[in] type 再生タイプ.
 * @return なし.
 */
void DirectSoundSocket::setType( SoundPlayType type )
{
	soundState_.type = type;
}



/*=========================================================================*/
/**
 * @brief 再生位置を設定する
 * 
 * @param[in] time 設定する再生位置時間( ミリ秒 ).
 * @return なし.
 */
void DirectSoundSocket::setTime( float time )
{
	soundState_.currentTime = time;

	// 再生をしなおす
	play();
}



/*=========================================================================*/
/**
 * @brief ボリュームの設定
 * 
 * 最大値 100( SOUND_VOLUME_MAX )
 * 最小値 0  ( SOUND_VOLUME_MIN )
 *
 * @param[in] volume 設定するボリューム.
 * @return なし.
 */
void DirectSoundSocket::setVolume( unsigned int volume )
{
	soundState_.volume = volume;

	// ボリューム値を設定
	//  -10000( DSBVOLUME_MIN 無音 )～0( DSBVOLUME_MAX )
	buffer_->SetVolume( static_cast< LONG >( -10000 + ( soundState_.volume * 100 )  ) );
}



/*=========================================================================*/
/**
 * @brief 左右のボリューム比率を設定
 *
 * 左最大値 -100 ( SOUND_PAN_LEFTMAX  )
 * 中間値   0    ( SOUND_PAN_MIDDLE   )
 * 右最大値 100  ( SOUND_PAN_RIGHTMAX )
 * 
 * @param[in] pan 設定するボリューム比率.
 * @return なし.
 */
void DirectSoundSocket::setPan( int pan )
{
	soundState_.pan = pan;

	// 左右のボリューム比率を設定
	// -10000（DSBPAN_LEFT）から 10000（DSBPAN_RIGHT） の範囲で設定可能
	// 0（DSBPAN_CENTER）が中立値で 両方のチャンネルが最大ボリュームとなります
	// 1/100 デシベル (dB) の単位で測定されます
	long value = soundState_.pan * 100;
	buffer_->GetPan( reinterpret_cast< LPLONG >( &value ) );
}


	
// 後々利用するため保存
///*=========================================================================*/
///**
// * @brief パラメータを設定
// *
// * @param[in] desc サウンドパラメータ記述子.
// * @return なし.
// */
//void DirectSoundSocket::soundParameterDesc( const SoundParameterDesc& desc )
//{	
//	soundParameter_ = desc;
//
//	// バッファが作成されていない
//	if( buffer_ == NULL ){
//		return;
//	}
//
//	// ボリューム値を設定
//	buffer_->SetVolume( static_cast< LONG >( soundParameter_.volume ) );
//
//	// パンの値を設定
//	buffer_->SetPan( static_cast< LONG >( soundParameter_.pan ) );
//
//	// 3Dバッファが作成されていないか
//	if( buffer3D_ == NULL ){
//		return;
//	}
//
//	// 最小距離と最大距離を設定
//	buffer3D_->SetMinDistance( 1,		DS3D_IMMEDIATE );
//	buffer3D_->SetMaxDistance( 10000,	DS3D_IMMEDIATE );
//
//	// 音源の速度を設定( 40KM/h )
//	buffer3D_->SetVelocity( 0, 0, 40, DS3D_IMMEDIATE );
//
//	// 再生位置を設定
//	buffer3D_->SetPosition(
//		soundParameter_.soundPosition.x,
//		soundParameter_.soundPosition.y,
//		soundParameter_.soundPosition.z,
//		DS3D_IMMEDIATE
//		);
//
//	// リスナーオブジェクトが作成されていないか
//	if( listener3D_ == NULL ){
//		return;
//	}
//
//	// リスナーの位置を設定
//	listener3D_->SetPosition(
//		soundParameter_.listenerPosition.x,
//		soundParameter_.listenerPosition.y,
//		soundParameter_.listenerPosition.z,
//		DS3D_IMMEDIATE
//		);
//
//	// ドップラーのかかり具合を設定
//	listener3D_->SetDopplerFactor( 100, DS3D_IMMEDIATE );
//}
	
	
	
/*========= EOF =============================================================*/