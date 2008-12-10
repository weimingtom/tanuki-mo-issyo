/*******************************************************************************/
/**
 * @file Utility.h.
 * 
 * @brief ユーティリティークラスヘッダファイル.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_UTIITY_H_
#define _NGL_UTIITY_H_

#include	<string>

namespace Ngl{

/**
 * @class Utility
 * @brief ユーティリティークラス．
 */
class Utility
{

public:

	/*=========================================================================*/
	/**
	 * @brief フルパスのファイル名からファイル名を切り出す( 拡張子なし )
	 * 
	 * @param[in] fileName 切り出すファイル名.
	 * @return 切り出したファイル名.
	 */
	static std::string getFileName( const char* fileName );
	
	
	/*=========================================================================*/
	/**
	 * @brief 拡張子を切り出す( .を含まない )
	 * 
	 * @param[in] fileName 切り出すファイル名.
	 * @return 切り出した拡張子.
	 */
	static std::string getFileExtension( const char* fileName );


	/*=========================================================================*/
	/**
	 * @brief ファイルパスのドライブ名を切り出す
	 * 
	 * @param[in] fileName 切り出すファイル名.
	 * @return 切り出したパス.
	 */
	static std::string getFilePathDrave( const char* fileName );


	/*=========================================================================*/
	/**
	 * @brief ファイルパスのディレクトリ名を切り出す
	 * 
	 * @param[in] fileName 切り出すファイル名.
	 * @return 切り出したディレクトリ.
	 */
	static std::string getFilePathDir( const char* fileName );


	/*=========================================================================*/
	/**
	 * @brief charからwchar_tへ変換する
	 * 
	 * @param[in] src 変換元のconst char型文字列.
	 * @param[in] dest 変換データを格納するwchar_t型文字列.
	 * @return なし.
	 */
	static void multiByteToWideChar( const char* src, wchar_t* dest );

};

}	// namespace ngl

#endif

/*===== EOF ==================================================================*/