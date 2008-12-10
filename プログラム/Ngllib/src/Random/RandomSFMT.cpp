/*******************************************************************************/
/**
 * @file RandomSFMT.cpp.
 * 
 * @brief 乱数生成クラスソースファイル.
 *
 * @date 2008/07/23.
 * 
 * @version 2.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Random/RandomSFMT.h"
#include	"SFMT/SFMT.h"
#include	"SFMT/SFMT.c" 
#include	<ctime>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 *
 * @param[in] なし.
 */
RandomSFMT::RandomSFMT()
{
	srand();
}

	
	
/*=========================================================================*/
/**
 * @brief 乱数の種を初期化( 自動 )
 *
 * 現在の時刻から乱数を初期化します。
 * 
 * @param[in] なし.
 * @return なし.
 */
void RandomSFMT::srand()
{
	unsigned long t  = (unsigned long)time( 0 );
	::init_gen_rand( t );
}



/*=========================================================================*/
/**
 * @brief 乱数の種を初期化
 * 
 * @param[in] seed 初期化する値.
 * @return なし.
 */
void RandomSFMT::srand( unsigned int seed )
{
	::init_gen_rand( seed );
}



/*=========================================================================*/
/**
 * @brief 32bit整数型の乱数を作成
 * 
 * @param[in] なし.
 * @return なし.
 */
unsigned int RandomSFMT::randi()
{
	return ::gen_rand32();
}



/*=========================================================================*/
/**
 * @brief min～maxの間の32bit整数型の乱数を作成
 * 
 * @param[in] min 乱数の最小値.
 * @param[in] max 乱数の最大値.
 * @return 32bit整数の乱数.
 */
unsigned int RandomSFMT::randi( unsigned int min, unsigned int max )
{
	return ( randi() % ( ( max + 1 ) - min ) ) + min;
}

	

/*=========================================================================*/
/**
 * @brief 32bit浮動小数点型の乱数( 0.0～1.0 )を作成
 * 
 * @param[in] type 乱数生成範囲.
 * @return 32bit浮動小数点の乱数.
 */
float RandomSFMT::randf( RangeType type )
{
	return static_cast< float >( randd( type ) );
}



/*=========================================================================*/
/**
 * @brief min以上max以下の間の32bit整数型の乱数を作成
 * 
 * @param[in] min 乱数の最小値.
 * @param[in] max 乱数の最大値.
 * @param[in] type 乱数生成範囲.
 * @return 32bit浮動小数点の乱数.
 */
float RandomSFMT::randf( float min, float max, RangeType type )
{
	return static_cast< float >( randd( min, max, type ) );
}


	
/*=========================================================================*/
/**
 * @brief 32bit浮動小数点型の乱数( 0.0～1.0 )を作成
 * 
 * @param[in] type 乱数生成範囲.
 * @return 32bit浮動小数点の乱数.
 */
double RandomSFMT::randd( RandomSFMT::RangeType type )
{
	double result = 0.0;

	switch( type )
	{
	case RANGETYPE_REAL1:
		result = ::genrand_real1();
		break;
	case RANGETYPE_REAL2:
		result = ::genrand_real2();
		break;
	case RANGETYPE_REAL3:
		result = ::genrand_real3();
		break;
	case RANGETYPE_REAL53:
		result = ::genrand_res53();
		break;
	default:
		result = ::genrand_real1();
	}

	return result;
}

	
	
/*=========================================================================*/
/**
 * @brief min以上max以下の間の32bit整数型の乱数を作成
 *
 * @param[in] min 乱数の最小値.
 * @param[in] max 乱数の最大値.
 * @param[in] type 乱数生成範囲.
 * @return 32bit浮動小数点の乱数.
 */
double RandomSFMT::randd( double min, double max, RangeType type )
{
	return ( randd( type ) * ( max - min ) + min );
}

	
	
/*===== EOF ==================================================================*/