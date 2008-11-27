/*******************************************************************************/
/**
 * @file NotEvaluator.h.
 * 
 * @brief NOT�]���҃N���X��`.
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
 * @brief NOT�]���҃N���X.
 * @tparam Entity �v�f.
 * @tparam Evaluator �]����.  
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
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] evaluator �]����.
	 */
	NotEvaluator( Evaluator& evaluator ) :
		mEvaluator( evaluator )
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
		return !mEvaluator.evaluate( entity );		
	}


private:

	/** �]���� */
	Evaluator&	mEvaluator;
};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/