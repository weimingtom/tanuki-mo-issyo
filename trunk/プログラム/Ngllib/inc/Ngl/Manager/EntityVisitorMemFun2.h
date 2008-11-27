/*******************************************************************************/
/**
 * @file EntityVisitorMemFun2.h.
 * 
 * @brief 2�����֐��|�C���^�K��҃N���X��`.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nisimura.
 */
/******************************************************************************/
#ifndef _NGLENTITYVISITORMEMFUN2_H_
#define _NGLENTITYVISITORME

#include	"IEntityVisitor.h"

namespace Ngl{

/**
 * @class EntityVisitorMemFun2.
 * @brief 2�����֐��|�C���^�K��҃N���X�D
 * @tparam Entity �K�₵���v�f.
 * @tparam First ����1�̌^.
 * @tparam Second ����2�̌^.
 * @tparam MemFun �K��֐��|�C���^( void �֐�( ����1, ����2 ) ).
 */
template
<
	typename Entity,
	typename First,
	typename Second,
	typename void (Entity::*MenFun)( First, Second )
>
class EntityVisitorMemFun2 : public IEntityVisitor<Entity*>
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] first �����P.
	 * @param[in] second �����Q.
	 */
	EntityVisitorMemFun2( First first , Second second ) :
		first_( first ),
		second_( second )
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
		( entity->*MemFun)( first_, second_ );
	}

private:

	/** ������ */
	First first_;

	/** ������ */
	Second second_;

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/