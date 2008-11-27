/*******************************************************************************/
/**
 * @file Quaternion.cpp.
 * 
 * @brief クォータニオン構造体ソースファイル.
 *
 * @date 2007/09/01.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Quaternion.h"
#include	"Ngl/Vector3.h"
#include	"Ngl/Matrix4.h"
#include	"Ngl/MathUtility.h"
#include	<cmath>

using namespace Ngl;


/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
Quaternion::Quaternion()
{
	// 単位クォータニオンにする
	setIdentity();
}



/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] X x成分.
 * @param[in] Y y成分.
 * @param[in] Z z成分.
 * @param[in] W w成分.
 */
Quaternion::Quaternion(float X, float Y, float Z, float W):
	x( X ),	// x成分
	y( Y ), // y成分
	z( Z ),	// z成分
	w( W )	// 回転角度
{}



/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] aNgle 回転角度.
 * @param[in] axis 軸.
 */
Quaternion::Quaternion(float aNgle, const Ngl::Vector3 &axis)
{
	// 回転角度からクォータニオンを作成する
	fromRotate( aNgle, axis );
}


	
/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] m 回転行列.
 */
Quaternion::Quaternion(const Ngl::Matrix4 &m)
{
	// 回転行列を空クォータニオンを作成する
	setMatrix( m );
}



/*===========================================================================*/
/**
 * @brief 単位クォータニオン化する
 * 
 * @param[in] なし.
 * @return 単位クォータニオン化したクォータニオン.
 */
Quaternion& Quaternion::setIdentity()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 1.0f;

	return *this;
}



/*===========================================================================*/
/**
 * @brief 正規化をする
 * 
 * @param[in] なし.
 * @return 正規化したクォータニオン.
 */
Quaternion& Quaternion::normalize()
{
	// 長さを求める
	float len = length();
	len = ( len > 0.0f ) ? ( 1.0f / len ) : 0.0f;

	// 各成分と乗算する
	x *= len;
	y *= len;
	z *= len;
	w *= len;

	return *this;
}



/*===========================================================================*/
/**
 * @brief 内積を求める
 * 
 * @param[in]  q 内積を求めるクォータニオン.
 * @return 内積の値.
 */
float Quaternion::dot(const Ngl::Quaternion &q) const
{
	return x * q.x + y * q.y + z * q.z + w * q.w;
}



/*===========================================================================*/
/**
 * @brief 長さを求める
 * 
 * @param[in] なし.
 * @return 長さの値.
 */
float Quaternion::length() const
{
	return dot( *this );
}



/*===========================================================================*/
/**
 * @brief 逆クォータニオン化する
 * 
 * @param[in] なし.
 * @return 逆クォータニオン化したクォータニオン.
 */
Quaternion& Quaternion::inverse()
{
	// 長さを求める
	float len = length();
	len = ( len > 0.0f ) ? ( 1.0f / len ) : 0.0f;

	// 各成分を反転して長さを乗算する
	x = -x * len;
	y = -y * len;
	z = -z * len;
	w = -w * len;

	return *this;
}



/*===========================================================================*/
/**
 * @brief 回転角度からクォータニオンを取得する
 * 
 * @param[in] aNgle 回転角度.
 * @param[in] vx x成分.
 * @param[in] vy y成分.
 * @param[in] vz z成分.
 * @return 取得したクォータニオン.
 */
Quaternion& Quaternion::fromRotate(float aNgle, float vx, float vy, float vz)
{
	x = Ngl::sin( aNgle / 2.0f ) * vx;
	y = Ngl::sin( aNgle / 2.0f ) * vy;
	z = Ngl::sin( aNgle / 2.0f ) * vz;
	w = Ngl::cos( aNgle / 2.0f );

	return *this;
}



/*===========================================================================*/
/**
 * @brief 回転角度からクォータニオンを取得する
 * 
 * @param[in] aNgle 回転角度.
 * @param[in] axis 軸.
 * @return 取得したクォータニオン.
 */
Quaternion& Quaternion::fromRotate(float aNgle, const Ngl::Vector3 &axis)
{
	return fromRotate( aNgle, axis.x, axis.y, axis.z );
}



/*===========================================================================*/
/**
 * @brief ヨー・ピッチ・ロールからクォータニオンを取得する
 * 
 * @param[in] yaw ヨー角.
 * @param[in] pitch ピッチ角.
 * @param[in] roll ロール角.
 * @return 取得したクォータニオン.
 */
