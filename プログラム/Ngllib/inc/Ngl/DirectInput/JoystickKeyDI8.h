/*******************************************************************************/
/**
 * @file JoystickKeyDI8.h.
 * 
 * @brief DirectInput ジョイスティックキー定数列挙型.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DIRECTINPUT_JOYSTICKKEYDI8_H_
#define _NGL_DIRECTINPUT_JOYSTICKKEYDI8_H_


namespace Ngl{


namespace DirectInput{


/**
 * @enum JoystickKeyDI8．
 * @brief DirectInput ジョイスティックキー定数列挙型.
 */
enum JoystickKeyDI8
{
	JOYSTICKKEYDI8_NONE			= 0,	/**< 0  何も押されていない			*/
	JOYSTICKKEYDI8_LEFT			= 1,	/**< 1  ジョイスティック軸左		*/
	JOYSTICKKEYDI8_RIGHT		= 2,	/**< 2  ジョイスティック軸右		*/
	JOYSTICKKEYDI8_UP			= 3,	/**< 3  ジョイスティック軸上		*/
	JOYSTICKKEYDI8_DOWN			= 4,	/**< 4  ジョイスティック軸下		*/
	JOYSTICKKEYDI8_LEFTDOWN		= 5,	/**< 5  ジョイスティック左斜め下	*/
	JOYSTICKKEYDI8_RIGHTDOWN	= 6,	/**< 6  ジョイスティック右斜め下	*/
	JOYSTICKKEYDI8_LEFTUP		= 7,	/**< 7  ジョイスティック左斜め上	*/
	JOYSTICKKEYDI8_RIGHTUP		= 8,	/**< 8  ジョイスティック左斜め下	*/
	JOYSTICKKEYDI8_BUTTON_1		= 9,	/**< 9  ジョイスティックボタン1		*/
	JOYSTICKKEYDI8_BUTTON_2		= 10,	/**< 10 ジョイスティックボタン2		*/
	JOYSTICKKEYDI8_BUTTON_3		= 11,	/**< 11 ジョイスティックボタン3		*/
	JOYSTICKKEYDI8_BUTTON_4		= 12,	/**< 12 ジョイスティックボタン4		*/
	JOYSTICKKEYDI8_BUTTON_5		= 13,	/**< 13 ジョイスティックボタン5		*/
	JOYSTICKKEYDI8_BUTTON_6		= 14,	/**< 14 ジョイスティックボタン6		*/
	JOYSTICKKEYDI8_BUTTON_7		= 15,	/**< 15 ジョイスティックボタン7		*/
	JOYSTICKKEYDI8_BUTTON_8		= 16,	/**< 16 ジョイスティックボタン8		*/
	JOYSTICKKEYDI8_BUTTON_9		= 17,	/**< 17 ジョイスティックボタン9		*/
	JOYSTICKKEYDI8_BUTTON_10	= 18,	/**< 18 ジョイスティックボタン10	*/

	JOYSTICKKEYDI8_COUNT				/**< ジョイスティックキー数			*/
};

} // namespace DirectInput

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/