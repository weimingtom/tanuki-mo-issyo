/*******************************************************************************/
/**
 * @file SoundDeviceDS.cpp.<br>
 * 
 * @brief �T�E���h�f�o�C�X�����N���X�\�[�X�t�@�C��.<br>
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
 * �R���X�g���N�^<br>
 * 
 * @param[in] �Ȃ�.
 */
SoundDeviceDS::SoundDeviceDS()
{}


	
/*=========================================================================*/
/**
 * Wav�t�@�C�����Đ�����f�o�C�X���쐬<br>
 * 
 * @param[in] hWnd �E�B���h�E�n���h��.
 * @return �Ȃ�.
 */
Ngl::ISoundDevice* SoundDeviceDS::CreateWaveSoundDevice( HWND hWnd )
{
	// �T�E���h���\�[�X���쐬
	Ngl::DirectSound::WaveResourceDS* res = new Ngl::DirectSound::WaveResourceDS();
	Ngl::DirectSound::DSSocketCreator* creator = new Ngl::DirectSound::DSSocketCreator( res );

	// �T�E���h�f�o�C�X���쐬
	Ngl::DirectSound::SoundDeviceDS* device = new Ngl::DirectSound::SoundDeviceDS();
	device->registCreator( "wav", creator );
	device->create( hWnd );

	return device;
}



/*=========================================================================*/
/**
 * Ogg�t�@�C�����Đ�����f�o�C�X���쐬<br>
 * 
 * @param[in] hWnd �E�B���h�E�n���h��.
 * @return �Ȃ�.
 */
Ngl::ISoundDevice* SoundDeviceDS::CreateOggSoundDevice( HWND hWnd )
{
	Ngl::Vox::SoundDeviceVox* device = new Ngl::Vox::SoundDeviceVox();
	
	return device;
}



/*===== EOF ==================================================================*/