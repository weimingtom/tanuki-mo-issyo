/*******************************************************************************/
/**
 * @file AndEvaluator.h.
 * 
 * @brief AND•]‰¿ÒƒNƒ‰ƒX’è‹`.
 *
 * @date 2008/08/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ANDEVALUATOR_H_
#define _NGL_ANDEVALUATOR_H_

#include	"IEntityEvaluator.h"


namespace Ngl{

/**
 * @class AndEvaluator.
 * @brief AND•]‰¿ÒƒNƒ‰ƒX.
 * @tparam Entity —v‘f.
 * @tparam Evaluator •]‰¿Ò.  
 */
template
<
	class Entity,
	class Evaluator	= IEntityEvaluator< Entity >
>
class AndEvaluator : public Evaluator
{
public:
	

	/*=========================================================================*/
	/**
	 * @brief ƒRƒ“ƒXƒgƒ‰ƒNƒ^
	 * 
	 * @param[in] first •]‰¿Ò‚»‚Ì1.
	 * @param[in] second •]‰¿Ò‚»‚Ì2.
	 */
	AndEvaluator( Evaluator& first, Evaluator& second ) :
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
			return mSecond.evaluate( entity );
		}
		return false;
	}

private:

	/** •]‰¿Ò‚»‚Ì1 */
	Evaluator&		mFirst;

	/** •]‰¿Ò‚»‚Ì2 */
	Evaluator&		mSecond;
};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/