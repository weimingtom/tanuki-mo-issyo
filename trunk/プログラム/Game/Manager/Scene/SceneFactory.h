/*******************************************************************************/
/**
 * @file SceneFactory.h.
 * 
 * @brief シーンファクトリクラス.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _SCENE_FACTORY_H_
#define _SCENE_FACTORY_H_

/*===== インクルード ==========================================================*/
#include	"IGameDevice.h"
class		SceneManagerMediator;
class		SceneBase;
class		Option;

/**
 * @brief SceneFactory．
 */
class SceneFactory
{
public:
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ.
	 * 
	 * @param[in] device ゲームデバイス.
	 * @param[in] SceneManagerMediator シーンマネージャメディエータ.
	 * @param[in] Option オプション.
	 */
	SceneFactory(IGameDevice& device, SceneManagerMediator& sceneManagerMediator, Option& option);
	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~SceneFactory();

	/*=========================================================================*/
	/**
	 * @brief シーンの生成.
	 * 
	 * @param[in] sceneID 生成するシーン.
	 * @return 生成したシーン.
	 */
	SceneBase* CreateScene(int sceneID);

private:
	
	/** ゲームデバイス */
	IGameDevice& m_device;
	/** シーンマネージャメディエータ */
	SceneManagerMediator& m_sceneManagerMediator;
	/** ゲームオプション */
	Option& m_option;
};

#endif

/*===== EOF ===================================================================*/