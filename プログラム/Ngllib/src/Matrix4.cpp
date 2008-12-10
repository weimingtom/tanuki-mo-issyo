/*******************************************************************************/
/**
 * @file Matrix4.cpp.
 * 
 * @brief 4x4行列構造体ソースファイル.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Matrix4.h"
#include	"Ngl/Quaternion.h"
#include	"Ngl/MathUtility.h"

using namespace Ngl;

/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
Matrix4::Matrix4()
{
	// 単位行列を作成
	setIdentitiy();
}



/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] m11～m44 行列成分.
 */
Matrix4::Matrix4
(
	float m11, float m12, float m13, float m14,
	float m21, float m22, float m23, float m24,
	float m31, float m32, float m33, float m34,
	float m41, float m42, float m43, float m44
)
{
	// 引数の値を代入
	m[0][0] = m11; m[0][1] = m12; m[0][2] = m13; m[0][3] = m14;
	m[1][0] = m21; m[1][1] = m22; m[1][2] = m23; m[1][3] = m24;
	m[2][0] = m31; m[2][1] = m32; m[2][2] = m33; m[2][3] = m34;
	m[3][0] = m41; m[3][1] = m42; m[3][2] = m43; m[3][3] = m44;
}



/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] other 代入する行列値.
 */
Matrix4::Matrix4( const float *other )
{
	for( int i=0; i<4; i++ ){
		for( int j=0; j<4; j++ ){
			m[i][j] = other[ ( i * 4 ) + j ];
		}
	}
}



/*===========================================================================*/
/**
 * @brief 単位行列の設定
 * 
 * @param[in] なし.
 * @return なし.
 */
Matrix4& Matrix4::setIdentitiy()
{
	// 単位行列の値を代入
	m[0][0] = 1.0f;	m[0][1] = 0.0f;	m[0][2] = 0.0f;	m[0][3] = 0.0f;
	m[1][0] = 0.0f;	m[1][1] = 1.0f;	m[1][2] = 0.0f;	m[1][3] = 0.0f;
	m[2][0] = 0.0f;	m[2][1] = 0.0f;	m[2][2] = 1.0f;	m[2][3] = 0.0f;
	m[3][0] = 0.0f;	m[3][1] = 0.0f;	m[3][2] = 0.0f;	m[3][3] = 1.0f;

	return *this;
}



/*===========================================================================*/
/**
 * @brief 転置行列を求める
 * 
 * @param[in] なし.
 * @return 求めた転置行列.
 */
Matrix4& Matrix4::transpose()
{
	Matrix4 tmp;

	// 行列の行と列を交換する
	for( int i=0; i<4; i++ ){
		for( int j=0; j<4; j++ ){
			tmp.m[i][j] = m[j][i];
		}
	}

	*this = tmp;

	return *this;
}



/*=========================================================================*/
/**
 * @brief 逆行列を取得する
 * 
 * @param[in] なし.
 * @return 求めた逆行列.
 */
Matrix4 Matrix4::getInverse() const
{
	Matrix4 tmp;

	tmp.m[0][0] = m[0][0];
	tmp.m[1][0] = m[0][1];
	tmp.m[2][0] = m[0][2];

	tmp.m[0][1] = m[1][0];
	tmp.m[1][1] = m[1][1];
	tmp.m[2][1] = m[1][2];

	tmp.m[0][2] = m[2][0];
	tmp.m[1][2] = m[2][1];
	tmp.m[2][2] = m[2][2];

	tmp.m[3][0] = -( m[3][0] * tmp.m[0][0]
	             + m[3][1] * tmp.m[1][0]
	             + m[3][2] * tmp.m[2][0] );
	tmp.m[3][1] = -( m[3][0] * tmp.m[0][1] 
	             + m[3][1] * tmp.m[1][1]
	             + m[3][2] * tmp.m[2][1] );
	tmp.m[3][2] = -( m[3][0] * tmp.m[0][2]
	             + m[3][1] * tmp.m[1][2]
	             + m[3][2] * tmp.m[2][2] );

	tmp.m[0][3] = m[0][3];
	tmp.m[1][3] = m[1][3];
	tmp.m[2][3] = m[2][3];
	tmp.m[3][3] = m[3][3];

	return tmp;
}
	

	
/*===========================================================================*/
/**
 * @brief 逆行列を求める
 * 
 * @param[in] なし.
 * @return 求めた逆行列.
 */
