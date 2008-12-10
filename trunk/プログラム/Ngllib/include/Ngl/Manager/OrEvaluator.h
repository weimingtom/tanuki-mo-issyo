/*******************************************************************************/
/**
 * @file OrEvaluator.h.
 * 
 * @brief OR•]‰¿ÒƒNƒ‰ƒX’è‹`.
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
 * @brief Or•]‰¿ÒƒNƒ‰ƒX.
 * @tparam Entity —v‘f.
 * @tparam Evaluator •]‰¿Ò.  
 */
template
<
	class Entity,								// —v‘f
	class Evaluator = IEntityEvaluator<Entity>	// •]‰¿Ò
>
class OrEvaluator : public Evaluator
{
public:
	

	/*=========================================================================*/
	/**
	 * @brief ƒRƒ“ƒXƒgƒ‰ƒNƒ^
	 * 
	 * @param[in] first •]‰¿Ò‚»‚Ì1.
	 * @param[in] second •]‰¿Ò‚»‚Ì2.
	 */
	OrEvaluator( Evaluator& first, Evaluator& second ) :
		mFirst( first ),
		mSecond( second )
	{}

	
	/*=========================================================================*/
	/**
	 * @brief •]‰¿‚·‚é
	 * 
	 * @param[in] entity •]‰¿‚·‚é—v‘f.
	 * @retval true ³‚µ‚¢.
	 * @retval false ŠÔˆá‚¢.
	 */
	bool evaluate( Entity entity )
	{
		if( mFirst.evaluate( entity ) == true ){
			return true;
		}
		return false;
	}

private:

	/** •]‰¿Ò‚»‚Ì1 */
	Evaluator&	mFirst;

	/** •]‰¿Ò‚»‚Ì2 */
	Evaluator&	mSecond;
};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/