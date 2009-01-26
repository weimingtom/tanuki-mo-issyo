/*******************************************************************************/
/*
 * @file SceneManager.cpp.
 * 
 * @brief �V�[���}�l�[�W���N���X��`.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/

/*===== �C���N���[�h ==========================================================*/
#include	"Manager/Scene/SceneManager.h"

/*=============================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 * @param[in] device �Q�[���f�o�C�X.
 * @param[in] sceneID �����V�[��.
 */
SceneManager::SceneManager(IGameDevice &device, int sceneID) :
	m_isTerminated(false), m_device(device)
{
	m_option.LoadSpriteInfo();

	m_sceneFactory = new SceneFactory(device, *this, m_option);
	
	m_stockScene.clear();
	m_currentScene = m_sceneFactory->CreateScene(sceneID);

}

/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
SceneManager::~SceneManager()
{
	delete m_sceneFactory;
	if(m_currentScene)
	{
		if(!m_currentScene->IsTerminated())
		{
			m_currentScene->Terminate();
		}
		delete m_currentScene;
	}
	for(std::vector<SceneBase*>::iterator i = m_stockScene.begin();i != m_stockScene.end();)
	{
		if(!(*i)->IsTerminated()){
			(*i)->Terminate();
		}
		delete (*i);
		i = m_stockScene.erase(i);
	}
}

/*=============================================================================*/
/**
 * @brief ����������.
 * 
 */
void SceneManager::Initialize()
{

}

/*=============================================================================*/
/**
 * @brief �I������.
 * 
 */
void SceneManager::Terminate()
{
	if(m_currentScene){
		if(!m_currentScene->IsTerminated()) {
			m_currentScene->Terminate();
		}
	}
	m_isTerminated = true;
}

/*=============================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool SceneManager::IsTerminated()
{
	return m_isTerminated;
}

/*=============================================================================*/
/**
 * @brief �V�[���̕ύX.
 * 
 * @param[in] sceneID �ύX����V�[��.
 */
void SceneManager::ChangeScene(int sceneID)
{
	if(m_currentScene)
	{
		if(!m_currentScene->IsTerminated())
		{
			m_currentScene->Terminate();
		}
		delete m_currentScene;
	}

	m_currentScene = m_sceneFactory->CreateScene(sceneID);
}

/*=============================================================================*/
/**
 * @brief �V�[���̌Ăяo��.
 * 
 * @param[in] sceneID �Ăяo���V�[��.
 */
void SceneManager::CallScene(int sceneID)
{
	if(m_currentScene)
	{
		m_stockScene.push_back(m_currentScene);
	}

	m_currentScene = m_sceneFactory->CreateScene(sceneID);
}

/*=============================================================================*/
/**
 * @brief �V�[���̕`�揈��.
 * 
 */
void SceneManager::RenderScene()
{
	if(m_currentScene)
	{
		m_currentScene->RenderScene();
	}
}

/*=============================================================================*/
/**
 * @brief �V�[���̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void SceneManager::UpdateScene(float frameTimer)
{
	if(m_currentScene)
	{
		if(!m_currentScene->IsTerminated())
		{
			m_currentScene->UpdateScene(frameTimer);
		} else
		{
			delete m_currentScene;
			if(m_stockScene.size() > 0)
			{
				m_currentScene = (*m_stockScene.begin());
				m_stockScene.erase(m_stockScene.begin());
			} else
			{
				Terminate();
			}
		}
	}
}

/*===== EOF ===================================================================*/