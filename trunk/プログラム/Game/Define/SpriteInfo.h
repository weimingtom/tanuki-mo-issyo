/*******************************************************************************/
/**
 * @file SpriteInfo.h.
 * 
 * @brief ÉQÅ[ÉÄå^íËã`.
 *
 * @date 2008/12/09.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/

#ifndef _SPRITEINFO_H_
#define _SPRITEINFO_H_

#include	<String>
#include	"Define.h"

typedef struct
{
	std::string	spriteName;
	Vector2		srcPosition;
	Vector2		srcSize;
	Vector2		position;
	Vector2		size;
}SpriteInfo;

#endif