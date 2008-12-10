/*******************************************************************************/
/**
 * @file PolygonQuad.cpp.
 * 
 * @brief 四角形ポリゴンクラスソースファイル.
 *
 * @date 2008/08/06.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/PolygonQuad.h"
#include	"Ngl/Vector3.h"
#include	"Ngl/Matrix4.h"

using namespace Ngl;


/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
PolygonQuad::PolygonQuad():
	vertexBuffer_( 0 ),
	indexBuffer_( 0 ),
	texcoordBuffer_( 0 ),
	normalBuffer_( 0 ),
	isDeleted_( false )
{}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
PolygonQuad::~PolygonQuad()
{
	end();
}



/*=========================================================================*/
/**
 * @brief 作成処理
 * 
 * @param[in] レンダラー.
 * @return なし.
 */
void PolygonQuad::create( IRenderer* renderer )
{
	// 頂点バッファの作成
	const static float vertices[][3] = {
		{ -0.5f,  0.5f, 0.0f },
		{ -0.5f, -0.5f, 0.0f },
		{  0.5f, -0.5f, 0.0f },
		{  0.5f,  0.5f, 0.0f }
	};
	Ngl::BufferDesc vertexBuffer;
	vertexBuffer.size	= sizeof( vertices );
	vertexBuffer.type	= BUFFER_TYPE_VERTEX;
	vertexBuffer.usage	= BUFFER_USAGE_DYNAMIC;
	vertexBuffer_ = renderer->createBuffer( vertexBuffer, vertices );

	// インデックスバッファを作成
	const static unsigned short indices[] = {
		0, 1, 2,
		0, 2, 3
	};
	Ngl::BufferDesc indexBuffer;
	indexBuffer.size	= sizeof( indices );
	indexBuffer.type	= BUFFER_TYPE_INDEX;
	indexBuffer.usage	= BUFFER_USAGE_DYNAMIC;
	indexBuffer_ = renderer->createBuffer( indexBuffer, indices );


	// テクスチャ座標バッファを作成
	const static float texcoords[][2] = {
		{ 0.0f, 0.0f },
		{ 0.0f, 1.0f },
		{ 1.0f, 1.0f },
		{ 1.0f, 0.0f }
	};
	/*const static float texcoords[][2] = {
		{ 0.0f, 1.0f },
		{ 0.0f, 0.0f },
		{ 1.0f, 0.0f },
		{ 1.0f, 1.0f }
	};*/

	Ngl::BufferDesc texcoordBuffer;
	texcoordBuffer.size		= sizeof( texcoords );
	texcoordBuffer.type		= BUFFER_TYPE_VERTEX;
	texcoordBuffer.usage	= BUFFER_USAGE_DYNAMIC;
	texcoordBuffer_ = renderer->createBuffer( texcoordBuffer, texcoords );

	// 法線ベクトルバッファを作成
	const static float normals[][3] = {
		{ 0.0f, 0.0f, 1.0f },
		{ 0.0f, 0.0f, 1.0f },
		{ 0.0f, 0.0f, 1.0f },
		{ 0.0f, 0.0f, 1.0f }
	};
	Ngl::BufferDesc normalBuffer;
	normalBuffer.size	= sizeof( normals );
	normalBuffer.type	= BUFFER_TYPE_VERTEX;
	normalBuffer.usage	= BUFFER_USAGE_DYNAMIC;
	normalBuffer_ = renderer->createBuffer( normalBuffer, normals );

	// 頂点ストリーム配列を作成
	Ngl::VertexStreamDesc streams[] = {
		Ngl::VertexStreamDesc( vertexBuffer_, 0, sizeof(float)*3 ),
		Ngl::VertexStreamDesc( normalBuffer_, 0, sizeof(float)*3 ),
		Ngl::VertexStreamDesc( texcoordBuffer_, 0, sizeof(float)*2 )
	};
	for( int i=0; i<3; ++i ){
		streamArray_.push_back( streams[ i ] );
	}
}



/*=========================================================================*/
/**
 * @brief 描画処理
 * 
 * @param[in] renderer レンダラー.
 * @param[in] effect エフェクト.
 * @return なし.
 */
