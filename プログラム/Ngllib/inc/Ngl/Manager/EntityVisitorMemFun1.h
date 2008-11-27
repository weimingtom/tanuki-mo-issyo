/*******************************************************************************/
/**
 * @file EntityVisitorMemFun1.h.
 * 
 * @brief 1引数関数ポインタ訪問者クラス定義.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nisimura.
 */
/******************************************************************************/
#ifndef _NGL_ENTITYVISITORMEMFUN1_H_
#define _NGL_ENTITYVISITORMEMFUN1_H_

#include	"IEntityVisitor.h"

namespace Ngl{


/**
 * @class EntityVisitorMemFun1.
 * @brief 1引数関数ポインタ訪問者クラス．
 * @tparam Entity 訪問した要素.
 * @tparam First 引数1の型.
 * @tparam MemFun 訪問関数ポインタ( void 関数( 引数1 ) ).
 */
template
<
	typename Entity,
	typename First,
	typename void (Entity::*MemFun)(First)
>
class EntityVisitorMemFun1 : public IEntityVisitor<Entity*>
{
public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] first 引数.
	 */
	EntityVisitorMemFun1( First first ) :
		first_(first)
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
		(entity->*MemFun)( first_ );
	}

private:

	/** 第一引数 */
	First first_;

};

}	// namespace Ngl

#endif 

/*===== EOF ==================================================================*/