/*******************************************************************************/
/**
 * @file MeshSkinDesc.h.<br>
 * 
 * @brief スキンメッシュ記述子構造体定義.<br>
 *
 * @date 2008/10/26.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _MESH_SKIN_DESC_H_
#define _MESH_SKIN_DESC_H_

#include	"MeshDesc.h"
#include	"Define/Define.h"

/**
 * @brief スキニングメッシュ記述子構造体．
 */
struct MeshSkinDesc
{
	/** メッシュ記述子 */
	MeshDesc		meshDesc;

	/** スケルトンファイル番号 */
	MeshID			skeletonID;

	/** アニメーションファイル番号 */
	MeshID			animationID;

	/** アニメーション番号 */
	unsigned int	animationNo;

	/** アニメーションタイマーの更新値 */
	float			animationTimer;

	/** アニメーション線形同士を補完するか */
	bool			isLerp;

	/** 補間要素のアニメーションファイル番号 */
	unsigned int	lerpAnimationID;

	/** 補間要素のアニメーション番号 */
	unsigned int	lerpAnimationNo;

	/** 補間要素のアニメーション更新値 */
	float			lerpAnimationTimer;

	/** 補間値(0.0f～1.0f) */
	float			lerpValue;

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ<br>
	 * 
	 * @param[in] なし.
	 */
	MeshSkinDesc():
		skeletonID( MESHID_NONE ),
		animationID( MESHID_NONE ),
		animationNo( 0 ),
		animationTimer( 0.0f ),
		isLerp( false ),
		lerpAnimationID( 0 ),
		lerpAnimationNo( 0 ),
		lerpAnimationTimer( 0.0f ),
		lerpValue( 0.0f )
	{
		meshDesc.techniqueName	=	"Skin";
		meshDesc.effectID		=	EFFECTID_COM_SKIN;
	}
};

#endif

/*===== EOF ==================================================================*/