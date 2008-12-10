/*******************************************************************************/
/**
 * @file SoundDeviceBase.h.<br>
 * 
 * @brief サウンドデバイス基底クラスヘッダファイル.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _SOUNDDEVICEBASE_H_
#define _SOUNDDEVICEBASE_H_

#include	"ISoundDevice.h"
#include	<Ngl/SoundDeviceManager.h>
#include	<windows.h>

/**
 * @brief サウンドデバイス基底クラス
 */
class SoundDeviceBase : public ISoundDevice
{
protected:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ<br>
	 * 
	 * @param[in] なし.
	 */
	SoundDeviceBase();

	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ<br>
	 * 
	 * @param[in] なし.
	 */
	virtual ~SoundDeviceBase();

public:

	/*=========================================================================*/
	/**
	 * @brief 作成処理<br>
	 * 
	 * @param[in] hWnd ウィンドウハンドル.
	 * @return なし.
	 */
	void Create( HWND hWnd );

	
	/*=========================================================================*/
	/**
	 * @brief 更新処理<br>
	 * 
	 * @param[in] frameTimer フレーム補正値.
	 * @return なし.
	 */
	void Update( float frameTimer );


	/*=========================================================================*/
	/**
	 * @brief 終了処理<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void End();

	
	/*=========================================================================*/
	/**
	 * @brief バッファカウンタを初期化<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void InitializeBufferCount();
	
	
	/*=========================================================================*/
	/**
	 * @brief BGMを再生<br>
	 * 
	 * @param[in] fileName ファイル名.
	 * @return なし.
	 */
	virtual void PlayBGM( const char*  fileName );

	
	/*=========================================================================*/
	/**
	 * @brief SEを再生<br>
	 * 
	 * @param[in] fileName ファイル名.
	 * @param[in] playType 再生方法フラグ.
	 * @return 再生バッファ番号.
	 */
	virtual int PlaySE( const char* fileName, SoundPlayType playType );

	
	/*=========================================================================*/
	/**
	 * @brief ボイスを再生<br>
	 * 
	 * @param[in] fileName ファイル名.
	 * @param[in] bufno ボイスバッファ番号.
	 * @return なし.
	 */
	virtual void PlayVoice( const char*  fileName, VoiceBufferNo bufno );
	
	
	/*=========================================================================*/
	/**
	 * @brief BGM再生を停止<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void StopBGM();

	
	/*=========================================================================*/
	/**
	 * @brief SE再生を停止<br>
	 * 
	 * @param[in] bufNo バッファ番号.
	 * @return なし.
	 */
	virtual void StopSE( int bufNo );

protected:

	/*=========================================================================*/
	/**
	 * @brief Wavファイルを再生するデバイスを作成<br>
	 * 
	 * @param[in] hWnd ウィンドウハンドル.
	 * @return なし.
	 */
	virtual Ngl::ISoundDevice* CreateWaveSoundDevice( HWND hWnd ) { return 0;  }

	
	/*=========================================================================*/
	/**
	 * @brief Oggファイルを再生するデバイスを作成<br>
	 * 
	 * @param[in] hWnd ウィンドウハンドル.
	 * @return なし.
	 */
	virtual Ngl::ISoundDevice* CreateOggSoundDevice( HWND hWnd ) { return  0; }

protected:

	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ( コピー禁止 )<br>
	 * 
	 * @param[in] other コピーするオブジェクト.
	 */
	SoundDeviceBase( const SoundDeviceBase& other );


	/*=========================================================================*/
	/**
	 * @brief = 演算子オーバーロード( コピー禁止 )<br>
	 * 
	 * @param[in] other 代入するオブジェクト.
	 * @return 代入結果のオブジェクト
	 */
	SoundDeviceBase& operator = ( const SoundDeviceBase& other );

private:

	/** サウンドデバイス管理者 */
	Ngl::SoundDeviceManager	soundDeviceManager_;

	/** バッファ番号カウンタ */
	int						seBufferCount_;

};

#endif

/*===== EOF ==================================================================*/