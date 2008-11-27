/*******************************************************************************/
/**
 * @file SoundDeviceVox.h.
 * 
 * @brief Vox �T�E���h�f�o�C�X�N���X�w�b�_�t�@�C��.
 * @brief ogg�`���̃t�@�C�����Đ��\�B
 * @brief Pan�̐ݒ�@�\�͂���܂���B
 *
 * @date 2008/07/07.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_VOX_OGGRESOURCEVOX_H_
#define _NGL_VOX_OGGRESOURCEVOX_H_

#include	"Vox/Vox.h"
#include	"Ngl/ISoundDevice.h"
#include	"Ngl/ISoundResource.h"
#include	<windows.h>
#include	<map>

namespace Ngl{


namespace Vox{


/** Vox�o�b�t�@�ԍ��^ */
typedef int VoxBufferNo;


/**
 * @struct VoxPlayState.
 * @brief Vox �Đ���ԍ\����
 */
enum VoxPlayState
{
	VOXPLAYSTATE_PLAY	= 0,	/**< �Đ���		*/
	VOXPLAYSTATE_PAUSE,			/**< �ꎞ��~��	*/
	VOXPLAYSTATE_STOP			/**< ��~��		*/
};


/**
 * @class SoundDeviceVox.
 * @brief Vox �T�E���h�f�o�C�X�N���X.
 */
class SoundDeviceVox : public ISoundDevice
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] : �Ȃ�.
	 */
	SoundDeviceVox();


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] : �Ȃ�.
	 */
	~SoundDeviceVox();


	/*=========================================================================*/
	/**
	 * @brief �X�V����
	 * 
	 * @param[in] frameTimer �t���[�������␳�l.
	 * @return �Ȃ�.
	 */
	virtual void update( float frameTimer );
	
	
	/*=========================================================================*/
	/**
	 * @brief �o�b�t�@���쐬
	 * 
	 * @param[in] fileName �t�@�C����.
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void createBuffer( const char* fileName, int bufNo=BGM_BUFFER );
	
	
	/*=========================================================================*/
	/**
	 * @brief �Đ�
	 * 
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @param[in] playType �Đ��^�C�v.
	 * @return �Ȃ�.
	 */
	virtual void play( int bufNo=BGM_BUFFER, SoundPlayType playType=SOUNDPLAYTYPE_NORMAL ) ;


	/*=========================================================================*/
	/**
	 * @brief �ꎞ��~
	 * 
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void pause( int bufNo=BGM_BUFFER );
	
	
	/*=========================================================================*/
	/**
	 * @brief �Đ����~
	 *
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void stop( int bufNo=BGM_BUFFER ) ;

	
	/*=========================================================================*/
	/**
	 * @brief �Đ�����
	 * 
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @retval true �Đ���.
	 * @retval false �Đ����Ă��Ȃ�.
	 */
	virtual bool isPlaying( int bufNo=BGM_BUFFER ) ;
	
	
	/*=========================================================================*/
	/**
	 * @brief �o�b�t�@���폜
	 *
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void eraseBuffer( int bufNo=BGM_BUFFER );
	
	
	/*=========================================================================*/
	/**
	 * @brief ��ԋL�q�q���擾
	 * 
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @return �T�E���h��ԋL�q�q.
	 */
	virtual SoundStateDesc& soundState( int bufNo=BGM_BUFFER );
		
	
	/*=========================================================================*/
	/**
	 * @brief �Đ��ʒu��ݒ肷��
	 * 
	 * @param[in] time �ݒ肷��Đ��ʒu����.
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void setTime( float time, int bufNo=BGM_BUFFER );

	
	/*=========================================================================*/
	/**
	 * @brief �{�����[���̐ݒ�
	 * 
	 * �ő�l 100( SOUND_VOLUME_MAX )
	 * �ŏ��l 0  ( SOUND_VOLUME_MIN )
	 *
	 * @param[in] volume �ݒ肷��{�����[��.
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void setVolume( unsigned int volume, int bufNo=BGM_BUFFER );
	
	
	/*=========================================================================*/
	/**
	 * @brief ���E�̃{�����[���䗦��ݒ�
	 * 
	 * @param[in] pan �ݒ肷��{�����[���䗦.
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void setPan( int pan, int bufNo=BGM_BUFFER );

private:

	/*=========================================================================*/
	/**
	 * @brief Vox�o�b�t�@�쐬����
	 * 
	 * @param[in] fileName �t�@�C�����O.
	 * @return �쐬�����h�c.
	 */
	VoxBufferNo create( const char* fileName );


	/*=========================================================================*/
	/**
	 * @brief ���ł�����
	 * 
	 * @param[in] id voxID.
	 * @return �Ȃ�.
	 */
	void release( VoxBufferNo id );


	/*=========================================================================*/
	/**
	 * @brief �o�b�t�@�����݂��Ă��邩
	 * 
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @return �Ȃ�.
	 */
	bool isExistBuffer( int bufNo );

private:

	/**
	 * @struct VoxState.
	 * @brief Vox ��ԍ\����.
	 */
	struct VoxState
	{
		/** �o�b�t�@�ԍ�	*/
		VoxBufferNo		bufferNo;

		/** �Đ���ԃt���O	*/
		VoxPlayState	playState;

		/** �T�E���h��ԍ\���� */
		SoundStateDesc	stateDesc;
	};

private:

	/** �T�E���h��ԃ��X�g�^ */
	typedef std::map< int, VoxState >	SoundStateList;

private:

	/** DLL�C���X�^���X */
	HINSTANCE			mHDll;

	/** VoxLoad�֐��|�C���^ */
	VoxLoad*			pVoxLoad;

	/** VoxPlay�֐��|�C���^ */
	VoxPlay*			pVoxPlay;

	/** VoxPause�֐��|�C���^ */
	VoxPause*			pVoxPause;

	/** VoxRelease�֐��|�C���^ */
	VoxRelease*			pVoxRelease;

	/** VoxSetLoop�֐��|�C���^ */
	VoxSetLoop*			pVoxSetLoop;

	/** VoxCheckDevice�֐��|�C���^ */
	VoxCheckDevice*		pVoxCheckDevice;

	/** VoxSetVolume�֐��|�C���^ */
	VoxSetVolume*		pVoxSetVolume;

	/** VoxGetVolume�֐��|�C���^ */
	VoxGetVolume*		pVoxGetVolume;

	/** VoxFade�֐��|�C���^ */
	VoxFade*			pVoxFade;

	/** VoxDelete�֐��|�C���^ */
	VoxDelete*			pVoxDelete;

	/** VoxGetTitalTime�֐��|�C���^ */
	VoxGetTotalTime*	 pVoxGetTotalTime;

	/** VoxGetCurrentTime�֐��|�C���^ */
	VoxGetCurrentTime*	pVoxGetCurrentTime;

	/** VoxSeek�֐��|�C���^ */
	VoxSeek*			pVoxSeek;

	/** VoxGetStatus�֐��|�C���^ */
	VoxGetStatus*		pVoxGetStatus;

	/** VoxGetComment�֐��|�C���^ */
	VoxGetComment*		pVoxGetComment;

	/** VoxParseComment�֐��|�C���^ */
	VoxParseComment*	pVoxParseComment;

	/** �T�E���h��ԃ��X�g */
	SoundStateList		soundStateList_;

};

}	// namespace Vox

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/