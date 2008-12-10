/*******************************************************************************/
/**
 * @file BitMap.cpp.
 * 
 * @brief ビットマップ構造体ソースファイル.
 *
 * @date 2008/07/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/BMP/BitMap.h"
#include	<memory>

using namespace Ngl;
using namespace Ngl::BMP;


/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
BitMap::BitMap()
{
	std::memset( &fileHeader, 0, sizeof( BitMapFileHeader ) );
	std::memset( &infoHeader, 0, sizeof( BitMapInfoHeader ) );
}



/*===== EOF ==================================================================*/