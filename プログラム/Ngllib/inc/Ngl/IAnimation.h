/*******************************************************************************/
/**
 * @file IAnimation.h.
 * 
 * @brief �A�j���[�V�����f�[�^�C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/01.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IANIMATION_H_
#define _NGL_IANIMATION_H_

#include	"Ngl/KeyframeData.h"

namespace Ngl{


/**
 * @interface IAnimation.
 * @brief �A�j���[�V�����f�[�^�C���^�[�t�F�[�X�D
 */
class IAnimation
{
public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IAnimation() {}
	
	
	/*=========================================================================*/
	/**
	 * @brief �w��̃L�[�t���[���f�[�^���擾����
	 * 
	 * @param[in] no �擾����f�[�^�ԍ�.
	 * @param[in] boneNo �擾����{�[���ԍ�.
	 * @param[in] globalTime �擾����L�[�̃^�C�}.
	 * @param[out] data �L�[�t���[���f�[�^.
	 * @return �L�[�t���[���f�[�^.
	 */
	virtual KeyframeData& getKeyFrame( unsigned int no, unsigned int boneNo, float globalTime, KeyframeData& data ) = 0;


	/*=========================================================================*/
	/**
	 * @brief �A�j���[�V�����̏I���^�C�}�𒲂ׂ�
	 * 
	 * @param[in] no �A�j���[�V�����i���o�[.
	 * @return �I���^�C�}.
	 */
	virtual unsigned int getEndTimer( unsigned int no ) = 0;


	/*=========================================================================*/
	/**
	 * @brief �w��̃A�j���[�V�����̃{�[�����𒲂ׂ�
	 * 
	 * @param[in] no �f�[�^�ԍ�.
	 * @return �{�[����.
	 */
	virtual unsigned int getNumBones( unsigned int no ) = 0;

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/