/*******************************************************************************/
/**
 * @file Color4.cpp.
 * 
 * @brief RGBAカラー構造体ソースファイル.
 *
 * @date 2007/06/04.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include		"Ngl/Color4.h"
#include		<algorithm>

using namespace Ngl;


/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
Color4::Color4():
	r( 0.0f ),
	g( 0.0f ),
	b( 0.0f ),
	a( 1.0f )
{
}



/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] R 赤成分.
 * @param[in] G 緑成分.
 * @param[in] B 青成分.
 * @param[in] A アルファ成分
 */
Color4::Color4(float R, float G, float B, float A):
			r(R), g(G), b(B), a(A)
{
}



/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] other カラー配列のポインタ.
 */
Color4::Color4(float *other)
{
	r = other[0];
	g = other[1];
	b = other[2];
	a = other[3];
}
			


/*===========================================================================*/
/**
 * @brief 0.0に初期化する
 * 
 * @param[in] なし.
 * @return なし.
 */
void Color4::zero()
{
	r = 0.0f;
	g = 0.0f;
	b = 0.0f;
	a = 0.0f;
}

	
	
/*===========================================================================*/
/**
 * @brief 初期化する
 * 
 * @param[in] R 赤成分.
 * @param[in] G 緑成分.
 * @param[in] B 青成分.
 * @param[in] A アルファ成分
 * @return なし.
 */
void Color4::initialize(float R, float G, float B, float A)
{
	r = R;
	g = G;
	b = B;
	a = A;
}



/*===========================================================================*/
/**
 * @brief 255～0の範囲にクランプ
 * 
 * @param[in] なし.
 * @return クランプされたcolor.
 */
Color4& Color4::saturate()
{
	r = std::min( 1.0f, std::max( 0.0f, r ) );
	g = std::min( 1.0f, std::max( 0.0f, g ) );
	b = std::min( 1.0f, std::max( 0.0f, b ) );
	a = std::min( 1.0f, std::max( 0.0f, a ) );

	return *this;
}



/*===========================================================================*/
/**
 * @brief 16進数の値に変換
 * 
 * @param[in] なし.
 * @return 変換した値.
 */
unsigned long Color4::changeHexaDecimal() const
{
	// メンバ変数をint型に変換
	int iA = static_cast<unsigned int>( 255 * a );
	int iR = static_cast<unsigned int>( 255 * r );
	int iG = static_cast<unsigned int>( 255 * g );
	int iB = static_cast<unsigned int>( 255 * b );

	// 16進数に変換
	return ((unsigned long)(((iA&0xff)<<24)|((iR&0xff)<<16)|((iG&0xff)<<8)|(iB&0xff)));
}



/*===========================================================================*/
/**
 * @brief RGB値からカラーを設定する
 * @param[in] R 赤成分.
 * @param[in] G 緑成分.
 * @param[in] B 青成分.
 * @return 変換した値.
 */
Color4& Color4::setColorOfRGB( int R, int G, int B )
{
	r = static_cast<float>( R / 255.0f );
	g = static_cast<float>( G / 255.0f );
	b = static_cast<float>( B / 255.0f );

	return *this;
}
	


/*===========================================================================*/
/**
 * @brief RGBA値からカラーを設定する
 * @param[in] R 赤成分.
 * @param[in] G 緑成分.
 * @param[in] B 青成分.
 * @param[in] A アルファ成分.
 * @return 変換した値.
 */
Color4& Color4::setColorOfRGBA( int R, int G, int B, int A )
{
	setColorOfRGB( R, G, B );

	// アルファ値を変換
	a = static_cast<float>( A / 255.0f );

	return *this;
}
	

	
/*===========================================================================*/
/**
 * @brief + 演算子オーバーロード
 * 
 * @param[in] なし.
 * @return 演算したcolorの値.
 */
Color4 Color4::operator + () const
{
	return *this;
}



/*===========================================================================*/
/**
 * @brief - 演算子オーバーロード, 補色を求める
 * 
 * @param[in] なし.
 * @return 演算したcolorの値.
 */
Color4 Color4::operator - () const
{
	return Color4( 1.0f - r, 1.0f - g, 1.0f - b, 1.0f - a );
}



/*===========================================================================*/
/**
 * @brief += 演算子オーバーロード
 * 
 * @param[in] c2 演算するカラー.
 * @return 演算したcolorの値.
 */
Color4& Color4::operator += ( const Color4& c2 )
{
	r += c2.r;
	g += c2.g;
	b += c2.b;
	a += c2.a;

	// 値をクランプ
	(*this).saturate();

	return *this;
}



/*===========================================================================*/
/**
 * @brief -= 演算子オーバーロード
 * 
 * @param[in] c2 演算するカラー.
 * @return 演算したcolorの値.
 */
Color4& Color4::operator -= ( const Color4& c2 )
{
	r = r - c2.r;
	g = g - c2.g;
	b = b - c2.b;
	a = a - c2.a;

	return *this;
}



