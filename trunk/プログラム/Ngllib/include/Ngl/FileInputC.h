/*******************************************************************************/
/**
 * @file FileInputC.h.
 * 
 * @brief Cスタイルファイル入力クラスヘッダファイル.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_FILE_INPUT_C_H_
#define _NGL_FILE_INPUT_C_H_

#include	"IInputStream.h"
#include	<string>
#include	<cstdio>

namespace Ngl{


/**
 * @class FileInputC.
 * @brief Cスタイルファイル入力クラス．
 *
 * C言語のファイル入力関数を使用したクラスです。<br>
 * アスキー形式のテキストファイルを読み込むことができます。<br>
 * (バイナリファイル読み込み非対応)<br>
 * '#'の文字をコメント文字として認識します。<br>
 * 指定のデリミタ文字でトークン分解を行います。<br>
 */
class FileInputC : public IInputStream
{
public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	FileInputC();
	
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] fileName 開くファイル名.
	 */
	FileInputC( std::string fileName );


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~FileInputC();

	
	/*=========================================================================*/
	/**
	 * @brief ファイルを開く
	 * 
	 * @param[in] fileName 開くファイル名.
	 * @return なし.
	 * @throw Ngl::FileOpenException ファイルオープン例外.
	 */
	void open( std::string fileName );


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
	 * @brief ファイルがOpenできなかったか
	 * 
	 * @param[in] なし.
	 * @retval true 開けなかった.
	 * @retval false 開けた.
	 */
	bool isOpenFailed();
		
	
	/*=========================================================================*/
	/**
	 * @brief ファイルのアクセスエラーが起きたか調べる
	 * 
	 * @param[in] なし.
	 * @retval true アクセスエラー.
	 * @retval false アクセス成功.
	 */
	 bool isError() const;


	/*=========================================================================*/
	/**
	 * @brief ファイルがＥＯＦまで達したか調べる
	 * 
	 * @param[in] なし.
	 * @retval true EOF.
	 * @retval false ファイルの途中.
	 */
	 bool isEOF() const;


	/*=========================================================================*/
	/**
	 * @brief 読み飛ばす文字を設定する
	 * 
	 * @param[in] skipChara 読み飛ばす文字.
	 * @return なし.
	 */
	 void setSkipCharacter( std::string skipChara );

	 
	/*=========================================================================*/
	/**
	 * @brief 行末まで読み飛ばす
	 * 
	 * @param[in] なし.
	 * @retval true 読み飛ばし完了.
	 * @retval false 読み飛ばし未完了.
	 */
	 bool skipToLineEnd();
	 
	 
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

	/*=========================================================================*/
	/**
	 * @brief テキストファイルからデータを読み取る
	 * 
	 * @param[in] format 読み取り形式.
	 * @param[in] input 読み込んだデータを保存するデータ.
	 * @retval true 読み取り成功.
	 * @retval false 読み取り失敗.
	 * @throw Ngl::FileReadException ファイル読み込み例外.
	 */
	void readTextFile( const char* format, void* input );


	/*=========================================================================*/
	/**
	 * @brief バッファを読み取る
	 * 
	 * @param[in] buf 読み込んだバッファを保存するデータ.
	 * @return true 読み取り成功.
	 * @retval false 読み取り失敗.
	 */
	bool readBuffer( char* buf );


	/*=========================================================================*/
	/**
	 * @brief デリミタ文字とコメント文字をスキップして1文字読み取る
	 * 
	 * @param[in] buf 読み込んだ文字を保存するデータ.
	 * @retval true 読み取り成功.
	 * @retval false 読み取り失敗.
	 */
	bool readSkipDelimiter( char* buf );


	/*=========================================================================*/
	/**
	 * @brief デリミタ文字か判定する
	 * 
	 * @param[in] c 判定する文字.
	 * @retval true デリミタ文字だった.
	 * @retval false デリミタ文字じゃなかった.
	 */
	inline bool isDelimiter( int c )
	{
		bool tmp;
		( strchr( delimiter_.c_str(), c ) != 0 ) ? tmp=true : tmp=false;
		return tmp;
	}

private:

	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ(コピー禁止処理)
	 * 
	 * @param[in] other コピーするオブジェクト.
	 */
	FileInputC( const FileInputC& other );


	/*=========================================================================*/
	/**
	 * @brief =演算子オーバーロード(コピー禁止処理)
	 * 
	 * @param[in] other 代入するオブジェクト.
	 * @return 代入結果のオブジェクト.
	 */
	FileInputC& operator = ( const FileInputC& other );

private:

	/** 読み込みバッファサイズ */
	const static int MAX_BUFFER_SIZE;

private:

	/** 読み込み中のファイル名 */
	std::string				fileName_;

	/** 読み取り中か */
	bool					isFileLoaded_;

	/** ファイル構造体 */
	FILE*					file_;

	/** デリミタ文字 */
	std::string				delimiter_;

	/** ファイル読み込みタイプ */
	StreamReadType			readType_;						

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/