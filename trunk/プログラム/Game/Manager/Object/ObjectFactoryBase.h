/*******************************************************************************/
/**
 * @file ObjectFactoryBase.h.
 * 
 * @brief �I�u�W�F�N�g�������N���X�̒�`.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _OBJECT_FACTORY_BASE_H_
#define _OBJECT_FACTORY_BASE_H_

/*===== �C���N���[�h ==========================================================*/
class	ObjectBase;


/**
 * @brief ObjectFactoryBase�D
 */
class ObjectFactoryBase
{
public:

	/*=========================================================================*/
	/**
	 * @brief ���z�f�X�g���N�^.
	 */
	virtual ~ObjectFactoryBase(){}

	/*=========================================================================*/
	/**
	 * @brief �I�u�W�F�N�g�̐���.
	 * 
	 * @param[in] objectID ��������I�u�W�F�N�g��ID.
	 * @return ���������I�u�W�F�N�g�̃|�C���^.
	 */
	virtual ObjectBase* CreateObject(int objectID) = 0;

};

#endif

/*===== EOF ===================================================================*/