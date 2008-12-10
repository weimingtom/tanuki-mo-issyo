/*******************************************************************************/
/**
 * @file TextureGL.cpp.
 * 
 * @brief OpenGL テクスチャ基底クラスソースファイル.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/OpenGL/TextureGL.h"

using namespace Ngl;
using namespace Ngl::OpenGL;


/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] desc テクスチャ作成記述子.
 * @param[in] data テクスチャイメージデータ配列.
 */
TextureGL::TextureGL( const TextureDesc& desc, const void* data ):
	desc_( desc ),
	type_( toType( desc.type ) ),
	texture_( 0 ),
	depthTexture_( 0 ),
	stencilTexture_( 0 )
{
	// テクスチャを作成する
	glGenTextures( 1, &texture_ );

	// デプスバッファで使用するか
	if( pixel().depthFormat ){
		depthTexture_		= texture_;
		type_.target		= GL_TEXTURE_2D;
		type_.arrayTarget	= GL_TEXTURE_2D;
		type_.arraySize		= 1;
	}

	// ステンシルバッファで使用するか
	if( pixel().stencilFormat ){
		stencilTexture_		= texture_;
		type_.target		= GL_TEXTURE_2D;
		type_.arrayTarget	= GL_TEXTURE_2D;
		type_.arraySize		= 1;
	}
}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
TextureGL::~TextureGL()
{
	glDeleteTextures( 1, &texture_ );
}



/*=========================================================================*/
/**
 * @brief 記述子を取得する
 * 
 * @param[in] なし.
 * @return テクスチャ記述子.
 */
const TextureDesc& TextureGL::desc() const
{
	return desc_;
}



/*=========================================================================*/
/**
 * @brief テクスチャデータの設定
 * 
 * @param[in] data 設定するデータ.
 * @return なし.
 */
void TextureGL::setData( const void* data )
{
	glBindTexture( target(), texture_ );
	const GLubyte* base = static_cast< const GLubyte* >( data );
	for( unsigned int i=0; i<arraySize(); ++i ){
		for( unsigned int mip=0; mip<desc().mipLevels; ++mip ){
			texImage( base, mip, i );
			if( data != 0 ){
				base += imageSize( mip );
			}
		}
	}

	glBindTexture( target(), 0 );
}



/*=========================================================================*/
/**
 * @brief テクスチャデータの取得
 * 
 * @param[out] data テクスチャデータを格納するデータ.
 * @return なし.
 */
void TextureGL::getData( void* data )
{
	// テクスチャをバインドする
	glBindTexture( target(), texture_ );

	// イメージの取得
	GLubyte* base = static_cast< GLubyte* >( data );
	for( unsigned int i=0; i<arraySize(); ++i ){
		for( unsigned int mip=0; mip<desc().mipLevels; ++mip ){
			// テクスチャイメージを取得
			getTexImage( base, mip, i );
			base += imageSize( mip );
		}
	}

	// バインドを初期化する
	glBindTexture( target(), 0 );
}



/*=========================================================================*/
/**
 * @brief イメージサイズの取得
 * 
 * @param[in] なし.
 * @return イメージサイズ.
 */
unsigned int TextureGL::size() const
{
	unsigned int size = 0;
	for( unsigned int mip=0; mip<desc_.mipLevels; ++mip ){
		size += imageSize( mip );
	}

	return size;
}



/*=========================================================================*/
/**
 * @brief OpenGLテクスチャオブジェクトの取得
 * 
 * @param[in] なし.
 * @return OpenGlテクスチャオブジェクト.
 */
GLuint	TextureGL::texture() const
{
	return texture_;
}



/*=========================================================================*/
/**
 * @brief デプスステンシルバッファへのアタッチ
 * 
 * @param[in] なし.
 * @return なし.
 */
void TextureGL::attachDepthStencil()
{
	// デプスバッファ用のテクスチャを設定
	glFramebufferTexture2DEXT(
		GL_FRAMEBUFFER_EXT,
		GL_DEPTH_ATTACHMENT_EXT,
		GL_TEXTURE_2D,
		depthTexture_,
		0
		);

	// ステンシルバッファ用のテクスチャを設定
	glFramebufferTexture2DEXT(
		GL_FRAMEBUFFER_EXT,
		GL_STENCIL_ATTACHMENT_EXT,
		GL_TEXTURE_2D,
		stencilTexture_,
		0
		);
}



/*=========================================================================*/
/**
 * @brief フレームバッファオブジェクトへのアタッチ
 * 
 * @param[in] drawBuffer 描画バッファ番号.
 * @param[in] index インデックス番号.
 * @return なし.
 */
void TextureGL::attachFramebuffer( GLuint drawBuffer, unsigned int index )
{
	framebufferTexture( drawBuffer, index );
}



/*=========================================================================*/
/**
 * @brief ミップマップの作成
 * 
 * @param[in] なし.
 * @return なし.
 */
