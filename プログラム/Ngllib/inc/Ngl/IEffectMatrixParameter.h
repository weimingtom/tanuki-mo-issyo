/*******************************************************************************/
/**
 * @file IEffectMatrixParameter.h.
 * 
 * @brief �G�t�F�N�g�s��p�����[�^�[�C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/12.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IEFFECTMATRIXPARAMETER_H_
#define _NGL_IEFFECTMATRIXPARAMETER_H_

#include	"Ngl/Matrix4.h"

namespace Ngl{


/**
 * @interface IEffectMatrixParameter�D
 * @brief �G�t�F�N�g�s��p�����[�^�[�C���^�[�t�F�[�X.
 */
class IEffectMatrixParameter
{

protected:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IEffectMatrixParameter() {}

public:

	/*=========================================================================*/
	/**
	 * @brief 4x4�s���ݒ肷��
	 * 
	 * @param[in] matrix �ݒ肷��4x4�s��\����.
	 * @return �Ȃ�.
	 */
	virtual void setMatrix( const Matrix4& matrix ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 4x4�s��̔z���ݒ肷��
	 * 
	 * @param[in] matrix �ݒ肷��4x4�s��\���̔z��̐擪�|�C���^.
	 * @param[in] count �v�f��
	 * @return �Ȃ�.
	 */
	virtual void setMatrixArray( const Matrix4* matrix, unsigned int count ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/