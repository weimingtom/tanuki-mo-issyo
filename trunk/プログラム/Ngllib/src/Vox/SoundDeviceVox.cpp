/*******************************************************************************/
/**
 * @file SoundDeviceVox.cpp.
 * 
 * @brief Voxサウンドデバイスクラスソースファイル.
 *
 * @date 2008/07/07.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Vox/SoundDeviceVox.h"
#include	<cassert>

using namespace Ngl;
using namespace Ngl::Vox;


/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] : なし.
 */
SoundDeviceVox::SoundDeviceVox():
	mHDll( NULL ),
	pVoxLoad( NULL ),
	pVoxPlay( NULL ),
	pVoxPause( NULL ),
	pVoxRelease( NULL ),
	pVoxCheckDevice( NULL ),
	pVoxSetVolume( NULL ),
	pVoxGetVolume( NULL ),
	pVoxFade( NULL ),
	pVoxDelete( NULL ),
	pVoxGetTotalTime( NULL ),
	pVoxGetCurrentTime( NULL ),
	pVoxSeek( NULL ),
	pVoxGetStatus( NULL ),
	pVoxGetComment( NULL ),
	pVoxParseComment( NULL )
{

	// DLLから関数ポインタをロード
#ifdef _DEBUG
	mHDll = LoadLibraryA( "Vox_d.dll" );
#else
	mHDll = LoadLibraryA( "Vox.dll" );
#endif
	pVoxLoad			= (VoxLoad*)GetProcAddress( mHDll, "VoxLoad" );
	pVoxPlay			= (VoxPlay*)GetProcAddress( mHDll, "VoxPlay" );
	pVoxRelease			= (VoxRelease*)GetProcAddress( mHDll, "VoxRelease" );
	pVoxDelete			= (VoxDelete*)GetProcAddress( mHDll, "VoxDelete" );
	pVoxPause			= (VoxPause*)GetProcAddress( mHDll, "VoxPause" );
	pVoxSetLoop			= (VoxSetLoop*)GetProcAddress( mHDll, "VoxSetLoop" );
	pVoxCheckDevice		= (VoxCheckDevice*)GetProcAddress( mHDll, "VoxCheckDevice" );
	pVoxSetVolume		= (VoxSetVolume*)GetProcAddress( mHDll, "VoxSetVolume" );
	pVoxGetVolume		= (VoxGetVolume*)GetProcAddress( mHDll, "VoxGetVolume" );
	pVoxFade			= (VoxFade*)GetProcAddress( mHDll, "VoxFade" );
	pVoxDelete			= (VoxDelete*)GetProcAddress( mHDll, "VoxDelete");
	pVoxGetTotalTime	= (VoxGetTotalTime*)GetProcAddress( mHDll, "VoxGetTotalTime" );
	pVoxGetCurrentTime	= (VoxGetCurrentTime*)GetProcAddress( mHDll, "VoxGetCurrentTime" );
	pVoxSeek			= (VoxSeek*)GetProcAddress( mHDll, "VoxSeek" );
	pVoxGetStatus		= (VoxGetStatus*)GetProcAddress( mHDll, "VoxGetStatus" );
	pVoxGetComment		= (VoxGetComment*)GetProcAddress( mHDll, "VoxGetComment" );
	pVoxParseComment	= (VoxParseComment*)GetProcAddress( mHDll, "VoxParseComment" );

	// dllの読み込みに失敗したか
	assert( mHDll != 0 );
	
}



/*===========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] : なし.
 */
SoundDeviceVox::~SoundDeviceVox()
{
	// バッファをすべて削除
	SoundStateList::iterator itor = soundStateList_.begin();
	for( ; itor!=soundStateList_.end(); ++itor ){
		release( itor->second.bufferNo );
	}

	if( mHDll != 0 ){
		// 関数ポインタをクリア
		pVoxLoad			= 0;
		pVoxPlay			= 0;
		pVoxRelease			= 0;
		pVoxDelete			= 0;
		pVoxPause			= 0;
		pVoxSetLoop			= 0;
		pVoxCheckDevice		= 0;
		pVoxSetVolume		= 0;
		pVoxGetVolume		= 0;
		pVoxFade			= 0;
		pVoxDelete			= 0;
		pVoxGetTotalTime	= 0;
		pVoxGetCurrentTime	= 0;
		pVoxSeek			= 0;
		pVoxGetStatus		= 0;
		pVoxGetComment		= 0;
		pVoxParseComment	= 0;

		// DLLを開放
		FreeLibrary( mHDll );
		mHDll = 0;
	}
}



