/*******************************************************************************/
/**
 * @file FileInputBinary.cpp.
 * 
 * @brief バイナリファイル入力クラスソースファイル.
 *
 * @date 2008/07/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/FileInputBinary.h"

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
FileInputBinary::FileInputBinary()
{}


/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] fileName 開くファイル名.
 */
FileInputBinary::FileInputBinary( const std::string& fileName )
{
	open( fileName );
}



/*=========================================================================*/
/**
 * @brief ファイルを開く
 * 
 * @param[in] fileName 開くファイル名.
 * @return なし.
 * @throw Ngl::FileOpenEception ファイルオープン例外.
 */
void FileInputBinary::open( const std::string& fileName )
{
	// ファイル名を保存
	fileName_ = fileName;

	// 例外を有効にする
	ifStream_.exceptions( std::ifstream::eofbit | std::ifstream::failbit | std::ifstream::badbit );
	
	try{
		ifStream_.open( fileName.c_str(), std::ios::in | std::ios::binary );
	}
	catch( std::ios::failure& e ){
		throw Ngl::FileOpenException( e.what() );
	}
}



/*=========================================================================*/
/**
 * @brief ファイルを閉じる
 * 
 * @param[in] なし.
 * @return なし.
 */
void FileInputBinary::close()
{
	ifStream_.close();
}



/*=========================================================================*/
/**
 * @brief データを読み込む ( char型データを読み込む )
 * 
 * @param[out] data データを設定する変数.
 * @return 読み込んだデータ.
 * @throw Ngl::FileReadException ファイル読み込み例外.
 */
void FileInputBinary::read( char& data )
{
	ifStream_.read( reinterpret_cast< char* >( &data ), sizeof( char ) );
}



/*=========================================================================*/
/**
 * @brief データを読み込む ( string型データを読み込む )
 * 
 * @param[out] data データを設定する変数.
 * @return 読み込んだデータ.
 * @throw Ngl::FileReadException ファイル読み込み例外.
 */
void FileInputBinary::read( std::string& data )
{
}



/*=========================================================================*/
/**
 * @brief データを読み込む ( short型データを読み込む )
 * 
 * @param[out] data データを設定する変数.
 * @return 読み込んだデータ.
 * @throw Ngl::FileReadException ファイル読み込み例外.
 */
void FileInputBinary::read( short& data )
{
	ifStream_.read( reinterpret_cast< char* >( &data ), sizeof( short ) );
}

	 
	 
/*=========================================================================*/
/**
 * @brief データを読み込む ( unsigned short型データを読み込む )
 * 
 * @param[out] data データを設定する変数.
 * @return 読み込んだデータ.
 * @throw Ngl::FileReadException ファイル読み込み例外.
 */
void FileInputBinary::read( unsigned short& data )
{
	ifStream_.read( reinterpret_cast< char* >( &data ), sizeof( unsigned short ) );
}


 
/*=========================================================================*/
/**
 * @brief データを読み込む ( int型データを読み込む )
 * 
 * @param[out] data データを設定する変数.
 * @return 読み込んだデータ.
 * @throw Ngl::FileReadException ファイル読み込み例外.
 */
void FileInputBinary::read( int& data )
{
	ifStream_.read( reinterpret_cast< char* >( &data ), sizeof( data ) );
}


	 
/*=========================================================================*/
/**
 * @brief データを読み込む ( unsigned int型データを読み込む )
 * 
 * @param[out] data データを設定する変数.
 * @return 読み込んだデータ.
 * @throw Ngl::FileReadException ファイル読み込み例外.
 */
void FileInputBinary::read( unsigned int& data )
{
	ifStream_.read( reinterpret_cast< char* >( &data ), sizeof( unsigned int ) );
}


 
/*=========================================================================*/
/**
 * @brief データを読み込む ( long型データを読み込む )
 * 
 * @param[out] data データを設定する変数.
 * @return 読み込んだデータ.
 * @throw Ngl::FileReadException ファイル読み込み例外.
 */
