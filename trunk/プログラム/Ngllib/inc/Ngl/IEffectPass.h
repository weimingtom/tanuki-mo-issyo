/*******************************************************************************/
/**
 * @file IEffectPass.h.
 * 
 * @brief �G�t�F�N�g�p�X�C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IEFFECTPASS_H_
#define _NGL_IEFFECTPASS_H_

#include	"Ngl/InputSignatureDesc.h"

namespace Ngl{


/**
 * @interface IEffectPass�D
 * @brief �G�t�F�N�g�p�X�C���^�[�t�F�[�X.
 */
class IEffectPass
{
protected:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IEffectPass() {}

public:

	/*=========================================================================*/
	/**
	 * @brief �p�X���J�n����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void begin() = 0;


	/*=========================================================================*/
	/**
	 * @brief �p�X���I������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void end() = 0;


	/*=========================================================================*/
	/**
	 * @brief ���̓V�O�l�`���L�q�q���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���̓V�O�l�`���L�q�q.
	 */
	virtual const InputSignatureDesc inputSignature() = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/