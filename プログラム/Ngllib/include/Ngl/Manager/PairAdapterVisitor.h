/*******************************************************************************/
/**
 * @file PairAdapterVisitor.h.
 * 
 * @brief ペア訪問者変換アダプタクラス定義.
 *
 * @date 2008/08/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_PAIRADAPTERVISITOR_H_
#define _NGL_PAIRADAPTERVISITOR_H_

#include	"IEntityPairVisitor.h"
#include	"IEntityVisitor.h"

namespace Ngl{


/**
 * @class PairAdapterVisitor.
 * @brief ペア訪問者変換アダプタクラス.
 * @tparam Entity 要素.
 * @tparam PairVisitor ペア訪問者.
 * @tparam Visitor 訪問者
 */
template
<
	class Entity,
	class PairVisitor	= IEntityPairVisitor< Entity >,
	class Visitor		= IEntityVisitor< Entity >
>
class PairAdapterVisitor : public Visitor
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] entity 訪問する要素.
	 * @param[in] pair ペア訪問者.
	 */
	PairAdapterVisitor( Entity entity, PairVisitor& pair ):
	  mEntity( entity ),
	  mPairVisitor( pair )
	  {}
	

	/*=========================================================================*/
	/**
	 * @brief 訪問する
	 * 
	 * @param[in] entity 訪問する要素.
	 * @return なし.
	 */
	void visit( Entity entity )
	{
		mPairVisitor.visit( mEntity, entity );
	}

private:

	/** 要素 */
	Entity			mEntity;
	
	/** ペア訪問者クラス */
	PairVisitor&	mPairVisitor;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/