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
	bool GetIsThinking()
	{
		return m_isThinking;
	}
	void SetIsThinking(bool flag)
	{
		m_isThinking = flag;
	}
	virtual bool GetKeyTrigger(unsigned int key) = 0;
	virtual bool GetKeyDown(unsigned int key)	 = 0;
	int GetTargetPosition()
	{
		return m_targetPosition;
	}
	void SetTargetPosition(int position)
	{
		m_targetPosition = position;
	}
	int GetTargetAngle()
	{
		return  m_targetAngle;
	}
	void SetTargetAngle(int angle)
	{
		m_targetAngle = angle;
	}
	virtual void Update(float frameTimer)		 = 0;
protected:
	bool	m_isThinking;
	int		m_targetPosition;
	int		m_targetAngle;
};
#endif