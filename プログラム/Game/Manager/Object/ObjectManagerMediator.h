/*******************************************************************************/
/**
 * @file ObjectManagerMediator.h.
 * 
 * @brief オブジェクト管理者仲介クラスの定義.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _OBJECT_MANAGER_MEDIATOR_H_
#define _OBJECT_MANAGER_MEDIATOR_H_

/*===== インクルード ==========================================================*/
#include	"Object/ObjectBase.h"


/**
 * @brief ObjectManagerMediator．
 */
class ObjectManagerMediator
{
public:

	/*=========================================================================*/
	/**
	 * @brief 仮想デストラクタ.
	 *
	 */
	virtual ~ObjectManagerMediator(){}

	/*=========================================================================*/
	/**
	 * @brief オブジェクトの追加.
	 * 
	 * @param[in] objectID 追加するオブジェクト.
	 */
	virtual void AddObject(int objectID) = 0;
	/*=========================================================================*/
	/**
	 * @brief オブジェクトの削除.
	 * 
	 * @param[in] object 削除するオブジェクト.
	 */
	virtual void DelObject(ObjectBase* object) = 0;

};

#endif

/*===== EOF ===================================================================*/