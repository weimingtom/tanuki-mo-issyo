/*******************************************************************************/
/**
 * @file TextDesc.h.
 * 
 * @brief テキスト描画構造体定義.
 *
 * @date 2008/12/23.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _TEXTDESC_H_
#define _TEXTDESC_H_

/*===== インクルード ==========================================================*/
#include	"Define/Define.h"
#include	<string>

/*===== 定数宣言 ==============================================================*/
#define FONT_CODE_NORMAL	0
#define FONT_CODE_BOLD		(1 << 0)
#define FONT_CODE_ITALIC	(1 << 1)
#define FONT_CODE_UNDERLINE	(1 << 2)
#define FONT_CODE_STRIKEOUT	(1 << 3)

struct TextDesc
{
	unsigned int code;
	unsigned int size;
	std::string font;
	std::string string;
	
};

#endif

/*===== EOF ===================================================================*/