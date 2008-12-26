/*******************************************************************************/
/*
 * @file ObjectManager.cpp.
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

/*===== �C���N���[�h ==========================================================*/
#include	"Manager/Object/ObjectManager.h"
#include "Object/ObjectBase.h"


/*=============================================================================*/
/**
 * @brief �R���X�g���N�^.
 *
 */
ObjectManager::ObjectManager(IGameDevice &device, Option &option) :
	m_device(device), m_option(option)
{
	m_objectFactory = new ObjectFactory(device, *this, option);
	m_effectFactory = new EffectFactory(device, *this, option);
}

/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
ObjectManager::~ObjectManager()
{
	delete m_objectFactory;
	delete m_effectFactory;

	for(std::vector<ObjectBase*>::iterator i = m_object.begin(); i != m_object.end();)
	{
		if(!(*i)->IsTerminated())
		{
			(*i)->Terminate();
		}
		delete (*i);
		i = m_object.erase(i);
	}
	
	for(std::vector<ObjectBase*>::iterator i = m_effect.begin(); i != m_effect.end();)
	{
		if(!(*i)->IsTerminated())
		{
			(*i)->Terminate();
		}
		delete (*i);
		i = m_effect.erase(i);
	}
}

/*=============================================================================*/
/**
 * @brief ����������.
 *
 */
void ObjectManager::Initialize()
{

}

/*=============================================================================*/
/**
 * @brief �I������.
 *
 */
void ObjectManager::Terminate()
{
	m_isTerminated = true;
}

/*=============================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool ObjectManager::IsTerminated()
{
	return m_isTerminated;
}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̒ǉ�.
 * 
 * @param[in] objectID �ǉ�����I�u�W�F�N�g.
 */
void ObjectManager::AddObject(ObjectBase* object)
{
	object->Initialize();
	m_object.push_back(object);
}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍폜.
 * 
 * @param[in] object �폜����I�u�W�F�N�g.
 */
void ObjectManager::DelObject(ObjectBase *object)
{
	for(std::vector<ObjectBase*>::iterator i = m_object.begin(); i != m_object.end();i++)
	{
		if((*i) == object)
		{
			if(!(*i)->IsTerminated())
			{
				(*i)->Terminate();
			}
			delete (*i);
			m_object.erase(i);
		}
	}
}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
 * 
 */
void ObjectManager::RenderObject()
{
	for(std::vector<ObjectBase*>::iterator i = m_object.begin(); i != m_object.end();i++)
	{
		(*i)->RenderObject();
	}
}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void ObjectManager::UpdateObject(float frameTimer)
{
/*
	for(std::vector<ObjectBase*>::iterator i = m_object.begin(); i != m_object.end();)
	{
		if(!(*i)->IsTerminated())
		{
			(*i)->UpdateObject(frameTimer);
		} else
		{
			delete (*i);
			i = m_object.erase(i);
			continue;
		}
		i++;
	}
*/

	for(unsigned int i = 0; i < m_object.size(); i++)
	{
		std::vector<ObjectBase*>::iterator j = m_object.begin() += i;

		if(!(*j)->IsTerminated())
		{
			(*j)->UpdateObject(frameTimer);
		} else
		{
			delete (*j);
			m_object.erase(j);
			i--;
		}
	}
}

/*=============================================================================*/
/**
 * @brief �G�t�F�N�g�̒ǉ�.
 * 
 * @param[in] objectID �ǉ�����I�u�W�F�N�g.
 */
void ObjectManager::AddEffect(ObjectBase* object)
{
	object->Initialize();
	m_effect.push_back(object);
}

/*=============================================================================*/
/**
 * @brief �G�t�F�N�g�̍폜.
 * 
 * @param[in] object �폜����I�u�W�F�N�g.
 */
void ObjectManager::DelEffect(ObjectBase *object)
{
	for(std::vector<ObjectBase*>::iterator i = m_effect.begin(); i != m_effect.end();i++)
	{
		if((*i) == object)
		{
			if(!(*i)->IsTerminated())
			{
				(*i)->Terminate();
			}
			delete (*i);
			m_effect.erase(i);
		}
	}
}

/*=============================================================================*/
/**
 * @brief �G�t�F�N�g�̕`�揈��.
 * 
 */
void ObjectManager::RenderEffect()
{
	for(std::vector<ObjectBase*>::iterator i = m_effect.begin(); i != m_effect.end();i++)
	{
		(*i)->RenderObject();
	}
}

/*=============================================================================*/
/**
 * @brief �G�t�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void ObjectManager::UpdateEffect(float frameTimer)
{

	for(unsigned int i = 0; i < m_effect.size(); i++)
	{
		std::vector<ObjectBase*>::iterator j = m_effect.begin() += i;

		if(!(*j)->IsTerminated())
		{
			(*j)->UpdateObject(frameTimer);
		} else
		{
			delete (*j);
			m_effect.erase(j);
			i--;
		}
	}
}

ObjectFactory& ObjectManager::GetObjectFactory()
{
	return *m_objectFactory;
}

EffectFactory& ObjectManager::GetEffectFactory()
{
	return *m_effectFactory;
}

/*===== EOF ===================================================================*/