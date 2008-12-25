/*******************************************************************************/
/**
 * @file GameDefine.h.
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
#ifndef _GAMEDEFINE_H_
#define _GAMEDEFINE_H_

/*===== íËêîêÈåæ ==============================================================*/
#define BLOCK_SIZE 30
#define FIELD_WIDTH 9
#define FIELD_HEIGHT 16



typedef struct
{
	int matrix[FIELD_WIDTH][FIELD_HEIGHT];
}FieldMatrix;

typedef struct
{
	bool checkedmatrix[FIELD_WIDTH][FIELD_HEIGHT];
	//bool deleteflagmatrix[FIELD_WIDTH][FIELD_HEIGHT];
}CheckMatrix;

typedef struct
{
	int x;
	int y;
}IntPoint;

enum 
{
	AVATAR_ANIMATION_STATE_STAND = 0,
	AVATAR_ANIMATION_STATE_ATTACK,
	AVATAR_ANIMATION_STATE_DAMAGE
};

#endif

/*===== EOF ===================================================================*/