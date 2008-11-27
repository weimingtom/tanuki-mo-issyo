/*******************************************************************************/
/**
 * @file TextureFilterColorKeyAuto.cpp.
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
#include	"Ngl/TextureFilterColorKeyAuto.h"

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
TextureFilterColorKeyAuto::TextureFilterColorKeyAuto():
	r_( 0 ),
	g_( 0 ),
	b_( 0 ),
	a_( 255 ),
	setFlag_( false )
{}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
TextureFilterColorKeyAuto::~TextureFilterColorKeyAuto()
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
void TextureFilterColorKeyAuto::operator () ( unsigned char* texel )
{
	// カラーキーが設定されていないか
	if( setFlag_ == false ){
		// カラーキーを設定
		r_ = texel[ 0 ];
		g_ = texel[ 1 ];
		b_ = texel[ 2 ];
		a_ = texel[ 3 ];
		setFlag_ = true;
	}

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