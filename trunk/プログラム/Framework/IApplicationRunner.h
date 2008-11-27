/*******************************************************************************/
/**
 * @file IApplicationRunner.h.<br>
 * 
 * @brief �A�v���P�[�V�������s�C���^�[�t�F�[�X��`.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _IAPPLICATIONRUNNER_H_
#define _IAPPLICATIONRUNNER_H_

#include	"Define/Define.h"

/**
 * @brief �A�v���P�[�V�������s�C���^�[�t�F�[�X
 */
class IApplicationRunner
{
public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^<br>
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IApplicationRunner() {}


	/*=========================================================================*/
	/**
	 * @brief �A�v���P�[�V�����̎��s<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �I���R�[�h.
	 */
	virtual int runApp() = 0;

};

#endif

/*===== EOF ==================================================================*/