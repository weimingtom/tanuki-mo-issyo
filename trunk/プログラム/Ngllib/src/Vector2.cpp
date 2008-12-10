/*******************************************************************************/
/**
 * @file Vector2.cpp.
 * 
 * @brief ２次元ベクトル構造体ソースファイル.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	<Ngl/Vector2.h>
#include	<Ngl/MathUtility.h>

using namespace Ngl;

/*==== 定数宣言 =============================================================*/

/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
Vector2::Vector2() :
	x( 0.0f ),
	y( 0.0f )
{}



/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] other 配列のポインタ.
 */
Vector2::Vector2(const float *other)
{
	x = other[0];
	y = other[1];
}

	
	
/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] X x成分.
 * @param[in] Y y成分.
 */
Vector2::Vector2( float X, float Y ) :
	x( X ), y( Y )
{
}



/*===========================================================================*/
/**
 * @brief 0.0に初期化する
 * 
 * @param[in] なし.
 * @return なし.
 */
void Vector2::zero()
{
	x = 0.0f;
	y = 0.0f;
}


	
/*===========================================================================*/
/**
 * @brief 初期化する
 * 
 * @param[in] X x成分.
 * @param[in] Y y成分.
 * @return なし.
 */
void Vector2::initialize(float X, float Y)
{
	x = X;
	y = Y;
}

	
	
/*===========================================================================*/
/**
 * @brief ノルムを求める
 * 
 * @param[in] なし.
 * @return なし.
 */
float Vector2::length() const
{
	return	Ngl::sqrt( x * x + y * y );
}



/*===========================================================================*/
/**
 * @brief 正規化する
 * 
 * @param[in] なし.
 * @return 正規化したベクトル.
 */
Vector2& Vector2::normalize()
{
	float len = length();
	if ( len != 0 ) {
		return *this /= length();
	}
	return *this;
}



/*===========================================================================*/
/**
 * @brief 内積を求める
 * 
 * @param[in] v 内積を求めるベクトル.
 * @return 内積.
 */
float Vector2::dot( const Vector2& v ) const
{
	return	x * v.x + y * v.y;
}



/*===========================================================================*/
/**
 * @brief ベクトル間の距離を求める
 * 
 * @param[in] other 距離を求めるベクトル.
 * @return 求めたベクトル.
 */
float Vector2::distance( const Ngl::Vector2& other )
{
	// 2つのベクトルの差を求める
	Vector2 v = *this - other;

	// ベクトルの長さを返す
	return v.length();
}



/*===========================================================================*/
/**
 * @brief ベクトルの線形補間を行う
 * 
 * @param[in] min 最小値.
 * @param[in] max 最大値.
 * @param[in] t 補間値( 0.0f～1.0f ).
 * @return 結果のベクトル.
 */
Vector2& Vector2::lerp(const Vector2 &min, const Vector2 &max, float t)
{
	x = Ngl::lerp( t, min.x, max.x );
	y = Ngl::lerp( t, min.y, max.y );

	return *this;
}



/*===========================================================================*/
/**
 * @brief ベクトルの2次補間を行う
 * 
 * @param[in] v1 補間要素2次元ベクトル.
 * @param[in] v2 補間要素2次元ベクトル.
 * @param[in] v3 2次元ベクトル.
 * @param[in] t 補間値( 0.0f～1.0f ).
 * @return 結果のベクトル.
 */
Vector2& Vector2::quadratic(const Vector2 &v1, const Vector2 &v2, const Vector2 &v3, float t)
{
	x = Ngl::quadratic( t, v1.x, v2.x, v3.x );
	y = Ngl::quadratic( t, v1.y, v2.y, v3.y );

	return *this;
}



/*===========================================================================*/
/**
 * @brief + 演算子オーバーロード
 * 
 * @param[in] なし.
 * @return なし.
 */
Vector2 Vector2::operator + () const
{
	return	*this;
}



/*===========================================================================*/
/**
 * @brief - 演算子オーバーロード 逆ベクトルを求める
 * 
 * @param[in] なし.
 * @return なし.
 */
Vector2 Vector2::operator - () const
{
	return	Vector2( -x, -y );
}



/*===========================================================================*/
/**
 * @brief += 演算子オーバーロード
 * 
 * @param[in] v 加算するベクトル.
 * @return 加算結果のベクトル.
 */
Vector2& Vector2::operator += ( const Vector2& v )
{
	x += v.x;
	y += v.y;
	return	*this;
}



/*===========================================================================*/
/**
 * @brief -= 演算子オーバーロード
 * 
 * @param[in] v 減算するベクトル.
 * @return 減算結果のベクトル.
 */
Vector2& Vector2::operator -= ( const Vector2& v )
{
	x -= v.x;
	y -= v.y;
	return	*this;
}



/*===========================================================================*/
/**
 * @brief *=演算子オーバーロード
 * 
 * @param[in] v 乗算するベクトル.
 * @return 演算結果のベクトル.
 */
Vector2& Vector2::operator *=(const Ngl::Vector2 &v)
{
	x *= v.x;
	y *= v.y;

	return *this;
}


