/*******************************************************************************/
/**
 * @file WaveResourceDS.h.
 * 
 * @brief DirectSound Wave�t�H�[�}�b�g���\�[�X�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DIRECTSOUND_WAVERESOURCEDS_H_
#define _NGL_DIRECTSOUND_WAVERESOURCEDS_H_

#include	"IDirectSoundResource.h"
#include	"DirectSound.h"


namespace Ngl{


namespace DirectSound{


/**
 * @class WaveResourceDS.
 * @brief DirectSound Wave�t�H�[�}�b�g���\�[�X�N���X�D
 */
class WaveResourceDS : public IDirectSoundResource
{

public:

	/*=========================================================================*/
	/**
	 * @brief �쐬����
	 * 
	 * @param[in] fileName �t�@�C����.
	 * @param[in] ds �_�C���N�g�T�E���h�I�u�W�F�N�g.
	 * @param[in] enable3D 3D�T�E���h��L���ɂ��邩.
	 * @return �_�C���N�g�T�E���h�o�b�t�@.
	 */
	virtual IDirectSoundBuffer* create( const char* fileName, IDirectSound8* ds, bool enable3D=false );

private:

	/*=========================================================================*/
	/**
	 * @brief Wave�t�H�[�}�b�g��ǂݍ���
	 * 
	 * @param[in] fileName �t�@�C����.
	 * @return �Ȃ�.
	 * @throw Ngl::DirectSound::WaveDSException Wave�t�@�C����O.
	 */
	void readWaveFormat( const char* fileName );


	/*=========================================================================*/
	/**
	 * @brief Wave�f�[�^��ǂݍ���
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 * @throw Ngl::DirectSound::WaveDSException Wave�t�@�C����O.
	 */
	void readWaveData();


	/*=========================================================================*/
	/**
	 * @brief DirectSound�o�b�t�@���쐬
	 * 
	 * @param[in] ds �_�C���N�g�T�E���h�I�u�W�F�N�g.
	 * @param[in] enable3D 3D�T�E���h��L���ɂ��邩.
	 * @return �쐬�����o�b�t�@.
	 */
	IDirectSoundBuffer* createSoundBuffer( IDirectSound8* ds, bool enable3D );


	/*=========================================================================*/
	/**
	 * @brief Wave�g�`�f�[�^����������
	 * 
	 * @param[out] buffer �쐬�����o�b�t�@.
	 * @param[in] fileName wave�t�@�C����.
	 * @return �Ȃ�.
	 * @throw Ngl::DirectSound::WaveDSException Wave�t�@�C����O.
	 */
	void writeWaveData( IDirectSoundBuffer* buffer, const char* fileName );

private:

	/** Windows�}���`���f�B�AAPI�̃n���h�� */
	HMMIO				hMmio_;	

	/** �ŏ㕔�`�����N�iRIFF�`�����N�j*/
	MMCKINFO			riffckInfo_;

	/** �`�����N��� */
	MMCKINFO			ckInfo_;

	/** pcm�t�H�[�}�b�g */
	PCMWAVEFORMAT		pcmWaveFormat_;

	/** wave�t�H�[�}�b�g */
	LPWAVEFORMATEX		waveFormat_;
};

}	// namespace DirectSound

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/