void FileInputBinary::read( long& data )
{
	ifStream_.read( reinterpret_cast< char* >( &data ), sizeof( long ) );
}


 
/*=========================================================================*/
/**
 * @brief データを読み込む ( unsigned long型データを読み込む )
 * 
 * @param[out] data データを設定する変数.
 * @return 読み込んだデータ.
 * @throw Ngl::FileReadException ファイル読み込み例外.
 */
void FileInputBinary::read( unsigned long& data )
{
	ifStream_.read( reinterpret_cast< char* >( &data ), sizeof( unsigned long ) );
}


 
/*=========================================================================*/
/**
 * @brief データを読み込む ( float型データを読み込む )
 * 
 * @param[out] data データを設定する変数.
 * @return 読み込んだデータ.
 * @throw Ngl::FileReadException ファイル読み込み例外.
 */
void FileInputBinary::read( float& data )
{
	ifStream_.read( reinterpret_cast< char* >( &data ), sizeof( float ) );
}

 
/*=========================================================================*/
/**
 * @brief データを読み込む ( double型データを読み込む )
 * 
 * @param[out] data データを設定する変数.
 * @return 読み込んだデータ.
 * @throw Ngl::FileReadException ファイル読み込み例外.
 */
void FileInputBinary::read( double& data )
{
	ifStream_.read( reinterpret_cast< char* >( &data ), sizeof( double ) );
}


/*=========================================================================*/
/**
 * @brief >> 演算子オーバーロード ( マニピュレータ用 )
 * 
 * @param[out] func マニピュレータの関数ポインタ.
 * @return 入力ストリームの参照.
 */
IInputStream& FileInputBinary::operator >> ( IInputStream& (*func)(IInputStream&) )
{
	return (*func)(*this);
}



/*=========================================================================*/
/**
 * @brief 指定バイト数分読み込む
 * 
 * @param[in] dest 読み込んだデータを格納するデータ.
 * @param[in] size 読み込むサイズ.
 * @return なし.
 */
void FileInputBinary::read( char* dest, unsigned int size )
{
	ifStream_.read( dest, size );
}



/*=========================================================================*/
/**
 * @brief 指定位置にシークする
 * 
 * @param[in] offset 移動する位置.
 * @param[in] flag シークフラグ.
 * @return なし.
 */
void FileInputBinary::seek( unsigned int offset, SeekFlug flag )
{
	std::ios_base::seek_dir way = std::ios::beg;
	switch( flag )
	{
	case SEEKFLUG_BEG:
		way = std::ios::beg;
		break;
	case SEEKFLUG_CUR:
		way = std::ios::cur;
		break;
	case SEEKFLUG_END:
		way = std::ios::end;
		break;
	}
	ifStream_.seekg( offset, way );
}



/*=========================================================================*/
/**
 * @brief 現在位置を取得する
 * 
 * @param[in] なし.
 * @return 現在位置のバイト数.
 */
unsigned int FileInputBinary::tell()
{
	return ifStream_.tellg();
}



/*=========================================================================*/
/**
 * @brief ストリーム読み込みタイプを設定する
 * 
 * @param[out] type 設定する読み込みタイプ.
 * @return なし.
 */
void FileInputBinary::readType( StreamReadType type )
{
	readType_ = type;
}



/*=========================================================================*/
/**
 * @brief ストリーム読み込みタイプを取得する
 * 
 * @param[out] なし.
 * @return ストリームタイプ.
 */
StreamReadType FileInputBinary::readType()
{
	return readType_;
}



/*=========================================================================*/
/**
 * @brief ストリーム名を取得する
 * 
 * @param[in] なし.
 * @return ストリーム名.
 */
const std::string& FileInputBinary::streamName() const
{
	return fileName_;
}



/*===== EOF ==================================================================*/