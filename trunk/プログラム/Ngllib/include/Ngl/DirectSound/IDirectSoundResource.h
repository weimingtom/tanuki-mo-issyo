/*******************************************************************************/
/**
 * @file IDirectSoundResource.h.
 * 
 * @brief DirectSound �I�[�f�B�I���\�[�X�C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DIRECTSOUND_IDIRECTSOUNDRESOURCE_H_
#define _NGL_DIRECTSOUND_IDIRECTSOUNDRESOURCE_H_

#include	<dsound.h>

namespace Ngl{


namespace DirectSound{


/**
 * @interface IDirectSoundResource.
 * @brief DirectSound �I�[�f�B�I���\�[�X�C���^�[�t�F�[�X�D
 */
class IDirectSoundResource
{

public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IDirectSoundResource() {}

	
	/*=========================================================================*/
	/**
	 * @brief �쐬����
	 * 
	 * @param[in] fileName �t�@�C����.
	 * @param[in] ds �_�C���N�g�T�E���h�I�u�W�F�N�g.
	 * @param[in] enable3D 3D�T�E���h��L���ɂ��邩.
	 * @return �_�C���N�g�T�E���h�o�b�t�@.
	 */
	virtual IDirectSoundBuffer* create( const char* fileName, IDirectSound8* ds, bool enable3D=false ) = 0;

};

}	// namespace DirectSound

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/