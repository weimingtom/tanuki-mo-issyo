/*******************************************************************************/
/**
 * @file EntityEvaluatorMemFun3.h.
 * 
 * @brief 3�����֐��|�C���^�]���҃N���X��`.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ENTITYEVALUATORMEMFUN3_H_
#define _NGL_ENTITYEVALUATORMEMFUN3_H_

#include	"IEntityEvaluator.h"

namespace Ngl{


/**
 * @class EntityEvaluatorMemFun3.
 * @brief 3�����֐��|�C���^�]���҃N���X�D
 * @tparam Entity �]������v�f.
 * @tparam First ����1�̌^.
 * @tparam Second ����2�̌^.
 * @tparam Third ����3�̌^.
 * @tparam MemFun �]���֐��|�C���^( bool �֐�( ����1, ����2, ����3 ) const ).
 */
template<
	typename Entity,
	typename First,
	typename Second,
	typename Third,
	typename bool(Entity::*MemFun)( First, Second, Third ) const
>
class EntityEvaluatorMemFun3 : public IEntityEvaluator<Entity*>
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] first �����P.
	 * @param[in] second �����Q.
	 * @param[in] third �����R.
	 */
	EntityEvaluatorMemFun3( First first, Second second , Third third ) :
	  first_( first ),
	  second_( second ),
	  third_( third )
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
		return (entity->*MemFun)( first_, second_ , third_ );
	}

private:

	/** ������ */
	First	first_;

	/** ������ */
	Second	second_;

	/** ��O���� */
	Third third_;
};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/