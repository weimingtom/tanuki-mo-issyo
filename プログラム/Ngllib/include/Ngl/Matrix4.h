/*******************************************************************************/
/**
 * @file Matrix4.h.
 * 
 * @brief 4x4行列構造体ヘッダファイル.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MATRIX4_H_
#define _NGL_MATRIX4_H_

#include	"Vector3.h"


#ifdef __cplusplus
namespace Ngl{


// クォータニオン構造体
struct Quaternion;
#endif


/**
 * @struct Matrix4
 * @brief 4x4行列構造体．
 */
typedef struct Matrix4
{
	/** 行列成分 */
	float m[4][4];


#ifdef __cplusplus

	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	Matrix4();


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] m11～m44 行列成分.
	 */
	Matrix4(float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44
			);

	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] other 代入する行列値.
	 */
	Matrix4( const float* other );
	
	
	/*=========================================================================*/
	/**
	 * @brief 単位行列の設定
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	Matrix4& setIdentitiy();

	
	/*=========================================================================*/
	/**
	 * @brief 転置行列を求める
	 * 
	 * @param[in] なし.
	 * @return 求めた転置行列.
	 */
	Matrix4& transpose();


	/*=========================================================================*/
	/**
	 * @brief 逆行列を取得する
	 * 
	 * @param[in] なし.
	 * @return 求めた逆行列.
	 */
	Matrix4 getInverse() const;

	
	/*=========================================================================*/
	/**
	 * @brief 逆行列を求める
	 * 
	 * @param[in] なし.
	 * @return 求めた逆行列.
	 */
	Matrix4& inverse();
	
	
	/*=========================================================================*/
	/**
	 * @brief 拡大縮小行列の設定(右手座標系)
	 * 
	 * @param[in] x x方向の拡大比率.
	 * @param[in] y y方向の拡大比率.
	 * @param[in] z z方向の拡大比率.
	 * @return 設定した行列.
	 */
	Matrix4& setScale( float x, float y, float z );
	
	
	/*=========================================================================*/
	/**
	 * @brief 拡大縮小行列の設定(右手座標系)
	 * 
	 * @param[in] v 拡大縮小率ベクトル.
	 * @return 設定した行列.
	 */
	Matrix4& setScale( const Vector3& v);

	
	/*=========================================================================*/
	/**
	 * @brief x軸周りの回転行列を設定(右手座標系)
	 * 
	 * @param[in] aNgle 角度.
	 * @return 設定した回転行列.
	 */
	Matrix4& setRotateX( float aNgle );


	/*=========================================================================*/
	/**
	 * @brief y軸周りの回転行列を設定(右手座標系)
	 * 
	 * @param[in] aNgle 角度.
	 * @return 設定した回転行列.
	 */
	Matrix4& setRotateY( float aNgle );


	/*=========================================================================*/
	/**
	 * @brief z軸周りの回転行列を設定(右手座標系)
	 * 
	 * @param[in] aNgle 角度.
	 * @return 設定した回転行列.
	 */
	Matrix4& setRotateZ( float aNgle ); // z軸周りの回転

	
	/*=========================================================================*/
	/**
	 * @brief ヨー・ピッチ・ロールから回転行列を求める(右手座標系)
	 * 
	 * @param[in] yaw ヨー.
	 * @param[in] pitch ピッチ.
	 * @param[in] role ロール.
	 * @return 設定した座標.
	 */
	Matrix4& setRotateFromYawPitchRole( float yaw, float pitch, float role );
	
	
	/*=========================================================================*/
	/**
	 * @brief 平行移動行列を設定
	 * 
	 * @param[in] x x方向の移動量.
	 * @param[in] y y方向の移動量.
	 * @param[in] z z方向の移動量.
	 * @return 設定した平行移動行列.
	 */
	Matrix4& setTranslate( float x, float y, float z );
	
	
	/*=========================================================================*/
	/**
	 * @brief 平行移動行列を設定
	 * 
	 * @param[in] v 平行移動成分.
	 * @return 設定した平行移動行列.
	 */
	Matrix4& setTranslate( const Vector3& v );

	
	/*=========================================================================*/
	/**
	 * @brief 透視変換行列の設定(右手座標系)
	 * 
	 * @param[in] fov 視野角.
	 * @param[in] aspect アスペクト比.
	 * @param[in] zNear 近クリップ面.
	 * @param[in] zFar 遠クリップ面.
	 * @return 設定した透視変換行列.
	 */
	Matrix4& setPerspectiveRH( float fov, float aspect, float zNear, float zFar );

	
	/*=========================================================================*/
	/**
	 * @brief 透視変換行列の設定(左手座標系)
	 * 
	 * @param[in] fov 視野角.
	 * @param[in] aspect アスペクト比.
	 * @param[in] zNear 近クリップ面.
	 * @param[in] zFar 遠クリップ面.
	 * @return 設定した透視変換行列.
	 */
	Matrix4& setPerspectiveLH( float fov, float aspect, float zNear, float zFar );
	
	
	/*=========================================================================*/
	/**
	 * @brief 視野変換行列を設定(右手座標系)
	 * 
	 * @param[in] eye 視点の位置.
	 * @param[in] at 注視点.
	 * @param[in] up 上方向のベクトル.
	 * @return 設定した視野変換行列.
	 */
	Matrix4& setLookAtRH( const Vector3& eye, const Vector3& at, const Vector3& up );


	/*=========================================================================*/
	/**
	 * @brief 視野変換行列を設定(左手座標系)
	 * 
	 * @param[in] eye 視点の位置.
	 * @param[in] at 注視点.
	 * @param[in] up 上方向のベクトル.
	 * @return 設定した視野変換行列.
	 */
	Matrix4& setLookAtLH(const Vector3& eye, const Vector3& at, const Vector3& up);


	/*=========================================================================*/
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
	Matrix4& setOrthoRH( float left, float right, float top, float bottom, float zNear, float zFar );
	
	
	/*=========================================================================*/
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
	Matrix4& setOrthoLH( float left, float right, float top, float bottom, float zNear, float zFar );
	
	
	/*=========================================================================*/
	/**
	 * @brief 座標変換
	 *
	 * ベクトルと行列行列の掛け算をする.
	 * 
	 * @param[in] v 乗算する3次元ベクトル.
	 * @return 演算結果の3次元ベクトル.
	 */
	Vector3 transform( const Vector3& v ) const;


	/*=========================================================================*/
	/**
	 * @brief 座標変換.
	 *
	 * ベクトルと行列行列の掛け算をする その結果を w = 1 に射影する.
	 * 
	 * @param[in] v 乗算する3次元ベクトル.
	 * @return 演算結果の3次元ベクトル.
	 */
	Vector3 transformCoord( const Vector3& v ) const;
	
	
	/*=========================================================================*/
	/**
	 * @brief 座標変換
	 *
	 * 法線ベクトル用で回転のみで平行移動はさせない.
	 * 
	 * @param[in] v 乗算する3次元ベクトル.
	 * @return 演算結果の3次元ベクトル.
	 */
	Vector3 transformNormal( const Vector3& v ) const;


	/*=========================================================================*/
	/**
	 * @brief ロール角を求める
	 * 
	 * @param[in] なし.
	 * @return ロール角.
	 */
	float getRole() const;


	/*=========================================================================*/
	/**
	 * @brief ピッチ角を求める
	 * 
	 * @param[in] なし.
	 * @return ピッチ角.
	 */
	float getPitch() const;


	/*=========================================================================*/
	/**
	 * @brief ヨー角を求める
	 * 
	 * @param[in] なし.
	 * @return ヨー角.
	 */
	float getYaw() const;


	/*=========================================================================*/
	/**
	 * @brief x軸位置を設定する
	 * 
	 * @param[in] axisX ｘ軸の位置座標.
	 * @return なし.
	 */
	Matrix4& setAxisX( const Vector3& axisX );


	/*=========================================================================*/
	/**
	 * @brief y軸位置を設定する
	 * 
	 * @param[in] axisY y軸の位置座標.
	 * @return なし.
	 */
	Matrix4& setAxisY( const Vector3& axisY );


	/*=========================================================================*/
	/**
	 * @brief z軸位置を設定する
	 * 
	 * @param[in] axisZ z軸の位置座標.
	 * @return なし.
	 */
	Matrix4& setAxisZ( const Vector3& axisZ );


	/*=========================================================================*/
	/**
	 * @brief 位置座標を設定する
	 * 
	 * @param[in] position 位置座標.
	 * @return なし.
	 */
	Matrix4& setPosition( const Vector3& position );
	
	
	/*=========================================================================*/
	/**
	 * @brief x軸位置を取得する
	 * 
	 * @param[in] なし.
	 * @return ｘ軸の位置座標.
	 */
	Vector3 getAxisX() const;
	
	
	/*=========================================================================*/
	/**
	 * @brief y軸位置を取得する
	 * 
	 * @param[in] なし.
	 * @return y軸の位置座標.
	 */
	Vector3 getAxisY() const;

	
	/*=========================================================================*/
	/**
	 * @brief z軸位置を取得する
	 * 
	 * @param[in] なし.
	 * @return z軸の位置座標.
	 */
	Vector3 getAxisZ() const;

	
	/*=========================================================================*/
	/**
	 * @brief 位置座標を取得する
	 * 
	 * @param[in] なし.
	 * @return 位置座標.
	 */
	Vector3 getPosition() const;

	
	/*=========================================================================*/
	/**
	 * @brief クォータニオンから行列を求める
	 * 
	 * @param[in] q クォータニオン.
	 * @return 行列.
	 */
	Matrix4& fromQuaternion( const Quaternion& q );
	
	
	/*=========================================================================*/
	/**
	 * @brief +演算子オーバーロード
	 * 
	 * @param[in] なし.
	 * @return 演算結果のMatrix4.
	 */
	Matrix4 operator + () const;


	/*=========================================================================*/
	/**
	 * @brief -演算子オーバーロード
	 * 
	 * @param[in] なし.
	 * @return 演算結果のMatrix4.
	 */
	Matrix4 operator - () const;
	
	
	/*=========================================================================*/
	/**
	 * @brief =演算子オーバーロード
	 * 
	 * @param[in] m2 代入するする行列.
	 * @return 代入した結果の行列.
	 */
	Matrix4& operator = ( const Matrix4& m2 );
	
	
	/*=========================================================================*/
	/**
	 * @brief *=演算子オーバーロード(右手座標系)
	 * 
	 * @param[in] m2 乗算する行列.
	 * @return 演算結果の行列.
	 */
	Matrix4& operator *= ( const Matrix4& m2 );


	/*=========================================================================*/
	/**
	 * @brief float* 演算子オーバーロード
	 * 
	 * @param[in] なし.
	 * @return キャストした値.
	 */
	operator float* () const;


	/*=========================================================================*/
	/**
	 * @brief float* 演算子オーバーロード
	 * 
	 * @param[in] なし.
	 * @return キャストした値.
	 */
	operator const float* () const;