Quaternion& Quaternion::fromYawPitchRoll(float yaw, float pitch, float roll)
{
	// ヨーピッチロールの正弦値を求める
	float fSinYaw	= Ngl::sin( yaw	/ 2.0f );
	float fSinPitch	= Ngl::sin( pitch	/ 2.0f );
	float fSinRoll	= Ngl::sin( roll	/ 2.0f );
	
	// ヨーピッチロールの余弦値を求める
	float fCosYaw	= Ngl::cos( yaw	/ 2.0f );
	float fCosPitch	= Ngl::cos( pitch	/ 2.0f );
	float fCosRoll	= Ngl::cos( roll	/ 2.0f );

	x = fSinRoll * fCosPitch * fCosYaw - fCosRoll * fSinPitch * fSinYaw;
	y = fCosRoll * fSinPitch * fCosYaw + fSinRoll * fCosPitch * fSinYaw;
	z = fCosRoll * fCosPitch * fSinYaw - fSinRoll * fSinPitch * fCosYaw;
	w = fCosRoll * fCosPitch * fCosYaw + fSinRoll * fSinPitch * fSinYaw;

	return *this;
}



/*===========================================================================*/
/**
 * @brief 回転行列を設定する
 * 
 * @param[in] mat 回転行列.
 * @return 設定したクォータニオン.
 */
Quaternion& Quaternion::setMatrix(const Ngl::Matrix4 &mat)
{
	float tr = mat.m[0][0] + mat.m[1][1] + mat.m[2][2] + mat.m[3][3];

	if( tr >= 1.0f ){
		float fourD = 2.0f * Ngl::sqrt( tr );
		w = fourD / 4.0f;
		x = ( mat.m[1][2] - mat.m[2][1] ) / fourD;
		y = ( mat.m[2][0] - mat.m[0][2] ) / fourD;
		z = ( mat.m[0][1] - mat.m[1][0] ) / fourD;
	}
	else{
		float pa[4];
		int i = 0;

		if( mat.m[0][0] > mat.m[1][1] ){
			i = 0;
		}
		else{
			i = 1;
		}
		if( mat.m[2][2] > mat.m[i][i] ){
			i = 2;
		}

		int j = ( i + 1 ) % 3;
		int k = ( j + 1 ) % 3;

		tr = mat.m[i][i] + mat.m[j][j] + mat.m[k][k] + 1.0f;
		float fourD = 2.0f * Ngl::sqrt( tr );

		pa[i] = fourD / 4.0f;
		pa[j] = ( mat.m[j][i] + mat.m[i][j] ) / fourD;
		pa[k] = ( mat.m[k][i] + mat.m[i][k] ) / fourD;
		pa[3] = ( mat.m[j][k] - mat.m[k][j] ) / fourD;

		x = pa[0];
		y = pa[1];
		z = pa[2];
		w = pa[3];
	}

	return *this;
}



/*===========================================================================*/
/**
 * @brief 軸を取得する
 * 
 * @param[in] なし.
 * @return 軸の値.
 */
Ngl::Vector3 Quaternion::getAxis() const
{
	// 角度を取得する
	float aNgle = getANgle();

	// 軸成分を求める
	Ngl::Vector3 tmp;
	tmp.x = x / Ngl::sin( aNgle / 2.0f );
	tmp.y = y / Ngl::sin( aNgle / 2.0f );
	tmp.z = z / Ngl::sin( aNgle / 2.0f );

	return tmp;
}



/*===========================================================================*/
/**
 * @brief 角度を取得する
 * 
 * @param[in] なし.
 * @return 角度の値.
 */
float Quaternion::getANgle() const
{
	return Ngl::acos( w ) * 2.0f;
}



/*===========================================================================*/
/**
 * @brief ヨー角を取得する
 * 
 * @param[in] なし.
 * @return ヨー角の値.
 */
float Quaternion::getYaw() const
{
	return Ngl::atan( 2.0f * ( y*z + w*x ), w*w - x*x - y*y - z*z );
}



/*===========================================================================*/
/**
 * @brief ピッチ角を取得する
 * 
 * @param[in] なし.
 * @return ピッチ角の値.
 */
float Quaternion::getPitch() const
{
	return Ngl::degreeNormalize( Ngl::asin( -2.0f * ( x*z  - w*y  ) ) );
}



