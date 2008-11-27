/*******************************************************************************/
/**
 * @file FileInputC.cpp.
 * 
 * @brief Cスタイルファイル入力クラスソースファイル.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/FileInputC.h"
#include	"Ngl/Vector2.h"
#include	"Ngl/Vector3.h"
#include	"Ngl/Color4.h"
#include	"Ngl/Matrix4.h"
#include	"Ngl/Quaternion.h"
#include	"Ngl/Sphere.h"
#include	<sstream>
#include	<algorithm>
#include	<cstring>
#include	<cassert>

using namespace Ngl;

/*==== 定数宣言 =============================================================*/

const int FileInputC::MAX_BUFFER_SIZE	= 1024;	// 読み込みバッファサイズ

/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
FileInputC::FileInputC():
	isFileLoaded_( false ),				// 読み込み中か
	file_( 0 ),							// ファイル構造体
	delimiter_( " \n\r\t," ),			// デリミタ文字
	readType_( STREAM_READ_TYPE_10 )	// ファイル読み込みタイプ
{}



/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] fileName 開くファイル名.
 * @param[in] flag 読み取りフラグ.
 */
FileInputC::FileInputC(std::string fileName ):
	fileName_( fileName ),				// ファイル名
	isFileLoaded_( false ),				// 読み込み中か
	file_( 0 ),							// ファイル構造体
	delimiter_( " \n\r\t," ),			// デリミタ文字
	readType_( STREAM_READ_TYPE_10 )	// ファイル読み込みタイプ
{
	open( fileName_  );
}



/*===========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
FileInputC::~FileInputC()
{
	if( isFileLoaded_ == true ){
		// ファイルを閉じる
		close();
	}
}



/*===========================================================================*/
/**
 * @brief ファイルを開く
 * 
 * @param[in] fileName 開くファイル名.
 * @return なし.
 * @throw Ngl::FileOpenException
 */
void FileInputC::open(std::string fileName)
{
	// ファイル名を設定する
	fileName_ = fileName;

	// ファイルを開く
	fopen_s( &file_, fileName_.c_str(), "r" );
	
	// 開けていないか
	if( file_ == 0 ){
		// 例外を投げる
		std::string info = "File Open Error" + fileName;
		throw FILE_OPEN_EXCEPTION( info );
	}

	// ファイル読み込み状態にする
	isFileLoaded_ = true;
}



/*===========================================================================*/
/**
 * @brief ファイルを閉じる
 * 
 * @param[in] なし.
 * @return なし.
 */
void FileInputC::close()
{
	//オブジェクトが作成されているか
	if( file_ != 0 ){
		fclose( file_ );
	}

	// 読み込みフラグを無効にする
	isFileLoaded_ = false;
}



/*===========================================================================*/
/**
 * @brief ファイルがOpenできなかったか
 * 
 * @param[in] なし.
 * @retval true 開けなかった.
 * @retval false 開けた.
 */
bool FileInputC::isOpenFailed()
{
	return isFileLoaded_;
}	



/*===========================================================================*/
/**
 * @brief ファイルのアクセスエラーが起きたか調べる
 * 
 * @param[in] なし.
 * @retval true アクセスエラー.
 * @retval false アクセス成功.
 */
bool FileInputC::isError() const
{
	if( ferror( file_ ) != 0 ){
		return true;
	}
	return false;
}



/*===========================================================================*/
/**
 * @brief ファイルがＥＯＦまで達したか調べる
 * 
 * @param[in] なし.
 * @retval true EOF.
 * @retval false ファイルの途中.
 */
bool FileInputC::isEOF() const
{
	if( feof( file_ ) != 0 ){
		return true;
	}
	return false;
}



/*===========================================================================*/
/**
 * @brief 読み飛ばす文字を設定する
 * 
 * @param[in] skipChara 読み飛ばす文字.
 * @return なし.
 */
void FileInputC::setSkipCharacter(std::string skipChara)
{
	delimiter_ += skipChara;
}



/*===========================================================================*/
/**
 * @brief 行末まで読み飛ばす
 * 
 * @param[in] なし.
 * @retval true 読み飛ばし完了.
 * @retval false 読み飛ばし未完了.
 */
bool FileInputC::skipToLineEnd()
{
	// EOFかどうか
	while ( feof( file_ ) == 0 ){
		// エラー状態であるか？
		if( ferror( file_ ) != 0 ){
			return	false;
		}
		// 改行コードが入力されるまでスキップする
		if( fgetc( file_ ) == '\n' ){
			return	true;
		}
	}
	return	false;
}



