/*******************************************************************************/
/**
 * @file SoundDeviceBase.cpp.<br>
 * 
 * @brief �T�E���h�f�o�C�X���N���X�\�[�X�t�@�C��.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"SoundDeviceBase.h"
#include	<Ngl/Utility.h>

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^<br>
 * 
 * @param[in] �Ȃ�.
 */
SoundDeviceBase::SoundDeviceBase():
	seBufferCount_( VOICEBUFFERNO_COUNT )
{}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^<br>
 * 
 * @param[in] �Ȃ�.
 */
SoundDeviceBase::~SoundDeviceBase()
{
	soundDeviceManager_.release();
}



/*=========================================================================*/
/**
 * @brief �쐬����<br>
 * 
 * @param[in] hWnd �E�B���h�E�n���h��.
 * @return �Ȃ�.
 */
void SoundDeviceBase::Create( HWND hWnd )
{
	// Wave�T�E���h�Đ��f�o�C�X���쐬����
	soundDeviceManager_.regist( "wav", CreateWaveSoundDevice( hWnd ) );

	// Ogg�T�E���h�Đ��f�o�C�X���쐬����
	soundDeviceManager_.regist( "ogg", CreateOggSoundDevice( hWnd ) );
}



/*=========================================================================*/
/**
 * @brief �X�V����<br>
 * 
 * @param[in] frameTimer �t���[���␳�l.
 * @return �Ȃ�.
 */
void SoundDeviceBase::Update( float frameTimer )
{
	soundDeviceManager_.update( frameTimer );

	// �J�E���g��������
	if( seBufferCount_ > 30 ){
		seBufferCount_ = VOICEBUFFERNO_COUNT;
	}
}

	

/*=========================================================================*/
/**
 * @brief �I������<br>
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void SoundDeviceBase::End()
{
	soundDeviceManager_.release();
}


	
/*=========================================================================*/
/**
 * @brief �o�b�t�@�J�E���^��������<br>
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void SoundDeviceBase::InitializeBufferCount()
{
	for( int i=0; i<seBufferCount_; ++i ){
		// �o�b�t�@���N���A
		soundDeviceManager_.eraseBuffer( i );
	}

	seBufferCount_ = VOICEBUFFERNO_COUNT;
}

	
	
/*=========================================================================*/
/**
 * @brief BGM���Đ�<br>
 * 
 * @param[in] fileName �t�@�C����.
 * @return �Ȃ�.
 */
void SoundDeviceBase::PlayBGM( const char*  fileName )
{
	std::string ffn = "Resource/";
	ffn += fileName;

	// �o�b�t�@���쐬
	soundDeviceManager_.createBuffer( ffn.c_str(), Ngl::BGM_BUFFER );

	// �o�b�t�@���Đ�
	soundDeviceManager_.play( Ngl::BGM_BUFFER, Ngl::SOUNDPLAYTYPE_LOOP );
}



/*=========================================================================*/
/**
 * @brief SE���Đ�<br>
 * 
 * @param[in] fileName �t�@�C����.
 * @param[in] playType �Đ����@�t���O.
 * @return �Đ��o�b�t�@�ԍ�.
 */
int SoundDeviceBase::PlaySE( const char* fileName, SoundPlayType playType )
{
	std::string ffn = "Resource/";
	ffn += fileName;

	// �o�b�t�@���쐬
	soundDeviceManager_.createBuffer( ffn.c_str(), seBufferCount_ );

	// �o�b�t�@���Đ�
	soundDeviceManager_.play( seBufferCount_, playType );

	int tmpbuf = seBufferCount_;

	// �J�E���^�𑝂₷
	seBufferCount_++;

	return tmpbuf;
}



/*=========================================================================*/
/**
 * @brief �{�C�X���Đ�<br>
 * 
 * @param[in] fileName �t�@�C����.
 * @param[in] bufno �{�C�X�o�b�t�@�ԍ�.
 * @return �Ȃ�.
 */
void SoundDeviceBase::PlayVoice( const char*  fileName, VoiceBufferNo bufno )
{
	std::string ffn = "Resource/";
	ffn += fileName;

	// �o�b�t�@���쐬
	soundDeviceManager_.createBuffer( ffn.c_str(), bufno );

	// �o�b�t�@���Đ�
	soundDeviceManager_.play( bufno, Ngl::SOUNDPLAYTYPE_NORMAL );
}
	

	
/*=========================================================================*/
/**
 * @brief BGM�Đ����~<br>
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void SoundDeviceBase::StopBGM()
{
	soundDeviceManager_.stop( Ngl::BGM_BUFFER );
	soundDeviceManager_.eraseBuffer( Ngl::BGM_BUFFER );
}



/*=========================================================================*/
/**
 * @brief SE�Đ����~<br>
 * 
 * @param[in] bufNo �o�b�t�@�ԍ�.
 * @return �Ȃ�.
 */
void SoundDeviceBase::StopSE( int bufNo )
{
	soundDeviceManager_.stop( bufNo );
	soundDeviceManager_.eraseBuffer( bufNo );
}



/*===== EOF ==================================================================*/