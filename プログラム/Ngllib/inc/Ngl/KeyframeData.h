/*******************************************************************************/
/**
 * @file KeyframeData.h.
 * 
 * @brief キーフレームデータ構造体定義.
 *
 * @date 2008/07/01.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_KEYFRAMEDATA_H_
#define _NGL_KEYFRAMEDATA_H_

#include	"Ngl/Vector3.h"
#include	"Ngl/Quaternion.h"

namespace Ngl{


/**
 * @struct KeyframeData．
 * @brief キーフレームデータ構造体.
 */
struct KeyframeData
{
	/** 拡大縮小キー */
	Ngl::Vector3	scale;

	/** 回転キー */
	Ngl::Quaternion	rotate;

	/** 平行移動キー */
	Ngl::Vector3	position;
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/