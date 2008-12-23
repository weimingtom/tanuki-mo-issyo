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

/*===== インクルード ==========================================================*/
#include	"Define/Define.h"

/*--------------
   構造体定義
----------------*/
struct GaugeDesc
{
	/** 最大横幅 */
	float max;
	/** ゲージの位置 */
	float point;
	/** サイズ */
	Vector2 size;

	Vector2 position;

	int texture1;
	int texture2;

	Rect textureRec1;
	Rect textureRec2;
};


#endif