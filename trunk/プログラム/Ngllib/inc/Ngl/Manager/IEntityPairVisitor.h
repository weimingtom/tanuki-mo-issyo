/*******************************************************************************/
/**
 * @file IEntityPairVisitor.h.
 * 
 * @brief �y�A�K��҃C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IENTITYPAIRVISITOR_H_
#define _NGL_IENTITYPAIRVISITOR_H_

namespace Ngl{


/**
 * @interface IEntityPairVisitor.
 * @brief �y�A�K��҃C���^�[�t�F�[�X.
 * @tparam Entity �K�₷��v�f.
 */
template <class Entity>
class IEntityPairVisitor
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IEntityPairVisitor(){}


	/*=========================================================================*/
	/**
	 * @brief �K�₷��
	 * 
	 * @param[in] entity1 �K�₷��v�f����1.
	 * @param[in] entity2 �K�₷��v�f����2.
	 * @return �Ȃ�.
	 */
	virtual void visit( Entity entity1, Entity entity2 ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/