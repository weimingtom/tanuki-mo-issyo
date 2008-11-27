/*******************************************************************************/
/**
 * @file MouseKeyDI8.h.
 * 
 * @brief DirectInput �}�E�X�L�[�萔�񋓌^��`.
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
 * @enum MouseKeyDI8�D
 * @brief �}�E�X�L�[�萔�񋓌^.
 */
enum MouseKeyDI8
{
	MOUSEKEYDI8_NONE		= 0,	/**< 0 ����������Ă��Ȃ�	*/
	MOUSEKEYDI8_BUTTON_1	= 1,	/**< 1 ���{�^��				*/
	MOUSEKEYDI8_BUTTON_2	= 2,	/**< 2 �E�{�^��				*/
	MOUSEKEYDI8_BUTTON_3	= 3,	/**< 3 �z�C�[��				*/
	MOUSEKEYDI8_BUTTON_4	= 4,	/**< 4 �g���{�^��1			*/

	MOUSEKEYDI8_COUNT				/**< �}�E�X�L�[��			*/
};

} // namespace DirectInput

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/