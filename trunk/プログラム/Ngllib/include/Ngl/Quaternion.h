/*******************************************************************************/
/**
 * @file Quaternion.h.
 * 
 * @brief クォータニオン構造体ヘッダファイル.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_QUATERNION_H_
#define _NGL_QUATERNION_H_

#include	<Ngl/Vector3.h>
#include	<Ngl/Matrix4.h>

namespace Ngl{

/**
 * @struct Quaternion
 * @brief クォータニオン構造体．
 */
struct Quaternion
{
	/** x成分 */
	float x;

	/** y成分 */
	float y;

	/** z成分 */
	float z;

	/** 回転角度 */
	float w;

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	Quaternion();


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] X x成分.
	 * @param[in] Y y成分.
	 * @param[in] Z z成分.
	 * @param[in] W w成分.
	 */
	Quaternion( float X, float Y, float Z, float W );

	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] aNgle 回転角度.
	 * @param[in] axis 軸.
	 */
	Quaternion( float aNgle, const Vector3& axis );
	
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] m 回転行列.
	 */
	Quaternion( const Matrix4& m );
	

	/*=========================================================================*/
	/**
	 * @brief 単位クォータニオン化する
	 * 
	 * @param[in] なし.
	 * @return 単位クォータニオン化したクォータニオン.
	 */
	Quaternion& setIdentity();


	/*=========================================================================*/
	/**
	 * @brief 正規化をする
	 * 
	 * @param[in] なし.
	 * @return 正規化したクォータニオン.
	 */
	Quaternion& normalize();


	/*=========================================================================*/
	/**
	 * @brief 内積を求める
	 * 
	 * @param[in] q 内積を求めるクォータニオン.
	 * @return 内積の値.
	 */
	float dot( const Ngl::Quaternion& q ) const;


	/*=========================================================================*/
	/**
	 * @brief 長さを求める
	 * 
	 * @param[in] なし.
	 * @return 長さの値.
	 */
	float length() const;
	
	
	/*=========================================================================*/
	/**
	 * @brief 逆クォータニオン化する
	 * 
	 * @param[in] なし.
	 * @return 逆クォータニオン化したクォータニオン.
	 */
	Quaternion& inverse();


	/*=========================================================================*/
	/**
	 * @brief 回転角度からクォータニオンを取得する
	 * 
	 * @param[in] aNgle 回転角度.
	 * @param[in] vx x成分.
	 * @param[in] vy y成分.
	 * @param[in] vz z成分.
	 * @return 取得したクォータニオン.
	 */
	Quaternion& fromRotate( float aNgle, float vx, float vy, float vz );


	/*=========================================================================*/
	/**
	 * @brief 回転角度からクォータニオンを取得する
	 * 
	 * @param[in] aNgle 回転角度.
	 * @param[in] axis 軸.
	 * @return 取得したクォータニオン.
	 */
	Quaternion& fromRotate( float aNgle, const Vector3& axis );

	
	/*=========================================================================*/
	/**
	 * @brief ヨー・ピッチ・ロールからクォータニオンを取得する
	 * 
	 * @param[in] yaw ヨー角.
	 * @param[in] pitch ピッチ角.
	 * @param[in] roll ロール角.
	 * @return 取得したクォータニオン.
	 */
	Quaternion& fromYawPitchRoll( float yaw, float pitch, float roll );


	/*=========================================================================*/
	/**
	 * @brief 回転行列を設定する
	 * 
	 * @param[in] mat 回転行列.
	 * @return 設定したクォータニオン.
	 */
	Quaternion& setMatrix( const Matrix4& mat );


	/*=========================================================================*/
	/**
	 * @brief 軸を取得する
	 * 
	 * @param[in] なし.
	 * @return 軸の値.
	 */
	Vector3 getAxis() const;


	/*=========================================================================*/
	/**
	 * @brief 角度を取得する
	 * 
	 * @param[in] なし.
	 * @return 角度の値.
	 */
	float getANgle() const;


	/*=========================================================================*/
	/**
	 * @brief ヨー角を取得する
	 * 
	 * @param[in] なし.
	 * @return ヨー角の値.
	 */
	float getYaw() const;


	/*=========================================================================*/
	/**
	 * @brief ピッチ角を取得する
	 * 
	 * @param[in] なし.
	 * @return ピッチ角の値.
	 */
	float getPitch() const;


	/*=========================================================================*/
	/**
	 * @brief ロール角を取得する
	 * 
	 * @param[in] なし.
	 * @return ロール角の値.
	 */
	float getRoll() const;
	

	/*=========================================================================*/
	/**
	 * @brief 線形補間する
	 * 
	 * @param[in] q1 補間要素のクォータニオン１.
	 * @param[in] q2 補間要素のクォータニオン２.
	 * @param[in] t 補間値.
	 * @return なし.
	 */
	Quaternion& lerp( const Quaternion& q1, const Quaternion& q2, float t );
	
	
	/*=========================================================================*/
	/**
	 * @brief 球形線形補間する
	 * 
	 * @param[in] q1 補間要素のクォータニオン１.
	 * @param[in] q2 補間要素のクォータニオン２.
	 * @param[in] t 補間値.
	 * @return なし.
	 */
	Quaternion& slerp( const Quaternion& q1, const Quaternion& q2, float t );
	

	/*=========================================================================*/
	/**
	 * @brief 2次補間する
	 * 
	 * @param[in] q1 補間要素のクォータニオン1.
	 * @param[in] q2 補間要素のクォータニオン2.
	 * @param[in] q3 補間要素のクォータニオン3.
	 * @param[in] t 補完度.
	 * @return 補完したクォータニオン.
	 */
	Quaternion& quadratic( const Quaternion& q1, const Quaternion& q2, const Quaternion& q3, float t );
	
	
	/*=========================================================================*/
	/**
	 * @brief + 演算子オーバーロード
	 * 
	 * @param[in] なし.
	 * @return 演算結果のクォータニオン.
	 */
	Quaternion operator + () const;


	/*=========================================================================*/
	/**
	 * @brief - 演算子オーバーロード
	 * 
	 * @param[in] なし.
	 * @return 演算結果のクォータニオン.
	 */
	Quaternion operator - () const;

	
	/*=========================================================================*/
	/**
	 * @brief += 演算子オーバーロード
	 * 
	 * @param[in] q 演算するクォータニオン.
	 * @return 演算結果のクォータニオン.
	 */
	Quaternion& operator += ( const Quaternion& q );
	
	
	/*=========================================================================*/
	/**
	 * @brief -= 演算子オーバーロード
	 * 
	 * @param[in] q 演算するクォータニオン.
	 * @return 演算結果のクォータニオン.
	 */
	Quaternion& operator -= ( const Quaternion& q );


	/*=========================================================================*/
	/**
	 * @brief *= 演算子オーバーロード
	 * 
	 * @param[in] q 演算するクォータニオン.
	 * @return 演算結果のクォータニオン.
	 */
	Quaternion& operator *= ( const Quaternion& q );


	/*=========================================================================*/
	/**
	 * @brief *= 演算子オーバーロード
	 * 
	 * @param[in] s 演算するスカラー.
	 * @return 演算結果のクォータニオン.
	 */
	Quaternion& operator *= ( float s );


	/*=========================================================================*/
	/**
	 * @brief /= 演算子オーバーロード
	 * 
	 * @param[in] s 演算するスカラー.
	 * @return 演算結果のクォータニオン.
	 */
	Quaternion& operator /= ( float s );

};

}	// namespace Ngl

