/*******************************************************************************/
/**
 * @file AIRoutineBase.h.
 * 
 * @brief AI���[�`���x�[�X�N���X��`.
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

/*===== �C���N���[�h ==========================================================*/


class AIRoutineBase{
public:
	virtual ~AIRoutineBase(){}
	virtual void Update(float frameTimer)		 = 0;

};
#endif