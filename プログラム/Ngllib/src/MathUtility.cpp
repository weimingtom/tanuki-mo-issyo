/*******************************************************************************/
/**
 * @file MathUtility.cpp.
 * 
 * @brief 数学ユーティリティー関数郡定義ソースファイル.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	<Ngl/MathUtility.h>


/*=========================================================================*/
/**
 * @brief 正弦値を求める
 * 
 * @param[in] degree 角度.
 * @return 正弦値.
 */
float Ngl::sin( float degree )
{
	float temp;

	// ラジアンに変換
	temp = (float)Ngl::toRadian(degree);

	return std::sin(temp);
}



/*=========================================================================*/
/**
 * @brief 余弦値を求める
 * 
 * @param[in] degree 角度.
 * @return 余弦値.
 */
float Ngl::cos( float degree )
{
	float temp;

	// ラジアンに変換
	temp = (float)Ngl::toRadian(degree);

	return std::cos(temp);
}



/*=========================================================================*/
/**
 * @brief 正接値を求める
 * 
 * @param[in] degree 角度.
 * @return 正接値.
 */
float Ngl::tan( float degree )
{
	float temp;

	// ラジアンに変換
	temp = (float)Ngl::toRadian(degree);

	return std::tan(temp);
}



/*=========================================================================*/
/**
 * @brief 逆正弦値を求める
 * 
 * @param[in] y 求める値.
 * @return 逆正弦値.
 */
float Ngl::asin( float y )
{
	return Ngl::toDegree( std::asin( y ) );
}



/*=========================================================================*/
/**
 * @brief 逆余弦値を求める
 * 
 * @param[in] x 求める値.
 * @return 逆余弦値.
 */
float Ngl::acos( float x )
{
	return Ngl::toDegree( std::acos( x ) );
}



/*=========================================================================*/
/**
 * @brief 逆正接値を求める
 * 
 * @param[in] x x成分.
 * @param[in] y y成分.
 * @return 逆正接値.
 */
float Ngl::atan( float x, float y )
{
	return degreeNormalize( Ngl::toDegree( std::atan2( x, y ) ) );
}



/*=========================================================================*/
/**
 * @brief 角度をラジアンに変換する
 * 
 * @param[in] degree 角度.
 * @return 変換したラジアン値.
 */
float Ngl::toRadian( float degree )
{
	return degree * ( 1.0f / 180.0f * Ngl::PI );
}



/*=========================================================================*/
/**
 * @brief ラジアンを角度に変換する
 * 
 * @param[in] radian ラジアン.
 * @return 変換した角度.
 */
float Ngl::toDegree( float radian )
{
	return radian * ( 1.0f / Ngl::PI * 180.0f );
}



/*=========================================================================*/
/**
 * @brief 角度を正規化する
 * 
 * @param[in] degree 正規化する角度.
 * @return 正規化した角度.
 */
float Ngl::degreeNormalize( float degree )
{
	return ( ( degree >= 0.0f ) ? (float)std::fmod( degree, 360.0f ) : (float)std::fmod( degree, 360.0f ) + 360.0f );
}



/*===== EOF ==================================================================*/