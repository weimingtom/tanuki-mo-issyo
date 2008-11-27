/*******************************************************************************/
/**
 * @file AnimationTake.cpp.
 * 
 * @brief アニメーションテイクデータクラスソースファイル.
 *
 * @date 2008/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/AnimationTake.h"
#include	<cassert>

using namespace Ngl;

/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
AnimationTake::AnimationTake()
{}



/*===========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
AnimationTake::~AnimationTake()
{
	// ボーンフレームを解放する
	release();
}



/*=========================================================================*/
/**
 * @brief キーフレームを追加する
 * 
 * @warning 追加したキーフレームはAnimatinTakeクラスで削除されます.
 *
 * @param[in] keyframe 追加するキーフレーム.
 * @return なし.
 */
void AnimationTake::addKeyFrame( IKeyframe* keyframe )
{
	keyFrameArray_.push_back( keyframe );
}

	
	
/*===========================================================================*/
/**
 * @brief 指定番号のキーフレームを取得する
 * 
 * @param[in] boneNo 取得するボーンID.
 * @param[in] globalTime 取得するキーのタイマ.
 * @param[out] data キーフレーム情報.
 * @return キーフレーム情報.
 */
KeyframeData& AnimationTake::getKeyframe(unsigned int boneNo, float globalTime, Ngl::KeyframeData &data)
{
	// ボーンナンバーがキーフレーム数よりも大きいか
	if( isOutOfRange( boneNo ) ){
		return data;
	}

	// キーフレームデータから各値を取得する
	return keyFrameArray_[ boneNo ]->getKey( globalTime, data );
}



/*===========================================================================*/
/**
 * @brief ボーンフレームを解放する
 * 
 * @param[in] なし.
 * @return なし.
 */
void AnimationTake::release()
{
	// キーフレーム配列を解放
	KeyFrameArray::iterator itor = keyFrameArray_.begin();
	while( itor != keyFrameArray_.end() ){
		delete *itor;
		itor = keyFrameArray_.erase( itor );
	}
}



/*===========================================================================*/
/**
 * @brief 指定のキーフレームの拡大縮小キー数を取得する
 * 
 * @param[in] no 取得するキーフレーム番号.
 * @return 拡大縮小キー数.
 */
unsigned int AnimationTake::getNumScaleKeys(unsigned int no)
{
	// 指定の番号がデータ数よりも大きいか
	if( isOutOfRange( no ) ){
		return 0;
	}

	// キーフレームから拡大縮小キー数を取得する
	return keyFrameArray_[no]->getNumScaleKeys();
}



/*===========================================================================*/
/**
 * @brief 指定のキーフレームの回転キー数を取得する
 * 
 * @param[in] no 取得するキーフレーム番号.
 * @return 回転キー数.
 */
unsigned int AnimationTake::getNumRotateKeys(unsigned int no)
{
	// 指定の番号がデータ数よりも大きいか
	if( isOutOfRange( no ) ){
		return 0;
	}

	// キーフレームから回転キー数を取得する
	return keyFrameArray_[no]->getNumRotateKeys();
}



/*===========================================================================*/
/**
 * @brief 指定のキーフレームの平行移動キー数を取得する
 * 
 * @param[in] no 取得するキーフレーム番号.
 * @return 平行移動キー数.
 */
unsigned int AnimationTake::getNumPositionKeys(unsigned int no)
{
	// 指定の番号がデータ数よりも大きいか
	if( isOutOfRange( no ) ){
		return 0;
	}

	// キーフレームから平行移動キー数を取得する
	return keyFrameArray_[no]->getNumPositionKeys();
}



/*===========================================================================*/
/**
 * @brief 指定のキーフレームの拡大縮小キーからフレームタイムを取得する
 * 
 * @param[in] frameNo 取得するキーフレーム番号.
 * @param[in] keyNo キー番号.
 * @return フレームタイム.
 */
unsigned int AnimationTake::getScaleKeyFrameTime(unsigned int frameNo, unsigned int keyNo)
{
	// 指定の番号がデータ数よりも大きいか
	if( isOutOfRange( frameNo ) ){
		return 0;
	}

	// フレームタイムを取得する
	return keyFrameArray_[frameNo]->getScaleKeyFrameTime( keyNo );
}



/*===========================================================================*/
/**
 * @brief 指定のキーフレームの回転キーからフレームタイムを取得する
 * 
 * @param[in] frameNo 取得するキーフレーム番号.
 * @param[in] keyNo キー番号.
 * @return フレームタイム.
 */
unsigned int AnimationTake::getRotateKeyFrameTime(unsigned int frameNo, unsigned int keyNo)
{
	// 指定の番号がデータ数よりも大きいか
	if( isOutOfRange( frameNo ) ){
		return 0;
	}

	// フレームタイムを取得する
	return keyFrameArray_[frameNo]->getRotateKeyFrameTime( keyNo );
}



/*===========================================================================*/
/**
 * @brief 指定のキーフレームの平行移動キーからフレームタイムを取得する
 * 
 * @param[in] frameNo 取得するキーフレーム番号.
 * @param[in] keyNo キー番号.
 * @return フレームタイム.
 */
unsigned int AnimationTake::getPositionKeyFrameTime( unsigned int frameNo, unsigned int keyNo )
{
	// 指定の番号がデータ数よりも大きいか
	if( isOutOfRange( frameNo ) ){
		return 0;
	}

	// フレームタイムを取得する
	return keyFrameArray_[frameNo]->getPositionKeyFrameTime( keyNo );
}



/*=========================================================================*/
/**
 * @brief キーフレーム数を取得する
 * 
 * @param[in] なし.
 * @return なし.
 */
unsigned int AnimationTake::getNumKeyframes() const
{
	return (unsigned int)keyFrameArray_.size();
}
	


/*===========================================================================*/
/**
 * @brief 指定の番号がデータ数を超えているか
 * 
 * @param[in] no 番号.
 * @retval true 超えている.
 * @retval false 超えていない.
 */
bool AnimationTake::isOutOfRange( unsigned int no )
{
	if( no > keyFrameArray_.size() ){
		return true;
	}
	return false;
}



/*========= EOF =============================================================*/