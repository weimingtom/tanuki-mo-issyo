/*******************************************************************************/
/**
 * @file SoundDeviceManager.h.
 * 
 * @brief サウンドデバイス管理者クラスヘッダファイル.
 *
 * @date 2008/07/06.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimuara.
 */
/******************************************************************************/
#ifndef _NGL_SOUNDDEVICEMANAGER_H_
#define _NGL_SOUNDDEVICEMANAGER_H_

#include	"Ngl/Manager/ObjectManager.h"
#include	"ISoundDevice.h"
#include	<map>
#include	<string>

namespace Ngl{


/**
 * @class SoundDeviceManager．
 * @brief サウンドデバイス管理者クラス.
 */
class SoundDeviceManager : public ISoundDevice
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	SoundDeviceManager();


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~SoundDeviceManager();


	/*=========================================================================*/
	/**
	 * @brief デバイスを登録
	 * 
	 * @param[in] extName 登録する拡張子名( .は含まない ).
	 * @param[in] device 登録するデバイスのポインタ.
	 *
	 * @return なし.
	 */
	void regist( std::string extName, ISoundDevice* device );
	
	
	/*=========================================================================*/
	/**
	 * @brief 指定のデバイスを削除
	 * 
	 * @param[in] extName 削除する拡張子名( .は含まない ).
	 * @return なし.
	 */
	void eraseDevice( std::string extName );
	
	
	/*=========================================================================*/
	/**
	 * @brief 解放処理
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void release();
	
	
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
	virtual void play( int bufNo=BGM_BUFFER, SoundPlayType playType=SOUNDPLAYTYPE_NORMAL );


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
	 * 最大値 100( SOUND_VOLUME_MAX )<br>
	 * 最小値 0  ( SOUND_VOLUME_MIN )<br>
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
	 * @brief 指定の要素がすでに存在しているか調べる
	 *
	 * @@aram[in] index 調べるインデックス名.
	 * @retval true 存在している.
	 * @retval false 存在していない.
	 */
	bool isIndexExist( std::string& index );

private:

	/** サウンドデバイスコンテナ型 */
	typedef ObjectManager< std::string, ISoundDevice* >	SoundDeviceContainer;

	/** 再生バッファリスト */
	typedef std::map< int, std::string >				PlayBufferList;	

private:

	/** サウンドデバイスコンテナ */
	SoundDeviceContainer	soundDeviceContainer_;

	/** 再生バッファリスト */
	PlayBufferList			playBufferList_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/