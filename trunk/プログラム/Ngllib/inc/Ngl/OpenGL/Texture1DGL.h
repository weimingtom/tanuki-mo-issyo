/*******************************************************************************/
/**
 * @file Texture1DGL.h.
 * 
 * @brief OpenGL 1Dテクスチャクラスヘッダファイル.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_OPENGL_TEXTURE1DGL_H_
#define _NGL_OPENGL_TEXTURE1DGL_H_

#include	"TextureGL.h"

namespace Ngl{


namespace OpenGL{


/**
 * @class Texture1DGL.
 * @brief OpenGL 1Dテクスチャクラス.
 */
class Texture1DGL : public TextureGL
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] desc テクスチャ作成記述子.
	 * @param[in] data テクスチャイメージデータ配列.
	 */
	Texture1DGL( const TextureDesc& desc, const void* data=0 );

private:

	/*=========================================================================*/
	/**
	 * @brief イメージを設定
	 * 
	 * @param[in] data 設定するイメージの配列.
	 * @param[in] mipLevel 設定先のミップマップレベル.
	 * @param[in] index 設定先のインデックス番号.
	 * @return なし.
	 */
	virtual void texImage( const void* data, unsigned int mipLevel, unsigned int index );

	
	/*=========================================================================*/
	/**
	 * @brief イメージの更新
	 * 
	 * @param[in] data 更新するイメージデータの配列.
	 * @param[in] mipLevel 更新先のミップマップレベル.
	 * @param[in] index 更新先のインデックス番号.
	 * @return OpenGLターゲットフラグ.
	 */
	virtual void texSubImage( const void* data, unsigned int mipLevel, unsigned int index );

	
	/*=========================================================================*/
	/**
	 * @brief フレームバッファオブジェクトへのアタッチ
	 * 
	 * @param[in] drawBuffer 描画バッファ番号.
	 * @param[in] index インデックス番号.
	 * @return なし.
	 */
	virtual void framebufferTexture( GLuint drawBuffer, unsigned int index );

};

} // namespace OpenGL

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/