/*******************************************************************************/
/**
 * @file SoundDeviceManager.h.
 * 
 * @brief �T�E���h�f�o�C�X�Ǘ��҃N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/06.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimuara.
 */
/******************************************************************************/
#ifndef _NGL_SOUNDDEVICEMANAGER_H_
#define _NGL_SOUNDDEVICEMANAGER_H_

#include	"Ngl/Manager/ObjectManager.h"
#include	"ISoundDevice.h"
#include	<map>
#include	<string>

namespace Ngl{


/**
 * @class SoundDeviceManager�D
 * @brief �T�E���h�f�o�C�X�Ǘ��҃N���X.
 */
class SoundDeviceManager : public ISoundDevice
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	SoundDeviceManager();


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~SoundDeviceManager();


	/*=========================================================================*/
	/**
	 * @brief �f�o�C�X��o�^
	 * 
	 * @param[in] extName �o�^����g���q��( .�͊܂܂Ȃ� ).
	 * @param[in] device �o�^����f�o�C�X�̃|�C���^.
	 *
	 * @return �Ȃ�.
	 */
	void regist( std::string extName, ISoundDevice* device );
	
	
	/*=========================================================================*/
	/**
	 * @brief �w��̃f�o�C�X���폜
	 * 
	 * @param[in] extName �폜����g���q��( .�͊܂܂Ȃ� ).
	 * @return �Ȃ�.
	 */
	void eraseDevice( std::string extName );
	
	
	/*=========================================================================*/
	/**
	 * @brief �������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void release();
	
	
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
	virtual void play( int bufNo=BGM_BUFFER, SoundPlayType playType=SOUNDPLAYTYPE_NORMAL );


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
	 * �ő�l 100( SOUND_VOLUME_MAX )<br>
	 * �ŏ��l 0  ( SOUND_VOLUME_MIN )<br>
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
	 * @brief �w��̗v�f�����łɑ��݂��Ă��邩���ׂ�
	 *
	 * @@aram[in] index ���ׂ�C���f�b�N�X��.
	 * @retval true ���݂��Ă���.
	 * @retval false ���݂��Ă��Ȃ�.
	 */
	bool isIndexExist( std::string& index );

private:

	/** �T�E���h�f�o�C�X�R���e�i�^ */
	typedef ObjectManager< std::string, ISoundDevice* >	SoundDeviceContainer;

	/** �Đ��o�b�t�@���X�g */
	typedef std::map< int, std::string >				PlayBufferList;	

private:

	/** �T�E���h�f�o�C�X�R���e�i */
	SoundDeviceContainer	soundDeviceContainer_;

	/** �Đ��o�b�t�@���X�g */
	PlayBufferList			playBufferList_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/