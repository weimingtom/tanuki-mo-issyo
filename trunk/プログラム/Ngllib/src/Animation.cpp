/*******************************************************************************/
/**
 * @file Animation.cpp.
 * 
 * @brief アニメーションデータクラスソースファイル.
 *
 * @date 2008/07/01.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Animation.h"
#include	"Ngl/FileInputC.h"
#include	<fstream>
#include	<algorithm>
#include	<cassert>

using namespace Ngl;

/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
Animation::Animation()
{}



/*===========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
Animation::~Animation()
{
	// アニメーションデータを解放する
	release();
}



/*=========================================================================*/
/**
 * @brief アニメーションテイクデータを追加する
 * 
 * @warning 追加したアニメーションテイクデータはAnimationクラスで削除されます.
 *
 * @param[in] animationTake 追加するデータ.
 * @return 終了タイマ.
 */
void Animation::addAnimationTake( IBoneframe* animationTake )
{
	animationTakeArray_.push_back( animationTake );
}

	
	
/*===========================================================================*/
/**
 * @brief 指定のキーフレームデータを取得する
 * 
 * @param[in] no 取得するデータ番号.
 * @param[in] boneNo 取得するボーン番号.
 * @param[in] globalTime 取得するキーのタイマ.
 * @param[out] data キーフレームデータ.
 * @return キーフレームデータ.
 */
KeyframeData& Animation::getKeyFrame(unsigned int no, unsigned int boneNo, float globalTime, KeyframeData &data)
{
	// 各キーの値を初期化する
	data.scale.initialize( 1.0f, 1.0f, 1.0f );
	data.rotate.setIdentity();
	data.position.zero();

	// ボーンフレーム番号がデータ数よりも大きいか
	if( isOutOfRange( no ) == true ){
		return data;
	}

	// 指定ボーンのキーフレームを取得する
	return animationTakeArray_[ no ]->getKeyframe( boneNo, globalTime, data );
}



/*===========================================================================*/
/**
 * @brief アニメーションの終了タイマを調べる
 * 
 * @param[in] no アニメーションナンバー.
 * @return 終了タイマ.
 */
unsigned int Animation::getEndTimer( unsigned int no )
{
	// 指定のナンバーがデータ数よりも多いか
	if( isOutOfRange( no ) == true ){
		return 0;
	}

	// 終了タイムの初期化
	unsigned int endTime = 0;

	// 終了タイマの一番多いキーを検索する
	IBoneframe* tmpBoneframe = animationTakeArray_[ no ];
	for( unsigned int i=0; i<tmpBoneframe->getNumKeyframes(); i++ ){
		// 拡大縮小キーのフレームタイムと比較
		unsigned int numScaleKeys = tmpBoneframe->getNumScaleKeys( i );
		if( numScaleKeys != 0 ){
			endTime = std::max( endTime, tmpBoneframe->getScaleKeyFrameTime( i, numScaleKeys - 1 ) );
		}

		// 回転キーのフレームタイムと比較
		unsigned int numRotateKeys = tmpBoneframe->getNumRotateKeys( i );
		if( numRotateKeys != 0 ){
			endTime = std::max( endTime, tmpBoneframe->getRotateKeyFrameTime( i, numRotateKeys - 1 ) );
		}

		// 平行移動キーのフレームタイムと比較
		unsigned int numPositionKeys = tmpBoneframe->getNumPositionKeys( i );
		if( numPositionKeys != 0 ){
			endTime = std::max( endTime, tmpBoneframe->getPositionKeyFrameTime( i, numPositionKeys - 1 ) );
		}
	}

	return endTime;
}



/*===========================================================================*/
/**
 * @brief 指定のアニメーションのボーン数を調べる
 * 
 * @param[in] no データ番号.
 * @return ボーン数.
 */
unsigned int Animation::getNumBones(unsigned int no)
{
	// 指定の番号がデータ数よりも大きいか
	if( isOutOfRange( no ) ){
		return 0;
	}

	return animationTakeArray_[no]->getNumKeyframes();
}



/*===========================================================================*/
/**
 * @brief アニメーションデータの解放
 * 
 * @param[in] なし.
 * @return なし.
 */
void Animation::release()
{
	// アニメーションテイク配列を解放
	AnimationTakeArray::iterator itor = animationTakeArray_.begin();
	while( itor != animationTakeArray_.end() ){
		delete *itor;
		itor = animationTakeArray_.erase( itor );
	}
}



/*===========================================================================*/
/**
 * @brief 指定ナンバーがボーンフレームデータ数よりも大きいか
 * 
 * @param[in] boneframeNo ボーンフレーム番号.
 * @retval true 大きい.
 * @retval false 小さい.
 */
bool Animation::isOutOfRange(unsigned int boneframeNo)
{
	if( boneframeNo >= animationTakeArray_.size() ){
		return true;
	}
	return false;
}



/*========= EOF =============================================================*/