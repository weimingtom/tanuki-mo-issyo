/*******************************************************************************/
/**
 * @file AIBase.h.
 * 
 * @brief AI�x�[�X�N���X��`.
 *
 * @date 2008/12/15.
 *
 * @version 1.00.
 *
 * @author Tsubasa Uragami.
 */
/*******************************************************************************/
#ifndef _AIBASE_H_
#define _AIBASE_H_

/*===== �C���N���[�h ==========================================================*/


class AIBase{
public:
	virtual ~AIBase(){}
	virtual bool GetKeyTrigger(unsigned int key) = 0;
	virtual bool GetKeyDown(unsigned int key)	 = 0;

};
#endif