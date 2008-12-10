/*******************************************************************************/
/**
 * @file Rect.cpp.
 * 
 * @brief 矩形構造体ソースファイル.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Rect.h"

using namespace Ngl;

/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
Rect::Rect():
	left( 0.0f ),	// 左端位置
	top( 0.0f ),	// 上端位置
	right( 0.0f ),	// 右端位置
	bottom( 0.0f )	// 下端位置
{
}



/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] L 左端位置, T 上端位置, R 右端位置, B 下端位置.
 */
Rect::Rect(float L, float T, float R, float B):
	left( L ),	// 左端位置
	top( T ),	// 上端位置
	right( R ),	// 右端位置
	bottom( B )	// 下端位置
{
}



/*===========================================================================*/
/**
 * @brief 初期化する
 * 
 * @param[in] L 左端位置.
 * @param[in] T 上端位置.
 * @param[in] R 右端位置.
 * @param[in] B 下端位置.
 * @return なし.
 */
void Rect::initialize( float L, float T, float R, float B )
{
	left = L;
	top = T;
	right = R;
	bottom = B;
}

	
	
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
void Rect::fromSize( float L, float T, float Width, float Height )
{
	left	= L;
	top		= T;
	right	= left + Width;
	bottom	= top + Height; 
}
	
	
	
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
bool operator == ( const Ngl::Rect& r1, const Ngl::Rect& r2 )
{
	return ( r1.left == r2.left && r1.top == r2.top && r1.right == r2.right && r1.bottom == r2.bottom );
}



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
bool operator != ( const Ngl::Rect& r1, const Ngl::Rect& r2 )
{
	return !( r1 == r2 );
}
	
	
	
/*========= EOF =============================================================*/