#endif


} NGLmatrix4;


#ifdef __cplusplus


/** 零行列 */
static const Matrix4 MATRIX4_ZERO = Matrix4(
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f
	);


/** 単位行列 */
static const Matrix4 MATRIX4_IDENTITY = Matrix4(
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
	);

}	// namespace Ngl

/*===========================================================================*/
/**
 * @brief ==演算子オーバーロード 非メンバ関数
 * 
 * @param[in] m1 比較する行列.
 * @param[in] m2 比較する行列.
 * @return 比較結果の行列.
 */
bool operator == ( const Ngl::Matrix4& m1, const Ngl::Matrix4& m2 );


/*===========================================================================*/
/**
 * @brief !=演算子オーバーロード 非メンバ関数
 * 
 * @param[in] m1 比較する行列.
 * @param[in] m2 比較する行列.
 * @return 比較結果の行列.
 */
bool operator != ( const Ngl::Matrix4& m1, const Ngl::Matrix4& m2 );


/*===========================================================================*/
/**
 * @brief +演算子オーバーロード 非メンバ関数
 * 
 * @param[in] m1 演算する行列.
 * @param[in] m2 演算する行列.
 * @return 演算結果の行列.
 */
const Ngl::Matrix4 operator + ( const Ngl::Matrix4& m1, const Ngl::Matrix4& m2 );


