/*******************************************************************************/
/**
 * @file WaveResourceDS.cpp.
 * 
 * @brief DirectSound Wave�t�H�[�}�b�g���\�[�X�N���X�\�[�X�t�@�C��.
 *
 * @date 2007/09/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"WaveResourceDS.h"
#include	"WaveDSException.h"
#include	<fstream>
#include	<memory>
#include	<cassert>


using namespace Ngl;
using namespace Ngl::DirectSound;


/*=========================================================================*/
/**
 * @brief �쐬����
 * 
 * @param[in] fileName �t�@�C����.
 * @param[in] ds �_�C���N�g�T�E���h�I�u�W�F�N�g.
 * @param[in] enable3D 3D�T�E���h��L���ɂ��邩.
 * @return �_�C���N�g�T�E���h�o�b�t�@.
 */
IDirectSoundBuffer* WaveResourceDS::create( const char* fileName, IDirectSound8* ds, bool enable3D )
{
	IDirectSoundBuffer*	buffer = NULL;	// �_�C���N�g�T�E���h�o�b�t�@

	try{	
		// Wave�t�H�[�}�b�g�f�[�^��ǂݍ���
		readWaveFormat( fileName );
		
		// Wave�f�[�^��ǂݍ���
		readWaveData();
		
		// �T�E���h�o�b�t�@���쐬
		buffer = createSoundBuffer( ds, enable3D );
		
		// �g�`�f�[�^����������
		writeWaveData( buffer, fileName );
	}
	catch( WaveDSException& e ){
		// �쐬�����o�b�t�@���폜
		if( buffer != NULL ){
			buffer->Release();
		}

		// �G���[���b�Z�[�W���o��
		e.add( "WaveResourceDS", "create" );
		e.outputConsol();
	}
	
	return buffer;
}



/*=========================================================================*/
/**
 * @brief Wave�t�H�[�}�b�g��ǂݍ���
 * 
 * @param[in] fileName �t�@�C����.
 * @return �Ȃ�.
 * @throw Ngl::DirectSound::WaveDSException Wave�t�@�C����O.
 */
void WaveResourceDS::readWaveFormat( const char* fileName )
{
	MMRESULT result = MMSYSERR_NOERROR;	// ���s����
	
	// WAV�t�@�C�����̃w�b�_�[���i���f�[�^�ȊO�j�̊m�F�Ɠǂݍ���
	hMmio_ = mmioOpenA( const_cast< LPSTR >( fileName ), NULL, MMIO_ALLOCBUF | MMIO_READ );
	assert( hMmio_ != 0 );
	
	//�t�@�C���|�C���^��RIFF�`�����N�̐擪�ɃZ�b�g����
	result = mmioDescend( hMmio_, &riffckInfo_, NULL, 0 );
	assert( result == MMSYSERR_NOERROR );
	
	//�`�����N���ɂ��WAV�t�@�C�����ǂ����m�F����
	if( ( riffckInfo_.ckid != mmioFOURCC('R', 'I', 'F', 'F') ) || ( riffckInfo_.fccType != mmioFOURCC('W', 'A', 'V', 'E') ) ){
		throw WaveDSException( "This is not WaveFile", "WaveResourceDS", "readWaveFormat" );
	}
	
	// �t�@�C���|�C���^��'f' 'm' 't' ' ' �`�����N�ɃZ�b�g����
	ckInfo_.ckid = mmioFOURCC('f', 'm', 't', ' ');
	result = mmioDescend( hMmio_, &ckInfo_, &riffckInfo_, MMIO_FINDCHUNK );
	assert( result == MMSYSERR_NOERROR );
	
	// �t�H�[�}�b�g��ǂݍ���
	if( mmioRead( hMmio_, (HPSTR) &pcmWaveFormat_, sizeof(pcmWaveFormat_)) != sizeof(pcmWaveFormat_) ){
		throw WaveDSException( "Wave Read format failed.", "WaveResourceDS", "readWaveFormat" );
	}
}

	
	
/*=========================================================================*/
/**
 * @brief Wave�f�[�^��ǂݍ���
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 * @throw Ngl::DirectSound::WaveDSException Wave�t�@�C����O.
 */
void WaveResourceDS::readWaveData()
{
	// ���j�APCM�ŁA���A�}���`�`�����l��WAV�͑z��O
	if( pcmWaveFormat_.wf.wFormatTag == WAVE_FORMAT_PCM ){
		waveFormat_ = (LPWAVEFORMATEX) new CHAR[ sizeof(WAVEFORMATEX) ];
		if( waveFormat_ == 0 ){
			throw WaveDSException( "This Type is not Readable", "WaveResourceDS", "readWaveData" );
		}
		// �t�H�[�}�b�g�f�[�^��ǂݍ���
		std::memcpy( waveFormat_, &pcmWaveFormat_, sizeof(pcmWaveFormat_) );
		waveFormat_->cbSize = 0;
	}
	else{
		delete[] waveFormat_;
		throw WaveDSException( "MulteChannelWaveFile can not opened", "WaveResourceDS", "readWaveData" );
	}

	// RIFF �t�@�C���̃`�����N����ޏo�ł��Ȃ�������
	if( mmioAscend( hMmio_, &ckInfo_, 0 ) != MMSYSERR_NOERROR ){
		delete[] waveFormat_;
		throw WaveDSException( "WaveData read erroer", "WaveResourceDS", "readWaveData" );
    }

	// WAV�t�@�C�����̉��f�[�^�̓ǂݍ���
	ckInfo_.ckid = mmioFOURCC('d', 'a', 't', 'a');
    MMRESULT result = mmioDescend( hMmio_, &ckInfo_, &riffckInfo_, MMIO_FINDCHUNK );
	if( result != MMSYSERR_NOERROR ){
		delete[] waveFormat_;
		throw WaveDSException( "WaveData read erroer", "WaveResourceDS", "readWaveData" );
	}
}
	
	
	
