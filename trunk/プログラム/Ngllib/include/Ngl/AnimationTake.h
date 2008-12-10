/*******************************************************************************/
/**
 * @file AnimationTake.h.
 * 
 * @brief アニメーションテイクデータクラスヘッダファイル.
 *
 * @date 2008/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ANIMATIONTAKE_H_
#define _NGL_ANIMATIONTAKE_H_

#include	"Ngl/IBoneframe.h"
#include	"Ngl/IKeyframe.h"
#include	<vector>

namespace Ngl{


/**
 * @class AnimationTake.
 * @brief アニメーションテイクデータクラス．
 */
class AnimationTake : public IBoneframe
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	AnimationTake();


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~AnimationTake();


	/*=========================================================================*/
	/**
	 * @brief キーフレームを追加する
	 * 
	 * @warning 追加したキーフレームはAnimatinTakeクラスで削除されます.
	 *
	 * @param[in] keyframe 追加するキーフレーム.
	 * @return なし.
	 */
	void addKeyFrame( IKeyframe* keyframe );

public:
	
	/*=========================================================================*/
	/**
	 * @brief 指定番号のキーフレームを取得する
	 * 
	 * @param[in] boneNo 取得するボーンID.
	 * @param[in] globalTime 取得するキーのタイマ.
	 * @param[out] data キーフレーム情報.
	 * @return キーフレーム情報.
	 */
	virtual KeyframeData& getKeyframe( unsigned int boneNo, float globalTime, KeyframeData& data );
	
	
	/*=========================================================================*/
	/**
	 * @brief 指定のキーフレームの拡大縮小キー数を取得する
	 * 
	 * @param[in] no 取得するキーフレーム番号.
	 * @return 拡大縮小キー数.
	 */
	virtual unsigned int getNumScaleKeys( unsigned int no );


	/*=========================================================================*/
	/**
	 * @brief 指定のキーフレームの回転キー数を取得する
	 * 
	 * @param[in] no 取得するキーフレーム番号.
	 * @return 回転キー数.
	 */
	virtual unsigned int getNumRotateKeys( unsigned int no );


	/*=========================================================================*/
	/**
	 * @brief 指定のキーフレームの平行移動キー数を取得する
	 * 
	 * @param[in] no 取得するキーフレーム番号.
	 * @return 平行移動キー数.
	 */
	virtual unsigned int getNumPositionKeys( unsigned int no );


	/*=========================================================================*/
	/**
	 * @brief 指定のキーフレームの拡大縮小キーからフレームタイムを取得する
	 * 
	 * @param[in] frameNo 取得するキーフレーム番号.
	 * @param[in] keyNo キー番号.
	 * @return フレームタイム.
	 */
	virtual unsigned int getScaleKeyFrameTime( unsigned int frameNo, unsigned int keyNo  );
	
	
	/*=========================================================================*/
	/**
	 * @brief 指定のキーフレームの回転キーからフレームタイムを取得する
	 * 
	 * @param[in] frameNo 取得するキーフレーム番号.
	 * @param[in] keyNo キー番号.
	 * @return フレームタイム.
	 */
	virtual unsigned int getRotateKeyFrameTime( unsigned int frameNo, unsigned int keyNo );


	/*=========================================================================*/
	/**
	 * @brief 指定のキーフレームの平行移動キーからフレームタイムを取得する
	 * 
	 * @param[in] frameNo 取得するキーフレーム番号.
	 * @param[in] keyNo キー番号.
	 * @return フレームタイム.
	 */
	virtual unsigned int getPositionKeyFrameTime( unsigned int frameNo, unsigned int keyNo );


	/*=========================================================================*/
	/**
	 * @brief キーフレーム数を取得する
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual unsigned int getNumKeyframes() const;

private:
	
	/*=========================================================================*/
	/**
	 * @brief ボーンフレームを解放する
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void release();


	/*=========================================================================*/
	/**
	 * @brief 指定の番号がデータ数を超えているか
	 * 
	 * @param[in] no 番号.
	 * @retval true 超えている.
	 * @retval false 超えていない.
	 */
	bool isOutOfRange( unsigned int no );

private:

	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ(コピー禁止)
	 * 
	 * @param[in] other コピーするオブジェクト.
	 * @return なし.
	 */
	AnimationTake( const AnimationTake& other );


	/*=========================================================================*/
	/**
	 * @brief = 演算子オーバーロード(コピー禁止)
	 * 
	 * @param[in] other 代入するするオブジェクト.
	 * @return 代入結果のオブジェクト.
	 */
	AnimationTake& operator = ( const AnimationTake& other );

private:

	/** キーフレーム配列型 */
	typedef std::vector< IKeyframe* >	KeyFrameArray;

private:

	/** キーフレーム配列 */
	KeyFrameArray	keyFrameArray_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/