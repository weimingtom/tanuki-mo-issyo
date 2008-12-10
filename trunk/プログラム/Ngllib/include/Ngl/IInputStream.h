/*******************************************************************************/
/**
 * @file IInputStream.h.
 * 
 * @brief 入力ストリームインターフェース定義.
 *
 * @date 2008/07/13.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IINPUTSTREAM_H_
#define _NGL_IINPUTSTREAM_H_

#include	"Exception.h"

namespace Ngl{


/**
 * @enum StreamReadType.
 * @brief ストリーム読み込みタイプ列挙型.
 */
enum StreamReadType
{
	STREAM_READ_TYPE_8	= 0,	/**< 8進数読み込み	*/
	STREAM_READ_TYPE_10,		/**< 10進数読み込み	*/
	STREAM_READ_TYPE_16			/**< 16進数読み込み	*/
};


/**
 * @enum SeekFlug.
 * @brief ファイルのシーク位置フラグ列挙型.
 */
enum SeekFlug
{
	SEEKFLUG_BEG	= 0,	/**< 先頭		*/
	SEEKFLUG_CUR,			/**< 現在位置	*/
	SEEKFLUG_END			/**< 末尾		*/
};


/**
 * @interface IInputStream．
 * @brief 入力ストリームインターフェース.
 */
class IInputStream
{

public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IInputStream() {}


	/*=========================================================================*/
	/**
	 * @brief データを読み込む ( char型データを読み込む )
	 * 
	 * @param[out] data データを設定する変数.
	 * @return 読み込んだデータ.
	 * @throw Ngl::InputStreamException 読み込み例外.
	 */
	virtual void read( char& data ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief データを読み込む ( string型データを読み込む )
	 * 
	 * @param[out] data データを設定する変数.
	 * @return 読み込んだデータ.
	 * @throw Ngl::InputStreamException 読み込み例外.
	 */
	virtual void read( std::string& data ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief データを読み込む ( short型データを読み込む )
	 * 
	 * @param[out] data データを設定する変数.
	 * @return 読み込んだデータ.
	 * @throw Ngl::InputStreamException 読み込み例外.
	 */
	virtual void read( short& data ) = 0;
		 
		 
	/*=========================================================================*/
	/**
	 * @brief データを読み込む ( unsigned short型データを読み込む )
	 * 
	 * @param[out] data データを設定する変数.
	 * @return 読み込んだデータ.
	 * @throw Ngl::InputStreamException 読み込み例外.
	 */
	virtual void read( unsigned short& data ) = 0;
	 
	 
	/*=========================================================================*/
	/**
	 * @brief データを読み込む ( int型データを読み込む )
	 * 
	 * @param[out] data データを設定する変数.
	 * @return 読み込んだデータ.
	 * @throw Ngl::InputStreamException 読み込み例外.
	 */
	virtual void read( int& data ) = 0;
		 
		 
	/*=========================================================================*/
	/**
	 * @brief データを読み込む ( unsigned int型データを読み込む )
	 * 
	 * @param[out] data データを設定する変数.
	 * @return 読み込んだデータ.
	 * @throw Ngl::InputStreamException 読み込み例外.
	 */
	virtual void read( unsigned int& data ) = 0;
	 
	 
	/*=========================================================================*/
	/**
	 * @brief データを読み込む ( long型データを読み込む )
	 * 
	 * @param[out] data データを設定する変数.
	 * @return 読み込んだデータ.
	 * @throw Ngl::InputStreamException 読み込み例外.
	 */
	virtual void read( long& data ) = 0;
	 
	 
	/*=========================================================================*/
	/**
	 * @brief データを読み込む ( unsigned long型データを読み込む )
	 * 
	 * @param[out] data データを設定する変数.
	 * @return 読み込んだデータ.
	 * @throw Ngl::InputStreamException 読み込み例外.
	 */
	virtual void read( unsigned long& data ) = 0;
	 
	 
	/*=========================================================================*/
	/**
	 * @brief データを読み込む ( float型データを読み込む )
	 * 
	 * @param[out] data データを設定する変数.
	 * @return 読み込んだデータ.
	 * @throw Ngl::InputStreamException 読み込み例外.
	 */
	virtual void read( float& data ) = 0;
	 
	 
	/*=========================================================================*/
	/**
	 * @brief データを読み込む ( double型データを読み込む )
	 * 
	 * @param[out] data データを設定する変数.
	 * @return 読み込んだデータ.
	 * @throw Ngl::InputStreamException 読み込み例外.
	 */
	virtual void read( double& data ) = 0;


	/*=========================================================================*/
	/**
	 * @brief >> 演算子オーバーロード ( マニピュレータ用 )
	 * 
	 * @param[out] func マニピュレータの関数ポインタ.
	 * @return 入力ストリームの参照.
	 */
	virtual IInputStream& operator >> ( IInputStream& (*func)(IInputStream&) ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 指定バイト数分読み込む
	 * 
	 * @param[in] dest 読み込んだデータを格納するデータ.
	 * @param[in] size 読み込むサイズ.
	 * @return なし.
	 */
	virtual void read( char* dest, unsigned int size ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 指定位置にシークする
	 * 
	 * @param[in] offset 移動する位置.
	 * @param[in] flag シークフラグ.
	 * @return なし.
	 */
	virtual void seek( unsigned int offset, SeekFlug flag ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 現在位置を取得する
	 * 
	 * @param[in] なし.
	 * @return 現在位置のバイト数.
	 */
	virtual unsigned int tell() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief ストリーム読み込みタイプを設定する
	 * 
	 * @param[out] type 設定する読み込みタイプ.
	 * @return なし.
	 */
	virtual void readType( StreamReadType type ) = 0; 
	

	/*=========================================================================*/
	/**
	 * @brief ストリーム読み込みタイプを取得する
	 * 
	 * @param[out] なし.
	 * @return ストリームタイプ.
	 */
	virtual StreamReadType readType() = 0;


	/*=========================================================================*/
	/**
	 * @brief ストリーム名を取得する
	 * 
	 * @param[in] なし.
	 * @return ストリーム名.
	 */
	virtual  const std::string& streamName() const = 0;


	/*=========================================================================*/
	/**
	 * @brief >> 演算子オーバーロード
	 * 
	 * @param[in] value 入力するデータ.
	 * @return 入力後のストリーム.
	 */
	template< class Value >
	void operator >> ( Value& value )
	{
		read( value );
	}

};

} // namespace Ngl


#endif

/*===== EOF ==================================================================*/