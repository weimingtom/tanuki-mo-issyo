/*******************************************************************************/
/**
 * @file SoundDeviceBase.h.<br>
 * 
 * @brief �T�E���h�f�o�C�X���N���X�w�b�_�t�@�C��.<br>
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
 * @brief �T�E���h�f�o�C�X���N���X
 */
class SoundDeviceBase : public ISoundDevice
{
protected:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^<br>
	 * 
	 * @param[in] �Ȃ�.
	 */
	SoundDeviceBase();

	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^<br>
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~SoundDeviceBase();

public:

	/*=========================================================================*/
	/**
	 * @brief �쐬����<br>
	 * 
	 * @param[in] hWnd �E�B���h�E�n���h��.
	 * @return �Ȃ�.
	 */
	void Create( HWND hWnd );

	
	/*=========================================================================*/
	/**
	 * @brief �X�V����<br>
	 * 
	 * @param[in] frameTimer �t���[���␳�l.
	 * @return �Ȃ�.
	 */
	void Update( float frameTimer );


	/*=========================================================================*/
	/**
	 * @brief �I������<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void End();

	
	/*=========================================================================*/
	/**
	 * @brief �o�b�t�@�J�E���^��������<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void InitializeBufferCount();
	
	
	/*=========================================================================*/
	/**
	 * @brief BGM���Đ�<br>
	 * 
	 * @param[in] fileName �t�@�C����.
	 * @return �Ȃ�.
	 */
	virtual void PlayBGM( const char*  fileName );

	
	/*=========================================================================*/
	/**
	 * @brief SE���Đ�<br>
	 * 
	 * @param[in] fileName �t�@�C����.
	 * @param[in] playType �Đ����@�t���O.
	 * @return �Đ��o�b�t�@�ԍ�.
	 */
	virtual int PlaySE( const char* fileName, SoundPlayType playType );

	
	/*=========================================================================*/
	/**
	 * @brief �{�C�X���Đ�<br>
	 * 
	 * @param[in] fileName �t�@�C����.
	 * @param[in] bufno �{�C�X�o�b�t�@�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void PlayVoice( const char*  fileName, VoiceBufferNo bufno );
	
	
	/*=========================================================================*/
	/**
	 * @brief BGM�Đ����~<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void StopBGM();

	
	/*=========================================================================*/
	/**
	 * @brief SE�Đ����~<br>
	 * 
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void StopSE( int bufNo );

protected:

	/*=========================================================================*/
	/**
	 * @brief Wav�t�@�C�����Đ�����f�o�C�X���쐬<br>
	 * 
	 * @param[in] hWnd �E�B���h�E�n���h��.
	 * @return �Ȃ�.
	 */
	virtual Ngl::ISoundDevice* CreateWaveSoundDevice( HWND hWnd ) { return 0;  }

	
	/*=========================================================================*/
	/**
	 * @brief Ogg�t�@�C�����Đ�����f�o�C�X���쐬<br>
	 * 
	 * @param[in] hWnd �E�B���h�E�n���h��.
	 * @return �Ȃ�.
	 */
	virtual Ngl::ISoundDevice* CreateOggSoundDevice( HWND hWnd ) { return  0; }

protected:

	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^( �R�s�[�֎~ )<br>
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 */
	SoundDeviceBase( const SoundDeviceBase& other );


	/*=========================================================================*/
	/**
	 * @brief = ���Z�q�I�[�o�[���[�h( �R�s�[�֎~ )<br>
	 * 
	 * @param[in] other �������I�u�W�F�N�g.
	 * @return ������ʂ̃I�u�W�F�N�g
	 */
	SoundDeviceBase& operator = ( const SoundDeviceBase& other );

private:

	/** �T�E���h�f�o�C�X�Ǘ��� */
	Ngl::SoundDeviceManager	soundDeviceManager_;

	/** �o�b�t�@�ԍ��J�E���^ */
	int						seBufferCount_;

};

#endif

/*===== EOF ==================================================================*/