void PolygonQuad::draw( IRenderer* renderer, IEffect* effect )
{
	static const VertexDeclarationDesc layout[] = {
		{ VERTEX_SEMANTIC_POSITION, 0, VERTEX_TYPE_FLOAT3, sizeof(float)*0, 0 },
		{ VERTEX_SEMANTIC_NORMAL,   0, VERTEX_TYPE_FLOAT3, sizeof(float)*0, 1 },
		{ VERTEX_SEMANTIC_TEXCOORD, 0, VERTEX_TYPE_FLOAT2, sizeof(float)*0, 2 }
	};

	// インデックスバッファを設定
	renderer->setIndexBuffer( indexBuffer_, INDEX_TYPE_USHORT );

	// 頂点バッファを設定
	renderer->setVertexBuffer( &streamArray_[0], 3 );

	// エフェクトのパス数分レンダリング
	for( int passNo=0; passNo<effect->getNumPass(); ++passNo ){
		// エフェクトを開始
		effect->begin( passNo );
		
		// 頂点宣言データを作成
		IVertexDeclaration* vertexDeclaration = renderer->createVertexDeclaration( 
			layout,																	// 頂点レイアウト記述子配列
			3,																		// 要素数
			effect->inputSigneture( effect->getCurrentTechniqueName(), passNo ) );	// 入力シグネチャ
		renderer->setVertexDeclaration( vertexDeclaration );

		// プリミティブを設定
		renderer->setPrimitive( PRIMITIVE_TYPE_TRIANGLE_LIST );
	
		// 描画
		renderer->drawIndexed( 6 );

		// エフェクトを終了
		effect->end();

		// 作成した頂点宣言データを削除
		delete vertexDeclaration;
	}
}



/*=========================================================================*/
/**
 * @brief 終了処理
 * 
 * @param[in] なし.
 * @return なし.
 */
void PolygonQuad::end()
{
	// すでに削除されているか
	if( isDeleted_ == true ){
		return;
	}

	delete vertexBuffer_;
	delete indexBuffer_;
	delete texcoordBuffer_;
	delete normalBuffer_;

	isDeleted_ = true;
}
	
	
	
/*=========================================================================*/
/**
 * @brief ポリゴンの矩形を設定
 * 
 * @param[in] size 矩形値( ワールド座標 ).
 * @return なし.
 */
void PolygonQuad::setSize( const Rect& size )
{
	Vector3 vertices[] = {
		Vector3( size.left,  size.top,    0.0f ),
		Vector3( size.left,  size.bottom, 0.0f ),
		Vector3( size.right, size.bottom, 0.0f ),
		Vector3( size.right, size.top,    0.0f )
	};
	vertexBuffer_->setData( vertices );
}


	
/*=========================================================================*/
/**
 * @brief ポリゴンの矩形を設定( 2Dスプライト用 )
 * 
 * @param[in] size 矩形値( スクリーン座標 ).
 * @param[in] windowWidth ウィンドウの幅.
 * @param[in] windowHeight ウィンドウの高さ.
 * @return なし.
 */
void PolygonQuad::setSize2D( const Rect& size, int windowWidth, int windowHeight )
{
	Vector3 vertices[] = {
		Vector3( size.left,  size.top,    0.0f ),
		Vector3( size.left,  size.bottom, 0.0f ),
		Vector3( size.right, size.bottom, 0.0f ),
		Vector3( size.right, size.top,    0.0f )
	};

	// ワールド座標からスクリーン座標への変換行列を作成
	Matrix4 model;
	model.setIdentitiy();
	model.m[0][0] = 1.0f / windowWidth;
	model.m[1][1] = 1.0f / windowHeight;

	// すべての頂点を座標変換する
	for( int i=0; i<4; ++i ){
		vertices[ i ].transform( model );

		vertices[ i ].x -= 0.5f;
		vertices[ i ].y -= 0.5f;
	}
	
	vertexBuffer_->setData( vertices );
}



/*=========================================================================*/
/**
 * @brief テクスチャ座標を設定する
 *
 * @param[in] srcRect 矩形値( ワールド座標 ).
 * @return なし.
 */
void PolygonQuad::setSrcRect( const Rect& srcRect )
{
	float texcoords[][2] = {
		{ srcRect.left,  srcRect.top },
		{ srcRect.left,  srcRect.bottom },
		{ srcRect.right, srcRect.bottom },
		{ srcRect.right, srcRect.top }
	};

	texcoordBuffer_->setData( texcoords );
}
	
	
	
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
void PolygonQuad::setSrcRect( const Rect& srcRect, int width, int height )
{
	// テクスチャ座標の計算を行う
	Rect rc( 
		srcRect.left   / width,
		srcRect.top    / height,
		srcRect.right  / width,
		srcRect.bottom / height
	);

	setSrcRect( rc );
}



/*===== EOF ==================================================================*/