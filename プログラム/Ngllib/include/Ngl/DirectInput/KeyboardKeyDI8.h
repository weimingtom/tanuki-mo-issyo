/*******************************************************************************/
/**
 * @file KeyboardKeyDI8.h.
 * 
 * @brief DirectInput �L�[�{�[�h�L�[�萔�񋓌^��`.
 *
 * @date 2008/07/17.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DIRECTINPUT_KEYBOARDKEYDI8_H_
#define _NGL_DIRECTINPUT_KEYBOARDKEYDI8_H_

#include	<windows.h>

namespace Ngl{


namespace DirectInput{


/**
 * @enum KeyboardKeyDI8�D
 * @brief DirectInput �L�[�{�[�h�L�[�萔�񋓌^.
 */
enum KeyboardKeyDI8
{
	KEYBOARDKEYDI8_NONE			= 0,		/**< 0		����������Ă��Ȃ�			*/
	KEYBOARDKEYDI8_ESCAPE		= 1,		/**< 1		�G�X�P�[�v�L�[				*/
	KEYBOARDKEYDI8_1			= 2,		/**< 2		1�L�[						*/
	KEYBOARDKEYDI8_2			= 3,		/**< 3		2�L�[						*/
	KEYBOARDKEYDI8_3			= 4,		/**< 4		3�L�[						*/
	KEYBOARDKEYDI8_4			= 5,		/**< 5		4�L�[						*/
	KEYBOARDKEYDI8_5			= 6,		/**< 6		5�L�[						*/
	KEYBOARDKEYDI8_6			= 7,		/**< 7		6�L�[						*/
	KEYBOARDKEYDI8_7			= 8,		/**< 8		7�L�[						*/
	KEYBOARDKEYDI8_8			= 9,		/**< 9		8�L�[						*/
	KEYBOARDKEYDI8_9			= 10,		/**< 10		9�L�[						*/
	KEYBOARDKEYDI8_0			= 11,		/**< 11		0�L�[						*/
	KEYBOARDKEYDI8_MINUS		= 12,		/**< 12		-�L�[						*/
	KEYBOARDKEYDI8_EQUALS		= 13,		/**< 13		=�L�[						*/
	KEYBOARDKEYDI8_BACK			= 14,		/**< 14		�o�b�N�X�y�[�X�L�[			*/
	KEYBOARDKEYDI8_TAB			= 15,		/**< 15		�^�u�L�[					*/
	KEYBOARDKEYDI8_Q			= 16,		/**< 16		q�L�[						*/
	KEYBOARDKEYDI8_W			= 17,		/**< 17		w�L�[						*/
	KEYBOARDKEYDI8_E			= 18,		/**< 18		e�L�[						*/
	KEYBOARDKEYDI8_R			= 19,		/**< 19		r�L�[						*/
	KEYBOARDKEYDI8_T			= 20,		/**< 20		t�L�[						*/
	KEYBOARDKEYDI8_Y			= 21,		/**< 21		y�L�[						*/
	KEYBOARDKEYDI8_U			= 22,		/**< 22		u�L�[						*/
	KEYBOARDKEYDI8_I			= 23,		/**< 23		i�L�[						*/
	KEYBOARDKEYDI8_O			= 24,		/**< 24		o�L�[						*/
	KEYBOARDKEYDI8_P			= 25,		/**< 25		p�L�[						*/
	KEYBOARDKEYDI8_LBRACKET		= 26,		/**< 26		���p����					*/
	KEYBOARDKEYDI8_RBRACKET		= 27,		/**< 27		�E�p����					*/
	KEYBOARDKEYDI8_RETURN		= 28,		/**< 28		���^�[���L�[				*/
	KEYBOARDKEYDI8_LCONTROL		= 29,		/**< 29		��Ctrl�L�[					*/
	KEYBOARDKEYDI8_A			= 30,		/**< 30		a�L�[						*/
	KEYBOARDKEYDI8_S			= 31,		/**< 31		s�L�[						*/
	KEYBOARDKEYDI8_D			= 32,		/**< 32		d�L�[						*/
	KEYBOARDKEYDI8_F			= 33,		/**< 33		f�L�[						*/
	KEYBOARDKEYDI8_G			= 34,		/**< 34		g�L�[						*/
	KEYBOARDKEYDI8_H			= 35,		/**< 35		h�L�[						*/
	KEYBOARDKEYDI8_J			= 36,		/**< 36		j�L�[						*/
	KEYBOARDKEYDI8_K			= 37,		/**< 37		k�L�[						*/
	KEYBOARDKEYDI8_L			= 38,		/**< 38		l�L�[						*/
	KEYBOARDKEYDI8_SEMICOLON	= 39,		/**< 39		,�L�[						*/
	KEYBOARDKEYDI8_APOSTROPHE	= 40,		/**< 40		:�L�[						*/
	KEYBOARDKEYDI8_GRAVE		= 41,		/**< 41		`�L�[						*/
	KEYBOARDKEYDI8_LSHIFT		= 42,		/**< 42		��SHIFT�L�[					*/
	KEYBOARDKEYDI8_BACKSLASH	= 43,		/**< 43		\�L�[						*/
	KEYBOARDKEYDI8_Z			= 44,		/**< 44		z�L�[						*/
	KEYBOARDKEYDI8_X			= 45,		/**< 45		x�L�[						*/
	KEYBOARDKEYDI8_C			= 46,		/**< 46		c�L�[						*/
	KEYBOARDKEYDI8_V			= 47,		/**< 47		v�L�[						*/
	KEYBOARDKEYDI8_B			= 48,		/**< 48		b�L�[						*/
	KEYBOARDKEYDI8_N			= 49,		/**< 49		n�L�[						*/
	KEYBOARDKEYDI8_M			= 50,		/**< 50		m�L�[						*/
	KEYBOARDKEYDI8_COMMA		= 51,		/**< 51		,�L�[						*/
	KEYBOARDKEYDI8_PERIOD		= 52,		/**< 52		.�L�[						*/
	KEYBOARDKEYDI8_SLASH		= 53,		/**< 53		/�L�[						*/
	KEYBOARDKEYDI8_RSHIFT		= 54,		/**< 54		�ESHIFT�L�[					*/
	KEYBOARDKEYDI8_MULTIPLY		= 55,		/**< 55		�e���L�[��*�L�[				*/
	KEYBOARDKEYDI8_LMENU		= 56,		/**< 56		��Alt�L�[					*/
	KEYBOARDKEYDI8_SPACE		= 57,		/**< 57		�X�y�[�X�L�[				*/
	KEYBOARDKEYDI8_CAPITAL		= 58,		/**< 58		CapsLock�L�[				*/
	KEYBOARDKEYDI8_F1			= 59,		/**< 59		F1�L�[						*/
	KEYBOARDKEYDI8_F2			= 60,		/**< 60		F2�L�[						*/
	KEYBOARDKEYDI8_F3			= 61,		/**< 61		F3�L�[						*/
	KEYBOARDKEYDI8_F4			= 62,		/**< 62		F4�L�[						*/
	KEYBOARDKEYDI8_F5			= 63,		/**< 63		F5�L�[						*/
	KEYBOARDKEYDI8_F6			= 64,		/**< 64		F6�L�[						*/
	KEYBOARDKEYDI8_F7			= 65,		/**< 65		F7�L�[						*/
	KEYBOARDKEYDI8_F8			= 66,		/**< 66		F8�L�[						*/
	KEYBOARDKEYDI8_F9			= 67,		/**< 67		F9�L�[						*/
	KEYBOARDKEYDI8_F10			= 68,		/**< 68		F10�L�[						*/
	KEYBOARDKEYDI8_NUMLOCK		= 69,		/**< 69		NumLock�L�[					*/
	KEYBOARDKEYDI8_SCROLL		= 70,		/**< 70		�X�N���[���L�[				*/
	KEYBOARDKEYDI8_NUMPAD7		= 71,		/**< 71		�e���L�[��7					*/
	KEYBOARDKEYDI8_NUMPAD8		= 72,		/**< 72		�e���L�[��8					*/
	KEYBOARDKEYDI8_NUMPAD9		= 73,		/**< 73		�e���L�[��9					*/
	KEYBOARDKEYDI8_SUBTRACT		= 74,		/**< 74		�e���L�[�́[�L�[			*/
	KEYBOARDKEYDI8_NUMPAD4		= 75,		/**< 75		�e���L�[��4					*/
	KEYBOARDKEYDI8_NUMPAD5		= 76,		/**< 76		�e���L�[��5					*/
	KEYBOARDKEYDI8_NUMPAD6		= 77,		/**< 77		�e���L�[��6					*/
	KEYBOARDKEYDI8_ADD			= 78,		/**< 78		�e���L�[�́{�L�[			*/
	KEYBOARDKEYDI8_NUMPAD1		= 79,		/**< 79		�e���L�[��1					*/
	KEYBOARDKEYDI8_NUMPAD2		= 80,		/**< 80		�e���L�[��2					*/
	KEYBOARDKEYDI8_NUMPAD3		= 81,		/**< 81		�e���L�[��3					*/
	KEYBOARDKEYDI8_NUMPAD0		= 82,		/**< 82		�e���L�[��0					*/
	KEYBOARDKEYDI8_DECIMAL		= 83,		/**< 83		�e���L�[��.�L�[				*/
	KEYBOARDKEYDI8_OEM_102		= 84,		/**< 84		�p�ꁕ�ƌ��102�L�[�{�[�h	*/
	KEYBOARDKEYDI8_F11			= 85,		/**< 85		F11�L�[						*/
	KEYBOARDKEYDI8_F12			= 86,		/**< 86		F12�L�[						*/
	KEYBOARDKEYDI8_F13			= 87,		/**< 87		F13�L�[(NEC-PC98�p)			*/
	KEYBOARDKEYDI8_F14			= 88,		/**< 88		F14�L�[(NEC-PC98�p)			*/
	KEYBOARDKEYDI8_F15			= 89,		/**< 89		F15�L�[(NEC-PC98�p)			*/
	KEYBOARDKEYDI8_KANA			= 90,		/**< 90		�J�i�L�[					*/
	KEYBOARDKEYDI8_CONVERT		= 91,		/**< 91		���{��L�[�{�[�h�̃L�[		*/
	KEYBOARDKEYDI8_NOCONVERT	= 92,		/**< 92		���{��L�[�{�[�h�̃L�[		*/
	KEYBOARDKEYDI8_YEN			= 93,		/**< 93		\�L�[						*/
	KEYBOARDKEYDI8_NUMPADEQUALS	= 94,		/**< 94		PC98�e���L�[�̃L�[			*/
	KEYBOARDKEYDI8_PREVTRACK	= 95,		/**< 95		�O�̃g���b�N�L�[			*/
	KEYBOARDKEYDI8_AT			= 96,		/**< 96		���{��L�[�{�[�h�̃L�[		*/
	KEYBOARDKEYDI8_COLON		= 97,		/**< 97		���{��L�[�{�[�h�̃L�[		*/
	KEYBOARDKEYDI8_UNDERLINE	= 98,		/**< 98		_�L�[						*/
	KEYBOARDKEYDI8_KANJI		= 99,		/**< 99		�����L�[					*/
	KEYBOARDKEYDI8_STOP			= 100,		/**< 100	PC98�p�L�[					*/
	KEYBOARDKEYDI8_AX			= 101,		/**< 101	���{��L�[�{�[�h�̃L�[		*/
	KEYBOARDKEYDI8_UNLABELED	= 102,		/**< 102	���{��L�[�{�[�h�̃L�[		*/
	KEYBOARDKEYDI8_NEXTTRACK	= 103,		/**< 103	���̃g���b�N�L�[			*/
	KEYBOARDKEYDI8_NUMPADENTER	= 104,		/**< 104	�e���L�[�̃G���^�[�L�[		*/
	KEYBOARDKEYDI8_RCONTROL		= 105,		/**< 105	�ECtrl�L�[					*/
	KEYBOARDKEYDI8_MUTE			= 106,		/**< 106	�~���[�g�L�[				*/
	KEYBOARDKEYDI8_CALCULATOR	= 107,		/**< 107	�d��L�[					*/
	KEYBOARDKEYDI8_PLAYPAUSE	= 108,		/**< 108	�ꎞ��~�L�[				*/
	KEYBOARDKEYDI8_MEDIASTOP	= 109,		/**< 109	���f�B�A��~�L�[			*/
	KEYBOARDKEYDI8_VOLUMEDOWN	= 110,		/**< 110	���ʃ_�E���L�[				*/
	KEYBOARDKEYDI8_VOLUMEUP		= 111,		/**< 111	���ʃA�b�v�L�[				*/
	KEYBOARDKEYDI8_WEBHOME		= 112,		/**< 112	�E�F�u�z�[���y�[�W�L�[		*/
	KEYBOARDKEYDI8_NUMPADCOMMA	= 113,		/**< 113	�e���L�[��.�L�[				*/
	KEYBOARDKEYDI8_DIVIDE		= 114,		/**< 114	�e���L�[��/�L�[				*/
	KEYBOARDKEYDI8_SYSRQ		= 115,		/**< 115	SysRq�L�[					*/
	KEYBOARDKEYDI8_RMENU		= 116,		/**< 116	�E���j���[�L�[				*/
	KEYBOARDKEYDI8_PAUSE		= 117,		/**< 117	�|�[�Y�L�[					*/
	KEYBOARDKEYDI8_HOME			= 118,		/**< 118	�z�[���L�[					*/
	KEYBOARDKEYDI8_UP			= 119,		/**< 119	���L�[						*/
	KEYBOARDKEYDI8_PRIOR		= 120,		/**< 120	PageUp�L�[					*/
	KEYBOARDKEYDI8_LEFT			= 121,		/**< 121	���L�[						*/
	KEYBOARDKEYDI8_RIGHT		= 122,		/**< 122	���L�[						*/
	KEYBOARDKEYDI8_END			= 123,		/**< 123	End�L�[						*/
	KEYBOARDKEYDI8_DOWN			= 124,		/**< 124	���L�[						*/
	KEYBOARDKEYDI8_NEXT			= 125,		/**< 125	Next�L�[					*/
	KEYBOARDKEYDI8_INSERT		= 126,		/**< 126	Insert�L�[					*/
	KEYBOARDKEYDI8_DELETE		= 127,		/**< 127	�f���[�g�L�[				*/
	KEYBOARDKEYDI8_LWIN			= 128,		/**< 128	��Windows�L�[				*/
	KEYBOARDKEYDI8_RWIN			= 129,		/**< 129	�EWindows�L�[				*/
	KEYBOARDKEYDI8_APPS			= 130,		/**< 130	�A�v���P�[�V�����L�[		*/
	KEYBOARDKEYDI8_POWER		= 131,		/**< 131	�d���L�[					*/
	KEYBOARDKEYDI8_SLEEP		= 132,		/**< 132	�X���[�v�L�[				*/
	KEYBOARDKEYDI8_WAKE			= 133,		/**< 133	�E�F�[�N�A�b�v�L�[			*/
	KEYBOARDKEYDI8_WEBSEARCH	= 134,		/**< 134	WEB�����L�[					*/
	KEYBOARDKEYDI8_WEBFAVORITES	= 135,		/**< 135	���C�ɓ���L�[				*/
	KEYBOARDKEYDI8_WEBREFRESH	= 136,		/**< 136	�E�F�u���t���b�V���L�[		*/
	KEYBOARDKEYDI8_WEBSTOP		= 137,		/**< 137	���f�B�A�I���L�[			*/
	KEYBOARDKEYDI8_WEBFORWARD	= 138,		/**< 138	�E�F�u��ɐi�ރL�[			*/
	KEYBOARDKEYDI8_WEBBACK		= 139,		/**< 139	�E�F�u�O�ɖ߂�L�[			*/
	KEYBOARDKEYDI8_MYCOMPUTER	= 140,		/**< 140	�}�C�R���s���[�^�L�[		*/
	KEYBOARDKEYDI8_MAIL			= 141,		/**< 141	���[���L�[					*/
	KEYBOARDKEYDI8_MEDIASELECT	= 142,		/**< 142	���f�B�A�I���L�[			*/

	KEYBOARDKEYDI8_COUNT					/**< �L�[�{�[�h�L�[��					*/
};

} // namespace DirectInput

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/