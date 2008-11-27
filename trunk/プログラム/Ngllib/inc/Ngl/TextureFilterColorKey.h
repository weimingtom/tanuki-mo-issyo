/*******************************************************************************/
/**
 * @file TextureFilterColorKey.h.
 * 
 * @brief カラーキーテクスチャフィルタクラスヘッダファイル.
 *
 * @date 2008/08/23.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_TEXTUREFILTERCOLORKEY_H_
#define _NGL_TEXTUREFILTERCOLORKEY_H_

#include	"ITextureFilter.h"

namespace Ngl{


// カラー型
struct Color4;

/**
 * @class TextureFilterColorKey．
 * @brief カラーキーテクスチャフィルタクラス.
 */
class TextureFilterColorKey : public ITextureFilter
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] r カラーキー赤成分( 整数値 0～255 or 16進数 0x00～0xff ).
	 * @param[in] g カラーキー緑成分( 整数値 0～255 or 16進数 0x00～0xff ).
	 * @param[in] b カラーキー青成分( 整数値 0～255 or 16進数 0x00～0xff ).
	 * @param[in] a カラーキーアルファ成分( 整数値 0～255 or 16進数 0x00～0xff  ).
	 */
	TextureFilterColorKey( unsigned char r=0, unsigned char g=0, unsigned char b=0, unsigned char a=255 );


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] color カラーキー( 浮動小数点値 0.0f～1.0f ).
	 */
	TextureFilterColorKey( const Color4& color );

	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~TextureFilterColorKey();


	/*=========================================================================*/
	/**
	 * @brief () 演算子オーバーロード
	 * 
	 * ピクセルを加工する.
	 *
	 * @param[in] texel 加工するピクセル値.
	 * @return なし.
	 */
	virtual void operator () ( unsigned char* texel );

private:

	/** カラーキー赤成分 */
	unsigned char r_;

	/** カラーキー緑成分 */
	unsigned char g_;

	/** カラーキー青成分 */
	unsigned char b_;

	/** カラーキーアルファ成分 */
	unsigned char a_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/