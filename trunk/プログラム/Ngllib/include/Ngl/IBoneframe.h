/*******************************************************************************/
/**
 * @file IBoneframe.h.
 * 
 * @brief アニメーションボーンフレームデータインターフェース定義.
 *
 * @date 2008/07/01.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IBONEFRAME_H_
#define _NGL_IBONEFRAME_H_

#include	"KeyframeData.h"

namespace Ngl{


/**
 * @interface IBoneframe.
 * @brief アニメーションボーンフレームデータインターフェース．
 */
class IBoneframe
{

public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IBoneframe() {}
	
	
	/*=========================================================================*/
	/**
	 * @brief 指定番号のキーフレームを取得する
	 * 
	 * @param[in] boneNo 取得するボーンID.
	 * @param[in] globalTime 取得するキーのタイマ.
	 * @param[out] data キーフレーム情報.
	 * @return キーフレーム情報.
	 */
	virtual KeyframeData& getKeyframe( unsigned int boneNo, float globalTime, KeyframeData& data ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 指定のキーフレームの拡大縮小キー数を取得する
	 * 
	 * @param[in] no 取得するキーフレーム番号.
	 * @return 拡大縮小キー数.
	 */
	virtual unsigned int getNumScaleKeys( unsigned int no ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 指定のキーフレームの回転キー数を取得する
	 * 
	 * @param[in] no 取得するキーフレーム番号.
	 * @return 回転キー数.
	 */
	virtual unsigned int getNumRotateKeys( unsigned int no ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 指定のキーフレームの平行移動キー数を取得する
	 * 
	 * @param[in] no 取得するキーフレーム番号.
	 * @return 平行移動キー数.
	 */
	virtual unsigned int getNumPositionKeys( unsigned int no ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 指定のキーフレームの拡大縮小キーからフレームタイムを取得する
	 * 
	 * @param[in] frameNo 取得するキーフレーム番号.
	 * @param[in] keyNo キー番号.
	 * @return フレームタイム.
	 */
	virtual unsigned int getScaleKeyFrameTime( unsigned int frameNo, unsigned int keyNo  ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 指定のキーフレームの回転キーからフレームタイムを取得する
	 * 
	 * @param[in] frameNo 取得するキーフレーム番号.
	 * @param[in] keyNo キー番号.
	 * @return フレームタイム.
	 */
	virtual unsigned int getRotateKeyFrameTime( unsigned int frameNo, unsigned int keyNo ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 指定のキーフレームの平行移動キーからフレームタイムを取得する
	 * 
	 * @param[in] frameNo 取得するキーフレーム番号.
	 * @param[in] keyNo キー番号.
	 * @return フレームタイム.
	 */
	virtual unsigned int getPositionKeyFrameTime( unsigned int frameNo, unsigned int keyNo ) = 0;


	/*=========================================================================*/
	/**
	 * @brief キーフレーム数を取得する
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual unsigned int getNumKeyframes() const = 0;

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/