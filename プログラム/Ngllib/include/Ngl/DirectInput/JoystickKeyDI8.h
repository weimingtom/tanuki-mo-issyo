/*******************************************************************************/
/**
 * @file JoystickKeyDI8.h.
 * 
 * @brief DirectInput �W���C�X�e�B�b�N�L�[�萔�񋓌^.
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
 * @enum JoystickKeyDI8�D
 * @brief DirectInput �W���C�X�e�B�b�N�L�[�萔�񋓌^.
 */
enum JoystickKeyDI8
{
	JOYSTICKKEYDI8_NONE			= 0,	/**< 0  ����������Ă��Ȃ�			*/
	JOYSTICKKEYDI8_LEFT			= 1,	/**< 1  �W���C�X�e�B�b�N����		*/
	JOYSTICKKEYDI8_RIGHT		= 2,	/**< 2  �W���C�X�e�B�b�N���E		*/
	JOYSTICKKEYDI8_UP			= 3,	/**< 3  �W���C�X�e�B�b�N����		*/
	JOYSTICKKEYDI8_DOWN			= 4,	/**< 4  �W���C�X�e�B�b�N����		*/
	JOYSTICKKEYDI8_LEFTDOWN		= 5,	/**< 5  �W���C�X�e�B�b�N���΂߉�	*/
	JOYSTICKKEYDI8_RIGHTDOWN	= 6,	/**< 6  �W���C�X�e�B�b�N�E�΂߉�	*/
	JOYSTICKKEYDI8_LEFTUP		= 7,	/**< 7  �W���C�X�e�B�b�N���΂ߏ�	*/
	JOYSTICKKEYDI8_RIGHTUP		= 8,	/**< 8  �W���C�X�e�B�b�N���΂߉�	*/
	JOYSTICKKEYDI8_BUTTON_1		= 9,	/**< 9  �W���C�X�e�B�b�N�{�^��1		*/
	JOYSTICKKEYDI8_BUTTON_2		= 10,	/**< 10 �W���C�X�e�B�b�N�{�^��2		*/
	JOYSTICKKEYDI8_BUTTON_3		= 11,	/**< 11 �W���C�X�e�B�b�N�{�^��3		*/
	JOYSTICKKEYDI8_BUTTON_4		= 12,	/**< 12 �W���C�X�e�B�b�N�{�^��4		*/
	JOYSTICKKEYDI8_BUTTON_5		= 13,	/**< 13 �W���C�X�e�B�b�N�{�^��5		*/
	JOYSTICKKEYDI8_BUTTON_6		= 14,	/**< 14 �W���C�X�e�B�b�N�{�^��6		*/
	JOYSTICKKEYDI8_BUTTON_7		= 15,	/**< 15 �W���C�X�e�B�b�N�{�^��7		*/
	JOYSTICKKEYDI8_BUTTON_8		= 16,	/**< 16 �W���C�X�e�B�b�N�{�^��8		*/
	JOYSTICKKEYDI8_BUTTON_9		= 17,	/**< 17 �W���C�X�e�B�b�N�{�^��9		*/
	JOYSTICKKEYDI8_BUTTON_10	= 18,	/**< 18 �W���C�X�e�B�b�N�{�^��10	*/

	JOYSTICKKEYDI8_COUNT				/**< �W���C�X�e�B�b�N�L�[��			*/
};

} // namespace DirectInput

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/