Matrix4& Matrix4::inverse()
{
	*this = getInverse();

	return *this;
}



/*===========================================================================*/
/**
 * @brief 拡大縮小行列の設定
 * 
 * @param[in] x x方向の拡大比率.
 * @param[in] y y方向の拡大比率.
 * @param[in] z z方向の拡大比率.
 * @return 設定した行列.
 */
Matrix4& Matrix4::setScale( float x, float y, float z )
{
	// 単位行列の値を代入
	m[0][0] = x;	m[0][1] = 0.0f;	m[0][2] = 0.0f;	m[0][3] = 0.0f;
	m[1][0] = 0.0f;	m[1][1] = y;	m[1][2] = 0.0f;	m[1][3] = 0.0f;
	m[2][0] = 0.0f;	m[2][1] = 0.0f;	m[2][2] = z;	m[2][3] = 0.0f;
	m[3][0] = 0.0f;	m[3][1] = 0.0f;	m[3][2] = 0.0f;	m[3][3] = 1.0f;

	return *this;
}

	
	
/*===========================================================================*/
/**
 * @brief 拡大縮小行列の設定
 * 
 * @param[in] v 拡大縮小率ベクトル.
 * @return 設定した行列.
 */
Matrix4& Matrix4::setScale(const Vector3& v)
{
	return setScale( v.x, v.y, v.z );
}



/*===========================================================================*/
/**
 * @brief x軸周りの回転行列を設定
 * 
 * @param[in] aNgle 角度.
 * @return 設定した回転行列.
 */
Matrix4& Matrix4::setRotateX(float aNgle)
{
	// Sin値とCos値を設定
	float Sin = Ngl::sin(aNgle);
	float Cos = Ngl::cos(aNgle);

	// 単位行列の値を代入
	m[0][0] = 1.0f;	m[0][1] = 0.0f;	m[0][2] = 0.0f;	m[0][3] = 0.0f;
	m[1][0] = 0.0f;	m[1][1] = Cos;	m[1][2] = Sin;	m[1][3] = 0.0f;
	m[2][0] = 0.0f;	m[2][1] = -Sin;	m[2][2] = Cos;	m[2][3] = 0.0f;
	m[3][0] = 0.0f;	m[3][1] = 0.0f;	m[3][2] = 0.0f;	m[3][3] = 1.0f;

	return *this;
}



/*===========================================================================*/
/**
 * @brief y軸周りの回転行列を設定
 * 
 * @param[in] aNgle 角度.
 * @return 設定した回転行列.
 */
Matrix4& Matrix4::setRotateY(float aNgle)
{
	// Sin値とCos値を設定
	float Sin = Ngl::sin(aNgle);
	float Cos = Ngl::cos(aNgle);

	// 単位行列の値を代入
	m[0][0] = Cos;	m[0][1] = 0.0f;	m[0][2] = -Sin;	m[0][3] = 0.0f;
	m[1][0] = 0.0f;	m[1][1] = 1.0f;	m[1][2] = 0.0f;	m[1][3] = 0.0f;
	m[2][0] = Sin;	m[2][1] = 0.0f;	m[2][2] = Cos;	m[2][3] = 0.0f;
	m[3][0] = 0.0f;	m[3][1] = 0.0f;	m[3][2] = 0.0f;	m[3][3] = 1.0f;

	return *this;
}