/*===========================================================================*/
/**
 * @brief ロール角を取得する
 * 
 * @param[in] なし.
 * @return ロール角の値.
 */
float Quaternion::getRoll() const
{
	return Ngl::atan( 2.0f * ( x*y + w*z ), w*w - x*x - y*y - z*z );
}



/*===========================================================================*/
/**
 * @brief 線形補間する
 * 
 * @param[in] q1 補間要素のクォータニオン１.
 * @param[in] q2 補間要素のクォータニオン２.
 * @param[in] t 補間値.
 * @return なし.
 */
Quaternion& Quaternion::lerp(const Ngl::Quaternion &q1, const Ngl::Quaternion &q2, float t)
{
	x = Ngl::leap( t, q1.x, q2.x );
	y = Ngl::leap( t, q1.y, q2.y );
	z = Ngl::leap( t, q1.z, q2.z );
	w = Ngl::leap( t, q1.w, q2.w );

	return *this;
}



/*===========================================================================*/
/**
 * @brief 球形線形補間する
 * 
 * @param[in] q1 補間要素のクォータニオン１.
 * @param[in] q2 補間要素のクォータニオン２.
 * @param[in] t 補間値.
 * @return なし.
 */
Quaternion& Quaternion::slerp( const Quaternion& q1, const Quaternion& q2, float t )
{
	float fCosTheta = q1.x * q2.x + q1.y * q2.y + q1.z * q2.z + q1.w * q2.w;

	Quaternion tb;
	if( fCosTheta < 0.0f ){
		fCosTheta	= -fCosTheta;
		tb.x		= -q2.x;
		tb.y		= -q2.y;
		tb.z		= -q2.z;
		tb.w		= -q2.w;
	}
	else{
		tb = q2;
	}

	float fBeta = 1.0f - t;

	if( ( 1.0f - fCosTheta ) > 0.001f ){
		float fTheta = (float)std::acos( fCosTheta );

		fBeta	= (float)( std::sin( fTheta * fBeta ) / std::sin( fTheta ) );
		t		= (float)( std::sin( fTheta * t		) / std::sin( fTheta ) );
	}

	x = fBeta * q1.x + t * tb.x;
	y = fBeta * q1.y + t * tb.y;
	z = fBeta * q1.z + t * tb.z;
	w = fBeta * q1.w + t * tb.w;

	(*this).normalize();

	return *this;
}



/*===========================================================================*/
/**
 * @brief 2次補間する
 * 
 * @param[in] q1 補間要素のクォータニオン1.
 * @param[in] q2 補間要素のクォータニオン2.
 * @param[in] q3 補間要素のクォータニオン3.
 * @param[in] t 補完度.
 * @return 補完したクォータニオン.
 */
Quaternion& Quaternion::quadratic(const Ngl::Quaternion &q1, const Ngl::Quaternion &q2, const Ngl::Quaternion &q3, float t)
{
	x = Ngl::quadratic( t, q1.x, q2.x, q3.x );
	y = Ngl::quadratic( t, q1.y, q2.y, q3.y );
	z = Ngl::quadratic( t, q1.z, q2.z, q3.z );
	w = Ngl::quadratic( t, q1.w, q2.w, q3.w );

	return *this;
}


/*===========================================================================*/
/**
 * @brief + 演算子オーバーロード
 * 
 * @param[in] なし.
 * @return 演算結果のクォータニオン.
 */
Quaternion Quaternion::operator +() const
{
	return *this;
}



/*===========================================================================*/
/**
 * @brief - 演算子オーバーロード
 * 
 * @param[in] なし.
 * @return 演算結果のクォータニオン.
 */
Quaternion Quaternion::operator -() const
{
	return Quaternion( -x, -y, -z, -w );
}



/*===========================================================================*/
/**
 * @brief += 演算子オーバーロード
 * 
 * @param[in] q 演算するクォータニオン.
 * @return 演算結果のクォータニオン.
 */
Quaternion& Quaternion::operator +=(const Ngl::Quaternion &q)
{
	x = x + q.x;
	y = y + q.y;
	z = z + q.z;
	w = w + q.w;

	return *this;
}



/*===========================================================================*/
/**
 * @brief -= 演算子オーバーロード
 * 
 * @param[in] q 演算するクォータニオン.
 * @return 演算結果のクォータニオン.
 */
