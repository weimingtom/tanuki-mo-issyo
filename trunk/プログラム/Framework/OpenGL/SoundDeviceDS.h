/*******************************************************************************/
/**
 * @file SoundDeviceDS.h.<br>
 * 
 * @brief サウンドデバイス実装クラスヘッダファイル.<br>
 *
 * @date 2008/08/16.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _SOUNDDEVICEDS_H_
#define _SOUNDDEVICEDS_H_

#include	"SoundDeviceBase.h"


/**
 * @brief DirectSoundサウンドデバイス.
 */
class SoundDeviceDS : public SoundDeviceBase
{
public:

	/*=========================================================================*/
	/**
	 * コンストラクタ<br>
	 * 
	 * @param[in] なし.
	 */
	SoundDeviceDS();

private:

	/*=========================================================================*/
	/**
	 * Wavファイルを再生するデバイスを作成<br>
	 * 
	 * @param[in] hWnd ウィンドウハンドル.
	 * @return なし.
	 */
	virtual Ngl::ISoundDevice* CreateWaveSoundDevice( HWND hWnd );

	
	/*=========================================================================*/
	/**
	 * Oggファイルを再生するデバイスを作成<br>
	 * 
	 * @param[in] hWnd ウィンドウハンドル.
	 * @return なし.
	 */
	virtual Ngl::ISoundDevice* CreateOggSoundDevice( HWND hWnd );

private:

	/*=========================================================================*/
	/**
	 * コピーコンストラクタ( コピー禁止 )<br>
	 * 
	 * @param[in] other コピーするオブジェクト.
	 */
	SoundDeviceDS( const SoundDeviceDS& other );


	/*=========================================================================*/
	/**
	 * = 演算子オーバーロード( コピー禁止 )<br>
	 * 
	 * @param[in] other 代入するオブジェクト.
	 * @return 代入結果のオブジェクト
	 */
	SoundDeviceDS& operator = ( const SoundDeviceDS& other );

};

#endif

/*===== EOF ==================================================================*/