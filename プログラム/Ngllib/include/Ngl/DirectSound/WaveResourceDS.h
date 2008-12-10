/*******************************************************************************/
/**
 * @file WaveResourceDS.h.
 * 
 * @brief DirectSound Waveフォーマットリソースクラスヘッダファイル.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DIRECTSOUND_WAVERESOURCEDS_H_
#define _NGL_DIRECTSOUND_WAVERESOURCEDS_H_

#include	"IDirectSoundResource.h"
#include	"DirectSound.h"


namespace Ngl{


namespace DirectSound{


/**
 * @class WaveResourceDS.
 * @brief DirectSound Waveフォーマットリソースクラス．
 */
class WaveResourceDS : public IDirectSoundResource
{

public:

	/*=========================================================================*/
	/**
	 * @brief 作成する
	 * 
	 * @param[in] fileName ファイル名.
	 * @param[in] ds ダイレクトサウンドオブジェクト.
	 * @param[in] enable3D 3Dサウンドを有効にするか.
	 * @return ダイレクトサウンドバッファ.
	 */
	virtual IDirectSoundBuffer* create( const char* fileName, IDirectSound8* ds, bool enable3D=false );

private:

	/*=========================================================================*/
	/**
	 * @brief Waveフォーマットを読み込む
	 * 
	 * @param[in] fileName ファイル名.
	 * @return なし.
	 * @throw Ngl::DirectSound::WaveDSException Waveファイル例外.
	 */
	void readWaveFormat( const char* fileName );


	/*=========================================================================*/
	/**
	 * @brief Waveデータを読み込む
	 * 
	 * @param[in] なし.
	 * @return なし.
	 * @throw Ngl::DirectSound::WaveDSException Waveファイル例外.
	 */
	void readWaveData();


	/*=========================================================================*/
	/**
	 * @brief DirectSoundバッファを作成
	 * 
	 * @param[in] ds ダイレクトサウンドオブジェクト.
	 * @param[in] enable3D 3Dサウンドを有効にするか.
	 * @return 作成したバッファ.
	 */
	IDirectSoundBuffer* createSoundBuffer( IDirectSound8* ds, bool enable3D );


	/*=========================================================================*/
	/**
	 * @brief Wave波形データを書き込む
	 * 
	 * @param[out] buffer 作成したバッファ.
	 * @param[in] fileName waveファイル名.
	 * @return なし.
	 * @throw Ngl::DirectSound::WaveDSException Waveファイル例外.
	 */
	void writeWaveData( IDirectSoundBuffer* buffer, const char* fileName );

private:

	/** WindowsマルチメディアAPIのハンドル */
	HMMIO				hMmio_;	

	/** 最上部チャンク（RIFFチャンク）*/
	MMCKINFO			riffckInfo_;

	/** チャンク情報 */
	MMCKINFO			ckInfo_;

	/** pcmフォーマット */
	PCMWAVEFORMAT		pcmWaveFormat_;

	/** waveフォーマット */
	LPWAVEFORMATEX		waveFormat_;
};

}	// namespace DirectSound

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/