/*******************************************************************************/
/**
 * @file PairAdapterVisitor.h.
 * 
 * @brief �y�A�K��ҕϊ��A�_�v�^�N���X��`.
 *
 * @date 2008/08/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_PAIRADAPTERVISITOR_H_
#define _NGL_PAIRADAPTERVISITOR_H_

#include	"IEntityPairVisitor.h"
#include	"IEntityVisitor.h"

namespace Ngl{


/**
 * @class PairAdapterVisitor.
 * @brief �y�A�K��ҕϊ��A�_�v�^�N���X.
 * @tparam Entity �v�f.
 * @tparam PairVisitor �y�A�K���.
 * @tparam Visitor �K���
 */
template
<
	class Entity,
	class PairVisitor	= IEntityPairVisitor< Entity >,
	class Visitor		= IEntityVisitor< Entity >
>
class PairAdapterVisitor : public Visitor
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] entity �K�₷��v�f.
	 * @param[in] pair �y�A�K���.
	 */
	PairAdapterVisitor( Entity entity, PairVisitor& pair ):
	  mEntity( entity ),
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
		mPairVisitor.visit( mEntity, entity );
	}

private:

	/** �v�f */
	Entity			mEntity;
	
	/** �y�A�K��҃N���X */
	PairVisitor&	mPairVisitor;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/