/*******************************************************************************/
/**
 * @file Material.h.
 * 
 * @brief マテリアルデータ構造体定義.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MATERIAL_H_
#define _NGL_MATERIAL_H_

#include	"Ngl/Color4.h"

namespace Ngl{


/**
 * @struct Material．
 * @brief マテリアルデータ構造体.
 */
struct Material
{

	/** 環境光カラー */
	Color4		ambient;

	/** 拡散反射光カラー */
	Color4		diffuse;

	/** 鏡面反射光カラー */
	Color4		specular;

	/** 放射光カラー */
	Color4		emissive;

	/* 鏡面反射指数 */
	float		power;


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	Material():
		power( 0.0f )
	{}

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/