/*******************************************************************************/
/**
 * @file TitleSceneState.h.
 * 
 * @brief タイトルシーン状態クラス定義.
 *
 * @date 2008/12/27.
 *
 * @version 1.00.
 *
 * @author Jun Futagawa.
 */
/*******************************************************************************/
#ifndef _TITLE_SCENE_STATE_H_
#define _TITLE_SCENE_STATE_H_

/*===== インクルード ==========================================================*/
#include	<vector>
class		Player;
#include	"Manager/Object/ObjectManager.h"


/**
 * @brief TitleSceneState．
 */
class TitleSceneState
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ.
	 * 
	 */
	TitleSceneState(ObjectManager& objectManager);
	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~TitleSceneState();




private:

	/** オブジェクトマネージャ */
	ObjectManager& m_objectManager;


	/** ゲームステート */
	int m_titleState;
};

#endif

/*===== EOF ===================================================================*/