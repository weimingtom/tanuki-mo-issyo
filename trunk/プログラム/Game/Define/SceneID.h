/*******************************************************************************/
/**
 * @file SceneID.h.
 * 
 * @brief シーンのID列挙型定義.
 *
 * @date 2008/11/27.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _SCENE_ID_H_
#define _SCENE_ID_H_


/**
 * @brief SceneID．
 */
enum SceneID
{
	/** シーンなし */
	SCENE_ID_NONE,
	/** ゲームシーン */
	SCENE_ID_GAME,
	/** タイトル */
	SCENE_ID_TITLE,
	/** キャラクタ選択シーン */
	SCENE_ID_CHARACTER_SELECT
};

#endif

/*===== EOF ===================================================================*/