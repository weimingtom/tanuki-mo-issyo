/*******************************************************************************/
/**
 * @file VertexDeclarationDesc.h.
 * 
 * @brief 頂点宣言構造体定義.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_VERTEX_DECLARATION_DESC_H_
#define _NGL_VERTEX_DECLARATION_DESC_H_

namespace Ngl{


/**
 * @enum VertexSemantic.
 * @brief 頂点セマンティック列挙型.
 */
enum VertexSemantic
{
	VERTEX_SEMANTIC_POSITION		= 0,	/**< 頂点座標			*/
	VERTEX_SEMANTIC_BLENDWEIGHT		= 1,	/**< 頂点ウェイト		*/
	VERTEX_SEMANTIC_NORMAL			= 2,	/**< 法線ベクトル		*/
	VERTEX_SEMANTIC_COLOR			= 3,	/**< 頂点カラー			*/
	VERTEX_SEMANTIC_DIFFUSE			= 4,	/**< 拡散反射光カラー	*/
	VERTEX_SEMANTIC_SPECULAR		= 5,	/**< 鏡面反射光カラー	*/
	VERTEX_SEMANTIC_TESSFACTOR		= 6,	/**< テッセレーション	*/
	VERTEX_SEMANTIC_FOGCOORD		= 7,	/**< フォグ位置			*/
	VERTEX_SEMANTIC_PSIZE			= 8,	/**< ポイントサイズ		*/
	VERTEX_SEMANTIC_BLENDINDICES	= 9,	/**< ボーン番号			*/
	VERTEX_SEMANTIC_TEXCOORD		= 10,	/**< テクスチャ座標0～8	*/
	VERTEX_SEMANTIC_TANGENT			= 11,	/**< 接ベクトル			*/
	VERTEX_SEMANTIC_BINORMAL		= 12	/**< 従法線ベクトル		*/
};


/**
 * @enum VertexType.
 * @brief 頂点タイプ列挙型.
 */
enum VertexType
{
	VERTEX_TYPE_FLOAT1		= 0,	/**< float型			要素数1			*/
	VERTEX_TYPE_FLOAT2		= 1,	/**< float型			要素数2			*/
	VERTEX_TYPE_FLOAT3		= 2,	/**< float型			要素数3			*/
	VERTEX_TYPE_FLOAT4		= 3,	/**< float型			要素数4			*/
	VERTEX_TYPE_BYTE4		= 4,	/**< char型				要素数4			*/
	VERTEX_TYPE_BYTE4N		= 5,	/**< char型				要素数4 正規化	*/
	VERTEX_TYPE_UBYTE4		= 6,	/**< unsigned char型	要素数4			*/
	VERTEX_TYPE_UBYTE4N		= 7,	/**< unsigned chart型	要素数4	正規化	*/
	VERTEX_TYPE_SHORT2		= 8,	/**< char型				要素数2			*/
	VERTEX_TYPE_SHORT2N		= 9,	/**< char型				要素数2	正規化	*/
	VERTEX_TYPE_USHORT2		= 10,	/**< unsigned char型	要素数2			*/
	VERTEX_TYPE_USHORT2N	= 11,	/**< unsigned char型	要素数2	正規化	*/
	VERTEX_TYPE_SHORT4		= 12,	/**< short型			要素数4			*/
	VERTEX_TYPE_SHORT4N		= 13,	/**< short型			要素数4	正規化	*/
	VERTEX_TYPE_USHORT4		= 14,	/**< unsigned short型	要素数4			*/
	VERTEX_TYPE_USHORT4N	= 15,	/**< unsigned short型	要素数4	正規化	*/
	VERTEX_TYPE_INT1		= 16,	/**< int型				要素数1			*/
	VERTEX_TYPE_INT2		= 17,	/**< int型				要素数2			*/
	VERTEX_TYPE_INT3		= 18,	/**< int型				要素数3			*/
	VERTEX_TYPE_INT4		= 19,	/**< int型				要素数4			*/
	VERTEX_TYPE_UINT1		= 20,	/**< unsigned int型		要素数1			*/
	VERTEX_TYPE_UINT2		= 21,	/**< unsigned int型		要素数2			*/
	VERTEX_TYPE_UINT3		= 22,	/**< unsigned int型		要素数3			*/
	VERTEX_TYPE_UINT4		= 23	/**< unsigned int型		要素数4			*/
};


/** 頂点宣言の最大値 */
static const unsigned int VERTEX_DECLARATION_MAX	= 16;


/**
 * @struct VertexDeclarationDesc.
 * @brief 頂点宣言記述子構造体.
 */
struct VertexDeclarationDesc
{
	/** セマンティック */
	VertexSemantic	semantic;

	/** セマンティックインデックス */
	unsigned int	index;

	/** 頂点タイプ */
	VertexType		type;

	/** オフセット */
	unsigned int	offset;

	/** ストリーム番号 */
	unsigned int	stream;
};

} // namespace Ngl

#endif