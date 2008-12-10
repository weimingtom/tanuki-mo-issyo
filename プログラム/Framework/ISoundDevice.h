/*******************************************************************************/
/**
 * @file ISoundDevice.h.<br>
 * 
 * @brief サウンドデバイスインターフェース定義.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _ISOUNDDEVICE_H_
#define _ISOUNDDEVICE_H_

#include "Define/Define.h"

/**
 * @brief ボイスバッファ番号列挙型.
 */
enum VoiceBufferNo
{
	VOICEBUFFERNO_PLAYER1		= 0,	/**< 1プレイヤー用バッファ	*/
	VOICEBUFFERNO_PLAYER2,				/**< 2プレイヤー用バッファ	*/
	VOICEBUFFERNO_OTHER1_1,				/**< 1プレイヤーの他キャラ1用バッファ	*/
	VOICEBUFFERNO_OTHRE1_2,				/**< 2プレイヤーの他キャラ1用バッファ	*/
	VOICEBUFFERNO_OTHER2_1,				/**< 1プレイヤーの他キャラ1用バッファ	*/
	VOICEBUFFERNO_OTHRE2_2,				/**< 2プレイヤーの他キャラ1用バッファ	*/

	VOICEBUFFERNO_COUNT					/**< ボイスバッファ数		*/
};


/**
 * @brief サウンドデバイスインターフェース
 */
class ISoundDevice
{
protected:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ<br>
	 * 
	 * @param[in] なし.
	 */
	virtual ~ISoundDevice(){}

public:

	/*=========================================================================*/
	/**
	 * @brief バッファカウンタを初期化<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void InitializeBufferCount() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief BGMを再生<br>
	 * 
	 * @param[in] fileName ファイル名.
	 */
	virtual void PlayBGM( const char*  fileName ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief SEを再生<br>
	 * 
	 * @param[in] fileName ファイル名.
	 * @param[in] playType 再生方法フラグ.
	 * @return 再生バッファ番号.
	 */
	virtual int PlaySE( const char* fileName, SoundPlayType playType ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief ボイスを再生<br>
	 * 
	 * @param[in] fileName ファイル名.
	 * @param[in] bufno ボイスバッファ番号.
	 * @return なし.
	 */
	virtual void PlayVoice( const char*  fileName, VoiceBufferNo bufno ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief BGM再生を停止<br>
	 * 
	 * @param[in] なし.
	 */
	virtual void StopBGM() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief SE再生を停止<br>
	 * 
	 * @param[in] bufNo バッファ番号.
	 */
	virtual void StopSE( int bufNo ) = 0;

};

#endif

/*========= End of File =====================================================*/