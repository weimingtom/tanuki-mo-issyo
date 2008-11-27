/*******************************************************************************/
/**
 * @file IKeyframe.h.
 * 
 * @brief アニメーションキーフレームインターフェース定義.
 *
 * @date 2008/07/01.
 * 
 * @version 1.00.
 * 
 * @author Kentaru Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IKEYFRAME_H_
#define _NGL_IKEYFRAME_H_

#include	"Ngl/KeyframeData.h"

namespace Ngl{


/**
 * @interface IKeyframe.
 * @brief アニメーションキーフレームインターフェース．
 */
class IKeyframe
{	

public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IKeyframe() {}
	
	
	/*=========================================================================*/
	/**
	 * @brief キーフレームデータの取得
	 * 
	 * @param[in] globalTime 取得するキーのタイマ.
	 * @param[out] data キーフレームデータ.
	 * @return キーフレームデータ.
	 */
	virtual KeyframeData& getKey( float globalTime, KeyframeData& data ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 指定の拡大縮小キーのフレームタイムを取得する
	 * 
	 * @param[in] no 拡大縮小キー番号.
	 * @return フレームタイマ.
	 */
	virtual unsigned int getScaleKeyFrameTime( unsigned int no ) const = 0;


	/*=========================================================================*/
	/**
	 * @brief 指定の回転キーのフレームタイムを取得する
	 * 
	 * @param[in] no 回転キー番号.
	 * @return フレームタイマ.
	 */
	virtual unsigned int getRotateKeyFrameTime( unsigned int no ) const = 0;


	/*=========================================================================*/
	/**
	 * @brief 指定の平行移動キーのフレームタイムを取得する
	 * 
	 * @param[in] no 平行移動キー番号.
	 * @return フレームタイマ.
	 */
	virtual unsigned int getPositionKeyFrameTime( unsigned int no ) const = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 拡大縮小キー数を取得する
	 * 
	 * @param[in] なし.
	 * @return 拡大縮小キー数.
	 */
	virtual unsigned int getNumScaleKeys() const = 0;


	/*=========================================================================*/
	/**
	 * @brief 回転キー数を取得する
	 * 
	 * @param[in] なし.
	 * @return 回転キー数.
	 */
	virtual unsigned int getNumRotateKeys() const = 0;
	

	/*=========================================================================*/
	/**
	 * @brief 平行移動キー数を取得する
	 * 
	 * @param[in] なし.
	 * @return 平行移動キー数.
	 */
	virtual unsigned int getNumPositionKeys() const = 0;

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/