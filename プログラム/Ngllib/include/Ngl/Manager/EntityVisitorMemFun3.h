/*******************************************************************************/
/**
 * @file EntityVisitorMemFun3.h.
 * 
 * @brief 3引数関数ポインタ訪問者クラス定義.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nisimura.
 */
/******************************************************************************/
#ifndef _NGLENTITYVISITORMEMFUN3_H_
#define _NGLENTITYVISITORMEMFUN3_H_

#include	"IEntityVisitor.h"

namespace Ngl{


/**
 * @class EntityVisitorMemFun3.
 * @brief 3引数関数ポインタ訪問者クラス．
 * @tparam Entity 訪問した要素.
 * @tparam First 引数1の型.
 * @tparam Second 引数2の型.
 * @tparam Third 引数3の型.
 * @tparam MemFun 訪問関数ポインタ( void 関数( 引数1, 引数2, 引数3 ) ).
 */
template
<
	typename Entity,
	typename First,
	typename Second,
	typename Third,
	typename void (Entity::*MenFun)( First, Second, Third )
>
class EntityVisitorMemFun3 : public IEntityVisitor<Entity*>
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
	EntityVisitorMemFun3( First first, Second second, Third third ) :
		first_( first ),
		second_( second ),
		third_( third )
	{}

	
	/*=========================================================================*/
	/**
	 * @brief 訪問する
	 * 
	 * @param[in] entity 要素.
	 * @return なし.
	 */
	void visit( Entity* entity )
	{
		( entity->*MemFun )( first_, second_, third_ );
	}

private:

	/** 第一引数 */
	First first_;
	
	/** 第二引数 */
	Second second_;

	/** 第三引数 */
	Third third_;
};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/