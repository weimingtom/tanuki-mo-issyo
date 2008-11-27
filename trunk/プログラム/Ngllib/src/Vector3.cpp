/*******************************************************************************/
/**
 * @file Vector3.cpp.
 * 
 * @brief 3次元ベクトル構造体ソースファイル.
 *
 * @date 2008/06/23.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	<Ngl/Vector3.h>
#include	<Ngl/Matrix4.h>
#include	<Ngl/MathUtility.h>

using namespace Ngl;

/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] 引数名 引数説明.
 */
Vector3::Vector3() :
	x(0.0f),
	y(0.0f),
	z(0.0f)
{
}



/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] other 配列のポインタ.
 */
Vector3::Vector3(const float* other)
{
	x = other[0];
	y = other[1];
	z = other[2];
}



/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] X x値.
 * @param[in] Y y値.
 * @param[in] Z z値.
 */
Vector3::Vector3(float X, float Y, float Z) :
	x(X), y(Y), z(Z)
{}
	
	

/*===========================================================================*/
/**
 * @brief 0.0に初期化する
 * 
 * @param[in] なし.
 * @return なし.
 */
void Vector3::zero()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}



/*===========================================================================*/
/**
 * @brief 初期化する
 * 
 * @param[in] X x値.
 * @param[in] Y y値.
 * @param[in] Z z値.
 * @return なし.
 */
void Vector3::initialize(float X, float Y, float Z)
{
	x = X;
	y = Y;
	z = Z;
}

	
	
/*===========================================================================*/
/**
 * @brief ノルムを求める
 * 
 * @param[in] なし.
 * @return ノルム.
 */
float Vector3::length() const
{
	return Ngl::sqrt( lengthSq() );
}



/*===========================================================================*/
/**
 * @brief ノルムを求める(ルートをとらない)
 * 
 * @param[in] なし.
 * @return ノルム(２乗和のみ).
 */
float Vector3::lengthSq() const
{
	return (x * x + y * y + z * z);
}



/*===========================================================================*/
/**
 * @brief 正規化する
 * 
 * @param[in] なし.
 * @return 正規化したベクトル.
 */
Vector3& Vector3::normalize()
{
	float len = length();
	if( len != 0.0f ){
		return *this /= len;
	}
	return *this;
}



/*===========================================================================*/
/**
 * @brief 内積を求める
 * 
 * @param[in] v 計算するベクトル.
 * @return 内積の値.
 */
float Vector3::dot(const Vector3& v) const
{
	return x * v.x + y * v.y + z * v.z;
}



/*===========================================================================*/
/**
 * @brief 外積の値を求める
 * 
 * @param[in] v 計算するベクトル.
 * @return 外積の値.
 */
Vector3 Vector3::cross(const Vector3& v) const
{
	Vector3 temp;
	
	temp.x = y * v.z - z * v.y;
	temp.y = z * v.x - x * v.z;
	temp.z = x * v.y - y * v.x;

	return temp;

}



/*===========================================================================*/
/**
 * @brief 仰角と方位角からベクトルを求める
 * 
 * @param[in] elevation 仰角.
 * @param[in] direction 方位角.
 * @return 求めたベクトル.
 */
Vector3& Vector3::fromEleDir( float elevation, float direction )
{
	x = Ngl::cos( elevation ) * Ngl::sin( direction );
	y = -Ngl::sin( elevation );
	z = Ngl::cos( elevation ) * Ngl::cos( direction );

	return *this;
}



/*===========================================================================*/
/**
 * @brief ピッチ角とヨー角からベクトルを求める
 * 
 * @param[in] pitch ピッチ角.
 * @param[in] yaw ヨー角.
 * @return 求めたベクトル.
 */
Vector3& Vector3::fromPitchYaw( float pitch, float yaw )
{
	return fromEleDir( pitch, yaw );
}



/*===========================================================================*/
/**
 * @brief ベクトル間の距離を求める
 * 
 * @param[in] other 距離を求めるベクトル.
 * @return 求めたベクトル.
 */
float Vector3::distance( const Vector3& other )
{
	// 2つのベクトルの差を求める
	Vector3 v = *this - other;

	// ベクトルの長さを返す
	return v.length();
}



/*===========================================================================*/
/**
 * @brief ベクトル同士の距離を求める(ルートを取らない)
 * 
 * @param[in] other 距離を求めるベクトル.
 * @return ベクトルの距離(２乗和のみ).
 */
float Vector3::distanceSq(const Vector3 &other)
{
	// 2つのベクトルの差を求める
	Vector3 v = *this - other;

	return v.lengthSq();
}



/*===========================================================================*/
/**
 * @brief ベクトル同士が作る角度を求める
 * 
 * @param[in] other 角度を求める相手ベクトル.
 * @return 角度.
 */
