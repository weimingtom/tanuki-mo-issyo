/*******************************************************************************/
/**
 * @file EffectParameter.cpp.<br>
 * 
 * @brief �G�t�F�N�g�p�����[�^�N���X�\�[�X�t�@�C��.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"EffectParameter.h"
#include	"IGraphicDevice.h"
#include	<cassert>


/**
 * @brief �R���X�g���N�^<br>
 * 
 * @param[in] �Ȃ�.
 */
EffectParameter::EffectParameter():
	mID( 0 ),
	mGraphicDevice( 0 ),
	mEffect( 0 )
{}



/**
 * @brief �R���X�g���N�^<br>
 * 
 * @param[in] id �G�t�F�N�gID.
 * @param[in] ef �G�t�F�N�g.
 * @param[in] g �O���t�B�b�N�f�o�C�X.
 */
void EffectParameter::Initialize( unsigned int id, Ngl::IEffectExtension* ef, IGraphicDevice* g )
{
	assert( ef != 0 && g != 0 && id != 0 );

	mID = id;
	mEffect = ef;
	mGraphicDevice = g;
}



/**
 * @brief ���������_�p�����[�^��ݒ肷��<br>
 * 
 * @param[in] name �p�����[�^��.
 * @param[in] f �p�����[�^.
 * @return �Ȃ�.
 */
void EffectParameter::SetParameter( const char* name, float f )
{
	mEffect->getParameterByName( name )->asScalar()->setFloat( f );
}



/**
 * @brief ���������_�p�����[�^�̔z���ݒ肷��<br>
 * 
 * @param[in] name �p�����[�^��.
 * @param[in] count �v�f��.
 * @param[in] f �p�����[�^�z��̃|�C���^.
 * @return �Ȃ�.
 */
void EffectParameter::SetParameter( const char* name, int count, float* fv )
{
	mEffect->getParameterByName( name )->asScalar()->setFloatArray( fv, count );
}
	


/**
 * @brief 3�����x�N�g���^�̃p�����[�^�̔z���ݒ肷��<br>
 * 
 * @param[in] name �p�����[�^��.
 * @param[in] v �p�����[�^.
 * @return �Ȃ�.
 */
void EffectParameter::SetParameter( const char* name, const Vector3& v )
{
	mEffect->getParameterByName( name )->asVector()->setVector3( v );
}	
	
	

/**
 * @brief �J���[�^�̃p�����[�^�̔z���ݒ肷��<br>
 * 
 * @param[in] name �p�����[�^��.
 * @param[in] c �p�����[�^.
 * @return �Ȃ�.
 */
void EffectParameter::SetParameter( const char* name, const Color4& c )
{
	mEffect->getParameterByName( name )->asScalar()->setColor( c );
}

	

/**
 * @brief �s��^�̃p�����[�^�̔z���ݒ肷��<br>
 * 
 * @param[in] name �p�����[�^��.
 * @param[in] m �p�����[�^.
 * @return �Ȃ�.
 */
void EffectParameter::SetParameter( const char* name, const Matrix4& m )
{
	mEffect->getParameterByName( name )->asMatrix()->setMatrix( m );
}



/**
 * @brief �e�N�X�`���̃p�����[�^��ݒ肷��<br>
 * 
 * @param[in] name �p�����[�^��.
 * @param[in] id �e�N�X�`��ID.
 * @return �Ȃ�.
 */
void EffectParameter::SetParameter( const char* name, TextureID id )
{
	mGraphicDevice->SetTextureToEffect( mID, id, name );
}



/**
 * @brief ���W�ϊ��s���ݒ肷��<br>
 * 
 * @param[in] model ���f�����O�ϊ��s��.
 * @return �Ȃ�.
 */
void EffectParameter::SetModelViewProjMatrix( const Matrix4& model )
{
	// ���f���r���[�ϊ��s����쐬����
	Matrix4 modelViewProj;
	modelViewProj = model * mGraphicDevice->GetTransformMatrix( MAT_VIEW );
	
	// ���f���r���[�v���W�F�N�V�����ϊ��s����쐬����
	Matrix4 matTransformProj;
	matTransformProj = modelViewProj * mGraphicDevice->GetTransformMatrix( MAT_PROJECTION );
	mEffect->getParameterByName( "g_ModelViewProjectionMatrix" )->asMatrix()->setMatrix( matTransformProj );
}



/**
 * @brief ���W�ϊ��s���ݒ肷��<br>
 * 
 * @param[in] model ���f�����O�ϊ��s��
 * @return �Ȃ�.
 */
void EffectParameter::SetTransform( const Matrix4& model )
{
	// ���f���r���[�ϊ��s����쐬����
	Matrix4 modelViewProj;
	modelViewProj = model * mGraphicDevice->GetTransformMatrix( MAT_VIEW );
	
	// ���f���r���[�v���W�F�N�V�����ϊ��s����쐬����
	Matrix4 matTransformProj;
	matTransformProj = modelViewProj * mGraphicDevice->GetTransformMatrix( MAT_PROJECTION );
	mEffect->getParameterByName( "g_ModelViewMatrix" )->asMatrix()->setMatrix( modelViewProj );
	mEffect->getParameterByName( "g_ModelViewProjectionMatrix" )->asMatrix()->setMatrix( matTransformProj );

	// �@���x�N�g���ϊ��s����V�F�[�_�[�n��
	Matrix4 matNormal = modelViewProj;
	matNormal.setPosition( Vector3( 0.0f, 0.0f, 0.0f ) );
	mEffect->getParameterByName( "g_NormalMatrix" )->asMatrix()->setMatrix( matNormal );
}



/**
 * @brief ����ϊ��s��̃��C�g�ʒu��ݒ�<br>
 * 
 * @param[in] lightpos ���C�g�ʒu.
 * @return �Ȃ�.
 */
void EffectParameter::SetLightPositionEye( const Vector3& lightpos )
{
	// ���_���W�n�̃��C�g�ʒu���V�F�[�_�[�ɓn��
	Vector3 lightPositionEye;
	lightPositionEye = lightpos * mGraphicDevice->GetTransformMatrix( MAT_VIEW );
	mEffect->getParameterByName( "g_LightPositionEye" )->asVector()->setVector3( lightPositionEye );
}



/**
 * @brief �����J���[��ݒ�<br>
 * 
 * @param[in] color ���C�g�F.
 * @return �Ȃ�.
 */
void EffectParameter::SetAmbientLightColor( const Color4& color )
{
	mEffect->getParameterByName( "g_AmbientLightColor" )->asScalar()->setColor( color );
}



/**
 * @brief �g�U���ˌ��J���[��ݒ�<br>
 * 
 * @param[in] color ���C�g�F.
 * @return �Ȃ�.
 */
void EffectParameter::SetDiffuseLightColor( const Color4& color )
{
	mEffect->getParameterByName( "g_DiffuseLightColor" )->asScalar()->setColor( color );
}



/**
 * @brief ���ʔ��ˌ��J���[��ݒ�<br>
 * 
 * @param[in] color ���C�g�F.
 * @return �Ȃ�.
 */
void EffectParameter::SetSpecularLightColor( const Color4& color )
{
	mEffect->getParameterByName( "g_SpecularLightColor" )->asScalar()->setColor( color );
}



/*===== EOF ==================================================================*/