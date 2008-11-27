/*******************************************************************************/
/**
 * @file DirectSoundSocket.cpp.
 * 
 * @brief DirectSound �\�P�b�g�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentaru Nishimura.
 */
/******************************************************************************/
#include	"DirectSoundSocket.h"
#include	<cassert>

using namespace Ngl;
using namespace Ngl::DirectSound;


/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
DirectSoundSocket::DirectSoundSocket():
	buffer_( NULL ),		// �_�C���N�g�T�E���h�I�u�W�F�N�g
	buffer3D_( NULL ),		// �_�C���N�g�RD�T�E���h�I�u�W�F�N�g
	listener3D_( NULL ),	// �_�C���N�g�RD���X�i�[�I�u�W�F�N�g
	waveFormat_( NULL ),	// DirectSoundSocket�t�@�C���t�H�[�}�b�g
	waveDataSize_( NULL )	// DirectSoundSocket�f�[�^�T�C�Y
{}



/*===========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
DirectSoundSocket::~DirectSoundSocket()
{
	// �������
	release();
}



/*===========================================================================*/
/**
 * @brief �쐬����
 * 
 * @param[in] fileName �t�@�C����.
 * @param[in] ds �_�C���N�g�T�E���h�I�u�W�F�N�g.
 * @param[in] rg ���\�[�X�N���X�̃|�C���^.
 * @retval true �쐬����.
 * @retval false �쐬���s.
 */
bool DirectSoundSocket::create( const char *fileName, IDirectSound8* ds, IDirectSoundResource* rg )
{
	// �\�[�X����o�b�t�@���쐬����
	buffer_ = rg->create( fileName, ds );
	assert( buffer_ != NULL );

	// 3D�o�b�t�@���擾����
	HRESULT hr = DS_OK;
	hr = buffer_->QueryInterface( IID_IDirectSound3DBuffer8, (VOID**)&buffer3D_ );
	if( hr != DS_OK ){
		// 3D�Đ����s�\
		return false;
	}
	
	// �v���C�}���[�o�b�t�@���擾
	LPDIRECTSOUNDBUFFER primary = NULL;
	DSBUFFERDESC dsbd;
	ZeroMemory( &dsbd, sizeof( DSBUFFERDESC ) );
	dsbd.dwSize		= sizeof( DSBUFFERDESC );
	dsbd.dwFlags	= DSBCAPS_CTRL3D | DSBCAPS_PRIMARYBUFFER;
	ds->CreateSoundBuffer( &dsbd, &primary, NULL );
	assert( primary != NULL );

	// ���X�i�[�I�u�W�F�N�g���擾����
	primary->QueryInterface( IID_IDirectSound3DListener8, (VOID**)&listener3D_ );
	primary->Release();
	assert( listener3D_ != NULL );

	// �쐬����
	return true;
}



/*===========================================================================*/
/**
 * @brief ���ł�����
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void DirectSoundSocket::release()
{
	// 3D�T�E���h�o�b�t�@���N���A
	buffer3D_	= NULL;
	listener3D_	= NULL;

	// �o�b�t�@���쐬����Ă��邩
	if( buffer_ != 0 ){
		// �t�H�[�}�b�g�����폜
		delete waveFormat_;
		waveFormat_;

		// �o�b�t�@���J������
		buffer_->Release();
		buffer_;
	}
}



/*===========================================================================*/
/**
 * @brief �Đ�����
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void DirectSoundSocket::play()
{
	// �쐬����Ă��邩
	assert( buffer_ != NULL );

	DWORD dwStatus	= 0;	// �Đ����

	// �T�E���h�o�b�t�@�̏�Ԃ��擾����
	if( buffer_->GetStatus( &dwStatus ) != DS_OK ){
		return;
	}

	// �T�E���h�o�b�t�@�������Ă��邩�`�F�b�N����
	if( ( dwStatus & DSBSTATUS_BUFFERLOST ) == DSBSTATUS_BUFFERLOST ){
		// �T�E���h�o�b�t�@�𕜌�����
		if( buffer_->Restore() != DS_OK ){
			return;
		}
	}

	// �Đ����̃`�F�b�N
	if( ( dwStatus & DSBSTATUS_PLAYING ) == DSBSTATUS_PLAYING ){
		// �T�E���h���~����
		stop();
	}

	// �Đ��ʒu��ݒ�
	buffer_->SetCurrentPosition( static_cast< DWORD >( soundState_.currentTime ) );

	// �T�E���h���Đ�����
	if( buffer_->Play( 0, 0, 0 ) != DS_OK ){
		return;
	}
}



/*===========================================================================*/
/**
 * @brief �Đ��������ׂ�
 * 
 * @param[in] �Ȃ�.
 * @retval true �Đ���.
 * @retval false ��~��.
 */
bool DirectSoundSocket::isPlay()
{
	DWORD dwStatus;	// �o�b�t�@�̏��

	// �T�E���h�o�b�t�@�̏�Ԃ��擾����
	if( buffer_->GetStatus( &dwStatus ) != DS_OK ){
		return false;
	}

	// �Đ������`�F�b�N����
	if( (  dwStatus & DSBSTATUS_PLAYING ) == DSBSTATUS_PLAYING ){
		// �Đ���������
		return true;
	}
	
	// �Đ����Ă��Ȃ�����
	return false;
}



