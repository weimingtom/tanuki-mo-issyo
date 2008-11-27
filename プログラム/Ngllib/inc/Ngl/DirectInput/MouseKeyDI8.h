/*******************************************************************************/
/**
 * @file MouseKeyDI8.h.
 * 
 * @brief DirectInput マウスキー定数列挙型定義.
 *
 * @date 2008/07/17.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DIRECTINPUT_MAUSEKEYDI8_H_
#define _NGL_DIRECTINPUT_MAUSEKEYDI8_H_


namespace Ngl{


namespace DirectInput{


/**
 * @enum MouseKeyDI8．
 * @brief マウスキー定数列挙型.
 */
enum MouseKeyDI8
{
	MOUSEKEYDI8_NONE		= 0,	/**< 0 何も押されていない	*/
	MOUSEKEYDI8_BUTTON_1	= 1,	/**< 1 左ボタン				*/
	MOUSEKEYDI8_BUTTON_2	= 2,	/**< 2 右ボタン				*/
	MOUSEKEYDI8_BUTTON_3	= 3,	/**< 3 ホイール				*/
	MOUSEKEYDI8_BUTTON_4	= 4,	/**< 4 拡張ボタン1			*/

	MOUSEKEYDI8_COUNT				/**< マウスキー数			*/
};

} // namespace DirectInput

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/