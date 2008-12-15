/*******************************************************************************/
/**
 * @file AIBase.h.
 * 
 * @brief AIベースクラス定義.
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

/*===== インクルード ==========================================================*/


class AIBase{
public:
	virtual ~AIBase(){}
	virtual bool GetKeyTrigger(unsigned int key) = 0;
	virtual bool GetKeyDown(unsigned int key)	 = 0;

};
#endif