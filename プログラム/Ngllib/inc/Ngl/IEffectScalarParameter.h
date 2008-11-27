/*******************************************************************************/
/**
 * @file IEffectScalarParameter.h.
 * 
 * @brief �G�t�F�N�g�X�J���[�p�����[�^�C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IEFFECTSCALARPARAMETER_H_
#define _NGL_IEFFECTSCALARPARAMETER_H_

#include	"Ngl/Color4.h"

namespace Ngl{


/**
 * @interface IEffectScalarParameter�D
 * @brief �G�t�F�N�g�X�J���[�p�����[�^�C���^�[�t�F�[�X.
 */
class IEffectScalarParameter
{
protected:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IEffectScalarParameter() {}

public:

	/*=========================================================================*/
	/**
	 * @brief int�^�̃p�����[�^��ݒ�
	 * 
	 * @param[in] v �ݒ肷��p�����[�^.
	 * @return �Ȃ�.
	 */
	virtual void setInt( int v ) = 0;


	/*=========================================================================*/
	/**
	 * @brief int�^�z��̃p�����[�^��ݒ�
	 * 
	 * @param[in] v �ݒ肷��z��p�����[�^�̐擪�|�C���^.
	 * @param[in] count �v�f��.
	 * @return �Ȃ�.
	 */
	virtual void setIntArray( const int* v, unsigned int count ) = 0;


	/*=========================================================================*/
	/**
	 * @brief float�^�̃p�����[�^��ݒ�
	 * 
	 * @param[in] v �ݒ肷��p�����[�^.
	 * @return �Ȃ�.
	 */
	virtual void setFloat( float v ) = 0;


	/*=========================================================================*/
	/**
	 * @brief float�^�z��̃p�����[�^��ݒ�
	 * 
	 * @param[in] v �ݒ肷��z��p�����[�^�̐擪�|�C���^.
	 * @param[in] count �v�f��.
	 * @return �Ȃ�.
	 */
	virtual void setFloatArray( const float* v, unsigned int count ) = 0;


	/*=========================================================================*/
	/**
	 * @brief RGBA�J���[�\���̂̃p�����[�^��ݒ�
	 * 
	 * @param[in] color �ݒ肷��RGBA�J���[�\���̃p�����[�^.
	 * @return �Ȃ�.
	 */
	virtual void setColor( const Color4& color ) = 0;


	/*=========================================================================*/
	/**
	 * @brief RGBA�J���[�\���̔z��̃p�����[�^��ݒ�
	 * 
	 * @param[in] color �ݒ肷��RGBA�J���[�z��p�����[�^�̐擪�|�C���^.
	 * @param[in] count �v�f��.
	 * @return �Ȃ�.
	 */
	virtual void setColorArray( const Color4* color, unsigned int count ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/