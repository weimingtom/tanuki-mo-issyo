/*******************************************************************************/
/**
 * @file BMPFile.cpp.
 * 
 * @brief BMP ビットマップフォーマット画像ファイル読み込みクラスソースファイル.
 *
 * @date 2008/07/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/BMP/BMPFile.h"
#include	"Ngl/BMP/DefaultBMPPixel2Bit.h"
#include	"Ngl/BMP/DefaultBMPPixel4Bit.h"
#include	"Ngl/BMP/DefaultBMPPixel8Bit.h"
#include	"Ngl/BMP/DefaultBMPPixel24Bit.h"
#include	"Ngl/BMP/DefaultBMPPixel32Bit.h"
#include	"Ngl/FileInputBinary.h"
#include	"Ngl/MathUtility.h"
#include	"Ngl/ITextureFilter.h"
#include	<memory>
#include	<iostream>

using namespace Ngl;
using namespace Ngl::BMP;

/*==== 関数のプロトタイプ宣言 ===============================================*/

/*=========================================================================*/
/**
 * @brief ビットマップファイルの幅のバイト数を求める
 * 
 * @param[in] width ビットマップ幅.
 * @param[in] bits ビット数.
 * @return ビットマップファイルの幅のバイト数.
 */
unsigned int calcBmpWidthSize( unsigned int width, unsigned int bits );


/*=========================================================================*/
/**
 * @brief ビットマップファイルの幅のパディング値を求めるbr>
 * 
 * @param[in] width ビットマップ幅.
 * @param[in] bits ビット数.
 * @return ビットマップファイルの幅のパディング値.
 */
unsigned int calcWidthPadding( unsigned int width, unsigned int bits );


/*==== 関数定義 =============================================================*/

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
BMPFile::BMPFile():
	filter_( 0 )
{
	// デフォルトのピクセル処理を登録
	setDefaultPixelFunc();
}

	
	
/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] fileName ファイル名.
 */
BMPFile::BMPFile( const char* fileName ):
	filter_( 0 )
{
	// デフォルトのピクセル処理を登録
	setDefaultPixelFunc();

	// ファイルを読み込む
	loadFromFile( fileName );
}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
BMPFile::~BMPFile()
{}



/*=========================================================================*/
/**
 * @brief 画像ファイルからデータを読み込む
 * 
 * @param[in] fileName ファイル名.
 * @return なし.
 */
void BMPFile::loadFromFile( const char* fileName )
{
	FileInputBinary stream;

	// ファイルを開く
	try{
		stream.open( fileName );
	}
	catch( FileOpenException& e ){
		e.add( "BMPFile", "loadFromFile" );
		e.outputConsol();
	}

	// データを読み込む
	loadFromStream( stream );
}



/*=========================================================================*/
/**
* @brief 入力ストリームからデータを読み込む
 * 
 * @param[in] stream 入力ストリーム.
 * @return なし.
 */
void BMPFile::loadFromStream( IInputStream& stream )
{
	// ビットマップファイルヘッダを読み込む
	try{
		readFileHeader( stream );
	}
	catch( Ngl::InputStreamException& e ){
		e.add( "BMPFile", "loadFromStream" );
		e.outputConsol();
		return;
	}

	// ビットマップ情報を読み込む
	try{
		readFileInfo( stream );
	}
	catch( Ngl::InputStreamException& e ){
		e.add( "BMPFile", "loadFromStream" );
		e.outputConsol();
		return;
	}

	// イメージサイズを求める
	bmp_.infoHeader.biSizeImage = calcImageSize();

	// カラーデータを読み込む
	try{
		readRGBQuad( stream );
	}
	catch( Ngl::InputStreamException& e ){
		e.add( "BMPFile", "loadFromStream" );
		e.outputConsol();
		return;
	}

	// イメージデータを読み込む
	try{
		loadImage( stream );
	}
	catch( Ngl::InputStreamException& e ){
		e.add( "BMPFile", "loadFromStream" );
		e.outputConsol();
		return;
	}
}
	
	
	
/*=========================================================================*/
/**
 * @brief ビットマップ情報構造体を取得
 * 
 * @param[in] なし.
 * @return ビットマップ情報構造体.
 */
const BitMapInfoHeader& BMPFile::desc()
{
	return bmp_.infoHeader;
}
	
	
	
/*=========================================================================*/
/**
 * @brief データサイズを取得
 * 
 * @param[in] なし.
 * @return データサイズ.
 */
