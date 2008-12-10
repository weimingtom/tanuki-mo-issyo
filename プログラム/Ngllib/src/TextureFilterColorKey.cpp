/*******************************************************************************/
/**
 * @file TextureFilterColorKey.cpp.
 * 
 * @brief カラーキーテクスチャフィルタクラスソースファイル.
 *
 * @date 2008/08/23.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/TextureFilterColorKey.h"
#include	"Ngl/Color4.h"

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] r カラーキー赤成分( 整数値 0～255 or 16進数 0x00～0xff ).
 * @param[in] g カラーキー緑成分( 整数値 0～255 or 16進数 0x00～0xff ).
 * @param[in] b カラーキー青成分( 整数値 0～255 or 16進数 0x00～0xff ).
 * @param[in] a カラーキーアルファ成分( 整数値 0～255 or 16進数 0x00～0xff  ).
 */
TextureFilterColorKey::TextureFilterColorKey( unsigned char r, unsigned char g, unsigned char b, unsigned char a ):
	r_( r ),
	g_( g ),
	b_( b ),
	a_( a )
{}



/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] color カラーキー( 浮動小数点値 0.0f～1.0f ).
 */
TextureFilterColorKey::TextureFilterColorKey( const Color4& color ):
	r_( static_cast< unsigned char >( 255.0f * color.r ) ),
	g_( static_cast< unsigned char >( 255.0f * color.g ) ),
	b_( static_cast< unsigned char >( 255.0f * color.b ) ),
	a_( static_cast< unsigned char >( 255.0f * color.a ) )
{}

	
	
/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
TextureFilterColorKey::~TextureFilterColorKey()
{}



/*=========================================================================*/
/**
 * @brief () 演算子オーバーロード
 * 
 * ピクセルを加工する.
 *
 * @param[in] texel 加工するピクセル値.
 * @return なし.
 */
void TextureFilterColorKey::operator () ( unsigned char* texel )
{
	// カラーキーと同じピクセルか調べる
	if( texel[ 0 ] == r_ &&
		texel[ 1 ] == g_ &&
		texel[ 2 ] == b_ &&
		texel[ 3 ] == a_
		){

		// テクセル値を0にする
		texel[ 0 ] = 0x00;
		texel[ 1 ] = 0x00;
		texel[ 2 ] = 0x00;
		texel[ 3 ] = 0x00;
	}
}



/*===== EOF ==================================================================*/