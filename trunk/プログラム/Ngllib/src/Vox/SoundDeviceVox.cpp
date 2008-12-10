/*******************************************************************************/
/**
 * @file SoundDeviceVox.cpp.
 * 
 * @brief Vox�T�E���h�f�o�C�X�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/07.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Vox/SoundDeviceVox.h"
#include	<cassert>

using namespace Ngl;
using namespace Ngl::Vox;


/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] : �Ȃ�.
 */
SoundDeviceVox::SoundDeviceVox():
	mHDll( NULL ),
	pVoxLoad( NULL ),
	pVoxPlay( NULL ),
	pVoxPause( NULL ),
	pVoxRelease( NULL ),
	pVoxCheckDevice( NULL ),
	pVoxSetVolume( NULL ),
	pVoxGetVolume( NULL ),
	pVoxFade( NULL ),
	pVoxDelete( NULL ),
	pVoxGetTotalTime( NULL ),
	pVoxGetCurrentTime( NULL ),
	pVoxSeek( NULL ),
	pVoxGetStatus( NULL ),
	pVoxGetComment( NULL ),
	pVoxParseComment( NULL )
{

	// DLL����֐��|�C���^�����[�h
#ifdef _DEBUG
	mHDll = LoadLibraryA( "Vox_d.dll" );
#else
	mHDll = LoadLibraryA( "Vox.dll" );
#endif
	pVoxLoad			= (VoxLoad*)GetProcAddress( mHDll, "VoxLoad" );
	pVoxPlay			= (VoxPlay*)GetProcAddress( mHDll, "VoxPlay" );
	pVoxRelease			= (VoxRelease*)GetProcAddress( mHDll, "VoxRelease" );
	pVoxDelete			= (VoxDelete*)GetProcAddress( mHDll, "VoxDelete" );
	pVoxPause			= (VoxPause*)GetProcAddress( mHDll, "VoxPause" );
	pVoxSetLoop			= (VoxSetLoop*)GetProcAddress( mHDll, "VoxSetLoop" );
	pVoxCheckDevice		= (VoxCheckDevice*)GetProcAddress( mHDll, "VoxCheckDevice" );
	pVoxSetVolume		= (VoxSetVolume*)GetProcAddress( mHDll, "VoxSetVolume" );
	pVoxGetVolume		= (VoxGetVolume*)GetProcAddress( mHDll, "VoxGetVolume" );
	pVoxFade			= (VoxFade*)GetProcAddress( mHDll, "VoxFade" );
	pVoxDelete			= (VoxDelete*)GetProcAddress( mHDll, "VoxDelete");
	pVoxGetTotalTime	= (VoxGetTotalTime*)GetProcAddress( mHDll, "VoxGetTotalTime" );
	pVoxGetCurrentTime	= (VoxGetCurrentTime*)GetProcAddress( mHDll, "VoxGetCurrentTime" );
	pVoxSeek			= (VoxSeek*)GetProcAddress( mHDll, "VoxSeek" );
	pVoxGetStatus		= (VoxGetStatus*)GetProcAddress( mHDll, "VoxGetStatus" );
	pVoxGetComment		= (VoxGetComment*)GetProcAddress( mHDll, "VoxGetComment" );
	pVoxParseComment	= (VoxParseComment*)GetProcAddress( mHDll, "VoxParseComment" );

	// dll�̓ǂݍ��݂Ɏ��s������
	assert( mHDll != 0 );
	
}



/*===========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] : �Ȃ�.
 */
SoundDeviceVox::~SoundDeviceVox()
{
	// �o�b�t�@�����ׂč폜
	SoundStateList::iterator itor = soundStateList_.begin();
	for( ; itor!=soundStateList_.end(); ++itor ){
		release( itor->second.bufferNo );
	}

	if( mHDll != 0 ){
		// �֐��|�C���^���N���A
		pVoxLoad			= 0;
		pVoxPlay			= 0;
		pVoxRelease			= 0;
		pVoxDelete			= 0;
		pVoxPause			= 0;
		pVoxSetLoop			= 0;
		pVoxCheckDevice		= 0;
		pVoxSetVolume		= 0;
		pVoxGetVolume		= 0;
		pVoxFade			= 0;
		pVoxDelete			= 0;
		pVoxGetTotalTime	= 0;
		pVoxGetCurrentTime	= 0;
		pVoxSeek			= 0;
		pVoxGetStatus		= 0;
		pVoxGetComment		= 0;
		pVoxParseComment	= 0;

		// DLL���J��
		FreeLibrary( mHDll );
		mHDll = 0;
	}
}