/*===========================================================================*/
/**
 * @brief z軸周りの回転行列を設定
 * 
 * @param[in] aNgle 角度.
 * @return 設定した回転行列.
 */
Matrix4& Matrix4::setRotateZ(float aNgle)
{
	// Sin値とCos値を設定
	float Sin = Ngl::sin(aNgle);
	float Cos = Ngl::cos(aNgle);

	// 単位行列の値を代入
	m[0][0] = Cos;	m[0][1] = Sin;	m[0][2] = 0.0f;	m[0][3] = 0.0f;
	m[1][0] = -Sin;	m[1][1] = Cos;	m[1][2] = 0.0f;	m[1][3] = 0.0f;
	m[2][0] = 0.0f;	m[2][1] = 0.0f;	m[2][2] = 1.0f;	m[2][3] = 0.0f;
	m[3][0] = 0.0f;	m[3][1] = 0.0f;	m[3][2] = 0.0f;	m[3][3] = 1.0f;

	return *this;
}



/*===========================================================================*/
/**
 * @brief ヨー・ピッチ・ロールから回転行列を求める
 * 
 * @param[in] yaw ヨー.
 * @param[in] pitch ピッチ.
 * @param[in] role ロール.
 * @return 設定した座標.
 */
Matrix4& Matrix4::setRotateFromYawPitchRole(float yaw, float pitch, float role)
{
	// ヨー角の変換行列を求める
	Matrix4 matYaw;
	matYaw.setRotateY( yaw );

	// ピッチ角の変換行列を求める
	Matrix4 matPitch;
	matPitch.setRotateX( pitch );

	// ロール角の変換行列を求める
	Matrix4 matRoll;
	matRoll.setRotateZ( role );

	// 変換行列を合成する
	*this = matRoll * matPitch * matYaw;

	return *this;
}



/*===========================================================================*/
/**
 * @brief 平行移動行列を設定
 * 
 * @param[in] x x方向の移動量.
 * @param[in] y y方向の移動量.
 * @param[in] z z方向の移動量.
 * @return 設定した平行移動行列.
 */
Matrix4& Matrix4::setTranslate(float x, float y, float z)
{
	// 単位行列の値を代入
	m[0][0] = 1.0f;	m[0][1] = 0.0f;	m[0][2] = 0.0f;	m[0][3] = 0.0f;
	m[1][0] = 0.0f;	m[1][1] = 1.0f;	m[1][2] = 0.0f;	m[1][3] = 0.0f;
	m[2][0] = 0.0f;	m[2][1] = 0.0f;	m[2][2] = 1.0f;	m[2][3] = 0.0f;
	m[3][0] = x;	m[3][1] = y;	m[3][2] = z;	m[3][3] = 1.0f;

	return *this;
}



/*===========================================================================*/
/**
 * @brief 平行移動行列を設定
 * 
 * @param[in] v 平行移動成分.
 * @return 設定した平行移動行列.
 */
Matrix4& Matrix4::setTranslate(const Vector3& v)
{
	return setTranslate( v.x, v.y, v.z );
}



/*===========================================================================*/
/**
 * @brief 透視変換行列の設定(右手座標系)
 * 
 * @param[in] fov 視野角.
 * @param[in] aspect アスペクト比.
 * @param[in] zNear 近クリップ面.
 * @param[in] zFar 遠クリップ面.
 * @return 設定した透視変換行列.
 */
Matrix4& Matrix4::setPerspectiveRH(float fov, float aspect, float zNear, float zFar)
{
	float f = 1.0f / Ngl::tan(fov / 2.0f);

	// 行列の値に代入
	m[0][0] = f / aspect;
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = 0.0f;
	
	m[1][0] = 0.0f;
	m[1][1] = f;
	m[1][2] = 0.0f;
	m[1][3] = 0.0f;
	
	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = (zFar + zNear) / (zNear - zFar);
	m[2][3] = -1.0f;
	
	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = (2 * zFar * zNear) / (zNear - zFar);
	m[3][3] = 0.0f;

	return *this;
}



