/*******************************************************************************/
/**
 * @file EntityVisitorMemFun3.h.
 * 
 * @brief 3�����֐��|�C���^�K��҃N���X��`.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nisimura.
 */
/******************************************************************************/
#ifndef _NGLENTITYVISITORMEMFUN3_H_
#define _NGLENTITYVISITORMEMFUN3_H_

#include	"IEntityVisitor.h"

namespace Ngl{


/**
 * @class EntityVisitorMemFun3.
 * @brief 3�����֐��|�C���^�K��҃N���X�D
 * @tparam Entity �K�₵���v�f.
 * @tparam First ����1�̌^.
 * @tparam Second ����2�̌^.
 * @tparam Third ����3�̌^.
 * @tparam MemFun �K��֐��|�C���^( void �֐�( ����1, ����2, ����3 ) ).
 */
template
<
	typename Entity,
	typename First,
	typename Second,
	typename Third,
	typename void (Entity::*MenFun)( First, Second, Third )
>
class EntityVisitorMemFun3 : public IEntityVisitor<Entity*>
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
	EntityVisitorMemFun3( First first, Second second, Third third ) :
		first_( first ),
		second_( second ),
		third_( third )
	{}

	
	/*=========================================================================*/
	/**
	 * @brief �K�₷��
	 * 
	 * @param[in] entity �v�f.
	 * @return �Ȃ�.
	 */
	void visit( Entity* entity )
	{
		( entity->*MemFun )( first_, second_, third_ );
	}

private:

	/** ������ */
	First first_;
	
	/** ������ */
	Second second_;

	/** ��O���� */
	Third third_;
};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/