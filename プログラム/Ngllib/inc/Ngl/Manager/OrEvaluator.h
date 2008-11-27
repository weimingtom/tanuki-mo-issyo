/*******************************************************************************/
/**
 * @file OrEvaluator.h.
 * 
 * @brief OR評価者クラス定義.
 *
 * @date 2008/08/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_OREVALUATOR_H_
#define _NGL_OREVALUATOR_H_

#include	"IEntityEvaluator.h"

namespace Ngl{


/**
 * @class OrEvaluator.
 * @brief Or評価者クラス.
 * @tparam Entity 要素.
 * @tparam Evaluator 評価者.  
 */
template
<
	class Entity,								// 要素
	class Evaluator = IEntityEvaluator<Entity>	// 評価者
>
class OrEvaluator : public Evaluator
{
public:
	

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] first 評価者その1.
	 * @param[in] second 評価者その2.
	 */
	OrEvaluator( Evaluator& first, Evaluator& second ) :
		mFirst( first ),
		mSecond( second )
	{}

	
	/*=========================================================================*/
	/**
	 * @brief 評価する
	 * 
	 * @param[in] entity 評価する要素.
	 * @retval true 正しい.
	 * @retval false 間違い.
	 */
	bool evaluate( Entity entity )
	{
		if( mFirst.evaluate( entity ) == true ){
			return true;
		}
		return false;
	}

private:

	/** 評価者その1 */
	Evaluator&	mFirst;

	/** 評価者その2 */
	Evaluator&	mSecond;
};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/