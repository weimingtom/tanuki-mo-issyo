/*******************************************************************************/
/**
 * @file DDSFile.cpp.
 * 
 * @brief DDSフォーマット画像ファイル読み込みクラスソースファイル.
 *
 * @date 2008/06/28.
 * 
 * @version 1.10.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/DDS/DDSFile.h"
#include	"Ngl/FileInputBinary.h"
#include	"Ngl/ITextureFilter.h"
#include	<memory>

using namespace Ngl;
using namespace Ngl::DDS;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
DDSFile::DDSFile():
	filter_( 0 )
{}

	
	
/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] fileName ファイル名.
 */
DDSFile::DDSFile( const char* fileName ):
	filter_( 0 )
{
	loadFromFile( fileName );
}



/*=========================================================================*/
/**
 * @brief 画像ファイルからデータを読み込む
 * 
 * @param[in] fileName ファイル名.
 * @return なし.
 */
void DDSFile::loadFromFile( const char* fileName )
{
	FileInputBinary ifStream;
	try{
		ifStream.open( fileName );
	}
	catch( FileOpenException& e ){
		e.add( "DDSFile", "loadFromFile" );
	}

	loadFromStream( ifStream );
}



/*=========================================================================*/
/**
 * @brief 入力ストリームからデータを読み込む
 * 
 * @param[in] stream 入力ストリーム.
 * @return なし.
 */
void DDSFile::loadFromStream( IInputStream& stream )
{	
	try{
		// ファイルサイズを求める
		stream.seek( 0, SEEKFLUG_END );
		DWORD fileSize = stream.tell();
		stream.seek( 0, SEEKFLUG_BEG );

		// マジックナンバーの読み込み
		DWORD magicNumber = 0;
		stream.read( reinterpret_cast< char* >( &magicNumber ), sizeof( DWORD ) );
		if( magicNumber != DDS_MAGIC_NUMBER ){
			throw FileReadException( "Is Not DDSFile", "DDSFile", "loadFromStream" );
		}

		// 記述子の読み込み
		stream.read( reinterpret_cast< char* >( &desc_ ), sizeof( SurfaceDesc ) );

		// サーフェースデータの読み込み
		surface_.resize( fileSize - sizeof( DWORD ) - sizeof( SurfaceDesc ) );
		stream.read( reinterpret_cast< char* >( &surface_[0] ), (std::streamsize)surface_.size() );

		// フィルタ処理をかける
		if( filter_ != 0 ){
			for( unsigned int i=0; i<surface_.size(); i+=4 ){
				(*filter_)( static_cast< unsigned char* >( &surface_[ i ] ) );
			}
		}
	}
	catch( InputStreamException& e ){
		e.add( "DDSFile", "loadFromStream" );
		e.outputConsol();
	}
}



/*=========================================================================*/
/**
 * @brief サーフェース記述子を取得
 * 
 * @param[in] なし.
 * @return サーフェース記述子の参照.
 */
const DDSFile::SurfaceDesc& DDSFile::desc()
{
	return desc_;
}



/*=========================================================================*/
/**
 * @brief データサイズを取得
 * 
 * @param[in] なし.
 * @return データサイズ.
 */
unsigned int DDSFile::size() const
{
	return ( unsigned int )surface_.size();
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
void DDSFile::setFilter( ITextureFilter* filter )
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
DDSFile::BYTE& DDSFile::operator[] ( unsigned int index )
{
	return surface_[ index ];
}



/*===== EOF ==================================================================*/