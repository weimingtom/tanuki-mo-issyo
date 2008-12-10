/*******************************************************************************/
/**
 * @file NoDestroy.h.
 * 
 * @brief ��폜�|���V�[�N���X��`.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_NODESTROY_H_
#define _NGL_NODESTROY_H_

namespace Ngl{


/**
 * @class NoDestroy.
 * @brief ��폜�|���V�[�N���X.
 */
class NoDestroy
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief �폜���Ȃ�
	 * 
	 * @tparam Entity �폜����v�f�����N���X.( *���Z�q�I�[�o�[���[�h������ )
	 * @param[in] instance �폜���Ȃ��v�f.
	 * @return �Ȃ�.
	 */
	template<class Entity>
	static void destroy( Entity instance ){}
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/