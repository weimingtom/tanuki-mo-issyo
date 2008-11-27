/*******************************************************************************/
/**
 * @file IEffectExtension.h.
 * 
 * @brief �g���G�t�F�N�g�C���^�[�t�F�[�X.
 *
 * @date 2008/07/11.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IEFFECTEXTENSION_H_
#define _NGL_IEFFECTEXTENSION_H_

#include	"Ngl/IEffectTechnique.h"
#include	"Ngl/IEffectParameter.h"
#include	"Ngl/IEffect.h"
#include	<string>

namespace Ngl{


/**
 * @interface IEffectExtension�D
 * @brief �G�t�F�N�g�g���C���^�[�t�F�[�X.
 */
class IEffectExtension
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IEffectExtension() {}


	/*=========================================================================*/
	/**
	 * @brief �C���f�b�N�X����e�N�j�b�N���擾����
	 * 
	 * @param[in] index �C���f�b�N�X.
	 * @return �G�t�F�N�g�e�N�j�b�N�C���^�[�t�F�[�X�̃|�C���^.
	 */
	virtual IEffectTechnique* getTechniqueByIndex( unsigned int index ) = 0;


	/*=========================================================================*/
	/**
	 * @brief �e�N�j�b�N������e�N�j�b�N���擾����
	 * 
	 * @param[in] name �e�N�j�b�N��.
	 * @return �G�t�F�N�g�e�N�j�b�N�C���^�[�t�F�[�X�̃|�C���^.
	 */
	virtual IEffectTechnique* getTechniqueByName( const char* name ) = 0;


	/*=========================================================================*/
	/**
	 * @brief �p�����[�^������p�����[�^���擾����
	 * 
	 * @param[in] name �p�����[�^��.
	 * @return �G�t�F�N�g�p�����[�^�C���^�[�t�F�[�X�̃|�C���^.
	 */
	virtual IEffectParameter* getParameterByName( const char* name ) = 0;


	/*=========================================================================*/
	/**
	 * @brief �G�t�F�N�g�C���^�[�t�F�[�X���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual IEffect* getEffect() = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/