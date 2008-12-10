/*******************************************************************************/
/**
 * @file SpriteDesc.h.
 * 
 * @brief 2Dスプライト記述子構造体定義.
 *
 * @date 2008/08/06.
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
	int			effectID;

	/** テクスチャID */
	int			textureID;

	/** 回転角度( z軸周り ) */
	float		angle;

	/** 中心位置座標( スクリーン座標, スプライト内の座標で指定 ) */
	Vector2		center;

	/** シェーダーに渡すテクスチャ名 */
	std::string	textureName;

	/** エフェクトテクニック名 */
	std::string techniqueName;

	/** ポリゴンの色 */
	Color4		color;

	/**
	 * コンストラクタ
	 */
	SpriteDesc() :
		rect( 0.0f, 0.0f, 0.0f, 0.0f ),
		srcRect( 0.0f, 0.0f, 0.0f, 0.0f ),
		effectID( EFFECTID_COM_SPRITE ),
		textureID( TEXTUREID_NONE ),
		angle( 0.0f ),
		textureName( "g_BaseMap" ),
		techniqueName( "Sprite" ),
		color( 1.0f, 1.0f, 1.0f, 1.0f )
	{}

};

#endif

/*===== EOF ==================================================================*/