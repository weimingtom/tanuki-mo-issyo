/*******************************************************************************/
/**
 * @file AIRoutineBase.h.
 * 
 * @brief AIルーチンベースクラス定義.
 *
 * @date 2009/04/17.
 *
 * @version 1.00.
 *
 * @author Tsubasa Uragami.
 */
/*******************************************************************************/
#ifndef _AIROUTINEBASE_H_
#define _AIROUTINEBASE_H_

/*===== インクルード ==========================================================*/


class AIRoutineBase{
public:
	virtual ~AIRoutineBase(){}
	virtual void Update(float frameTimer)		 = 0;

};
#endif