/*===========================================================================*/
/**
 * @brief -演算子オーバーロード 非メンバ関数
 * 
 * @param[in] m1 演算する行列.
 * @param[in] m2 演算する行列.
 * @return 演算結果の行列.
 */
const Ngl::Matrix4 operator - ( const Ngl::Matrix4& m1, const Ngl::Matrix4& m2 );


/*===========================================================================*/
/**
 * @brief *演算子オーバーロード 非メンバ関数
 * 
 * @param[in] m1 演算する行列.
 * @param[in] m2 演算する行列.
 * @return 演算結果の行列.
 */
const Ngl::Matrix4 operator * ( const Ngl::Matrix4& m1, const Ngl::Matrix4& m2 );


/*===========================================================================*/
/**
 * @brief *演算子オーバーロード 非メンバ関数
 * 
 * @param[in] v 演算する3次元ベクトル.
 * @param[in] m 演算する行列.
 * @return 演算結果の3次元ベクトル.
 */
const Ngl::Vector3 operator * ( const Ngl::Vector3& v, const Ngl::Matrix4& m );


/*===========================================================================*/
/**
 * @brief *演算子オーバーロード 非メンバ関数
 * 
 * @param[in] m 演算する行列.
 * @param[in] s 演算するスカラー.
 * @return 演算結果の3次元ベクトル.
 */
const Ngl::Matrix4 operator * ( const Ngl::Matrix4& m, float s );


/*===========================================================================*/
/**
 * @brief *演算子オーバーロード 非メンバ関数
 * 
 * @param[in] s 演算するスカラー.
 * @param[in] m 演算する行列.
 * @return 演算結果の3次元ベクトル.
 */
const Ngl::Matrix4 operator * ( float s, const Ngl::Matrix4& m );


/*===========================================================================*/
/**
 * @brief /演算子オーバーロード 非メンバ関数
 * 
 * @param[in] m 演算する行列.
 * @param[in] s 演算するスカラー.
 * @return 演算結果の3次元ベクトル.
 */
const Ngl::Matrix4 operator / ( const Ngl::Matrix4& m, float s );


#endif


#endif


/*========= EOF =============================================================*/