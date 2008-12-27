/*******************************************************************************/
/**
 * @file CharacterSelectSceneState.h.
 * 
 * @brief ゲームセレクトシーン状態クラス定義.
 *
 * @date 2008/12/27.
 *
 * @version 1.00.
 *
 * @author Ryoma Kawasue.
 */
/*******************************************************************************/
#ifndef _CHARACTER_SELECT_SCENE_STATE_H_
#define _CHARACTER_SELECT_SCENE_STATE_H_

/*===== インクルード ==========================================================*/
#include	<vector>
#include	"Manager/Object/ObjectManager.h"


/**
 * @brief CharacterSelectSceneState．
 */
class CharacterSelectSceneState
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ.
	 * 
	 */
	CharacterSelectSceneState(ObjectManager& objectManager);
	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~CharacterSelectSceneState();

private:

	/** オブジェクトマネージャ */
	ObjectManager& m_objectManager;

};

#endif

/*===== EOF ===================================================================*/