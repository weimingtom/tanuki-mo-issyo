/*******************************************************************************/
/**
 * @file SoundDeviceManager.cpp.
 * 
 * @brief サウンドデバイス管理者クラスソースファイル.
 *
 * @date 2008/07/06.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimuara.
 */
/******************************************************************************/
#include	"Ngl/SoundDeviceManager.h"
#include	"Ngl/Manager/EntityVisitorMemFun1.h"
#include	"Ngl/Utility.h"
#include	<functional>
#include	<algorithm>
#include	<cassert>

using namespace Ngl;


/** 更新処理訪問者 */
typedef EntityVisitorMemFun1< ISoundDevice, float, &ISoundDevice::update >	UpdataVisitor;


/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
SoundDeviceManager::SoundDeviceManager()
{}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
SoundDeviceManager::~SoundDeviceManager()
{}



/*=========================================================================*/
/**
 * @brief デバイスを登録
 * 
 * @param[in] extName 登録する拡張子名( .は含まない ).
 * @param[in] device 登録するデバイスのポインタ.
 *
 * @return なし.
 */
void SoundDeviceManager::regist( std::string extName, ISoundDevice* device )
{
	assert( device != NULL );

	// すでに存在しているか
	if( isIndexExist( extName ) == true ){
		// デバイスを削除
		eraseDevice( extName );
	}

	// デバイスを登録
	soundDeviceContainer_.add( extName, device );
}



/*=========================================================================*/
/**
 * @brief 指定のデバイスを削除
 * 
 * @param[in] extName 削除する拡張子名( .は含まない ).
 *
 * @return なし.
 */
void SoundDeviceManager::eraseDevice( std::string extName )
{
	soundDeviceContainer_.remove( extName );
}
	
	

/*=========================================================================*/
/**
 * @brief 解放処理
 * 
 * @param[in] なし.
 * @return なし.
 */
void SoundDeviceManager::release()
{
	soundDeviceContainer_.clear();
}

	
	
/*=========================================================================*/
/**
 * @brief 更新処理
 * 
 * @param[in] frameTimer フレーム処理補正値.
 * @return なし.
 */
void SoundDeviceManager::update( float frameTimer )
{
	UpdataVisitor uv( frameTimer );
	soundDeviceContainer_.accept( uv );
}

	
	
/*=========================================================================*/
/**
 * @brief バッファを作成
 * 
 * @param[in] fileName ファイル名.
 * @param[in] bufNo バッファ番号.
 * @return なし.
 */
void SoundDeviceManager::createBuffer( const char* fileName, int bufNo )
{
	// 拡張子を抜き出す
	std::string ext = Utility::getFileExtension( fileName );

	// 登録された拡張しが存在するか
	bool result = isIndexExist( ext );
	assert( result == true );

	// 停止する
	stop( bufNo );

	// リストに登録
	soundDeviceContainer_[ ext ]->createBuffer( fileName, bufNo );
	playBufferList_[ bufNo ] = ext;
}

	
	
/*=========================================================================*/
/**
 * @brief 再生
 * 
 * @param[in] bufNo バッファ番号.
 * @param[in] playType 再生タイプ.
 * @return なし.
 */
void SoundDeviceManager::play( int bufNo, SoundPlayType playType )
{
	// バッファ番号を検索
	PlayBufferList::iterator itor = playBufferList_.find( bufNo );
	if( itor != playBufferList_.end() ){
		soundDeviceContainer_[ itor->second ]->play( bufNo, playType );
	}
}



/*=========================================================================*/
/**
 * @brief 再生を停止
 *
 * @param[in] bufNo バッファ番号.
 * @return なし.
 */
void SoundDeviceManager::stop( int bufNo )
{
	// バッファ番号を検索
	PlayBufferList::iterator itor = playBufferList_.find( bufNo );
	if( itor != playBufferList_.end() ){
		soundDeviceContainer_[ itor->second ]->stop( bufNo );
	}
}



/*=========================================================================*/
/**
 * @brief 一時停止
 * 
 * @param[in] bufNo バッファ番号.
 * @return なし.
 */
void SoundDeviceManager::pause( int bufNo )
{
	if( isPlaying( bufNo ) == false ){
		return;
	}

	soundDeviceContainer_[ playBufferList_[ bufNo ] ]->pause( bufNo );
}

	
	
/*=========================================================================*/
/**
 * @brief 再生中か
 * 
 * @param[in] bufNo 調べるバッファ番号.
 * @retval true 再生中.
 * @retval false 再生していない.
 */
bool SoundDeviceManager::isPlaying( int bufNo )
{
	if( playBufferList_.find( bufNo ) != playBufferList_.end() ){
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
void SoundDeviceManager::eraseBuffer( int bufNo )
{
	// バッファ番号を検索
	PlayBufferList::iterator itor = playBufferList_.find( bufNo );
	if( itor != playBufferList_.end() ){
		soundDeviceContainer_[ itor->second ]->eraseBuffer( bufNo );

		// バッファリストから削除
		playBufferList_.erase( itor );
	}
}


	
/*=========================================================================*/
/**
 * @brief 状態記述子を取得
 * 
 * @param[in] bufNo バッファ番号.
 * @return サウンド状態記述子.
 */
SoundStateDesc& SoundDeviceManager::soundState( int bufNo )
{
	return soundDeviceContainer_[ playBufferList_[ bufNo ] ]->soundState( bufNo );
}



/*=========================================================================*/
/**
 * @brief 再生位置を設定する
 * 
 * @param[in] time 設定する再生位置時間.
 * @param[in] bufNo バッファ番号.
 * @return なし.
 */
void SoundDeviceManager::setTime( float time, int bufNo )
{
	soundDeviceContainer_[ playBufferList_[ bufNo ] ]->setTime( time, bufNo );
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
void SoundDeviceManager::setVolume( unsigned int volume, int bufNo )
{
	soundDeviceContainer_[ playBufferList_[ bufNo ] ]->setVolume( volume, bufNo );
}



/*=========================================================================*/
/**
 * @brief 左右のボリューム比率を設定
 * 
 * @param[in] pan 設定するボリューム比率.
 * @param[in] bufNo バッファ番号.
 * @return なし.
 */
void SoundDeviceManager::setPan( int pan, int bufNo )
{
	soundDeviceContainer_[ playBufferList_[ bufNo ] ]->setPan( pan, bufNo );
}



/*=========================================================================*/
/**
 * @brief 指定の要素がすでに存在しているか調べる
 *
 * @@aram[in] index 調べるインデックス名.
 * @retval true 存在している.
 * @retval false 存在していない.
 */
bool SoundDeviceManager::isIndexExist( std::string& index )
{
	return soundDeviceContainer_.isExist( index );
}
	
	

/*===== EOF ==================================================================*/