/*=========================================================================*/
/**
 * @brief + 演算子オーバーロード 非メンバ関数
 * 
 * @param[in] q1 演算するクォータニオン1.
 * @param[in] q2 演算するクォータニオン2.
 * @return 演算結果のクォータニオン.
 */
Ngl::Quaternion operator + ( const Ngl::Quaternion& q1, const Ngl::Quaternion& q2 );


/*=========================================================================*/
/**
 * @brief - 演算子オーバーロード 非メンバ関数
 * 
 * @param[in] q1 演算するクォータニオン1.
 * @param[in] q2 演算するクォータニオン2.
 * @return 演算結果のクォータニオン.
 */
Ngl::Quaternion operator - ( const Ngl::Quaternion& q1, const Ngl::Quaternion& q2 );


/*=========================================================================*/
/**
 * @brief * 演算子オーバーロード 非メンバ関数
 * 
 * @param[in] q1 演算するクォータニオン1.
 * @param[in] q2 演算するクォータニオン2.
 * @return 演算結果のクォータニオン.
 */
Ngl::Quaternion operator * ( const Ngl::Quaternion& q1, const Ngl::Quaternion& q2 );


/*=========================================================================*/
/**
 * @brief * 演算子オーバーロード 非メンバ関数
 * 
 * @param[in] q 演算するクォータニオン.
 * @param[in] s 演算するスカラー.
 * @return 演算結果のクォータニオン.
 */
Ngl::Quaternion operator * ( const Ngl::Quaternion& q, float s );


/*=========================================================================*/
/**
 * @brief += 演算子オーバーロード 非メンバ関数
 * 
 * @param[in] s 演算するスカラー.
 * @param[in] q 演算するクォータニオン.
 * @return 演算結果のクォータニオン.
 */
Ngl::Quaternion operator * ( float s, const Ngl::Quaternion& q );


/*=========================================================================*/
/**
 * @brief == 演算子オーバーロード 非メンバ関数
 * 
 * @param[in] q1 演算するクォータニオン1.
 * @param[in] q2 演算するクォータニオン2.
 * @return true 一致している false 一致していない.
 */
bool operator == ( const Ngl::Quaternion& q1, const Ngl::Quaternion& q2 );


/*=========================================================================*/
/**
 * @brief != 演算子オーバーロード 非メンバ関数
 * 
 * @param[in] q1 演算するクォータニオン1.
 * @param[in] q2 演算するクォータニオン2.
 * @return true 一致していない false 一致している.
 */
bool operator != ( const Ngl::Quaternion& q1, const Ngl::Quaternion& q2 );


#endif

/*===== EOF ==================================================================*/