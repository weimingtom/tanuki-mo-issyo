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


/*=============================================================================*/
/**
 * @brief �R���X�g���N�^.
 *
 */
ObjectManager::ObjectManager() :
	m_objectFactory(0)
{

}

/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
ObjectManager::~ObjectManager()
{
	if(m_objectFactory)
	{
		delete m_objectFactory;
	}
	for(std::vector<ObjectBase*>::iterator i = m_object.begin(); i != m_object.end();)
	{
		if(!(*i)->IsTerminated())
		{
			(*i)->Terminate();
		}
		delete (*i);
		i = m_object.erase(i);
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
void ObjectManager::AddObject(int objectID)
{
	ObjectBase* object;
	object = m_objectFactory->CreateObject(objectID);
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
}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�t�@�N�g���̐ݒ�.
 * 
 * @param[in] objectFactory �ݒ肷��t�@�N�g��.
 */
void ObjectManager::SetFactory(ObjectFactoryBase *objectFactory)
{
	if(m_objectFactory)
	{
		delete m_objectFactory;
	}
	m_objectFactory = objectFactory;
}

/*===== EOF ===================================================================*/