unsigned int BMPFile::size() const
{
	return static_cast< unsigned int >( pixelArray_.size() );
}



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
void BMPFile::setBMPPixel( IBMPPixel* pixel, BitCount bitCount )
{
	pixelFuncList_[ bitCount ] = PixelFuncPtr( pixel );
}
	
	

/*=========================================================================*/
/**
 * @brief テクスチャフィルタを設定する
 * 
 * @warning 設定したインスタンスの削除は行いません.
 *
 * @param[in] filter 設定するフィルタ.
 * @return なし.
 */
void BMPFile::setFilter( ITextureFilter* filter )
{
	filter_ = filter;
}

	
	
/*=========================================================================*/
/**
 * purpose [] 演算子オーバーロード: 
 * 
 * ピクセルデータを取得する.
 *
 * @param[in] index 取得するデータのインデックス番号.
 * @return ピクセルデータ配列の参照.
 */
unsigned char& BMPFile::operator[] ( unsigned int index )
{
	return pixelArray_[ index ];
}



/*=========================================================================*/
/**
 * @brief デフォルトのピクセル処理クラスを登録
 * 
 * @param[in] なし.
 * @retval なし.
 */
void BMPFile::setDefaultPixelFunc()
{
	// デフォルトの関数を作成
	pixelFuncList_[ BITCOUNT_2 ]	= PixelFuncPtr( new DefaultBMPPixel2Bit() );
	pixelFuncList_[ BITCOUNT_4 ]	= PixelFuncPtr( new DefaultBMPPixel4Bit() );
	pixelFuncList_[ BITCOUNT_8 ]	= PixelFuncPtr( new DefaultBMPPixel8Bit() );
	pixelFuncList_[ BITCOUNT_24 ]	= PixelFuncPtr( new DefaultBMPPixel24Bit() );
	pixelFuncList_[ BITCOUNT_32 ]	= PixelFuncPtr( new DefaultBMPPixel32Bit() );

}
	
	
	
/*=========================================================================*/
/**
 * @brief ビットマップファイルヘッダを読み込む
 * 
 * @param[in] stream 入力ストリーム.
 * @retval なし.
 * @throw std::ios::failure 読み込みエラー.
 */
void BMPFile::readFileHeader( IInputStream& stream )
{
	try{
		stream >> bmp_.fileHeader.bfType;
		stream >> bmp_.fileHeader.bfSize;
		stream >> bmp_.fileHeader.bfReserved1;
		stream >> bmp_.fileHeader.bfReserved2; 
		stream >> bmp_.fileHeader.bfOffBits;
	}
	catch( InputStreamException& e ){
		e.add( "BMPFile", "readFileHeader" );
		throw e;
	}

	// ビットマップファイルではないか
	if( bmp_.fileHeader.bfType != BITMAPFLAG ){
		throw InputStreamException( "Is Not BitmapFile", "BMPFile", "readFileHeader" );
	}
}


	
/*=========================================================================*/
/**
 * @brief ビットマップファイル情報を読み込む
 * 
 * @param[in] stream 入力ストリーム.
 * @retval なし.
 * @throw std::ios::failure 読み込みエラー.
 */
void BMPFile::readFileInfo( IInputStream& stream )
{
	try{
		stream >> bmp_.infoHeader.biSize;		
		stream >> bmp_.infoHeader.biWidth;		
		stream >> bmp_.infoHeader.biHeight;		
		stream >> bmp_.infoHeader.biPlanes;		
		stream >> bmp_.infoHeader.biBitCount;	
		stream >> bmp_.infoHeader.biCompression;
		stream >> bmp_.infoHeader.biSizeImage;	
		stream >> bmp_.infoHeader.biXPelsPerMeter; 
		stream >> bmp_.infoHeader.biYPelsPerMeter;
		stream >> bmp_.infoHeader.biClrUsed;		
		stream >> bmp_.infoHeader.biClrImportant;
	}
	catch( InputStreamException& e ){
		e.add( "BMPFile", "readFileInfo" );
		throw e;
	}

}

	 
	 
/*=========================================================================*/
/**
 * @brief カラーデータを読み込む
 * 
 * @param[in] なし.
 * @retval なし.
 * @throw std::ios::failure 読み込みエラー.
 */
void BMPFile::readRGBQuad( IInputStream& stream )
{
	// カラーデータ数を取得
	unsigned int ncolor = calcColorCount();

	// カラーデータが存在しない
	if ( ncolor == 0 ){
		return;
	}

	try{
		for( unsigned int i=0; i<ncolor; ++i ){
			stream.read( reinterpret_cast< char* >( &bmp_.rgbQuad[ i ] ), sizeof( RGBQuad ) );
		}
	}
	catch( InputStreamException& e ){
		e.add( "BMPFile", "readRGBQuad" );
		throw e;
	}

}

	 
	 
