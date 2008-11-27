/*******************************************************************************/
/**
 * @file Color4.h.
 * 
 * @brief RGBAカラー構造体ヘッダファイル.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_COLOR4_H_
#define _NGL_COLOR4_H_

#ifdef __cplusplus
namespace Ngl{
#endif


/**
 * @struct Color4
 * @brief RGBAカラー構造体．
 */
typedef struct Color4
{
	/** r成分 */
	float	r;

	/** g成分 */
	float	g;

	/** g成分 */
	float	b;

	/** a成分 */
	float	a;


#ifdef __cplusplus


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	Color4();


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] R 赤成分.
	 * @param[in] G 緑成分.
	 * @param[in] B 青成分.
	 * @param[in] A アルファ成分
	 */
	Color4(float R, float G, float B, float A);


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] other カラー配列のポインタ.
	 */
	Color4( float* other );


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
	 * @param[in] R 赤成分.
	 * @param[in] G 緑成分.
	 * @param[in] B 青成分.
	 * @param[in] A アルファ成分
	 * @return なし.
	 */
	void initialize( float R, float G, float B, float A );

	
	/*=========================================================================*/
	/**
	 * @brief 255～0の範囲にクランプ
	 * 
	 * @param[in] なし.
	 * @return クランプされたcolor.
	 */
	Color4& saturate();


	/*=========================================================================*/
	/**
	 * @brief 16進数の値に変換
	 * 
	 * @param[in] なし.
	 * @return 変換した値.
	 */
	unsigned long changeHexaDecimal() const;


	/*=========================================================================*/
	/**
	 * @brief RGB値からカラーを設定する
	 * @param[in] R 赤成分.
	 * @param[in] G 緑成分.
	 * @param[in] B 青成分.
	 * @return 変換した値.
	 */
	Color4& setColorOfRGB( int R, int G, int B );

	
	/*=========================================================================*/
	/**
	 * @brief RGBA値からカラーを設定する
	 * @param[in] R 赤成分.
	 * @param[in] G 緑成分.
	 * @param[in] B 青成分.
	 * @param[in] A アルファ成分.
	 * @return 変換した値.
	 */
	Color4& setColorOfRGBA( int R, int G, int B, int A );

	
	/*=========================================================================*/
	/**
	 * @brief + 演算子オーバーロード
	 * 
	 * @param[in] なし.
	 * @return 演算したcolorの値.
	 */
	Color4 operator + () const;


	/*=========================================================================*/
	/**
	 * @brief - 演算子オーバーロード, 補色を求める
	 * 
	 * @param[in] なし.
	 * @return 演算したcolorの値.
	 */
	Color4 operator - () const;

	
	/*=========================================================================*/
	/**
	 * @brief += 演算子オーバーロード
	 * 
	 * @param[in] c2 演算するカラー.
	 * @return 演算したcolorの値.
	 */
	Color4& operator += (const Color4& c2);
	

	/*=========================================================================*/
	/**
	 * @brief -= 演算子オーバーロード
	 * 
	 * @param[in] c2 演算するカラー.
	 * @return 演算したcolorの値.
	 */
	Color4& operator -= (const Color4& c2);
	
	
	/*=========================================================================*/
	/**
	 * @brief *= 演算子オーバーロード
	 * 
	 * @param[in] c2 演算するカラー.
	 * @return 演算したcolorの値.
	 */
	Color4& operator *= (const Color4& c2);


	/*=========================================================================*/
	/**
	 * @brief *= 演算子オーバーロード
	 * 
	 * @param[in] s 演算する値.
	 * @return 演算したcolorの値.
	 */
	Color4& operator *= (float s);
	
	
	/*=========================================================================*/
	/**
	 * @brief *= 演算子オーバーロード
	 * 
	 * @param[in] s 演算する値.
	 * @return 演算したcolorの値.
	 */
	Color4& operator *= (int s);
	
	
	/*=========================================================================*/
	/**
	 * @brief /= 演算子オーバーロード
	 * 
	 * @param[in] c2 演算するカラー.
	 * @return 演算したcolorの値.
	 */
	Color4& operator /= (const Color4& c2);
	
	
	/*=========================================================================*/
	/**
	 * @brief /= 演算子オーバーロード
	 * 
	 * @param[in] s 演算する値.
	 * @return 演算したcolorの値.
	 */
	Color4& operator /= (int s);


	/*=========================================================================*/
	/**
	 * @brief float* 演算子オーバーロード
	 * 
	 * @param[in] なし.
	 * @return キャストしたfloat型の値.
	 */
	operator float *() const;


	/*=========================================================================*/
	/**
	 * @brief const float* 演算子オーバーロード
	 * 
	 * @param[in] なし.
	 * @return キャストしたconst float*型の値.
	 */
	operator const float *() const;


