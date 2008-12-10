/*******************************************************************************/
/**
 * @file SoundDeviceBase.cpp.
 * 
 * @brief サウンドデバイス基底クラスソースファイル.
 *
 * @date 2008/07/19.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/SoundDeviceBase.h"
#include	<cassert>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
SoundDeviceBase::SoundDeviceBase()
{}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
SoundDeviceBase::~SoundDeviceBase()
{
	clearBuffer();
}



/*=========================================================================*/
/**
 * @brief 更新処理
 * 
 * @param[in] frameTimer フレーム処理補正値.
 * @return なし.
 */
void SoundDeviceBase::update( float frameTimer )
{
	SoundList::iterator itor;
	for( itor=soundList_.begin(); itor!=soundList_.end(); ++itor ){
		// ループ指定か
		ISoundResource* res = itor->second;
		if( res->soundState().type == SOUNDPLAYTYPE_LOOP ){
			// 再生が終了しているか
			if( res->isPlay() == false ){
				// 再生位置を初期化
				res->setTime( 0 );

				// 再生を開始
				res->play();
			}
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
void SoundDeviceBase::createBuffer( const char* fileName, int bufNo )
{
	// バッファが存在しているか
	if( isBufferExist( bufNo ) ){
		// バッファをクリア
		releaseBuffer( bufNo );
	}

	// リソースを作成
	ISoundResource* res = create( fileName );
	assert( res != NULL );

	// サウンドリストに登録
	soundList_[ bufNo ] = res;
}



/*=========================================================================*/
/**
 * @brief 再生
 * 
 * @param[in] bufNo バッファ番号.
 * @param[in] playType 再生タイプ.
 * @return なし.
 */
void SoundDeviceBase::play( int bufNo, SoundPlayType playType )
{
	// オブジェクトの再生方法を設定
	soundList_[bufNo]->setType( playType );

	// 再生する
	soundList_[bufNo]->play();
}



/*=========================================================================*/
/**
 * @brief 一時停止
 * 
 * @param[in] bufNo バッファ番号.
 * @return なし.
 */
void SoundDeviceBase::pause( int bufNo )
{
	// バッファが存在していないか
	if( isBufferExist( bufNo ) == false ){
		return;
	}

	// 再生中か
	if( soundList_[ bufNo ]->isPlay() == false ){
		return;
	}

	soundList_[ bufNo ]->pause();
}



/*=========================================================================*/
/**
 * @brief 再生を停止
 *
 * @param[in] bufNo バッファ番号.
 * @return なし.
 */
void SoundDeviceBase::stop( int bufNo )
{
	// バッファが存在していないか
	if( isBufferExist( bufNo ) == false ){
		return;
	}

	ISoundResource* res = soundList_[ bufNo ];

	// 再生待ち指定か
	if( res->soundState().type == SOUNDPLAYTYPE_WAIT ){
		// 再生が終了していない
		if( res->isPlay() == false ){
			return;
		}
	}

	// 再生タイプをデフォルトに再設定
	res->setType( SOUNDPLAYTYPE_NORMAL );

	// 再生を停止する
	soundList_[ bufNo ]->stop();
}



/*=========================================================================*/
/**
 * @brief 再生中か
 * 
 * @param[in] bufNo バッファ番号.
 * @retval true 再生中.
 * @retval false 再生していない.
 */
bool SoundDeviceBase::isPlaying( int bufNo )
{
	return soundList_[ bufNo ]->isPlay();
}



/*=========================================================================*/
/**
 * @brief バッファを削除
 *
 * @param[in] bufNo バッファ番号.
 * @return なし.
 */
void SoundDeviceBase::eraseBuffer( int bufNo )
{
	// バッファが存在していないか
	if( isBufferExist( bufNo ) == false ){
		return;
	}

	// 再生中か
	if( soundList_[ bufNo ]->isPlay() == false ){
		// 再生を停止
		stop( bufNo );
	}

	// バッファを開放する
	releaseBuffer( bufNo );
}



/*=========================================================================*/
/**
 * @brief 状態記述子を取得
 * 
 * @param[in] bufNo バッファ番号.
 * @return サウンド状態記述子.
 */
SoundStateDesc& SoundDeviceBase::soundState( int bufNo )
{
	return soundList_[ bufNo ]->soundState();
}



/*=========================================================================*/
/**
 * @brief 再生位置を設定する
 * 
 * @param[in] time 設定する再生位置時間.
 * @param[in] bufNo バッファ番号.
 * @return なし.
 */
void SoundDeviceBase::setTime( float time, int bufNo )
{
	soundList_[ bufNo ]->setTime( time );
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
void SoundDeviceBase::setVolume( unsigned int volume, int bufNo )
{
	soundList_[ bufNo ]->setVolume( volume );
}



/*=========================================================================*/
/**
 * @brief 左右のボリューム比率を設定
 * 
 * @param[in] pan 設定するボリューム比率.
 * @param[in] bufNo バッファ番号.
 * @return なし.
 */
void SoundDeviceBase::setPan( int pan, int bufNo )
{
	soundList_[ bufNo ]->setPan( pan );
}



/*===========================================================================*/
/**
 * @brief 指定のバッファが存在しているか調べる
 * 
 * @param[in] bufNo バッファ番号.
 * @retval true 存在している.
 * @retval false 存在していない.
 */
bool SoundDeviceBase::isBufferExist(int bufNo)
{
	SoundList::iterator itor;
	for( itor=soundList_.begin(); itor!=soundList_.end(); ++itor ){
		if( itor->first == bufNo ){
			return true;
		}
	}

	// 存在していない
	return false;
}



/*===========================================================================*/
/**
 * @brief 指定のバッファを解放する
 * 
 * @param[in] bufNo バッファ番号.
 * @retval true 削除成功.
 * @retval false 削除失敗.
 */
bool SoundDeviceBase::releaseBuffer(int bufNo)
{
	// リストの全要素を検索する
	SoundList::iterator i = soundList_.find( bufNo );

	// 末尾までたどり着いた
	if( i == soundList_.end() ){
		// バッファが存在しない
		return false;
	}

	// 再生を停止する
	i->second->stop();

	// 要素を削除する
	delete i->second;

	// リストから削除する
	i = soundList_.erase( i );

	// 削除成功
	return true;

}



/*=========================================================================*/
/**
 * @brief バッファをすべて解放する
 * 
 * @param[in] なし.
 * @return なし.
 */
void SoundDeviceBase::clearBuffer()
{
	// リストの全要素を削除する
	SoundList::iterator i = soundList_.begin();
	while( i != soundList_.end() ){
		// 再生中か
		if( i->second->isPlay() == true ){
			// 再生を停止する
			i->second->stop();
		}
		
		// 要素を削除する
		delete i->second;

		// リストから削除する
		i = soundList_.erase( i );
	}
}
	
	
	
/*===== EOF ==================================================================*/