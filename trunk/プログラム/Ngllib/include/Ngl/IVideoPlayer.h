/*******************************************************************************/
/**
 * @file IVideoPlayer.h.
 * 
 * @brief ビデオプレイヤーインターフェース定義.
 *
 * @date 2008/07/30.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IVIDEOPLAYER_H_
#define _NGL_IVIDEOPLAYER_H_


namespace Ngl{


static const unsigned int VIDEO_VOLUME_MIN	= 0;	/**< ボリュームの最小値				*/
static const unsigned int VIDEO_VOLUME_MAX	= 100;	/**< ボリュームの最大値				*/

/**
 * @interface IVideoPlayer．
 * @brief ビデオプレイヤーインターフェース.
 */
class IVideoPlayer
{

public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IVideoPlayer() {}


	/*=========================================================================*/
	/**
	 * @brief ムービーの高さを取得
	 * 
	 * @param[in] なし.
	 * @return ムービーの高さ.
	 */
	virtual int getImageHeight() const = 0;


	/*=========================================================================*/
	/**
	 * @brief ムービーの幅を取得
	 * 
	 * @param[in] なし.
	 * @return ムービーの幅.
	 */
	virtual int getImageWidth() const = 0;

	
	/*=========================================================================*/
	/**
	 * @brief ムービーのイメージをロックする
	 * 
	 * @param[in] なし.
	 * @return ロックしたビデオメモリ.
	 */
	virtual void* lockImage() = 0;


	/*=========================================================================*/
	/**
	 * @brief ムービーのイメージをアンロックする
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void unlockImage() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief ムービーの再生
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void play() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief ムービーの停止
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void stop() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief 再生スピードの変更
	 * 
	 * @param[in] time 設定するスピード.
	 * @return なし.
	 */
	virtual void setSpeed( float time ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 現在の再生位置を指定位置にセット
	 * 
	 * @param[in] time 設定する再生位置時間.
	 * @return なし.
	 */
	virtual void setTime( float time ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief 再生終了時間を取得する
	 * 
	 * @param[in] なし.
	 * @return 終了時間.
	 */
	virtual float getStopTime() const = 0;

	
	/*=========================================================================*/
	/**
	 * @brief ストリームの時間幅の取得
	 * 
	 * @param[in] なし.
	 * @return 時間幅.
	 */
	virtual float getDuration() const = 0;

	
	/*=========================================================================*/
	/**
	 * @brief 現在の再生位置の取得
	 * 
	 * @param[in] なし.
	 * @return 現在の再生位置.
	 */
	virtual float getCurrentPosition() const = 0;

	
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
	virtual void setVolume( unsigned int volume ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/