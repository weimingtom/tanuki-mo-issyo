/*******************************************************************************/
/**
 * @file Vector2.h.
 * 
 * @brief ２次元ベクトル構造体ヘッダファイル.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef	_NGL_VECTOR2_H_
#define	_NGL_VECTOR2_H_


#ifdef __cplusplus
namespace Ngl{
#endif

/**
 * @struct Vector2.
 * @brief 2次元ベクトル構造体．
 */
typedef struct Vector2
{
	/** x成分 */
	float		x;

	/** y成分 */
	float		y;

	
#ifdef __cplusplus


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	Vector2();


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] other 配列のポインタ.
	 */
	Vector2( const float* other );
	
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] X x成分.
	 * @param[in] Y y成分.
	 */
	Vector2( float X, float Y );

	
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
	 * @param[in] X x成分.
	 * @param[in] Y y成分.
	 * @return なし.
	 */
	void initialize( float X, float Y );
	
	
	/*=========================================================================*/
	/**
	 * @brief ノルムを求める
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	float length() const;


	/*=========================================================================*/
	/**
	 * @brief 正規化する
	 * 
	 * @param[in] なし.
	 * @return 正規化したベクトル.
	 */
	Vector2& normalize();


	/*=========================================================================*/
	/**
	 * @brief 内積を求める
	 * 
	 * @param[in] v 内積を求めるベクトル.
	 * @return 内積.
	 */
	float dot( const Vector2& v ) const;


	/*=========================================================================*/
	/**
	 * @brief ベクトル同士の距離を求める
	 * 
	 * @param[in] other 距離を求めるベクトル.
	 * @return ベクトルの距離.
	 */
	float distance( const Ngl::Vector2& other );

	
	/*=========================================================================*/
	/**
	 * @brief ベクトルの線形補間を行う
	 * 
	 * @param[in] min 最小値.
	 * @param[in] max 最大値.
	 * @param[in] t 補間値( 0.0f～1.0f ).
	 * @return 結果のベクトル.
	 */
	Vector2& lerp( const Vector2& min, const Vector2& max, float t );


	/*=========================================================================*/
	/**
	 * @brief ベクトルの2次補間を行う
	 * 
	 * @param[in] v1 補間要素2次元ベクトル.
	 * @param[in] v2 補間要素2次元ベクトル.
	 * @param[in] v3 2次元ベクトル.
	 * @param[in] t 補間値( 0.0f～1.0f ).
	 * @return 結果のベクトル.
	 */
	Vector2& quadratic( const Vector2& v1, const Vector2& v2, const Vector2& v3, float t );
	
	
	/*=========================================================================*/
	/**
	 * @brief + 演算子オーバーロード
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	Vector2  operator + () const;
	
	
	/*=========================================================================*/
	/**
	 * @brief - 演算子オーバーロード 逆ベクトルを求める
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	Vector2  operator - () const;


	/*=========================================================================*/
	/**
	 * @brief += 演算子オーバーロード
	 * 
	 * @param[in] v 加算するベクトル.
	 * @return 加算結果のベクトル.
	 */
	Vector2&  operator += ( const Vector2& v );


	/*=========================================================================*/
	/**
	 * @brief -= 演算子オーバーロード
	 * 
	 * @param[in] v 減算するベクトル.
	 * @return 減算結果のベクトル.
	 */
	Vector2&  operator -= ( const Vector2& v );


	/*=========================================================================*/
	/**
	 * @brief *=演算子オーバーロード
	 * 
	 * @param[in] v 乗算するベクトル.
	 * @return 演算結果のベクトル.
	 */
	Vector2& operator *= ( const Vector2& v );
	
	
	/*=========================================================================*/
	/**
	 * @brief *= 演算子オーバーロード
	 * 
	 * @param[in] s 乗算するスカラー値.
	 * @return 乗算結果のベクトル.
	 */
	Vector2&  operator *= ( float s );


	/*=========================================================================*/
	/**
	 * @brief /=演算子オーバーロード
	 * 
	 * @param[in] v 除算するベクトル.
	 * @return 演算結果のベクトル.
	 */
	Vector2& operator /= ( const Vector2& v );
	
	
	/*=========================================================================*/
	/**
	 * @brief /= 演算子オーバーロード
	 * 
	 * @param[in] s 除算するスカラー値.
	 * @return 除算結果のベクトル.
	 */
	Vector2&  operator /= ( float s );


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
	 * @brief float*演算子オーバーロード
	 * 
	 * @param[in] なし.
	 * @return キャストした値.
	 */
	operator const float* () const;


