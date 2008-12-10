/*******************************************************************************/
/**
 * @file IEffectVectorParameter.h.
 * 
 * @brief �G�t�F�N�g�x�N�g���p�����[�^�C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/11.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IEFFECTVECTORVARIABLE_H_
#define _NGL_IEFFECTVECTORVARIABLE_H_

#include	"Ngl/Vector2.h"
#include	"Ngl/Vector3.h"
#include	"Ngl/Vector4.h"

namespace Ngl{


/**
 * @interface IEffectVectorParameter�D
 * @brief �G�t�F�N�g�x�N�g���p�����[�^�C���^�[�t�F�[�X.
 */
class IEffectVectorParameter
{

protected:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IEffectVectorParameter() {}

public:

	/*=========================================================================*/
	/**
	 * @brief 2�����x�N�g����ݒ肷��
	 * 
	 * @param[in] v2 �ݒ肷��2�����x�N�g���\����.
	 * @return �Ȃ�.
	 */
	virtual void setVector2( const Vector2& v2 ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 2�����x�N�g���̔z���ݒ肷��
	 * 
	 * @param[in] v2 �ݒ肷��2�����x�N�g���\���̔z��̐擪�|�C���^.
	 * @param[in] count �z��̗v�f��
	 * @return �Ȃ�.
	 */
	virtual void setVector2Array( const Vector2& v2, unsigned int count ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 3�����x�N�g����ݒ肷��
	 * 
	 * @param[in] v3 �ݒ肷��3�����x�N�g���\����.
	 * @return �Ȃ�.
	 */
	virtual void setVector3( const Vector3& v3 ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 3�����x�N�g���̔z���ݒ肷��
	 * 
	 * @param[in] v3 �ݒ肷��3�����x�N�g���\���̔z��̐擪�|�C���^.
	 * @param[in] count �z��̗v�f��
	 * @return �Ȃ�.
	 */
	virtual void setVector3Array( const Vector3& v3, unsigned int count ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 4�����x�N�g����ݒ肷��
	 * 
	 * @param[in] v4 �ݒ肷��4�����x�N�g���\����.
	 * @return �Ȃ�.
	 */
	virtual void setVector4( const Vector4& v4 ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 4�����x�N�g���̔z���ݒ肷��
	 * 
	 * @param[in] v4 �ݒ肷��4�����x�N�g���\���̔z��̐擪�|�C���^.
	 * @param[in] count �z��̗v�f��
	 * @return �Ȃ�.
	 */
	virtual void setVector4Array( const Vector4& v4, unsigned int count ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/