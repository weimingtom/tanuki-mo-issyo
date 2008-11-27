/*******************************************************************************/
/**
 * @file ISoundDevice.h.
 * 
 * @brief サウンドデバイスインターフェース定義.
 *
 * @date 2008/07/05.
 * 
 * @version 1.01.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ISOUNDDEVICE_H_
#define _NGL_ISOUNDDEVICE_H_

#include	"Ngl/SoundStateDesc.h"

namespace Ngl{


/** BGMのバッファ番号 */
static const int BGM_BUFFER = -1;


/**
 * @interface ISoundDevice．
 * @brief サウンドデバイスインターフェース.
 *
 * バッファ番号について
 * -1	BGM用バッファ( BGM_BUFFER )
 * 0～	SE用バッファ
 * 独自にバッファの割り当てをしても問題ありません。
 */
class ISoundDevice
{
	
public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~ISoundDevice() {}


	/*=========================================================================*/
	/**
	 * @brief 更新処理
	 * 
	 * @param[in] frameTimer フレーム処理補正値.
	 * @return なし.
	 */
	virtual void update( float frameTimer ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief バッファを作成
	 * 
	 * @param[in] fileName ファイル名.
	 * @param[in] bufNo バッファ番号.
	 * @return なし.
	 */
	virtual void createBuffer( const char* fileName, int bufNo=BGM_BUFFER ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 再生
	 * 
	 * @param[in] bufNo バッファ番号.
	 * @param[in] playType 再生タイプ.
	 * @return なし.
	 */
	virtual void play( int bufNo=BGM_BUFFER, SoundPlayType playType=SOUNDPLAYTYPE_NORMAL ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 一時停止
	 * 
	 * @param[in] bufNo バッファ番号.
	 * @return なし.
	 */
	virtual void pause( int bufNo=BGM_BUFFER ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 再生を停止
	 *
	 * @param[in] bufNo バッファ番号.
	 * @return なし.
	 */
	virtual void stop( int bufNo=BGM_BUFFER ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief 再生中か
	 * 
	 * @param[in] bufNo バッファ番号.
	 * @retval true 再生中.
	 * @retval false 再生していない.
	 */
	virtual bool isPlaying( int bufNo=BGM_BUFFER ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief バッファを削除
	 *
	 * @param[in] bufNo バッファ番号.
	 * @return なし.
	 */
	virtual void eraseBuffer( int bufNo=BGM_BUFFER ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 状態記述子を取得
	 * 
	 * @param[in] bufNo バッファ番号.
	 * @return サウンド状態記述子.
	 */
	virtual SoundStateDesc& soundState( int bufNo=BGM_BUFFER ) = 0;
		
	
	/*=========================================================================*/
	/**
	 * @brief 再生位置を設定する
	 * 
	 * @param[in] time 設定する再生位置時間.
	 * @param[in] bufNo バッファ番号.
	 * @return なし.
	 */
	virtual void setTime( float time, int bufNo=BGM_BUFFER ) = 0;

	
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
	virtual void setVolume( unsigned int volume, int bufNo=BGM_BUFFER ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 左右のボリューム比率を設定
	 * 
	 * @param[in] pan 設定するボリューム比率.
	 * @param[in] bufNo バッファ番号.
	 * @return なし.
	 */
	virtual void setPan( int pan, int bufNo=BGM_BUFFER ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/