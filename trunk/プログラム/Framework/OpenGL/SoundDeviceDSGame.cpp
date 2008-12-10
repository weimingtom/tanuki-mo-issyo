/*******************************************************************************/
/**
 * @file SoundDeviceDS.cpp.<br>
 * 
 * @brief サウンドデバイス実装クラスソースファイル.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"SoundDeviceDS.h"
#include	<Ngl/DirectSound/WaveResourceDS.h>
#include	<Ngl/DirectSound/DSSocketCreator.h>
#include	<Ngl/DirectSound/SoundDeviceDS.h>
#include	<Ngl/Vox/SoundDeviceVox.h>


/*=========================================================================*/
/**
 * コンストラクタ<br>
 * 
 * @param[in] なし.
 */
SoundDeviceDS::SoundDeviceDS()
{}


	
/*=========================================================================*/
/**
 * Wavファイルを再生するデバイスを作成<br>
 * 
 * @param[in] hWnd ウィンドウハンドル.
 * @return なし.
 */
Ngl::ISoundDevice* SoundDeviceDS::CreateWaveSoundDevice( HWND hWnd )
{
	// サウンドリソースを作成
	Ngl::DirectSound::WaveResourceDS* res = new Ngl::DirectSound::WaveResourceDS();
	Ngl::DirectSound::DSSocketCreator* creator = new Ngl::DirectSound::DSSocketCreator( res );

	// サウンドデバイスを作成
	Ngl::DirectSound::SoundDeviceDS* device = new Ngl::DirectSound::SoundDeviceDS();
	device->registCreator( "wav", creator );
	device->create( hWnd );

	return device;
}



/*=========================================================================*/
/**
 * Oggファイルを再生するデバイスを作成<br>
 * 
 * @param[in] hWnd ウィンドウハンドル.
 * @return なし.
 */
Ngl::ISoundDevice* SoundDeviceDS::CreateOggSoundDevice( HWND hWnd )
{
	Ngl::Vox::SoundDeviceVox* device = new Ngl::Vox::SoundDeviceVox();
	
	return device;
}



/*===== EOF ==================================================================*/