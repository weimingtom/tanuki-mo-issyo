/*******************************************************************************/
/**
 * @file TextureDesc.h.
 * 
 * @brief テクスチャ記述子構造体定義.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_TEXTURE_DESC_H_
#define _NGL_TEXTURE_DESC_H_

namespace Ngl{


/**
 * @enum TextureType．
 * @brief テクスチャの種類列挙型.
 */
enum TextureType
{
	TEXTURE_TYPE_1D		= 0,	/**< 1Dテクスチャ		*/
	TEXTURE_TYPE_2D		= 1,	/**< 2Dテクスチャ		*/
	TEXTURE_TYPE_3D		= 2,	/**< 3Dテクスチャ		*/
	TEXTURE_TYPE_CUBE	= 3		/**< キューブテクスチャ	*/
};


/**
 * @enum TextureFormat．
 * @brief テクスチャフォーマット列挙型.
 */
enum TextureFormat
{
	TEXTURE_FORMAT_I8			= 0,
	TEXTURE_FORMAT_IA8			= 1,
	TEXTURE_FORMAT_RGBA8		= 2,
	TEXTURE_FORMAT_I16			= 3,
	TEXTURE_FORMAT_IA16			= 4,
	TEXTURE_FORMAT_RBGA16		= 5,
	TEXTURE_FORMAT_I16F			= 6,
	TEXTURE_FORMAT_IA16F		= 7,
	TEXTURE_FORMAT_RGBA16F		= 8,
	TEXTURE_FORMAT_I32F			= 9,
	TEXTURE_FORMAT_IA32F		= 10,
	TEXTURE_FORMAT_RGB32F		= 11,
	TEXTURE_FORMAT_RGBA32F		= 12,
	TEXTURE_FORMAT_R11G11B10F	= 13,
	TEXTURE_FORMAT_DXT1			= 14,
	TEXTURE_FORMAT_DXT3			= 15,
	TEXTURE_FORMAT_DXT5			= 16,
	TEXTURE_FORMAT_D16			= 17,
	TEXTURE_FORMAT_D32F			= 18,
	TEXTURE_FORMAT_D24S8		= 19
};


/**
 * @enum TextureUsage．
 * @brief テクスチャの使用方法列挙型.
 */
enum TextureUsage
{
	TEXTURE_USAGE_DEFAULT	= 0,
	TEXTURE_USAGE_IMMUTABLE = 1,
	TEXTURE_USAGE_DYNAMIC	= 2,
};


/**
 * @struct TextureDesc．
 * @brief テクスチャ作成記述子構造体.
 */
struct TextureDesc
{
	/** テクスチャタイプ */
	TextureType		type;

	/** テクスチャフォーマット */
	TextureFormat	format;

	/** 幅 */
	unsigned int	width;

	/** 高さ */
	unsigned int	height;

	/** 深さ */
	unsigned int	depth;

	/** ミップマップレベル */
	unsigned int	mipLevels;

	/** バッファの使用法 */
	TextureUsage	usage;

	/** レンダーターゲットに設定できるか */
	bool			renderTarget;

	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	TextureDesc():
		type( TEXTURE_TYPE_2D ),
		format( TEXTURE_FORMAT_RGBA8 ),
		width( 1 ),
		height( 1 ),
		depth( 1 ),
		mipLevels( 1 ),
		usage( TEXTURE_USAGE_DEFAULT ),
		renderTarget( false )
	{}
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/