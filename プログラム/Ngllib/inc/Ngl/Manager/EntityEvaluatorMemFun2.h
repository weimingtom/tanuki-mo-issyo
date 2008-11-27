/*******************************************************************************/
/**
 * @file EntityEvaluatorMemFun2.h.
 * 
 * @brief 2引数関数ポインタ評価者クラス定義.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ENTITYEVALUATORMEMFUN2_H_
#define _NGL_ENTITYEVALUATORMEMFUN2_H_

#include	"IEntityEvaluator.h"

namespace Ngl{


/**
 * @class EntityEvaluatorMemFun2.
 * @brief 2引数関数ポインタ評価者クラス．
 * @tparam Entity 評価する要素.
 * @tparam First 引数1の型.
 * @tparam Second 引数2の型.
 * @tparam MemFun 評価関数ポインタ( bool 関数( 引数1, 引数2 ) const ).
 */
template<
	typename Entity,
	typename First,
	typename Second,
	typename bool(Entity::*MemFun)( First, Second ) const
>
class EntityEvaluatorMemFun2 : public IEntityEvaluator<Entity*>
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] first 引数1.
	 * @param[in] second 引数2.
	 */
	EntityEvaluatorMemFun2( First first, Second second ) :
	  first_( first ),
	  second_( second )
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
		return (entity->*MemFun)( first_, second_ );
	}

private:

	/** 第一引数 */
	First	first_;

	/** 第二引数 */
	Second	second_;
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/