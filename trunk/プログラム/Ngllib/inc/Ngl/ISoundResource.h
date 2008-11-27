/*******************************************************************************/
/**
 * @file ISoundResource.h.
 * 
 * @brief �T�E���h���\�[�X�C���^�[�t�F�[�X�N���X��`.
 *
 * @date 2007/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ISOUNDRESOURCE_H_
#define _NGL_ISOUNDRESOURCE_H_

#include	"ISoundDevice.h"
#include	"SoundStateDesc.h"

namespace Ngl{


/**
 * @interface ISoundResource�D
 * @brief �T�E���h���\�[�X�C���^�[�t�F�[�X.
 */
class ISoundResource
{

public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~ISoundResource() {}


	/*=========================================================================*/
	/**
	 * @brief �Đ�����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void play() = 0;


	/*=========================================================================*/
	/**
	 * @brief �Đ��������ׂ�
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �Đ���.
	 * @retval false ��~��.
	 */
	virtual bool isPlay() = 0;


	/*=========================================================================*/
	/**
	 * @brief �ꎞ��~
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void pause() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief ��~����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void stop() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief ��ԋL�q�q���擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �T�E���h��ԋL�q�q.
	 */
	virtual SoundStateDesc& soundState() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �Ȃ̍Đ��^�C�v��ݒ�
	 * 
	 * @param[in] type �Đ��^�C�v.
	 * @return �Ȃ�.
	 */
	virtual void setType( SoundPlayType type ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �Đ��ʒu��ݒ肷��
	 * 
	 * @param[in] time �ݒ肷��Đ��ʒu����( �~���b ).
	 * @return �Ȃ�.
	 */
	virtual void setTime( float time ) = 0;

	
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
	virtual void setPan( int pan ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/