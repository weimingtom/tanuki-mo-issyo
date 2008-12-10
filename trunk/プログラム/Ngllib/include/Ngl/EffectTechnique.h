/*******************************************************************************/
/**
 * @file EffectTechnique.h.
 * 
 * @brief �G�t�F�N�g�e�N�j�b�N�N���X�w�b�_�t�@�C��.
 *
 * @date 2007/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_EFFECTTECHNIQUE_H_
#define _NGL_EFFECTTECHNIQUE_H_

#include	"Ngl/EffectPass.h"
#include	"Ngl/IEffectTechnique.h"
#include	"Ngl/IEffect.h"
#include	<vector>

namespace Ngl{


/**
 * @class EffectTechnique�D
 * @brief �G�t�F�N�g�e�N�j�b�N�N���X.
 */
	class EffectTechnique : public IEffectTechnique
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] effect �G�t�F�N�g�N���X�̃|�C���^.
	 * @param[in] techniqueNo �e�N�j�b�N�ԍ�.
	 */
	EffectTechnique( IEffect* effect, unsigned int techniqueNo );


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~EffectTechnique();


	/*=========================================================================*/
	/**
	 * @brief �p�X�����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �p�X��.
	 */
	virtual unsigned int numPass();


	/*=========================================================================*/
	/**
	 * @brief �C���f�b�N�X����p�X���擾����
	 * 
	 * @param[in] index �p�X�C���f�b�N�X�ԍ�.
	 * @return �p�X�N���X�̃|�C���^.
	 */
	virtual IEffectPass* getPassByIndex( unsigned int index );


	/*=========================================================================*/
	/**
	 * @brief �e�N�j�b�N�����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e�N�j�b�N��.
	 */
	virtual const std::string& name() const;


	/*=========================================================================*/
	/**
	 * @brief �e�N�j�b�N��ݒ�
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void setTechnique();

private:

	/** �G�t�F�N�g�p�X�R���e�i�^ */
	typedef std::vector< EffectPass* >	EffectPassContainer;

private:

	/** �G�t�F�N�g�N���X�̃|�C���^ */
	IEffect*			effect_;

	/** �e�N�j�b�N�ԍ� */
	unsigned int		techniqueNo_;

	/** �e�N�j�b�N�� */
	std::string			techniqueName_;

	/** �G�t�F�N�g�p�X�R���e�i */
	EffectPassContainer	passContainer_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/