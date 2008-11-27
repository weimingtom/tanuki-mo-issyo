/*******************************************************************************/
/*
 * @file QuadDesc.h.<br>
 * 
 * @brief �l�p�`�|���S���L�q�q�\���̒�`.<br>
 *
 * @date 2008/08/06.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _QUADDESC_H_
#define _QUADDESC_H_

#include	"Define/Define.h"
#include	<string>


/**
 * @brief �l�p�`�|���S���L�q�q�\����
 */
struct QuadDesc
{
	/** �|���S���̋�`( ���[���h���W ) */
	Rect		rect;

	/** �e�N�X�`���̋�`( �X�N���[�����W ) */
	Rect		srcRect;

	/** �g�p����G�t�F�N�gID */
	EffectID	effectID;

	/** �e�N�X�`��ID */
	TextureID	textureID;

	/** �V�F�[�_�[�ɓn���e�N�X�`���� */
	std::string	textureName;

	/** �G�t�F�N�g�e�N�j�b�N�� */
	std::string techniqueName;

	/** ���W�ϊ��s�� */
	Matrix4		matrix;
	
	/** ���_�J���[ */
	Color4		color;

	/** �u�����h�֐� */
	BlendFunc	blendFunc;

	/**
	 * @brief �R���X�g���N�^
	 */
	QuadDesc() :
		rect( -0.5f, 0.5f, 0.5f, -0.5f ),
		srcRect( 0.0f, 0.0f, 0.0f, 0.0f ),
		effectID( EFFECTID_COM_QUAD ),
		textureID( TEXTUREID_NONE ),
		textureName( "g_BaseMap" ),
		techniqueName( "Quad" ),
		color( 1.0f, 1.0f, 1.0f, 1.0f ),
		blendFunc( BLEND_ALPHA )
	{
		matrix.setIdentitiy();
	}

};

#endif

/*===== EOF ==================================================================*/