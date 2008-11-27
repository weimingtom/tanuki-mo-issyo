/*******************************************************************************/
/**
 * @file ObjectManagerMediator.h.
 * 
 * @brief �I�u�W�F�N�g�Ǘ��Ғ���N���X�̒�`.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _OBJECT_MANAGER_MEDIATOR_H_
#define _OBJECT_MANAGER_MEDIATOR_H_

/*===== �C���N���[�h ==========================================================*/
#include	"Object/ObjectBase.h"


/**
 * @brief ObjectManagerMediator�D
 */
class ObjectManagerMediator
{
public:

	/*=========================================================================*/
	/**
	 * @brief ���z�f�X�g���N�^.
	 *
	 */
	virtual ~ObjectManagerMediator(){}

	/*=========================================================================*/
	/**
	 * @brief �I�u�W�F�N�g�̒ǉ�.
	 * 
	 * @param[in] objectID �ǉ�����I�u�W�F�N�g.
	 */
	virtual void AddObject(int objectID) = 0;
	/*=========================================================================*/
	/**
	 * @brief �I�u�W�F�N�g�̍폜.
	 * 
	 * @param[in] object �폜����I�u�W�F�N�g.
	 */
	virtual void DelObject(ObjectBase* object) = 0;

};

#endif

/*===== EOF ===================================================================*/