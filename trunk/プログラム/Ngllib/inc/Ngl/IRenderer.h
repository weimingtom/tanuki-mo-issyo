/*******************************************************************************/
/**
 * @file IRenderer.h.
 * 
 * @brief レンダラーインターフェース定義.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IRENDERER_H_
#define _NGL_IRENDERER_H_

#include	"IBuffer.h"
#include	"ITexture.h"
#include	"IVertexDeclaration.h"
#include	"IEffect.h"
#include	"VertexStreamDesc.h"
#include	"ViewportDesc.h"

namespace Ngl{


/**
 * @enum PrimitiveType.
 * @brief プリミティブタイプ列挙型.
 */
enum PrimitiveType
{
	PRIMITIVE_TYPE_POINT_LIST		= 0,	/** 点リスト			*/
	PRIMITIVE_TYPE_LINE_LIST		= 1,	/** 線分リスト			*/
	PRIMITIVE_TYPE_LINE_STRIP		= 2,	/** 線分ストリップ		*/
	PRIMITIVE_TYPE_TRIANGLE_LIST	= 3,	/** 三角形リスト		*/
	PRIMITIVE_TYPE_TRIANGLE_STRIP	= 4		/** 三角形ストリップ	*/
};


/**
 * @enum IndexType
 * @brief 頂点インデックスタイプ列挙型.
 */
enum IndexType{
	INDEX_TYPE_USHORT	= 0,	/**< unsigned short型	*/
	INDEX_TYPE_UINT		= 1		/**< unsigned int型		*/
};


/**
 * @interface IRenderer.
 * @brief レンダラーインターフェース
 */
class IRenderer
{
public:
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IRenderer(){}

	
	/*=========================================================================*/
	/**
	 * @brief 初期化処理
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void initialize() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief ビューポートの設定
	 * 
	 * @param[in] desc ビューポート記述子.
	 * @return なし.
	 */
	virtual void setViewport( const ViewportDesc& desc ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief ビューポートの取得
	 * 
	 * @param[in] なし.
	 * @return ビューポート記述子.
	 */
	virtual const ViewportDesc& getViewport() const = 0;

	
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
	virtual void clearColorBuffer( float r=0.0f, float g=0.0f, float b=0.0f, float a=0.0f ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief デプスステンシルバッファを消去
	 * 
	 * @param[in] depth デプスバッファを消去するか.
	 * @param[in] stencil ステンシルバッファを消去するか.
	 * @return なし.
	 */
	virtual void clearDepthStencilBuffer( bool depth=true, bool stencil=false ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief バッファを作成
	 * 
	 * @param[in] desc バッファ記述子.
	 * @param[in] data バッファデータ.
	 * @return 作成したバッファインターフェースのポインタ.
	 */
	virtual IBuffer* createBuffer( const BufferDesc& desc, const void* data=0 ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief テクスチャを作成
	 * 
	 * @param[in] desc テクスチャ記述子.
	 * @param[in] data テクスチャデータ.
	 * @return 作成したテクスチャインターフェースのポインタ.
	 */
	virtual ITexture* createTexture( const TextureDesc& desc, const void* data=0 ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief 頂点宣言を作成
	 * 
	 * @param[in] desc 頂点宣言記述子の配列.
	 * @param[in] numDesc 頂点宣言記述子配列の要素数.
	 * @param[in] inputSignature 入力シグネチャ記述子.
	 * @return 作成した頂点宣言インターフェースのポインタ.
	 */
	virtual IVertexDeclaration* createVertexDeclaration( const VertexDeclarationDesc desc[], unsigned int numDesc, const InputSignatureDesc& inputSignature ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief エフェクトの作成
	 * 
	 * @param[in] fileName エフェクトファイル名.
	 * @return 作成したエフェクトインターフェースのポインタ.
	 */
	virtual IEffect* createEffect( const char* fileName ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief 頂点宣言データを設定
	 * 
	 * @param[in] layout 設定する頂点宣言データのポインタ.
	 * @return なし.
	 */
	virtual void setVertexDeclaration( IVertexDeclaration* layout ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief バッファを設定
	 * 
	 * @param[in] stream 頂点ストリーム記述子配列.
	 * @param[in] numStream 頂点ストリーム記述子配列の要素数.
	 * @param[in] offset オフセット値.
	 * @return なし.
	 */
	virtual void setVertexBuffer( const VertexStreamDesc stream[], unsigned int numStream=1, unsigned int offset=0 ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief インデックスバッファを設定
	 * 
	 * @param[in] buffer インデックスバッファのポインタ.
	 * @param[in] type 頂点タイプ.
	 * @param[in] offset オフセット値.
	 * @return なし.
	 */
	virtual void setIndexBuffer( IBuffer* buffer, IndexType type, unsigned int offset=0 ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief ミップマップの作成
	 * 
	 * @param[in] texture ミップマップを作成するテクスチャのポインタ.
	 * @return なし.
	 */
	virtual void generateMipmap( ITexture* texture ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief 描画するプリミティブを設定
	 * 
	 * @param[in] primitiveType プリミティブタイプ.
	 * @return なし.
	 */
	virtual void setPrimitive( PrimitiveType primitiveType ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief 頂点バッファを描画
	 * 
	 * @param[in] numVertex 描画する頂点数.
	 * @param[in] start 開始頂点番号.
	 * @return なし.
	 */
	virtual void draw( unsigned int numVertex, unsigned int start=0 ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief インデックスバッファを使用して描画する
	 * 
	 * @param[in] numIndices インデックス数.
	 * @param[in] startIndex 開始インデックス番号.
	 * @param[in] startVertex 開始頂点番号
	 * @return なし.
	 */
	virtual void drawIndexed( unsigned int numIndices, unsigned int startIndex=0, unsigned int startVertex=0 ) = 0;

	
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
	virtual void setRenderTargets( ITexture* targets[], unsigned int numTargets, ITexture* depthStencil, unsigned int index=0 ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief レンダーターゲットをリセット
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void resetRenderTargets() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief レンダラーをフラッシュ
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void flush() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief レンダラーの状態をクリア
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void clearState() = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/