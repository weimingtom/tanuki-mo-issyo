/*******************************************************************************/
/**
 * @file FrameTimer.cpp.
 * 
 * @brief フレームタイム調整クラスソースファイル.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/FrameTimer.h"
#include	<windows.h>

using namespace Ngl;

/*==== 定数宣言 =============================================================*/
const int	FrameTimer::FRAME_SKIP_MAX	= 8;		// フレームスキップの最大可能数
const float	FrameTimer::FPS_ERROR		= 0.1f;		// タイマ誤差
const float	FrameTimer::FPS				= 60.0f;	// フレームタイム


/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
FrameTimer::FrameTimer() :
	fps_( FPS ),						// FPS
	startTime_( 0.0f ),					// 1フレーム開始時間
	prevTime_( 0.0f ),					// 前回のフレーム開始時間
	frameTime_( 0.0f ),					// 1フレームの経過時間
	overTime_( 0.0f ),					// 処理オーバー時間
	waitTime_( 0.25f ),					// ウェイト時間
	frameSkipCount_( 0 ),				// フレームスキップカウンタ
	frameSkipCountMax_( FRAME_SKIP_MAX )// フレームスキップの最大数
{}



/*===========================================================================*/
/**
 * @brief フレームタイマーのリセットbr>
 * 
 * @param[in] なし.
 * @return なし.
 */
void FrameTimer::reset()
{
	startTime_			= 0.0f;		// フレーム開始時間
	frameTime_			= 0.0f;		// 1フレームの処理時間
	overTime_			= 0.0f;		// 処理オーバー時間
	waitTime_			= 0.25f;	// ウェイト時間
	frameSkipCount_		= 0;		// フレームスキップ回数

	// 前回のフレーム開始時間を保存する
	prevTime_			= timeGetTime();
}



/*===========================================================================*/
/**
 * @brief フレームタイマーを更新するbr>
 * 
 * @param[in] なし.
 * @return なし.
 */
void FrameTimer::update()
{
	// 1フレームの開始時間を計測
	startTime_ = timeGetTime();

	// 1フレームあたりの処理時間を求める
	frameTime_ = ( startTime_ - prevTime_ ) * fps_;

	// 前回のタイマー値として保存する
	prevTime_ = startTime_;

	// FPSタイマー以上に時間が経過してしまっているか
	overTime_ = 0.0f;
	if( frameTime_ > 1.0f ){
		// オーバーした時間を計算する
		overTime_ = frameTime_ - 1.0f;

		// オーバー分を補正する
		frameTime_ = 1.0f;

		// 誤差の範囲内か判定する
		if( overTime_ <= FPS_ERROR ){
			overTime_ = 0.0f;
		}
	}
}



/*===========================================================================*/
/**
 * @brief 秒タイマ－を取得するbr>
 * 
 * @param[in] なし.
 * @return 経過時間(秒). 　
 */
float FrameTimer::timeGetTime()
{
	// タイマを取得する
	LARGE_INTEGER Time;
	QueryPerformanceCounter( &Time );

	// タイマの分解能を取得する
	LARGE_INTEGER Freq;
	QueryPerformanceFrequency( &Freq );

	// 秒単位に変換して返す
	return	(float)( (double)Time.QuadPart / (double)Freq.QuadPart );
}



/*===========================================================================*/
/**
 * @brief 処理おちによる描画スキップの必要があるか調べるbr>
 * 
 * @param[in] なし.
 * @retval true スキップが必要.
 * @retval false 不要.
 */
bool FrameTimer::isSkipFrame()
{
	// 最大スキップ数以上はスキップさせないようにする
	if( frameSkipCount_ >= FRAME_SKIP_MAX ){
		/* スキップ数を初期化する */
		frameSkipCount_ = 0;

		/* オーバーした時間を初期化する */
		overTime_ = 0.0f;

		return	false;
	}

	// 時間オーバーしているか
	if ( overTime_ > 0 ){
		// ＦＰＳタイマよりもオーバーしているか？
		if ( overTime_ > 1.0f ){
			// オーバーした時間を調整する
			overTime_ -= 1.0f;

			// タイマを調整する
			frameTime_ = 1.0f;
		}
		else{
			// タイマを調整する
			frameTime_ = overTime_;

			// オーバーした時間分は処理をした事にする
			overTime_ = 0.0f;
		}

		// スキップカウンタを増加させる
		frameSkipCount_++;

		// 描画をスキップする必要がある
		return	true;
	}

	// スキップカウンタを初期化する
	frameSkipCount_ = 0;

	// オーバーした時間を初期化する
	overTime_ = 0.0f;

	return	false;
}



/*===========================================================================*/
/**
 * @brief ウェイトをするbr>
 * 
 * @param[in] なし.
 * @return なし.
 */
void FrameTimer::wait()
{
	// １フレームあたりの時間を求める
	float		frameTime;
	frameTime = ( timeGetTime() - startTime_ ) * fps_;

	// 最低ウェイト時間よりも時間が短いか
	if ( frameTime < waitTime_ ){
		// ウェイトする時間を求める
		float		waitTime;
		waitTime = waitTime_ - frameTime;

		// 最低ウェイトタイマ分ウェイトする
		float		startTime;
		startTime = timeGetTime() * fps_;
		while ( ( ( ( timeGetTime() * fps_ ) - startTime )  ) < waitTime );
	}
}



/*========= EOF =============================================================*/