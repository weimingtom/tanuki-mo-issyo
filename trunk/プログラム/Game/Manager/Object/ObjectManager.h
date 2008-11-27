/*******************************************************************************/
/**
 * @file ObjectManager.h.
 * 
 * @brief �I�u�W�F�N�g�Ǘ��N���X�̒�`.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _OBJECT_MANAGER_H_
#define _OBJECT_MANAGER_H_

/*===== �C���N���[�h ==========================================================*/
#include	<vector>
#include	"Manager/Object/ObjectManagerMediator.h"
#include	"Manager/Object/ObjectFactoryBase.h"


/**
 * @brief ObjectManager�D
 */
class ObjectManager : public ObjectManagerMediator
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^.
	 *
	 */
	ObjectManager();
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 *
	 */
	~ObjectManager();

	/*=========================================================================*/
	/**
	 * @brief ����������.
	 * 
	 */
	void Initialize();
	/*=========================================================================*/
	/**
	 * @brief �I������.
	 * 
	 */
	void Terminate();
	/*=========================================================================*/
	/**
	 * @brief �I�����Ă��邩�ǂ���.
	 * 
	 * @return �I���t���O.
	 */
	bool IsTerminated();

	/*=========================================================================*/
	/**
	 * @brief �I�u�W�F�N�g�̒ǉ�.
	 * 
	 * @param[in] objectID �ǉ�����I�u�W�F�N�g.
	 */
	void AddObject(int objectID);
	/*=========================================================================*/
	/**
	 * @brief �I�u�W�F�N�g�̍폜.
	 * 
	 * @param[in] object �폜����I�u�W�F�N�g.
	 */
	void DelObject(ObjectBase* object);
	/*=========================================================================*/
	/**
	 * @brief �I�u�W�F�N�g�̕`�揈��.
	 * 
	 */
	void RenderObject();
	/*=========================================================================*/
	/**
	 * @brief �I�u�W�F�N�g�̍X�V����.
	 * 
	 * @param[in] frameTimer �X�V�^�C�}.
	 */
	void UpdateObject(float frameTimer);

	/*=========================================================================*/
	/**
	 * @brief �I�u�W�F�N�g�t�@�N�g���̐ݒ�.
	 * 
	 * @param[in] objectFactory �ݒ肷��t�@�N�g��.
	 */
	void SetFactory(ObjectFactoryBase* objectFactory);

private:

	/** �I�u�W�F�N�g�t�@�N�g�� */
	ObjectFactoryBase* m_objectFactory;
	/** �I�u�W�F�N�g���X�g */
	std::vector<ObjectBase*> m_object;
	/** �I���t���O */
	bool m_isTerminated;

};

#endif

/*===== EOF ===================================================================*/