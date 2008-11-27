/*******************************************************************************/
/**
 * @file Vector4.h.
 * 
 * @brief 4次元ベクトル構造体ヘッダファイル.
 *
 * @date 2008/07/02.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_VECTOR4_H_
#define _NGL_VECTOR4_H_


#ifdef __cplusplus
namespace Ngl{

// 3次元ベクトル
struct Vector3;

// 4x4構造体
struct Matrix4;

#endif


/**
 * @struct Vector4．
 * @brief 4次元ベクトル構造体.
 */
typedef struct Vector4 
{
	/**	x成分	*/
	float	x;

	/**	y成分	*/
	float	y;

	/**	z成分	*/
	float	z;

	/** w成分 */
	float	w;


#ifdef __cplusplus


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	Vector4();

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] X x値.
	 * @param[in] Y y値.
	 * @param[in] Z z値.
	 * @param[in] W w値.
	 */
	Vector4( float X, float Y, float Z, float W );


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] V 3次元ベクトル.
	 * @param[in] W w値.
	 */
	Vector4( const Vector3& V, float W=0.0f );

	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] other 代入する配列.
	 */
	Vector4( float* other );


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
	 * @param[in] W w値.
	 * @return なし.
	 */
	void initialize( float X, float Y, float Z, float W );


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
	Vector4& normalize();


	/*=========================================================================*/
	/**
	 * @brief 内積を求める
	 * 
	 * @param[in] v 計算するベクトル.
	 * @return 内積の値.
	 */
	float dot( const Vector4& v ) const;
	
	
	/*=========================================================================*/
	/**
	 * @brief 仰角と方位角からベクトルを求める
	 * 
	 * @param[in] elevation 仰角.
	 * @param[in] direction 方位角.
	 * @return 求めたベクトル.
	 */
	Vector4& fromEleDir( float elevation, float direction );
	
	
	/*=========================================================================*/
	/**
	 * @brief ピッチ角とヨー角からベクトルを求める
	 * 
	 * @param[in] pitch ピッチ角.
	 * @param[in] yaw ヨー角.
	 * @return 求めたベクトル.
	 */
	Vector4& fromPitchYaw( float pitch, float yaw );


	/*=========================================================================*/
	/**
	 * @brief ベクトル同士の距離を求める
	 * 
	 * @param[in] other 距離を求めるベクトル.
	 * @return ベクトルの距離.
	 */
	float distance( const Vector4& other );

	
	/*=========================================================================*/
	/**
	 * @brief ベクトル同士の距離を求める(ルートを取らない)
	 * 
	 * @param[in] other 距離を求めるベクトル.
	 * @return ベクトルの距離(２乗和のみ).
	 */
	float distanceSq( const Vector4& other );
	
	
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
	 * @brief 直線の方程式の計算を行う
	 * 
	 * @param[in] p ベクトル1.
	 * @param[in] v ベクトル2.
	 * @param[in] t 係数.
	 * @return 結果のベクトル.
	 */
	Vector4 linearEquation( const Vector4& p, const Vector4& v, float t );

	
	/*=========================================================================*/
	/**
	 * @brief ベクトルの線形補間を行う
	 * 
	 * @param[in] min 最小値.
	 * @param[in] max 最大値.
	 * @param[in] t 補間値( 0.0f～1.0f ).
	 * @return 結果のベクトル.
	 */
	Vector4& lerp( const Vector4& min, const Vector4& max, float t );


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
	Vector4& quadratic( const Vector4& v1, const Vector4& v2, const Vector4& v3, float t );
	
	
	/*=========================================================================*/
	/**
	 * @brief ベクトルを座標変換する
	 * 
	 * @param[in] matrix 変換行列.
	 * @return 結果.
	 */
	Vector4& transform( const Matrix4& matrix );
	
	
	/*=========================================================================*/
	/**
	 * @brief ＋演算子オーバーロード
	 * 
	 * @param[in] なし.
	 * @return 意味なし.
	 */
	Vector4	operator + () const;


	/*=========================================================================*/
	/**
	 * @brief -演算子オーバーロード
	 * 
	 * @param[in] なし.
	 * @return 逆ベクトル.
	 */
	Vector4	operator - () const;


	/*=========================================================================*/
	/**
	 * @brief +=演算子オーバーロード
	 * 
	 * @param[in] v 加算するベクトル.
	 * @return 演算結果のベクトル.
	 */
	Vector4& operator += ( const Vector4& v);


	/*=========================================================================*/
	/**
	 * @brief -=演算子オーバーロード
	 * 
	 * @param[in] v 減算するベクトル.
	 * @return 演算結果のベクトル.
	 */
	Vector4& operator -= ( const Vector4& v );


	/*=========================================================================*/
	/**
	 * @brief *=演算子オーバーロード
	 * 
	 * @param[in] v 乗算するベクトル.
	 * @return 演算結果のベクトル.
	 */
	Vector4& operator *= ( const Vector4& v );
	
	
	/*=========================================================================*/
	/**
	 * @brief *=演算子オーバーロード
	 * 
	 * @param[in] s 乗算するスカラー.
	 * @return 演算結果のベクトル.
	 */
	Vector4& operator *= ( float s );
	

	/*=========================================================================*/
	/**
	 * @brief /=演算子オーバーロード
	 * 
	 * @param[in] v 除算するベクトル.
	 * @return 演算結果のベクトル.
	 */
	Vector4& operator /= ( const Vector4& v );
	
	
	/*=========================================================================*/
	/**
	 * @brief /=演算子オーバーロード
	 * 
	 * @param[in] s 除算するスカラー.
	 * @return 演算結果のベクトル.
	 */
	Vector4& operator /= ( float s );

	
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


} NGLvector4;


