/*******************************************************************************/
/**
 * @file SoundDeviceManager.cpp.
 * 
 * @brief �T�E���h�f�o�C�X�Ǘ��҃N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/06.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimuara.
 */
/******************************************************************************/
#include	"Ngl/SoundDeviceManager.h"
#include	"Ngl/Manager/EntityVisitorMemFun1.h"
#include	"Ngl/Utility.h"
#include	<functional>
#include	<algorithm>
#include	<cassert>

using namespace Ngl;


/** �X�V�����K��� */
typedef EntityVisitorMemFun1< ISoundDevice, float, &ISoundDevice::update >	UpdataVisitor;


/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
SoundDeviceManager::SoundDeviceManager()
{}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
SoundDeviceManager::~SoundDeviceManager()
{}



/*=========================================================================*/
/**
 * @brief �f�o�C�X��o�^
 * 
 * @param[in] extName �o�^����g���q��( .�͊܂܂Ȃ� ).
 * @param[in] device �o�^����f�o�C�X�̃|�C���^.
 *
 * @return �Ȃ�.
 */
void SoundDeviceManager::regist( std::string extName, ISoundDevice* device )
{
	assert( device != NULL );

	// ���łɑ��݂��Ă��邩
	if( isIndexExist( extName ) == true ){
		// �f�o�C�X���폜
		eraseDevice( extName );
	}

	// �f�o�C�X��o�^
	soundDeviceContainer_.add( extName, device );
}



/*=========================================================================*/
/**
 * @brief �w��̃f�o�C�X���폜
 * 
 * @param[in] extName �폜����g���q��( .�͊܂܂Ȃ� ).
 *
 * @return �Ȃ�.
 */
void SoundDeviceManager::eraseDevice( std::string extName )
{
	soundDeviceContainer_.remove( extName );
}
	
	

/*=========================================================================*/
/**
 * @brief �������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void SoundDeviceManager::release()
{
	soundDeviceContainer_.clear();
}

	
	
/*=========================================================================*/
/**
 * @brief �X�V����
 * 
 * @param[in] frameTimer �t���[�������␳�l.
 * @return �Ȃ�.
 */
void SoundDeviceManager::update( float frameTimer )
{
	UpdataVisitor uv( frameTimer );
	soundDeviceContainer_.accept( uv );
}

	
	
/*=========================================================================*/
/**
 * @brief �o�b�t�@���쐬
 * 
 * @param[in] fileName �t�@�C����.
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @return �Ȃ�.
 */
void SoundDeviceManager::createBuffer( const char* fileName, int bufNo )
{
	// �g���q�𔲂��o��
	std::string ext = Utility::getFileExtension( fileName );

	// �o�^���ꂽ�g���������݂��邩
	bool result = isIndexExist( ext );
	assert( result == true );

	// ��~����
	stop( bufNo );

	// ���X�g�ɓo�^
	soundDeviceContainer_[ ext ]->createBuffer( fileName, bufNo );
	playBufferList_[ bufNo ] = ext;
}

	
	
/*=========================================================================*/
/**
 * @brief �Đ�
 * 
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @param[in] playType �Đ��^�C�v.
 * @return �Ȃ�.
 */
void SoundDeviceManager::play( int bufNo, SoundPlayType playType )
{
	// �o�b�t�@�ԍ�������
	PlayBufferList::iterator itor = playBufferList_.find( bufNo );
	if( itor != playBufferList_.end() ){
		soundDeviceContainer_[ itor->second ]->play( bufNo, playType );
	}
}



/*=========================================================================*/
/**
 * @brief �Đ����~
 *
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @return �Ȃ�.
 */
void SoundDeviceManager::stop( int bufNo )
{
	// �o�b�t�@�ԍ�������
	PlayBufferList::iterator itor = playBufferList_.find( bufNo );
	if( itor != playBufferList_.end() ){
		soundDeviceContainer_[ itor->second ]->stop( bufNo );
	}
}



/*=========================================================================*/
/**
 * @brief �ꎞ��~
 * 
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @return �Ȃ�.
 */
void SoundDeviceManager::pause( int bufNo )
{
	if( isPlaying( bufNo ) == false ){
		return;
	}

	soundDeviceContainer_[ playBufferList_[ bufNo ] ]->pause( bufNo );
}

	
	
/*=========================================================================*/
/**
 * @brief �Đ�����
 * 
 * @param[in] bufNo ���ׂ�o�b�t�@�ԍ�.
 * @retval true �Đ���.
 * @retval false �Đ����Ă��Ȃ�.
 */
bool SoundDeviceManager::isPlaying( int bufNo )
{
	if( playBufferList_.find( bufNo ) != playBufferList_.end() ){
		return true;
	}
	return false;
}

	
	
/*=========================================================================*/
/**
 * @brief �o�b�t�@���폜
 *
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @return �Ȃ�.
 */
void SoundDeviceManager::eraseBuffer( int bufNo )
{
	// �o�b�t�@�ԍ�������
	PlayBufferList::iterator itor = playBufferList_.find( bufNo );
	if( itor != playBufferList_.end() ){
		soundDeviceContainer_[ itor->second ]->eraseBuffer( bufNo );

		// �o�b�t�@���X�g����폜
		playBufferList_.erase( itor );
	}
}


	
/*=========================================================================*/
/**
 * @brief ��ԋL�q�q���擾
 * 
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @return �T�E���h��ԋL�q�q.
 */
SoundStateDesc& SoundDeviceManager::soundState( int bufNo )
{
	return soundDeviceContainer_[ playBufferList_[ bufNo ] ]->soundState( bufNo );
}



/*=========================================================================*/
/**
 * @brief �Đ��ʒu��ݒ肷��
 * 
 * @param[in] time �ݒ肷��Đ��ʒu����.
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @return �Ȃ�.
 */
void SoundDeviceManager::setTime( float time, int bufNo )
{
	soundDeviceContainer_[ playBufferList_[ bufNo ] ]->setTime( time, bufNo );
}



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
void SoundDeviceManager::setVolume( unsigned int volume, int bufNo )
{
	soundDeviceContainer_[ playBufferList_[ bufNo ] ]->setVolume( volume, bufNo );
}



/*=========================================================================*/
/**
 * @brief ���E�̃{�����[���䗦��ݒ�
 * 
 * @param[in] pan �ݒ肷��{�����[���䗦.
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @return �Ȃ�.
 */
void SoundDeviceManager::setPan( int pan, int bufNo )
{
	soundDeviceContainer_[ playBufferList_[ bufNo ] ]->setPan( pan, bufNo );
}



/*=========================================================================*/
/**
 * @brief �w��̗v�f�����łɑ��݂��Ă��邩���ׂ�
 *
 * @@aram[in] index ���ׂ�C���f�b�N�X��.
 * @retval true ���݂��Ă���.
 * @retval false ���݂��Ă��Ȃ�.
 */
bool SoundDeviceManager::isIndexExist( std::string& index )
{
	return soundDeviceContainer_.isExist( index );
}
	
	

/*===== EOF ==================================================================*/