void TextureGL::generateMipmap()
{
	glEnable( target() );
	glBindTexture( target(), texture_ );
	glGenerateMipmapEXT( target() );
	glBindTexture( target(), 0 );
	glDisable( target() );
}

	

/*=========================================================================*/
/**
 * @brief  初期化処理
 * 
 * @param[in] data テクスチャデータ.
 * @return なし.
 */
void TextureGL::initialize( const void* data )
{
	// テクスチャをバインド
	glBindTexture( target(), texture_ );

	// テクスチャイメージの設定
	const GLubyte* base = static_cast< const GLubyte* >( data );
	for( unsigned int i=0; i<arraySize(); ++i ){
		for( unsigned int mip=0; mip<desc().mipLevels; ++mip ){
			texImage( base, mip, i );
			if( data != 0 ){
				base += imageSize( mip );
			}
		}
	}

	// デフォルトのテクスチャパラメータ
	glTexParameteri( target(), GL_TEXTURE_MAG_FILTER, GL_NEAREST );
	glTexParameteri( target(), GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glBindTexture( target(), 0 );
}



/*=========================================================================*/
/**
 * @brief  ピクセルフォーマットの取得
 * 
 * @param[in] なし.
 * @return ピクセルフォーマット構造体.
 */
const TextureGL::Pixel& TextureGL::pixel() const
{
	static const Pixel pixelFormat[] = {
		{ GL_INTENSITY8,					GL_LUMINANCE,			GL_UNSIGNED_BYTE,						sizeof( GLubyte ) * 1,		false,	false,	false },	// TEXTURE_FORMAT_I8			= 0
		{ GL_LUMINANCE8_ALPHA8,				GL_LUMINANCE_ALPHA,		GL_UNSIGNED_BYTE,						sizeof( GLubyte ) * 2,		false,	false,	false },	// TEXTURE_FORMAT_IA8			= 1
		{ GL_RGBA8,							GL_RGBA,				GL_UNSIGNED_BYTE,						sizeof( GLubyte ) * 4,		false,	false,	false },	// TEXTURE_FORMAT_RGBA8			= 2
		{ GL_INTENSITY16,					GL_LUMINANCE,			GL_UNSIGNED_SHORT,						sizeof( GLushort ) * 1,		false,	false,	false },	// TEXTURE_FORMAT_I16			= 3
		{ GL_LUMINANCE16_ALPHA16,			GL_LUMINANCE_ALPHA,		GL_UNSIGNED_SHORT,						sizeof( GLushort ) * 2,		false,	false,	false },	// TEXTURE_FORMAT_IA16			= 4
		{ GL_RGBA16,						GL_RGBA,				GL_UNSIGNED_SHORT,						sizeof( GLushort ) * 4,		false,	false,	false },	// TEXTURE_FORMAT_RGBA16		= 5
		{ GL_INTENSITY16F_ARB,				GL_LUMINANCE,			GL_HALF_FLOAT_ARB,						sizeof( GLfloat ) / 2 * 1,	false,	false,	false },	// TEXTURE_FORMAT_I16F			= 6
		{ GL_LUMINANCE_ALPHA16F_ARB,		GL_LUMINANCE_ALPHA,		GL_HALF_FLOAT_ARB,						sizeof( GLfloat ) / 2 * 2,	false,	false,	false },	// TEXTURE_FORMAT_IA16F			= 7,
		{ GL_RGBA16F_ARB,					GL_RGBA,				GL_HALF_FLOAT_ARB,						sizeof( GLfloat ) / 2 * 4,	false,	false,	false },	// TEXTURE_FORMAT_RGBA16F		= 8,
		{ GL_INTENSITY32F_ARB,				GL_LUMINANCE,			GL_FLOAT,								sizeof( GLfloat ) * 1,		false,	false,	false },	// TEXTURE_FORMAT_I32F			= 9,
		{ GL_LUMINANCE_ALPHA32F_ARB,		GL_LUMINANCE_ALPHA,		GL_FLOAT,								sizeof( GLfloat ) * 2,		false,	false,	false },	// TEXTURE_FORMAT_IA32F			= 10
		{ GL_RGB32F_ARB,					GL_RGB,					GL_FLOAT,								sizeof( GLfloat ) * 3,		false,	false,	false },	// TEXTURE_FORMAT_RGB32F		= 11
		{ GL_RGBA32F_ARB,					GL_RGBA,				GL_FLOAT,								sizeof( GLfloat ) * 4,		false,	false,	false },	// TEXTURE_FORMAT_RGBA32F		= 12
		{ GL_R11F_G11F_B10F_EXT,			GL_RGB,					GL_UNSIGNED_INT_10F_11F_11F_REV_EXT,	sizeof( GLuint ),			false,	false,	false },	// TEXTURE_FORMAT_R11G11B10F	= 13
		{ GL_COMPRESSED_RGB_S3TC_DXT1_EXT,	GL_RGB,					GL_UNSIGNED_BYTE,						sizeof( GLubyte ) * 8,		true,	false,	false },	// TEXTURE_FORMAT_DXT1			= 14
		{ GL_COMPRESSED_RGBA_S3TC_DXT3_EXT,	GL_RGBA,				GL_UNSIGNED_BYTE,						sizeof( GLubyte ) * 16,		true,	false,	false },	// TEXTURE_FORMAT_DXT3			= 15
		{ GL_COMPRESSED_RGBA_S3TC_DXT5_EXT,	GL_RGBA,				GL_UNSIGNED_BYTE,						sizeof( GLubyte ) * 16,		true,	false,	false },	// TEXTURE_FORMAT_DXT5			= 16
		{ GL_DEPTH_COMPONENT16,				GL_DEPTH_COMPONENT,		GL_UNSIGNED_SHORT,						sizeof( GLushort ) * 1,		false,	true,	false },	// TEXTIRE_FORMAT_D16			= 17
		{ GL_DEPTH_COMPONENT32,				GL_DEPTH_COMPONENT,		GL_FLOAT,								sizeof( GLfloat ) * 1,		false,	true,	false },	// TEXTURE_FORMAT_D32F			= 18
		{ GL_DEPTH24_STENCIL8_EXT,			GL_DEPTH_STENCIL_EXT,	GL_UNSIGNED_INT_24_8_EXT,				sizeof( GLubyte ) * 4,		false,	true,	true  }		// TEXTURE_FORMAT_D24S8			= 19
	};

	return pixelFormat[ desc_.format ];
}



/*=========================================================================*/
/**
 * @brief イメージサイズの計算
 * 
 * @param[in] mipLevel ミップマップレベル.
 * @return 計算したサイズ.
 */
unsigned int TextureGL::imageSize( unsigned int mipLevel ) const
{
	// ミップレベルに合わせたサイズを求める
	unsigned int w = mipSize( desc().width, mipLevel );
	unsigned int h = mipSize( desc().height, mipLevel );
	unsigned int d = mipSize( desc().depth, mipLevel );

	// DXTフォーマットか
	if( pixel().complessedFormat == true ){
		// DXTのブロックサイズに変更
		w = ( w + 3 ) / 4;
		h = ( h + 3 ) / 4;
	}

	// イメージサイズの計算
	return w * h * d * pixel().size;
}



/*=========================================================================*/
/**
 * @brief ミップマップサイズを取得
 * 
 * @param[in] size テクスチャサイズ.
 * @param[in] mipLevel ミップマップレベル.
 * @return ミップマップサイズ.
 */
unsigned int TextureGL::mipSize( unsigned int size, unsigned int mipLevel )
{
	return ( ( size >> mipLevel ) <= 0 ) ? 1 : ( size >> mipLevel );
}



/*=========================================================================*/
/**
 * @brief テクスチャ配列サイズの取得
 * 
 * @param[in] なし.
 * @return テクスチャ配列サイズ.
 */
unsigned int TextureGL::arraySize() const
{
	return type_.arraySize;
}



/*=========================================================================*/
/**
 * @brief OpenGLターゲットフラグの取得
 * 
 * @param[in] なし.
 * @return OpenGLターゲットフラグ.
 */
GLenum TextureGL::target() const
{
	return type_.target;
}



/*=========================================================================*/
/**
 * @brief イメージ用のOpenGLターゲットフラグを取得
 * 
 * @param[in] index ターゲット番号.
 * @return OpenGLターゲットフラグ.
 */
GLenum TextureGL::target( unsigned int index ) const
{
	return type_.arrayTarget + index;
}



/*=========================================================================*/
/**
 * @brief イメージを取得
 * 
 * @param[out] data 取得したデータを格納する配列.
 * @param[in] mipLevel 取得するイメージのミップマップレベル.
 * @param[in] index テクスチャインデックス.
 * @return なし.
 */
void TextureGL::getTexImage( void* data, unsigned int mipLevel, unsigned int index ) const
{
	glGetTexImage(
		target( index ),
		mipLevel,
		pixel().format, pixel().type, data
	);
}



/*=========================================================================*/
/**
 * @brief テクスチャタイプを変換
 * 
 * @param[in] type 変換するテクスチャタイプフラグ.
 * @param[in] 変換したテクスチャタイプ構造体.
 * @return なし.
 */
const TextureGL::Type& TextureGL::toType( TextureType type )
{
	// 今回は２Ｄのみ
	static const Type types[] = {
		{ GL_TEXTURE_1D,		GL_TEXTURE_1D,					1 },	// TEXTURE_TYPE_1D		= 0
		{ GL_TEXTURE_2D,		GL_TEXTURE_2D,					1 },	// TEXTURE_TUPE_2D		= 1
		{ GL_TEXTURE_3D,		GL_TEXTURE_3D,					1 },	// TEXTURE_TYPE_3D		= 2
		{ GL_TEXTURE_CUBE_MAP,	GL_TEXTURE_CUBE_MAP_POSITIVE_X,	6 }		// TEXTURE_TYPE_CUBE	= 3
	};

	return types[type];
}



/*===== EOF ==================================================================*/