/*******************************************************************************/
/**
 * @file BMPFile.h.
 * 
 * @brief BMP ビットマップフォーマット画像ファイル読み込みクラスヘッダファイル.
 *
 * @date 2008/07/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_BMP_BMPFILE_H_
#define _NGL_BMP_BMPFILE_H_

#include	"BitMap.h"
#include	"IBMPPixel.h"
#include	"Ngl/SmartPtr.h"
#include	<fstream>
#include	<vector>
#include	<map>
#include	<memory>


namespace Ngl{


// テクスチャフィルタ
class ITextureFilter;

namespace BMP{


/**
 * @class BMPFile．
 * @brief BMP ビットマップフォーマット画像ファイル読み込みクラス.
 */
class BMPFile
{
public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	BMPFile();
	
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] fileName ファイル名.
	 */
	BMPFile( const char* fileName );


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~BMPFile();


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
	 * @brief ビットマップ情報構造体を取得
	 * 
	 * @param[in] なし.
	 * @return ビットマップ情報構造体.
	 */
	const BitMapInfoHeader& desc();
	
	
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
	 * @brief ピクセルクラスを設定する
	 * 
	 * bitCount数のビットマップのピクセルデータ処理クラスを設定します。
	 *
	 * @param[in] pixel 設定するピクセルクラス.
	 * @param[in] bitCount 関数を設定するビットマップ.
	 * @return なし.
	 */
	void setBMPPixel( IBMPPixel* pixel, BitCount bitCount );
	
	
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
	unsigned char& operator[] ( unsigned int index );

private:

	/*=========================================================================*/
	/**
	 * @brief デフォルトのピクセル処理クラスを登録
	 * 
	 * @param[in] なし.
	 * @retval なし.
	 */
	void setDefaultPixelFunc();

	
	/*=========================================================================*/
	/**
	 * @brief ビットマップファイルヘッダを読み込む
	 * 
	 * @param[in] stream 入力ストリーム.
	 * @retval なし.
	 * @throw std::ios::failure 読み込みエラー.
	 */
	void readFileHeader( IInputStream& stream );


	/*=========================================================================*/
	/**
	 * @brief ビットマップファイル情報を読み込む
	 * 
	 * @param[in] stream 入力ストリーム.
	 * @retval なし.
	 * @throw std::ios::failure 読み込みエラー.
	 */
	void readFileInfo( IInputStream& stream );


	/*=========================================================================*/
	/**
	 * @brief カラーデータを読み込む
	 * 
	 * @param[in] stream 入力ストリーム.
	 * @retval なし.
	 * @throw std::ios::failure 読み込みエラー.
	 */
	void readRGBQuad( IInputStream& stream );


	/*=========================================================================*/
	/**
	 * @brief イメージサイズを求める
	 * 
	 * @param[in] なし.
	 * @retval イメージサイズ.
	 */
	unsigned int calcImageSize();


	/*=========================================================================*/
	/**
	 * @brief カラーデータ数を求める
	 * 
	 * @param[in] なし.
	 * @retval カラーデータ数.
	 */
	unsigned int calcColorCount();


	/*=========================================================================*/
	/**
	 * @brief イメージデータを読み込む
	 * 
	 * @param[in] stream 入力ストリーム.
	 * @retval なし.
	 * @throw std::ios::failure 読み込みエラー.
	 */
	void loadImage( IInputStream& stream );


	/*=========================================================================*/
	/**
	 * @brief テクスチャのフィルタ処理をする
	 * 
	 * @param[in] texel テクセルデータ.
	 * @retval なし.
	 */
	void setFilter( BYTE* texel );

private:

	/** ピクセルデータ配列型 */
	typedef std::vector< unsigned char >		PixelArray;

	/** 読み込み関数ポインタ型 */
	typedef SmartPtr< IBMPPixel >				PixelFuncPtr;

	/** 読み込み関数リスト */
	typedef std::map< BitCount, PixelFuncPtr >	PixelFuncList;

private:

	/** テクスチャフィルタ */
	ITextureFilter*	filter_;

	/** ピクセルデータ配列 */
	PixelArray		pixelArray_;

	/** BMP構造体 */
	BitMap			bmp_;

	/** 読み込み関数リスト */
	PixelFuncList	pixelFuncList_;

	/** 現在のピクセル関数 */
	PixelFuncPtr	pixelFunc_;

};

} // namespace BMP

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/