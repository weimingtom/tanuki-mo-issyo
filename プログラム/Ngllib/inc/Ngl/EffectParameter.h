/*******************************************************************************/
/**
 * @file EffectParameter.h.
 * 
 * @brief �G�t�F�N�g�p�����[�^�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_EFFECTPARAMETER_H_
#define _NGL_EFFECTPARAMETER_H_

#include	"Ngl/IEffectParameter.h"
#include	"Ngl/IEffect.h"

namespace Ngl{


/**
 * @class EffectParameter�D
 * @brief �G�t�F�N�g�p�����[�^�N���X.
 */
class EffectParameter :	public IEffectParameter,
						public IEffectScalarParameter,
						public IEffectVectorParameter,
						public IEffectMatrixParameter,
						public IEffectTextureParameter
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] effect �G�t�F�N�g�N���X�̃|�C���^.
	 * @param[in] parameterName �p�����[�^��.
	 */
	EffectParameter( IEffect* effect, const std::string parameterName );


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~EffectParameter();


	/*=========================================================================*/
	/**
	 * @brief �p�����[�^�����擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �p�����[�^��.
	 */
	virtual const std::string& name() const;
	
	
	/*=========================================================================*/
	/**
	 * @brief �X�J���[�p�����[�^�C���^�[�t�F�[�X���擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �X�J���[�p�����[�^�C���^�[�t�F�[�X�̃|�C���^.
	 */
	virtual IEffectScalarParameter* asScalar();


	/*=========================================================================*/
	/**
	 * @brief �x�N�g���p�����[�^�C���^�[�t�F�[�X���擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �x�N�g���p�����[�^�C���^�[�t�F�[�X�̃|�C���^.
	 */
	virtual IEffectVectorParameter* asVector();


	/*=========================================================================*/
	/**
	 * @brief �s��p�����[�^�C���^�[�t�F�[�X���擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �s��p�����[�^�C���^�[�t�F�[�X�̃|�C���^.
	 */
	virtual IEffectMatrixParameter* asMatrix();


	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`���p�����[�^�C���^�[�t�F�[�X���擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e�N�X�`���p�����[�^�C���^�[�t�F�[�X�̃|�C���^.
	 */
	virtual IEffectTextureParameter* asTexture();

private:

	/*=========================================================================*/
	/**
	 * @brief int�^�̃p�����[�^��ݒ�
	 * 
	 * @param[in] v �ݒ肷��p�����[�^.
	 * @return �Ȃ�.
	 */
	virtual void setInt( int v );


	/*=========================================================================*/
	/**
	 * @brief int�^�z��̃p�����[�^��ݒ�
	 * 
	 * @param[in] v �ݒ肷��z��p�����[�^�̐擪�|�C���^.
	 * @param[in] count �v�f��.
	 * @return �Ȃ�.
	 */
	virtual void setIntArray( const int* v, unsigned int count );


	/*=========================================================================*/
	/**
	 * @brief float�^�̃p�����[�^��ݒ�
	 * 
	 * @param[in] v �ݒ肷��p�����[�^.
	 * @return �Ȃ�.
	 */
	virtual void setFloat( float v );


	/*=========================================================================*/
	/**
	 * @brief float�^�z��̃p�����[�^��ݒ�
	 * 
	 * @param[in] v �ݒ肷��z��p�����[�^�̐擪�|�C���^.
	 * @param[in] count �v�f��.
	 * @return �Ȃ�.
	 */
	virtual void setFloatArray( const float* v, unsigned int count );


	/*=========================================================================*/
	/**
	 * @brief RGBA�J���[�\���̂̃p�����[�^��ݒ�
	 * 
	 * @param[in] color �ݒ肷��RGBA�J���[�\���̃p�����[�^.
	 * @return �Ȃ�.
	 */
	virtual void setColor( const Color4& color );


	/*=========================================================================*/
	/**
	 * @brief RGBA�J���[�\���̔z��̃p�����[�^��ݒ�
	 * 
	 * @param[in] color �ݒ肷��RGBA�J���[�z��p�����[�^�̐擪�|�C���^.
	 * @param[in] count �v�f��.
	 * @return �Ȃ�.
	 */
	virtual void setColorArray( const Color4* color, unsigned int count );

	
	/*=========================================================================*/
	/**
	 * @brief 2�����x�N�g����ݒ肷��
	 * 
	 * @param[in] v2 �ݒ肷��2�����x�N�g���\����.
	 * @return �Ȃ�.
	 */
	virtual void setVector2( const Vector2& v2 );


	/*=========================================================================*/
	/**
	 * @brief 2�����x�N�g���̔z���ݒ肷��
	 * 
	 * @param[in] v2 �ݒ肷��2�����x�N�g���\���̔z��̐擪�|�C���^.
	 * @param[in] count �z��̗v�f��
	 * @return �Ȃ�.
	 */
	virtual void setVector2Array( const Vector2& v2, unsigned int count );


	/*=========================================================================*/
	/**
	 * @brief 3�����x�N�g����ݒ肷��
	 * 
	 * @param[in] v3 �ݒ肷��3�����x�N�g���\����.
	 * @return �Ȃ�.
	 */
	virtual void setVector3( const Vector3& v3 );


	/*=========================================================================*/
	/**
	 * @brief 3�����x�N�g���̔z���ݒ肷��
	 * 
	 * @param[in] v3 �ݒ肷��3�����x�N�g���\���̔z��̐擪�|�C���^.
	 * @param[in] count �z��̗v�f��
	 * @return �Ȃ�.
	 */
	virtual void setVector3Array( const Vector3& v3, unsigned int count );


	/*=========================================================================*/
	/**
	 * @brief 4�����x�N�g����ݒ肷��
	 * 
	 * @param[in] v4 �ݒ肷��4�����x�N�g���\����.
	 * @return �Ȃ�.
	 */
	virtual void setVector4( const Vector4& v4 );


	/*=========================================================================*/
	/**
	 * @brief 4�����x�N�g���̔z���ݒ肷��
	 * 
	 * @param[in] v4 �ݒ肷��4�����x�N�g���\���̔z��̐擪�|�C���^.
	 * @param[in] count �z��̗v�f��
	 * @return �Ȃ�.
	 */
	virtual void setVector4Array( const Vector4& v4, unsigned int count );


	/*=========================================================================*/
	/**
	 * @brief 4x4�s���ݒ肷��
	 * 
	 * @param[in] matrix �ݒ肷��4x4�s��\����.
	 * @return �Ȃ�.
	 */
	virtual void setMatrix( const Matrix4& matrix );


	/*=========================================================================*/
	/**
	 * @brief 4x4�s��̔z���ݒ肷��
	 * 
	 * @param[in] matrix �ݒ肷��4x4�s��\���̔z��̐擪�|�C���^.
	 * @param[in] count �v�f��
	 * @return �Ȃ�.
	 */
	virtual void setMatrixArray( const Matrix4* matrix, unsigned int count );


	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`���p�����[�^��ݒ�
	 * 
	 * @param[in] texture �ݒ肷��e�N�X�`���C���^�[�t�F�[�X�̃|�C���^.
	 * @return �Ȃ�.
	 */
	virtual void setTexture( ITexture* texture );

private:

	/** �G�t�F�N�g�N���X�̃|�C���^ */
	IEffect*	effect_;

	/** �p�����[�^�� */
	std::string	parameterName_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/