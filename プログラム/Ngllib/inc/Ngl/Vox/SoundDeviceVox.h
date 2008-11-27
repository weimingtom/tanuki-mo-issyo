/*******************************************************************************/
/**
 * @file SoundDeviceVox.h.
 * 
 * @brief Vox サウンドデバイスクラスヘッダファイル.
 * @brief ogg形式のファイルが再生可能。
 * @brief Panの設定機能はありません。
 *
 * @date 2008/07/07.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_VOX_OGGRESOURCEVOX_H_
#define _NGL_VOX_OGGRESOURCEVOX_H_

#include	"Vox/Vox.h"
#include	"Ngl/ISoundDevice.h"
#include	"Ngl/ISoundResource.h"
#include	<windows.h>
#include	<map>

namespace Ngl{


namespace Vox{


/** Voxバッファ番号型 */
typedef int VoxBufferNo;


/**
 * @struct VoxPlayState.
 * @brief Vox 再生状態構造体
 */
enum VoxPlayState
{
	VOXPLAYSTATE_PLAY	= 0,	/**< 再生中		*/
	VOXPLAYSTATE_PAUSE,			/**< 一時停止中	*/
	VOXPLAYSTATE_STOP			/**< 停止中		*/
};


/**
 * @class SoundDeviceVox.
 * @brief Vox サウンドデバイスクラス.
 */
class SoundDeviceVox : public ISoundDevice
{
public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] : なし.
	 */
	SoundDeviceVox();


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] : なし.
	 */
	~SoundDeviceVox();


	/*=========================================================================*/
	/**
	 * @brief 更新処理
	 * 
	 * @param[in] frameTimer フレーム処理補正値.
	 * @return なし.
	 */
	virtual void update( float frameTimer );
	
	
	/*=========================================================================*/
	/**
	 * @brief バッファを作成
	 * 
	 * @param[in] fileName ファイル名.
	 * @param[in] bufNo バッファ番号.
	 * @return なし.
	 */
	virtual void createBuffer( const char* fileName, int bufNo=BGM_BUFFER );
	
	
	/*=========================================================================*/
	/**
	 * @brief 再生
	 * 
	 * @param[in] bufNo バッファ番号.
	 * @param[in] playType 再生タイプ.
	 * @return なし.
	 */
	virtual void play( int bufNo=BGM_BUFFER, SoundPlayType playType=SOUNDPLAYTYPE_NORMAL ) ;


	/*=========================================================================*/
	/**
	 * @brief 一時停止
	 * 
	 * @param[in] bufNo バッファ番号.
	 * @return なし.
	 */
	virtual void pause( int bufNo=BGM_BUFFER );
	
	
	/*=========================================================================*/
	/**
	 * @brief 再生を停止
	 *
	 * @param[in] bufNo バッファ番号.
	 * @return なし.
	 */
	virtual void stop( int bufNo=BGM_BUFFER ) ;

	
	/*=========================================================================*/
	/**
	 * @brief 再生中か
	 * 
	 * @param[in] bufNo バッファ番号.
	 * @retval true 再生中.
	 * @retval false 再生していない.
	 */
	virtual bool isPlaying( int bufNo=BGM_BUFFER ) ;
	
	
	/*=========================================================================*/
	/**
	 * @brief バッファを削除
	 *
	 * @param[in] bufNo バッファ番号.
	 * @return なし.
	 */
	virtual void eraseBuffer( int bufNo=BGM_BUFFER );
	
	
	/*=========================================================================*/
	/**
	 * @brief 状態記述子を取得
	 * 
	 * @param[in] bufNo バッファ番号.
	 * @return サウンド状態記述子.
	 */
	virtual SoundStateDesc& soundState( int bufNo=BGM_BUFFER );
		
	
	/*=========================================================================*/
	/**
	 * @brief 再生位置を設定する
	 * 
	 * @param[in] time 設定する再生位置時間.
	 * @param[in] bufNo バッファ番号.
	 * @return なし.
	 */
	virtual void setTime( float time, int bufNo=BGM_BUFFER );

	
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
	virtual void setVolume( unsigned int volume, int bufNo=BGM_BUFFER );
	
	
	/*=========================================================================*/
	/**
	 * @brief 左右のボリューム比率を設定
	 * 
	 * @param[in] pan 設定するボリューム比率.
	 * @param[in] bufNo バッファ番号.
	 * @return なし.
	 */
	virtual void setPan( int pan, int bufNo=BGM_BUFFER );

private:

	/*=========================================================================*/
	/**
	 * @brief Voxバッファ作成処理
	 * 
	 * @param[in] fileName ファイル名前.
	 * @return 作成したＩＤ.
	 */
	VoxBufferNo create( const char* fileName );


	/*=========================================================================*/
	/**
	 * @brief 消滅させる
	 * 
	 * @param[in] id voxID.
	 * @return なし.
	 */
	void release( VoxBufferNo id );


	/*=========================================================================*/
	/**
	 * @brief バッファが存在しているか
	 * 
	 * @param[in] bufNo バッファ番号.
	 * @return なし.
	 */
	bool isExistBuffer( int bufNo );

private:

	/**
	 * @struct VoxState.
	 * @brief Vox 状態構造体.
	 */
	struct VoxState
	{
		/** バッファ番号	*/
		VoxBufferNo		bufferNo;

		/** 再生状態フラグ	*/
		VoxPlayState	playState;

		/** サウンド状態構造体 */
		SoundStateDesc	stateDesc;
	};

private:

	/** サウンド状態リスト型 */
	typedef std::map< int, VoxState >	SoundStateList;

private:

	/** DLLインスタンス */
	HINSTANCE			mHDll;

	/** VoxLoad関数ポインタ */
	VoxLoad*			pVoxLoad;

	/** VoxPlay関数ポインタ */
	VoxPlay*			pVoxPlay;

	/** VoxPause関数ポインタ */
	VoxPause*			pVoxPause;

	/** VoxRelease関数ポインタ */
	VoxRelease*			pVoxRelease;

	/** VoxSetLoop関数ポインタ */
	VoxSetLoop*			pVoxSetLoop;

	/** VoxCheckDevice関数ポインタ */
	VoxCheckDevice*		pVoxCheckDevice;

	/** VoxSetVolume関数ポインタ */
	VoxSetVolume*		pVoxSetVolume;

	/** VoxGetVolume関数ポインタ */
	VoxGetVolume*		pVoxGetVolume;

	/** VoxFade関数ポインタ */
	VoxFade*			pVoxFade;

	/** VoxDelete関数ポインタ */
	VoxDelete*			pVoxDelete;

	/** VoxGetTitalTime関数ポインタ */
	VoxGetTotalTime*	 pVoxGetTotalTime;

	/** VoxGetCurrentTime関数ポインタ */
	VoxGetCurrentTime*	pVoxGetCurrentTime;

	/** VoxSeek関数ポインタ */
	VoxSeek*			pVoxSeek;

	/** VoxGetStatus関数ポインタ */
	VoxGetStatus*		pVoxGetStatus;

	/** VoxGetComment関数ポインタ */
	VoxGetComment*		pVoxGetComment;

	/** VoxParseComment関数ポインタ */
	VoxParseComment*	pVoxParseComment;

	/** サウンド状態リスト */
	SoundStateList		soundStateList_;

};

}	// namespace Vox

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/