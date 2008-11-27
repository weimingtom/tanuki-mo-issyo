/*******************************************************************************/
/**
 * @file KeyboardKeyDI8.h.
 * 
 * @brief DirectInput キーボードキー定数列挙型定義.
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
 * @enum KeyboardKeyDI8．
 * @brief DirectInput キーボードキー定数列挙型.
 */
enum KeyboardKeyDI8
{
	KEYBOARDKEYDI8_NONE			= 0,		/**< 0		何も押されていない			*/
	KEYBOARDKEYDI8_ESCAPE		= 1,		/**< 1		エスケープキー				*/
	KEYBOARDKEYDI8_1			= 2,		/**< 2		1キー						*/
	KEYBOARDKEYDI8_2			= 3,		/**< 3		2キー						*/
	KEYBOARDKEYDI8_3			= 4,		/**< 4		3キー						*/
	KEYBOARDKEYDI8_4			= 5,		/**< 5		4キー						*/
	KEYBOARDKEYDI8_5			= 6,		/**< 6		5キー						*/
	KEYBOARDKEYDI8_6			= 7,		/**< 7		6キー						*/
	KEYBOARDKEYDI8_7			= 8,		/**< 8		7キー						*/
	KEYBOARDKEYDI8_8			= 9,		/**< 9		8キー						*/
	KEYBOARDKEYDI8_9			= 10,		/**< 10		9キー						*/
	KEYBOARDKEYDI8_0			= 11,		/**< 11		0キー						*/
	KEYBOARDKEYDI8_MINUS		= 12,		/**< 12		-キー						*/
	KEYBOARDKEYDI8_EQUALS		= 13,		/**< 13		=キー						*/
	KEYBOARDKEYDI8_BACK			= 14,		/**< 14		バックスペースキー			*/
	KEYBOARDKEYDI8_TAB			= 15,		/**< 15		タブキー					*/
	KEYBOARDKEYDI8_Q			= 16,		/**< 16		qキー						*/
	KEYBOARDKEYDI8_W			= 17,		/**< 17		wキー						*/
	KEYBOARDKEYDI8_E			= 18,		/**< 18		eキー						*/
	KEYBOARDKEYDI8_R			= 19,		/**< 19		rキー						*/
	KEYBOARDKEYDI8_T			= 20,		/**< 20		tキー						*/
	KEYBOARDKEYDI8_Y			= 21,		/**< 21		yキー						*/
	KEYBOARDKEYDI8_U			= 22,		/**< 22		uキー						*/
	KEYBOARDKEYDI8_I			= 23,		/**< 23		iキー						*/
	KEYBOARDKEYDI8_O			= 24,		/**< 24		oキー						*/
	KEYBOARDKEYDI8_P			= 25,		/**< 25		pキー						*/
	KEYBOARDKEYDI8_LBRACKET		= 26,		/**< 26		左角括弧					*/
	KEYBOARDKEYDI8_RBRACKET		= 27,		/**< 27		右角括弧					*/
	KEYBOARDKEYDI8_RETURN		= 28,		/**< 28		リターンキー				*/
	KEYBOARDKEYDI8_LCONTROL		= 29,		/**< 29		左Ctrlキー					*/
	KEYBOARDKEYDI8_A			= 30,		/**< 30		aキー						*/
	KEYBOARDKEYDI8_S			= 31,		/**< 31		sキー						*/
	KEYBOARDKEYDI8_D			= 32,		/**< 32		dキー						*/
	KEYBOARDKEYDI8_F			= 33,		/**< 33		fキー						*/
	KEYBOARDKEYDI8_G			= 34,		/**< 34		gキー						*/
	KEYBOARDKEYDI8_H			= 35,		/**< 35		hキー						*/
	KEYBOARDKEYDI8_J			= 36,		/**< 36		jキー						*/
	KEYBOARDKEYDI8_K			= 37,		/**< 37		kキー						*/
	KEYBOARDKEYDI8_L			= 38,		/**< 38		lキー						*/
	KEYBOARDKEYDI8_SEMICOLON	= 39,		/**< 39		,キー						*/
	KEYBOARDKEYDI8_APOSTROPHE	= 40,		/**< 40		:キー						*/
	KEYBOARDKEYDI8_GRAVE		= 41,		/**< 41		`キー						*/
	KEYBOARDKEYDI8_LSHIFT		= 42,		/**< 42		左SHIFTキー					*/
	KEYBOARDKEYDI8_BACKSLASH	= 43,		/**< 43		\キー						*/
	KEYBOARDKEYDI8_Z			= 44,		/**< 44		zキー						*/
	KEYBOARDKEYDI8_X			= 45,		/**< 45		xキー						*/
	KEYBOARDKEYDI8_C			= 46,		/**< 46		cキー						*/
	KEYBOARDKEYDI8_V			= 47,		/**< 47		vキー						*/
	KEYBOARDKEYDI8_B			= 48,		/**< 48		bキー						*/
	KEYBOARDKEYDI8_N			= 49,		/**< 49		nキー						*/
	KEYBOARDKEYDI8_M			= 50,		/**< 50		mキー						*/
	KEYBOARDKEYDI8_COMMA		= 51,		/**< 51		,キー						*/
	KEYBOARDKEYDI8_PERIOD		= 52,		/**< 52		.キー						*/
	KEYBOARDKEYDI8_SLASH		= 53,		/**< 53		/キー						*/
	KEYBOARDKEYDI8_RSHIFT		= 54,		/**< 54		右SHIFTキー					*/
	KEYBOARDKEYDI8_MULTIPLY		= 55,		/**< 55		テンキーの*キー				*/
	KEYBOARDKEYDI8_LMENU		= 56,		/**< 56		左Altキー					*/
	KEYBOARDKEYDI8_SPACE		= 57,		/**< 57		スペースキー				*/
	KEYBOARDKEYDI8_CAPITAL		= 58,		/**< 58		CapsLockキー				*/
	KEYBOARDKEYDI8_F1			= 59,		/**< 59		F1キー						*/
	KEYBOARDKEYDI8_F2			= 60,		/**< 60		F2キー						*/
	KEYBOARDKEYDI8_F3			= 61,		/**< 61		F3キー						*/
	KEYBOARDKEYDI8_F4			= 62,		/**< 62		F4キー						*/
	KEYBOARDKEYDI8_F5			= 63,		/**< 63		F5キー						*/
	KEYBOARDKEYDI8_F6			= 64,		/**< 64		F6キー						*/
	KEYBOARDKEYDI8_F7			= 65,		/**< 65		F7キー						*/
	KEYBOARDKEYDI8_F8			= 66,		/**< 66		F8キー						*/
	KEYBOARDKEYDI8_F9			= 67,		/**< 67		F9キー						*/
	KEYBOARDKEYDI8_F10			= 68,		/**< 68		F10キー						*/
	KEYBOARDKEYDI8_NUMLOCK		= 69,		/**< 69		NumLockキー					*/
	KEYBOARDKEYDI8_SCROLL		= 70,		/**< 70		スクロールキー				*/
	KEYBOARDKEYDI8_NUMPAD7		= 71,		/**< 71		テンキーの7					*/
	KEYBOARDKEYDI8_NUMPAD8		= 72,		/**< 72		テンキーの8					*/
	KEYBOARDKEYDI8_NUMPAD9		= 73,		/**< 73		テンキーの9					*/
	KEYBOARDKEYDI8_SUBTRACT		= 74,		/**< 74		テンキーのーキー			*/
	KEYBOARDKEYDI8_NUMPAD4		= 75,		/**< 75		テンキーの4					*/
	KEYBOARDKEYDI8_NUMPAD5		= 76,		/**< 76		テンキーの5					*/
	KEYBOARDKEYDI8_NUMPAD6		= 77,		/**< 77		テンキーの6					*/
	KEYBOARDKEYDI8_ADD			= 78,		/**< 78		テンキーの＋キー			*/
	KEYBOARDKEYDI8_NUMPAD1		= 79,		/**< 79		テンキーの1					*/
	KEYBOARDKEYDI8_NUMPAD2		= 80,		/**< 80		テンキーの2					*/
	KEYBOARDKEYDI8_NUMPAD3		= 81,		/**< 81		テンキーの3					*/
	KEYBOARDKEYDI8_NUMPAD0		= 82,		/**< 82		テンキーの0					*/
	KEYBOARDKEYDI8_DECIMAL		= 83,		/**< 83		テンキーの.キー				*/
	KEYBOARDKEYDI8_OEM_102		= 84,		/**< 84		英語＆独語の102キーボード	*/
	KEYBOARDKEYDI8_F11			= 85,		/**< 85		F11キー						*/
	KEYBOARDKEYDI8_F12			= 86,		/**< 86		F12キー						*/
	KEYBOARDKEYDI8_F13			= 87,		/**< 87		F13キー(NEC-PC98用)			*/
	KEYBOARDKEYDI8_F14			= 88,		/**< 88		F14キー(NEC-PC98用)			*/
	KEYBOARDKEYDI8_F15			= 89,		/**< 89		F15キー(NEC-PC98用)			*/
	KEYBOARDKEYDI8_KANA			= 90,		/**< 90		カナキー					*/
	KEYBOARDKEYDI8_CONVERT		= 91,		/**< 91		日本語キーボードのキー		*/
	KEYBOARDKEYDI8_NOCONVERT	= 92,		/**< 92		日本語キーボードのキー		*/
	KEYBOARDKEYDI8_YEN			= 93,		/**< 93		\キー						*/
	KEYBOARDKEYDI8_NUMPADEQUALS	= 94,		/**< 94		PC98テンキーのキー			*/
	KEYBOARDKEYDI8_PREVTRACK	= 95,		/**< 95		前のトラックキー			*/
	KEYBOARDKEYDI8_AT			= 96,		/**< 96		日本語キーボードのキー		*/
	KEYBOARDKEYDI8_COLON		= 97,		/**< 97		日本語キーボードのキー		*/
	KEYBOARDKEYDI8_UNDERLINE	= 98,		/**< 98		_キー						*/
	KEYBOARDKEYDI8_KANJI		= 99,		/**< 99		漢字キー					*/
	KEYBOARDKEYDI8_STOP			= 100,		/**< 100	PC98用キー					*/
	KEYBOARDKEYDI8_AX			= 101,		/**< 101	日本語キーボードのキー		*/
	KEYBOARDKEYDI8_UNLABELED	= 102,		/**< 102	日本語キーボードのキー		*/
	KEYBOARDKEYDI8_NEXTTRACK	= 103,		/**< 103	次のトラックキー			*/
	KEYBOARDKEYDI8_NUMPADENTER	= 104,		/**< 104	テンキーのエンターキー		*/
	KEYBOARDKEYDI8_RCONTROL		= 105,		/**< 105	右Ctrlキー					*/
	KEYBOARDKEYDI8_MUTE			= 106,		/**< 106	ミュートキー				*/
	KEYBOARDKEYDI8_CALCULATOR	= 107,		/**< 107	電卓キー					*/
	KEYBOARDKEYDI8_PLAYPAUSE	= 108,		/**< 108	一時停止キー				*/
	KEYBOARDKEYDI8_MEDIASTOP	= 109,		/**< 109	メディア停止キー			*/
	KEYBOARDKEYDI8_VOLUMEDOWN	= 110,		/**< 110	音量ダウンキー				*/
	KEYBOARDKEYDI8_VOLUMEUP		= 111,		/**< 111	音量アップキー				*/
	KEYBOARDKEYDI8_WEBHOME		= 112,		/**< 112	ウェブホームページキー		*/
	KEYBOARDKEYDI8_NUMPADCOMMA	= 113,		/**< 113	テンキーの.キー				*/
	KEYBOARDKEYDI8_DIVIDE		= 114,		/**< 114	テンキーの/キー				*/
	KEYBOARDKEYDI8_SYSRQ		= 115,		/**< 115	SysRqキー					*/
	KEYBOARDKEYDI8_RMENU		= 116,		/**< 116	右メニューキー				*/
	KEYBOARDKEYDI8_PAUSE		= 117,		/**< 117	ポーズキー					*/
	KEYBOARDKEYDI8_HOME			= 118,		/**< 118	ホームキー					*/
	KEYBOARDKEYDI8_UP			= 119,		/**< 119	↑キー						*/
	KEYBOARDKEYDI8_PRIOR		= 120,		/**< 120	PageUpキー					*/
	KEYBOARDKEYDI8_LEFT			= 121,		/**< 121	←キー						*/
	KEYBOARDKEYDI8_RIGHT		= 122,		/**< 122	→キー						*/
	KEYBOARDKEYDI8_END			= 123,		/**< 123	Endキー						*/
	KEYBOARDKEYDI8_DOWN			= 124,		/**< 124	↓キー						*/
	KEYBOARDKEYDI8_NEXT			= 125,		/**< 125	Nextキー					*/
	KEYBOARDKEYDI8_INSERT		= 126,		/**< 126	Insertキー					*/
	KEYBOARDKEYDI8_DELETE		= 127,		/**< 127	デリートキー				*/
	KEYBOARDKEYDI8_LWIN			= 128,		/**< 128	左Windowsキー				*/
	KEYBOARDKEYDI8_RWIN			= 129,		/**< 129	右Windowsキー				*/
	KEYBOARDKEYDI8_APPS			= 130,		/**< 130	アプリケーションキー		*/
	KEYBOARDKEYDI8_POWER		= 131,		/**< 131	電源キー					*/
	KEYBOARDKEYDI8_SLEEP		= 132,		/**< 132	スリープキー				*/
	KEYBOARDKEYDI8_WAKE			= 133,		/**< 133	ウェークアップキー			*/
	KEYBOARDKEYDI8_WEBSEARCH	= 134,		/**< 134	WEB検索キー					*/
	KEYBOARDKEYDI8_WEBFAVORITES	= 135,		/**< 135	お気に入りキー				*/
	KEYBOARDKEYDI8_WEBREFRESH	= 136,		/**< 136	ウェブリフレッシュキー		*/
	KEYBOARDKEYDI8_WEBSTOP		= 137,		/**< 137	メディア選択キー			*/
	KEYBOARDKEYDI8_WEBFORWARD	= 138,		/**< 138	ウェブ先に進むキー			*/
	KEYBOARDKEYDI8_WEBBACK		= 139,		/**< 139	ウェブ前に戻るキー			*/
	KEYBOARDKEYDI8_MYCOMPUTER	= 140,		/**< 140	マイコンピュータキー		*/
	KEYBOARDKEYDI8_MAIL			= 141,		/**< 141	メールキー					*/
	KEYBOARDKEYDI8_MEDIASELECT	= 142,		/**< 142	メディア選択キー			*/

	KEYBOARDKEYDI8_COUNT					/**< キーボードキー数					*/
};

} // namespace DirectInput

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/