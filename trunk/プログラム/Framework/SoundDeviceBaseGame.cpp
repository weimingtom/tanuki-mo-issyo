/*******************************************************************************/
/**
 * @file SoundDeviceBase.cpp.<br>
 * 
 * @brief サウンドデバイス基底クラスソースファイル.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"SoundDeviceBase.h"
#include	<Ngl/Utility.h>

/*=========================================================================*/
/**
 * @brief コンストラクタ<br>
 * 
 * @param[in] なし.
 */
SoundDeviceBase::SoundDeviceBase():
	seBufferCount_( VOICEBUFFERNO_COUNT )
{}



/*=========================================================================*/
/**
 * @brief デストラクタ<br>
 * 
 * @param[in] なし.
 */
SoundDeviceBase::~SoundDeviceBase()
{
	soundDeviceManager_.release();
}



/*=========================================================================*/
/**
 * @brief 作成処理<br>
 * 
 * @param[in] hWnd ウィンドウハンドル.
 * @return なし.
 */
void SoundDeviceBase::Create( HWND hWnd )
{
	// Waveサウンド再生デバイスを作成する
	soundDeviceManager_.regist( "wav", CreateWaveSoundDevice( hWnd ) );

	// Oggサウンド再生デバイスを作成する
	soundDeviceManager_.regist( "ogg", CreateOggSoundDevice( hWnd ) );
}



/*=========================================================================*/
/**
 * @brief 更新処理<br>
 * 
 * @param[in] frameTimer フレーム補正値.
 * @return なし.
 */
void SoundDeviceBase::Update( float frameTimer )
{
	soundDeviceManager_.update( frameTimer );

	// カウントを初期化
	if( seBufferCount_ > 30 ){
		seBufferCount_ = VOICEBUFFERNO_COUNT;
	}
}

	

/*=========================================================================*/
/**
 * @brief 終了処理<br>
 * 
 * @param[in] なし.
 * @return なし.
 */
void SoundDeviceBase::End()
{
	soundDeviceManager_.release();
}


	
/*=========================================================================*/
/**
 * @brief バッファカウンタを初期化<br>
 * 
 * @param[in] なし.
 * @return なし.
 */
void SoundDeviceBase::InitializeBufferCount()
{
	for( int i=0; i<seBufferCount_; ++i ){
		// バッファをクリア
		soundDeviceManager_.eraseBuffer( i );
	}

	seBufferCount_ = VOICEBUFFERNO_COUNT;
}

	
	
/*=========================================================================*/
/**
 * @brief BGMを再生<br>
 * 
 * @param[in] fileName ファイル名.
 * @return なし.
 */
void SoundDeviceBase::PlayBGM( const char*  fileName )
{
	std::string ffn = "Resource/";
	ffn += fileName;

	// バッファを作成
	soundDeviceManager_.createBuffer( ffn.c_str(), Ngl::BGM_BUFFER );

	// バッファを再生
	soundDeviceManager_.play( Ngl::BGM_BUFFER, Ngl::SOUNDPLAYTYPE_LOOP );
}



/*=========================================================================*/
/**
 * @brief SEを再生<br>
 * 
 * @param[in] fileName ファイル名.
 * @param[in] playType 再生方法フラグ.
 * @return 再生バッファ番号.
 */
int SoundDeviceBase::PlaySE( const char* fileName, SoundPlayType playType )
{
	std::string ffn = "Resource/";
	ffn += fileName;

	// バッファを作成
	soundDeviceManager_.createBuffer( ffn.c_str(), seBufferCount_ );

	// バッファを再生
	soundDeviceManager_.play( seBufferCount_, playType );

	int tmpbuf = seBufferCount_;

	// カウンタを増やす
	seBufferCount_++;

	return tmpbuf;
}



/*=========================================================================*/
/**
 * @brief ボイスを再生<br>
 * 
 * @param[in] fileName ファイル名.
 * @param[in] bufno ボイスバッファ番号.
 * @return なし.
 */
void SoundDeviceBase::PlayVoice( const char*  fileName, VoiceBufferNo bufno )
{
	std::string ffn = "Resource/";
	ffn += fileName;

	// バッファを作成
	soundDeviceManager_.createBuffer( ffn.c_str(), bufno );

	// バッファを再生
	soundDeviceManager_.play( bufno, Ngl::SOUNDPLAYTYPE_NORMAL );
}
	

	
/*=========================================================================*/
/**
 * @brief BGM再生を停止<br>
 * 
 * @param[in] なし.
 * @return なし.
 */
void SoundDeviceBase::StopBGM()
{
	soundDeviceManager_.stop( Ngl::BGM_BUFFER );
	soundDeviceManager_.eraseBuffer( Ngl::BGM_BUFFER );
}



/*=========================================================================*/
/**
 * @brief SE再生を停止<br>
 * 
 * @param[in] bufNo バッファ番号.
 * @return なし.
 */
void SoundDeviceBase::StopSE( int bufNo )
{
	soundDeviceManager_.stop( bufNo );
	soundDeviceManager_.eraseBuffer( bufNo );
}



/*===== EOF ==================================================================*/