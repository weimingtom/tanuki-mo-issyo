/*******************************************************************************/
/**
 * @file DirectSoundSocket.h.
 * 
 * @brief DirectSound �\�P�b�g�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DIRECTSOUND_DIRECTSOUNDSOCKET_H_
#define _NGL_DIRECTSOUND_DIRECTSOUNDSOCKET_H_

#include	"IDirectSoundResource.h"
#include	"Ngl/ISoundDevice.h"
#include	"Ngl/ISoundResource.h"
#include	"DirectSound.h"


namespace Ngl{


namespace DirectSound{


/**
 * @class DirectSoundSocket
 * @brief DirectSound �\�P�b�g�N���X�D
 */
class DirectSoundSocket : public ISoundResource
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	DirectSoundSocket();


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~DirectSoundSocket();


	/*=========================================================================*/
	/**
	 * @brief �쐬����
	 * 
	 * @param[in] fileName �t�@�C����.
	 * @param[in] ds �_�C���N�g�T�E���h�I�u�W�F�N�g.
	 * @param[in] rg ���\�[�X�N���X�̃|�C���^.
	 * @retval true �쐬����.
	 * @retval false �쐬���s.
	 */
	bool create( const char* fileName, IDirectSound8* ds, IDirectSoundResource* rg );


	/*=========================================================================*/
	/**
	 * @brief ���ł�����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void release();


	/*=========================================================================*/
	/**
	 * @brief �Đ�����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void play();


	/*=========================================================================*/
	/**
	 * @brief �Đ��������ׂ�
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �Đ���.
	 * @retval false ��~��.
	 */
	virtual bool isPlay();


	/*=========================================================================*/
	/**
	 * @brief �ꎞ��~
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void pause();
	
	
	/*=========================================================================*/
	/**
	 * @brief ��~����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void stop();
	
	
	/*=========================================================================*/
	/**
	 * @brief ��ԋL�q�q���擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �T�E���h��ԋL�q�q.
	 */
	virtual SoundStateDesc& soundState();
	
	
	/*=========================================================================*/
	/**
	 * @brief �Ȃ̍Đ��^�C�v��ݒ�
	 * 
	 * @param[in] type �Đ��^�C�v.
	 * @return �Ȃ�.
	 */
	virtual void setType( SoundPlayType type );
	
	
	/*=========================================================================*/
	/**
	 * @brief �Đ��ʒu��ݒ肷��
	 * 
	 * @param[in] time �ݒ肷��Đ��ʒu����( �~���b ).
	 * @return �Ȃ�.
	 */
	virtual void setTime( float time );

	
	/*=========================================================================*/
	/**
	 * @brief �{�����[���̐ݒ�
	 *
	 * �ő�l 100( SOUND_VOLUME_MAX )
	 * �ŏ��l 0  ( SOUND_VOLUME_MIN )
	 * 
	 * @param[in] volume �ݒ肷��{�����[��.
	 * @return �Ȃ�.
	 */
	virtual void setVolume( unsigned int volume );
	
	
	/*=========================================================================*/
	/**
	 * @brief ���E�̃{�����[���䗦��ݒ�
	 * 
	 * ���ő�l -100 ( SOUND_PAN_LEFTMAX  )
	 * ���Ԓl   0    ( SOUND_PAN_MIDDLE   )
	 * �E�ő�l 100  ( SOUND_PAN_RIGHTMAX )
	 *
	 * @param[in] pan �ݒ肷��{�����[���䗦.
	 * @return �Ȃ�.
	 */
	virtual void setPan( int pan );
	
private:

	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^ (�R�s�[�֎~)
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 */
	DirectSoundSocket( const DirectSoundSocket& other );


	/*=========================================================================*/
	/**
	 * @brief = ���Z�q�I�[�o�[���[�h (�R�s�[�֎~)
	 * 
	 * @param[in] other �R�s�[���̃I�u�W�F�N�g.
	 * @return �R�s�[���ʂ̃I�u�W�F�N�g.
	 */
	DirectSoundSocket& operator = ( const DirectSoundSocket& other );

private:
	
	/** �_�C���N�g�T�E���h�I�u�W�F�N�g */
	IDirectSoundBuffer*		buffer_;

	/** �_�C���N�g�RD�T�E���h�I�u�W�F�N�g */
	IDirectSound3DBuffer*	buffer3D_;

	/** �_�C���N�g�RD���X�i�[�I�u�W�F�N�g */
	IDirectSound3DListener*	listener3D_;

	/** wave�t�@�C���t�H�[�}�b�g */
	WAVEFORMATEX*			waveFormat_;

	/** wave�f�[�^�T�C�Y */
	unsigned long			waveDataSize_;

	/** �T�E���h��ԋL�q�q */
	SoundStateDesc			soundState_;
};

}	// namespace DirectSound

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/