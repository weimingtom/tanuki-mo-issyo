/*******************************************************************************/
/**
 * @file Texture1DGL.cpp.
 * 
 * @brief OpenGL 1Dテクスチャクラスソースファイル.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/OpenGL/Texture1DGL.h"

using namespace Ngl;
using namespace Ngl::OpenGL;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] desc テクスチャ作成記述子.
 * @param[in] data テクスチャイメージデータ配列.
 */
Texture1DGL::Texture1DGL( const TextureDesc& desc, const void* data ):
	TextureGL( desc, data )
{
	initialize( data );
}



/*=========================================================================*/
/**
 * @brief イメージを設定
 * 
 * @param[in] data 設定するイメージの配列.
 * @param[in] mipLevel 設定先のミップマップレベル.
 * @param[in] index 設定先のインデックス番号.
 * @return なし.
 */
void Texture1DGL::texImage( const void* data, unsigned int mipLevel, unsigned int index )
{
	// 無圧縮イメージ
	glTexImage1D(
		target(index),
		mipLevel,
		pixel().internalFormat,
		mipSize( desc().width, mipLevel ),
		0,
		pixel().format, pixel().type, data
		);
}




/*=========================================================================*/
/**
 * @brief イメージの更新
 * 
 * @param[in] data 更新するイメージデータの配列.
 * @param[in] mipLevel 更新先のミップマップレベル.
 * @param[in] index 更新先のインデックス番号.
 * @return OpenGLターゲットフラグ.
 */
void Texture1DGL::texSubImage( const void* data, unsigned int mipLevel, unsigned int index )
{
	if( pixel().complessedFormat ){
		// 圧縮イメージ
		glCompressedTexSubImage1DARB(
			target( index ),
			mipLevel,
			0,
			mipSize( desc().width, mipLevel ),
			pixel().format,
			imageSize( mipLevel ),
			data
			);
	}
	else{
		// 無圧縮イメージ
		glTexSubImage1D(
			target( index ),
			mipLevel,
			0,
			mipSize( desc().width, mipLevel ),
			pixel().format, pixel().type, data
		);
	}
}



/*=========================================================================*/
/**
 * @brief フレームバッファオブジェクトへのアタッチ
 * 
 * @param[in] drawBuffer 描画バッファ番号.
 * @param[in] index インデックス番号.
 * @return なし.
 */
void Texture1DGL::framebufferTexture( GLuint drawBuffer, unsigned int index )
{
	(void)index;
	glFramebufferTexture1DEXT(
		GL_FRAMEBUFFER_EXT,
		GL_COLOR_ATTACHMENT0_EXT + drawBuffer,
		GL_TEXTURE_1D,
		texture(),
		0
	);
}



/*===== EOF ==================================================================*/