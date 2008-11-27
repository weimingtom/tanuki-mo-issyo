/*******************************************************************************/
/**
 * @file Vector4.cpp.
 * 
 * @brief 4次元ベクトル構造体ソースファイル.
 *
 * @date 2008/07/02.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Vector4.h"
#include	"Ngl/Vector3.h"
#include	"Ngl/Matrix4.h"
#include	"Ngl/MathUtility.h"

using namespace Ngl;


/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
Vector4::Vector4():
	x( 0.0f ),
	y( 0.0f ),
	z( 0.0f ),
	w( 0.0f )
{}



/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] X x値.
 * @param[in] Y y値.
 * @param[in] Z z値.
 * @param[in] W w値.
 */
Vector4::Vector4( float X, float Y, float Z, float W ):
	x( X ),
	y( Y ),
	z( Z ),
	w( W )
{}



/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] V 3次元ベクトル.
 * @param[in] W w値.
 */
Vector4::Vector4( const Vector3& V, float W ):
	x( V.x ),
	y( V.y ),
	z( V.z ),
	w( W )
{}

	
	
/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] other 代入する配列.
 */
Vector4::Vector4( float* other ):
	x( other[ 0 ] ),
	y( other[ 1 ] ),
	z( other[ 2 ] ),
	w( other[ 3 ] )
{}



/*=========================================================================*/
/**
 * @brief 0.0に初期化する
 * 
 * @param[in] なし.
 * @return なし.
 */
void Vector4::zero()
{
	initialize( 0.0f, 0.0f, 0.0f, 0.0f );
}



/*=========================================================================*/
/**
 * @brief 初期化する
 * 
 * @param[in] X x値.
 * @param[in] Y y値.
 * @param[in] Z z値.
 * @param[in] W w値.
 * @return なし.
 */
void Vector4::initialize( float X, float Y, float Z, float W )
{
	x = X;
	y = Y;
	z = Z;
	w = W;
}



/*=========================================================================*/
/**
 * @brief ノルムを求める
 * 
 * @param[in] なし.
 * @return ノルム.
 */
float Vector4::length() const
{
	return Ngl::sqrt( lengthSq() );
}



/*=========================================================================*/
/**
 * @brief ノルムを求める(ルートをとらない)
 * 
 * @param[in] なし.
 * @return ノルム(２乗和のみ).
 */
float Vector4::lengthSq() const
{
	return ( x * x + y * y + z * z + w * w );
}



/*=========================================================================*/
/**
 * @brief 正規化する
 * 
 * @param[in] なし.
 * @return 正規化したベクトル.
 */
Vector4& Vector4::normalize()
{
	float len = length();
	if( len != 0.0f ){
		return *this /= len;
	}
	return *this;
}



/*=========================================================================*/
/**
 * @brief 内積を求める
 * 
 * @param[in] v 計算するベクトル.
 * @return 内積の値.
 */
float Vector4::dot( const Vector4& v ) const
{
	return ( x * v.x + y * v.y + z * v.z + w * v.w );
}
	
	
	
/*=========================================================================*/
/**
 * @brief 仰角と方位角からベクトルを求める
 * 
 * @param[in] elevation 仰角.
 * @param[in] direction 方位角.
 * @return 求めたベクトル.
 */
Vector4& Vector4::fromEleDir( float elevation, float direction )
{
	x =  Ngl::cos( elevation ) * Ngl::sin( direction );
	y = -Ngl::sin( elevation );
	z =  Ngl::cos( elevation ) * Ngl::cos( direction );
	w = 1.0f;

	return *this;
}



/*=========================================================================*/
/**
 * @brief ピッチ角とヨー角からベクトルを求める
 * 
 * @param[in] pitch ピッチ角.
 * @param[in] yaw ヨー角.
 * @return 求めたベクトル.
 */
Vector4& Vector4::fromPitchYaw( float pitch, float yaw )
{
	return fromEleDir( pitch, yaw );
}



/*=========================================================================*/
/**
 * @brief ベクトル同士の距離を求める
 * 
 * @param[in] other 距離を求めるベクトル.
 * @return ベクトルの距離.
 */
float Vector4::distance( const Vector4& other )
{
	Vector4 tmp = *this - other;
	return tmp.length();
}



/*=========================================================================*/
/**
 * @brief ベクトル同士の距離を求める(ルートを取らない)
 * 
 * @param[in] other 距離を求めるベクトル.
 * @return ベクトルの距離(２乗和のみ).
 */
float Vector4::distanceSq( const Vector4& other )
{
	Vector4 tmp = *this - other;
	return tmp.lengthSq();
}


	
/*=========================================================================*/
/**
 * @brief ベクトル同士が作る角度を求める
 * 
 * @param[in] other 角度を求める相手ベクトル.
 * @return 角度.
 */
