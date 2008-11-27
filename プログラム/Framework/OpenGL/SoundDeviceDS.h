/*******************************************************************************/
/**
 * @file SoundDeviceDS.h.<br>
 * 
 * @brief �T�E���h�f�o�C�X�����N���X�w�b�_�t�@�C��.<br>
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
 * @brief DirectSound�T�E���h�f�o�C�X.
 */
class SoundDeviceDS : public SoundDeviceBase
{
public:

	/*=========================================================================*/
	/**
	 * �R���X�g���N�^<br>
	 * 
	 * @param[in] �Ȃ�.
	 */
	SoundDeviceDS();

private:

	/*=========================================================================*/
	/**
	 * Wav�t�@�C�����Đ�����f�o�C�X���쐬<br>
	 * 
	 * @param[in] hWnd �E�B���h�E�n���h��.
	 * @return �Ȃ�.
	 */
	virtual Ngl::ISoundDevice* CreateWaveSoundDevice( HWND hWnd );

	
	/*=========================================================================*/
	/**
	 * Ogg�t�@�C�����Đ�����f�o�C�X���쐬<br>
	 * 
	 * @param[in] hWnd �E�B���h�E�n���h��.
	 * @return �Ȃ�.
	 */
	virtual Ngl::ISoundDevice* CreateOggSoundDevice( HWND hWnd );

private:

	/*=========================================================================*/
	/**
	 * �R�s�[�R���X�g���N�^( �R�s�[�֎~ )<br>
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 */
	SoundDeviceDS( const SoundDeviceDS& other );


	/*=========================================================================*/
	/**
	 * = ���Z�q�I�[�o�[���[�h( �R�s�[�֎~ )<br>
	 * 
	 * @param[in] other �������I�u�W�F�N�g.
	 * @return ������ʂ̃I�u�W�F�N�g
	 */
	SoundDeviceDS& operator = ( const SoundDeviceDS& other );

};

#endif

/*===== EOF ==================================================================*/