/*===========================================================================*/
/**
 * @brief 透視変換行列の設定(左手座標系)
 * 
 * @param[in] fov 視野角.
 * @param[in] aspect アスペクト比.
 * @param[in] zNear 近クリップ面.
 * @param[in] zFar 遠クリップ面.
 * @return 設定した透視変換行列.
 */
Matrix4& Matrix4::setPerspectiveLH(float fov, float aspect, float zNear, float zFar)
{
	float f = Ngl::cos( fov / 2.0f ) / Ngl::sin( fov / 2.0f );

	m[0][0] = f / aspect;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;

	m[1][0] = 0;
	m[1][1] = f;
	m[1][2] = 0;
	m[1][3] = 0;

	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = ( zFar + zNear ) / ( zNear - zFar );
	m[2][3] = 1.0f;

	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = ( 2.0f * zFar * zNear ) / ( zNear - zFar );
	m[3][3] = 0.0f;

	return *this;
}



/*===========================================================================*/
/**
 * @brief 視野変換行列を設定(右手座標系)
 * 
 * @param[in] eye 視点の位置.
 * @param[in] at 注視点.
 * @param[in] up 上方向のベクトル.
 * @return 設定した視野変換行列.
 */
Matrix4& Matrix4::setLookAtRH(const Vector3& eye, const Vector3& at, const Vector3& up)
{
	// z方向のベクトルを求める
	Vector3 e(eye - at);
	e.normalize();

	// x方向のベクトルを求める
	Vector3 v(up.cross(e));
	v.normalize();

	// y方向のベクトルを求める
	Vector3 u(e.cross(v));

	// 行列の値に代入
	m[0][0] = v.x;
	m[0][1] = u.x;
	m[0][2] = e.x;
	m[0][3] = 0.0f;
	
	m[1][0] = v.y;
	m[1][1] = u.y;
	m[1][2] = e.y;
	m[1][3] = 0.0f;
	
	m[2][0] = v.z;
	m[2][1] = u.z;
	m[2][2] = e.z;
	m[2][3] = 0.0f;
	
	m[3][0] = -eye.dot(v);
	m[3][1] = -eye.dot(u);
	m[3][2] = -eye.dot(e);
	m[3][3] = 1.0f;

	return *this;
}


/*===========================================================================*/
/**
 * @brief 視野変換行列を設定(左手座標系)
 * 
 * @param[in] eye 視点の位置.
 * @param[in] at 注視点.
 * @param[in] up 上方向のベクトル.
 * @return 設定した視野変換行列.
 */
Matrix4& Matrix4::setLookAtLH(const Vector3& eye, const Vector3& at, const Vector3& up)
{
	// z方向のベクトルを求める
	Vector3 e( at - eye );
	e.normalize();

	// x方向のベクトルを求める
	Vector3 v( up.cross( e ) );
	v.normalize();

	// y方向のベクトルを求める
	Vector3 u( e.cross( v ) );

	// 回転行列に各ベクトルを設定する
	m[0][0] = v.x;
	m[0][1] = u.x;
	m[0][2] = e.x;
	m[0][3] = 0.0f;

	m[1][0] = v.y;
	m[1][1] = u.y;
	m[1][2] = e.y;
	m[1][3] = 0.0f;

	m[2][0] = v.z;
	m[2][1] = u.z;
	m[2][2] = e.z;
	m[2][3] = 0.0f;

	// 視点の位置を設定する
	m[3][0] = -eye.dot( v );
	m[3][1] = -eye.dot( u );
	m[3][2] = -eye.dot( e );
	m[3][3] = 1.0f;

	return *this;
}



