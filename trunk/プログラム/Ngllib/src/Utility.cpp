/*******************************************************************************/
/**
 * @file Utility.cpp.
 * 
 * @brief ユーティリティークラスソースファイル.
 *
 * @date 2008/07/08.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Utility.h"
#include	<cstring>
#include	<cstdlib>
#include	<clocale>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief フルパスのファイル名からファイル名を切り出す( 拡張子なし )
 * 
 * @param[in] fileName 切り出すファイル名.
 * @return 切り出したファイル名.
 */
std::string Utility::getFileName( const char* fileName )
{
	char fname[_MAX_FNAME ];
	_splitpath( fileName, NULL, NULL, fname, NULL );

	std::string fileNameExt = fname;

	return fileNameExt;
}

	
	
/*===========================================================================*/
/**
 * @brief 拡張子を切り出す( .を含まない )
 * 
 * @param[in] fileName 切り出すファイル名.
 * @return 切り出した拡張子.
 */
std::string Utility::getFileExtension(const char *fileName)
{
	char ext[_MAX_FNAME ];
	_splitpath( fileName, NULL, NULL, NULL, ext );

	// .を切り落とす
	std::string fileNameExt = ext;
	fileNameExt.erase( 0, 1 );
	
	return fileNameExt;
}



/*===========================================================================*/
/**
 * @brief ファイルパスのドライブ名を切り出す
 * 
 * @param[in] fileName 切り出すファイル名.
 * @return 切り出したパス.
 */
std::string Utility::getFilePathDrave(const char *fileName)
{
	char drive[_MAX_DRIVE ];
	char dir[_MAX_DIR ];
	_splitpath( fileName, drive, dir, NULL, NULL );

	return std::string( drive );
}




/*===========================================================================*/
/**
 * @brief ファイルパスのディレクトリ名を切り出す
 * 
 * @param[in] fileName 切り出すファイル名.
 * @return 切り出したディレクトリ.
 */
std::string Utility::getFilePathDir(const char *fileName)
{
	char drive[_MAX_DRIVE ];
	char dir[_MAX_DIR ];
	_splitpath( fileName, drive, dir, NULL, NULL );

	return std::string( dir );
}



/*=========================================================================*/
/**
 * @brief charからwchar_tへ変換する
 * 
 * @param[in] src 変換元のconst char型文字列.
 * @param[in] dest 変換データを格納するwchar_t型文字列.
 * @return なし.
 */
void Utility::multiByteToWideChar( const char* src, wchar_t* dest )
{
	// ロケールを設定
	setlocale( LC_ALL, "ja" );
	
	// 文字列を変換してコピー
	size_t len = 0;
	mbstowcs_s( &len, dest, strlen( src ) + 1, src, 1024 ); 
}

	
	
/*========= EOF =============================================================*/