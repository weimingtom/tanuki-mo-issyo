/*******************************************************************************/
/**
 * @file IEntityPairVisitor.h.
 * 
 * @brief ペア訪問者インターフェース定義.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IENTITYPAIRVISITOR_H_
#define _NGL_IENTITYPAIRVISITOR_H_

namespace Ngl{


/**
 * @interface IEntityPairVisitor.
 * @brief ペア訪問者インターフェース.
 * @tparam Entity 訪問する要素.
 */
template <class Entity>
class IEntityPairVisitor
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IEntityPairVisitor(){}


	/*=========================================================================*/
	/**
	 * @brief 訪問する
	 * 
	 * @param[in] entity1 訪問する要素その1.
	 * @param[in] entity2 訪問する要素その2.
	 * @return なし.
	 */
	virtual void visit( Entity entity1, Entity entity2 ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/