/*=========================================================================*/
/**
 * @brief �ꎞ��~
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void DirectSoundSocket::pause()
{
	buffer_->GetCurrentPosition( (LPDWORD)&soundState_.currentTime, NULL );

	// ��~����
	buffer_->Stop();
}

	
	
/*===========================================================================*/
/**
 * @brief ��~����
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void DirectSoundSocket::stop()
{
	// ��~����
	buffer_->Stop();
	
	// �Đ��ʒu��������
	soundState_.currentTime = 0.0f;
}



/*=========================================================================*/
/**
 * @brief ��ԋL�q�q���擾
 * 
 * @param[in] �Ȃ�.
 * @return �T�E���h��ԋL�q�q.
 */
SoundStateDesc& DirectSoundSocket::soundState()
{
	// ���݂̍Đ��ʒu���擾
	buffer_->GetCurrentPosition( reinterpret_cast< LPDWORD >( &soundState_.currentTime ), 0 );
	
	// DirectSound�ł͋Ȃ̒������擾�ł��Ȃ��̂ŁA0��ݒ�
	soundState_.endTime = 0;

	// �p���̒l���擾
	long pan = 0;
	buffer_->GetPan( &pan );
	soundState_.pan = static_cast< int >( pan );

	// �{�����[���̒l���擾
	long volume = 0;
	buffer_->GetVolume( &volume );
	soundState_.volume = static_cast< unsigned int >( volume ) + ( SOUND_VOLUME_MAX * 100 );

	return soundState_;
}



/*=========================================================================*/
/**
 * @brief �Ȃ̍Đ��^�C�v��ݒ�
 * 
 * @param[in] type �Đ��^�C�v.
 * @return �Ȃ�.
 */
void DirectSoundSocket::setType( SoundPlayType type )
{
	soundState_.type = type;
}



/*=========================================================================*/
/**
 * @brief �Đ��ʒu��ݒ肷��
 * 
 * @param[in] time �ݒ肷��Đ��ʒu����( �~���b ).
 * @return �Ȃ�.
 */
void DirectSoundSocket::setTime( float time )
{
	soundState_.currentTime = time;

	// �Đ������Ȃ���
	play();
}



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
void DirectSoundSocket::setVolume( unsigned int volume )
{
	soundState_.volume = volume;

	// �{�����[���l��ݒ�
	//  -10000( DSBVOLUME_MIN ���� )�`0( DSBVOLUME_MAX )
	buffer_->SetVolume( static_cast< LONG >( -10000 + ( soundState_.volume * 100 )  ) );
}



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
void DirectSoundSocket::setPan( int pan )
{
	soundState_.pan = pan;

	// ���E�̃{�����[���䗦��ݒ�
	// -10000�iDSBPAN_LEFT�j���� 10000�iDSBPAN_RIGHT�j �͈̔͂Őݒ�\
	// 0�iDSBPAN_CENTER�j�������l�� �����̃`�����l�����ő�{�����[���ƂȂ�܂�
	// 1/100 �f�V�x�� (dB) �̒P�ʂő��肳��܂�
	long value = soundState_.pan * 100;
	buffer_->GetPan( reinterpret_cast< LPLONG >( &value ) );
}


	
// ��X���p���邽�ߕۑ�
///*=========================================================================*/
///**
// * @brief �p�����[�^��ݒ�
// *
// * @param[in] desc �T�E���h�p�����[�^�L�q�q.
// * @return �Ȃ�.
// */
//void DirectSoundSocket::soundParameterDesc( const SoundParameterDesc& desc )
//{	
//	soundParameter_ = desc;
//
//	// �o�b�t�@���쐬����Ă��Ȃ�
//	if( buffer_ == NULL ){
//		return;
//	}
//
//	// �{�����[���l��ݒ�
//	buffer_->SetVolume( static_cast< LONG >( soundParameter_.volume ) );
//
//	// �p���̒l��ݒ�
//	buffer_->SetPan( static_cast< LONG >( soundParameter_.pan ) );
//
//	// 3D�o�b�t�@���쐬����Ă��Ȃ���
//	if( buffer3D_ == NULL ){
//		return;
//	}
//
//	// �ŏ������ƍő勗����ݒ�
//	buffer3D_->SetMinDistance( 1,		DS3D_IMMEDIATE );
//	buffer3D_->SetMaxDistance( 10000,	DS3D_IMMEDIATE );
//
//	// �����̑��x��ݒ�( 40KM/h )
//	buffer3D_->SetVelocity( 0, 0, 40, DS3D_IMMEDIATE );
//
//	// �Đ��ʒu��ݒ�
//	buffer3D_->SetPosition(
//		soundParameter_.soundPosition.x,
//		soundParameter_.soundPosition.y,
//		soundParameter_.soundPosition.z,
//		DS3D_IMMEDIATE
//		);
//
//	// ���X�i�[�I�u�W�F�N�g���쐬����Ă��Ȃ���
//	if( listener3D_ == NULL ){
//		return;
//	}
//
//	// ���X�i�[�̈ʒu��ݒ�
//	listener3D_->SetPosition(
//		soundParameter_.listenerPosition.x,
//		soundParameter_.listenerPosition.y,
//		soundParameter_.listenerPosition.z,
//		DS3D_IMMEDIATE
//		);
//
//	// �h�b�v���[�̂�������ݒ�
//	listener3D_->SetDopplerFactor( 100, DS3D_IMMEDIATE );
//}
	
	
	
/*========= EOF =============================================================*/