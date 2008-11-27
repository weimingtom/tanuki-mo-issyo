/*******************************************************************************/
/**
 * @file VertexStreamDesc.h.
 * 
 * @brief 頂点ストリーム記述子構造体定義.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_VERTEX_STREAM_DESC_H_
#define _NGL_VERTEX_STREAM_DESC_H_

namespace Ngl{

// バッファインターフェース
class IBuffer;

/**
 * @struct VertexStreamDesc.
 * @brief 頂点ストリーム記述子構造体.
 */
struct VertexStreamDesc
{
	/** 頂点バッファ */
	IBuffer*		buffer;

	/** バッファまでのオフセット値 */
	unsigned int	offset;

	/** ストライド値 */
	unsigned int	stride;


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	VertexStreamDesc():
		buffer( 0 ),
		stride( 0 ),
		offset( 0 )
	{}


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] Buffer 頂点バッファ.
	 * @param[in] Offset バッファまでのオフセット値.
	 * @param[in] Stride ストライド値.
	 */
	VertexStreamDesc( IBuffer* Buffer, unsigned int Offset=0, unsigned int Stride=0 ):
		buffer( Buffer ),
		offset( Offset ),
		stride( Stride )
	{}

};

} // namesapce Ngl

#endif

/*===== EOF ==================================================================*/