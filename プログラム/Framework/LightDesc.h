/*******************************************************************************/
/**
 * @file LightDesc.h.<br>
 * 
 * @brief ライト設定記述子構造体定義.<br>
 *
 * @date 2008/10/26.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _LIGHT_DESC_H_
#define _LIGHT_DESC_H_

#include	"Define/Define.h"


/**
 * @brief ライト記述子構造体．
 */
struct LightDesc
{
	/** 環境光の色 */
	Color4				ambientColor;

	/** 拡散反射光の色 */
	Color4				diffuseColor;

	/** 鏡面反射光の色 */
	Color4				specularColor;

	/** ライト位置 */
	Vector3				position;
};


/** デフォルトのライト記述子 */
static const LightDesc LIGHTDESC_DEFAULT = { 
	Color4( 0.3f, 0.3f, 0.3f, 1.0f ), 
	Color4( 1.0f, 1.0f, 1.0f, 1.0f ), 
	Color4( 0.0f, 0.0f, 0.0f, 1.0f ),
	Vector3( 0.0f, 0.0f, 0.0f )
	};


#endif

/*===== EOF ==================================================================*/