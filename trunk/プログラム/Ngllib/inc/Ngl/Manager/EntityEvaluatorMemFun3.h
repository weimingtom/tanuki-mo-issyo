/*******************************************************************************/
/**
 * @file EntityEvaluatorMemFun3.h.
 * 
 * @brief 3引数関数ポインタ評価者クラス定義.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ENTITYEVALUATORMEMFUN3_H_
#define _NGL_ENTITYEVALUATORMEMFUN3_H_

#include	"IEntityEvaluator.h"

namespace Ngl{


/**
 * @class EntityEvaluatorMemFun3.
 * @brief 3引数関数ポインタ評価者クラス．
 * @tparam Entity 評価する要素.
 * @tparam First 引数1の型.
 * @tparam Second 引数2の型.
 * @tparam Third 引数3の型.
 * @tparam MemFun 評価関数ポインタ( bool 関数( 引数1, 引数2, 引数3 ) const ).
 */
template<
	typename Entity,
	typename First,
	typename Second,
	typename Third,
	typename bool(Entity::*MemFun)( First, Second, Third ) const
>
class EntityEvaluatorMemFun3 : public IEntityEvaluator<Entity*>
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] first 引数１.
	 * @param[in] second 引数２.
	 * @param[in] third 引数３.
	 */
	EntityEvaluatorMemFun3( First first, Second second , Third third ) :
	  first_( first ),
	  second_( second ),
	  third_( third )
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
		return (entity->*MemFun)( first_, second_ , third_ );
	}

private:

	/** 第一引数 */
	First	first_;

	/** 第二引数 */
	Second	second_;

	/** 第三引数 */
	Third third_;
};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/