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

#include	"Manager/Object/ObjectFactory.h"
#include	"Manager/Object/EffectFactory.h"

/**
 * @brief ObjectManager�D
 */
class ObjectManager
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^.
	 *
	 */
	ObjectManager(IGameDevice &device, Option &option);
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
	void AddObject(ObjectBase* object);
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

	ObjectFactory& GetObjectFactory();
	EffectFactory& GetEffectFactory();

	void AddEffect(ObjectBase* object);
	void DelEffect(ObjectBase* object);
	void RenderEffect();
	void UpdateEffect(float frameTimer);

private:

	/** �I�u�W�F�N�g�t�@�N�g�� */
	ObjectFactory* m_objectFactory;
	EffectFactory* m_effectFactory;
	/** �I�u�W�F�N�g���X�g */
	std::vector<ObjectBase*> m_object;
	/** �G�t�F�N�g���X�g */
	std::vector<ObjectBase*> m_effect;
	/** �I���t���O */
	bool m_isTerminated;
	
	/** �Q�[���f�o�C�X */
	IGameDevice& m_device;
	/** �Q�[���I�v�V���� */
	Option& m_option;
	

};

#endif

/*===== EOF ===================================================================*/