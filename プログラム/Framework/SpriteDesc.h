/*******************************************************************************/
/**
 * @file SpriteDesc.h.<br>
 * 
 * @brief 2Dスプライト記述子構造体定義.<br>
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
 * @brief 2Dスプライト記述子構造体
 */
struct SpriteDesc
{
	/** ポリゴンの矩形( スクリーン座標 ) */
	Rect		rect;

	/** テクスチャの矩形( スクリーン座標 ) */
	Rect		srcRect;

	/** 使用するエフェクトID */
	EffectID	effectID;

	/** テクスチャID */
	TextureID	textureID;

	/** シェーダーに渡すテクスチャ名 */
	std::string	textureName;

	/** エフェクトテクニック名 */
	std::string techniqueName;

	/** ポリゴンの色 */
	Color4		color;

	/**
	 * @brief コンストラクタ
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