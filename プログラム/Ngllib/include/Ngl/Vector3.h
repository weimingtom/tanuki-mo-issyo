/*******************************************************************************/
/**
 * @file Vector3.h.
 * 
 * @brief 3次元ベクトル構造体ヘッダファイル.
 *
 * @date 2008/06/23.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_VECTOR3_
#define _NGL_VECTOR3_

#include	"Vector2.h"

#ifdef __cplusplus
namespace Ngl{


// 行列構造体の前方参照
struct Matrix4;

#endif

/**
 * @struct Vector3.
 * @brief 3次元ベクトル構造体．
 */
typedef struct Vector3
{
	/**	x成分	*/
	float	x;

	/**	y成分	*/
	float	y;

	/**	z成分	*/
	float	z;


#ifdef __cplusplus


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	Vector3();

	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] X x値.
	 * @param[in] Y y値.
	 * @param[in] Z z値.
	 */
	Vector3(float X, float Y, float Z);


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] other 代入する配列.
	 */
	Vector3( const float* other );
	
	
	/*=========================================================================*/
	/**
	 * @brief 0.0に初期化する
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void zero();
	
	
	/*=========================================================================*/
	/**
	 * @brief 初期化する
	 * 
	 * @param[in] X x値.
	 * @param[in] Y y値.
	 * @param[in] Z z値.
	 * @return なし.
	 */
	void initialize( float X, float Y, float Z );
	
	
	/*=========================================================================*/
	/**
	 * @brief ノルムを求める
	 * 
	 * @param[in] なし.
	 * @return ノルム.
	 */
	float length() const;


	/*=========================================================================*/
	/**
	 * @brief ノルムを求める(ルートをとらない)
	 * 
	 * @param[in] なし.
	 * @return ノルム(２乗和のみ).
	 */
	float lengthSq() const;


	/*=========================================================================*/
	/**
	 * @brief 正規化する
	 * 
	 * @param[in] なし.
	 * @return 正規化したベクトル.
	 */
	Vector3& normalize();


	/*=========================================================================*/
	/**
	 * @brief 内積を求める
	 * 
	 * @param[in] v 計算するベクトル.
	 * @return 内積の値.
	 */
	float dot( const Vector3& v ) const;


	/*=========================================================================*/
	/**
	 * @brief 外積の値を求める
	 * 
	 * @param[in] v 計算するベクトル.
	 * @return 外積の値.
	 */
	Vector3 cross( const Vector3& v ) const;


	/*=========================================================================*/
	/**
	 * @brief 仰角と方位角からベクトルを求める
	 * 
	 * @param[in] elevation 仰角.
	 * @param[in] direction 方位角.
	 * @return 求めたベクトル.
	 */
	Vector3& fromEleDir( float elevation, float direction );
	
	
	/*=========================================================================*/
	/**
	 * @brief ピッチ角とヨー角からベクトルを求める
	 * 
	 * @param[in] pitch ピッチ角.
	 * @param[in] yaw ヨー角.
	 * @return 求めたベクトル.
	 */
	Vector3& fromPitchYaw( float pitch, float yaw );


	/*=========================================================================*/
	/**
	 * @brief ベクトル同士の距離を求める
	 * 
	 * @param[in] other 距離を求めるベクトル.
	 * @return ベクトルの距離.
	 */
	float distance( const Vector3& other );

	
	/*=========================================================================*/
	/**
	 * @brief ベクトル同士の距離を求める(ルートを取らない)
	 * 
	 * @param[in] other 距離を求めるベクトル.
	 * @return ベクトルの距離(２乗和のみ).
	 */
	float distanceSq( const Vector3& other );
	
	
	/*=========================================================================*/
	/**
	 * @brief ベクトル同士が作る角度を求める
	 * 
	 * @param[in] other 角度を求める相手ベクトル.
	 * @return 角度.
	 */
	float innerDegree( const Vector3& other );


	/*=========================================================================*/
	/**
	 * @brief 面法線を求める
	 * 
	 * @param[in] vec1 頂点.
	 * @param[in] vec2 頂点.
	 * @return 法線ベクトル.
	 */
	Vector3 calculateNoamal( const Vector3& vec1, const Vector3& vec2 );

	
	/*=========================================================================*/
	/**
	 * @brief 直線の方程式の計算を行う
	 * 
	 * @param[in] p ベクトル1.
	 * @param[in] v ベクトル2.
	 * @param[in] t 係数.
	 * @return 結果のベクトル.
	 */
	Vector3 linearEquation( const Vector3& p, const Vector3& v, float t );


	/*=========================================================================*/
	/**
	 * @brief ベクトルの線形補間を行う
	 * 
	 * @param[in] min 最小値.
	 * @param[in] max 最大値.
	 * @param[in] t 補間値( 0.0f～1.0f ).
	 * @return 結果のベクトル.
	 */
	Vector3& lerp( const Vector3& min, const Vector3& max, float t );


	/*=========================================================================*/
	/**
	 * @brief ベクトルの2次補間を行う
	 * 
	 * @param[in] v1 補間要素3次元ベクトル.
	 * @param[in] v2 補間要素3次元ベクトル.
	 * @param[in] v3 3次元ベクトル.
	 * @param[in] t 補間値( 0.0f～1.0f ).
	 * @return 結果のベクトル.
	 */
	Vector3& quadratic( const Vector3& v1, const Vector3& v2, const Vector3& v3, float t );
	
	
	/*=========================================================================*/
	/**
	 * @brief ベクトルを座標変換する
	 * 
	 * @param[in] matrix 変換行列.
	 * @return 結果.
	 */
	Vector3& transform( const Matrix4& matrix );
	
	
	/*=========================================================================*/
	/**
	 * @brief 法線ベクトルを座標変換する
	 * 
	 * @param[in] matrix 変換行列.
	 * @return 結果.
	 */
	Vector3& transformNormal( const Matrix4& matrix );

	
	/*=========================================================================*/
	/**
	 * @brief xy値から2次元ベクトルを作成する
	 * 
	 * @param[in] なし.
	 * @return 2次元ベクトル.
	 */
	Vector2 xy();
	
	
	/*=========================================================================*/
	/**
	 * @brief ＋演算子オーバーロード
	 * 
	 * @param[in] なし.
	 * @return 意味なし.
	 */
	Vector3	operator + () const;


	/*=========================================================================*/
	/**
	 * @brief -演算子オーバーロード
	 * 
	 * @param[in] なし.
	 * @return 逆ベクトル.
	 */
	Vector3	operator - () const;


	/*=========================================================================*/
	/**
	 * @brief +=演算子オーバーロード
	 * 
	 * @param[in] v 加算するベクトル.
	 * @return 演算結果のベクトル.
	 */
	Vector3& operator += ( const Vector3& v);


	/*=========================================================================*/
	/**
	 * @brief -=演算子オーバーロード
	 * 
	 * @param[in] v 減算するベクトル.
	 * @return 演算結果のベクトル.
	 */
	Vector3& operator -= ( const Vector3& v );


	/*=========================================================================*/
	/**
	 * @brief *=演算子オーバーロード
	 * 
	 * @param[in] v 乗算するベクトル.
	 * @return 演算結果のベクトル.
	 */
	Vector3& operator *= ( const Vector3& v );
	
	
	/*=========================================================================*/
	/**
	 * @brief *=演算子オーバーロード
	 * 
	 * @param[in] s 乗算するスカラー.
	 * @return 演算結果のベクトル.
	 */
	Vector3& operator *= ( float s );
	

	/*=========================================================================*/
	/**
	 * @brief /=演算子オーバーロード
	 * 
	 * @param[in] v 除算するベクトル.
	 * @return 演算結果のベクトル.
	 */
	Vector3& operator /= ( const Vector3& v );
	
	
	/*=========================================================================*/
	/**
	 * @brief /=演算子オーバーロード
	 * 
	 * @param[in] s 除算するスカラー.
	 * @return 演算結果のベクトル.
	 */
	Vector3& operator /= ( float s );


	/*=========================================================================*/
	/**
	 * @brief float*演算子オーバーロード
	 * 
	 * @param[in] なし.
	 * @return キャストした値.
	 */
	operator float* () const;


	/*=========================================================================*/
	/**
	 * @brief const float*演算子オーバーロード
	 * 
	 * @param[in] なし.
	 * @return キャストした値.
	 */
	operator const float* () const;


