/*******************************************************************************/
/**
 * @file IEntityEvaluator.h.
 * 
 * @brief �]���C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IENTITYEVALUATOR_H_
#define _NGL_IENTITYEVALUATOR_H_

namespace Ngl{


/**
 * @interface IEntityEvaluator.
 * @brief �]���҃C���^�[�t�F�[�X�D
 * @tparam Entity �]������v�f.
 */
template <class Entity>
class IEntityEvaluator
{
public:
	

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IEntityEvaluator(){}
	
	
	/*=========================================================================*/
	/**
	 * @brief �]������
	 * 
	 * @param[in] entity �]������v�f.
	 * @return �Ȃ�.
	 */
	virtual bool evaluate( Entity entity ) = 0;
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/