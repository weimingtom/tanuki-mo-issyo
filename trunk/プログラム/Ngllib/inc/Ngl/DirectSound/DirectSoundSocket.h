/*******************************************************************************/
/**
 * @file DirectSoundSocket.h.
 * 
 * @brief DirectSound ソケットクラスヘッダファイル.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DIRECTSOUND_DIRECTSOUNDSOCKET_H_
#define _NGL_DIRECTSOUND_DIRECTSOUNDSOCKET_H_

#include	"IDirectSoundResource.h"
#include	"Ngl/ISoundDevice.h"
#include	"Ngl/ISoundResource.h"
#include	"DirectSound.h"


namespace Ngl{


namespace DirectSound{


/**
 * @class DirectSoundSocket
 * @brief DirectSound ソケットクラス．
 */
class DirectSoundSocket : public ISoundResource
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	DirectSoundSocket();


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~DirectSoundSocket();


	/*=========================================================================*/
	/**
	 * @brief 作成する
	 * 
	 * @param[in] fileName ファイル名.
	 * @param[in] ds ダイレクトサウンドオブジェクト.
	 * @param[in] rg リソースクラスのポインタ.
	 * @retval true 作成成功.
	 * @retval false 作成失敗.
	 */
	bool create( const char* fileName, IDirectSound8* ds, IDirectSoundResource* rg );


	/*=========================================================================*/
	/**
	 * @brief 消滅させる
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void release();


	/*=========================================================================*/
	/**
	 * @brief 再生する
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void play();


	/*=========================================================================*/
	/**
	 * @brief 再生中か調べる
	 * 
	 * @param[in] なし.
	 * @retval true 再生中.
	 * @retval false 停止中.
	 */
	virtual bool isPlay();


	/*=========================================================================*/
	/**
	 * @brief 一時停止
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void pause();
	
	
	/*=========================================================================*/
	/**
	 * @brief 停止する
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void stop();
	
	
	/*=========================================================================*/
	/**
	 * @brief 状態記述子を取得
	 * 
	 * @param[in] なし.
	 * @return サウンド状態記述子.
	 */
	virtual SoundStateDesc& soundState();
	
	
	/*=========================================================================*/
	/**
	 * @brief 曲の再生タイプを設定
	 * 
	 * @param[in] type 再生タイプ.
	 * @return なし.
	 */
	virtual void setType( SoundPlayType type );
	
	
	/*=========================================================================*/
	/**
	 * @brief 再生位置を設定する
	 * 
	 * @param[in] time 設定する再生位置時間( ミリ秒 ).
	 * @return なし.
	 */
	virtual void setTime( float time );

	
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
	virtual void setVolume( unsigned int volume );
	
	
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
	virtual void setPan( int pan );
	
private:

	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ (コピー禁止)
	 * 
	 * @param[in] other コピーするオブジェクト.
	 */
	DirectSoundSocket( const DirectSoundSocket& other );


	/*=========================================================================*/
	/**
	 * @brief = 演算子オーバーロード (コピー禁止)
	 * 
	 * @param[in] other コピー元のオブジェクト.
	 * @return コピー結果のオブジェクト.
	 */
	DirectSoundSocket& operator = ( const DirectSoundSocket& other );

private:
	
	/** ダイレクトサウンドオブジェクト */
	IDirectSoundBuffer*		buffer_;

	/** ダイレクト３Dサウンドオブジェクト */
	IDirectSound3DBuffer*	buffer3D_;

	/** ダイレクト３Dリスナーオブジェクト */
	IDirectSound3DListener*	listener3D_;

	/** waveファイルフォーマット */
	WAVEFORMATEX*			waveFormat_;

	/** waveデータサイズ */
	unsigned long			waveDataSize_;

	/** サウンド状態記述子 */
	SoundStateDesc			soundState_;
};

}	// namespace DirectSound

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/