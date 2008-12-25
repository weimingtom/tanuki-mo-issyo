/*******************************************************************************/
/**
 * @file RendererGL.cpp.
 * 
 * @brief OpenGL レンダラークラスソースファイル.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/OpenGL/RendererGL.h"
#include	"Ngl/OpenGL/BufferGL.h"
#include	"Ngl/OpenGL/VertexDeclarationGL.h"
#include	"Ngl/OpenGL/EffectCgGL.h"
#include	"Ngl/OpenGL/Texture1DGL.h"
#include	"Ngl/OpenGL/Texture2DGL.h"
#include	"Ngl/OpenGL/Texture3DGL.h"
#include	<cassert>

using namespace Ngl;
using namespace Ngl::OpenGL;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
RendererGL::RendererGL():
	vertexDeclaration_( 0 ),
	indexBuffer_( 0 ),
	indexFormat_( toIndexFormat( INDEX_TYPE_USHORT ) ),
	indexOffset_( 0 ),
	primitiveMode_( toPrimitiveMode( PRIMITIVE_TYPE_TRIANGLE_LIST ) ),
	framebufferObject_( 0 )
{
	// フレームバッファオブジェクトの作成
	glGenFramebuffersEXT( 1, &framebufferObject_ );

	// 初期化処理
	initialize();
}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
RendererGL::~RendererGL()
{
	// 状態を初期化する
	clearState();

	// フレームバッファオブジェクトの削除
	glDeleteFramebuffersEXT( 1, &framebufferObject_ );
}



/*=========================================================================*/
/**
 * @brief 初期化処理
 * 
 * @param[in] なし.
 * @return なし.
 */
void RendererGL::initialize()
{
	// 面カリングの設定
	//glEnable( GL_CULL_FACE );
	//glCullFace( GL_BACK );
	//glFrontFace( GL_CCW );
	
	// デプスバッファを1.0でクリアする
	glEnable( GL_DEPTH_TEST );
	glDepthFunc( GL_LESS );

	// アルファテストの設定
	glEnable( GL_ALPHA_TEST  );
	glAlphaFunc( GL_GREATER, 0.0f );

	// ブレンドステートの設定
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	// パースペクティブ補正を行う
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
}



/*=========================================================================*/
/**
 * @brief ビューポートの設定
 * 
 * @param[in] desc ビューポート記述子.
 * @return なし.
 */
void RendererGL::setViewport( const ViewportDesc& desc )
{
	glViewport( desc.x, desc.y, desc.width, desc.height );
	viewport_ = desc;
}



/*=========================================================================*/
/**
 * @brief ビューポートの取得
 * 
 * @param[in] なし.
 * @return ビューポート記述子.
 */
const ViewportDesc& RendererGL::getViewport() const
{
	return viewport_;
}



/*=========================================================================*/
/**
 * @brief カラーバッファ消去
 * 
 * @param[in] r クリアカラー赤成分.
 * @param[in] g クリアカラー緑成分.
 * @param[in] b クリアカラー青成分.
 * @param[in] a クリアカラーアルファ成分.	 
 * @return なし.
 */
void RendererGL::clearColorBuffer( float r, float g, float b, float a )
{
	// クリアカラーを設定する
	glClearColor( r, g, b, a );

	// カラーバッファの消去
	glClear( GL_COLOR_BUFFER_BIT );

}



/*=========================================================================*/
/**
 * @brief デプスステンシルバッファを消去
 * 
 * @param[in] depth デプスバッファを消去するか.
 * @param[in] stencil ステンシルバッファを消去するか.
 * @return なし.
 */
void RendererGL::clearDepthStencilBuffer( bool depth, bool stencil )
{
	GLbitfield mask = 0;

	if( depth ){
		mask |= GL_DEPTH_BUFFER_BIT;
	}

	if( stencil ){
		mask |= GL_STENCIL_BUFFER_BIT;
	}

	glClear( mask );
}



/*=========================================================================*/
/**
 * @brief バッファを作成
 * 
 * @param[in] desc バッファ記述子.
 * @param[in] data バッファデータ.
 * @return 作成したバッファインターフェースのポインタ.
 */
IBuffer* RendererGL::createBuffer( const BufferDesc& desc, const void* data )
{
	return new BufferGL( desc, data );
}



/*=========================================================================*/
/**
 * @brief テクスチャを作成
 * 
 * @param[in] desc テクスチャ記述子.
 * @param[in] data テクスチャデータ.
 * @return 作成したテクスチャインターフェースのポインタ.
 */
ITexture* RendererGL::createTexture( const TextureDesc& desc, const void* data )
{
	TextureGL* texture = 0;
	switch( desc.type ){
		case TEXTURE_TYPE_1D:
			texture = new Texture1DGL( desc, data );
			break;
		case TEXTURE_TYPE_2D:
			texture = new Texture2DGL( desc, data );
			break;
		case TEXTURE_TYPE_3D:
			texture = new Texture3DGL( desc, data );
			break;
		case TEXTURE_TYPE_CUBE:
			texture = new Texture2DGL( desc, data );
	}

	return texture;
}



