/*******************************************************************************/
/**
 * @file EntityVisitorMemFun1.h.
 * 
 * @brief 1�����֐��|�C���^�K��҃N���X��`.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nisimura.
 */
/******************************************************************************/
#ifndef _NGL_ENTITYVISITORMEMFUN1_H_
#define _NGL_ENTITYVISITORMEMFUN1_H_

#include	"IEntityVisitor.h"

namespace Ngl{


/**
 * @class EntityVisitorMemFun1.
 * @brief 1�����֐��|�C���^�K��҃N���X�D
 * @tparam Entity �K�₵���v�f.
 * @tparam First ����1�̌^.
 * @tparam MemFun �K��֐��|�C���^( void �֐�( ����1 ) ).
 */
template
<
	typename Entity,
	typename First,
	typename void (Entity::*MemFun)(First)
>
class EntityVisitorMemFun1 : public IEntityVisitor<Entity*>
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] first ����.
	 */
	EntityVisitorMemFun1( First first ) :
		first_(first)
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
		(entity->*MemFun)( first_ );
	}

private:

	/** ������ */
	First first_;

};

}	// namespace Ngl

#endif 

/*===== EOF ==================================================================*/