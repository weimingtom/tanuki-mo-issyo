/*******************************************************************************/
/**
 * @file IAnimation.h.
 * 
 * @brief アニメーションデータインターフェース定義.
 *
 * @date 2008/07/01.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IANIMATION_H_
#define _NGL_IANIMATION_H_

#include	"Ngl/KeyframeData.h"

namespace Ngl{


/**
 * @interface IAnimation.
 * @brief アニメーションデータインターフェース．
 */
class IAnimation
{
public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IAnimation() {}
	
	
	/*=========================================================================*/
	/**
	 * @brief 指定のキーフレームデータを取得する
	 * 
	 * @param[in] no 取得するデータ番号.
	 * @param[in] boneNo 取得するボーン番号.
	 * @param[in] globalTime 取得するキーのタイマ.
	 * @param[out] data キーフレームデータ.
	 * @return キーフレームデータ.
	 */
	virtual KeyframeData& getKeyFrame( unsigned int no, unsigned int boneNo, float globalTime, KeyframeData& data ) = 0;


	/*=========================================================================*/
	/**
	 * @brief アニメーションの終了タイマを調べる
	 * 
	 * @param[in] no アニメーションナンバー.
	 * @return 終了タイマ.
	 */
	virtual unsigned int getEndTimer( unsigned int no ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 指定のアニメーションのボーン数を調べる
	 * 
	 * @param[in] no データ番号.
	 * @return ボーン数.
	 */
	virtual unsigned int getNumBones( unsigned int no ) = 0;

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/