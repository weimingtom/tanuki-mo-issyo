/*******************************************************************************/
/**
 * @file IEntityVisitor.h.
 * 
 * @brief �K��҃C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IENTITYVISITOR_H_
#define _NGL_IENTITYVISITOR_H_

namespace Ngl{


/**
 * @interface IEntityVisitor.
 * @brief �K��҃C���^�[�t�F�[�X.
 * @tparam Entity �K�₷��v�f.
 */
template <class Entity>
class IEntityVisitor
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IEntityVisitor(){}


	/*=========================================================================*/
	/**
	 * @brief �K�₷��
	 * 
	 * @param[in] entity �v�f.
	 * @return �Ȃ�.
	 */
	virtual void visit( Entity entity ) = 0;
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/