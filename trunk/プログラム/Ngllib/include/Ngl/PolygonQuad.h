/*******************************************************************************/
/**
 * @file PolygonQuad.h.
 * 
 * @brief 四角形ポリゴンクラスヘッダファイル.
 *
 * @date 2008/08/06.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_POLYGONQUAD_H_
#define _NGL_POLYGONQUAD_H_

#include	"IRenderer.h"
#include	"Rect.h"
#include	<vector>

namespace Ngl{


/**
 * @class PolygonQuad．
 * @brief 四角形ポリゴンクラス.
 * @warning インデックスの並びは右手座標系です。
 */
class PolygonQuad
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	PolygonQuad();


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~PolygonQuad();


	/*=========================================================================*/
	/**
	 * @brief 作成処理
	 * 
	 * @param[in] renderer レンダラー.
	 * @return なし.
	 */
	void create( IRenderer* renderert );

	
	/*=========================================================================*/
	/**
	 * @brief 描画処理
	 * 
	 * @param[in] renderer レンダラー.
	 * @param[in] effect エフェクト.
	 * @return なし.
	 */
	void draw( IRenderer* renderer, IEffect* effec );


	/*=========================================================================*/
	/**
	 * @brief 終了処理
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void end();
	
	
	/*=========================================================================*/
	/**
	 * @brief ポリゴンの矩形を設定
	 * 
	 * @param[in] size 矩形値( ワールド座標 ).
	 * @return なし.
	 */
	void setSize( const Rect& size );
	
	
	/*=========================================================================*/
	/**
	 * @brief ポリゴンの矩形を設定( 2Dスプライト用 )
	 * 
	 * @param[in] size 矩形値( スクリーン座標 ).
	 * @param[in] windowWidth ウィンドウの幅.
	 * @param[in] windowHeight ウィンドウの高さ.
	 * @return なし.
	 */
	void setSize2D( const Rect& size, int windowWidth, int windowHeight );


	/*=========================================================================*/
	/**
	 * @brief テクスチャ座標を設定する
	 *
	 * @param[in] srcRect 矩形値( ワールド座標 ).
	 * @return なし.
	 */
	void setSrcRect( const Rect& srcRect );
	
	
	/*=========================================================================*/
	/**
	 * @brief テクスチャ座標を設定する
	 *
	 * スクリーン座標からワールド座標へ変換して設定する.
	 * 
	 * @param[in] srcRect 矩形値( スクリーン座標 ).
	 * @param[in] width テクスチャの幅.
	 * @param[in] height テクスチャの高さ.
	 * @return なし.
	 */
	void setSrcRect( const Rect& srcRect, int width, int height );

private:

	/** 頂点ストリーム配列型 */
	typedef std::vector< Ngl::VertexStreamDesc >	StreamArray;

private:

	/** 頂点バッファ */
	IBuffer*				vertexBuffer_;

	/** インデックスバッファ */
	IBuffer*				indexBuffer_;

	/** テクスチャ座標バッファ */
	IBuffer*				texcoordBuffer_;

	/** 法線ベクトルバッファ */
	IBuffer*				normalBuffer_;

	/** 頂点ストリーム配列 */
	StreamArray				streamArray_;

	/** 削除フラグ */
	bool					isDeleted_;
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/