#endif


} NGLcolor4;


#ifdef __cplusplus


/** ホワイト */
static const Ngl::Color4 COLOR4_WHITE = Ngl::Color4( 1.0f, 1.0f, 1.0f, 1.0f );

/** 赤 */
static const Ngl::Color4 COLOR4_RED = Ngl::Color4( 1.0f, 0.0f, 0.0f, 1.0f );

/** 緑 */
static const Ngl::Color4 COLOR4_GREEN = Ngl::Color4( 0.0f, 1.0f, 0.0f, 1.0f );

/** 青 */
static const Ngl::Color4 COLOR4_BLUE = Ngl::Color4( 0.0f, 0.0f, 1.0f, 1.0f );

/** 黒 */
static const Ngl::Color4 COLOR4_BLACK = Ngl::Color4( 0.0f, 0.0f, 0.0f, 1.0f );


}	// namespace Ngl


/*===========================================================================*/
/**
 * @brief + 演算子オーバーロード
 * 
 * @param[in] c1 演算するカラー.
 * @param[in] c2 演算するカラー.
 * @return 演算した結果.
 */
const Ngl::Color4 operator + (const Ngl::Color4& c1, const Ngl::Color4& c2);


/*===========================================================================*/
/**
 * @brief - 演算子オーバーロード
 * 
 * @param[in] c1 演算するカラー.
 * @param[in] c2 演算するカラー.
 * @return 演算した結果.
 */
const Ngl::Color4 operator - (const Ngl::Color4& c1, const Ngl::Color4& c2);


/*===========================================================================*/
/**
 * @brief * 演算子オーバーロード
 * 
 * @param[in] c1 演算するカラー.
 * @param[in] c2 演算するカラー.
 * @return 演算した結果.
 */
const Ngl::Color4 operator * (const Ngl::Color4& c1, const Ngl::Color4& c2);


/*===========================================================================*/
/**
 * @brief * 演算子オーバーロード
 * 
 * @param[in] s 演算する値.
 * @param[in] c 演算するカラー.
 * @return 演算した結果.
 */
const Ngl::Color4 operator * (float s, const Ngl::Color4& c);


/*===========================================================================*/
/**
 * @brief * 演算子オーバーロード
 * 
 * @param[in] c 演算するカラー.
 * @param[in] s 演算する値.
 * @return 演算した結果.
 */
const Ngl::Color4 operator * (const Ngl::Color4& c, float s);


/*===========================================================================*/
/**
 * @brief * 演算子オーバーロード
 * 
 * @param[in] s 演算する値.
 * @param[in] c 演算するカラー.
 * @return 演算した結果.
 */
const Ngl::Color4 operator * (int s, const Ngl::Color4& c);


/*===========================================================================*/
/**
 * @brief * 演算子オーバーロード
 * 
 * @param[in] c 演算するカラー.
 * @param[in] s 演算する値.
 * @return 演算した結果.
 */
const Ngl::Color4 operator * (const Ngl::Color4& c, int s);


/*===========================================================================*/
/**
 * @brief / 演算子オーバーロード
 * 
 * @param[in] c 演算するカラー.
 * @param[in] s 演算する値.
 * @return 演算した結果.
 */
const Ngl::Color4 operator / (const Ngl::Color4& c, int s);


#endif


#endif

/*========= EOF =============================================================*/