Quaternion& Quaternion::operator -=(const Ngl::Quaternion &q)
{
	x = x - q.x;
	y = y - q.y;
	z = z - q.z;
	w = w - q.w;

	return *this;
}



/*===========================================================================*/
/**
 * @brief *= 演算子オーバーロード
 * 
 * @param[in] q 演算するクォータニオン.
 * @return 演算結果のクォータニオン.
 */
Quaternion& Quaternion::operator *=(const Ngl::Quaternion &q)
{
	x =  x * q.w + y * q.z + z * q.y + w * q.x;
	y = -x * q.z + y * q.w + z * q.x + w * q.y;
	z =  x * q.y + y * q.x + z * q.w + w * q.z;
	w = -x * q.x + y * q.y + z * q.z + w * q.w;

	return *this;
}



/*===========================================================================*/
/**
 * @brief *= 演算子オーバーロード
 * 
 * @param[in] s 演算するスカラー.
 * @return 演算結果のクォータニオン.
 */
Quaternion& Quaternion::operator *=(float s)
{
	x = x * s;
	y = y * s;
	z = z * s;
	w = w * s;

	return *this;
}



/*===========================================================================*/
/**
 * @brief /= 演算子オーバーロード
 * 
 * @param[in] s 演算するスカラー.
 * @return 演算結果のクォータニオン.
 */
Quaternion& Quaternion::operator /=(float s)
{
	return ( *this *= ( 1.0f / s ) );
}



/*=========================================================================*/
/**
 * @brief + 演算子オーバーロード 非メンバ関数
 * 
 * @param[in] q1 演算するクォータニオン1.
 * @param[in] q2 演算するクォータニオン2.
 * @return 演算結果のクォータニオン.
 */
Quaternion operator + ( const Quaternion& q1, const Quaternion& q2 )
{
	Quaternion tmp( q1 );
	return tmp += q2;
}



/*=========================================================================*/
/**
 * @brief - 演算子オーバーロード 非メンバ関数
 * 
 * @param[in] q1 演算するクォータニオン1.
 * @param[in] q2 演算するクォータニオン2.
 * @return 演算結果のクォータニオン.
 */
Quaternion operator - ( const Quaternion& q1, const Quaternion& q2 )
{
	Quaternion tmp( q1 );
	return tmp -= q2;
}



/*=========================================================================*/
/**
 * @brief * 演算子オーバーロード 非メンバ関数
 * 
 * @param[in] q1 演算するクォータニオン1.
 * @param[in] q2 演算するクォータニオン2.
 * @return 演算結果のクォータニオン.
 */
Quaternion operator * ( const Quaternion& q1, const Quaternion& q2 )
{
	Quaternion tmp( q1 );
	return tmp *= q2;
}



/*=========================================================================*/
/**
 * @brief * 演算子オーバーロード 非メンバ関数
 * 
 * @param[in] q 演算するクォータニオン.
 * @param[in] s 演算するスカラー.
 * @return 演算結果のクォータニオン.
 */
Quaternion operator * ( const Quaternion& q, float s )
{
	Quaternion tmp( q );
	return tmp *= s;
}



/*=========================================================================*/
/**
 * @brief += 演算子オーバーロード 非メンバ関数
 * 
 * @param[in] s 演算するスカラー.
 * @param[in] q 演算するクォータニオン.
 * @return 演算結果のクォータニオン.
 */
Quaternion operator * ( float s, const Quaternion& q )
{
	return q * s;
}



/*=========================================================================*/
/**
 * @brief == 演算子オーバーロード 非メンバ関数
 * 
 * @param[in] q1 演算するクォータニオン1.
 * @param[in] q2 演算するクォータニオン2.
 * @return true 一致している false 一致していない.
 */
bool operator == ( const Quaternion& q1, const Quaternion& q2 )
{
	return ( q1.x == q2.x && q1.y == q2.y && q1.z == q2.z && q1.w == q2.w );
}



/*=========================================================================*/
/**
 * @brief != 演算子オーバーロード 非メンバ関数
 * 
 * @param[in] q1 演算するクォータニオン1.
 * @param[in] q2 演算するクォータニオン2.
 * @return true 一致していない false 一致している.
 */
bool operator != ( const Quaternion& q1, const Quaternion& q2 )
{
	return !( q1 == q2 );
}



/*========= EOF =============================================================*/