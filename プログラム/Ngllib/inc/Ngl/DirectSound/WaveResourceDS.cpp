/*******************************************************************************/
/**
 * @file WaveResourceDS.cpp.
 * 
 * @brief DirectSound Waveフォーマットリソースクラスソースファイル.
 *
 * @date 2007/09/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"WaveResourceDS.h"
#include	"WaveDSException.h"
#include	<fstream>
#include	<memory>
#include	<cassert>


using namespace Ngl;
using namespace Ngl::DirectSound;


/*=========================================================================*/
/**
 * @brief 作成する
 * 
 * @param[in] fileName ファイル名.
 * @param[in] ds ダイレクトサウンドオブジェクト.
 * @param[in] enable3D 3Dサウンドを有効にするか.
 * @return ダイレクトサウンドバッファ.
 */
IDirectSoundBuffer* WaveResourceDS::create( const char* fileName, IDirectSound8* ds, bool enable3D )
{
	IDirectSoundBuffer*	buffer = NULL;	// ダイレクトサウンドバッファ

	try{	
		// Waveフォーマットデータを読み込む
		readWaveFormat( fileName );
		
		// Waveデータを読み込む
		readWaveData();
		
		// サウンドバッファを作成
		buffer = createSoundBuffer( ds, enable3D );
		
		// 波形データを書き込む
		writeWaveData( buffer, fileName );
	}
	catch( WaveDSException& e ){
		// 作成したバッファを削除
		if( buffer != NULL ){
			buffer->Release();
		}

		// エラーメッセージを出力
		e.add( "WaveResourceDS", "create" );
		e.outputConsol();
	}
	
	return buffer;
}



/*=========================================================================*/
/**
 * @brief Waveフォーマットを読み込む
 * 
 * @param[in] fileName ファイル名.
 * @return なし.
 * @throw Ngl::DirectSound::WaveDSException Waveファイル例外.
 */
void WaveResourceDS::readWaveFormat( const char* fileName )
{
	MMRESULT result = MMSYSERR_NOERROR;	// 実行結果
	
	// WAVファイル内のヘッダー情報（音データ以外）の確認と読み込み
	hMmio_ = mmioOpenA( const_cast< LPSTR >( fileName ), NULL, MMIO_ALLOCBUF | MMIO_READ );
	assert( hMmio_ != 0 );
	
	//ファイルポインタをRIFFチャンクの先頭にセットする
	result = mmioDescend( hMmio_, &riffckInfo_, NULL, 0 );
	assert( result == MMSYSERR_NOERROR );
	
	//チャンク情報によりWAVファイルかどうか確認する
	if( ( riffckInfo_.ckid != mmioFOURCC('R', 'I', 'F', 'F') ) || ( riffckInfo_.fccType != mmioFOURCC('W', 'A', 'V', 'E') ) ){
		throw WaveDSException( "This is not WaveFile", "WaveResourceDS", "readWaveFormat" );
	}
	
	// ファイルポインタを'f' 'm' 't' ' ' チャンクにセットする
	ckInfo_.ckid = mmioFOURCC('f', 'm', 't', ' ');
	result = mmioDescend( hMmio_, &ckInfo_, &riffckInfo_, MMIO_FINDCHUNK );
	assert( result == MMSYSERR_NOERROR );
	
	// フォーマットを読み込む
	if( mmioRead( hMmio_, (HPSTR) &pcmWaveFormat_, sizeof(pcmWaveFormat_)) != sizeof(pcmWaveFormat_) ){
		throw WaveDSException( "Wave Read format failed.", "WaveResourceDS", "readWaveFormat" );
	}
}

	
	
/*=========================================================================*/
/**
 * @brief Waveデータを読み込む
 * 
 * @param[in] なし.
 * @return なし.
 * @throw Ngl::DirectSound::WaveDSException Waveファイル例外.
 */
void WaveResourceDS::readWaveData()
{
	// リニアPCMで、かつ、マルチチャンネルWAVは想定外
	if( pcmWaveFormat_.wf.wFormatTag == WAVE_FORMAT_PCM ){
		waveFormat_ = (LPWAVEFORMATEX) new CHAR[ sizeof(WAVEFORMATEX) ];
		if( waveFormat_ == 0 ){
			throw WaveDSException( "This Type is not Readable", "WaveResourceDS", "readWaveData" );
		}
		// フォーマットデータを読み込む
		std::memcpy( waveFormat_, &pcmWaveFormat_, sizeof(pcmWaveFormat_) );
		waveFormat_->cbSize = 0;
	}
	else{
		delete[] waveFormat_;
		throw WaveDSException( "MulteChannelWaveFile can not opened", "WaveResourceDS", "readWaveData" );
	}

	// RIFF ファイルのチャンクから退出できなかったか
	if( mmioAscend( hMmio_, &ckInfo_, 0 ) != MMSYSERR_NOERROR ){
		delete[] waveFormat_;
		throw WaveDSException( "WaveData read erroer", "WaveResourceDS", "readWaveData" );
    }

	// WAVファイル内の音データの読み込み
	ckInfo_.ckid = mmioFOURCC('d', 'a', 't', 'a');
    MMRESULT result = mmioDescend( hMmio_, &ckInfo_, &riffckInfo_, MMIO_FINDCHUNK );
	if( result != MMSYSERR_NOERROR ){
		delete[] waveFormat_;
		throw WaveDSException( "WaveData read erroer", "WaveResourceDS", "readWaveData" );
	}
}
	
	
	
