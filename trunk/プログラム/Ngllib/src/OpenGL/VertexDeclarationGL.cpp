/*******************************************************************************/
/**
 * @file VertexDeclarationGL.cpp.
 * 
 * @brief OpenGL 頂点宣言データクラスソースファイル.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/OpenGL/VertexDeclarationGL.h"
#include	"Ngl/OpenGL/BufferGL.h"

using namespace Ngl;
using namespace Ngl::OpenGL;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] desc 頂点宣言データ記述子の配列.
 * @param[in] numDesc 頂点宣言データ記述子配列の要素数.
 */
VertexDeclarationGL::VertexDeclarationGL( const VertexDeclarationDesc desc[], unsigned int numDesc ):
	desc_( &desc[0], &desc[numDesc] ),
	elements_( numDesc )
{
	for( unsigned int  i=0; i<numDesc; ++i ){
		elements_[i] = toElement( desc_[i] );
	}
}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
VertexDeclarationGL::~VertexDeclarationGL()
{}



/*=========================================================================*/
/**
 * @brief 頂点宣言データの個数を取得
 * 
 * @param[in] なし.
 * @return 個数.
 */
unsigned int VertexDeclarationGL::size() const
{
	return (unsigned int)desc_.size();
}



/*=========================================================================*/
/**
 * @brief 記述子を取得
 * 
 * @param[in] index 取得する記述子のインデックス番号.
 * @return 記述子.
 */
const VertexDeclarationDesc& VertexDeclarationGL::desc( unsigned int index ) const
{
	return desc_[index];
}



/*=========================================================================*/
/**
 * @brief 頂点バッファストリームの設定
 * 
 * @param[in] streams 設定する頂点ストリーム記述子配列.
 * @param[in] start 設定開始配列位置.
 * @return なし.
 */
void VertexDeclarationGL::setVertexStream( const VertexStreamDesc streams[], unsigned int start )
{
	// 頂点ストリームのリセット
	resetVertexStream();

	// 頂点バッファを設定する
	for( VertexDeclarationArray::iterator i = elements_.begin(); i !=elements_.end(); ++i ){
		setVertexBuffer( *i, streams[ (*i).stream ], start );
	}
}



/*=========================================================================*/
/**
 * @brief 頂点バッファストリームのリセット
 * 
 * @param[in] なし.
 * @return なし.
 */
void VertexDeclarationGL::resetVertexStream()
{
	// 頂点配列を無効にする
	for( GLuint attr=0; attr<VERTEX_DECLARATION_MAX; ++attr ){
		glDisableVertexAttribArray( attr );
	}
}



/*=========================================================================*/
/**
 * @brief 頂点バッファの設定
 * 
 * @param[in] element 頂点宣言要素構造体.
 * @param[in] stream 頂点ストリーム記述子.
 * @param[in] start 開始位置.
 * @return なし.
 */
void VertexDeclarationGL::setVertexBuffer( const VertexDeclarationGL::Element& element, const VertexStreamDesc& stream, unsigned int start )
{
	// 頂点バッファをバインドする
	glBindBufferARB( GL_ARRAY_BUFFER_ARB, static_cast< BufferGL* >( stream.buffer )->buffer() );

	// 頂点データ配列を有効にする
	glEnableVertexAttribArrayARB( element.attrib );

	// 頂点バッファを設定する
	GLubyte* base = 0;
	glVertexAttribPointerARB(
		element.attrib,
		element.format.size,
		element.format.type,
		element.format.normalized,
		stream.stride,
		&base[ start * stream.stride + stream.offset + element.offset ]
		);

	// 頂点バッファのバインドを解除
	glBindBufferARB( GL_ARRAY_BUFFER_ARB, 0 );
}



/*=========================================================================*/
/**
 * @brief 頂点宣言記述子を変換
 * 
 * @param[in] desc 変換する頂点宣言記述子構造体.
 * @return 変換後の頂点宣言要素構造体.
 */
VertexDeclarationGL::Element VertexDeclarationGL::toElement( const VertexDeclarationDesc& desc )
{
	Element element;
	element.attrib	= toAttrib( desc.semantic ) + desc.index;
	element.format	= toVertexFormat( desc.type );
	element.offset	= desc.offset;
	element.stream	= desc.stream;
	return element;
}



/*=========================================================================*/
/**
 * @brief 頂点セマンティックを変換
 * 
 * @param[in] semantic 変換する頂点セマンティックフラグ.
 * @return 変換後のOpenGL頂点セマンティック.
 */
