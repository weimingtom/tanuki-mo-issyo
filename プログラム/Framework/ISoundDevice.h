/*******************************************************************************/
/**
 * @file ISoundDevice.h.<br>
 * 
 * @brief �T�E���h�f�o�C�X�C���^�[�t�F�[�X��`.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _ISOUNDDEVICE_H_
#define _ISOUNDDEVICE_H_

#include "Define/Define.h"

/**
 * @brief �{�C�X�o�b�t�@�ԍ��񋓌^.
 */
enum VoiceBufferNo
{
	VOICEBUFFERNO_PLAYER1		= 0,	/**< 1�v���C���[�p�o�b�t�@	*/
	VOICEBUFFERNO_PLAYER2,				/**< 2�v���C���[�p�o�b�t�@	*/
	VOICEBUFFERNO_OTHER1_1,				/**< 1�v���C���[�̑��L����1�p�o�b�t�@	*/
	VOICEBUFFERNO_OTHRE1_2,				/**< 2�v���C���[�̑��L����1�p�o�b�t�@	*/
	VOICEBUFFERNO_OTHER2_1,				/**< 1�v���C���[�̑��L����1�p�o�b�t�@	*/
	VOICEBUFFERNO_OTHRE2_2,				/**< 2�v���C���[�̑��L����1�p�o�b�t�@	*/

	VOICEBUFFERNO_COUNT					/**< �{�C�X�o�b�t�@��		*/
};


/**
 * @brief �T�E���h�f�o�C�X�C���^�[�t�F�[�X
 */
class ISoundDevice
{
protected:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^<br>
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~ISoundDevice(){}

public:

	/*=========================================================================*/
	/**
	 * @brief �o�b�t�@�J�E���^��������<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void InitializeBufferCount() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief BGM���Đ�<br>
	 * 
	 * @param[in] fileName �t�@�C����.
	 */
	virtual void PlayBGM( const char*  fileName ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief SE���Đ�<br>
	 * 
	 * @param[in] fileName �t�@�C����.
	 * @param[in] playType �Đ����@�t���O.
	 * @return �Đ��o�b�t�@�ԍ�.
	 */
	virtual int PlaySE( const char* fileName, SoundPlayType playType ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �{�C�X���Đ�<br>
	 * 
	 * @param[in] fileName �t�@�C����.
	 * @param[in] bufno �{�C�X�o�b�t�@�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void PlayVoice( const char*  fileName, VoiceBufferNo bufno ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief BGM�Đ����~<br>
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual void StopBGM() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief SE�Đ����~<br>
	 * 
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 */
	virtual void StopSE( int bufNo ) = 0;

};

#endif

/*========= End of File =====================================================*/