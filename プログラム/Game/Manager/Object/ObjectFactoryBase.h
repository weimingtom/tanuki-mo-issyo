/*******************************************************************************/
/**
 * @file ObjectFactoryBase.h.
 * 
 * @brief オブジェクト生成基底クラスの定義.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _OBJECT_FACTORY_BASE_H_
#define _OBJECT_FACTORY_BASE_H_

/*===== インクルード ==========================================================*/
class	ObjectBase;


/**
 * @brief ObjectFactoryBase．
 */
class ObjectFactoryBase
{
public:

	/*=========================================================================*/
	/**
	 * @brief 仮想デストラクタ.
	 */
	virtual ~ObjectFactoryBase(){}

	/*=========================================================================*/
	/**
	 * @brief オブジェクトの生成.
	 * 
	 * @param[in] objectID 生成するオブジェクトのID.
	 * @return 生成したオブジェクトのポインタ.
	 */
	virtual ObjectBase* CreateObject(int objectID) = 0;

};

#endif

/*===== EOF ===================================================================*/