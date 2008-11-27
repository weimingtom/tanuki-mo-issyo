/*******************************************************************************/
/**
 * @file SoundDeviceBase.h.
 * 
 * @brief サウンドデバイス基底クラスヘッダファイル.
 *
 * @date 2008/07/19.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_SOUNDDEVICEBASE_H_
#define _NGL_SOUNDDEVICEBASE_H_

#include	"ISoundDevice.h"
#include	"ISoundResource.h"
#include	<string>
#include	<map>

namespace Ngl{


/**
 * @class SoundDeviceBase．
 * @brief サウンドデバイス基底クラス.
 *
 * ISoundResourceクラスのインスタンスを管理するマネージャクラスの基底クラスです。
 * SoundDeviceManage自体もひとつのサウンドデバイスとして使用可能です。
 *
 * バッファ番号について
 * -1		BGM用バッファ( BGM_BUFFER )
 * 0～無限	SE用バッファ
 * 独自にバッファの割り当てをしても問題ありません。
 */
class SoundDeviceBase : public ISoundDevice
{

protected:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	SoundDeviceBase();

public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~SoundDeviceBase();


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
	virtual void play( int bufNo=BGM_BUFFER, SoundPlayType PlayType=SOUNDPLAYTYPE_NORMAL );


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
	virtual void stop( int bufNo=BGM_BUFFER );

	
	/*=========================================================================*/
	/**
	 * @brief 再生中か
	 * 
	 * @param[in] bufNo バッファ番号.
	 * @retval true 再生中.
	 * @retval false 再生していない.
	 */
	virtual bool isPlaying( int bufNo=BGM_BUFFER );
	
	
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
	
protected:

	/*=========================================================================*/
	/**
	 * @brief リソースを作成する
	 *
	 * @param[in] fileName ファイル名.
	 * @return 作成したリソース.
	 */
	virtual ISoundResource* create( const std::string& fileName ) = 0;

	/*=========================================================================*/
	/**
	 * @brief 指定のバッファが存在しているか調べる
	 * 
	 * @param[in] bufNo バッファ番号.
	 * @retval true 存在している.
	 * @retval false 存在していない.
	 */
	bool isBufferExist( int bufNo );


	/*=========================================================================*/
	/**
	 * @brief 指定のバッファを解放する
	 * 
	 * @param[in] bufNo バッファ番号.
	 * @retval true 削除成功.
	 * @retval false 削除失敗.
	 */
	bool releaseBuffer( int bufNo );


	/*=========================================================================*/
	/**
	 * @brief バッファをすべて解放する
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void clearBuffer();

private:

	/** サウンドリスト型 */
	typedef std::map< int, ISoundResource* >	SoundList;

private:

	/** サウンドリスト */
	SoundList	soundList_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/