float Vector3::innerDegree(const Vector3& other)
{
	float cos_Theta = dot( other ) / length() * other.length();

	float angle = Ngl::acos( Ngl::clamp( cos_Theta, -1.0f, 1.0f ) );

	return angle;
}


/*===========================================================================*/
/**
 * @brief 面法線を求める
 * 
 * @param[in] vec1 頂点.
 * @param[in] vec2 頂点.
 * @return 法線ベクトル.
 */
Vector3 Vector3::calculateNoamal(const Vector3 &vec1, const Vector3 &vec2)
{
	Vector3 vv1 = *this - vec1;
	Vector3 vv2 = vec1 - vec2;

	// ベクトルの外積を求める
	Vector3 c = vv1.cross( vv2 );

	// ベクトルを正規化する
	c = c.normalize();

	return c;
}



/*===========================================================================*/
/**
 * @brief 直線の方程式の計算を行う
 * 
 * @param[in] p ベクトル1.
 * @param[in] v ベクトル2.
 * @param[in] t 係数.
 * @return 結果のベクトル.
 */
Vector3 Vector3::linearEquation(const Vector3 &p, const Vector3 &v, float t )
{
	x = v.x * t + p.x;
	y = v.y * t + p.y;
	z = v.z * t + p.z;

	return *this;
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
Vector3& Vector3::lerp(const Vector3 &min, const Vector3 &max, float t)
{
	x = Ngl::leap( t, min.x, max.x );
	y = Ngl::leap( t, min.y, max.y );
	z = Ngl::leap( t, min.z, max.z );

	return *this;
}



/*===========================================================================*/
/**
 * @brief ベクトルの2次補間を行う
 * 
 * @param[in] v1 補間要素3次元ベクトル.
 * @param[in] v2 補間要素3次元ベクトル.
 * @param[in] v3 3次元ベクトル.
 * @param[in] t 補間値( 0.0f～1.0f ).
 * @return 結果のベクトル.
 */
Vector3& Vector3::quadratic(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3, float t)
{
	x = Ngl::quadratic( t, v1.x, v2.x, v3.x );
	y = Ngl::quadratic( t, v1.y, v2.y, v3.y );
	z = Ngl::quadratic( t, v1.z, v2.z, v3.z );

	return *this;
}



/*===========================================================================*/
/**
 * @brief ベクトルを座標変換する
 * 
 * @param[in] matrix 変換行列.
 * @return 結果.
 */
Vector3& Vector3::transform(const Matrix4 &matrix)
{
	Ngl::Vector3 v;

	// 各成分を座標変換
	v.x = x * matrix.m[0][0] +
		  y * matrix.m[1][0] +
		  z * matrix.m[2][0] +
		  matrix.m[3][0];

	v.y = x * matrix.m[0][1] +
		  y * matrix.m[1][1] +
		  z * matrix.m[2][1] +
		  matrix.m[3][1];

	v.z = x * matrix.m[0][2] +
		  y * matrix.m[1][2] +
		  z * matrix.m[2][2] +
		  matrix.m[3][2];

	// ベクトルを設定
	*this = v;

	return *this;
}



/*===========================================================================*/
/**
 * @brief 法線ベクトルを座標変換する
 * 
 * @param[in] matrix 変換行列.
 * @return 結果.
 */
Vector3& Vector3::transformNormal(const Matrix4 &matrix)
{
	Vector3 v;

	// 各成分を座標変換
	v.x = x * matrix.m[0][0] +
		  y * matrix.m[1][0] +
		  z * matrix.m[2][0];

	v.y = x * matrix.m[0][1] +
		  y * matrix.m[1][1] +
		  z * matrix.m[2][1];

	v.z = x * matrix.m[0][2] +
		  y * matrix.m[1][2] +
		  z * matrix.m[2][2];

	// ベクトルを設定
	*this = v;

	return *this;
}



/*===========================================================================*/
/**
 * @brief ＋演算子オーバーロード
 * 
 * @param[in] なし.
 * @return 意味なし.
 */
Vector3 Vector3::operator + () const
{
	return *this;
}



/*===========================================================================*/
/**
 * @brief -演算子オーバーロード
 * 
 * @param[in] なし.
 * @return 逆ベクトル.
 */
Vector3 Vector3::operator - () const
{
	return Vector3(-x, -y, -z);
}



/*===========================================================================*/
/**
 * @brief +=演算子オーバーロード
 * 
 * @param[in] v 加算するベクトル.
 * @return 演算結果のベクトル.
 */
Vector3& Vector3::operator += (const Vector3& v)
{
	x += v.x;
	y += v.y;
	z += v.z;

	return *this;
}



/*===========================================================================*/
/**
 * @brief -=演算子オーバーロード
 * 
 * @param[in] v 減算するベクトル.
 * @return 演算結果のベクトル.
 */
Vector3& Vector3::operator -= (const Vector3& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;

	return *this;
}



/*===========================================================================*/
/**
 * @brief *=演算子オーバーロード
 * 
 * @param[in] v 乗算するベクトル.
 * @return 演算結果のベクトル.
 */
Vector3& Vector3::operator *=(const Ngl::Vector3 &v)
{
	x *= v.x;
	y *= v.y;
	z *= v.z;

	return *this;
}


/*===========================================================================*/
/**
 * @brief *=演算子オーバーロード
 * 
 * @param[in] s 乗算するスカラー.
 * @return 演算結果のベクトル.
 */
Vector3& Vector3::operator *= (float s)
{
	x *= s;
	y *= s;
	z *= s;

	return *this;
}



/*===========================================================================*/
/**
 * @brief /=演算子オーバーロード
 * 
 * @param[in] v 除算するベクトル.
 * @return 演算結果のベクトル.
 */
Vector3& Vector3::operator /=(const Ngl::Vector3 &v)
{
	x /= v.x;
	y /= v.y;
	z /= v.z;

	return *this;
}



/*===========================================================================*/
/**
 * @brief /=演算子オーバーロード
 * 
 * @param[in] s 除算するスカラー.
 * @return 演算結果のベクトル.
 */
Vector3& Vector3::operator /= (float s)
{
	x /= s;
	y /= s;
	z /= s;

	return *this;
}



/*===========================================================================*/
/**
 * @brief float*演算子オーバーロード
 * 
 * @param[in] なし.
 * @return キャストした値.
 */
Vector3::operator float *() const
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
Vector3::operator const float *() const
{
	return ( const float* )this;
}



/*===========================================================================*/
/**
 * @brief +演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v1 演算するベクトル1.
 * @param[in] v2 演算するベクトル2.
 * @return 演算結果のベクトル.
 */
const Vector3 operator + (const Vector3& v1, const Vector3& v2)
{
	Vector3 temp(v1);
	return temp += v2;
}



/*===========================================================================*/
/**
 * @brief -演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v1 演算するベクトル1.
 * @param[in] v2 演算するベクトル2.
 * @return 演算結果のベクトル.
 */
const Vector3 operator - (const Vector3& v1, const Vector3& v2)
{
	Vector3 temp(v1);
	return temp -= v2;
}



/*===========================================================================*/
/**
 * @brief *演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v1 演算するベクトル1.
 * @param[in] v2 演算するベクトル2.
 * @return 演算結果のベクトル.
 */
const Vector3 operator * (const Vector3 &v1, const Vector3 &v2)
{
	Vector3 temp(v1);
	return temp *= v2;
}



/*===========================================================================*/
/**
 * @brief *演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v 演算するベクトル1.
 * @param[in] s 演算するスカラー.
 * @return 演算結果のベクトル.
 */
const Vector3 operator * (const Vector3& v, float s)
{
	Vector3 temp(v);
	return temp *= s;
}



/*===========================================================================*/
/**
 * @brief *演算子オーバーロード　非メンバ関数
 * 
 * @param[in] s 演算するスカラー.
 * @param[in] v 演算するベクトル.
 * @return 演算結果のベクトル.
 */
const Vector3 operator * (float s, const Vector3& v)
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
const Vector3 operator / (const Vector3 &v1, const Vector3 &v2)
{
	Vector3 tmp( v1 );
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
const Vector3 operator / (const Vector3& v, float s)
{
	Vector3 temp(v);
	return temp /= s;
}



/*===========================================================================*/
/**
 * @brief ==演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値, false 違う値.
 */
bool operator == (const Vector3 &v1, const Vector3 &v2)
{
	return ( v1.x == v2.x && v1.y == v2.y && v1.z == v2.z );
}



/*===========================================================================*/
/**
 * @brief !=演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値, false 違う値.
 */
bool operator != (const Vector3 &v1, const Vector3 &v2)
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
bool operator < (const Vector3 &v1, const Vector3 &v2)
{
	if( v1.x >= v2.x ) return false;
	if( v1.y >= v2.y ) return false;
	if( v1.z >= v2.z ) return false;

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
bool operator > (const Vector3 &v1, const Vector3 &v2)
{
	if ( v1.x <= v2.x ) return false;
	if ( v1.y <= v2.y ) return false;
	if ( v1.z <= v2.z ) return false;

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
bool operator <= (const Vector3 &v1, const Vector3 &v2)
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
bool operator >= (const Vector3 &v1, const Vector3 &v2)
{
	return !( v1 < v2 );
}



/*========= EOF =============================================================*/