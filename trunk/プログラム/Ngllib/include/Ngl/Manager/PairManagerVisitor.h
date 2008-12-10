/*******************************************************************************/
/**
 * @file PairManagerVisitor.h.
 * 
 * @brief �y�A�}�l�[�W���[�K��҃N���X��`.
 *
 * @date 2008/08/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_PAIRMANAGERVISITOR_H_
#define _NGL_PAIRMANAGERVISITOR_H_

#include	"EntityManager.h"
#include	"IEntityPairVisitor.h"
#include	"IEntityVisitor.h"
#include	"PairAdapterVisitor.h"

namespace Ngl{


/**
 * @class PairManagerVisitor
 * @brief �y�A�}�l�[�W���[�K��҃N���X.
 * @tparam Entity �v�f.
 * @tparam Manager �Ǘ���.
 * @tparam PairVisitor �y�A�K���.
 * @tparam Visitor �K���.
 */
template
<
	class Entity,
	class Manager		= EntityManager< Entity >,
	class PairVisitor	= IEntityPairVisitor< Entity >,
	class Visitor		= IEntityVisitor< Entity >
>
class PairManagerVisitor : public Visitor
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] manager �}�l�[�W���[.
	 * @param[in] pair �y�A�K���.
	 */
	PairManagerVisitor( Manager& manager, PairVisitor& pair ) :
	  mManager( manager ),
	  mPairVisitor( pair )
	{}


	/*=========================================================================*/
	/**
	 * @brief �K�₷��
	 * 
	 * @param[in] entity �K�₷��v�f.
	 * @return �Ȃ�.
	 */
	void visit( Entity entity )
	{
		// �y�A�K��҂�ϊ�����
		PairAdapterVisitor< Entity, PairVisitor, Visitor > visitor( entity, mPairVisitor );
		mManager.accept( visitor );
	}

private:

	/** �}�l�[�W���[ */
	Manager&		mManager;

	/** �y�A�K��� */
	PairVisitor&	mPairVisitor;
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/