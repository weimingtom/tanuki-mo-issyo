/*******************************************************************************/
/**
 * @file EntityVisitorMemFun.h.
 * 
 * @brief 引数なし関数ポインタ訪問者クラス定義.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ENTITYVISITORMEMFUN_H_
#define _NGL_ENTITYVISITORMEMFUN_H_

#include	"IEntityVisitor.h"

namespace Ngl{


/**
 * @class EntityVisitorMemFun.
 * @brief 引数なし関数ポインタ訪問者クラス．
 * @tparam Entity 訪問した要素.
 * @tparam MemFun 訪問関数ポインタ( void 関数() ).
 */
template
<
	typename Entity,
	typename void (Entity::*MenFun)()
>
class EntityVisitorMemFun : public IEntityVisitor<Entity*>
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief 訪問する
	 * 
	 * @param[in] entity 訪問した要素.
	 * @return なし.
	 */
	void visit( Entity* entity )
	{
		(entity->*MemFun)();
	}

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/