/*===========================================================================*/
/**
 * @brief 正射影変換行列を設定(右手座標系)
 * 
 * @param[in] left クリップ面の左側の座標.
 * @param[in] right クリップ面の右側の座標.
 * @param[in] bottom クリップ面の下側の座標.
 * @param[in] top クリップ面の上側の座標.
 * @param[in] zNear 近クリップ面の座標.
 * @param[in] zFar 遠クリップ面の座標.
 * @return 設定した変換行列.
 */
Matrix4& Matrix4::setOrthoRH( float left, float right, float top, float bottom, float zNear, float zFar )
{
	m[0][0] = 2.0f / ( right - left );
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0; 

	m[1][0] = 0;
	m[1][1] = 2.0f / (  top - bottom );
	m[1][2] = 0;
	m[1][3] = 0;

	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = -2.0f / ( zFar - zNear );
	m[2][3] = 0; 

	m[3][0] = -( right + left   ) / ( right - left   );
	m[3][1] = -( top   + bottom ) / ( top   - bottom );
	m[3][2] = -( zFar  + zNear  ) / ( zFar  - zNear  );
	m[3][3] = 1;

	return *this;
}
	
	
	
/*===========================================================================*/
/**
 * @brief 正射影変換行列を設定(左手座標系)
 * 
 * @param[in] left クリップ面の左側の座標.
 * @param[in] right クリップ面の右側の座標.
 * @param[in] bottom クリップ面の下側の座標.
 * @param[in] top クリップ面の上側の座標.
 * @param[in] zNear 近クリップ面の座標.
 * @param[in] zFar 遠クリップ面の座標.
 * @return 設定した変換行列.
 */
Matrix4& Matrix4::setOrthoLH( float left, float right, float top, float bottom, float zNear, float zFar )
{
	m[0][0] = 2.0f / ( right - left );
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0; 

	m[1][0] = 0;
	m[1][1] = 2.0f / (  top - bottom );
	m[1][2] = 0;
	m[1][3] = 0;

	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 2.0f / ( zFar - zNear );
	m[2][3] = 0; 

	m[3][0] = -( right + left   ) / ( right - left   );
	m[3][1] = -( top   + bottom ) / ( top   - bottom );
	m[3][2] = -( zFar  + zNear  ) / ( zFar  - zNear  );
	m[3][3] = 1;


	return *this;
}

	
	
/*=========================================================================*/
/**
 * @brief 座標変換
 *
 * ベクトルと行列行列の掛け算をする.
 * 
 * @param[in] v 乗算する3次元ベクトル.
 * @return 演算結果の3次元ベクトル.
 */
Vector3 Matrix4::transform(const Vector3& v) const
{
	float x = v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0] + m[3][0];
	float y = v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1] + m[3][1];
	float z = v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2] + m[3][2];
	float w = v.x * m[0][3] + v.y * m[1][3] + v.z * m[2][3] + m[3][3];

	return Vector3(x/w, y/w, z/w);
}



/*=========================================================================*/
/**
 * @brief 座標変換.
 *
 * ベクトルと行列行列の掛け算をする その結果を w = 1 に射影する.
 * 
 * @param[in] v 乗算する3次元ベクトル.
 * @return 演算結果の3次元ベクトル.
 */
Vector3 Matrix4::transformCoord( const Vector3& v ) const
{
	float x = v.x * m[0][0]
			+ v.y * m[1][0]
			+ v.z * m[2][0]
			+ m[3][0];
	float y = v.x * m[0][1]
			+ v.y * m[1][1]
			+ v.z * m[2][1]
			+ m[3][1];
	float z = v.x * m[0][2]
			+ v.y * m[1][2]
			+ v.z * m[2][2]
			+ m[3][2];
	float w = v.x * m[0][3]
			+ v.y * m[1][3]
			+ v.z * m[2][3]
			+ m[3][3];

	Vector3 result( x, y, z );
	result = result * ( 1.0f / w );

	return result;
}

	
	
