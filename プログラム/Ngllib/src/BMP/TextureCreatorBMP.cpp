/*******************************************************************************/
/**
 * @file TextureCreatorBMP.cpp.
 * 
 * @brief BMP テクスチャ作成クラスソースファイル.
 *
 * @date 2008/07/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/BMP/TextureCreatorBMP.h"

using namespace Ngl;
using namespace Ngl::BMP;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] renderer レンダラークラスのポインタ.
 */
TextureCreatorBMP::TextureCreatorBMP( IRenderer* renderer ):
	renderer_( renderer ),
	filter_( 0 )
{}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
TextureCreatorBMP::~TextureCreatorBMP()
{}



/*=========================================================================*/
/**
 * @brief テクスチャを作成
 * 
 * @param[in] fileName ファイル名.
 * @return 作成したテクスチャのポインタ.
 */
ITexture* TextureCreatorBMP::create( const std::string& fileName )
{
	// フィルタが設定されているか
	if( filter_ != 0 ){
		bmp_.setFilter( filter_ );
	}

	// BMPファイルを作成
	bmp_.loadFromFile( fileName.c_str() );

	// テクスチャ記述子を作成
	TextureDesc td;
	td.format		= TEXTURE_FORMAT_RGBA8;
	td.type			= TEXTURE_TYPE_2D;
	td.width		= bmp_.desc().biWidth;
	td.height		= bmp_.desc().biHeight;
	td.mipLevels	= 1;
	td.usage		= TEXTURE_USAGE_IMMUTABLE;

	// テクスチャデータを作成
	ITexture* tex = renderer_->createTexture( td, &bmp_[ 0 ] );

	return tex;
}



/*=========================================================================*/
/**
 * @brief レンダラーを設定
 * 
 * @param[in] renderer レンダラークラスのポインタ.
 * @return なし.
 */
void TextureCreatorBMP::setRenderer( IRenderer* renderer )
{
	renderer_ = renderer;
}



/*=========================================================================*/
/**
 * @brief 作成できるファイル拡張子名を取得
 * 
 * @warning "."を含まず、全てアルファベット小文字の拡張子名を返す.
 * @param[in] なし.
 * @return 拡張子名.
 */
std::string TextureCreatorBMP::extension()
{
	return "bmp";
}



/*=========================================================================*/
/**
 * @brief テクスチャフィルタを設定する
 * 
 * @warning 設定したインスタンスの削除は行いません.
 *
 * @param[in] filter 設定するフィルタ.
 * @return なし.
 */
void TextureCreatorBMP::setFilter( ITextureFilter* filter )
{
	bmp_.setFilter( filter );
}
	
	
	
/*=========================================================================*/
/**
 * @brief ピクセルクラスを設定する
 * 
 * bitCountビットのビットマップのピクセルデータ処理クラスを設定します。
 *
 * @param[in] pixel 設定するピクセルクラス.
 * @param[in] bitCount 関数を設定するビットマップ.
 * @return なし.
 */
void TextureCreatorBMP::setBMPPixel( IBMPPixel* pixel, BitCount bitCount )
{
	bmp_.setBMPPixel( pixel, bitCount );
}
	
	
	
/*===== EOF ==================================================================*/