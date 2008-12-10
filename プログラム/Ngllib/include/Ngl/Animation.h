/*******************************************************************************/
/**
 * @file Animation.h.
 * 
 * @brief アニメーションデータクラスヘッダファイル.
 *
 * @date 2008/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MSH_ANIMATIONANM_H_
#define _NGL_MSH_ANIMATIONANM_H_

#include	"Ngl/IAnimation.h"
#include	"Ngl/IBoneframe.h"
#include	<vector>

namespace Ngl{


/**
 * @class Animation
 * @brief アニメーションクラス．
 */
class Animation : public IAnimation
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	Animation();


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~Animation();


	/*=========================================================================*/
	/**
	 * @brief アニメーションテイクデータを追加する
	 * 
	 * @warning 追加したアニメーションテイクデータはAnimationクラスで削除されます.
	 *
	 * @param[in] animationTake 追加するデータ.
	 * @return 終了タイマ.
	 */
	void addAnimationTake( IBoneframe* animationTake );

public:
	
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
	KeyframeData& getKeyFrame( unsigned int no, unsigned int boneNo, float globalTime, KeyframeData& data );


	/*=========================================================================*/
	/**
	 * @brief アニメーションの終了タイマを調べる
	 * 
	 * @param[in] no アニメーションナンバー.
	 * @return 終了タイマ.
	 */
	unsigned int getEndTimer( unsigned int no );


	/*=========================================================================*/
	/**
	 * @brief 指定のアニメーションのボーン数を調べる
	 * 
	 * @param[in] no データ番号.
	 * @return ボーン数.
	 */
	unsigned int getNumBones( unsigned int no );
	
private:
	
	/*=========================================================================*/
	/**
	 * @brief アニメーションデータの解放
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void release();

	
	/*=========================================================================*/
	/**
	 * @brief 指定ナンバーがボーンフレームデータ数よりも大きいか
	 * 
	 * @param[in] boneframeNo ボーンフレーム番号.
	 * @retval true 大きい.
	 * @retval false 小さい.
	 */
	bool isOutOfRange( unsigned int boneframeNo );

private:

	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ( コピー禁止 ）
	 * 
	 * @param[in] other コピーするオブジェクト.
	 * @return なし.
	 */
	Animation( const Animation& other );


	/*=========================================================================*/
	/**
	 * @brief =演算子オーバーロード（ コピー禁止 ）
	 * 
	 * @param[in] other 代入するオブジェクト.
	 * @return 代入結果のオブジェクト.
	 */
	Animation& operator = ( const Animation& other );

private:

	/** アニメーションテイク配列型 */
	typedef std::vector< IBoneframe* >	AnimationTakeArray;

private:

	/** アニメーションテイク配列 */
	AnimationTakeArray	animationTakeArray_;

};

} // namesapce Msh

#endif

/*===== EOF ==================================================================*/