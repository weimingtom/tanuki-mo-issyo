/*******************************************************************************/
/**
 * @file AnimationRect.cpp.
 * 
 * @brief アニメーション矩形クラスソースファイル.
 *
 * @date 2008/08/11.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/AnimationRect.h"

using namespace Ngl;


/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @oaram[in] なし
 */
AnimationRect::AnimationRect(  ):
	isPlay_( false )
{
}



/*=========================================================================*/
/**
 * @brief 開始処理
 * 
 * @param[in] desc アニメーション矩形記述子.
 * @return なし.
 */
void AnimationRect::begin( const AnimationRectDesc& desc )
{
	// 設定記述子からパラメータをコピー
	param_.totalWidth			= desc.totalWidth;
	param_.totalHeight			= desc.totalHeight;
	param_.imageWidth			= desc.imageWidth;
	param_.imageHeight			= desc.imageHeight;
	param_.timer				= desc.timer;
	param_.loop					= desc.loop;
	param_.imageCountColumns	= desc.imageCountColumns;
	param_.imageCountRows		= desc.imageCountRows;

	// 設定をリセット
	reset();

	// 更新インターバルを求める
	param_.interval = (float)param_.timer / (float)param_.imageCountColumns / (float)param_.imageCountRows;

	// 再生開始
	isPlay_ = true;
}



/*=========================================================================*/
/**
 * @brief 更新処理
 * 
 * @param[in] frameTimer フレーム処理補正値.
 * @return なし.
 */
void AnimationRect::update( float frameTimer )
{
	// 再生中ではないか
	if( isPlay_ == false ){
		return;
	}

	// アニメーションタイマーを加算する
	param_.currentTimer += frameTimer;

	// インターバルに到達しているか
	if( param_.currentTimer >= param_.interval ){
		// 矩形値を更新
		updateRect();

		// アニメーションタイマーをクリア
		param_.currentTimer = 0.0f;
	}
}



/*=========================================================================*/
/**
 * @brief 矩形値を取得
 *
 * @warning 矩形の値はスクリーン座標です。
 *
 * @param[in] なし.
 * @return 現在の矩形値.
 */
const Rect& AnimationRect::getRect() const
{
	return rect_;
}



/*=========================================================================*/
/**
 * @brief アニメーションをリセット
 *
 * @param[in] なし.
 * @return なし.
 */
void AnimationRect::reset()
{
	// 固有パラメータを初期化
	param_.currentTimer				= 0.0f;
	param_.currentImageIndexColumn	= 0;
	param_.currentImageIndexRow		= 0;

	// 1枚目のイメージの矩形値を設定
	rect_.initialize( 
		0,							// 左
		0,							// 上
		(float)param_.imageWidth,	// 右
		(float)param_.imageHeight	// 下
		);
}
	
	

/*=========================================================================*/
/**
 * @brief パラメータを取得
 *
 * @param[in] なし.
 * @return パラメータ構造体.
 */
const AnimationRect::AnimationRectParameter& AnimationRect::parameter()
{
	return param_;
}



/*=========================================================================*/
/**
 * @brief 矩形値を更新する
 *
 * @param[in] なし.
 * @return なし.
 */
void AnimationRect::updateRect()
{
	// 現在のX位置を計算
	int curX = param_.imageWidth * param_.currentImageIndexColumn;
	int curY = param_.imageHeight * param_.currentImageIndexRow;
	
	// テクスチャ座標を変更
	rect_.initialize(
		(float)curX,							// 左
		(float)curY,							// 左上				
		(float)( curX + param_.imageWidth  ),	// 右
		(float)( curY + param_.imageHeight )	// 右下
	);

	// 横のイメージ番号を更新
	param_.currentImageIndexColumn++;

	// 横枚数を超えていないか
	if( param_.currentImageIndexColumn <= param_.imageCountColumns ){
		return;
	}

	// 横のイメージ番号を初期化
	param_.currentImageIndexColumn = 0;

	// 縦のイメージ番号を更新
	param_.currentImageIndexRow++;

	// 縦枚数を超えていないか
	if( param_.currentImageIndexRow < param_.imageCountRows ){
		return;
	}

	// ループ指定か
	if( param_.loop == true ){
		// 初期化する
		reset();
	}
	else{
		// 停止する
		isPlay_ = false;

		// 最後のイメージに設定
		param_.currentImageIndexColumn	= param_.imageCountColumns-1;
		param_.currentImageIndexRow		= param_.imageCountRows-1;
	}
}

	
	
/*===== EOF ==================================================================*/