/*=========================================================================*/
/**
 * @brief 頂点宣言を作成
 * 
 * @param[in] desc 頂点宣言記述子の配列.
 * @param[in] numDesc 頂点宣言記述子配列の要素数.
 * @param[in] inputSignature 入力シグネチャ記述子.
 * @return 作成した頂点宣言インターフェースのポインタ.
 */
IVertexDeclaration* RendererGL::createVertexDeclaration( const VertexDeclarationDesc desc[], unsigned int numDesc, const InputSignatureDesc& inputSignature )
{
	(void)inputSignature;	// OpenGLでは使用しない
	return new VertexDeclarationGL( desc, numDesc );
}



/*=========================================================================*/
/**
 * @brief エフェクトの作成
 * 
 * @param[in] fileName エフェクトファイル名.
 * @return 作成したエフェクトインターフェースのポインタ.
 */
IEffect* RendererGL::createEffect( const char* fileName )
{
	return new EffectCgGL( fileName );
}



/*=========================================================================*/
/**
 * @brief 頂点宣言データを設定
 * 
 * @param[in] layout 設定する頂点宣言データのポインタ.
 * @return なし.
 */
void RendererGL::setVertexDeclaration( IVertexDeclaration* layout )
{
	vertexDeclaration_ = static_cast< VertexDeclarationGL* >( layout );
}



/*=========================================================================*/
/**
 * @brief バッファを設定
 * 
 * @param[in] stream 頂点ストリーム記述子配列.
 * @param[in] numStream 頂点ストリーム記述子配列の要素数.
 * @param[in] offset オフセット値.
 * @return なし.
 */
void RendererGL::setVertexBuffer( const VertexStreamDesc stream[], unsigned int numStream, unsigned int offset )
{
	for( unsigned int i=0; i<numStream; ++i ){
		vertexStream_[i+offset] = stream[i];
	}
}



/*=========================================================================*/
/**
 * @brief インデックスバッファを設定
 * 
 * @param[in] buffer インデックスバッファのポインタ.
 * @param[in] type 頂点タイプ.
 * @param[in] offset オフセット値.
 * @return なし.
 */
void RendererGL::setIndexBuffer( IBuffer* buffer, IndexType type, unsigned int offset )
{
	indexBuffer_ = static_cast< BufferGL* >( buffer );
	indexFormat_ = toIndexFormat( type );
	indexOffset_ = offset;
}



/*=========================================================================*/
/**
 * @brief ミップマップの作成
 * 
 * @param[in] texture ミップマップを作成するテクスチャのポインタ.
 * @return なし.
 */
void RendererGL::generateMipmap( ITexture* texture )
{
	TextureGL* tex = static_cast< TextureGL* >( texture );
	tex->generateMipmap();
}



/*=========================================================================*/
/**
 * @brief 描画するプリミティブを設定
 * 
 * @param[in] primitive プリミティブタイプ.
 * @return なし.
 */
void RendererGL::setPrimitive( PrimitiveType primitive )
{
	primitiveMode_ = toPrimitiveMode( primitive );
}



/*=========================================================================*/
/**
 * @brief 頂点バッファを描画
 * 
 * @param[in] numVertex 描画する頂点数.
 * @param[in] start 開始頂点番号.
 * @return なし.
 */
void RendererGL::draw( unsigned int numVertex, unsigned int start )
{
	// 頂点宣言を設定
	vertexDeclaration_->setVertexStream( vertexStream_, start );

	// 頂点バッファの描画
	glDrawArrays( primitiveMode_, 0, numVertex );

	// 頂点バッファをリセットする
	vertexDeclaration_->resetVertexStream();
}



/*=========================================================================*/
/**
 * @brief インデックスバッファを使用して描画する
 * 
 * @param[in] numIndices インデックス数.
 * @param[in] startIndex 開始インデックス番号.
 * @param[in] startVertex 開始頂点番号
 * @return なし.
 */
void RendererGL::drawIndexed( unsigned int numIndices, unsigned int startIndex, unsigned int startVertex )
{
	// 頂点バッファを設定する
	vertexDeclaration_->setVertexStream( vertexStream_, startVertex );

	// インデックスバッファをバインドする
	glBindBufferARB( GL_ELEMENT_ARRAY_BUFFER_ARB, indexBuffer_->buffer() );

	GLubyte* base = 0;
	glDrawElements( 
		primitiveMode_,
		numIndices,
		indexFormat_.type,
		&base[ ( indexOffset_ + startIndex ) * indexFormat_.size ]
	);

	// インデックスバッファをリセットする
	glBindBufferARB( GL_ELEMENT_ARRAY_BUFFER_ARB, 0 );

	// 頂点バッファをリセットする
	vertexDeclaration_->resetVertexStream();
}



/*=========================================================================*/
/**
 * @brief テクスチャをレンダーターゲットに設定
 * 
 * @param[in] targets 設定するテクスチャの配列.
 * @param[in] numTargets テクスチャ配列の要素数.
 * @param[in] depthStencil デプスステンシルバッファとして使用するテクスチャのポインタ.
 * @param[in] index 開始インデックス番号.
 * @return なし.
 */