/*=========================================================================*/
/**
 * @brief データを読み込む ( char型データを読み込む )
 * 
 * @param[out] data データを設定する変数.
 * @return 読み込んだデータ.
 * @throw Ngl::FileReadException ファイル読み込み例外.
 */
void FileInputC::read( char& data )
{
	try{
		 readTextFile( "%c", &data );
	}
	catch( Ngl::FileReadException& e ){
		e += "[FileInputC] : [operator>>char]";
		throw e;
	}
}


/*=========================================================================*/
/**
 * @brief データを読み込む ( string型データを読み込む )
 * 
 * @param[out] data データを設定する変数.
 * @return 読み込んだデータ.
 * @throw Ngl::FileReadException ファイル読み込み例外.
 */
void FileInputC::read( std::string& data )
{
	 static std::string readData;	// 読み取るstring型
	 static bool findFlag = false;	// 読み飛ばすか

	 char s[ MAX_BUFFER_SIZE ];

	 try{
		readTextFile( "%s", s );
	 }
	 catch( Ngl::FileReadException& e ){
		e += "[FileInputC] : [operator>>string]";
		throw e;
	 }

	 data = s;
}



/*=========================================================================*/
/**
 * @brief データを読み込む ( short型データを読み込む )
 * 
 * @param[out] data データを設定する変数.
 * @return 読み込んだデータ.
 * @throw Ngl::FileReadException ファイル読み込み例外.
 */
void FileInputC::read( short& data )
{
	try{
		switch( readType_ ){
		// 8進数読み込み
		case STREAM_READ_TYPE_8:
			readTextFile( "%o", &data );
			break;
		// 10進数で読み込み
		case STREAM_READ_TYPE_10:
			readTextFile( "%hd", &data );
			break;
		default:
			assert( false );
		}
	 }
	 catch( Ngl::FileReadException& e ){
		e += "[FileInputC] : [operator>>short]";
		throw e;
	 }

	// 10進数読み込みに初期化
	readType_ = STREAM_READ_TYPE_10;
}

	 
	 
/*=========================================================================*/
/**
 * @brief データを読み込む ( unsigned short型データを読み込む )
 * 
 * @param[out] data データを設定する変数.
 * @return 読み込んだデータ.
 * @throw Ngl::FileReadException ファイル読み込み例外.
 */
void FileInputC::read( unsigned short& data )
{
	try{
		readTextFile( "%hu", &data );
	}
	catch( Ngl::FileReadException& e ){
		e += "[FileInputC] : [operator>>unsigned short]";
		throw e;
	}

	// 10進数読み込みに初期化
	readType_ = STREAM_READ_TYPE_10;
}

 
 
/*=========================================================================*/
/**
 * @brief データを読み込む ( int型データを読み込む )
 * 
 * @param[out] data データを設定する変数.
 * @return 読み込んだデータ.
 * @throw Ngl::FileReadException ファイル読み込み例外.
 */
void FileInputC::read( int& data )
{
	try{
		switch( readType_ ){
		// 8進数読み込み
		case STREAM_READ_TYPE_8:
			readTextFile( "%o", &data );
			break;
		// 10進数読み込み
		case STREAM_READ_TYPE_10:
			readTextFile( "%d", &data );
			break;
		// 16進数で読み込み
		case STREAM_READ_TYPE_16:
			readTextFile( "%x", &data );
			break;
		default:
			assert( false );
		}
	}
	catch( Ngl::FileReadException& e ){
		e += "[FileInputC] : [operator>>int]";
		throw e;
	}

	// 10進数読み込みに初期化
	readType_ = STREAM_READ_TYPE_10;
}

	 
	 
/*=========================================================================*/
/**
 * @brief データを読み込む ( unsigned int型データを読み込む )
 * 
 * @param[out] data データを設定する変数.
 * @return 読み込んだデータ.
 * @throw Ngl::FileReadException ファイル読み込み例外.
 */
void FileInputC::read( unsigned int& data )
{
	try{
		switch( readType_ ){
		// 8進数読み込み
		case STREAM_READ_TYPE_8:
			readTextFile( "%o", &data );
			break;
		// 10進数読み込み
		case STREAM_READ_TYPE_10:
			readTextFile( "%u", &data );
			break;
		// 16進数で読み込み
		case STREAM_READ_TYPE_16:
			readTextFile( "%x", &data );
			break;
		default:
			assert( false );
		}
	}
	catch( Ngl::FileReadException& e ){
		e += "[FileInputC] : [operator>>unsigned int]";
		throw e;
	}

	// 10進数読み込みに初期化
	readType_ = STREAM_READ_TYPE_10;
}

 
 
