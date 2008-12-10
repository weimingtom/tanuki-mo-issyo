/*******************************************************************************/
/**
 * @file ISoundResource.h.
 * 
 * @brief サウンドリソースインターフェースクラス定義.
 *
 * @date 2007/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ISOUNDRESOURCE_H_
#define _NGL_ISOUNDRESOURCE_H_

#include	"ISoundDevice.h"
#include	"SoundStateDesc.h"

namespace Ngl{


/**
 * @interface ISoundResource．
 * @brief サウンドリソースインターフェース.
 */
class ISoundResource
{

public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~ISoundResource() {}


	/*=========================================================================*/
	/**
	 * @brief 再生する
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void play() = 0;


	/*=========================================================================*/
	/**
	 * @brief 再生中か調べる
	 * 
	 * @param[in] なし.
	 * @retval true 再生中.
	 * @retval false 停止中.
	 */
	virtual bool isPlay() = 0;


	/*=========================================================================*/
	/**
	 * @brief 一時停止
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void pause() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 停止する
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void stop() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 状態記述子を取得
	 * 
	 * @param[in] なし.
	 * @return サウンド状態記述子.
	 */
	virtual SoundStateDesc& soundState() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 曲の再生タイプを設定
	 * 
	 * @param[in] type 再生タイプ.
	 * @return なし.
	 */
	virtual void setType( SoundPlayType type ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 再生位置を設定する
	 * 
	 * @param[in] time 設定する再生位置時間( ミリ秒 ).
	 * @return なし.
	 */
	virtual void setTime( float time ) = 0;

	
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
	virtual void setPan( int pan ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/