#endif


} NGLvector3;


#ifdef __cplusplus


/** ゼロベクトル */
static const Vector3 VECTOR3_ZERO = Vector3( 0.0f, 0.0f, 0.0f );

/** 単位ベクトル */
static const Vector3 VECTOR3_IDENTITY = Vector3( 1.0f, 1.0f, 1.0f );

/** 上方向ベクトル */
static const Vector3 VECTOR3_UP = Vector3( 0.0f, 1.0f, 0.0f );


}	// namespace Ngl

/*===========================================================================*/
/**
 * @brief +演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v1 演算するベクトル1.
 * @param[in] v2 演算するベクトル2.
 * @return 演算結果のベクトル.
 */
const Ngl::Vector3 operator + ( const Ngl::Vector3& v1, const Ngl::Vector3& v2 );


/*===========================================================================*/
/**
 * @brief -演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v1 演算するベクトル1.
 * @param[in] v2 演算するベクトル2.
 * @return 演算結果のベクトル.
 */
const Ngl::Vector3 operator - ( const Ngl::Vector3& v1, const Ngl::Vector3& v2 );


/*===========================================================================*/
/**
 * @brief *演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v1 演算するベクトル1.
 * @param[in] v2 演算するベクトル2.
 * @return 演算結果のベクトル.
 */