#endif


} NGLvector2;


#ifdef __cplusplus


/** ゼロベクトル */
static const Vector2 VECTOR2_ZERO = Vector2( 0.0f, 0.0f );

/** 上方向ベクトル */
static const Vector2 VECTOR2_UP = Vector2( 0.0f, 1.0f );

}	// namespace Ngl

/*===========================================================================*/
/**
 * @brief + 演算子オーバーロード
 * 
 * @param[in] v1 加算するベクトル1.
 * @param[in] v2 加算するベクトル2.
 * @return 加算結果のベクトル.
 */
const Ngl::Vector2 operator + ( const Ngl::Vector2& v1, const Ngl::Vector2& v2 );


/*===========================================================================*/
/**
 * @brief - 演算子オーバーロード
 * 
 * @param[in] v1 減算するベクトル1.
 * @param[in] v2 減算するベクトル2.
 * @return 減算結果のベクトル.
 */
const Ngl::Vector2 operator - ( const Ngl::Vector2& v1, const Ngl::Vector2& v2 );


/*===========================================================================*/
/**
 * @brief *演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v1 演算するベクトル1.
 * @param[in] v2 演算するベクトル2.
 * @return 演算結果のベクトル.
 */
const Ngl::Vector2 operator * ( const Ngl::Vector2& v1, const Ngl::Vector2& v2 );


/*===========================================================================*/
/**
 * @brief * 演算子オーバーロード
 * 
 * @param[in] v 乗算するベクトル.
 * @param[in] s 乗算するスカラー値.
 * @return 乗算結果のベクトル.
 */
const Ngl::Vector2 operator * ( const Ngl::Vector2& v, float s );


/*===========================================================================*/
/**
 * @brief * 演算子オーバーロード
 * 
 * @param[in] s 乗算するスカラー.
 * @param[in] v 加算するベクトル2.
 * @return 加算結果のベクトル.
 */
const Ngl::Vector2 operator * ( float s, const Ngl::Vector2& v );


/*===========================================================================*/
/**
 * @brief /演算子オーバーロード　非メンバ関数
 * 
 * @param[in] v1 演算するベクトル1.
 * @param[in] v2 演算するベクトル2.
 * @return 演算結果のベクトル.
 */
const Ngl::Vector2 operator / ( const Ngl::Vector2& v1, const Ngl::Vector2& v2 );


/*===========================================================================*/
/**
 * @brief / 演算子オーバーロード
 * 
 * @param[in] v 除算するベクトル.
 * @param[in] s 除算するスカラー.
 * @return 除算結果のベクトル.
 */
const Ngl::Vector2 operator / ( const Ngl::Vector2& v, float s );


/*=========================================================================*/
/**
 * @brief ==演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値, false 違う値.
 */
bool operator == ( const Ngl::Vector2& v1, const Ngl::Vector2& v2 );


/*=========================================================================*/
/**
 * @brief !=演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値, false 違う値.
 */
bool operator != ( const Ngl::Vector2& v1, const Ngl::Vector2& v2 );


/*=========================================================================*/
/**
 * @brief <演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値,
 */
bool operator < ( const Ngl::Vector2& v1, const Ngl::Vector2& v2 );


/*=========================================================================*/
/**
 * @brief <演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値,
 */
bool operator > ( const Ngl::Vector2& v1, const Ngl::Vector2& v2 );


/*=========================================================================*/
/**
 * @brief <=演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値,
 */
bool operator <= ( const Ngl::Vector2& v1, const Ngl::Vector2& v2 );


/*=========================================================================*/
/**
 * @brief >=演算子オーバーロード
 * 
 * @param[in] v1 比較する3次元ベクトル1.
 * @param[in] v2 比較する3次元ベクトル2.
 * @return true 同じ値,
 */
bool operator >= ( const Ngl::Vector2& v1, const Ngl::Vector2& v2 );


#endif


#endif

/*===== EOF ==================================================================*/