/*=========================================================================*/
/**
 * @brief 更新処理
 * 
 * @param[in] frameTimer フレーム処理補正値.
 * @return なし.
 */
void SoundDeviceVox::update( float frameTimer )
{
	SoundStateList::iterator itor;
	for( itor=soundStateList_.begin(); itor!=soundStateList_.end(); ++itor ){
		// ポーズ状態か
		if( itor->second.playState == VOXPLAYSTATE_PAUSE ){
			pause( itor->first );
		}

		// 停止状態か
		if( itor->second.playState == VOXPLAYSTATE_STOP ){
			stop( itor->first );
		}
	}
}

	
	
/*=========================================================================*/
/**
 * @brief バッファを作成
 * 
 * @param[in] fileName ファイル名.
 * @param[in] bufNo バッファ番号.
 * @return なし.
 */
void SoundDeviceVox::createBuffer( const char* fileName, int bufNo )
{
	// バッファを作成
	VoxBufferNo no = create( fileName );

	// 初期状態を設定
	VoxState state;
	state.bufferNo	= no;
	state.playState	= VOXPLAYSTATE_STOP;
	state.stateDesc = SOUNDSTATEDESC_DEFAULT;

	// 再生バッファに登録
	soundStateList_[ bufNo ] = state;
}



/*=========================================================================*/
/**
 * @brief 再生
 * 
 * @param[in] bufNo バッファ番号.
 * @param[in] playType 再生タイプ.
 * @return なし.
 */
void SoundDeviceVox::play( int bufNo, SoundPlayType playType )
{
	// バッファが存在していないか
	if( isExistBuffer( bufNo ) == false ){
		return;
	}

	// 再生タイプを設定
	soundStateList_[ bufNo ].stateDesc.type = playType;

	// 再生位置を設定
	pVoxSeek( soundStateList_[ bufNo ].bufferNo, (int)soundStateList_[ bufNo ].stateDesc.currentTime );

	// ループするか
	if( playType == SOUNDPLAYTYPE_LOOP ){
		// ループ状態に設定
		pVoxSetLoop( soundStateList_[ bufNo ].bufferNo, 65535 );
	}
	else{
		pVoxSetLoop( soundStateList_[ bufNo ].bufferNo, 0 );
	}

	// 再生状態に設定
	soundStateList_[ bufNo ].playState = VOXPLAYSTATE_PLAY;

	// 再生
	pVoxPlay( soundStateList_[ bufNo ].bufferNo );
}



/*=========================================================================*/
/**
 * @brief 一時停止
 * 
 * @param[in] bufNo バッファ番号.
 * @return なし.
 */
void SoundDeviceVox::pause( int bufNo )
{
	// バッファが存在するか
	if( isExistBuffer( bufNo ) == false ){
		return;
	}

	// 現在の時間を保存
	soundStateList_[ bufNo ].stateDesc.currentTime = static_cast< float >( pVoxGetCurrentTime( soundStateList_[ bufNo ].bufferNo ) );

	// 再生状態に設定
	soundStateList_[ bufNo ].playState = VOXPLAYSTATE_PAUSE;

	// 再生を一時停止
	pVoxPause( soundStateList_[ bufNo ].bufferNo );
}



/*=========================================================================*/
/**
 * @brief 再生を停止
 *
 * @param[in] bufNo バッファ番号.
 * @return なし.
 */
void SoundDeviceVox::stop( int bufNo )
{
	// バッファが存在するか
	if( isExistBuffer( bufNo ) == false ){
		return;
	}

	// 停止状態に設定
	soundStateList_[ bufNo ].playState = VOXPLAYSTATE_STOP;

	// 再生タイプをノーマルに設定
	soundStateList_[ bufNo ].stateDesc.type = SOUNDPLAYTYPE_NORMAL;

	// 現在の時間を保存
	soundStateList_[ bufNo ].stateDesc.currentTime = 0;

	// 再生を停止
	pVoxSeek( soundStateList_[ bufNo ].bufferNo, 0 );
	pVoxPause( soundStateList_[ bufNo ].bufferNo );
}



/*=========================================================================*/
/**
 * @brief 再生中か
 * 
 * @param[in] bufNo バッファ番号.
 * @retval true 再生中.
 * @retval false 再生していない.
 */
