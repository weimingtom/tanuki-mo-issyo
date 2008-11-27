/*******************************************************************************/
/**
 * @file EffectPass.h.
 * 
 * @brief �G�t�F�N�g�p�X�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_EFFECTPASS_H_
#define _NGL_EFFECTPASS_H_

#include	"IEffectPass.h"
#include	"IEffect.h"
#include	<string>


namespace Ngl{


/**
 * @class EffectPass�D
 * @brief �G�t�F�N�g�p�X�N���X.
 */
class EffectPass : public IEffectPass
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] effect �G�t�F�N�g�N���X�̃|�C���^.
	 * @param[in] techniqueName �e�N�j�b�N��.
	 * @param[in] passNo �p�X�ԍ�.
	 */
	EffectPass( IEffect* effect, const std::string& techniqueName, unsigned int passNo );


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~EffectPass();


	/*=========================================================================*/
	/**
	 * @brief �p�X���J�n����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void begin();


	/*=========================================================================*/
	/**
	 * @brief �p�X���I������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void end();


	/*=========================================================================*/
	/**
	 * @brief ���̓V�O�l�`���L�q�q���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���̓V�O�l�`���L�q�q.
	 */
	virtual const InputSignatureDesc inputSignature();

private:

	/** �p�X�ԍ� */
	unsigned int		passNo_;

	/** �e�N�j�b�N�� */
	std::string			techniqueName_;

	/** �G�t�F�N�g�N���X�̃|�C���^ */
	IEffect*			effect_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/