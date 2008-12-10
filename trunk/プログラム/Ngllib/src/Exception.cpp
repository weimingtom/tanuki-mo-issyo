/*******************************************************************************/
/**
 * @file Exception.cpp.
 * 
 * @brief 例外クラスソースファイル.
 *
 * @date 2008/07/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Exception.h"
#include	"Ngl/Utility.h"
#include	<iostream>
#include	<sstream>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] mes 例外情報文字列.
 */
Exception::Exception( const std::string& mes ):
	mes_( mes )
{}



/*=========================================================================*/
/**
 * @brief コンストラクタ
 *
 * "mes\n[file] : [line]"の形の文字列情報として情報を設定します。
 * ファイル名にパスが含まれていた場合は、ファイル名のみを出力します。
 * 
 * @param[in] mes 例外情報文字列.
 * @param[in] file 例外の発生したファイル名.
 * @param[in] line 例外の発生した行数.
 */
Exception::Exception( const std::string& mes, std::string file, int line )
{
	
	std::string fname = file;

	// フルパスのファイル名からファイル名を切り出す
	fname = Utility::getFileName( file.c_str() );
	fname += ".";
	fname += Utility::getFileExtension( file.c_str() );

	// 文字列を作成
	std::stringstream ss;
	ss << mes << "\n[" << fname << "] : [" << line << "]";
	mes_ = ss.str();
}



/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * "mes\n[className] : [methodName]"の形の文字列情報として情報を設定します。
 *
 * @param[in] mes 例外情報文字列.
 * @param[in] className 例外の発生したクラス名.
 * @param[in] methodName 例外の発生した関数名.
 */
Exception::Exception( const std::string& mes, const std::string& className, const std::string& methodName )
{
	std::stringstream ss;
	ss << mes << "\n[" << className << "] : [" << methodName << "]";
	mes_ = ss.str();
}

	
	
/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
Exception::~Exception()
{}



/*=========================================================================*/
/**
 * @brief 例外情報文字を取得する
 * 
 * @param[in] なし.
 * @return 例外情報文字列.
 */
const char* Exception::what()
{
	return mes_.c_str();
}



/*=========================================================================*/
/**
 * @brief 例外情報文字を取得する( stringクラス )
 * 
 * @param[in] なし.
 * @return 例外情報文字列.
 */
const std::string& Exception::str()
{
	return mes_;
}
	
	
	
/*=========================================================================*/
/**
 * @brief 例外情報を追加する
 * 
 * @param[in] mes 追加する情報.
 * @return なし.
 */
void Exception::add( const std::string& mes )
{
	mes_ = mes_ + "\n" + mes; 
}



/*=========================================================================*/
/**
 * @brief 例外情報を追加する
 *
 * "\n[file] : [line]"の形の文字列情報として情報を追加します。
 * ファイル名にパスが含まれていた場合は、ファイル名のみを出力します。
 * 
 * @param[in] file 例外の発生したファイル名.
 * @param[in] line 例外の発生した行数.
 */
void Exception::add( std::string file, int line )
{
	std::string fname = file;

	// フルパスのファイル名からファイル名を切り出す
	fname = Utility::getFileName( file.c_str() );
	fname += ".";
	fname += Utility::getFileExtension( file.c_str() );

	std::stringstream ss;
	ss << "\n" << "[" << fname << "] : [" << line << "]";
	mes_ += ss.str();
}



/*=========================================================================*/
/**
 * @brief 例外情報を追加する
 * 
 * "\n[className] : [methodName]"の形の文字列情報として情報を設定します。
 *
 * @param[in] className 例外の発生したクラス名.
 * @param[in] methodName 例外の発生した関数名.
 */
void Exception::add( const std::string& className, const std::string& methodName )
{
	std::stringstream ss;
	ss << "\n[" << className << "] : [" << methodName << "]";
	mes_ += ss.str();
}



/*=========================================================================*/
/**
 * @brief 例外情報をコンソールに出力する
 * 
 * @param[in] なし.
 * @return なし.
 */
void Exception::outputConsol()
{
	std::cout << mes_  << std::endl;
}

	
	
/*=========================================================================*/
/**
 * @brief += 演算子オーバーロード
 *
 * 例外情報を追加する
 * 
 * @param[in] mes 追加する情報.
 * @return なし.
 */
void Exception::operator += ( const std::string& mes )
{
	add( mes );
}



/*=========================================================================*/
/**
 * @brief + 演算子オーバーロード
 *
 * 例外情報を追加する
 * 
 * @param[in] ext 追加する例外.
 * @param[in] mes 追加する情報.
 * @return なし.
 */
Ngl::Exception& operator + ( Ngl::Exception& ext, const std::string& mes )
{
	ext += mes;

	return ext;
}



/*=========================================================================*/
/**
 * @brief + 演算子オーバーロード
 *
 * 例外情報を追加する
 * 
 * @param[in] ext 追加する例外.
 * @param[in] mes 追加する情報.
 * @return なし.
 */
Ngl::Exception& operator + ( const std::string& mes, Ngl::Exception& ext )
{
	return ext + mes;
}



/*===== EOF ==================================================================*/