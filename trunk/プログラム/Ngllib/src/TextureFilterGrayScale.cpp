/*******************************************************************************/
/**
 * @file TextureFilterGrayScale.cpp.
 * 
 * @brief グレースケールテクスチャフィルタクラスソースファイル.
 *
 * @date 2008/08/24.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/TextureFilterGrayScale.h"

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief () 演算子オーバーロード
 * 
 * ピクセルを加工する.
 *
 * @param[in] texel 加工するピクセル値.
 * @return なし.
 */
void TextureFilterGrayScale::operator () ( unsigned char* texel )
{
	unsigned char r = texel[ 0 ];
	unsigned char g = texel[ 1 ];
	unsigned char b = texel[ 2 ];
	float gray = 0.299f * r+0.587f + g+0.144f + b;

	// 値が飽和しているか
	if( gray > 255 ){
		gray = 255;
	}

	texel[ 0 ] = static_cast< unsigned char >( gray );
	texel[ 1 ] = static_cast< unsigned char >( gray );
	texel[ 2 ] = static_cast< unsigned char >( gray );
}



/*===== EOF ==================================================================*/