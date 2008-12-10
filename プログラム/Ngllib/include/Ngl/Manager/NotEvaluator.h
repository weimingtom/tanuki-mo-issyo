/*******************************************************************************/
/**
 * @file NotEvaluator.h.
 * 
 * @brief NOT評価者クラス定義.
 *
 * @date 2008/08/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_NOTEVALUATOR_H_
#define _NGL_NOTEVALUATOR_H_

#include	"IEntityEvaluator.h"

namespace Ngl{


/**
 * @class NotEvaluator.
 * @brief NOT評価者クラス.
 * @tparam Entity 要素.
 * @tparam Evaluator 評価者.  
 */
template 
<
	class Entity,
	class Evaluator = IEntityEvaluator<Entity>
>
class NotEvaluator : public Evaluator
{
public:
	

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] evaluator 評価者.
	 */
	NotEvaluator( Evaluator& evaluator ) :
		mEvaluator( evaluator )
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
		return !mEvaluator.evaluate( entity );		
	}


private:

	/** 評価者 */
	Evaluator&	mEvaluator;
};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/