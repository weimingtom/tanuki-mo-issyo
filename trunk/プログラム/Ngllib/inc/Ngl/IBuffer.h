/*******************************************************************************/
/**
 * @file IBuffer.h.
 * 
 * @brief �o�b�t�@�C���^�[�t�F�[�X��`.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IBUFFER_H_
#define	_NGL_IBUFFER_H_

#include	"BufferDesc.h"

namespace Ngl{


/**
 * @interface IBuffer�D
 * @brief �o�b�t�@�C���^�[�t�F�[�X.
 */
class IBuffer
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IBuffer(){}

	
	/*=========================================================================*/
	/**
	 * @brief �L�q�q���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �o�b�t�@�L�q�q.
	 */
	virtual const BufferDesc& desc() const = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �o�b�t�@�f�[�^�̐ݒ�
	 * 
	 * @param[in] data �ݒ肷��f�[�^.
	 * @return �Ȃ�.
	 */
	virtual void setData( const void* data ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �o�b�t�@�f�[�^�̎擾
	 * 
	 * @param[out] data �o�b�t�@�f�[�^���i�[����f�[�^.
	 * @return �Ȃ�.
	 */
	virtual void getData( void* data ) const = 0;

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/