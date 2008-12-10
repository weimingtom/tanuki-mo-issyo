/*******************************************************************************/
/**
 * @file DDSFile.h.
 * 
 * @brief DDS DDSフォーマット画像ファイル読み込みクラスヘッダファイル.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DDS_DDSFILE_H_
#define _NGL_DDS_DDSFILE_H_

#include	"Ngl/IInputStream.h"
#include	<vector>

namespace Ngl{


// テクスチャフィルタ
class ITextureFilter;

namespace DDS{


/**
 * @class DDSFile.
 * @brief DDS DDSフォーマット画像ファイル読み込みクラス.
 *
 * A8B8G8R8フォーマットのDDSファイルのみ対応.
 */
class DDSFile
{
public:

	/** 符号無し8bit型 */
	typedef unsigned char BYTE;

	/** 符号無し32bit型 */
	typedef unsigned int DWORD;

	
	/**
	 * @struct PixelFormat.
	 * @brief DDS DDSファイルピクセルフォーマット構造体
	 */
	struct PixelFormat
	{
		DWORD			dwSize;
		DWORD			dwFlags;
		DWORD			dwFourCC;
		DWORD			dwRGBBitCount;
		DWORD			dwRBitMask;
		DWORD			dwGBitMask;
		DWORD			dwBBitMask;
		DWORD			dwRGBAlphaBitMask;
	};


	/**
	 * @struct Caps2.
	 * @brief DDS DDSファイル補助フラグ構造体.
	 */
	struct Caps2
	{
		DWORD			dwCaps1;
		DWORD			dwCaps2;
		DWORD			dwReserved[2];
	};

	
	/**
	 * @struct SurfaceDesc.
	 * @brief DDS サーフェース記述子.
	 */
	struct SurfaceDesc
	{
		DWORD			dwSize;
		DWORD			dwFlags;
		DWORD			dwHeight;
		DWORD			dwWidth;
		DWORD			dwPitchOrLinearSize;
		DWORD			dwDepth;
		DWORD			dwMipMapCount;
		DWORD			dwReserved1[11];
		PixelFormat		ddpfPixelFormat;
		Caps2			ddsCaps;
		DWORD			dwReserved2;
	};

	/** DDSファイルマジックナンバー */
	static const DWORD DDS_MAGIC_NUMBER		= 0x20534444;

	/** DDSフラグ */
	static const DWORD FLAG_CAPS			= 0x00000001;
	static const DWORD FLAG_HEIGHT			= 0x00000002;
	static const DWORD FLAG_WIDTH			= 0x00000004;
	static const DWORD FLAG_PITCH			= 0x00000008;
	static const DWORD FLAG_PIXELFORMAT		= 0x00001000;
	static const DWORD FLAG_MIPMAPCOUNT		= 0x00020000;
	static const DWORD FLAG_LINEARSIZE		= 0x00080000;
	static const DWORD FLAG_DEPTH			= 0x00800000;

	/** ピクセルフォーマット */
	static const DWORD FORMAT_LUMINANCE		= 0x00020000;
	static const DWORD FORMAT_RGB			= 0x00000040;
	static const DWORD FORMAT_ALPHAPIXELS	= 0x00000001;
	static const DWORD FORMAT_FOURCC		= 0x00000004;
	static const DWORD FORMAT_DXT1			= 0x31545844;
	static const DWORD FORMAT_DXT3			= 0x33545844;
	static const DWORD FORMAT_DXT5			= 0x35545844;

	/** 補助フラグ */
	static const DWORD CAPS1_ALPHA			= 0x00000002;
	static const DWORD CAPS1_MIPMAP			= 0x00400000;
	static const DWORD CAPS1_COMPLEX		= 0x00000008;
	static const DWORD CAPS1_TEXTURE		= 0x00001000;
	static const DWORD CAPS2_CUBEMAP		= 0x0000fe00;
	static const DWORD CAPS2_VOLUME			= 0x00200000;

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	DDSFile();

	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] fileName ファイル名.
	 */
	DDSFile( const char* fileName );

	
	/*=========================================================================*/
	/**
	 * @brief 画像ファイルからデータを読み込む
	 * 
	 * @param[in] fileName ファイル名.
	 * @return なし.
	 */
	void loadFromFile( const char* fileName );

	
	/*=========================================================================*/
	/**
	 * @brief 入力ストリームからデータを読み込む
	 * 
	 * @param[in] stream 入力ストリーム.
	 * @return なし.
	 */
	void loadFromStream( IInputStream& stream );
	
	
	/*=========================================================================*/
	/**
	 * @brief サーフェース記述子を取得
	 * 
	 * @param[in] なし.
	 * @return サーフェース記述子の参照.
	 */
	const SurfaceDesc& desc();

	
	/*=========================================================================*/
	/**
	 * @brief データサイズを取得
	 * 
	 * @param[in] なし.
	 * @return データサイズ.
	 */
	unsigned int size() const;

	
	/*=========================================================================*/
	/**
	 * @brief テクスチャフィルタを設定する
	 * 
	 * @warning 設定したインスタンスの削除は行いません.
	 *
	 * @param[in] filter 設定するフィルタ.
	 * @return なし.
	 */
	void setFilter( ITextureFilter* filter );
	
	
	/*=========================================================================*/
	/**
	 * purpose [] 演算子オーバーロード: 
	 * 
	 * ピクセルデータを取得する.
	 *
	 * @param[in] index 取得するデータのインデックス番号.
	 * @return ピクセルデータ配列の参照.
	 */
	DDSFile::BYTE& operator [] ( unsigned int index );

private:

	/** サーフェース型 */
	typedef std::vector< BYTE >	Surface;

private:

	/** テクスチャフィルタ */
	ITextureFilter*	filter_;

	/** サーフェース記述子 */
	SurfaceDesc		desc_;

	/** サーフェース */
	Surface			surface_;

};

} // namespace DDS

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/