/*******************************************************************************/
/**
 * @file Texture2DGL.cpp.
 * 
 * @brief OpenGL 2Dテクスチャクラスソースファイル.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Texture2DGL.h"

using namespace Ngl;
using namespace Ngl::OpenGL;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] desc テクスチャ作成記述子.
 * @param[in] data テクスチャイメージデータ配列.
 */
Texture2DGL::Texture2DGL( const TextureDesc& desc, const void* data ):
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
void Texture2DGL::texImage( const void* data, unsigned int mipLevel, unsigned int index )
{
	if( pixel().complessedFormat ){
		// 圧縮イメージ
		glCompressedTexImage2DARB(
			target( index ),
			mipLevel,
			pixel().internalFormat,
			mipSize( desc().width, mipLevel ),
			mipSize( desc().height, mipLevel ),
			0,
			imageSize( mipLevel ),
			data
			);
	}
	else{
		// 無圧縮イメージ
		glTexImage2D(
			target(index),
			mipLevel,
			pixel().internalFormat,
			mipSize( desc().width, mipLevel ),
			mipSize( desc().height, mipLevel ),
			0,
			pixel().format, pixel().type, data
			);
	}
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
void Texture2DGL::texSubImage( const void* data, unsigned int mipLevel, unsigned int index )
{
	if( pixel().complessedFormat ){
		// 圧縮イメージ
		glCompressedTexSubImage2DARB(
			target( index ),
			mipLevel,
			0, 0,
			mipSize( desc().width, mipLevel ),
			mipSize( desc().height, mipLevel ),
			pixel().format,
			imageSize( mipLevel ),
			data
			);
	}
	else{
		// 無圧縮イメージ
		glTexSubImage2D(
			target( index ),
			mipLevel,
			0, 0,
			mipSize( desc().width, mipLevel ),
			mipSize( desc().height, mipLevel ),
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
void Texture2DGL::framebufferTexture( GLuint drawBuffer, unsigned int index )
{
	(void)index;
	glFramebufferTexture2DEXT(
		GL_FRAMEBUFFER_EXT,
		GL_COLOR_ATTACHMENT0_EXT + drawBuffer,
		target( index ),
		texture(),
		0
	);
}



/*===== EOF ==================================================================*/