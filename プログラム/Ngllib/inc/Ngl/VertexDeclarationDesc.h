/*******************************************************************************/
/**
 * @file VertexDeclarationDesc.h.
 * 
 * @brief Έ_ιΎ\’Μθ`.
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
 * @brief Έ_Z}eBbNρ^.
 */
enum VertexSemantic
{
	VERTEX_SEMANTIC_POSITION		= 0,	/**< Έ_ΐW			*/
	VERTEX_SEMANTIC_BLENDWEIGHT		= 1,	/**< Έ_EFCg		*/
	VERTEX_SEMANTIC_NORMAL			= 2,	/**< @όxNg		*/
	VERTEX_SEMANTIC_COLOR			= 3,	/**< Έ_J[			*/
	VERTEX_SEMANTIC_DIFFUSE			= 4,	/**< gU½ΛυJ[	*/
	VERTEX_SEMANTIC_SPECULAR		= 5,	/**< ΎΚ½ΛυJ[	*/
	VERTEX_SEMANTIC_TESSFACTOR		= 6,	/**< ebZ[V	*/
	VERTEX_SEMANTIC_FOGCOORD		= 7,	/**< tHOΚu			*/
	VERTEX_SEMANTIC_PSIZE			= 8,	/**< |CgTCY		*/
	VERTEX_SEMANTIC_BLENDINDICES	= 9,	/**< {[Τ			*/
	VERTEX_SEMANTIC_TEXCOORD		= 10,	/**< eNX`ΐW0`8	*/
	VERTEX_SEMANTIC_TANGENT			= 11,	/**< ΪxNg			*/
	VERTEX_SEMANTIC_BINORMAL		= 12	/**< ]@όxNg		*/
};


/**
 * @enum VertexType.
 * @brief Έ_^Cvρ^.
 */
enum VertexType
{
	VERTEX_TYPE_FLOAT1		= 0,	/**< float^			vf1			*/
	VERTEX_TYPE_FLOAT2		= 1,	/**< float^			vf2			*/
	VERTEX_TYPE_FLOAT3		= 2,	/**< float^			vf3			*/
	VERTEX_TYPE_FLOAT4		= 3,	/**< float^			vf4			*/
	VERTEX_TYPE_BYTE4		= 4,	/**< char^				vf4			*/
	VERTEX_TYPE_BYTE4N		= 5,	/**< char^				vf4 ³K»	*/
	VERTEX_TYPE_UBYTE4		= 6,	/**< unsigned char^	vf4			*/
	VERTEX_TYPE_UBYTE4N		= 7,	/**< unsigned chart^	vf4	³K»	*/
	VERTEX_TYPE_SHORT2		= 8,	/**< char^				vf2			*/
	VERTEX_TYPE_SHORT2N		= 9,	/**< char^				vf2	³K»	*/
	VERTEX_TYPE_USHORT2		= 10,	/**< unsigned char^	vf2			*/
	VERTEX_TYPE_USHORT2N	= 11,	/**< unsigned char^	vf2	³K»	*/
	VERTEX_TYPE_SHORT4		= 12,	/**< short^			vf4			*/
	VERTEX_TYPE_SHORT4N		= 13,	/**< short^			vf4	³K»	*/
	VERTEX_TYPE_USHORT4		= 14,	/**< unsigned short^	vf4			*/
	VERTEX_TYPE_USHORT4N	= 15,	/**< unsigned short^	vf4	³K»	*/
	VERTEX_TYPE_INT1		= 16,	/**< int^				vf1			*/
	VERTEX_TYPE_INT2		= 17,	/**< int^				vf2			*/
	VERTEX_TYPE_INT3		= 18,	/**< int^				vf3			*/
	VERTEX_TYPE_INT4		= 19,	/**< int^				vf4			*/
	VERTEX_TYPE_UINT1		= 20,	/**< unsigned int^		vf1			*/
	VERTEX_TYPE_UINT2		= 21,	/**< unsigned int^		vf2			*/
	VERTEX_TYPE_UINT3		= 22,	/**< unsigned int^		vf3			*/
	VERTEX_TYPE_UINT4		= 23	/**< unsigned int^		vf4			*/
};


/** Έ_ιΎΜΕεl */
static const unsigned int VERTEX_DECLARATION_MAX	= 16;


/**
 * @struct VertexDeclarationDesc.
 * @brief Έ_ιΎLqq\’Μ.
 */
struct VertexDeclarationDesc
{
	/** Z}eBbN */
	VertexSemantic	semantic;

	/** Z}eBbNCfbNX */
	unsigned int	index;

	/** Έ_^Cv */
	VertexType		type;

	/** ItZbg */
	unsigned int	offset;

	/** Xg[Τ */
	unsigned int	stream;
};

} // namespace Ngl

#endif