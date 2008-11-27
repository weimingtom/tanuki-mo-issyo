/*******************************************************************************/
/**
 * @file ISoundDevice.h.
 * 
 * @brief �T�E���h�f�o�C�X�C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/05.
 * 
 * @version 1.01.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ISOUNDDEVICE_H_
#define _NGL_ISOUNDDEVICE_H_

#include	"Ngl/SoundStateDesc.h"

namespace Ngl{


/** BGM�̃o�b�t�@�ԍ� */
static const int BGM_BUFFER = -1;


/**
 * @interface ISoundDevice�D
 * @brief �T�E���h�f�o�C�X�C���^�[�t�F�[�X.
 *
 * �o�b�t�@�ԍ��ɂ���
 * -1	BGM�p�o�b�t�@( BGM_BUFFER )
 * 0�`	SE�p�o�b�t�@
 * �Ǝ��Ƀo�b�t�@�̊��蓖�Ă����Ă���肠��܂���B
 */
class ISoundDevice
{
	
public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~ISoundDevice() {}


	/*=========================================================================*/
	/**
	 * @brief �X�V����
	 * 
	 * @param[in] frameTimer �t���[�������␳�l.
	 * @return �Ȃ�.
	 */
	virtual void update( float frameTimer ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �o�b�t�@���쐬
	 * 
	 * @param[in] fileName �t�@�C����.
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void createBuffer( const char* fileName, int bufNo=BGM_BUFFER ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �Đ�
	 * 
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @param[in] playType �Đ��^�C�v.
	 * @return �Ȃ�.
	 */
	virtual void play( int bufNo=BGM_BUFFER, SoundPlayType playType=SOUNDPLAYTYPE_NORMAL ) = 0;


	/*=========================================================================*/
	/**
	 * @brief �ꎞ��~
	 * 
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void pause( int bufNo=BGM_BUFFER ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �Đ����~
	 *
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void stop( int bufNo=BGM_BUFFER ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �Đ�����
	 * 
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @retval true �Đ���.
	 * @retval false �Đ����Ă��Ȃ�.
	 */
	virtual bool isPlaying( int bufNo=BGM_BUFFER ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �o�b�t�@���폜
	 *
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void eraseBuffer( int bufNo=BGM_BUFFER ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief ��ԋL�q�q���擾
	 * 
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @return �T�E���h��ԋL�q�q.
	 */
	virtual SoundStateDesc& soundState( int bufNo=BGM_BUFFER ) = 0;
		
	
	/*=========================================================================*/
	/**
	 * @brief �Đ��ʒu��ݒ肷��
	 * 
	 * @param[in] time �ݒ肷��Đ��ʒu����.
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void setTime( float time, int bufNo=BGM_BUFFER ) = 0;

	
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
	virtual void setVolume( unsigned int volume, int bufNo=BGM_BUFFER ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief ���E�̃{�����[���䗦��ݒ�
	 * 
	 * @param[in] pan �ݒ肷��{�����[���䗦.
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void setPan( int pan, int bufNo=BGM_BUFFER ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/