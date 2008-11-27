/*******************************************************************************/
/**
 * @file EffectID.h.<br>
 * 
 * @brief エフェクトＩＤ定義ファイル.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _EFFECTID_H_
#define _EFFECTID_H_

/**
 * @brief エフェクトＩＤ列挙型
 */
enum EffectID
{
	EFFECTID_NONE		= 0,	/**< エフェクトなし			*/
	EFFECTID_COM_QUAD,			/**< 四角形ポリゴン			*/
	EFFECTID_COM_SPRITE,		/**< スプライト				*/
	EFFECTID_COM_PIXELLIGHTING,	/**< ピクセルライティング	*/
	EFFECTID_COM_SKIN			/**< スキンメッシュ			*/
};

#endif

/*========= End of File =====================================================*/