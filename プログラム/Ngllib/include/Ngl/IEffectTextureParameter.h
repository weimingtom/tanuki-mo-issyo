/*******************************************************************************/
/**
 * @file IEffectTextureParameter.h.
 * 
 * @brief �G�t�F�N�g�e�N�X�`���p�����[�^�C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/12.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IEFFECTTEXTUREPARAMETER_H_
#define _NGL_IEFFECTTEXTUREPARAMETER_H_

#include	"Ngl/ITexture.h"

namespace Ngl{


/**
 * @interface IEffectTextureParameter�D
 * @brief �G�t�F�N�g�e�N�X�`���p�����[�^�C���^�[�t�F�[�X.
 */
class IEffectTextureParameter
{

protected:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IEffectTextureParameter() {}

public:

	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`���p�����[�^��ݒ�
	 * 
	 * @param[in] texture �ݒ肷��e�N�X�`���C���^�[�t�F�[�X�̃|�C���^.
	 * @return �Ȃ�.
	 */
	virtual void setTexture( ITexture* texture ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/