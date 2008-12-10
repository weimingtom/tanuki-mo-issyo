/*******************************************************************************/
/**
 * @file IFrameWork.h.
 * 
 * @brief �t���[�����[�N�C���^�[�t�F�[�X��`.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IFRAMEWORK_H_
#define _NGL_IFRAMEWORK_H_

#include	"FrameWorkDesc.h"

namespace Ngl{


/**
 * @interface IFrameWork�D
 * @brief �t���[�����[�N�C���^�[�t�F�[�X
 */
class IFrameWork
{

public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IFrameWork(){}


	/*=========================================================================*/
	/**
	 * @brief �A�v���P�[�V�����̎��s
	 * 
	 * @param[in] �Ȃ�.
	 * @return �I���R�[�h.
	 */
	virtual int run() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �A�v���P�[�V�����̏I��
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void exit() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �t���[�����[�N�L�q�q���擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �t���[�����[�N�L�q�q.
	 */
	virtual const FrameWorkDesc& desc() const = 0;


	/*=========================================================================*/
	/**
	 * @brief �E�B���h�E�n���h�����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �E�B���h�E�n���h��.
	 */
	virtual void* getHWND() = 0;

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/