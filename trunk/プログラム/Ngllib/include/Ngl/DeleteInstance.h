/*******************************************************************************/
/**
 * @file DeleteInstance.h.
 * 
 * @brief �폜�֐��I�u�W�F�N�g�N���X��`.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DELETE_INSTANCE_H_
#define _NGL_DELETE_INSTANCE_H_

namespace Ngl{


/**
 * @class DeleteInstance.
 * @brief �ėp�폜�֐��I�u�W�F�N�g�N���X.
 */
class DeleteInstance
{

public:

	/*=========================================================================*/
	/**
	 * @brief  �֐��Ăяo�� ()���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] instance �폜����C���X�^���X.
	 * @return true �폜����.
	 */
	template <class T>						
	bool operator () ( const T* instance )
	{
		delete instance;

		return true;
	}
};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/