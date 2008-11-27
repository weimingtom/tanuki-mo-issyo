/*******************************************************************************/
/**
 * @file SpriteDesc.h.<br>
 * 
 * @brief 2D�X�v���C�g�L�q�q�\���̒�`.<br>
 *
 * @date 2008/08/06.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _SPRITEDESC_H_
#define _SPRITEDESC_H_

#include	"Define/Define.h"
#include	<string>

/**
 * @brief 2D�X�v���C�g�L�q�q�\����
 */
struct SpriteDesc
{
	/** �|���S���̋�`( �X�N���[�����W ) */
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

	/** �|���S���̐F */
	Color4		color;

	/**
	 * @brief �R���X�g���N�^
	 */
	SpriteDesc() :
		rect( 0.0f, 0.0f, 0.0f, 0.0f ),
		srcRect( 0.0f, 0.0f, 0.0f, 0.0f ),
		effectID( EFFECTID_COM_SPRITE ),
		textureID( TEXTUREID_NONE ),
		textureName( "g_BaseMap" ),
		techniqueName( "Sprite" ),
		color( 1.0f, 1.0f, 1.0f, 1.0f )
	{}

};

#endif

/*===== EOF ==================================================================*/