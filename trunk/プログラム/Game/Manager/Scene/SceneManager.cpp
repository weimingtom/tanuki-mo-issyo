/*******************************************************************************/
/*
 * @file SceneManager.cpp.
 * 
 * @brief シーンマネージャクラス定義.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/

/*===== インクルード ==========================================================*/
#include	"Manager/Scene/SceneManager.h"

/*=============================================================================*/
/**
 * @brief コンストラクタ.
 * 
 * @param[in] device ゲームデバイス.
 * @param[in] sceneID 初期シーン.
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
 * @brief デストラクタ.
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
 * @brief 初期化処理.
 * 
 */
void SceneManager::Initialize()
{

}

/*=============================================================================*/
/**
 * @brief 終了処理.
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
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool SceneManager::IsTerminated()
{
	return m_isTerminated;
}

/*=============================================================================*/
/**
 * @brief シーンの変更.
 * 
 * @param[in] sceneID 変更するシーン.
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
 * @brief シーンの呼び出し.
 * 
 * @param[in] sceneID 呼び出すシーン.
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
 * @brief シーンの描画処理.
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
 * @brief シーンの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
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