/*=========================================================================*/
/**
 * @brief 座標変換
 *
 * 法線ベクトル用で回転のみで平行移動はさせない.
 * 
 * @param[in] v 乗算する3次元ベクトル.
 * @return 演算結果の3次元ベクトル.
 */
Vector3 Matrix4::transformNormal(const Vector3& v) const
{
	float x = v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0];
	float y = v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1];
	float z = v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2];

	return Vector3(x, y, x);
}



/*===========================================================================*/
/**
 * @brief ロール角を求める
 * 
 * @param[in] なし.
 * @return ロール角.
 */
float Matrix4::getRole() const
{
	return Ngl::atan( m[0][1], m[1][1] );
}



/*===========================================================================*/
/**
 * @brief ピッチ角を求める
 * 
 * @param[in] なし.
 * @return ピッチ角.
 */
float Matrix4::getPitch() const
{
	return Ngl::degreeNormalize( Ngl::asin( -m[2][1] ) );
}



/*===========================================================================*/
/**
 * @brief ヨー角を求める
 * 
 * @param[in] なし.
 * @return ヨー角.
 */
float Matrix4::getYaw() const
{
	return Ngl::atan( m[2][0], m[2][2] );
}



/*===========================================================================*/
/**
 * @brief x軸位置を設定する
 * 
 * @param[in] axisX ｘ軸の位置座標.
 * @return なし.
 */
Matrix4& Matrix4::setAxisX(const Vector3 &axisX)
{
	m[0][1] = axisX.x;
	m[0][2] = axisX.y;
	m[0][3] = axisX.z;

	return *this;
}



/*===========================================================================*/
/**
 * @brief y軸位置を設定する
 * 
 * @param[in] axisY y軸の位置座標.
 * @return なし.
 */
Matrix4& Matrix4::setAxisY(const Vector3 &axisY)
{
	m[1][0] = axisY.x;
	m[1][1] = axisY.y;
	m[1][2] = axisY.z;

	return *this;
}


/*===========================================================================*/
/**
 * @brief z軸位置を設定する
 * 
 * @param[in] axisZ z軸の位置座標.
 * @return なし.
 */
Matrix4& Matrix4::setAxisZ(const Vector3 &axisZ)
{
	m[2][0] = axisZ.x;
	m[2][1] = axisZ.y;
	m[2][2] = axisZ.z;

	return *this;
}



/*===========================================================================*/
/**
 * @brief 位置座標を設定する
 * 
 * @param[in] position 位置座標.
 * @return なし.
 */
Matrix4& Matrix4::setPosition(const Vector3 &position)
{
	m[3][0] = position.x;
	m[3][1] = position.y;
	m[3][2] = position.z;

	return *this;
}



/*===========================================================================*/
/**
 * @brief x軸位置を取得する
 * 
 * @param[in] なし.
 * @return ｘ軸の位置座標.
 */
Vector3 Matrix4::getAxisX() const
{
	return Vector3( m[0][0], m[0][1], m[0][2] );
}



/*===========================================================================*/
/**
 * @brief y軸位置を取得する
 * 
 * @param[in] なし.
 * @return y軸の位置座標.
 */
Vector3 Matrix4::getAxisY() const
{
	return Vector3( m[1][0], m[1][1], m[1][2] );
}



/*===========================================================================*/
/**
 * @brief z軸位置を取得する
 * 
 * @param[in] なし.
 * @return z軸の位置座標.
 */
Vector3 Matrix4::getAxisZ() const
{
	return Vector3( m[2][0], m[2][1], m[2][2] );
}



/*===========================================================================*/
/**
 * @brief 位置座標を取得する
 * 
 * @param[in] なし.
 * @return 位置座標.
 */
Vector3 Matrix4::getPosition() const
{
	return Vector3( m[3][0], m[3][1], m[3][2] );
}



/*===========================================================================*/
/**
 * @brief クォータニオンから行列を求める
 * 
 * @param[in] q クォータニオン.
 * @return 行列.
 */