#ifdef __cplusplus


/** ゼロベクトル */
static const Vector4 VECTOR4_ZERO = Vector4( 0.0f, 0.0f, 0.0f, 0.0f );

/** 単位ベクトル */
static const Vector4 VECTOR4_IDENTITY = Vector4( 1.0f, 1.0f, 1.0f, 1.0f );


} // namespace Ngl

/*===========================================================================*/
/**
 * @brief +演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v1 演算するベクトル1.
 * @param[in] v2 演算するベクトル2.
 * @return 演算結果のベクトル.
 */
const Ngl::Vector4 operator + ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 );


/*===========================================================================*/
/**
 * @brief -演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v1 演算するベクトル1.
 * @param[in] v2 演算するベクトル2.
 * @return 演算結果のベクトル.
 */
const Ngl::Vector4 operator - ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 );


/*===========================================================================*/
/**
 * @brief *演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v1 演算するベクトル1.
 * @param[in] v2 演算するベクトル2.
 * @return 演算結果のベクトル.
 */
const Ngl::Vector4 operator * ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 );


/*===========================================================================*/
/**
 * @brief *演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v 演算するベクトル1.
 * @param[in] s 演算するスカラー.
 * @return 演算結果のベクトル.
 */
const Ngl::Vector4 operator * ( const Ngl::Vector4& v, float s );


/*===========================================================================*/
/**
 * @brief *演算子オーバーロード　非メンバ関数
 * 
 * @param[in] s 演算するスカラー.
 * @param[in] v 演算するベクトル.
 * @return 演算結果のベクトル.
 */
const Ngl::Vector4 operator * ( float s, const Ngl::Vector4& v );


/*===========================================================================*/
/**
 * @brief /演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v1 演算するベクトル1.
 * @param[in] v2 演算するベクトル2.
 * @return 演算結果のベクトル.
 */
const Ngl::Vector4 operator / ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 );


/*===========================================================================*/
/**
 * @brief /演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v 演算するベクトル.
 * @param[in] s 演算するスカラー.
 * @return 演算結果のベクトル.
 */
const Ngl::Vector4 operator / ( const Ngl::Vector4& v, float s );


/*=========================================================================*/
/**
 * @brief ==演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値, false 違う値.
 */
bool operator == ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 );


/*=========================================================================*/
/**
 * @brief !=演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値, false 違う値.
 */
bool operator != ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 );


/*=========================================================================*/
/**
 * @brief <演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値,
 */
bool operator < ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 );


/*=========================================================================*/
/**
 * @brief <演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値,
 */
bool operator > ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 );


/*=========================================================================*/
/**
 * @brief <=演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値,
 */
bool operator <= ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 );


/*=========================================================================*/
/**
 * @brief >=演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値,
 */
bool operator >= ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 );


#endif


#endif

/*===== EOF ==================================================================*/