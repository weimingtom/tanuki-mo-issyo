/*******************************************************************************/
/**
 * @file KeyInfo.h.
 * 
 * @brief キーフラグ構造体定義.
 *
 * @date 2009/04/17.
 *
 * @version 1.00.
 *
 * @author Tsubasa Uragami.
 */
/*******************************************************************************/
#ifndef _KEYINFOAI_H_
#define _KEYINFOAI_H_

typedef struct
{
	bool keyTrigger_up;
	bool keyTrigger_down;
	bool keyTrigger_right;
	bool keyTrigger_left;
	bool keyTrigger_circle;
	bool keyTrigger_triangle;
	bool keyDown_up;
	bool keyDown_down;
	bool keyDown_right;
	bool keyDown_left;
}KeyInfo;

#endif