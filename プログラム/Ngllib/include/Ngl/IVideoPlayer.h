/*******************************************************************************/
/**
 * @file IVideoPlayer.h.
 * 
 * @brief �r�f�I�v���C���[�C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/30.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IVIDEOPLAYER_H_
#define _NGL_IVIDEOPLAYER_H_


namespace Ngl{


static const unsigned int VIDEO_VOLUME_MIN	= 0;	/**< �{�����[���̍ŏ��l				*/
static const unsigned int VIDEO_VOLUME_MAX	= 100;	/**< �{�����[���̍ő�l				*/

/**
 * @interface IVideoPlayer�D
 * @brief �r�f�I�v���C���[�C���^�[�t�F�[�X.
 */
class IVideoPlayer
{

public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IVideoPlayer() {}


	/*=========================================================================*/
	/**
	 * @brief ���[�r�[�̍������擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���[�r�[�̍���.
	 */
	virtual int getImageHeight() const = 0;


	/*=========================================================================*/
	/**
	 * @brief ���[�r�[�̕����擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���[�r�[�̕�.
	 */
	virtual int getImageWidth() const = 0;

	
	/*=========================================================================*/
	/**
	 * @brief ���[�r�[�̃C���[�W�����b�N����
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���b�N�����r�f�I������.
	 */
	virtual void* lockImage() = 0;


	/*=========================================================================*/
	/**
	 * @brief ���[�r�[�̃C���[�W���A�����b�N����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void unlockImage() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief ���[�r�[�̍Đ�
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void play() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief ���[�r�[�̒�~
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void stop() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �Đ��X�s�[�h�̕ύX
	 * 
	 * @param[in] time �ݒ肷��X�s�[�h.
	 * @return �Ȃ�.
	 */
	virtual void setSpeed( float time ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief ���݂̍Đ��ʒu���w��ʒu�ɃZ�b�g
	 * 
	 * @param[in] time �ݒ肷��Đ��ʒu����.
	 * @return �Ȃ�.
	 */
	virtual void setTime( float time ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �Đ��I�����Ԃ��擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �I������.
	 */
	virtual float getStopTime() const = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �X�g���[���̎��ԕ��̎擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���ԕ�.
	 */
	virtual float getDuration() const = 0;

	
	/*=========================================================================*/
	/**
	 * @brief ���݂̍Đ��ʒu�̎擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���݂̍Đ��ʒu.
	 */
	virtual float getCurrentPosition() const = 0;

	
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
	virtual void setVolume( unsigned int volume ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/