/*******************************************************************************/
/**
 * @file BitMap.h.
 * 
 * @brief ビットマップ構造体ヘッダファイル.
 *
 * @date 2008/07/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_BMP_BITMAP_H_
#define _NGL_BMP_BITMAP_H_


namespace Ngl{


namespace BMP{


/** 符号無し8bit型 */
typedef unsigned char BYTE;

/** 符号なし16bit型 */
typedef unsigned short WORD;

/** 符号無し32bit型 */
typedef unsigned long DWORD;

/** 符号付32bit型 */
typedef long LONG;


/**
 * @struct BitMapFileHeader.
 * @brief BMP ビットマップファイルヘッダ構造体.
 */
struct BitMapFileHeader
{
	 WORD    bfType;		/**< ファイルタイプ							*/
	 DWORD   bfSize;		/**< ビットマップファイルサイズ				*/
	 WORD    bfReserved1;	/**< 現在使われていない						*/
	 WORD    bfReserved2;	/**< 現在使われていない						*/
	 DWORD   bfOffBits;		/**< この構造体から画像ビットまでのバイト数	*/
};


/**
 * @struct BitMapInfoHeader.
 * @brief BMP ビットマップ情報ヘッダ構造体.
 */
struct BitMapInfoHeader
{
	DWORD  biSize;			/**< 構造体のバイト数 ( sizeof(BitMapInfoHeader) )	*/
	LONG   biWidth;			/**< ビットマップの幅( ピクセル単位					*/
	LONG   biHeight;		/**< ビットマップの高さ( ピクセル単位				*/
	WORD   biPlanes;		/**< ターゲットデバイスのためのプレーン数 ( 必ず1	*/
	WORD   biBitCount;		/**< 1ピクセルあたりのビット数( 0,1,4,8,16,24,32 )	*/
	DWORD  biCompression;	/**< 圧縮フォーマットフラグ							*/
	DWORD  biSizeImage;		/**< 画像のサイズ									*/
	LONG   biXPelsPerMeter;	/**< ターゲットデバイスの水平方向の解像度			*/
	LONG   biYPelsPerMeter;	/**< ターゲットデバイスの垂直方向の解像度			*/
	DWORD  biClrUsed;		/**< カラーテーブルのデータ数						*/
	DWORD  biClrImportant;	/**< 表示するのに必要なカラーテーブルデータ数		*/
};


/**
 * @struct RGBQuad.
 * @brief BMP RGBデータ構造体.
 */
struct RGBQuad
{
	BYTE    rgbBlue;		/**< 青成分	*/
	BYTE    rgbGreen;		/**< 緑成分	*/
	BYTE    rgbRed;			/**< 赤成分	*/
	BYTE    rgbReserved;	/**< 予約	*/
};


/**
 * @enum BitCount.
 * @brief BMP ビットカウント列挙型.
 */
enum BitCount
{
	BITCOUNT_2	= 2,	/**< 2色ビットマップ				*/
	BITCOUNT_4	= 4,	/**< 4色ビットマップ				*/
	BITCOUNT_8	= 8,	/**< 256色ビットマップ				*/
	BITCOUNT_24	= 24,	/**< 24ビットフルカラービットマップ	*/
	BITCOUNT_32	= 32	/**< 32ビットアルファ付ビットマップ	*/
};


/** ビットマップ識別フラグ */
static const unsigned short BITMAPFLAG = 0x4D42;


/**
 * @struct BitMap.
 * @brief BMP ビットマップデータ構造体.
 */
struct BitMap
{
	/** ファイルヘッダ */
	BitMapFileHeader	fileHeader;

	/** ファイル情報 */
	BitMapInfoHeader	infoHeader;

	/** RGBパレットデータ配列 */
	RGBQuad				rgbQuad[ 256 ];


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	BitMap();

};

} // namespace BMP

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/