Matrix4& Matrix4::fromQuaternion(const Quaternion &q)
{
	float		xx, yy, zz;
	float		xy, xz, yz;
	float		wx, wy, wz;

	xx = q.x * q.x * 2.0f;
	yy = q.y * q.y * 2.0f;
	zz = q.z * q.z * 2.0f;
	xy = q.x * q.y * 2.0f;
	xz = q.x * q.z * 2.0f;
	yz = q.y * q.z * 2.0f;
	wx = q.w * q.x * 2.0f;
	wy = q.w * q.y * 2.0f;
	wz = q.w * q.z * 2.0f;

	m[0][0] = 1.0f - ( yy + zz );
	m[0][1] = xy + wz;
	m[0][2] = xz - wy;
	m[0][3] = 0.0f;

	m[1][0] = xy - wz;
	m[1][1] = 1.0f - ( xx + zz );
	m[1][2] = yz + wx;
	m[1][3] = 0.0f;

	m[2][0] = xz + wy;
	m[2][1] = yz - wx;
	m[2][2] = 1.0f - ( xx + yy );
	m[2][3] = 0.0f;

	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = 0.0f;
	m[3][3] = 1.0f;

	return *this;
}



/*===========================================================================*/
/**
 * @brief +演算子オーバーロード
 * 
 * @param[in] なし.
 * @return 演算結果のMatrix4.
 */
Matrix4 Matrix4::operator + () const
{
	return *this;
}



/*===========================================================================*/
/**
 * @brief -演算子オーバーロード
 * 
 * @param[in] なし.
 * @return 演算結果のMatrix4.
 */
Matrix4 Matrix4::operator - () const
{
	// すべての要素の符号を反転させた行列を返す
	return Matrix4(
		-m[0][0], -m[0][1], -m[0][2], -m[0][3],
		-m[1][0], -m[1][1], -m[1][2], -m[1][3],
		-m[2][0], -m[2][1], -m[2][2], -m[2][3],
		-m[3][0], -m[3][1], -m[3][2], -m[3][3]
		);
}



/*===========================================================================*/
/**
 * @brief =演算子オーバーロード
 * 
 * @param[in] m2 代入するする行列.
 * @return 代入した結果の行列.
 */
Matrix4& Matrix4::operator =(const Matrix4 &m2)
{
	// 自分への代入ではないか
	if( this != &m2 ){
		// 各成分をコピー
		for( int i=0; i<4; i++ ){
			for( int j=0; j<4; j++ ){
				m[i][j] = m2.m[i][j];
			}
		}
	}

	return *this;
}



/*===========================================================================*/
/**
 * @brief *=演算子オーバーロード
 * 
 * @param[in] m2 乗算する行列.
 * @return 演算結果の行列.
 */
Matrix4& Matrix4::operator *= (const Matrix4& m2)
{
	Matrix4 tmp;

	for ( int i = 0; i < 4; i++ ){
		for ( int j = 0; j < 4; j++ ){
			tmp.m[i][j] = m[i][0] * m2.m[0][j]
					    + m[i][1] * m2.m[1][j]
					    + m[i][2] * m2.m[2][j]
					    + m[i][3] * m2.m[3][j];
		}
	}

	*this = tmp;

	return *this;
}



/*===========================================================================*/
/**
 * @brief float* 演算子オーバーロード
 * 
 * @param[in] なし.
 * @return キャストした値.
 */
Matrix4::operator float *() const
{
	return ( float* )m;
}



/*===========================================================================*/
/**
 * @brief float* 演算子オーバーロード
 * 
 * @param[in] なし.
 * @return キャストした値.
 */
Matrix4::operator const float *() const
{
	return ( const float* )m;
}



/*===========================================================================*/
/**
 * @brief ==演算子オーバーロード 非メンバ関数
 * 
 * @param[in] m1 比較する行列.
 * @param[in] m2 比較する行列.
 * @return 比較結果の行列.
 */
