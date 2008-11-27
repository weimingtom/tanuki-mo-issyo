/*******************************************************************************/
/**
 * @file EntityEvaluatorMemFun2.h.
 * 
 * @brief 2�����֐��|�C���^�]���҃N���X��`.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ENTITYEVALUATORMEMFUN2_H_
#define _NGL_ENTITYEVALUATORMEMFUN2_H_

#include	"IEntityEvaluator.h"

namespace Ngl{


/**
 * @class EntityEvaluatorMemFun2.
 * @brief 2�����֐��|�C���^�]���҃N���X�D
 * @tparam Entity �]������v�f.
 * @tparam First ����1�̌^.
 * @tparam Second ����2�̌^.
 * @tparam MemFun �]���֐��|�C���^( bool �֐�( ����1, ����2 ) const ).
 */
template<
	typename Entity,
	typename First,
	typename Second,
	typename bool(Entity::*MemFun)( First, Second ) const
>
class EntityEvaluatorMemFun2 : public IEntityEvaluator<Entity*>
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] first ����1.
	 * @param[in] second ����2.
	 */
	EntityEvaluatorMemFun2( First first, Second second ) :
	  first_( first ),
	  second_( second )
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
		return (entity->*MemFun)( first_, second_ );
	}

private:

	/** ������ */
	First	first_;

	/** ������ */
	Second	second_;
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/