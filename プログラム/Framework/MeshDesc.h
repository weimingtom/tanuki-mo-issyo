/*******************************************************************************/
/**
 * @file MeshDesc.h.<br>
 * 
 * @brief メッシュ記述子構造体定義.<br>
 *
 * @date 2008/10/26.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _MESH_DESC_H_
#define _MESH_DESC_H_

#include	"Define/Define.h"
#include	<string>


/**
 * @brief メッシュ記述子構造体．
 */
struct MeshDesc
{
	/** メッシュＩＤ */
	MeshID			meshID;

	/** 使用するエフェクト番号 */
	EffectID		effectID;

	/** エフェクトテクニック名 */
	std::string		techniqueName;

	/** マテリアルカラーを出力するか */
	bool			isSetMaterial;

	/** テクスチャを出力するか */
	bool			isSetTexture;

	/** ライト番号 */
	unsigned int	lightNo;

	/** 座標変換行列 */
	Matrix4			matrix;

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ<br>
	 * 
	 * @param[in] なし.
	 */
	MeshDesc() :
		meshID( MESHID_NONE ),
		effectID( EFFECTID_COM_PIXELLIGHTING ),
		lightNo( 0 ),
		techniqueName( "PixelLighting" ),
		isSetMaterial( true ),
		isSetTexture( true )
	{}
};

#endif

/*===== EOF ==================================================================*/