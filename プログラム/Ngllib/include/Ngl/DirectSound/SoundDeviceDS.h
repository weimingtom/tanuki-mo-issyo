/*******************************************************************************/
/**
 * @file SoundDeviceDS.h.
 * 
 * @brief DirectSound �T�E���h�f�o�C�X�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DIRECTINPUT_SOUNDDEVIDEDS_H_
#define _NGL_DIRECTINPUT_SOUNDDEVIDEDS_H_

#include	"DirectSound.h"
#include	"DSSocketCreator.h"
#include	"IDirectSoundResource.h"
#include	"Ngl/SoundDeviceBase.h"
#include	<map>


namespace Ngl{


namespace DirectSound{


/**
 * @class SoundDeviceDS.
 * @brief DirectSound �T�E���h�f�o�C�X�N���X�D
 */
class SoundDeviceDS : public SoundDeviceBase
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	SoundDeviceDS();


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~SoundDeviceDS();

	
	/*=========================================================================*/
	/**
	 * @brief �f�o�C�X���쐬����
	 * 
	 * @param[in] hwnd �E�B���h�E�n���h��.
	 * @retval true �쐬����.
	 * @retval false �쐬���s.
	 */
	bool create( HWND hwnd );


	/*=========================================================================*/
	/**
	 * @brief �\�P�b�g�쐬�҂�o�^����
	 * 
	 * @param[in] name �o�^���i"."���܂܂Ȃ��Đ��t�@�C���̊g���q).
	 * @param[in] creator �쐬�҂̃|�C���^.
	 * @return �Ȃ�.
	 */
	void registCreator( std::string name, DSSocketCreator* creator );
	

	/*=========================================================================*/
	/**
	 * @brief �f�o�C�X���������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void release();

private:

	/*=========================================================================*/
	/**
	 * @brief ���\�[�X���쐬����
	 *
	 * @param[in] fileName �t�@�C����.
	 * @return �쐬�������\�[�X.
	 */
	virtual ISoundResource* create( const std::string& fileName );

private:

	/** ���\�[�X�H��^ */
	typedef std::map< std::string, DSSocketCreator* >	ResourceFactory;

private:

	/** �_�C���N�g�T�E���h�f�o�C�X */
	LPDIRECTSOUND8		device_;

	/** ���\�[�X�H�� */
	ResourceFactory		resourceFactory_;

};

}	// namespace DirectSound

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/