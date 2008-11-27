/*******************************************************************************/
/**
 * @file DSSocketCreator.h.
 * 
 * @brief DirectSound �\�P�b�g�쐬�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DIRECTSOUND_DSSOCKETCREATOR_H_
#define _NGL_DIRECTSOUND_DSSOCKETCREATOR_H_

#include	"DirectSound.h"
#include	"IDirectSoundResource.h"
#include	"Ngl/ISoundResource.h"

namespace Ngl{


namespace DirectSound{


/**
 * @class DSSocketCreator�D
 * @brief DirectSound �\�P�b�g�쐬�N���X.
 */
class DSSocketCreator
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] resource �_�C���N�g�T�E���h���\�[�X.
	 */
	DSSocketCreator( IDirectSoundResource* resource );


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~DSSocketCreator();


	/*=========================================================================*/
	/**
	 * @brief 
	 * 
	 * @param[in] fileName �t�@�C����.
	 * @param[in] ds DirectSound�f�o�C�X�̃|�C���^.
	 * @return �쐬�����T�E���h���\�[�X.
	 */
	ISoundResource* create( const char* fileName, IDirectSound8* ds );

private:

	/** �_�C���N�g�T�E���h���\�[�X */
	IDirectSoundResource*	resource_;

};

} // namespace DirectSound

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/