void RendererGL::setRenderTargets( ITexture* targets[], unsigned int numTargets, ITexture* depthStencil, unsigned int index )
{
	// レンダーターゲットをリセットする
	resetRenderTargets();

	// 何も設定されていない場合はリセットのみ
	if( targets == 0 && depthStencil == 0 ){
		return;
	}

	// フレームバッファオブジェクトのバインド
	glBindFramebufferEXT( GL_FRAMEBUFFER_EXT, framebufferObject_ );

	// デプスステンシルバッファの設定
	TextureGL* depthStencilBuffer = static_cast< TextureGL* >( depthStencil );
	if( depthStencilBuffer != 0 ){
		// デプスステンシルバッファにアタッチ
		depthStencilBuffer->attachDepthStencil();
	}

	// レンダーターゲットの設定
	GLenum drawBuffers[ RENDER_TARGET_MAX ];
	for( GLuint i=0; i<numTargets; ++i ){
		// テクスチャをフレームバッファオブジェクトにアタッチ
		static_cast< TextureGL* >( targets[i] )->attachFramebuffer( i, index );

		// 描画バッファの設定
		drawBuffers[i] = GL_COLOR_ATTACHMENT0_EXT + i;
	}

	// レンダーターゲットが存在するか
	if( numTargets > 0 ){
		// 描画バッファの設定
		glDrawBuffersARB( numTargets, drawBuffers );
	}
	else{
		// 描画バッファへの書き込みをしないようにする
		glDrawBuffer( GL_NONE );
		glReadBuffer( GL_NONE );
	}

	assert( glCheckFramebufferStatusEXT( GL_FRAMEBUFFER_EXT ) == GL_FRAMEBUFFER_COMPLETE_EXT );
}



/*=========================================================================*/
/**
 * @brief レンダーターゲットをリセット
 * 
 * @param[in] なし.
 * @return なし.
 */
void RendererGL::resetRenderTargets()
{
	glBindFramebufferEXT( GL_FRAMEBUFFER_EXT, framebufferObject_ );

	// デプスステンシルバッファのリセット
	glFramebufferTexture2DEXT( GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT,   GL_TEXTURE_2D, 0, 0 );
	glFramebufferTexture2DEXT( GL_FRAMEBUFFER_EXT, GL_STENCIL_ATTACHMENT_EXT, GL_TEXTURE_2D, 0, 0 );

	// レンダーターゲットのリセット
	GLint maxDrawBuffer;
	glGetIntegerv( GL_MAX_DRAW_BUFFERS, &maxDrawBuffer );
	for( GLint i=0; i<maxDrawBuffer; ++i ){
		glFramebufferTexture2DEXT( GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT+i, GL_TEXTURE_2D, 0, 0 );
	}

	// 描画・読み込みバッファのリセット
	glDrawBuffer( GL_COLOR_ATTACHMENT0_EXT );
	glReadBuffer( GL_COLOR_ATTACHMENT0_EXT );

	// フレームバッファオブジェクトをリセットする
	glBindFramebufferEXT( GL_FRAMEBUFFER_EXT, 0 );
}



/*=========================================================================*/
/**
 * @brief レンダラーをフラッシュ
 * 
 * @param[in] なし.
 * @return なし.
 */
void RendererGL::flush()
{
	glFlush();
}



/*=========================================================================*/
/**
 * @brief レンダラーの状態をクリア
 * 
 * @param[in] なし.
 * @return なし.
 */
void RendererGL::clearState()
{
	resetRenderTargets();

	initialize();
}



/*=========================================================================*/
/**
 * @brief インデックスタイプの変換
 * 
 * @param[in] format 変換するインデックスタイプフラグ.
 * @return 変換後のインデックスフォーマット構造体.
 */
const RendererGL::IndexFormat& RendererGL::toIndexFormat( IndexType format )
{
	static const RendererGL::IndexFormat indexFormats[] = {
		{ GL_UNSIGNED_SHORT,	sizeof( GLushort )	},
		{ GL_UNSIGNED_INT,		sizeof( GLuint )	}
	};

	return indexFormats[ format ];
}



/*=========================================================================*/
/**
 * @brief プリミティブタイプの変換
 * 
 * @param[in] primitive 変換するプリミティブタイプフラグ.
 * @return 変換後のOpenGLプリミティブフラグ.
 */
GLenum RendererGL::toPrimitiveMode( PrimitiveType primitive )
{
	static const GLenum primitiveModels[] = {
		GL_POINTS,			// PRIMITIVE_TYPE_POINTLIST		 = 0
		GL_LINES,			// PRIMITIVE_TYPE_LINELIST		 = 1
		GL_LINE_STRIP,		// PRIMITIVE_TYPE_LINESTRIP		 = 2
		GL_TRIANGLES,		// PRIMITIVE_TYPE_TRIGNALE_LIST	 = 3
		GL_TRIANGLE_STRIP	// PRIMITIVE_TYPE_TRIANGLE_STRIP = 4
	};
	
	return primitiveModels[ primitive ];
}



/*===== EOF ==================================================================*/