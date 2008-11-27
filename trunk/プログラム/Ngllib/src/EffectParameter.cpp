/*******************************************************************************/
/**
 * @file EffectParameter.cpp.
 * 
 * @brief �G�t�F�N�g�p�����[�^�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/EffectParameter.h"
#include	<cassert>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] effect �G�t�F�N�g�N���X�̃|�C���^.
 * @param[in] parameterName �p�����[�^��.
 */
EffectParameter::EffectParameter( IEffect* effect, const std::string parameterName  ):
	effect_( effect ),
	parameterName_( parameterName )
{
	assert( effect_ != 0 );
}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
EffectParameter::~EffectParameter()
{
	effect_ = 0;
}



/*=========================================================================*/
/**
 * @brief �p�����[�^�����擾
 * 
 * @param[in] �Ȃ�.
 * @return �p�����[�^��.
 */
const std::string& EffectParameter::name() const
{
	return parameterName_;
}
	
	
/*=========================================================================*/
/**
 * @brief �X�J���[�p�����[�^�C���^�[�t�F�[�X���擾
 * 
 * @param[in] �Ȃ�.
 * @return �X�J���[�p�����[�^�C���^�[�t�F�[�X�̃|�C���^.
 */
IEffectScalarParameter* EffectParameter::asScalar()
{
	return this;
}



/*=========================================================================*/
/**
 * @brief �x�N�g���p�����[�^�C���^�[�t�F�[�X���擾
 * 
 * @param[in] �Ȃ�.
 * @return �x�N�g���p�����[�^�C���^�[�t�F�[�X�̃|�C���^.
 */
IEffectVectorParameter* EffectParameter::asVector()
{
	return this;
}

	
	
/*=========================================================================*/
/**
 * @brief �s��p�����[�^�C���^�[�t�F�[�X���擾
 * 
 * @param[in] �Ȃ�.
 * @return �s��p�����[�^�C���^�[�t�F�[�X�̃|�C���^.
 */
IEffectMatrixParameter* EffectParameter::asMatrix()
{
	return this;
}

	
	
/*=========================================================================*/
/**
 * @brief �e�N�X�`���p�����[�^�C���^�[�t�F�[�X���擾
 * 
 * @param[in] �Ȃ�.
 * @return �e�N�X�`���p�����[�^�C���^�[�t�F�[�X�̃|�C���^.
 */
IEffectTextureParameter* EffectParameter::asTexture()
{
	return this;
}


	
/*=========================================================================*/
/**
 * @brief int�^�̃p�����[�^��ݒ�
 * 
 * @param[in] v �ݒ肷��p�����[�^.
 * @return �Ȃ�.
 */
void EffectParameter::setInt( int v )
{
	effect_->setScalar( name().c_str(), v );
}



/*=========================================================================*/
/**
 * @brief int�^�z��̃p�����[�^��ݒ�
 * 
 * @param[in] v �ݒ肷��z��p�����[�^�̐擪�|�C���^.
 * @param[in] count �v�f��.
 * @return �Ȃ�.
 */
void EffectParameter::setIntArray( const int* v, unsigned int count )
{
	effect_->setScalarArray( name().c_str(), const_cast< int* >( v ), count );
}



/*=========================================================================*/
/**
 * @brief float�^�̃p�����[�^��ݒ�
 * 
 * @param[in] v �ݒ肷��p�����[�^.
 * @return �Ȃ�.
 */
void EffectParameter::setFloat( float v )
{
	effect_->setScalar( name().c_str(), v );
}



/*=========================================================================*/
/**
 * @brief float�^�z��̃p�����[�^��ݒ�
 * 
 * @param[in] v �ݒ肷��z��p�����[�^�̐擪�|�C���^.
 * @param[in] count �v�f��.
 * @return �Ȃ�.
 */
void EffectParameter::setFloatArray( const float* v, unsigned int count )
{
	effect_->setScalarArray( name().c_str(), const_cast< float* >( v ), count );
}
	
	
	
/*=========================================================================*/
/**
 * @brief RGBA�J���[�\���̂̃p�����[�^��ݒ�
 * 
 * @param[in] color �ݒ肷��RGBA�J���[�\���̃p�����[�^.
 * @return �Ȃ�.
 */
void EffectParameter::setColor( const Color4& color )
{
	effect_->setVector( name().c_str(), color.r, color.g, color.b, color.a );
}



