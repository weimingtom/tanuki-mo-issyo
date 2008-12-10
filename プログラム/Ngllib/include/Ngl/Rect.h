/*******************************************************************************/
/**
 * @file Rect.h.
 * 
 * @brief 矩形構造体ヘッダファイル.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_RECT_H_
#define _NGL_RECT_H_

#ifdef __cplusplus
namespace Ngl{
#endif


/**
 * @struct Rect
 * @brief 矩形構造体．
 */
typedef struct Rect
{

	/** 左座標 */
	float left;

	/** 上座標 */
	float top;

	/** 右座標 */
	float right;

	/** 下座標 */
	float bottom;


#ifdef __cplusplus


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	Rect();


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] L 左端位置.
	 * @param[in] T 上端位置.
	 * @param[in] R 右端位置.
	 * @param[in] B 下端位置.
	 */
	Rect( float L, float T, float R, float B );


	/*=========================================================================*/
	/**
	 * @brief 初期化する
	 * 
	 * @param[in] L 左端位置.
	 * @param[in] T 上端位置.
	 * @param[in] R 右端位置.
	 * @param[in] B 下端位置.
	 * @return なし.
	 */
	void initialize( float L, float T, float R, float B );


	/*=========================================================================*/
	/**
	 * @brief 位置座標, 幅と高さから矩形を求める
	 * 
	 * @param[in] L 左上位置x座標.
	 * @param[in] T 左上位置y座標.
	 * @param[in] Width 右端位置.
	 * @param[in] Height 下端位置.
	 * @return なし.
	 */
	void fromSize( float L, float T, float Width, float Height );


#endif


} NGLrect;


#ifdef __cplusplus


/** 零矩形 */
static const Rect RECT_ZERO = Rect( 0.0f, 0.0f, 0.0f, 0.0f );

/** デフォルトのテクスチャ座標 */
static const Rect RECT_TEXCOORD = Rect( 0.0f, 0.0f, 1.0f, 1.0f );


} // namespace Ngl


/*=========================================================================*/
/**
 * @brief == 演算子オーバーロード
 *
 * 同じ値の矩形か比較する。
 * 
 * @param[in] r1 比較する矩形1.
 * @param[in] r2 比較する矩形2.
 * @retval true 同じ値.
 * @retval false 違う値.
 */
bool operator == ( const Ngl::Rect& r1, const Ngl::Rect& r2 );


/*=========================================================================*/
/**
 * @brief != 演算子オーバーロード
 *
 * 違う値の矩形か比較する。
 * 
 * @param[in] r1 比較する矩形1.
 * @param[in] r2 比較する矩形2.
 * @retval true 違う値.
 * @retval false 同じ値.
 */
bool operator != ( const Ngl::Rect& r1, const Ngl::Rect& r2 );


#endif


#endif

/*===== EOF ==================================================================*/