bool SoundDeviceVox::isPlaying( int bufNo )
{
	// バッファに存在していないか
	if( isExistBuffer( bufNo ) == false ){
		return false;
	}

	// 状態を取得する
	VOXSTATE state = static_cast< VOXSTATE >( pVoxGetStatus( soundStateList_[ bufNo ].bufferNo ) );

	// 再生中か
	if( state == STATE_PLAYING ){
		return true;
	}

	return false;
}



/*=========================================================================*/
/**
 * @brief バッファを削除
 *
 * @param[in] bufNo バッファ番号.
 * @return なし.
 */
void SoundDeviceVox::eraseBuffer( int bufNo )
{
	release( soundStateList_[ bufNo ].bufferNo );

	// バッファを削除
	soundStateList_.erase( bufNo );
}
	
	
	
/*=========================================================================*/
/**
 * @brief 状態記述子を取得
 * 
 * @param[in] bufNo バッファ番号.
 * @return サウンド状態記述子.
 */
SoundStateDesc& SoundDeviceVox::soundState( int bufNo )
{
	// サウンド状態記述子を取得
	SoundStateDesc& desc = soundStateList_[ bufNo ].stateDesc;

	// Voxのバッファ番号を取得
	VoxBufferNo buf = soundStateList_[ bufNo ].bufferNo;

	// ボリュームを設定
	desc.volume = static_cast< unsigned int >( pVoxGetVolume( buf ) * 100.0f );

	// 現在の再生位置を設定
	desc.currentTime = static_cast< float >( pVoxGetCurrentTime( buf ) );

	// 終了位置を設定
	desc.endTime = static_cast< float >( pVoxGetTotalTime( buf ) );

	// 相対ボリュームを設定（機能がないのでデフォルト)
	desc.pan = 0;

	return desc;
}



/*=========================================================================*/
/**
 * @brief 再生位置を設定する
 * 
 * @param[in] time 設定する再生位置時間.
 * @param[in] bufNo バッファ番号.
 * @return なし.
 */
void SoundDeviceVox::setTime( float time, int bufNo )
{
	soundStateList_[ bufNo ].stateDesc.currentTime = time;

	pVoxSeek( soundStateList_[ bufNo ].bufferNo, static_cast< int >( time ) );
}



/*=========================================================================*/
/**
 * @brief ボリュームの設定
 * 
 * 最大値 100( SOUND_VOLUME_MAX )
 * 最小値 0  ( SOUND_VOLUME_MIN )
 *
 * @param[in] volume 設定するボリューム.
 * @param[in] bufNo バッファ番号.
 * @return なし.
 */
void SoundDeviceVox::setVolume( unsigned int volume, int bufNo )
{
	soundStateList_[ bufNo ].stateDesc.volume = volume;
	
	// ボリューム比率を求める
	float vol = static_cast< float >( volume ) / static_cast< float >( SOUND_VOLUME_MAX );

	pVoxSetVolume( soundStateList_[ bufNo ].bufferNo, vol );
}



/*=========================================================================*/
/**
 * @brief 左右のボリューム比率を設定
 * 
 * @param[in] pan 設定するボリューム比率.
 * @param[in] bufNo バッファ番号.
 * @return なし.
 */
void SoundDeviceVox::setPan( int pan, int bufNo )
{
	// 機能がないため実装なし
}

	
	
/*===========================================================================*/
/**
 * @brief Voxバッファ作成処理
 * 
 * @param[in] fileName ファイル名前.
 * @return 作成したＩＤ.
 */
VoxBufferNo SoundDeviceVox::create( const char* fileName )
{
	// constをキャストで解除
	char* fn = const_cast< char* >( fileName );

	// ファイルを読み込む
	VoxBufferNo bufNo = pVoxLoad( fn );

	// 作成したＩＤを返す
	return bufNo;
}



/*===========================================================================*/
/**
 * @brief 消滅させる
 * 
 * @param[in] id voxID.
 * @return なし.
 */
void SoundDeviceVox::release( VoxBufferNo id )
{
	// voxオブジェクトを開放
	pVoxRelease( id );
	pVoxDelete( id );
}



/*=========================================================================*/
/**
 * @brief バッファが存在しているか
 * 
 * @param[in] bufNo バッファ番号.
 * @return なし.
 */
bool SoundDeviceVox::isExistBuffer( int bufNo )
{
	SoundStateList::iterator itor = soundStateList_.find( bufNo );
	if( itor != soundStateList_.end() ){
		return true;
	}

	return false;
}


	
/*========= EOF =============================================================*/