/*******************************************************************************/
/**
 * @file EntityEvaluatorMemFun1.h.
 * 
 * @brief 1�����֐��|�C���^�]���҃N���X��`.
 *
 * @date 2007/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ENTITYEVALUATORMEMFUN1_H_
#define _NGL_ENTITYEVALUATORMEMFUN1_H_

#include	"IEntityEvaluator.h"

namespace Ngl{

/**
 * @class EntityEvaluatorMemFun1.
 * @brief 1�����֐��|�C���^�]���҃N���X�D
 * @tparam Entity �]������v�f.
 * @tparam First �����̌^.
 * @tparam MemFun �]���֐��|�C���^( bool �֐�( ����1 ) const ).
 */
template
<
	typename Entity,
	typename First,
	typename bool(Entity::*MemFun)( First ) const
>
class EntityEvaluatorMemFun1 : public IEntityEvaluator<Entity*>
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] first ����.
	 */
	EntityEvaluatorMemFun1( First first ) :
	  first_( first )
	{}


	/*=========================================================================*/
	/**
	 * @brief �]������
	 * 
	 * @param[in] entity �]������v�f.
	 * @retval true ������.
	 * @retval false �ԈႢ.
	 */
	bool evaluate( Entity* entity )
	{
		return (entity->*MemFun)( first_ );
	}

private:

	/** ������ */
	First	first_;
};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/