/*===========================================================================*/
/**
 * @brief *= 演算子オーバーロード
 * 
 * @param[in] s 乗算するスカラー値.
 * @return 乗算結果のベクトル.
 */
Vector2& Vector2::operator *= ( float s )
{
	x *= s;
	y *= s;
	return	*this;
}



/*===========================================================================*/
/**
 * @brief /=演算子オーバーロード
 * 
 * @param[in] v 除算するベクトル.
 * @return 演算結果のベクトル.
 */
Vector2& Vector2::operator /=(const Ngl::Vector2 &v)
{
	x /= v.x;
	y /= v.y;

	return *this;
}



/*===========================================================================*/
/**
 * @brief /= 演算子オーバーロード
 * 
 * @param[in] s 除算するスカラー値.
 * @return 除算結果のベクトル.
 */
Vector2& Vector2::operator /= ( float s )
{
	x /= s;
	y /= s;
	return	*this;
}


/*===========================================================================*/
/**
 * @brief float*演算子オーバーロード
 * 
 * @param[in] なし.
 * @return キャストした値.
 */
Vector2::operator float *() const
{
	return ( float* )this;
}



/*===========================================================================*/
/**
 * @brief float*演算子オーバーロード
 * 
 * @param[in] なし.
 * @return キャストした値.
 */
Vector2::operator const float *() const
{
	return ( const float* )this;
}



/*===========================================================================*/
/**
 * @brief + 演算子オーバーロード
 * 
 * @param[in] v1 加算するベクトル1.
 * @param[in] v2 加算するベクトル2.
 * @return 加算結果のベクトル.
 */
const Vector2 operator + ( const Vector2& v1, const Vector2& v2 )
{
	Vector2	temp(v1);
	return	temp += v2;
}



/*===========================================================================*/
/**
 * @brief - 演算子オーバーロード
 * 
 * @param[in] v1 減算するベクトル1.
 * @param[in] v2 減算するベクトル2.
 * @return 減算結果のベクトル.
 */
const Vector2 operator - ( const Vector2& v1, const Vector2& v2 )
{
	Vector2	temp(v1);
	return	temp -= v2;
}



/*===========================================================================*/
/**
 * @brief *演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v1 演算するベクトル1.
 * @param[in] v2 演算するベクトル2.
 * @return 演算結果のベクトル.
 */
const Vector2 operator * (const Vector2 &v1, const Vector2 &v2)
{
	Vector2 temp(v1);
	return temp *= v2;
}



/*===========================================================================*/
/**
 * @brief * 演算子オーバーロード
 * 
 * @param[in] v 乗算するベクトル.
 * @param[in] s 乗算するスカラー値.
 * @return 乗算結果のベクトル.
 */
const Vector2 operator * ( const Vector2& v, float s )
{
	Vector2	temp(v);
	return	temp *= s;
}



/*===========================================================================*/
/**
 * @brief * 演算子オーバーロード
 * 
 * @param[in] s 乗算するスカラー.
 * @param[in] v 加算するベクトル2.
 * @return 加算結果のベクトル.
 */
const Vector2 operator * ( float s, const Vector2& v )
{
	return	v * s;
}



/*===========================================================================*/
/**
 * @brief /演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v1 演算するベクトル1.
 * @param[in] v2 演算するベクトル2.
 * @return 演算結果のベクトル.
 */
const Vector2 operator / (const Vector2 &v1, const Vector2 &v2)
{
	Vector2 temp( v1 );
	return temp /= v2;
}


/*===========================================================================*/
/**
 * @brief / 演算子オーバーロード
 * 
 * @param[in] v 除算するベクトル.
 * @param[in] s 除算するスカラー.
 * @return 除算結果のベクトル.
 */
const Vector2 operator / ( const Vector2& v, float s )
{
	Vector2	temp(v);
	return	temp /= s;
}



/*===========================================================================*/
/**
 * @brief ==演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値, false 違う値.
 */
bool operator == (const Vector2 &v1, const Vector2 &v2)
{
	return ( v1.x == v2.x && v1.y == v2.y );
}



/*===========================================================================*/
/**
 * @brief !=演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値, false 違う値.
 */
bool operator != (const Vector2 &v1, const Vector2 &v2)
{
	return !( v1 == v2 );
}



/*===========================================================================*/
/**
 * @brief <演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値,
 */
bool operator < (const Vector2 &v1, const Vector2 &v2)
{
	if( v1.x >= v2.x ) return false;
	if( v1.y >= v2.y ) return false;

	return true;
}



/*===========================================================================*/
/**
 * @brief <演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値,
 */
bool operator > (const Vector2 &v1, const Vector2 &v2)
{
	if ( v1.x <= v2.x ) return false;
	if ( v1.y <= v2.y ) return false;

	return	true;
}



/*===========================================================================*/
/**
 * @brief <=演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値,
 */
bool operator <= (const Vector2 &v1, const Vector2 &v2)
{
	return !( v1 > v2 );
}



/*===========================================================================*/
/**
 * @brief >=演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値,
 */
bool operator >= (const Vector2 &v1, const Vector2 &v2)
{
	return !( v1 < v2 );
}



/*========= EOF =============================================================*/