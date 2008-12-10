/*******************************************************************************/
/**
 * @file PairManagerVisitor.h.
 * 
 * @brief ペアマネージャー訪問者クラス定義.
 *
 * @date 2008/08/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_PAIRMANAGERVISITOR_H_
#define _NGL_PAIRMANAGERVISITOR_H_

#include	"EntityManager.h"
#include	"IEntityPairVisitor.h"
#include	"IEntityVisitor.h"
#include	"PairAdapterVisitor.h"

namespace Ngl{


/**
 * @class PairManagerVisitor
 * @brief ペアマネージャー訪問者クラス.
 * @tparam Entity 要素.
 * @tparam Manager 管理者.
 * @tparam PairVisitor ペア訪問者.
 * @tparam Visitor 訪問者.
 */
template
<
	class Entity,
	class Manager		= EntityManager< Entity >,
	class PairVisitor	= IEntityPairVisitor< Entity >,
	class Visitor		= IEntityVisitor< Entity >
>
class PairManagerVisitor : public Visitor
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] manager マネージャー.
	 * @param[in] pair ペア訪問者.
	 */
	PairManagerVisitor( Manager& manager, PairVisitor& pair ) :
	  mManager( manager ),
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
		// ペア訪問者を変換する
		PairAdapterVisitor< Entity, PairVisitor, Visitor > visitor( entity, mPairVisitor );
		mManager.accept( visitor );
	}

private:

	/** マネージャー */
	Manager&		mManager;

	/** ペア訪問者 */
	PairVisitor&	mPairVisitor;
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/