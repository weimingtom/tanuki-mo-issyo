/*******************************************************************************/
/**
 * @file EntityEvaluatorMemFun.h.
 * 
 * @brief �����Ȃ��֐��|�C���^�]���҃N���X��`.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimrua.
 */
/******************************************************************************/
#ifndef _NGL_ENTITYEVALUATORMEMFUN_H_
#define _NGL_ENTITYEVALUATORMEMFUN_H_

#include	"IEntityEvaluator.h"

namespace Ngl{


/**
 * @class EntityEvaluatorMemFun.
 * @brief �����Ȃ��֐��|�C���^�]���҃N���X�D
 * @tparam Entity �]������v�f.
 * @tparam MemFun �]���֐��|�C���^( bool �֐�() const ).
 */
template<
	typename Entity,
	typename bool(Entity::*MemFun)() const
>
class EntityEvaluatorMemFun : public IEntityEvaluator<Entity*>
{
public:
	
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
		return (entity->*MemFun)();
	}
};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/