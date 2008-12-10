/*******************************************************************************/
/**
 * @file SoundDeviceBase.h.
 * 
 * @brief �T�E���h�f�o�C�X���N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/19.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_SOUNDDEVICEBASE_H_
#define _NGL_SOUNDDEVICEBASE_H_

#include	"ISoundDevice.h"
#include	"ISoundResource.h"
#include	<string>
#include	<map>

namespace Ngl{


/**
 * @class SoundDeviceBase�D
 * @brief �T�E���h�f�o�C�X���N���X.
 *
 * ISoundResource�N���X�̃C���X�^���X���Ǘ�����}�l�[�W���N���X�̊��N���X�ł��B
 * SoundDeviceManage���̂��ЂƂ̃T�E���h�f�o�C�X�Ƃ��Ďg�p�\�ł��B
 *
 * �o�b�t�@�ԍ��ɂ���
 * -1		BGM�p�o�b�t�@( BGM_BUFFER )
 * 0�`����	SE�p�o�b�t�@
 * �Ǝ��Ƀo�b�t�@�̊��蓖�Ă����Ă���肠��܂���B
 */
class SoundDeviceBase : public ISoundDevice
{

protected:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	SoundDeviceBase();

public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~SoundDeviceBase();


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
	virtual void play( int bufNo=BGM_BUFFER, SoundPlayType PlayType=SOUNDPLAYTYPE_NORMAL );


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
	virtual void stop( int bufNo=BGM_BUFFER );

	
	/*=========================================================================*/
	/**
	 * @brief �Đ�����
	 * 
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @retval true �Đ���.
	 * @retval false �Đ����Ă��Ȃ�.
	 */
	virtual bool isPlaying( int bufNo=BGM_BUFFER );
	
	
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
	
protected:

	/*=========================================================================*/
	/**
	 * @brief ���\�[�X���쐬����
	 *
	 * @param[in] fileName �t�@�C����.
	 * @return �쐬�������\�[�X.
	 */
	virtual ISoundResource* create( const std::string& fileName ) = 0;

	/*=========================================================================*/
	/**
	 * @brief �w��̃o�b�t�@�����݂��Ă��邩���ׂ�
	 * 
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @retval true ���݂��Ă���.
	 * @retval false ���݂��Ă��Ȃ�.
	 */
	bool isBufferExist( int bufNo );


	/*=========================================================================*/
	/**
	 * @brief �w��̃o�b�t�@���������
	 * 
	 * @param[in] bufNo �o�b�t�@�ԍ�.
	 * @retval true �폜����.
	 * @retval false �폜���s.
	 */
	bool releaseBuffer( int bufNo );


	/*=========================================================================*/
	/**
	 * @brief �o�b�t�@�����ׂĉ������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void clearBuffer();

private:

	/** �T�E���h���X�g�^ */
	typedef std::map< int, ISoundResource* >	SoundList;

private:

	/** �T�E���h���X�g */
	SoundList	soundList_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/