/*=========================================================================*/
/**
 * @brief DirectSoundバッファを作成
 * 
 * @param[in] ds ダイレクトサウンドオブジェクト.
 * @param[in] enable3D 3Dサウンドを有効にするか.
 * @return 作成したバッファ.
 */
IDirectSoundBuffer* WaveResourceDS::createSoundBuffer( IDirectSound8* ds, bool enable3D )
{
	IDirectSoundBuffer* buffer = NULL; // サウンドバッファ

	DWORD flags		= 0;				// デバイスフラグ
	GUID algorithm	= DS3DALG_DEFAULT;	// 再生アルゴリズム

	// 3Dが有効か
	if( enable3D ==true ){
		flags = DSBCAPS_CTRL3D |				// 3Dサウンド
				DSBCAPS_MUTE3DATMAXDISTANCE;	// 最大距離以上で無音

		algorithm = DS3DALG_HRTF_FULL;			// 高品質の 3D オーディオ アルゴリズム
	}
	else{
		flags =	DSBCAPS_CTRLPAN |				// パンの操作
				DSBCAPS_CTRLVOLUME |			// ボリュームの操作
				DSBCAPS_CTRLPOSITIONNOTIFY |	// 位置操作
				DSBCAPS_GETCURRENTPOSITION2;	// 位置取得
	}

	// セカンダリバッファ記述子を作成
	DSBUFFERDESC dsbd;
	ZeroMemory( &dsbd, sizeof(DSBUFFERDESC) );
	dsbd.dwSize				= sizeof(DSBUFFERDESC);	// 構造体のサイズ
	dsbd.dwFlags			= flags;				// デバイスフラグ
	dsbd.dwBufferBytes		= ckInfo_.cksize;		// waveデータのサイズ
	dsbd.lpwfxFormat		= waveFormat_;			// waveフォーマット
	dsbd.guid3DAlgorithm	= algorithm;			// 再生アルゴリズム

	// DirectSoundセカンダリーバッファー作成
	HRESULT hr = ds->CreateSoundBuffer( &dsbd, &buffer, NULL );

	// 3D再生で、高品質3Dアルゴリズムが使用できなかった
	if( enable3D == true && hr != DS_OK ){
		// 一段階低いアルゴリズム設定で再作成をする
		dsbd.guid3DAlgorithm = DS3DALG_HRTF_LIGHT;
		hr = ds->CreateSoundBuffer( &dsbd, &buffer, NULL );
	}
	assert( hr == DS_OK );

	return buffer;
}

	
	
/*=========================================================================*/
/**
 * @brief Wave波形データを書き込む
 * 
 * @param[out] buffer 作成したバッファ.
 * @param[in] fileName waveファイル名.
 * @return なし.
 * @throw Ngl::DirectSound::WaveDSException Waveファイル例外.
 */
void WaveResourceDS::writeWaveData( IDirectSoundBuffer* buffer, const char* fileName )
{
	// 波形データを書き込む準備として、セカンダリーバッファーをロックする
	VOID* pBuffer		= 0;
	DWORD dwBufferSize	= 0;
	if( FAILED( buffer->Lock( 0, ckInfo_.cksize, &pBuffer, &dwBufferSize, 0, 0, 0 ) ) ){
		delete[] waveFormat_;
	    throw WaveDSException( "BufferLock error", "WaveResourceDS", "writeWaveData" ); 
	}
	
	// ロックしたバッファーサイズが実際の波形データより大きか(クラッシュ防止)
	DWORD dwSize = dwBufferSize;
	if( dwSize > ckInfo_.cksize ){
		// サイズを補正
		dwSize = ckInfo_.cksize;
	}
	
	// バッファーに音データを書き込む
	std::ifstream is( fileName, std::ios::in | std::ios::binary );
	is.seekg( riffckInfo_.dwDataOffset + sizeof(FOURCC), std::ios::beg );
	BYTE* pWavData = new BYTE[ dwSize ];

	// まずは、一時的な場所(pWavData)に波形データを読み込む
	is.read( (char*)pWavData, dwSize );

	// 一時的な場所の波形データをセカンダリバッファーにコピーする
	for( DWORD i = 0; i < dwSize; i++ ){
		*((BYTE*)pBuffer+i) = *((BYTE*) pWavData+i);
	}

	// フォーマットを削除
	delete[] waveFormat_;
	
	//一時的な波形データを開放する
	delete[] pWavData;

	// バッファをアンロックする。
	buffer->Unlock( pBuffer, dwBufferSize, 0, 0 );
}
	
	
	
/*========= EOF =============================================================*/