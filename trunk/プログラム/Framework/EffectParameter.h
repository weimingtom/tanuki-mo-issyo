/*******************************************************************************/
/**
 * @file EffectParameter.h.<br>
 * 
 * @brief �G�t�F�N�g�p�����[�^�N���X�w�b�_�t�@�C��.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _EFFECTPARAMETER_H_
#define _EFFECTPARAMETER_H_

#include	"IEffectParameter.h"
#include	<Ngl/IRenderer.h>
#include	<Ngl/IEffectExtension.h>
#include	<string>

// �O���t�B�b�N�f�o�C�X�̑O���Q��
class IGraphicDevice;

/**
 * @brief �G�t�F�N�g�p�����[�^�N���X.
 */
class EffectParameter : public IEffectParameter
{
public:

	/**
	 * @brief �R���X�g���N�^<br>
	 * 
	 * @param[in] �Ȃ�.
	 */
	EffectParameter();
	
	/**
	 * @brief �R���X�g���N�^<br>
	 * 
	 * @param[in] id �G�t�F�N�gID.
	 * @param[in] ef �G�t�F�N�g.
	 * @param[in] g �O���t�B�b�N�f�o�C�X.
	 */
	void Initialize( unsigned int id, Ngl::IEffectExtension* ef, IGraphicDevice* g );
	
	/**
	 * @brief ���������_�p�����[�^��ݒ肷��<br>
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] f �p�����[�^.
	 * @return �Ȃ�.
	 */
	void SetParameter( const char* name, float f );

	/**
	 * @brief ���������_�p�����[�^�̔z���ݒ肷��<br>
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] count �v�f��.
	 * @param[in] f �p�����[�^�z��̃|�C���^.
	 * @return �Ȃ�.
	 */
	void SetParameter( const char* name, int count, float* fv );
	
	/**
	 * @brief 3�����x�N�g���^�̃p�����[�^�̔z���ݒ肷��<br>
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] v �p�����[�^.
	 * @return �Ȃ�.
	 */
	void SetParameter( const char* name, const Vector3& v );
	
	/**
	 * @brief �J���[�^�̃p�����[�^�̔z���ݒ肷��<br>
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] c �p�����[�^.
	 * @return �Ȃ�.
	 */
	void SetParameter( const char* name, const Color4& c );
	
	/**
	 * @brief �s��^�̃p�����[�^�̔z���ݒ肷��<br>
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] m �p�����[�^.
	 * @return �Ȃ�.
	 */
	void SetParameter( const char* name, const Matrix4& m );
	
	/**
	 * @brief �e�N�X�`���̃p�����[�^��ݒ肷��<br>
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] id �e�N�X�`��ID.
	 * @return �Ȃ�.
	 */
	void SetParameter( const char* name, TextureID id );
	
	/**
	 * @brief ���W�ϊ��s���ݒ肷��<br>
	 * 
	 * @param[in] model ���f�����O�ϊ��s��.
	 * @return �Ȃ�.
	 */
	void SetModelViewProjMatrix( const Matrix4& model );
	
	/**
	 * @brief ���W�ϊ��s���ݒ肷��<br>
	 * 
	 * @param[in] model ���f�����O�ϊ��s��
	 * @return �Ȃ�.
	 */
	void SetTransform( const Matrix4& model );
	
	/**
	 * @brief ����ϊ��s��̃��C�g�ʒu��ݒ�<br>
	 * 
	 * @param[in] lightpos ���C�g�ʒu.
	 * @return �Ȃ�.
	 */
	void SetLightPositionEye( const Vector3& lightpos );
	
	/**
	 * @brief �����J���[��ݒ�<br>
	 * 
	 * @param[in] color ���C�g�F.
	 * @return �Ȃ�.
	 */
	void SetAmbientLightColor( const Color4& color );

	/**
	 * @brief �g�U���ˌ��J���[��ݒ�<br>
	 * 
	 * @param[in] color ���C�g�F.
	 * @return �Ȃ�.
	 */
	void SetDiffuseLightColor( const Color4& color );

	/**
	 * @brief ���ʔ��ˌ��J���[��ݒ�<br>
	 * 
	 * @param[in] color ���C�g�F.
	 * @return �Ȃ�.
	 */
	void SetSpecularLightColor( const Color4& color );

private:

	/** �G�t�F�N�gID */
	unsigned int			mID;

	/** �O���t�B�b�N�f�o�C�X�̎Q�� */
	IGraphicDevice*			mGraphicDevice;

	/** �V�F�[�_�[�p�����[�^�̃|�C���^ */
	Ngl::IEffectExtension*	mEffect;

};

#endif

/*===== EOF ==================================================================*/