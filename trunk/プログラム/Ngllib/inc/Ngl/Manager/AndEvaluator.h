/*******************************************************************************/
/**
 * @file AndEvaluator.h.
 * 
 * @brief AND�]���҃N���X��`.
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
 * @brief AND�]���҃N���X.
 * @tparam Entity �v�f.
 * @tparam Evaluator �]����.  
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
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] first �]���҂���1.
	 * @param[in] second �]���҂���2.
	 */
	AndEvaluator( Evaluator& first, Evaluator& second ) :
	  mFirst( first ),
	  mSecond( second )
	{}
	  

	/*=========================================================================*/
	/**
	 * @brief �]������
	 * 
	 * @param[in] entity �]������v�f.
	 * @retval true ������.
	 * @retval false �ԈႢ.
	 */
	bool evaluate( Entity entity )
	{
		if( mFirst.evaluate( entity ) == true ){
			return mSecond.evaluate( entity );
		}
		return false;
	}

private:

	/** �]���҂���1 */
	Evaluator&		mFirst;

	/** �]���҂���2 */
	Evaluator&		mSecond;
};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/