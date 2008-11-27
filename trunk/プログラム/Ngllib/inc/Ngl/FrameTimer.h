/*******************************************************************************/
/**
 * @file FrameTimer.h.
 * 
 * @brief フレームタイム調整クラスヘッダファイル.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_FRAMETIMER_H_
#define _NGL_FRAMETIMER_H_

namespace Ngl{


/**
 * @class FrameTimer.
 * @brief フレーム処理時間計測クラス．
 */
class FrameTimer
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタbr>
	 * 
	 * @param[in] なし.
	 */
	FrameTimer();
	
	
	/*=========================================================================*/
	/**
	 * @brief フレームタイマーのリセットbr>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void reset();


	/*=========================================================================*/
	/**
	 * @brief フレームタイマーを更新するbr>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void update();


	/*=========================================================================*/
	/**
	 * @brief 秒タイマ－を取得するbr>
	 * 
	 * @param[in] なし.
	 * @return 経過時間(秒).
	 */
	float timeGetTime();


	/*=========================================================================*/
	/**
	 * @brief 処理おちによる描画スキップの必要があるか調べるbr>
	 * 
	 * @param[in] なし.
	 * @retval true スキップが必要.
	 * @retval false 不要.
	 */
	bool isSkipFrame();

	
	/*=========================================================================*/
	/**
	 * @brief ウェイトをするbr>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void wait();
	
	
	/*=========================================================================*/
	/**
	 * @brief フレーム処理時間を取得するbr>
	 * 
	 * @param[in] なし.
	 * @return フレーム処理時間.
	 */
	inline float getTime() const
	{
		return frameTime_;
	}


	/*=========================================================================*/
	/**
	 * @brief ウェイト時間を設定するbr>
	 * 
	 * @param[in] wait 設定する待ち時間.
	 * @return なし.
	 */
	inline void setWaitTime( float wait )
	{
		waitTime_ = wait;
	}


	/*=========================================================================*/
	/**
	 * @brief FPSを設定するbr>
	 * 
	 * @param[in] fps 設定するFPS値.
	 * @return なし.
	 */
	inline void setFPS( float fps )
	{
		fps_ = fps;
	}

public:

	/** フレームタイム */
	static const float	FPS;

	/** スキップ最大数 */
	static const int	FRAME_SKIP_MAX;

	/** タイマの誤差 */
	static const float	FPS_ERROR;

private:

	/** FPS */
	float	fps_;

	/** 1フレームの開始時間 */
	float	startTime_;

	/** 前回のフレーム開始時間 */
	float	prevTime_;

	/** 1フレームの経過時間 */
	float	frameTime_;

	/** 処理オーバー時間 */
	float	overTime_;

	/** ウェイト時間 */
	float	waitTime_;

	/** フレームスキップカウンタ */
	int		frameSkipCount_;

	/** フレームスキップの最大数 */
	int		frameSkipCountMax_;

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/