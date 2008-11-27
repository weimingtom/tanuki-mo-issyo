/*******************************************************************************/
/**
 * @file ISkeleton.h.
 * 
 * @brief �X�P���g�����C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/01.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ISKELTON_H_
#define _NGL_ISKELTON_H_

#include	"Ngl/IBone.h"
#include	"Ngl/Matrix4.h"

namespace Ngl{


/**
 * @interface ISkeleton.
 * @brief �X�P���g�����C���^�[�t�F�[�X�D
 */
class ISkeleton
{
public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~ISkeleton(){}


	/*=========================================================================*/
	/**
	 * @brief �p���ϊ��s������߂�
	 * 
	 * @param[out] outMatrices ���W�ϊ��s��̔z��.
	 * @param[in] parentMatrix �e�̕ϊ��s��ւ̃|�C���^.
	 * @param[in] animMatrices �A�j���[�V�����p�ϊ��s��z��.
	 * @return �Ȃ�.
	 */
	virtual void calculateOrientation( Matrix4* outMatrices, const Matrix4* parentMatrix, const Matrix4* animMatrices ) = 0;


	/*=========================================================================*/
	/**
	 * @brief ���W�ϊ��s��̌v�Z���s��
	 * 
	 * @param[out] outMatrices ���W�ϊ��s��̔z��
	 * @param[in] orientMatrices �p���ϊ��s��.
	 * @return �Ȃ�.
	 */
	virtual void calculateTransform( Matrix4* outMatrices, Matrix4* orientMatrices ) = 0;


	/*=========================================================================*/
	/**
	 * @brief �{�[���̐����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �{�[����.
	 */
	virtual unsigned int getNumBones() const = 0;

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/