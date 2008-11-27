/*******************************************************************************/
/**
 * @file TextureGL.h.
 * 
 * @brief OpenGL テクスチャ基底クラスヘッダファイル.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_OPENGL_TEXTUREGL_H_
#define _NGL_OPENGL_TEXTUREGL_H_

#include	"Ngl/ITexture.h"
#include	"OpenGL.h"

namespace Ngl{


namespace OpenGL{


/**
 * @class TextureGL．
 * @brief OpenGL テクスチャ基底クラス.
 */
class TextureGL : public ITexture
{
protected:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] desc テクスチャ作成記述子.
	 * @param[in] data テクスチャイメージデータ配列.
	 */
	TextureGL( const TextureDesc& desc, const void* data );

	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~TextureGL();

public:

	/*=========================================================================*/
	/**
	 * @brief 記述子を取得する
	 * 
	 * @param[in] なし.
	 * @return テクスチャ記述子.
	 */
	const TextureDesc& desc() const;

	
	/*=========================================================================*/
	/**
	 * @brief テクスチャデータの設定
	 * 
	 * @param[in] data 設定するデータ.
	 * @return なし.
	 */
	void setData( const void* data );

	
	/*=========================================================================*/
	/**
	 * @brief テクスチャデータの取得
	 * 
	 * @param[out] data テクスチャデータを格納するデータ.
	 * @return なし.
	 */
	void getData( void* data );

	
	/*=========================================================================*/
	/**
	 * @brief イメージサイズの取得
	 * 
	 * @param[in] なし.
	 * @return イメージサイズ.
	 */
	unsigned int size() const;

	
	/*=========================================================================*/
	/**
	 * @brief OpenGLテクスチャオブジェクトの取得
	 * 
	 * @param[in] なし.
	 * @return OpenGlテクスチャオブジェクト.
	 */
	GLuint	texture() const;

	
	/*=========================================================================*/
	/**
	 * @brief デプスステンシルバッファへのアタッチ
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void attachDepthStencil();

	
	/*=========================================================================*/
	/**
	 * @brief フレームバッファオブジェクトへのアタッチ
	 * 
	 * @param[in] drawBuffer 描画バッファ番号.
	 * @param[in] index インデックス番号.
	 * @return なし.
	 */
	void attachFramebuffer( GLuint drawBuffer, unsigned int index );

	
	/*=========================================================================*/
	/**
	 * @brief ミップマップの作成
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void generateMipmap();

protected:

	/**
	 * @struct Type.
	 * @brief OpenGL テクスチャタイプ構造体
	 */
	struct Type
	{
		GLenum			target;			/**< ターゲット		*/
		GLenum			arrayTarget;	/**< ターゲット配列 */
		unsigned int	arraySize;		/**< 配列サイズ		*/
	};

	/**
	 * @struct Pixel.
	 * @brief OpenGL ピクセルフォーマット構造体.
	 */
	struct Pixel{
		GLenum	internalFormat;		/**< リソースのフォーマット		*/
		GLenum	format;				/**< フォーマット				*/
		GLenum	type;				/**< ピクセルタイプ				*/
		GLuint	size;				/**< データサイズ				*/
		bool	complessedFormat;	/**< 圧縮フォーマットか			*/
		bool	depthFormat;		/**< デプス用フォーマットか		*/
		bool	stencilFormat;		/**< ステンシル用フォーマットか	*/
	};

	/*=========================================================================*/
	/**
	 * @brief  初期化処理
	 * 
	 * @param[in] data テクスチャデータ.
	 * @return なし.
	 */
	void initialize( const void* data );

	
	/*=========================================================================*/
	/**
	 * @brief  ピクセルフォーマットの取得
	 * 
	 * @param[in] なし.
	 * @return ピクセルフォーマット構造体.
	 */
	const Pixel& pixel() const;

	
	/*=========================================================================*/
	/**
	 * @brief イメージサイズの計算
	 * 
	 * @param[in] mipLevel ミップマップレベル.
	 * @return 計算したサイズ.
	 */
	unsigned int imageSize( unsigned int mipLevel ) const;

	
	/*=========================================================================*/
	/**
	 * @brief ミップマップサイズを取得
	 * 
	 * @param[in] size テクスチャサイズ.
	 * @param[in] mipLevel ミップマップレベル.
	 * @return ミップマップサイズ.
	 */
	static unsigned int mipSize( unsigned int size, unsigned int mipLevel );

	
	/*=========================================================================*/
	/**
	 * @brief テクスチャ配列サイズの取得
	 * 
	 * @param[in] なし.
	 * @return テクスチャ配列サイズ.
	 */
	unsigned int arraySize() const;

	
	/*=========================================================================*/
	/**
	 * @brief OpenGLターゲットフラグの取得
	 * 
	 * @param[in] なし.
	 * @return OpenGLターゲットフラグ.
	 */
	GLenum target() const;

	
	/*=========================================================================*/
	/**
	 * @brief イメージ用のOpenGLターゲットフラグを取得
	 * 
	 * @param[in] index ターゲット番号.
	 * @return OpenGLターゲットフラグ.
	 */
	GLenum target( unsigned int index ) const;


	/*=========================================================================*/
	/**
	 * @brief イメージを取得
	 * 
	 * @param[out] data 取得したデータを格納する配列.
	 * @param[in] mipLevel 取得するイメージのミップマップレベル.
	 * @param[in] index テクスチャインデックス.
	 * @return なし.
	 */
	void getTexImage( void* data, unsigned int mipLevel, unsigned int index ) const;


	/*=========================================================================*/
	/**
	 * @brief テクスチャタイプを変換
	 * 
	 * @param[in] type 変換するテクスチャタイプフラグ.
	 * @param[in] 変換したテクスチャタイプ構造体.
	 * @return なし.
	 */
	static const Type& toType( TextureType type );

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
	virtual void texImage( const void* data, unsigned int mipLevel, unsigned int index ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief イメージの更新
	 * 
	 * @param[in] data 更新するイメージデータの配列.
	 * @param[in] mipLevel 更新先のミップマップレベル.
	 * @param[in] index 更新先のインデックス番号.
	 * @return OpenGLターゲットフラグ.
	 */
	virtual void texSubImage( const void* data, unsigned int mipLevel, unsigned int index ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief フレームバッファオブジェクトへのアタッチ
	 * 
	 * @param[in] drawBuffer 描画バッファ番号.
	 * @param[in] index インデックス番号.
	 * @return なし.
	 */
	virtual void framebufferTexture( GLuint drawBuffer, unsigned int index ) = 0;

private:
	
	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ( コピー禁止 )
	 * 
	 * @param[in] other 代入するオブジェクト.
	 */
	TextureGL( const TextureGL& other );
	
	
	/*=========================================================================*/
	/**
	 * @brief = 演算子オーバーロード( コピー禁止 )
	 * 
	 * @param[in] other 代入するオブジェクト.
	 * @return 代入結果のオブジェクト.
	 */
	TextureGL& operator = ( const TextureGL& other );

private:

	/** テクスチャ記述子 */
	TextureDesc		desc_;

	/** テクスチャタイプ */
	Type			type_;

	/** テクスチャオブジェクト */
	GLuint			texture_;

	/** デプステクスチャ */
	GLuint			depthTexture_;

	/** ステンシルテクスチャ */
	GLuint			stencilTexture_;

};

} // namespace OpenGL

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/