/*=========================================================================*/
/**
 * @brief データを読み込む ( long型データを読み込む )
 * 
 * @param[out] data データを設定する変数.
 * @return 読み込んだデータ.
 * @throw Ngl::FileReadException ファイル読み込み例外.
 */
void FileInputC::read( long& data )
{
	try{
		switch( readType_ ){
		// 8進数読み込み
		case STREAM_READ_TYPE_8:
			readTextFile( "%lo", &data );
			break;
		// 10進数読み込み
		case STREAM_READ_TYPE_10:
			readTextFile( "%ld", &data );
			break;
		// 16進数で読み込み
		case STREAM_READ_TYPE_16:
			readTextFile( "%lx", &data );
			break;
		default:
			assert( false );
		}
	}
	catch( Ngl::FileReadException& e ){
		e += "[FileInputC] : [operator>>long]";
		throw e;
	}

	// 10進数読み込みに初期化
	readType_ = STREAM_READ_TYPE_10;
}

 
 
/*=========================================================================*/
/**
 * @brief データを読み込む ( unsigned long型データを読み込む )
 * 
 * @param[out] data データを設定する変数.
 * @return 読み込んだデータ.
 * @throw Ngl::FileReadException ファイル読み込み例外.
 */
void FileInputC::read( unsigned long& data )
{
	try{
		 switch( readType_ ){
		// 8進数読み込み
		case STREAM_READ_TYPE_8:
			readTextFile( "%lo", &data );
			break;
		// 10進数読み込み
		case STREAM_READ_TYPE_10:
			readTextFile( "%lu", &data );
			break;
		// 16進数で読み込み
		case STREAM_READ_TYPE_16:
			readTextFile( "%lx", &data );
			break;
		default:
			assert( false );
		}
	}
	catch( Ngl::FileReadException& e ){
		e += "[FileInputC] : [operator>>unsigned long]";
		throw e;
	}

	// 10進数読み込みに初期化
	readType_ = STREAM_READ_TYPE_10;
}

 
 
/*=========================================================================*/
/**
 * @brief データを読み込む ( float型データを読み込む )
 * 
 * @param[out] data データを設定する変数.
 * @return 読み込んだデータ.
 * @throw Ngl::FileReadException ファイル読み込み例外.
 */
void FileInputC::read( float& data )
{
	try{
		readTextFile( "%f", &data );
	}
	catch( Ngl::FileReadException& e ){
		e += "[FileInputC] : [operator>>float]";
		throw e;
	}
}

 
 
/*=========================================================================*/
/**
 * @brief データを読み込む ( double型データを読み込む )
 * 
 * @param[out] data データを設定する変数.
 * @return 読み込んだデータ.
 * @throw Ngl::FileReadException ファイル読み込み例外.
 */
void FileInputC::read( double& data )
{
	try{
		readTextFile( "%lf", &data );
	}
	catch( Ngl::FileReadException& e ){
		e += "[FileInputC] : [operator>>double]";
		throw e;
	}
}

	
	

/*=========================================================================*/
/**
 * @brief 指定バイト数分読み込む
 * 
 * @param[in] dest 読み込んだデータを格納するデータ.
 * @param[in] size 読み込むサイズ.
 * @return なし.
 */
void FileInputC::read( char* dest, unsigned int size )
{
	fread( dest, size, 1, file_ );
}



/*=========================================================================*/
/**
 * @brief 指定位置にシークする
 * 
 * @param[in] offset 移動する位置.
 * @param[in] flag シークフラグ.
 * @return なし.
 */
void FileInputC::seek( unsigned int offset, SeekFlug flag )
{
	int cflag = SEEK_SET;
	switch( flag )
	{
	case SEEKFLUG_BEG:
		cflag = SEEK_SET;
		break;
	case SEEKFLUG_CUR:
		cflag = SEEK_CUR;
		break;
	case SEEKFLUG_END:
		cflag = SEEK_END;
		break;
	}

	fseek( file_, offset, cflag );
}

	
	
/*=========================================================================*/
/**
 * @brief 現在位置を取得する
 * 
 * @param[in] なし.
 * @return 現在位置のバイト数.
 */
unsigned int FileInputC::tell()
{
	unsigned int size = ftell( file_ );

	// エラーがあるか
	if( isError() == true ){
		throw FILE_READ_EXCEPTION( "tell Error" );
	}

	return size;
}
	
	
	
