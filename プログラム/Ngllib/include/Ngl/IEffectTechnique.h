/*******************************************************************************/
/**
 * @file IEffectTechnique.h.
 * 
 * @brief �G�t�F�N�g�e�N�j�b�N�C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IEFFECTTECHNIQUE_H_
#define _NGL_IEFFECTTECHNIQUE_H_

#include	"IEffectPass.h"
#include	<string>

namespace Ngl{


/**
 * @interface IEffectTechnique�D
 * @brief �G�t�F�N�g�e�N�j�b�N�C���^�[�t�F�[�X.
 */
class IEffectTechnique
{

protected:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IEffectTechnique() {}

public:

	/*=========================================================================*/
	/**
	 * @brief �p�X�����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �p�X��.
	 */
	virtual unsigned int numPass() = 0;


	/*=========================================================================*/
	/**
	 * @brief �C���f�b�N�X����p�X���擾����
	 * 
	 * @param[in] index �p�X�C���f�b�N�X�ԍ�.
	 * @return �p�X�N���X�̃|�C���^.
	 */
	virtual IEffectPass* getPassByIndex( unsigned int index ) = 0;


	/*=========================================================================*/
	/**
	 * @brief �e�N�j�b�N�����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e�N�j�b�N��.
	 */
	virtual const std::string& name() const = 0;


	/*=========================================================================*/
	/**
	 * @brief �e�N�j�b�N��ݒ�
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void setTechnique() = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/