GLuint VertexDeclarationGL::toAttrib( VertexSemantic semantic )
{
	static const unsigned int attribs[] = {
		0,	// VERTEX_FORMAT_POSITION		= 0
		1,	// VERTEX_FORMAT_BLENDWEIGHT	= 1
		2,	// VERTEX_FORMAT_NORMAL			= 2
		3,	// VERTEX_FORMAT_COLOR			= 3
		3,	// VERTEX_FORMAT_DIFFUSE		= 4
		4,	// VERTEX_FORMAT_SPECULAR		= 5
		5,	// VERTEX_FORMAT_TESSFACTOR		= 6
		5,	// VERTEX_FORMAT_FOGCOORD		= 7
		6,	// VERTEX_FORMAT_PSIE			= 8
		7,	// VERTEX_FORMAT_BLENDINDICES	= 9
		8,	// VERTEX_FORMAT_TEXCOORD		= 10
		14,	// VERTEX_FORMAT_TANGENT		= 11
		15	// VERTEX_FORMAT_BINORMAL		= 12
	};

	return attribs[ semantic ];
}



/*=========================================================================*/
/**
 * @brief 頂点タイプを変換
 * 
 * @param[in] type 変換する頂点タイプフラグ.
 * @return 変換後の頂点フォーマット構造体.
 */
const VertexDeclarationGL::VertexFormat& VertexDeclarationGL::toVertexFormat( VertexType type )
{
	static const VertexFormat vertexFormats[] = {
		{ GL_FLOAT,				1,	GL_FALSE },		// VERTEX_TYPE_FLOAT1	= 0
		{ GL_FLOAT,				2,	GL_FALSE },		// VERTEX_TYPE_FLOAT2	= 1
		{ GL_FLOAT,				3,	GL_FALSE },		// VERTEX_TYPE_FLOAT3	= 2
		{ GL_FLOAT,				4,	GL_FALSE },		// VERTEX_TYPE_FLOAT4	= 3
		{ GL_BYTE,				4,	GL_FALSE },		// VERTEX_TYPE_BYTE4	= 4
		{ GL_BYTE,				4,	GL_TRUE	 },		// VERTEX_TYPE_BYTE4N	= 5
		{ GL_UNSIGNED_BYTE,		4,	GL_FALSE },		// VERTEX_TYPE_UBYTE4	= 6
		{ GL_UNSIGNED_BYTE,		4,	GL_TRUE	 },		// VERTEX_TYPE_UBYTE4N	= 7
		{ GL_SHORT,				2,	GL_FALSE },		// VERTEX_TYPE_SHORT2	= 8
		{ GL_SHORT,				2,	GL_TRUE  },		// VERTEX_TYPE_SHORT2N	= 9
		{ GL_UNSIGNED_SHORT,	2,	GL_FALSE },		// VERTEX_TYPE_USHORT2	= 10
		{ GL_UNSIGNED_SHORT,	2,	GL_TRUE	 },		// VERTEX_TYPE_USHORT2N	= 11
		{ GL_SHORT,				4,	GL_FALSE },		// VERTEX_TYPE_SHORT4	= 12
		{ GL_SHORT,				4,	GL_TRUE	 },		// VERTEX_TYPE_SHORT4N	= 13
		{ GL_UNSIGNED_SHORT,	4,	GL_FALSE },		// VERTEX_TYPE_USHORT4	= 14
		{ GL_UNSIGNED_SHORT,	4,	GL_TRUE  },		// VERTEX_TYPE_USHORT4N	= 15
		{ GL_INT,				1,	GL_FALSE },		// VERTEX_TYPE_INT1		= 16
		{ GL_INT,				2,	GL_FALSE },		// VERTEX_TYPE_INT2		= 17
		{ GL_INT,				3,	GL_FALSE },		// VERTEX_TYPE_INT3		= 18
		{ GL_INT,				4,	GL_FALSE },		// VERTEX_TYPE_INT4		= 19
		{ GL_UNSIGNED_INT,		1,	GL_FALSE },		// VERTEX_TYPE_UINT1	= 20
		{ GL_UNSIGNED_INT,		2,	GL_FALSE },		// VERTEX_TYPE_UINT2	= 21
		{ GL_UNSIGNED_INT,		3,	GL_FALSE },		// VERTEX_TYPE_UINT3	= 22
		{ GL_UNSIGNED_INT,		4,	GL_FALSE }		// VERTEX_TYPE_UINT4	= 23
	};

	return vertexFormats[ type ];
}



/*===== EOF ==================================================================*/