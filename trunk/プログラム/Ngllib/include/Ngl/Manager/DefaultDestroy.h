/*******************************************************************************/
/**
 * @file DefaultDestroy.h.
 * 
 * @brief �폜�|���V�[�N���X��`.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DEFAULTDESTROY_H_
#define _NGL_DEFAULTDESTROY_H_

namespace Ngl{


/**
 * @class DefaultDestroy.
 * @brief �폜�|���V�[�N���X
 */
class DefaultDestroy
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief �폜����
	 * 
	 * @tparam Entity �폜����v�f�����N���X.( *���Z�q�I�[�o�[���[�h������ )
	 * @param[in] instance �폜����v�f.
	 * @return �Ȃ�.
	 */
	template <class Entity>
	static void destroy( Entity instance )
	{
		delete instance;
	}

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/