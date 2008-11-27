/*******************************************************************************/
/**
 * @file Random.h.
 * 
 * @brief 乱数生成クラスヘッダファイル.
 *
 * @date 2008/07/23.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_RANDOM_H_
#define _NGL_RANDOM_H_

namespace Ngl{


/**
 * @class Random．
 * @brief 乱数生成クラス.
 *
 * SFMT（メルセンヌツイスター）による乱数を生成するユーティリティクラスです。
 */
class Random
{

public:

	/*=========================================================================*/
	/**
	 * @brief 乱数の種を初期化( 自動 )
	 *
	 * 現在の時刻から乱数を初期化します。
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	static void srand();
	
	
	/*=========================================================================*/
	/**
	 * @brief 乱数の種を初期化
	 * 
	 * @param[in] seed 初期化する値.
	 * @return なし.
	 */
	static void srand( unsigned int seed );


	/*=========================================================================*/
	/**
	 * @brief 32bit整数型の乱数を作成
	 * 
	 * @param[in] なし.
	 * @return 32bit整数の乱数.
	 */
	static unsigned int randi();


	/*=========================================================================*/
	/**
	 * @brief min以上max以下の間の32bit整数型の乱数を作成
	 * 
	 * @param[in] min 乱数の最小値.
	 * @param[in] max 乱数の最大値.
	 * @return 32bit整数の乱数.
	 */
	static unsigned int randi( unsigned int min, unsigned int max );

public:

	/**
	 * @enum Random::RangeType.
	 * @brief 乱数生成幅列挙型.
	 */
	enum RangeType
	{
		RANGETYPE_REAL1	= 0,	/**< [0,1] (0と1を含む) (32ビット精度)				*/
		RANGETYPE_REAL2,		/**< [0,1) (0は含むが、1は含まない) (32ビット精度)	*/
		RANGETYPE_REAL3,		/**< (0,1) (0も1も含まない) (32ビット精度)			*/
		RANGETYPE_REAL53		/**< [0,1) (0は含むが、1は含まない) (53ビット精度)	*/
	};

public:

	/*=========================================================================*/
	/**
	 * @brief 32bit浮動小数点型の乱数( 0.0～1.0 )を作成
	 * 
	 * @param[in] type 乱数生成範囲.
	 * @return 32bit浮動小数点の乱数.
	 */
	static float randf( RangeType type=RANGETYPE_REAL1 );
	
	
	/*=========================================================================*/
	/**
	 * @brief min以上max以下の間の32bit整数型の乱数を作成
	 * 
	 * @param[in] type 乱数生成範囲.
	 * @return 32bit浮動小数点の乱数.
	 */
	static float randf( float min, float max, RangeType type=RANGETYPE_REAL1 );

	
	/*=========================================================================*/
	/**
	 * @brief 32bit浮動小数点型の乱数( 0.0～1.0 )を作成
	 * 
	 * @param[in] type 乱数生成範囲.
	 * @return 32bit浮動小数点の乱数.
	 */
	static double randd( RangeType type=RANGETYPE_REAL1 );


	/*=========================================================================*/
	/**
	 * @brief min以上max以下の間の32bit整数型の乱数を作成
	 * 
	 * @param[in] type 乱数生成範囲.
	 * @return 32bit浮動小数点の乱数.
	 */
	static double randd( double min, double max, RangeType type=RANGETYPE_REAL1 );
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/