/*******************************************************************************/
/**
 * @file TextureCreatorDDS.cpp.
 * 
 * @brief DDS テクスチャ作成クラスソースファイル.
 *
 * @date 2008/07/12.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/DDS/TextureCreatorDDS.h"
#include	<cassert>

using namespace Ngl;
using namespace Ngl::DDS;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] renderer レンダラークラスのポインタ.
 */
TextureCreatorDDS::TextureCreatorDDS( IRenderer* renderer ):
	renderer_( renderer ),
	dds_( 0 ),
	filter_( 0 )
{}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
TextureCreatorDDS::~TextureCreatorDDS()
{
	delete dds_;
}



/*=========================================================================*/
/**
 * @brief テクスチャを作成
 * 
 * @param[in] fileName ファイル名.
 * @return 作成したテクスチャのポインタ.
 */
ITexture* TextureCreatorDDS::create( const std::string& fileName )
{
	// レンダラーが登録されているか
	assert( renderer_ != 0 );

	// 同じデータの作成要求が来たか?
	if( fileName_ == fileName && dds_ != 0 ){
		// テクスチャ作製記述子に変換
		TextureDesc descTex = toTextureDesc( dds_->desc() );

		// テクスチャを作成
		return renderer_->createTexture( descTex, &dds_[ 0 ] );
	}

	// 以前のデータを削除
	delete dds_;
	dds_ = 0;

	// ファイル名を登録
	fileName_ = fileName;

	// DDSファイルを作成
	dds_ = new DDSFile();

	// テクスチャフィルタを設定
	if( filter_ != 0 ){
		dds_->setFilter( filter_ );
	}

	// DDSファイルを読み込む
	dds_->loadFromFile( fileName_.c_str() );

	// テクスチャ作製記述子に変換
	TextureDesc descTex = toTextureDesc( dds_->desc() );

	// テクスチャを作成
	return renderer_->createTexture( descTex, &(*dds_)[ 0 ] );
}



/*=========================================================================*/
/**
 * @brief レンダラーを設定
 * 
 * @param[in] renderer レンダラークラスのポインタ.
 * @return なし.
 */
void TextureCreatorDDS::setRenderer( IRenderer* renderer )
{
	renderer_ = renderer;
}



/*=========================================================================*/
/**
 * @brief 作成できるファイル拡張子名を取得( .を含まない拡張子名 )
 * 
 * @warning "."を含まず、全てアルファベット小文字の拡張子名を返す.
 *
 * @param[in] なし.
 * @return 拡張子名( "dds" ).
 */
std::string TextureCreatorDDS::extension()
{
	return "dds";
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
void TextureCreatorDDS::setFilter( ITextureFilter* filter )
{
	filter_ = filter;
}
	
	
	
/*=========================================================================*/
/**
 * @brief テクスチャフォーマットに変換
 * 
 * @param[in] ddpf DDSピクセルフォーマット構造体の参照.
 * @return 変換したテクスチャフォーマット.
 */
TextureFormat TextureCreatorDDS::toTextureFormat( const DDSFile::PixelFormat& ddpf )
{
	// L8フォーマットか
	if( ( ddpf.dwFlags & DDSFile::FORMAT_LUMINANCE ) != 0 ){
		return TEXTURE_FORMAT_I8;
	}

	// DXTフォーマットか
	if( ( ddpf.dwFlags & DDSFile::FORMAT_FOURCC ) != 0 ){
		if( ddpf.dwFourCC == DDSFile::FORMAT_DXT1 ){
			return TEXTURE_FORMAT_DXT1;
		}
		if( ddpf.dwFourCC == DDSFile::FORMAT_DXT3 ){
			return TEXTURE_FORMAT_DXT3;
		}
		if( ddpf.dwFourCC == DDSFile::FORMAT_DXT5 ){
			return TEXTURE_FORMAT_DXT5;
		}
	}

	// ABGRフォーマットか
	assert( ( ddpf.dwFlags & DDSFile::FORMAT_RGB ) != 0
		&& ddpf.dwRGBBitCount		== 32
		&& ddpf.dwRBitMask			== 0x000000ff
		&& ddpf.dwGBitMask			== 0x0000ff00
		&& ddpf.dwBBitMask			== 0x00ff0000
		&& ddpf.dwRGBAlphaBitMask	== 0xff000000
		);

	return TEXTURE_FORMAT_RGBA8;
}



/*=========================================================================*/
/**
 * @brief テクスチャタイプに変換
 * 
 * @param[in] caps DDS補助フラグ構造体の参照.
 * @return 変換したテクスチャタイプ.
 */
TextureType TextureCreatorDDS::toTextureType( const DDSFile::Caps2& caps )
{
	if( ( caps.dwCaps2 & DDSFile::CAPS2_CUBEMAP ) == DDSFile::CAPS2_CUBEMAP ){
		return TEXTURE_TYPE_CUBE;
	}

	if( ( caps.dwCaps2 & DDSFile::CAPS2_VOLUME ) != 0 ){
		return TEXTURE_TYPE_3D;
	}

	return TEXTURE_TYPE_2D;
}



/*=========================================================================*/
/**
 * @brief テクスチャ記述子に変換
 * 
 * @param[in] descDDS DDSサーフェース記述子の参照.
 * @return 変換したテクスチャ記述子.
 */
TextureDesc TextureCreatorDDS::toTextureDesc( const DDSFile::SurfaceDesc& descDDS )
{
	TextureDesc descTex;
	descTex.type		= toTextureType( descDDS.ddsCaps );
	descTex.format		= toTextureFormat( descDDS.ddpfPixelFormat );
	descTex.width		= descDDS.dwWidth;
	descTex.height		= descDDS.dwHeight;
	
	if( descTex.type == TEXTURE_TYPE_3D ){
		descTex.depth = descDDS.dwDepth;
	}

	descTex.mipLevels = 1;
	if( ( descDDS.dwFlags & DDSFile::FLAG_MIPMAPCOUNT ) != 0 ){
		descTex.mipLevels = descDDS.dwMipMapCount;
	}

	descTex.renderTarget = false;

	return descTex;
}

	
	
/*===== EOF ==================================================================*/