/*******************************************************************************/
/*
 * @file ObjectManager.cpp.
 * 
 * @brief オブジェクト管理クラスの定義.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/

/*===== インクルード ==========================================================*/
#include	"Manager/Object/ObjectManager.h"
#include "Object/ObjectBase.h"


/*=============================================================================*/
/**
 * @brief コンストラクタ.
 *
 */
ObjectManager::ObjectManager(IGameDevice &device, Option &option) :
	m_device(device), m_option(option)
{
	m_objectFactory = new ObjectFactory(device, *this, option);
}

/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
ObjectManager::~ObjectManager()
{
	delete m_objectFactory;

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
 * @brief 初期化処理.
 *
 */
void ObjectManager::Initialize()
{

}

/*=============================================================================*/
/**
 * @brief 終了処理.
 *
 */
void ObjectManager::Terminate()
{
	m_isTerminated = true;
}

/*=============================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool ObjectManager::IsTerminated()
{
	return m_isTerminated;
}

/*=============================================================================*/
/**
 * @brief オブジェクトの追加.
 * 
 * @param[in] objectID 追加するオブジェクト.
 */
void ObjectManager::AddObject(ObjectBase* object)
{
	object->Initialize();
	m_object.push_back(object);
}

/*=============================================================================*/
/**
 * @brief オブジェクトの削除.
 * 
 * @param[in] object 削除するオブジェクト.
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
 * @brief オブジェクトの描画処理.
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
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
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

ObjectFactory& ObjectManager::GetObjectFactory()
{
	return *m_objectFactory;
}

/*===== EOF ===================================================================*/