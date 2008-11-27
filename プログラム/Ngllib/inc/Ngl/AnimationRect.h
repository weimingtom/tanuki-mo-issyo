/*******************************************************************************/
/**
 * @file AnimationRect.h.
 * 
 * @brief アニメーション矩形クラスヘッダファイル.
 *
 * @date 2008/08/11.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ANIMATIONRECT_H_
#define _NGL_ANIMATIONRECT_H_

#include	"Rect.h"

namespace Ngl{


/**
 * @struct AnimationRectDesc.
 * @brief アニメーション矩形記述子構造体.
 *
 * パラメータの設定に使用する記述子です.
 */
struct AnimationRectDesc
{
	/** 全体の幅( スクリーン座標 ) */
	int			totalWidth;

	/** 全体の高さ( スクリーン座標 ) */
	int			totalHeight;

	/** イメージ1枚の幅( スクリーン座標 ) */
	int			imageWidth;

	/** イメージ1枚の高さ( スクリーン座標 ) */
	int			imageHeight;

	/** イメージの横枚数 */
	int			imageCountColumns;

	/** イメージの縦枚数 */
	int			imageCountRows;

	/** すべてのイメージを描画するのにかかる時間 */
	int			timer;

	/** ループするか */
	bool		loop;


	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし
	 */
	AnimationRectDesc():
		totalWidth( 1 ),
		totalHeight( 1 ),
		imageWidth( 1 ),
		imageHeight( 1 ),
		imageCountColumns( 1 ),
		imageCountRows( 1  ),
		timer( 1 ),
		loop( true )
	{}
};


/**
 * @class AnimationRect．
 * @brief アニメーション矩形クラス.
 *
 * アニメーション用の矩形値を生成するクラスです。
 * ビデオテクスチャなどをアニメーションさせるためのテクスチャ座標として利用できます。
 */
class AnimationRect
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @oaram[in] なし
	 */
	AnimationRect();


	/*=========================================================================*/
	/**
	 * @brief 開始処理
	 *
	 * @param[in] desc アニメーション矩形記述子.
	 * @return なし.
	 */
	void begin( const AnimationRectDesc& desc );
	
	
	/*=========================================================================*/
	/**
	 * @brief 更新処理
	 * 
	 * @param[in] frameTimer フレーム処理補正値.
	 * @return なし.
	 */
	void update( float frameTimer );


	/*=========================================================================*/
	/**
	 * @brief 矩形値を取得
	 *
	 * @warning 矩形の値はスクリーン座標です。
	 *
	 * @param[in] なし.
	 * @return 現在の矩形値.
	 */
	const Rect& getRect() const;


	/*=========================================================================*/
	/**
	 * @brief アニメーションをリセット
	 *
	 * @param[in] なし.
	 * @return なし.
	 */
	void reset();

public:

	/**
	 * @struct AnimationRectParameter.
	 * @brief アニメーション矩形パラメータ構造体.
	 */
	struct AnimationRectParameter
	{
		/** ループするか */
		bool		loop;
		
		/** 現在の描画しているイメージ横番号( イメージ1枚目が0番 ) */
		int			currentImageIndexColumn;

		/** 現在の描画しているイメージ縦番号( イメージ1枚目が0番 ) */
		int			currentImageIndexRow;

		/** 全体の幅( スクリーン座標 ) */
		int			totalWidth;

		/** 全体の高さ( スクリーン座標 ) */
		int			totalHeight;

		/** イメージ1枚の幅( スクリーン座標 ) */
		int			imageWidth;

		/** イメージ1枚の高さ( スクリーン座標 ) */
		int			imageHeight;

		/** イメージの横枚数 */
		int			imageCountColumns;

		/** イメージの縦枚数 */
		int			imageCountRows;

		/** 描画タイマー */
		int			timer;

		/** 現在の描画タイマー */
		float		currentTimer;

		// 切り替え間隔
		float		interval;
	};


	/*=========================================================================*/
	/**
	 * @brief パラメータを取得
	 *
	 * @param[in] なし.
	 * @return パラメータ構造体.
	 */
	const AnimationRectParameter& parameter();

private:

	/*=========================================================================*/
	/**
	 * @brief 矩形値を更新する
	 *
	 * @param[in] なし.
	 * @return なし.
	 */
	void updateRect();

private:

	/** 矩形値 */
	Rect					rect_;
	
	/** パラメータ */
	AnimationRectParameter	param_;

	/** 再生中か */
	bool					isPlay_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/