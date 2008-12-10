/*******************************************************************************/
/**
 * @file FileInputBinary.h.
 * 
 * @brief バイナリファイル入力クラスヘッダファイル.
 *
 * @date 2008/07/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_FILEINPUTBINARY_H_
#define _NGL_FILEINPUTBINARY_H_

#include	"IInputStream.h"
#include	<fstream>

namespace Ngl{


/**
 * @class FileInputBinary．
 * @brief バイナリファイル入力クラス.
 *
 * リトルエンディアン方式（std::fstream) でバイナリデータを読み込みます.
 */
class FileInputBinary : public IInputStream
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	FileInputBinary();
	
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] fileName 開くファイル名.
	 */
	FileInputBinary( const std::string& fileName );


	/*=========================================================================*/
	/**
	 * @brief ファイルを開く
	 * 
	 * @param[in] fileName 開くファイル名.
	 * @return なし.
	 * @throw Ngl::FileOpenEception ファイルオープン例外.
	 */
	void open( const std::string& fileName );


	/*=========================================================================*/
	/**
	 * @brief ファイルを閉じる
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void close();
	
	
	/*=========================================================================*/
	/**
	 * @brief データを読み込む ( char型データを読み込む )
	 * 
	 * @param[out] data データを設定する変数.
	 * @return 読み込んだデータ.
	 * @throw Ngl::FileReadException ファイル読み込み例外.
	 */
	virtual void read( char& data );
	
	
	/*=========================================================================*/
	/**
	 * @brief データを読み込む ( string型データを読み込む )
	 * 
	 * @param[out] data データを設定する変数.
	 * @return 読み込んだデータ.
	 * @throw Ngl::FileReadException ファイル読み込み例外.
	 */
	virtual void read( std::string& data );
	
	
	/*=========================================================================*/
	/**
	 * @brief データを読み込む ( short型データを読み込む )
	 * 
	 * @param[out] data データを設定する変数.
	 * @return 読み込んだデータ.
	 * @throw Ngl::FileReadException ファイル読み込み例外.
	 */
	virtual void read( short& data );
		 
		 
	/*=========================================================================*/
	/**
	 * @brief データを読み込む ( unsigned short型データを読み込む )
	 * 
	 * @param[out] data データを設定する変数.
	 * @return 読み込んだデータ.
	 * @throw Ngl::FileReadException ファイル読み込み例外.
	 */
	virtual void read( unsigned short& data );
	 
	 
	/*=========================================================================*/
	/**
	 * @brief データを読み込む ( int型データを読み込む )
	 * 
	 * @param[out] data データを設定する変数.
	 * @return 読み込んだデータ.
	 * @throw Ngl::FileReadException ファイル読み込み例外.
	 */
	virtual void read( int& data );
		 
		 
	/*=========================================================================*/
	/**
	 * @brief データを読み込む ( unsigned int型データを読み込む )
	 * 
	 * @param[out] data データを設定する変数.
	 * @return 読み込んだデータ.
	 * @throw Ngl::FileReadException ファイル読み込み例外.
	 */
	virtual void read( unsigned int& data );
	 
	 
	/*=========================================================================*/
	/**
	 * @brief データを読み込む ( long型データを読み込む )
	 * 
	 * @param[out] data データを設定する変数.
	 * @return 読み込んだデータ.
	 * @throw Ngl::FileReadException ファイル読み込み例外.
	 */
	virtual void read( long& data );
	 
	 
	/*=========================================================================*/
	/**
	 * @brief データを読み込む ( unsigned long型データを読み込む )
	 * 
	 * @param[out] data データを設定する変数.
	 * @return 読み込んだデータ.
	 * @throw Ngl::FileReadException ファイル読み込み例外.
	 */
	virtual void read( unsigned long& data );
	 
	 
	/*=========================================================================*/
	/**
	 * @brief データを読み込む ( float型データを読み込む )
	 * 
	 * @param[out] data データを設定する変数.
	 * @return 読み込んだデータ.
	 * @throw Ngl::FileReadException ファイル読み込み例外.
	 */
	virtual void read( float& data );
	 
	 
	/*=========================================================================*/
	/**
	 * @brief データを読み込む ( double型データを読み込む )
	 * 
	 * @param[out] data データを設定する変数.
	 * @return 読み込んだデータ.
	 * @throw Ngl::FileReadException ファイル読み込み例外.
	 */
	virtual void read( double& data );


	/*=========================================================================*/
	/**
	 * @brief >> 演算子オーバーロード ( マニピュレータ用 )
	 * 
	 * @param[out] func マニピュレータの関数ポインタ.
	 * @return 入力ストリームの参照.
	 */
	virtual IInputStream& operator >> ( IInputStream& (*func)(IInputStream&) );
	
	
	/*=========================================================================*/
	/**
	 * @brief 指定バイト数分読み込む
	 * 
	 * @param[in] dest 読み込んだデータを格納するデータ.
	 * @param[in] size 読み込むサイズ.
	 * @return なし.
	 */
	virtual void read( char* dest, unsigned int size );
	
	
	/*=========================================================================*/
	/**
	 * @brief 指定位置にシークする
	 * 
	 * @param[in] offset 移動する位置.
	 * @param[in] flag シークフラグ.
	 * @return なし.
	 */
	virtual void seek( unsigned int offset, SeekFlug flag );
	
	
	/*=========================================================================*/
	/**
	 * @brief 現在位置を取得する
	 * 
	 * @param[in] なし.
	 * @return 現在位置のバイト数.
	 */
	virtual unsigned int tell();
	
	
	/*=========================================================================*/
	/**
	 * @brief ストリーム読み込みタイプを設定する
	 * 
	 * @param[out] type 設定する読み込みタイプ.
	 * @return なし.
	 */
	virtual void readType( StreamReadType type ); 
	

	/*=========================================================================*/
	/**
	 * @brief ストリーム読み込みタイプを取得する
	 * 
	 * @param[out] なし.
	 * @return ストリームタイプ.
	 */
	virtual StreamReadType readType();


	/*=========================================================================*/
	/**
	 * @brief ストリーム名を取得する
	 * 
	 * @param[in] なし.
	 * @return ストリーム名.
	 */
	virtual  const std::string& streamName() const;

private:

	// ファイル入力ストリーム
	std::ifstream	ifStream_;

	/** ファイル読み込みタイプ */
	StreamReadType	readType_;	

	// ファイル名
	std::string		fileName_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/