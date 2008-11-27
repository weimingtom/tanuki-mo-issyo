/*******************************************************************************/
/**
 * @file OrEvaluator.h.
 * 
 * @brief OR�]���҃N���X��`.
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
 * @brief Or�]���҃N���X.
 * @tparam Entity �v�f.
 * @tparam Evaluator �]����.  
 */
template
<
	class Entity,								// �v�f
	class Evaluator = IEntityEvaluator<Entity>	// �]����
>
class OrEvaluator : public Evaluator
{
public:
	

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] first �]���҂���1.
	 * @param[in] second �]���҂���2.
	 */
	OrEvaluator( Evaluator& first, Evaluator& second ) :
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
			return true;
		}
		return false;
	}

private:

	/** �]���҂���1 */
	Evaluator&	mFirst;

	/** �]���҂���2 */
	Evaluator&	mSecond;
};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/