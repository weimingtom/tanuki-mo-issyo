/*******************************************************************************/
/**
 * @file EffectExtension.h.
 * 
 * @brief �g���G�t�F�N�g�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_EFFECTEXTENSION_H_
#define _NGL_EFFECTEXTENSION_H_

#include	"Ngl/EffectTechnique.h"
#include	"Ngl/EffectParameter.h"
#include	"Ngl/IEffectExtension.h"
#include	"Ngl/IEffect.h"
#include	"Ngl/IRenderer.h"
#include	<string>
#include	<vector>

namespace Ngl{


/**
 * @class EffectExtension�D
 * @brief �G�t�F�N�g�g���N���X.
 */
class EffectExtension : public IEffectExtension
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] fileName �t�@�C����.
	 * @param[in] renderer �����_���[�N���X�̃|�C���^.
	 */
	EffectExtension( const char* fileName, IRenderer* renderer );


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] effect �G�t�F�N�g�N���X�̃|�C���^.
	 * @param[in] isDelete �ݒ肵���G�t�F�N�g�N���X���폜���邩
	 */
	EffectExtension( IEffect* effect, bool isDelete );
	
	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~EffectExtension();


	/*=========================================================================*/
	/**
	 * @brief �C���f�b�N�X����e�N�j�b�N���擾����
	 * 
	 * @param[in] index �C���f�b�N�X.
	 * @return �G�t�F�N�g�e�N�j�b�N�C���^�[�t�F�[�X�̃|�C���^.
	 */
	virtual IEffectTechnique* getTechniqueByIndex( unsigned int index );


	/*=========================================================================*/
	/**
	 * @brief �e�N�j�b�N������e�N�j�b�N���擾����
	 * 
	 * @param[in] name �e�N�j�b�N��.
	 * @return �G�t�F�N�g�e�N�j�b�N�C���^�[�t�F�[�X�̃|�C���^.
	 */
	virtual IEffectTechnique* getTechniqueByName( const char* name );


	/*=========================================================================*/
	/**
	 * @brief �p�����[�^������p�����[�^���擾����
	 * 
	 * @param[in] name �p�����[�^��.
	 * @return �G�t�F�N�g�p�����[�^�C���^�[�t�F�[�X�̃|�C���^.
	 */
	virtual IEffectParameter* getParameterByName( const char* name );


	/*=========================================================================*/
	/**
	 * @brief �G�t�F�N�g�C���^�[�t�F�[�X���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual IEffect* getEffect();

private:

	/*=========================================================================*/
	/**
	 * @brief �쐬����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void create();

private:

	/** �e�N�j�b�N�R���e�i�^ */
	typedef std::vector< EffectTechnique* >	TechniqueContainer;

	/** �p�����[�^�R���e�i�^ */
	typedef std::vector< EffectParameter* >	ParameterContainer;

private:

	/** �G�t�F�N�g */
	IEffect*				effect_;

	/** �e�N�j�b�N�R���e�i */
	TechniqueContainer		techniqueContainer_;

	/** �p�����[�^�R���e�i */
	ParameterContainer		parameterContainer_;

	/** �C���X�^���X���폜���邩 */
	bool					isDelete_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/