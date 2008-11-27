/*******************************************************************************/
/**
 * @file IEntityVisitor.h.
 * 
 * @brief 訪問者インターフェース定義.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IENTITYVISITOR_H_
#define _NGL_IENTITYVISITOR_H_

namespace Ngl{


/**
 * @interface IEntityVisitor.
 * @brief 訪問者インターフェース.
 * @tparam Entity 訪問する要素.
 */
template <class Entity>
class IEntityVisitor
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IEntityVisitor(){}


	/*=========================================================================*/
	/**
	 * @brief 訪問する
	 * 
	 * @param[in] entity 要素.
	 * @return なし.
	 */
	virtual void visit( Entity entity ) = 0;
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/