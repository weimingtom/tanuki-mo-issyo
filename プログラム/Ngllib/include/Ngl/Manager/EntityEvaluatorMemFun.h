/*******************************************************************************/
/**
 * @file EntityEvaluatorMemFun.h.
 * 
 * @brief 引数なし関数ポインタ評価者クラス定義.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimrua.
 */
/******************************************************************************/
#ifndef _NGL_ENTITYEVALUATORMEMFUN_H_
#define _NGL_ENTITYEVALUATORMEMFUN_H_

#include	"IEntityEvaluator.h"

namespace Ngl{


/**
 * @class EntityEvaluatorMemFun.
 * @brief 引数なし関数ポインタ評価者クラス．
 * @tparam Entity 評価する要素.
 * @tparam MemFun 評価関数ポインタ( bool 関数() const ).
 */
template<
	typename Entity,
	typename bool(Entity::*MemFun)() const
>
class EntityEvaluatorMemFun : public IEntityEvaluator<Entity*>
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief 評価する
	 * 
	 * @param[in] entity 評価する要素.
	 * @retval true 正しい.
	 * @retval false 間違い.
	 */
	bool evaluate( Entity* entity )
	{
		return (entity->*MemFun)();
	}
};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/