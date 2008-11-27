/*******************************************************************************/
/**
 * @file SceneManagerMediator.h.
 * 
 * @brief シーンマネージャ仲介クラス定義.
 *
 * @date 2008/11/27.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _SCENE_MANAGER_MEDIATOR_H_
#define _SCENE_MANAGER_MEDIATOR_H_

/*===== インクルード ==========================================================*/
class	SceneFactoryBase;


/**
 * @brief クラス名．
 */
class SceneManagerMediator
{
public:

	/*=========================================================================*/
	/**
	 * @brief 仮想デストラクタ.
	 *
	 */
	virtual ~SceneManagerMediator(){}
	
	/*=========================================================================*/
	/**
	 * @brief シーンの変更.
	 * 
	 * @param[in] sceneID 変更するシーン.
	 */
	virtual void ChangeScene(int sceneID) = 0;
	/*=========================================================================*/
	/**
	 * @brief シーンの呼び出し.
	 * 
	 * @param[in] sceneID 呼び出すシーン.
	 */
	virtual void CallScene(int sceneID) = 0;

};

#endif