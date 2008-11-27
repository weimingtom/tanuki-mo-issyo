/*******************************************************************************/
/**
 * @file IEffectParameter.h.
 * 
 * @brief �G�t�F�N�g�p�����[�^�C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IEFFECTPARAMETER_H_
#define _NGL_IEFFECTPARAMETER_H_

#include	"Ngl/IEffectScalarParameter.h"
#include	"Ngl/IEffectVectorParameter.h"
#include	"Ngl/IEffectMatrixParameter.h"
#include	"Ngl/IEffectTextureParameter.h"
#include	<string>

namespace Ngl{


/**
 * @interface IEffectParameter�D
 * @brief �G�t�F�N�g�p�����[�^�C���^�[�t�F�[�X.
 */
class IEffectParameter
{
protected:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IEffectParameter() {}

public:

	/*=========================================================================*/
	/**
	 * @brief �p�����[�^�����擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �p�����[�^��.
	 */
	virtual const std::string& name() const = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �X�J���[�p�����[�^�C���^�[�t�F�[�X���擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �X�J���[�p�����[�^�C���^�[�t�F�[�X�̃|�C���^.
	 */
	virtual IEffectScalarParameter* asScalar() = 0;


	/*=========================================================================*/
	/**
	 * @brief �x�N�g���p�����[�^�C���^�[�t�F�[�X���擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �x�N�g���p�����[�^�C���^�[�t�F�[�X�̃|�C���^.
	 */
	virtual IEffectVectorParameter* asVector() = 0;


	/*=========================================================================*/
	/**
	 * @brief �s��p�����[�^�C���^�[�t�F�[�X���擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �s��p�����[�^�C���^�[�t�F�[�X�̃|�C���^.
	 */
	virtual IEffectMatrixParameter* asMatrix() = 0;


	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`���p�����[�^�C���^�[�t�F�[�X���擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e�N�X�`���p�����[�^�C���^�[�t�F�[�X�̃|�C���^.
	 */
	virtual IEffectTextureParameter* asTexture() = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/