bool operator == ( const Matrix4& m1, const Matrix4& m2 )
{
	for( int i=0; i<4; i++ ){
		for( int j=0; j<4; j++ ){
			if( m1.m[i][j] != m2.m[i][j] ){
				return false;
			}
		}
	}
	return true;
}



/*===========================================================================*/
/**
 * @brief !=演算子オーバーロード 非メンバ関数
 * 
 * @param[in] m1 比較する行列.
 * @param[in] m2 比較する行列.
 * @return 比較結果の行列.
 */
bool operator != ( const Matrix4& m1, const Matrix4& m2 )
{
	return !( m1 == m2 );
}



/*===========================================================================*/
/**
 * @brief +演算子オーバーロード 非メンバ関数
 * 
 * @param[in] m1 演算する行列.
 * @param[in] m2 演算する行列.
 * @return 演算結果の行列.
 */
const Matrix4 operator + ( const Matrix4& m1, const Matrix4& m2 )
{
	Matrix4 result;	// 演算結果行列

	for( int i=0; i<4; i++ ){
		for( int j=0; j<4; j++ ){
			result.m[i][j] = m1.m[i][j] + m2.m[i][j];
		}
	}
	
	// 結果を返す
	return result;
}



/*===========================================================================*/
/**
 * @brief -演算子オーバーロード 非メンバ関数
 * 
 * @param[in] m1 演算する行列.
 * @param[in] m2 演算する行列.
 * @return 演算結果の行列.
 */
const Matrix4 operator - ( const Matrix4& m1, const Matrix4& m2 )
{
	Matrix4 result;	// 演算結果行列

	for( int i=0; i<4; i++ ){
		for( int j=0; j<4; j++ ){
			result.m[i][j] = m1.m[i][j] - m2.m[i][j];
		}
	}
	
	// 結果を返す
	return result;
}



/*===========================================================================*/
/**
 * @brief *演算子オーバーロード 非メンバ関数
 * 
 * @param[in] m1 演算する行列.
 * @param[in] m2 演算する行列.
 * @return 演算結果の行列.
 */
const Matrix4 operator * ( const Matrix4& m1, const Matrix4& m2 )
{
	Matrix4 tmp(m1);
	return tmp *= m2;
}



/*===========================================================================*/
/**
 * @brief *演算子オーバーロード 非メンバ関数
 * 
 * @param[in] v 演算する3次元ベクトル.
 * @param[in] m 演算する行列.
 * @return 演算結果の3次元ベクトル.
 */
const Vector3 operator * ( const Vector3& v, const Matrix4& m )
{
	return m.transform(v);
}



/*===========================================================================*/
/**
 * @brief *演算子オーバーロード 非メンバ関数
 * 
 * @param[in] m 演算する行列.
 * @param[in] s 演算するスカラー.
 * @return 演算結果の3次元ベクトル.
 */
const Matrix4 operator * ( const Matrix4& m, float s )
{
	Matrix4 result; // 演算結果

	for( int i=0; i<4; i++ ){
		for( int j=0; j<4; j++ ){
			result.m[i][j] = m.m[i][j] * s;
		}
	}

	return result;
}



/*===========================================================================*/
/**
 * @brief *演算子オーバーロード 非メンバ関数
 * 
 * @param[in] s 演算するスカラー.
 * @param[in] m 演算する行列.
 * @return 演算結果の3次元ベクトル.
 */
const Matrix4 operator * ( float s, const Matrix4& m )
{
	return m * s;
}



/*===========================================================================*/
/**
 * @brief /演算子オーバーロード 非メンバ関数
 * 
 * @param[in] m 演算する行列.
 * @param[in] s 演算するスカラー.
 * @return 演算結果の3次元ベクトル.
 */
const Matrix4 operator / ( const Matrix4& m, float s )
{
	return m * ( 1.0f / s );
}



/*========= EOF =============================================================*/