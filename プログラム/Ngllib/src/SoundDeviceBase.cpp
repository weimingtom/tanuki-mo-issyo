/*******************************************************************************/
/**
 * @file SoundDeviceBase.cpp.
 * 
 * @brief �T�E���h�f�o�C�X���N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/19.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/SoundDeviceBase.h"
#include	<cassert>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
SoundDeviceBase::SoundDeviceBase()
{}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
SoundDeviceBase::~SoundDeviceBase()
{
	clearBuffer();
}



/*=========================================================================*/
/**
 * @brief �X�V����
 * 
 * @param[in] frameTimer �t���[�������␳�l.
 * @return �Ȃ�.
 */
void SoundDeviceBase::update( float frameTimer )
{
	SoundList::iterator itor;
	for( itor=soundList_.begin(); itor!=soundList_.end(); ++itor ){
		// ���[�v�w�肩
		ISoundResource* res = itor->second;
		if( res->soundState().type == SOUNDPLAYTYPE_LOOP ){
			// �Đ����I�����Ă��邩
			if( res->isPlay() == false ){
				// �Đ��ʒu��������
				res->setTime( 0 );

				// �Đ����J�n
				res->play();
			}
		}
	}
}


	
/*=========================================================================*/
/**
 * @brief �o�b�t�@���쐬
 * 
 * @param[in] fileName �t�@�C����.
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @return �Ȃ�.
 */
void SoundDeviceBase::createBuffer( const char* fileName, int bufNo )
{
	// �o�b�t�@�����݂��Ă��邩
	if( isBufferExist( bufNo ) ){
		// �o�b�t�@���N���A
		releaseBuffer( bufNo );
	}

	// ���\�[�X���쐬
	ISoundResource* res = create( fileName );
	assert( res != NULL );

	// �T�E���h���X�g�ɓo�^
	soundList_[ bufNo ] = res;
}



/*=========================================================================*/
/**
 * @brief �Đ�
 * 
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @param[in] playType �Đ��^�C�v.
 * @return �Ȃ�.
 */
void SoundDeviceBase::play( int bufNo, SoundPlayType playType )
{
	// �I�u�W�F�N�g�̍Đ����@��ݒ�
	soundList_[bufNo]->setType( playType );

	// �Đ�����
	soundList_[bufNo]->play();
}



/*=========================================================================*/
/**
 * @brief �ꎞ��~
 * 
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @return �Ȃ�.
 */
void SoundDeviceBase::pause( int bufNo )
{
	// �o�b�t�@�����݂��Ă��Ȃ���
	if( isBufferExist( bufNo ) == false ){
		return;
	}

	// �Đ�����
	if( soundList_[ bufNo ]->isPlay() == false ){
		return;
	}

	soundList_[ bufNo ]->pause();
}



/*=========================================================================*/
/**
 * @brief �Đ����~
 *
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @return �Ȃ�.
 */
void SoundDeviceBase::stop( int bufNo )
{
	// �o�b�t�@�����݂��Ă��Ȃ���
	if( isBufferExist( bufNo ) == false ){
		return;
	}

	ISoundResource* res = soundList_[ bufNo ];

	// �Đ��҂��w�肩
	if( res->soundState().type == SOUNDPLAYTYPE_WAIT ){
		// �Đ����I�����Ă��Ȃ�
		if( res->isPlay() == false ){
			return;
		}
	}

	// �Đ��^�C�v���f�t�H���g�ɍĐݒ�
	res->setType( SOUNDPLAYTYPE_NORMAL );

	// �Đ����~����
	soundList_[ bufNo ]->stop();
}



/*=========================================================================*/
/**
 * @brief �Đ�����
 * 
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @retval true �Đ���.
 * @retval false �Đ����Ă��Ȃ�.
 */
bool SoundDeviceBase::isPlaying( int bufNo )
{
	return soundList_[ bufNo ]->isPlay();
}



/*=========================================================================*/
/**
 * @brief �o�b�t�@���폜
 *
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @return �Ȃ�.
 */
void SoundDeviceBase::eraseBuffer( int bufNo )
{
	// �o�b�t�@�����݂��Ă��Ȃ���
	if( isBufferExist( bufNo ) == false ){
		return;
	}

	// �Đ�����
	if( soundList_[ bufNo ]->isPlay() == false ){
		// �Đ����~
		stop( bufNo );
	}

	// �o�b�t�@���J������
	releaseBuffer( bufNo );
}



/*=========================================================================*/
/**
 * @brief ��ԋL�q�q���擾
 * 
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @return �T�E���h��ԋL�q�q.
 */
SoundStateDesc& SoundDeviceBase::soundState( int bufNo )
{
	return soundList_[ bufNo ]->soundState();
}



/*=========================================================================*/
/**
 * @brief �Đ��ʒu��ݒ肷��
 * 
 * @param[in] time �ݒ肷��Đ��ʒu����.
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @return �Ȃ�.
 */
void SoundDeviceBase::setTime( float time, int bufNo )
{
	soundList_[ bufNo ]->setTime( time );
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
void SoundDeviceBase::setVolume( unsigned int volume, int bufNo )
{
	soundList_[ bufNo ]->setVolume( volume );
}



/*=========================================================================*/
/**
 * @brief ���E�̃{�����[���䗦��ݒ�
 * 
 * @param[in] pan �ݒ肷��{�����[���䗦.
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @return �Ȃ�.
 */
void SoundDeviceBase::setPan( int pan, int bufNo )
{
	soundList_[ bufNo ]->setPan( pan );
}



/*===========================================================================*/
/**
 * @brief �w��̃o�b�t�@�����݂��Ă��邩���ׂ�
 * 
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @retval true ���݂��Ă���.
 * @retval false ���݂��Ă��Ȃ�.
 */
bool SoundDeviceBase::isBufferExist(int bufNo)
{
	SoundList::iterator itor;
	for( itor=soundList_.begin(); itor!=soundList_.end(); ++itor ){
		if( itor->first == bufNo ){
			return true;
		}
	}

	// ���݂��Ă��Ȃ�
	return false;
}



/*===========================================================================*/
/**
 * @brief �w��̃o�b�t�@���������
 * 
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @retval true �폜����.
 * @retval false �폜���s.
 */
bool SoundDeviceBase::releaseBuffer(int bufNo)
{
	// ���X�g�̑S�v�f����������
	SoundList::iterator i = soundList_.find( bufNo );

	// �����܂ł��ǂ蒅����
	if( i == soundList_.end() ){
		// �o�b�t�@�����݂��Ȃ�
		return false;
	}

	// �Đ����~����
	i->second->stop();

	// �v�f���폜����
	delete i->second;

	// ���X�g����폜����
	i = soundList_.erase( i );

	// �폜����
	return true;

}



/*=========================================================================*/
/**
 * @brief �o�b�t�@�����ׂĉ������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void SoundDeviceBase::clearBuffer()
{
	// ���X�g�̑S�v�f���폜����
	SoundList::iterator i = soundList_.begin();
	while( i != soundList_.end() ){
		// �Đ�����
		if( i->second->isPlay() == true ){
			// �Đ����~����
			i->second->stop();
		}
		
		// �v�f���폜����
		delete i->second;

		// ���X�g����폜����
		i = soundList_.erase( i );
	}
}
	
	
	
/*===== EOF ==================================================================*/