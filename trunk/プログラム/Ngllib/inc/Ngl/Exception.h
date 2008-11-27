/*******************************************************************************/
/**
 * @file Exception.h.
 * 
 * @brief 例外クラス定義.
 *
 * @date 2008/07/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_EXCEPTION_H_
#define _NGL_EXCEPTION_H_

#include	<string>

namespace Ngl{


/**
 * @interface Exception．
 * @brief 例外クラス.
 */
class Exception
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] mes 例外情報文字列.
	 */
	Exception( const std::string& mes );
	
	
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
	Exception( const std::string& mes, std::string file, int line );
	
	
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
	Exception( const std::string& mes, const std::string& className, const std::string& methodName );
	
	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~Exception();


	/*=========================================================================*/
	/**
	 * @brief 例外情報文字を取得する
	 * 
	 * @param[in] なし.
	 * @return 例外情報文字列.
	 */
	virtual const char* what();


	/*=========================================================================*/
	/**
	 * @brief 例外情報文字を取得する( stringクラス )
	 * 
	 * @param[in] なし.
	 * @return 例外情報文字列.
	 */
	virtual const std::string& str();
	
	
	/*=========================================================================*/
	/**
	 * @brief 例外情報を追加する
	 * 
	 * @param[in] mes 追加する情報.
	 * @return なし.
	 */
	virtual void add( const std::string& mes );

	
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
	virtual void add( std::string file, int line );
	
	
	/*=========================================================================*/
	/**
	 * @brief 例外情報を追加する
	 * 
	 * "\n[className] : [methodName]"の形の文字列情報として情報を設定します。
	 *
	 * @param[in] className 例外の発生したクラス名.
	 * @param[in] methodName 例外の発生した関数名.
	 */
	virtual void add( const std::string& className, const std::string& methodName );

	
	/*=========================================================================*/
	/**
	 * @brief 例外情報をコンソールに出力する
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void outputConsol();
	
	
	/*=========================================================================*/
	/**
	 * @brief += 演算子オーバーロード
	 *
	 * 例外情報を追加する
	 * 
	 * @param[in] mes 追加する情報.
	 * @return なし.
	 */
	virtual void operator += ( const std::string& mes );

private:

	/** 例外情報文字列 */
	std::string		mes_;

};


/** ファイル名と行数自動登録マクロ */
#define EXCEPTION( msg ) Ngl::Exception(msg, __FILE__, __LINE__)

/** ファイル名と行数情報自動追加マクロ */
#define ADDEXCEPTIONINFO_FILELINE( exception ) exception.add(__FILE__, __LINE__)


/**
 * @class InputStreamException.
 * @brief 入力ストリーム例外クラス．
 */
class InputStreamException : public Exception
{
public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] msg エラーメッセージ.
	 */
	InputStreamException( const std::string& msg ) :
		Exception( msg )	// 標準例外クラス
	{}


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 *
	 * "mes \n [file] : [line]"の形の文字列情報として情報を設定します。
	 * 
	 * @param[in] mes 例外情報文字列.
	 * @param[in] file 例外の発生したファイル名.
	 * @param[in] line 例外の発生した行数.
	 */
	InputStreamException( const std::string& mes, std::string file, int line ):
		Exception( mes, file, line )
	{}
	
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * "mes \n [className] : [methodName]"の形の文字列情報として情報を設定します。
	 *
	 * @param[in] mes 例外情報文字列.
	 * @param[in] className 例外の発生したクラス名.
	 * @param[in] methodName 例外の発生した関数名.
	 */
	InputStreamException( const std::string& mes, const std::string& className, const std::string& methodName ):
		Exception( mes, className, methodName )
	{}

};


/** ファイル名と行数自動登録マクロ */
#define INPUT_STREAM_EXCEPTION( msg ) Ngl::InputStreamException(msg, __FILE__, __LINE__)


/**
 * @class FileOpenException.
 * @brief ファイルオープン例外クラス．
 */
class FileOpenException : public InputStreamException
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] msg エラーメッセージ.
	 */
	FileOpenException( const std::string& msg ) :
	  InputStreamException( msg )	// 標準例外クラス
	{}


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 *
	 * "mes \n [file] : [line]"の形の文字列情報として情報を設定します。
	 * 
	 * @param[in] mes 例外情報文字列.
	 * @param[in] file 例外の発生したファイル名.
	 * @param[in] line 例外の発生した行数.
	 */
	FileOpenException( const std::string& mes, std::string file, int line ):
	  InputStreamException( mes, file, line )
	{}
	
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * "mes \n [className] : [methodName]"の形の文字列情報として情報を設定します。
	 *
	 * @param[in] mes 例外情報文字列.
	 * @param[in] className 例外の発生したクラス名.
	 * @param[in] methodName 例外の発生した関数名.
	 */
	FileOpenException( const std::string& mes, const std::string& className, const std::string& methodName ):
	 InputStreamException( mes, className, methodName )
	{}

};


/** ファイル名と行数自動登録マクロ */
#define FILE_OPEN_EXCEPTION( msg ) Ngl::FileOpenException(msg, __FILE__, __LINE__)


/**
 * @class FileReadException.
 * @brief ファイル読み込み例外クラス．
 */
class FileReadException : public InputStreamException
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] msg エラーメッセージ.
	 */
	FileReadException( const std::string& msg ) :
	  InputStreamException( msg )	// 標準例外クラス
	{}


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 *
	 * "mes \n [file] : [line]"の形の文字列情報として情報を設定します。
	 * 
	 * @param[in] mes 例外情報文字列.
	 * @param[in] file 例外の発生したファイル名.
	 * @param[in] line 例外の発生した行数.
	 */
	FileReadException( const std::string& mes, std::string file, int line ):
	  InputStreamException( mes, file, line )
	{}
	
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * "mes \n [className] : [methodName]"の形の文字列情報として情報を設定します。
	 *
	 * @param[in] mes 例外情報文字列.
	 * @param[in] className 例外の発生したクラス名.
	 * @param[in] methodName 例外の発生した関数名.
	 */
	FileReadException( const std::string& mes, const std::string& className, const std::string& methodName ):
	 InputStreamException( mes, className, methodName )
	{}

};


/** ファイル名と行数自動登録マクロ */
#define FILE_READ_EXCEPTION( msg ) Ngl::FileReadException(msg, __FILE__, __LINE__)


} // namespace Ngl


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
Ngl::Exception& operator + ( Ngl::Exception& ext, const std::string& mes );


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
Ngl::Exception& operator + ( const std::string& mes, Ngl::Exception& ext );


#endif

/*===== EOF ==================================================================*/