/*=========================================================================*/
/**
 * @brief RGBA�J���[�\���̔z��̃p�����[�^��ݒ�
 * 
 * @param[in] color �ݒ肷��RGBA�J���[�z��p�����[�^�̐擪�|�C���^.
 * @param[in] count �v�f��.
 * @return �Ȃ�.
 */
void EffectParameter::setColorArray( const Color4* color, unsigned int count )
{
	effect_->setVectorArray( name().c_str(), (float*)color, count );
}

	
	
/*=========================================================================*/
/**
 * @brief 2�����x�N�g����ݒ肷��
 * 
 * @param[in] v2 �ݒ肷��2�����x�N�g���\����.
 * @return �Ȃ�.
 */
void EffectParameter::setVector2( const Vector2& v2 )
{
	effect_->setScalarArray( name().c_str(), (float*)v2, 2 );
}



/*=========================================================================*/
/**
 * @brief 2�����x�N�g���̔z���ݒ肷��
 * 
 * @param[in] v2 �ݒ肷��2�����x�N�g���\���̔z��̐擪�|�C���^.
 * @param[in] count �z��̗v�f��
 * @return �Ȃ�.
 */
void EffectParameter::setVector2Array( const Vector2& v2, unsigned int count )
{
	effect_->setVectorArray( name().c_str(), (float*)v2, count );
}



/*=========================================================================*/
/**
 * @brief 3�����x�N�g����ݒ肷��
 * 
 * @param[in] v3 �ݒ肷��3�����x�N�g���\����.
 * @return �Ȃ�.
 */
void EffectParameter::setVector3( const Vector3& v3 )
{
	effect_->setVector( name().c_str(), v3.x, v3.y, v3.z );
}



/*=========================================================================*/
/**
 * @brief 3�����x�N�g���̔z���ݒ肷��
 * 
 * @param[in] v3 �ݒ肷��3�����x�N�g���\���̔z��̐擪�|�C���^.
 * @param[in] count �z��̗v�f��
 * @return �Ȃ�.
 */
void EffectParameter::setVector3Array( const Vector3& v3, unsigned int count )
{
	effect_->setVectorArray( name().c_str(), (float*)v3, count );
}



/*=========================================================================*/
/**
 * @brief 4�����x�N�g����ݒ肷��
 * 
 * @param[in] v4 �ݒ肷��4�����x�N�g���\����.
 * @return �Ȃ�.
 */
void EffectParameter::setVector4( const Vector4& v4 )
{
	effect_->setVector( name().c_str(), v4.x, v4.y, v4.z, v4.w );
}



/*=========================================================================*/
/**
 * @brief 4�����x�N�g���̔z���ݒ肷��
 * 
 * @param[in] v4 �ݒ肷��4�����x�N�g���\���̔z��̐擪�|�C���^.
 * @param[in] count �z��̗v�f��
 * @return �Ȃ�.
 */
void EffectParameter::setVector4Array( const Vector4& v4, unsigned int count )
{
	effect_->setVectorArray( name().c_str(), (float*)v4, count );
}

	
	
/*=========================================================================*/
/**
 * @brief 4x4�s���ݒ肷��
 * 
 * @param[in] matrix �ݒ肷��4x4�s��\����.
 * @return �Ȃ�.
 */
void EffectParameter::setMatrix( const Matrix4& matrix )
{
	effect_->setMatrix( parameterName_.c_str(), (float*)matrix );
}



/*=========================================================================*/
/**
 * @brief 4x4�s��̔z���ݒ肷��
 * 
 * @param[in] matrix �ݒ肷��4x4�s��\���̔z��̐擪�|�C���^.
 * @param[in] count �v�f��
 * @return �Ȃ�.
 */
void EffectParameter::setMatrixArray( const Matrix4* matrix, unsigned int count )
{
	effect_->setMatrixArray( parameterName_.c_str(), (float*)matrix, count );
}

	
	
/*=========================================================================*/
/**
 * @brief �e�N�X�`���p�����[�^��ݒ�
 * 
 * @param[in] texture �ݒ肷��e�N�X�`���C���^�[�t�F�[�X�̃|�C���^.
 * @return �Ȃ�.
 */
void EffectParameter::setTexture( ITexture* texture )
{
	effect_->setTexture( parameterName_.c_str(), texture );
}

	
	
/*===== EOF ==================================================================*/