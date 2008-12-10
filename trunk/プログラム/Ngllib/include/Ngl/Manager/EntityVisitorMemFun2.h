/*******************************************************************************/
/**
 * @file EntityVisitorMemFun2.h.
 * 
 * @brief 2引数関数ポインタ訪問者クラス定義.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nisimura.
 */
/******************************************************************************/
#ifndef _NGLENTITYVISITORMEMFUN2_H_
#define _NGLENTITYVISITORME

#include	"IEntityVisitor.h"

namespace Ngl{

/**
 * @class EntityVisitorMemFun2.
 * @brief 2引数関数ポインタ訪問者クラス．
 * @tparam Entity 訪問した要素.
 * @tparam First 引数1の型.
 * @tparam Second 引数2の型.
 * @tparam MemFun 訪問関数ポインタ( void 関数( 引数1, 引数2 ) ).
 */
template
<
	typename Entity,
	typename First,
	typename Second,
	typename void (Entity::*MenFun)( First, Second )
>
class EntityVisitorMemFun2 : public IEntityVisitor<Entity*>
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] first 引数１.
	 * @param[in] second 引数２.
	 */
	EntityVisitorMemFun2( First first , Second second ) :
		first_( first ),
		second_( second )
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
		( entity->*MemFun)( first_, second_ );
	}

private:

	/** 第一引数 */
	First first_;

	/** 第二引数 */
	Second second_;

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/