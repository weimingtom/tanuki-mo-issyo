/*******************************************************************************/
/**
 * @file EffectOutputDesc.h.
 * 
 * @brief エフェクト出力記述子構造体定義.
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
 * @brief エフェクト出力記述子構造体
 */
struct EffectOutputDesc
{

	/** マテリアルデータをエフェクトに出力するか */
	bool			isOutMaterial;

	/** テクスチャデータをエフェクトに出力するか */
	bool			isOutTexture;

	/** 頂点カラーデータをエフェクトに出力するか */
	bool			isOutVertexColor;

	/** テクスチャー出力名 */
	std::string		textureName;

	/** マテリアル環境光カラー出力名 */
	std::string		matAmbientName;

	/** マテリアル拡散反射光カラー出力名 */
	std::string		matDiffuseName;

	/** マテリアル鏡面反射光カラー出力名 */
	std::string		matSpecularName;

	/** マテリアル放射光カラー出力名 */
	std::string		matEmissiveName;

	/** 放射光カラー出力名 */
	std::string		matShininessName;


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
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