/*=========================================================================*/
/**
 * @brief イメージサイズを求める
 * 
 * @param[in] なし.
 * @retval イメージサイズ.
 */
unsigned int BMPFile::calcImageSize()
{
	// 高さが負の場合は正する
	int height = bmp_.infoHeader.biHeight;
	height = ( height < 0 ) ? -height: height;

	// 幅と高さを掛け合せるとバイト数になる
	return	calcBmpWidthSize( bmp_.infoHeader.biWidth, bmp_.infoHeader.biBitCount ) * height;
}
	 
	 
	 
/*=========================================================================*/
/**
 * @brief カラーデータ数を求める
 * 
 * @param[in] なし.
 * @retval カラーデータ数.
 */
unsigned int BMPFile::calcColorCount()
{
	unsigned int ncolor = 0;	// カラー数
	
	// ビットカウントが8個以下か
	if ( bmp_.infoHeader.biBitCount <= 8 ){
		// カラーテーブルのデータ数が指定されていないか
		if ( bmp_.infoHeader.biClrUsed == 0 ){
			// データ数を求める
			ncolor = 1 << bmp_.infoHeader.biBitCount;
		}
		else{
			// 指定されて数を代入
			ncolor = bmp_.infoHeader.biClrUsed;
		}
	}

	return	ncolor;
}
	 
	 
	 
/*=========================================================================*/
/**
 * @brief イメージデータを読み込む
 * 
 * @param[in] stream 入力ストリーム.
 * @retval なし.
 * @throw std::ios::failure 読み込みエラー.
 */
void BMPFile::loadImage( IInputStream& stream )
{
	try{
		// イメージデータまでシークする
		stream.seek( bmp_.fileHeader.bfOffBits, SEEKFLUG_BEG );

		// 高さの絶対値を求める
		LONG height = Ngl::abs( bmp_.infoHeader.biHeight );
		
		// ピクセルサイズを設定
		pixelArray_.resize( sizeof( DWORD ) * height * bmp_.infoHeader.biWidth );

		// 幅のパディング値を求める
		LONG pad = calcWidthPadding( bmp_.infoHeader.biWidth, bmp_.infoHeader.biBitCount );

		// ピクセルを読み込む関数を設定
		pixelFunc_ = pixelFuncList_[ (BitCount)bmp_.infoHeader.biBitCount ];

		// for each ビットマップの高さ
		for ( LONG y = 0; y < height; y++ ){
			// テクセルを取得
			unsigned char* texel = &pixelArray_[ ( height-1 - y ) * bmp_.infoHeader.biWidth * 4 ];

			// for each ビットマップの幅
			for ( LONG x = 0; x < bmp_.infoHeader.biWidth; x++ ){
				// ピクセルデータを設定する
				(*pixelFunc_)( texel, stream, bmp_, x, y );

				// フィルタ処理をする
				setFilter( texel );

				// 次のテクセルへ移動
				texel += 4;
			}
			// パディング分をスキップする
			stream.seek( pad, SEEKFLUG_CUR );
		}
	}
	catch( InputStreamException& e ){
		e.add( "BMPFile", "loadImage" );
		throw e;
	}

}
	
	
	
/*=========================================================================*/
/**
 * @brief テクスチャのフィルタ処理をする
 * 
 * @param[in] texel テクセルデータ.
 * @retval なし.
 */
void BMPFile::setFilter( BYTE* texel )
{
	if( filter_ == 0 ){
		return;
	}

	// テクセル処理をする
	(*filter_)( texel );
}

	
	
/*=========================================================================*/
/**
 * @brief ビットマップファイルの幅のバイト数を求める
 * 
 * @param[in] width ビットマップ幅.
 * @param[in] bits ビット数.
 * @return ビットマップファイルの幅のバイト数.
 */
unsigned int calcBmpWidthSize( unsigned int width, unsigned int bits )
{
	return ( (width)*(bits) + ( ( 32 - (width)*(bits) ) & 0x01f ) ) >> 3;
}



/*=========================================================================*/
/**
 * @brief ビットマップファイルの幅のパディング値を求めるbr>
 * 
 * @param[in] width ビットマップ幅.
 * @param[in] bits ビット数.
 * @return ビットマップファイルの幅のパディング値.
 */
unsigned int calcWidthPadding( unsigned int width, unsigned int bits )
{
	return ( 32 - ( width * bits ) & 0x01f ) >> 3;
}



/*===== EOF ==================================================================*/