float Vector4::innerDegree( const Vector3& other )
{
	float cos_theta = dot( other ) / ( length() * other.length() );

	float angle = Ngl::acos( Ngl::clamp( cos_theta, -1.0f, 1.0f ) );

	return	angle;
}

	
	
/*=========================================================================*/
/**
 * @brief 直線の方程式の計算を行う
 * 
 * @param[in] p ベクトル1.
 * @param[in] v ベクトル2.
 * @param[in] t 係数.
 * @return 結果のベクトル.
 */
Vector4 Vector4::linearEquation( const Vector4& p, const Vector4& v, float t )
{
	x = v.x * t + p.x;
	y = v.y * t + p.y;
	z = v.z * t + p.z;
	w = v.w * t + p.w;

	return	*this;
}

	
	
/*=========================================================================*/
/**
 * @brief ベクトルの線形補間を行う
 * 
 * @param[in] min 最小値.
 * @param[in] max 最大値.
 * @param[in] t 補間値( 0.0f～1.0f ).
 * @return 結果のベクトル.
 */
Vector4& Vector4::lerp( const Vector4& min, const Vector4& max, float t )
{
	x = Ngl::leap( t, min.x, max.x );
	y = Ngl::leap( t, min.y, max.y );
	z = Ngl::leap( t, min.z, max.z );
	w = Ngl::leap( t, min.w, max.w );

	return	*this;
}



/*=========================================================================*/
/**
 * @brief ベクトルの2次補間を行う
 * 
 * @param[in] v1 補間要素4次元ベクトル.
 * @param[in] v2 補間要素4次元ベクトル.
 * @param[in] v3 補間要素4次元ベクトル.
 * @param[in] t 補間値( 0.0f～1.0f ).
 * @return 結果のベクトル.
 */
Vector4& Vector4::quadratic( const Vector4& v1, const Vector4& v2, const Vector4& v3, float t )
{
	x = Ngl::quadratic( t, v1.x, v2.x, v3.x );
	y = Ngl::quadratic( t, v1.y, v2.y, v3.y );
	z = Ngl::quadratic( t, v1.z, v2.z, v3.z );
	w = Ngl::quadratic( t, v1.w, v2.w, v3.w );

	return	*this;
}



/*=========================================================================*/
/**
 * @brief ベクトルを座標変換する
 * 
 * @param[in] matrix 変換行列.
 * @return 結果.
 */
Vector4& Vector4::transform( const Matrix4& matrix )
{
	Vector4	v;

	v.x = x * matrix.m[0][0]
	    + y * matrix.m[1][0]
	    + z * matrix.m[2][0]
	    + w * matrix.m[3][0];

	v.y = x * matrix.m[0][1]
	    + y * matrix.m[1][1]
	    + z * matrix.m[2][1]
	    + w * matrix.m[3][1];

	v.z = x * matrix.m[0][2]
	    + y * matrix.m[1][2]
	    + z * matrix.m[2][2]
	    + w * matrix.m[3][2];

	v.w = x * matrix.m[0][3]
	    + y * matrix.m[1][3]
	    + z * matrix.m[2][3]
	    + w * matrix.m[3][3];

	*this = v;

	return	*this;
}


	
/*=========================================================================*/
/**
 * @brief ＋演算子オーバーロード
 * 
 * @param[in] なし.
 * @return 意味なし.
 */
Vector4	Vector4::operator + () const
{
	return *this;
}



/*=========================================================================*/
/**
 * @brief -演算子オーバーロード
 * 
 * @param[in] なし.
 * @return 逆ベクトル.
 */
Vector4	Vector4::operator - () const
{
	return Vector4( -x, -y, -z, -w );
}



/*=========================================================================*/
/**
 * @brief +=演算子オーバーロード
 * 
 * @param[in] v 加算するベクトル.
 * @return 演算結果のベクトル.
 */
Vector4& Vector4::operator += ( const Vector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;

	return *this;
}



/*=========================================================================*/
/**
 * @brief -=演算子オーバーロード
 * 
 * @param[in] v 減算するベクトル.
 * @return 演算結果のベクトル.
 */
Vector4& Vector4::operator -= ( const Vector4& v )
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;

	return *this;
}



/*=========================================================================*/
/**
 * @brief *=演算子オーバーロード
 * 
 * @param[in] v 乗算するベクトル.
 * @return 演算結果のベクトル.
 */
Vector4& Vector4::operator *= ( const Vector4& v )
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	w *= v.w;

	return *this;
}



/*=========================================================================*/
/**
 * @brief *=演算子オーバーロード
 * 
 * @param[in] s 乗算するスカラー.
 * @return 演算結果のベクトル.
 */
Vector4& Vector4::operator *= ( float s )
{
	x *= s;
	y *= s;
	z *= s;
	w *= s;

	return *this;
}



