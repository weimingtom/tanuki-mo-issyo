/*******************************************************************************/
/**
 * @file EntityVisitorMemFun.h.
 * 
 * @brief �����Ȃ��֐��|�C���^�K��҃N���X��`.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ENTITYVISITORMEMFUN_H_
#define _NGL_ENTITYVISITORMEMFUN_H_

#include	"IEntityVisitor.h"

namespace Ngl{


/**
 * @class EntityVisitorMemFun.
 * @brief �����Ȃ��֐��|�C���^�K��҃N���X�D
 * @tparam Entity �K�₵���v�f.
 * @tparam MemFun �K��֐��|�C���^( void �֐�() ).
 */
template
<
	typename Entity,
	typename void (Entity::*MenFun)()
>
class EntityVisitorMemFun : public IEntityVisitor<Entity*>
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief �K�₷��
	 * 
	 * @param[in] entity �K�₵���v�f.
	 * @return �Ȃ�.
	 */
	void visit( Entity* entity )
	{
		(entity->*MemFun)();
	}

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/