/*=========================================================================*/
/**
 * @brief �X�V����
 * 
 * @param[in] frameTimer �t���[�������␳�l.
 * @return �Ȃ�.
 */
void SoundDeviceVox::update( float frameTimer )
{
	SoundStateList::iterator itor;
	for( itor=soundStateList_.begin(); itor!=soundStateList_.end(); ++itor ){
		// �|�[�Y��Ԃ�
		if( itor->second.playState == VOXPLAYSTATE_PAUSE ){
			pause( itor->first );
		}

		// ��~��Ԃ�
		if( itor->second.playState == VOXPLAYSTATE_STOP ){
			stop( itor->first );
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
void SoundDeviceVox::createBuffer( const char* fileName, int bufNo )
{
	// �o�b�t�@���쐬
	VoxBufferNo no = create( fileName );

	// ������Ԃ�ݒ�
	VoxState state;
	state.bufferNo	= no;
	state.playState	= VOXPLAYSTATE_STOP;
	state.stateDesc = SOUNDSTATEDESC_DEFAULT;

	// �Đ��o�b�t�@�ɓo�^
	soundStateList_[ bufNo ] = state;
}



/*=========================================================================*/
/**
 * @brief �Đ�
 * 
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @param[in] playType �Đ��^�C�v.
 * @return �Ȃ�.
 */
void SoundDeviceVox::play( int bufNo, SoundPlayType playType )
{
	// �o�b�t�@�����݂��Ă��Ȃ���
	if( isExistBuffer( bufNo ) == false ){
		return;
	}

	// �Đ��^�C�v��ݒ�
	soundStateList_[ bufNo ].stateDesc.type = playType;

	// �Đ��ʒu��ݒ�
	pVoxSeek( soundStateList_[ bufNo ].bufferNo, (int)soundStateList_[ bufNo ].stateDesc.currentTime );

	// ���[�v���邩
	if( playType == SOUNDPLAYTYPE_LOOP ){
		// ���[�v��Ԃɐݒ�
		pVoxSetLoop( soundStateList_[ bufNo ].bufferNo, 65535 );
	}
	else{
		pVoxSetLoop( soundStateList_[ bufNo ].bufferNo, 0 );
	}

	// �Đ���Ԃɐݒ�
	soundStateList_[ bufNo ].playState = VOXPLAYSTATE_PLAY;

	// �Đ�
	pVoxPlay( soundStateList_[ bufNo ].bufferNo );
}



/*=========================================================================*/
/**
 * @brief �ꎞ��~
 * 
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @return �Ȃ�.
 */
void SoundDeviceVox::pause( int bufNo )
{
	// �o�b�t�@�����݂��邩
	if( isExistBuffer( bufNo ) == false ){
		return;
	}

	// ���݂̎��Ԃ�ۑ�
	soundStateList_[ bufNo ].stateDesc.currentTime = static_cast< float >( pVoxGetCurrentTime( soundStateList_[ bufNo ].bufferNo ) );

	// �Đ���Ԃɐݒ�
	soundStateList_[ bufNo ].playState = VOXPLAYSTATE_PAUSE;

	// �Đ����ꎞ��~
	pVoxPause( soundStateList_[ bufNo ].bufferNo );
}



/*=========================================================================*/
/**
 * @brief �Đ����~
 *
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @return �Ȃ�.
 */
void SoundDeviceVox::stop( int bufNo )
{
	// �o�b�t�@�����݂��邩
	if( isExistBuffer( bufNo ) == false ){
		return;
	}

	// ��~��Ԃɐݒ�
	soundStateList_[ bufNo ].playState = VOXPLAYSTATE_STOP;

	// �Đ��^�C�v���m�[�}���ɐݒ�
	soundStateList_[ bufNo ].stateDesc.type = SOUNDPLAYTYPE_NORMAL;

	// ���݂̎��Ԃ�ۑ�
	soundStateList_[ bufNo ].stateDesc.currentTime = 0;

	// �Đ����~
	pVoxSeek( soundStateList_[ bufNo ].bufferNo, 0 );
	pVoxPause( soundStateList_[ bufNo ].bufferNo );
}



/*=========================================================================*/
/**
 * @brief �Đ�����
 * 
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @retval true �Đ���.
 * @retval false �Đ����Ă��Ȃ�.
 */
bool SoundDeviceVox::isPlaying( int bufNo )
{
	// �o�b�t�@�ɑ��݂��Ă��Ȃ���
	if( isExistBuffer( bufNo ) == false ){
		return false;
	}

	// ��Ԃ��擾����
	VOXSTATE state = static_cast< VOXSTATE >( pVoxGetStatus( soundStateList_[ bufNo ].bufferNo ) );

	// �Đ�����
	if( state == STATE_PLAYING ){
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
void SoundDeviceVox::eraseBuffer( int bufNo )
{
	release( soundStateList_[ bufNo ].bufferNo );

	// �o�b�t�@���폜
	soundStateList_.erase( bufNo );
}
	
	
	
/*=========================================================================*/
/**
 * @brief ��ԋL�q�q���擾
 * 
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @return �T�E���h��ԋL�q�q.
 */
SoundStateDesc& SoundDeviceVox::soundState( int bufNo )
{
	// �T�E���h��ԋL�q�q���擾
	SoundStateDesc& desc = soundStateList_[ bufNo ].stateDesc;

	// Vox�̃o�b�t�@�ԍ����擾
	VoxBufferNo buf = soundStateList_[ bufNo ].bufferNo;

	// �{�����[����ݒ�
	desc.volume = static_cast< unsigned int >( pVoxGetVolume( buf ) * 100.0f );

	// ���݂̍Đ��ʒu��ݒ�
	desc.currentTime = static_cast< float >( pVoxGetCurrentTime( buf ) );

	// �I���ʒu��ݒ�
	desc.endTime = static_cast< float >( pVoxGetTotalTime( buf ) );

	// ���΃{�����[����ݒ�i�@�\���Ȃ��̂Ńf�t�H���g)
	desc.pan = 0;

	return desc;
}



/*=========================================================================*/
/**
 * @brief �Đ��ʒu��ݒ肷��
 * 
 * @param[in] time �ݒ肷��Đ��ʒu����.
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @return �Ȃ�.
 */
void SoundDeviceVox::setTime( float time, int bufNo )
{
	soundStateList_[ bufNo ].stateDesc.currentTime = time;

	pVoxSeek( soundStateList_[ bufNo ].bufferNo, static_cast< int >( time ) );
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
void SoundDeviceVox::setVolume( unsigned int volume, int bufNo )
{
	soundStateList_[ bufNo ].stateDesc.volume = volume;
	
	// �{�����[���䗦�����߂�
	float vol = static_cast< float >( volume ) / static_cast< float >( SOUND_VOLUME_MAX );

	pVoxSetVolume( soundStateList_[ bufNo ].bufferNo, vol );
}



/*=========================================================================*/
/**
 * @brief ���E�̃{�����[���䗦��ݒ�
 * 
 * @param[in] pan �ݒ肷��{�����[���䗦.
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @return �Ȃ�.
 */
void SoundDeviceVox::setPan( int pan, int bufNo )
{
	// �@�\���Ȃ����ߎ����Ȃ�
}

	
	
/*===========================================================================*/
/**
 * @brief Vox�o�b�t�@�쐬����
 * 
 * @param[in] fileName �t�@�C�����O.
 * @return �쐬�����h�c.
 */
VoxBufferNo SoundDeviceVox::create( const char* fileName )
{
	// const���L���X�g�ŉ���
	char* fn = const_cast< char* >( fileName );

	// �t�@�C����ǂݍ���
	VoxBufferNo bufNo = pVoxLoad( fn );

	// �쐬�����h�c��Ԃ�
	return bufNo;
}



/*===========================================================================*/
/**
 * @brief ���ł�����
 * 
 * @param[in] id voxID.
 * @return �Ȃ�.
 */
void SoundDeviceVox::release( VoxBufferNo id )
{
	// vox�I�u�W�F�N�g���J��
	pVoxRelease( id );
	pVoxDelete( id );
}



/*=========================================================================*/
/**
 * @brief �o�b�t�@�����݂��Ă��邩
 * 
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @return �Ȃ�.
 */
bool SoundDeviceVox::isExistBuffer( int bufNo )
{
	SoundStateList::iterator itor = soundStateList_.find( bufNo );
	if( itor != soundStateList_.end() ){
		return true;
	}

	return false;
}


	
/*========= EOF =============================================================*/