/*******************************************************************************/
/**
 * @file XMLText.h.
 * 
 * @brief XMLテキストクラスヘッダファイル.
 *
 * @date 2008/11/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_XMLTEXT_H_
#define _NGL_XMLTEXT_H_

#include	"Ngl/IXMLText.h"
#include	<string>

namespace Ngl{


namespace XML{


/**
 * @class XMLText．
 * @brief XMLテキストクラス.
 */
class XMLText : public IXMLText
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in]なし.
	 */
	XMLText();

	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] text XMLのテキスト.
	 */
	XMLText( const char* text );


	/*=========================================================================*/
	/**
	 * @brief テキストを設定する
	 * 
	 * @param[in] text XMLのテキスト.
	 */
	void setText( const char* text );
	
	
	/*=========================================================================*/
	/**
	 * @brief テキストを保持しているか
	 * 
	 * @param[in] なし.
	 * @retval true 保持している.
	 * @retval false 保持していない.
	 */
	virtual bool hasText() const;
	
	
	/*=========================================================================*/
	/**
	 * @brief テキストを文字列で取得する
	 * 
	 * @param[in] なし.
	 * @return テキスト.
	 */
	virtual const std::string& getText() const;


	/*=========================================================================*/
	/**
	 * @brief テキストをint型の数値で取得する
	 * 
	 * @param[in] なし.
	 * @return テキスト.
	 */
	virtual int getTextInt() const;


	/*=========================================================================*/
	/**
	 * @brief テキストをfloat型の数値で取得する
	 * 
	 * @param[in] なし.
	 * @return テキスト.
	 */
	virtual float getTextFloat() const;


	/*=========================================================================*/
	/**
	 * @brief テキストを文字列配列で取得する
	 * 
	 * @param[out] array XML文字列型配列.
	 * @return なし.
	 */
	virtual void getArray( StringArray& array ) const;


	/*=========================================================================*/
	/**
	 * @brief テキストをint型配列で取得する
	 * 
	 * @param[out] array XMLint型配列.
	 * @return テキスト.
	 */
	virtual void getArray( IntArray& array ) const;


	/*=========================================================================*/
	/**
	 * @brief テキストをfloat型配列で取得する
	 * 
	 * @param[out] array XMLfloat型配列.
	 * @return テキスト.
	 */
	virtual void getArray( FloatArray& array ) const;

private:

	/** XMLのテキスト */
	std::string	text_;

};

} // namespace XML

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/