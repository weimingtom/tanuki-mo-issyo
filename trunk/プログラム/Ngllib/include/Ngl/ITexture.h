/*******************************************************************************/
/**
 * @file ITexture.h.
 * 
 * @brief �e�N�X�`���C���^�[�t�F�[�X��`.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ITEXTURE_H_
#define _NGL_ITEXTURE_H_

#include	"TextureDesc.h"

namespace Ngl{


/**
 * @interface ITexture�D
 * @brief �e�N�X�`���C���^�[�t�F�[�X.
 */
class ITexture
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~ITexture(){}

	
	/*=========================================================================*/
	/**
	 * @brief �L�q�q���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e�N�X�`���L�q�q.
	 */
	virtual const TextureDesc& desc() const = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`���f�[�^�̐ݒ�
	 * 
	 * @param[in] data �ݒ肷��f�[�^.
	 * @return �Ȃ�.
	 */
	virtual void setData( const void* data ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`���f�[�^�̎擾
	 * 
	 * @param[out] data �e�N�X�`���f�[�^���i�[����f�[�^.
	 * @return �Ȃ�.
	 */
	virtual void getData( void* data ) = 0;


	/*=========================================================================*/
	/**
	 * @brief �C���[�W�T�C�Y�̎擾
	 * 
	 * @param[out] �Ȃ�.
	 * @return �C���[�W�T�C�Y.
	 */
	virtual unsigned int size() const  = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/