/*=========================================================================*/
/**
 * @brief DirectSound�o�b�t�@���쐬
 * 
 * @param[in] ds �_�C���N�g�T�E���h�I�u�W�F�N�g.
 * @param[in] enable3D 3D�T�E���h��L���ɂ��邩.
 * @return �쐬�����o�b�t�@.
 */
IDirectSoundBuffer* WaveResourceDS::createSoundBuffer( IDirectSound8* ds, bool enable3D )
{
	IDirectSoundBuffer* buffer = NULL; // �T�E���h�o�b�t�@

	DWORD flags		= 0;				// �f�o�C�X�t���O
	GUID algorithm	= DS3DALG_DEFAULT;	// �Đ��A���S���Y��

	// 3D���L����
	if( enable3D ==true ){
		flags = DSBCAPS_CTRL3D |				// 3D�T�E���h
				DSBCAPS_MUTE3DATMAXDISTANCE;	// �ő勗���ȏ�Ŗ���

		algorithm = DS3DALG_HRTF_FULL;			// ���i���� 3D �I�[�f�B�I �A���S���Y��
	}
	else{
		flags =	DSBCAPS_CTRLPAN |				// �p���̑���
				DSBCAPS_CTRLVOLUME |			// �{�����[���̑���
				DSBCAPS_CTRLPOSITIONNOTIFY |	// �ʒu����
				DSBCAPS_GETCURRENTPOSITION2;	// �ʒu�擾
	}

	// �Z�J���_���o�b�t�@�L�q�q���쐬
	DSBUFFERDESC dsbd;
	ZeroMemory( &dsbd, sizeof(DSBUFFERDESC) );
	dsbd.dwSize				= sizeof(DSBUFFERDESC);	// �\���̂̃T�C�Y
	dsbd.dwFlags			= flags;				// �f�o�C�X�t���O
	dsbd.dwBufferBytes		= ckInfo_.cksize;		// wave�f�[�^�̃T�C�Y
	dsbd.lpwfxFormat		= waveFormat_;			// wave�t�H�[�}�b�g
	dsbd.guid3DAlgorithm	= algorithm;			// �Đ��A���S���Y��

	// DirectSound�Z�J���_���[�o�b�t�@�[�쐬
	HRESULT hr = ds->CreateSoundBuffer( &dsbd, &buffer, NULL );

	// 3D�Đ��ŁA���i��3D�A���S���Y�����g�p�ł��Ȃ�����
	if( enable3D == true && hr != DS_OK ){
		// ��i�K�Ⴂ�A���S���Y���ݒ�ōč쐬������
		dsbd.guid3DAlgorithm = DS3DALG_HRTF_LIGHT;
		hr = ds->CreateSoundBuffer( &dsbd, &buffer, NULL );
	}
	assert( hr == DS_OK );

	return buffer;
}

	
	
/*=========================================================================*/
/**
 * @brief Wave�g�`�f�[�^����������
 * 
 * @param[out] buffer �쐬�����o�b�t�@.
 * @param[in] fileName wave�t�@�C����.
 * @return �Ȃ�.
 * @throw Ngl::DirectSound::WaveDSException Wave�t�@�C����O.
 */
void WaveResourceDS::writeWaveData( IDirectSoundBuffer* buffer, const char* fileName )
{
	// �g�`�f�[�^���������ޏ����Ƃ��āA�Z�J���_���[�o�b�t�@�[�����b�N����
	VOID* pBuffer		= 0;
	DWORD dwBufferSize	= 0;
	if( FAILED( buffer->Lock( 0, ckInfo_.cksize, &pBuffer, &dwBufferSize, 0, 0, 0 ) ) ){
		delete[] waveFormat_;
	    throw WaveDSException( "BufferLock error", "WaveResourceDS", "writeWaveData" ); 
	}
	
	// ���b�N�����o�b�t�@�[�T�C�Y�����ۂ̔g�`�f�[�^���傫��(�N���b�V���h�~)
	DWORD dwSize = dwBufferSize;
	if( dwSize > ckInfo_.cksize ){
		// �T�C�Y��␳
		dwSize = ckInfo_.cksize;
	}
	
	// �o�b�t�@�[�ɉ��f�[�^����������
	std::ifstream is( fileName, std::ios::in | std::ios::binary );
	is.seekg( riffckInfo_.dwDataOffset + sizeof(FOURCC), std::ios::beg );
	BYTE* pWavData = new BYTE[ dwSize ];

	// �܂��́A�ꎞ�I�ȏꏊ(pWavData)�ɔg�`�f�[�^��ǂݍ���
	is.read( (char*)pWavData, dwSize );

	// �ꎞ�I�ȏꏊ�̔g�`�f�[�^���Z�J���_���o�b�t�@�[�ɃR�s�[����
	for( DWORD i = 0; i < dwSize; i++ ){
		*((BYTE*)pBuffer+i) = *((BYTE*) pWavData+i);
	}

	// �t�H�[�}�b�g���폜
	delete[] waveFormat_;
	
	//�ꎞ�I�Ȕg�`�f�[�^���J������
	delete[] pWavData;

	// �o�b�t�@���A�����b�N����B
	buffer->Unlock( pBuffer, dwBufferSize, 0, 0 );
}
	
	
	
/*========= EOF =============================================================*/