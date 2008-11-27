/*******************************************************************************/
/**
 * @file EntityEvaluatorMemFun1.h.
 * 
 * @brief 1引数関数ポインタ評価者クラス定義.
 *
 * @date 2007/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ENTITYEVALUATORMEMFUN1_H_
#define _NGL_ENTITYEVALUATORMEMFUN1_H_

#include	"IEntityEvaluator.h"

namespace Ngl{

/**
 * @class EntityEvaluatorMemFun1.
 * @brief 1引数関数ポインタ評価者クラス．
 * @tparam Entity 評価する要素.
 * @tparam First 引数の型.
 * @tparam MemFun 評価関数ポインタ( bool 関数( 引数1 ) const ).
 */
template
<
	typename Entity,
	typename First,
	typename bool(Entity::*MemFun)( First ) const
>
class EntityEvaluatorMemFun1 : public IEntityEvaluator<Entity*>
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] first 引数.
	 */
	EntityEvaluatorMemFun1( First first ) :
	  first_( first )
	{}


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
		return (entity->*MemFun)( first_ );
	}

private:

	/** 第一引数 */
	First	first_;
};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/