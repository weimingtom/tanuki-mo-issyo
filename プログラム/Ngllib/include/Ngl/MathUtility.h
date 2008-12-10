/*******************************************************************************/
/**
 * @file MathUtility.h.
 * 
 * @brief 数学ユーティリティー関数郡定義ヘッダファイル.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MATHUTILITY_H_
#define _NGL_MATHUTILITY_H_

#include	<cmath>

namespace Ngl{


/** 円周率 */
static const float PI = 3.14159265358979323846264f;


/*=========================================================================*/
/**
 * @brief 正弦値を求める
 * 
 * @param[in] degree 角度.
 * @return 正弦値.
 */
float sin( float degree );


/*=========================================================================*/
/**
 * @brief 余弦値を求める
 * 
 * @param[in] degree 角度.
 * @return 余弦値.
 */
float cos( float degree );


/*=========================================================================*/
/**
 * @brief 正接値を求める
 * 
 * @param[in] degree 角度.
 * @return 正接値.
 */
float tan( float degree );


/*=========================================================================*/
/**
 * @brief 逆正弦値を求める
 * 
 * @param[in] y 求める値.
 * @return 逆正弦値.
 */
float asin( float y );


/*=========================================================================*/
/**
 * @brief 逆余弦値を求める
 * 
 * @param[in] x 求める値.
 * @return 逆余弦値.
 */
float acos( float x );


/*=========================================================================*/
/**
 * @brief 逆正接値を求める
 * 
 * @param[in] x x成分.
 * @param[in] y y成分.
 * @return 逆正接値.
 */
float atan( float degX, float degY );


/*=========================================================================*/
/**
 * @brief 角度をラジアンに変換する
 * 
 * @param[in] degree 角度.
 * @return 変換したラジアン値.
 */
float toRadian( float degree );


/*=========================================================================*/
/**
 * @brief ラジアンを角度に変換する
 * 
 * @param[in] radian ラジアン.
 * @return 変換した角度.
 */
float toDegree( float radian );


/*=========================================================================*/
/**
 * @brief 角度を正規化する
 * 
 * @param[in] degree 正規化する角度.
 * @return 正規化した角度.
 */
float degreeNormalize( float degree );


/*=========================================================================*/
/**
 * @brief 絶対値を求める
 * 
 * @param[in] v 絶対値を求める値.
 * @return 絶対値.
 */
template< typename Type >
Type abs( Type v )
{
	Type result = 0;
	( v < 0 ) ? result = -v : result = v;
	return result;
}


/*=========================================================================*/
/**
 * @brief 最大値を求める
 * 
 * @param[in] a 要素１.
 * @param[in] b 要素２.
 * @return 最大値.
 */
template< typename Type >
Type max_ngl( Type a, Type b )
{
	Type result = 0;
	( a > b ) ? result = a : result = b;
	return result;
}


/*=========================================================================*/
/**
 * @brief 最小値を求める
 * 
 * @param[in] a 要素１.
 * @param[in] b 要素２.
 * @return 最小値.
 */
template< typename Type >
Type min_ngl( Type a, Type b )
{
	Type result = 0;
	( a < b ) ? result = a : result = b;
	return result;
}


/*=========================================================================*/
/**
 * @brief 指定の値を２乗する
 * 
 * @param[in] a ２乗する値
 * @return ２乗した値.
 */
template< typename Type >
Type sqr( Type a )
{
	return a * a;
}


/*=========================================================================*/
/**
 * @brief 平方根を求める
 * 
 * @param[in] a 平方根を求める値
 * @return ２乗した値.
 */
template< typename Type >
Type sqrt( Type a )
{
	return std::sqrt( a );
}



/*=========================================================================*/
/**
 * @brief vをlからhの間に収める
 * 
 * @param[in] v クランプする値.
 * @param[in] l 最小値.
 * @param[in] h 最大値.
 * @return クランプした値.
 */
template< typename Type >
Type clamp( Type v, Type l, Type h )
{
	return max_ngl( l, min_ngl( v, h ) );
}


/*=========================================================================*/
/**
 * @brief lからhまでを線形補間する(aは0.0fから1.0f)
 * 
 * @param[in] a 補間したい値.
 * @param[in] l 最小値.
 * @param[in] h 最大値.
 * @return 補間した値.
 */
template< typename Type >
Type lerp( float a, Type l, Type h )
{
	return l + ( h - l ) * a;
}


/*=========================================================================*/
/**
 * @brief v1, v2, v3を二次補完する(aは0.0fから1.0f)
 * 
 * @param[in] a 補間したい値.
 * @param[in] v1 補間値１.
 * @param[in] v2 補間値２.
 * @param[in] v3 補間値３.
 * @return 補間した値.
 */
template< typename Type >
Type quadratic( float a, Type v1, Type v2, Type v3 )
{
	return v1 * ( 1.0f - a ) * ( 1.0f - a ) + 2 * v2 * a * ( 1.0f - a ) + v3 * a * a; 
}


/*=========================================================================*/
/**
 * @brief a の値がmin, maxの範囲外の値か調べる
 * 
 * @param[in] a 調べる値.
 * @param[in] minV 範囲の最小値.
 * @param[in] maxV 範囲の最大値.
 * @retval true 範囲外の値.
 * @retval false 範囲内の値.
 */
template< typename Type >
bool outOfRange( Type a, Type minV, Type maxV )
{
	return ( ( ( a < minV ) || ( a > maxV ) ) ? true : false );
}


} // namespace Ngl

#endif

/*===== EOF ==================================================================*/