/*******************************************************************************/
/**
 * @file SoundParameterDesc.h.<br>
 * 
 * @brief サウンド再生パラメータ記述子構造体定義.<br>
 *
 * @date 2007/07/05.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_SOUNDPARAMETERDESC_H_
#define _NGL_SOUNDPARAMETERDESC_H_

#include	<Ngl/Vector3.h>

namespace Ngl{


/**
 * @struct SoundParameterDesc．
 * @brief サウンド再生パラメータ記述子構造体.
 */
struct SoundParameterDesc
{

public:

	/** ボリューム */
	int				volume;

	/** パン（音の左右音量）*/
	int				pan;

	/** 現在の再生位置 */
	int				currentPosition;

	/** 曲の再生終了位置 */
	int				endPosition;

	/** 再生位置3D座標 */
	Vector3			soundPosition;

	/** 聞き取り位置3D座標 */
	Vector3			listenerPosition;
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/