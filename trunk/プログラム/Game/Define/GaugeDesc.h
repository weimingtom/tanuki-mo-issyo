/*******************************************************************************/
/**
 * @file GaugeDesc.h.
 * 
 * @brief ゲージデスク型定義.
 *
 * @date 2008/12/23.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/
#ifndef _GAUGEDESC_H_
#define _GAUGEDESC_H_

#include	"Define.h"
#include	<Ngl/Vector2.h>
#include	<Ngl/Rect.h>

/*--------------
   構造体定義
----------------*/
typedef struct{
	/** 最大横幅 */
	float Max;
	/** ゲージの位置 */
	float Point;
	/** サイズ */
	Vector2 Size;

	Vector2 Position;

	int Texture1;
	int Texture2;

	Rect TextureRec1;
	Rect TextureRec2;
}GaugeDesc;


#endif