/*=========================================================================*/
/**
 * @brief /=演算子オーバーロード
 * 
 * @param[in] v 除算するベクトル.
 * @return 演算結果のベクトル.
 */
Vector4& Vector4::operator /= ( const Vector4& v )
{
	x /= v.x;
	y /= v.y;
	z /= v.z;
	w /= v.w;

	return *this;
}



/*=========================================================================*/
/**
 * @brief /=演算子オーバーロード
 * 
 * @param[in] s 除算するスカラー.
 * @return 演算結果のベクトル.
 */
Vector4& Vector4::operator /= ( float s )
{
	x /= s;
	y /= s;
	z /= s;
	w /= s;

	return *this;
}


	
/*=========================================================================*/
/**
 * @brief float*演算子オーバーロード
 * 
 * @param[in] なし.
 * @return キャストした値.
 */
Vector4::operator float* () const
{
	return (float*)this;
}



/*=========================================================================*/
/**
 * @brief const float*演算子オーバーロード
 * 
 * @param[in] なし.
 * @return キャストした値.
 */
Vector4::operator const float* () const
{
	return (const float*)this;
}



/*===========================================================================*/
/**
 * @brief +演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v1 演算するベクトル1.
 * @param[in] v2 演算するベクトル2.
 * @return 演算結果のベクトル.
 */
const Ngl::Vector4 operator + ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 )
{
	Vector4 tmp( v1 );
	return tmp += v2;
}



/*===========================================================================*/
/**
 * @brief -演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v1 演算するベクトル1.
 * @param[in] v2 演算するベクトル2.
 * @return 演算結果のベクトル.
 */
const Ngl::Vector4 operator - ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 )
{
	Vector4 tmp( v1 );
	return tmp -= v2;
}



/*===========================================================================*/
/**
 * @brief *演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v1 演算するベクトル1.
 * @param[in] v2 演算するベクトル2.
 * @return 演算結果のベクトル.
 */
const Ngl::Vector4 operator * ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 )
{
	Vector4 tmp( v1 );
	return tmp *= v2;
}



/*===========================================================================*/
/**
 * @brief *演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v 演算するベクトル1.
 * @param[in] s 演算するスカラー.
 * @return 演算結果のベクトル.
 */
const Ngl::Vector4 operator * ( const Ngl::Vector4& v, float s )
{
	Vector4 tmp( v );
	return tmp *= s;
}



/*===========================================================================*/
/**
 * @brief *演算子オーバーロード　非メンバ関数
 * 
 * @param[in] s 演算するスカラー.
 * @param[in] v 演算するベクトル.
 * @return 演算結果のベクトル.
 */
const Ngl::Vector4 operator * ( float s, const Ngl::Vector4& v )
{
	return v * s;
}



/*===========================================================================*/
/**
 * @brief /演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v1 演算するベクトル1.
 * @param[in] v2 演算するベクトル2.
 * @return 演算結果のベクトル.
 */
const Ngl::Vector4 operator / ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 )
{
	Vector4 tmp( v1 );
	return tmp /= v2;
}



/*===========================================================================*/
/**
 * @brief /演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v 演算するベクトル.
 * @param[in] s 演算するスカラー.
 * @return 演算結果のベクトル.
 */
const Ngl::Vector4 operator / ( const Ngl::Vector4& v, float s )
{
	Vector4 tmp( v );
	return tmp /= s;
}



/*=========================================================================*/
/**
 * @brief ==演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値, false 違う値.
 */
bool operator == ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 )
{
	return ( v1.x == v2.x && v1.y == v2.y && v1.z == v2.z && v1.w == v2.w );
}



/*=========================================================================*/
/**
 * @brief !=演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値, false 違う値.
 */
bool operator != ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 )
{
	return !( v1 == v2 );
}



/*=========================================================================*/
/**
 * @brief <演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値,
 */
bool operator < ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 )
{
	if( v1.x >= v2.x ) return false;
	if( v1.y >= v2.y ) return false;
	if( v1.z >= v2.z ) return false;
	if( v1.w >= v2.w ) return false;

	return true;
}



/*=========================================================================*/
/**
 * @brief <演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値,
 */
bool operator > ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 )
{
	if ( v1.x <= v2.x ) return false;
	if ( v1.y <= v2.y ) return false;
	if ( v1.z <= v2.z ) return false;
	if ( v1.w <= v2.w ) return false; 

	return	true;
}



/*=========================================================================*/
/**
 * @brief <=演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値,
 */
bool operator <= ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 )
{
	return !( v1 > v2 );
}



/*=========================================================================*/
/**
 * @brief >=演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値,
 */
bool operator >= ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 )
{
	return !( v1 < v2 );
}



/*===== EOF ==================================================================*/