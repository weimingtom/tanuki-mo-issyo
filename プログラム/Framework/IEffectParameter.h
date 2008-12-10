/*******************************************************************************/
/**
 * @file IEffectParameter.h.<br>
 * 
 * @brief �G�t�F�N�g�p�����[�^�C���^�[�t�F�[�X��`.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _IEFFECTPARAMETER_H_
#define _IEFFECTPARAMETER_H_

#include	"Define/Define.h"

/**
 * @brief �G�t�F�N�g�p�����[�^�C���^�[�t�F�[�X.
 */
class IEffectParameter
{
protected:

	/**
	 * @brief �f�X�g���N�^<br>
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IEffectParameter() {}

public:

	/**
	 * @brief ���������_�p�����[�^��ݒ肷��<br>
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] f �p�����[�^.
	 * @return �Ȃ�.
	 */
	virtual void SetParameter( const char* name, float f ) = 0;
	
	/**
	 * @brief ���������_�p�����[�^�̔z���ݒ肷��<br>
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] count �v�f��.
	 * @param[in] f �p�����[�^�z��̃|�C���^.
	 * @return �Ȃ�.
	 */
	virtual void SetParameter( const char* name, int count, float* fv ) = 0;
	
	/**
	 * @brief 3�����x�N�g���^�̃p�����[�^�̔z���ݒ肷��<br>
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] v �p�����[�^.
	 * @return �Ȃ�.
	 */
	virtual void SetParameter( const char* name, const Vector3& v ) = 0;
	
	/**
	 * @brief �J���[�^�̃p�����[�^�̔z���ݒ肷��<br>
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] c �p�����[�^.
	 * @return �Ȃ�.
	 */
	virtual void SetParameter( const char* name, const Color4& c ) = 0;
	
	/**
	 * @brief �s��^�̃p�����[�^�̔z���ݒ肷��<br>
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] m �p�����[�^.
	 * @return �Ȃ�.
	 */
	virtual void SetParameter( const char* name, const Matrix4& m ) = 0;
	
	/**
	 * @brief �e�N�X�`���̃p�����[�^��ݒ肷��<br>
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] id �e�N�X�`��ID.
	 * @return �Ȃ�.
	 */
	virtual void SetParameter( const char* name, TextureID id ) = 0;

	/**
	 * @brief ���W�ϊ��s���ݒ肷��<br>
	 * 
	 * @param[in] model ���f�����O�ϊ��s��.
	 * @return �Ȃ�.
	 */
	virtual void SetModelViewProjMatrix( const Matrix4& model ) = 0;
	
	/**
	 * @brief ���W�ϊ��s���ݒ肷��<br>
	 * 
	 * @param[in] model ���f�����O�ϊ��s��
	 * @return �Ȃ�.
	 */
	virtual void SetTransform( const Matrix4& model ) = 0;

	/**
	 * @brief ����ϊ��s��̃��C�g�ʒu��ݒ�<br>
	 * 
	 * @param[in] lightpos ���C�g�ʒu.
	 * @return �Ȃ�.
	 */
	virtual void SetLightPositionEye( const Vector3& lightpos ) = 0;
	
	/**
	 * @brief �����J���[��ݒ�<br>
	 * 
	 * @param[in] color ���C�g�F.
	 * @return �Ȃ�.
	 */
	virtual void SetAmbientLightColor( const Color4& color ) = 0;

	/**
	 * @brief �g�U���ˌ��J���[��ݒ�<br>
	 * 
	 * @param[in] color ���C�g�F.
	 * @return �Ȃ�.
	 */
	virtual void SetDiffuseLightColor( const Color4& color ) = 0;

	/**
	 * @brief ���ʔ��ˌ��J���[��ݒ�<br>
	 * 
	 * @param[in] color ���C�g�F.
	 * @return �Ȃ�.
	 */
	virtual void SetSpecularLightColor( const Color4& color ) = 0;

};

#endif

/*===== EOF ==================================================================*/