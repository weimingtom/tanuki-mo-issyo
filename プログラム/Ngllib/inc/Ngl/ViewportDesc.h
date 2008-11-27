/*******************************************************************************/
/**
 * @file ViewportDesc.h.
 * 
 * @brief ビューポート記述子構造体定義.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_VIEWPORT_DESC_H_
#define _NGL_VIEWPORT_DESC_H_

namespace Ngl{


/**
 * @struct ViewportDesc.
 * @brief ビューポート記述子構造体.
 */
struct ViewportDesc
{
	/** x座標 */
	int x;

	/** y座標 */
	int y;

	/** 幅 */
	int width;

	/** 高さ */
	int height;
};

} // namesapce Ngl

#endif

/*===== EOF ==================================================================*/