const Ngl::Vector3 operator * ( const Ngl::Vector3& v1, const Ngl::Vector3& v2 );


/*===========================================================================*/
/**
 * @brief *演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v 演算するベクトル1.
 * @param[in] s 演算するスカラー.
 * @return 演算結果のベクトル.
 */
const Ngl::Vector3 operator * ( const Ngl::Vector3& v, float s );


/*===========================================================================*/
/**
 * @brief *演算子オーバーロード　非メンバ関数
 * 
 * @param[in] s 演算するスカラー.
 * @param[in] v 演算するベクトル.
 * @return 演算結果のベクトル.
 */
const Ngl::Vector3 operator * ( float s, const Ngl::Vector3& v );


/*===========================================================================*/
/**
 * @brief /演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v1 演算するベクトル1.
 * @param[in] v2 演算するベクトル2.
 * @return 演算結果のベクトル.
 */
const Ngl::Vector3 operator / ( const Ngl::Vector3& v1, const Ngl::Vector3& v2 );


/*===========================================================================*/
/**
 * @brief /演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v 演算するベクトル.
 * @param[in] s 演算するスカラー.
 * @return 演算結果のベクトル.
 */
const Ngl::Vector3 operator / ( const Ngl::Vector3& v, float s );


/*=========================================================================*/
/**
 * @brief ==演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値, false 違う値.
 */
bool operator == ( const Ngl::Vector3& v1, const Ngl::Vector3& v2 );


/*=========================================================================*/
/**
 * @brief !=演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値, false 違う値.
 */
bool operator != ( const Ngl::Vector3& v1, const Ngl::Vector3& v2 );


/*=========================================================================*/
/**
 * @brief <演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値,
 */
bool operator < ( const Ngl::Vector3& v1, const Ngl::Vector3& v2 );


/*=========================================================================*/
/**
 * @brief <演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値,
 */
bool operator > ( const Ngl::Vector3& v1, const Ngl::Vector3& v2 );


/*=========================================================================*/
/**
 * @brief <=演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値,
 */
bool operator <= ( const Ngl::Vector3& v1, const Ngl::Vector3& v2 );


/*=========================================================================*/
/**
 * @brief >=演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値,
 */
bool operator >= ( const Ngl::Vector3& v1, const Ngl::Vector3& v2 );


#endif


#endif

/*========= EOF =============================================================*/