/*******************************************************************************/
/**
 * @file EffectOutputDesc.h.
 * 
 * @brief �G�t�F�N�g�o�͋L�q�q�\���̒�`.
 *
 * @date 2008/07/04.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_EFFECTOUTPUTDESC_H_
#define _NGL_EFFECTOUTPUTDESC_H_

#include	<string>

namespace Ngl{


/**
 * @struct EffectOutputDesc.
 * @brief �G�t�F�N�g�o�͋L�q�q�\����
 */
struct EffectOutputDesc
{

	/** �}�e���A���f�[�^���G�t�F�N�g�ɏo�͂��邩 */
	bool			isOutMaterial;

	/** �e�N�X�`���f�[�^���G�t�F�N�g�ɏo�͂��邩 */
	bool			isOutTexture;

	/** ���_�J���[�f�[�^���G�t�F�N�g�ɏo�͂��邩 */
	bool			isOutVertexColor;

	/** �e�N�X�`���[�o�͖� */
	std::string		textureName;

	/** �}�e���A�������J���[�o�͖� */
	std::string		matAmbientName;

	/** �}�e���A���g�U���ˌ��J���[�o�͖� */
	std::string		matDiffuseName;

	/** �}�e���A�����ʔ��ˌ��J���[�o�͖� */
	std::string		matSpecularName;

	/** �}�e���A�����ˌ��J���[�o�͖� */
	std::string		matEmissiveName;

	/** ���ˌ��J���[�o�͖� */
	std::string		matShininessName;


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	EffectOutputDesc():
		isOutMaterial( true ),
		isOutTexture( true ),
		isOutVertexColor( true ),
		textureName( "g_BaseMap" ),
		matAmbientName( "g_MaterialAmbient" ),
		matDiffuseName( "g_MaterialDiffuse" ),
		matSpecularName( "g_MaterialSpecular" ),
		matEmissiveName( "g_MaterialEmissive" ),
		matShininessName( "g_MaterialShininess" )
	{}
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/