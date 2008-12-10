/*******************************************************************************/
/**
 * @file SoundStateDesc.h.
 * 
 * @brief サウンド状態記述子構造体定義.
 *
 * @date 2007/07/31.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_SOUNDSTATEDESC_H_
#define _NGL_SOUNDSTATEDESC_H_

#include	<Ngl/Vector3.h>

namespace Ngl{


static const unsigned int SOUND_VOLUME_MIN	= 0;	/**< ボリュームの最小値				*/
static const unsigned int SOUND_VOLUME_MAX	= 100;	/**< ボリュームの最大値				*/

static const int SOUND_PAN_LEFTMAX	= -100;			/**< 相対ボリューム位置の左最大値	*/
static const int SOUND_PAN_MIDDLE	= 0;			/**< 相対ボリューム位置の中間位置	*/
static const int SOUND_PAN_RIGHTMAX	= 100;			/**< 相対ボリューム位置の右最大値	*/

/**
 * @enum SoundPlayType.
 * @brief サウンド再生タイプ列挙型.
 */
enum SoundPlayType
{
	SOUNDPLAYTYPE_NORMAL = 0,	/**< 通常再生		*/
	SOUNDPLAYTYPE_LOOP,			/**< ループ再生		*/
	SOUNDPLAYTYPE_WAIT			/**< 再生終了待ち	*/
};


/**
 * @struct SoundStateDesc．
 * @brief サウンド状態記述子構造体.
 */
struct SoundStateDesc
{

	/** 曲の再生タイプ */
	SoundPlayType	type;
	
	/** ボリューム */
	unsigned int	volume;

	/** パン（音の左右音量）*/
	long			pan;

	/** 現在の再生位置時間 */
	float			currentTime;

	/** 曲の再生終了位置時間 */
	float			endTime;

};


/** デフォルトのサウンド状態記述子 */
static const SoundStateDesc SOUNDSTATEDESC_DEFAULT = { SOUNDPLAYTYPE_NORMAL, SOUND_VOLUME_MAX, 0, 0, 0 };


} // namespace Ngl

#endif

/*===== EOF ==================================================================*/