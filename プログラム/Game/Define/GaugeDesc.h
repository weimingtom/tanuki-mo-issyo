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
	/** 表示座標 */
	Vector2 position;

	/** テクスチャID1 */
	int texture1;
	/** テクスチャID2 */
	int texture2;

	/** テクスチャ切り取りサイズ1 */
	Rect textureRec1;
	/** テクスチャ切り取りサイズ2 */
	Rect textureRec2;
};


#endif