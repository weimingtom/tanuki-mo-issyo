/*******************************************************************************/
/**
 * @file Random.cpp.
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
#include	"Ngl/Random/Random.h"
#include	<ctime>
#include	<cstdlib>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 *
 * @param[in] なし.
 */
Random::Random()
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
void Random::srand()
{
	srand( (unsigned int)time( 0 ) );
}



/*=========================================================================*/
/**
 * @brief 乱数の種を初期化
 * 
 * @param[in] seed 初期化する値.
 * @return なし.
 */
void Random::srand( unsigned int seed )
{
	::srand( seed );
}



/*=========================================================================*/
/**
 * @brief 32bit整数型の乱数を作成
 * 
 * @param[in] なし.
 * @return 32bit整数の乱数.
 */
unsigned int Random::randi()
{
	return rand();
}



/*=========================================================================*/
/**
 * @brief min以上max以下の間の32bit整数型の乱数を作成
 * 
 * @param[in] min 乱数の最小値.
 * @param[in] max 乱数の最大値.
 * @return 32bit整数の乱数.
 */
unsigned int Random::randi( unsigned int min, unsigned int max )
{
	return ( rand() / RAND_MAX ) * ( max - min ) + min;
}



/*=========================================================================*/
/**
 * @brief 32bit浮動小数点型の乱数( 0.0～1.0 )を作成
 * 
 * @param[in] なし.
 * @return 32bit浮動小数点の乱数.
 */
float Random::randf()
{
	return ( (float)rand() / RAND_MAX );
}



/*=========================================================================*/
/**
 * @brief min以上max以下の間の32bit整数型の乱数を作成
 * 
 * @param[in] なし.
 * @return 32bit浮動小数点の乱数.
 */
float Random::randf( float min, float max )
{
	return ( (float)rand() / RAND_MAX ) * ( max - min ) + min;
}



/*=========================================================================*/
/**
 * @brief 32bit浮動小数点型の乱数( 0.0～1.0 )を作成
 * 
 * @param[in] なし.
 * @return 32bit浮動小数点の乱数.
 */
double Random::randd()
{
	return ( (double)rand() / RAND_MAX );
}



/*=========================================================================*/
/**
 * @brief min以上max以下の間の32bit整数型の乱数を作成
 * 
 * @param[in] なし.
 * @return 32bit浮動小数点の乱数.
 */
double Random::randd( double min, double max )
{
	return ( (double)rand() / RAND_MAX ) * ( max - min ) + min;
}



/*===== EOF ==================================================================*/