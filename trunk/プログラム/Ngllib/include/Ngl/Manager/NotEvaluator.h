/*******************************************************************************/
/**
 * @file NotEvaluator.h.
 * 
 * @brief NOT]¿ÒNXè`.
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
 * @brief NOT]¿ÒNX.
 * @tparam Entity vf.
 * @tparam Evaluator ]¿Ò.  
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
	 * @brief RXgN^
	 * 
	 * @param[in] evaluator ]¿Ò.
	 */
	NotEvaluator( Evaluator& evaluator ) :
		mEvaluator( evaluator )
	{}

	
	/*=========================================================================*/
	/**
	 * @brief ]¿·é
	 * 
	 * @param[in] entity ]¿·évf.
	 * @retval true ³µ¢.
	 * @retval false Ôá¢.
	 */
	bool evaluate( Entity entity )
	{
		return !mEvaluator.evaluate( entity );		
	}


private:

	/** ]¿Ò */
	Evaluator&	mEvaluator;
};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/