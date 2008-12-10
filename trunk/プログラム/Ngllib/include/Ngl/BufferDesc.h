/*******************************************************************************/
/**
 * @file BufferDesc.h.
 * 
 * @brief バッファ作成記述子構造体定義.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_BUFFER_DESC_H_
#define _NGL_BUFFER_DESC_H_

namespace Ngl{


/**
 * @enum BufferUsage
 * @brief バッファの使用方法列挙型.
 */
enum BufferUsage
{
	BUFFER_USAGE_DEFAULT	= 0,	/**< デフォルト					*/
	BUFFER_USAGE_IMMUTABLE	= 1,	/**< 作成時のみ一度だけ書き込む	*/
	BUFFER_USAGE_DYNAMIC	= 2		/**< 頻繁に書き込み				*/
};


/**
 * @enum BufferType．
 * @brief バッファタイプ列挙型.
 */
enum BufferType
{
	BUFFER_TYPE_VERTEX	= 0,	/**< 頂点バッファ			*/
	BUFFER_TYPE_INDEX	= 1		/**< インデックスバッファ	*/
};


/**
 * @struct BufferDesc．
 * @brief バッファ作成記述子構造体.
 */
struct BufferDesc
{
	/** バッファタイプ */
	BufferType	type;

	/** バッファの使用方法 */
	BufferUsage	usage;

	/** データのバイト数 */
	unsigned int	size;


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	BufferDesc():
		type( BUFFER_TYPE_VERTEX),
		usage( BUFFER_USAGE_DEFAULT ),
		size( 0 )
	{}
};

}	// namesapce Ngl

#endif

/*===== EOF ==================================================================*/