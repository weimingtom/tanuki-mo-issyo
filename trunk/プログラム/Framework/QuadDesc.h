/*******************************************************************************/
/*
 * @file QuadDesc.h.<br>
 * 
 * @brief 四角形ポリゴン記述子構造体定義.<br>
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
 * @brief 四角形ポリゴン記述子構造体
 */
struct QuadDesc
{
	/** ポリゴンの矩形( ワールド座標 ) */
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

	/** 座標変換行列 */
	Matrix4		matrix;
	
	/** 頂点カラー */
	Color4		color;

	/** ブレンド関数 */
	BlendFunc	blendFunc;

	/**
	 * @brief コンストラクタ
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