/*===========================================================================*/
/**
 * @brief *= 演算子オーバーロード
 * 
 * @param[in] c2 演算するカラー.
 * @return 演算したcolorの値.
 */
Color4& Color4::operator *= ( const Color4& c2 )
{	
	r = r * c2.r;
	g = g * c2.g;
	b = b * c2.b;
	a = a * c2.a;

	// 値をクランプ
	(*this).saturate();

	return *this;
}



/*===========================================================================*/
/**
 * @brief *= 演算子オーバーロード
 * 
 * @param[in] s 演算する値.
 * @return 演算したcolorの値.
 */
Color4& Color4::operator *= ( float s )
{
	r *= s;
	g *= s;
	b *= s;
	a *= s;

	// 値をクランプ
	(*this).saturate();

	return *this;
}


	
/*===========================================================================*/
/**
 * @brief *= 演算子オーバーロード
 * 
 * @param[in] s 演算する値.
 * @return 演算したcolorの値.
 */
Color4& Color4::operator *= ( int s )
{	
	r *= s;
	g *= s;
	b *= s;
	a *= s;

	// 値をクランプ
	(*this).saturate();

	return *this;
}



/*===========================================================================*/
/**
 * @brief /= 演算子オーバーロード
 * 
 * @param[in] c2 演算するカラー.
 * @return 演算したcolorの値.
 */
Color4& Color4::operator /= ( const Color4& c2 )
{	
	r = r / c2.r;
	g = g / c2.g;
	b = b / c2.b;
	a = a / c2.a;

	(*this).saturate();

	return *this;
}



/*===========================================================================*/
/**
 * @brief /= 演算子オーバーロード
 * 
 * @param[in] s 演算する値.
 * @return 演算したcolorの値.
 */
Color4& Color4::operator /= ( int s )
{
	r /= s;
	g /= s;
	b /= s;
	a /= s;

	// 値をクランプ
	(*this).saturate();

	return *this;
}



/*===========================================================================*/
/**
 * @brief float* 演算子オーバーロード
 * 
 * @param[in] なし.
 * @return キャストしたfloat型の値.
 */
Color4::operator float *() const
{
	return ( float* )this;
}



/*===========================================================================*/
/**
 * @brief const float* 演算子オーバーロード
 * 
 * @param[in] なし.
 * @return キャストしたconst float*型の値.
 */
Color4::operator const float *() const
{
	return ( const float* )this;
}



/*===========================================================================*/
/**
 * @brief + 演算子オーバーロード
 * 
 * @param[in] c1 演算するカラー.
 * @param[in] c2 演算するカラー.
 * @return 演算した結果.
 */
const Color4 operator + ( const Color4& c1, const Color4& c2 )
{
	Color4 tmp(c1);
	return tmp += c2;
}



/*===========================================================================*/
/**
 * @brief - 演算子オーバーロード
 * 
 * @param[in] c1 演算するカラー.
 * @param[in] c2 演算するカラー.
 * @return 演算した結果.
 */
const Color4 operator - ( const Color4& c1, const Color4& c2 )
{
	Color4 tmp(c1);
	return tmp -= c2;
}



/*===========================================================================*/
/**
 * @brief * 演算子オーバーロード
 * 
 * @param[in] c1 演算するカラー.
 * @param[in] c2 演算するカラー.
 * @return 演算した結果.
 */
const Color4 operator * ( const Color4& c1, const Color4& c2 )
{
	Color4 tmp(c1);
	return tmp *= c2;
}



/*===========================================================================*/
/**
 * @brief * 演算子オーバーロード
 * 
 * @param[in] s 演算する値.
 * @param[in] c 演算するカラー.
 * @return 演算した結果.
 */
const Color4 operator * ( float s, const Color4& c )
{
	return c * s;
}



/*===========================================================================*/
/**
 * @brief * 演算子オーバーロード
 * 
 * @param[in] c 演算するカラー.
 * @param[in] s 演算する値.
 * @return 演算した結果.
 */
const Color4 operator * ( const Color4& c, float s )
{
	Color4 tmp(c);
	return tmp *= s;
}



/*===========================================================================*/
/**
 * @brief * 演算子オーバーロード
 * 
 * @param[in] s 演算する値.
 * @param[in] c 演算するカラー.
 * @return 演算した結果.
 */
const Color4 operator * ( int s, const Color4& c )
{
	return c * s;
}



/*===========================================================================*/
/**
 * @brief * 演算子オーバーロード
 * 
 * @param[in] c 演算するカラー.
 * @param[in] s 演算する値.
 * @return 演算した結果.
 */
const Color4 operator * ( const Color4& c, int s )
{
	Color4 tmp(c);
	return tmp *= s;
}



/*===========================================================================*/
/**
 * @brief / 演算子オーバーロード
 * 
 * @param[in] c 演算するカラー.
 * @param[in] s 演算する値.
 * @return 演算した結果.
 */
const Color4 operator / ( const Color4& c, int s )
{
	Color4 tmp( c );
	return tmp /= s;
}



/*========= EOF =============================================================*/