/*=========================================================================*/
/**
 * @brief ストリーム名を取得する
 * 
 * @param[in] なし.
 * @return ストリーム名.
 */
const std::string& FileInputC::streamName() const
{
	 return fileName_;
}
	 


/*=========================================================================*/
/**
 * @brief ストリーム読み込みタイプを取得する
 * 
 * @param[out] なし.
 * @return ストリームタイプ.
 */
StreamReadType FileInputC::readType()
{
	return readType_;
}
	
	
	
/*=========================================================================*/
/**
 * @brief >> 演算子オーバーロード ( マニピュレータ用 )
 * 
 * @param[out] func マニピュレータの関数ポインタ.
 * @return 入力ストリームの参照.
 */
IInputStream& FileInputC::operator >> ( IInputStream& (*func)(IInputStream&) )
{
	return (*func)(*this);
}

	
	
/*=========================================================================*/
/**
 * @brief ストリーム読み込みタイプを設定する
 * 
 * @param[out] type 設定する読み込みタイプ.
 * @return なし.
 */
void FileInputC::readType( StreamReadType type )
{
	readType_ = type;
}



/*===========================================================================*/
/**
 * @brief テキストファイルからデータを読み取る
 * 
 * @param[in] format 読み取り形式.
 * @param[in] input 読み込んだデータを保存するデータ.
 * @retval true 読み取り成功.
 * @retval false 読み取り失敗.
 * @throw Ngl::FileReadException ファイル読み込み例外.
 */
void FileInputC::readTextFile(const char *format, void *input)
{
	char buffer[ MAX_BUFFER_SIZE ];

	// 文字列を読み込む
	if( readBuffer( buffer ) == false ){
		std::string info;
		info = "File Read Error!!" + fileName_;
		throw FileReadException( info, "FileInputC", "readTextFile" );
	}

	// 指定のフォーマットに変換する
	if( sscanf( buffer, format, input ) == 0 ){
		std::stringstream info;
		std::string fm = format;
		info << "Format Convert Error!!" << fm << fileName_;
		throw FileReadException( info.str(), "FileInputC", "readTextFile" );
	}
}



/*===========================================================================*/
/**
 * @brief バッファを読み取る
 * 
 * @param[in] buf 読み込んだバッファを保存するデータ.
 * @retval true 読み取り成功.
 * @retval false 読み取り失敗.
 */
bool FileInputC::readBuffer(char *buf)
{
	// エラー状態か
	if( isError() == true ){
		return false;
	}

	// EOFか
	if( isEOF() == true ){
		return false;
	}

	char	c;	// 読み取り文字

	// デリミタ文字をスキップ
	if( readSkipDelimiter( &c ) == false ){
		return false;
	}

	*buf++ = c;

	// デリミタまで読み取る
	int		ic		= 0;	// 読み取った文字
	bool	success = true;	// 読み取りフラグ
	while( true ){
		// 1文字読み込む
		ic = fgetc( file_ );
		
		// EOFか
		if( isEOF() == true ){
			success = true;
			break;
		}

		// エラーか
		if( isError() == true ){
			success = false;
			break;
		}

		// デリミタ文字か
		if( isDelimiter( ic ) == true ){
			success = true;
			break;
		}

		*buf++ = (char)ic;
	}
	*buf = '\0';

	// 結果を返す
	return success;
}



/*===========================================================================*/
/**
 * @brief デリミタ文字とコメント文字をスキップして1文字読み取る
 * 
 * @param[in] buf 読み込んだ文字を保存するデータ.
 * @retval true 読み取り成功.
 * @retval false 読み取り失敗.
 */
bool FileInputC::readSkipDelimiter(char *buf)
{
	int	c = 0;				// 読み取った文字
	bool success = true;	// 読み取りフラグ

	// デリミタ文字をスキップ
	do{
		// 1文字読み取る
		c = fgetc( file_ );
		
		// EOFか
		if( isEOF() == true ){
			success = true;
			break;
		}

		// エラーかどうか
		if( isError() == true ){
			success = false;
			break;
		}

		// コメントがあるか
		if( c == '#' ){
			// コメント行は行末までスキップ
			skipToLineEnd();

			c = '\n';
		}
	}while( isDelimiter( c ) == true );

	// EOFまたはエラーか
	if( isEOF() == true || isError() == true ){
		return false;
	}

	*buf = (char)c;

	return true;
}



/*========= EOF =============================================================*/