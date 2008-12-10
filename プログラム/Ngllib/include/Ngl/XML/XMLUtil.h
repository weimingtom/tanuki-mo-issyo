/*******************************************************************************/
/**
 * @file XMLUtil.h.
 * 
 * @brief XMLユーティリティー関数郡ヘッダファイル.
 *
 * @date 2008/11/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_XMLUTIL_H_
#define _NGL_XMLUTIL_H_

#include	"Ngl/IXMLText.h"


/*=========================================================================*/
/**
 * @brief テキストをchar型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator << ( char& value, const Ngl::IXMLText& text );


/*=========================================================================*/
/**
 * @brief テキストをunsigned char型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( unsigned char& value, const Ngl::IXMLText& text );


/*=========================================================================*/
/**
 * @brief テキストをshort型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( short& value, const Ngl::IXMLText& text );


/*=========================================================================*/
/**
 * @brief テキストをunsigned short型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( unsigned short& value, const Ngl::IXMLText& text );


/*=========================================================================*/
/**
 * @brief テキストをint型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( int& value, const Ngl::IXMLText& text );


/*=========================================================================*/
/**
 * @brief テキストをunsigned int型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( unsigned int& value, const Ngl::IXMLText& text );


/*=========================================================================*/
/**
 * @brief テキストをlong型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( long& value, const Ngl::IXMLText& text );


/*=========================================================================*/
/**
 * @brief テキストをunsigned long型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( unsigned long& value, const Ngl::IXMLText& text );


/*=========================================================================*/
/**
 * @brief テキストをfloat型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( float& value, const Ngl::IXMLText& text );


/*=========================================================================*/
/**
 * @brief テキストをdouble型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( double& value, const Ngl::IXMLText& text );


/*=========================================================================*/
/**
 * @brief テキストをstring型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( std::string& value, const Ngl::IXMLText& text );


/*=========================================================================*/
/**
 * @brief テキストをstring配列型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( Ngl::IXMLText::StringArray& value, const Ngl::IXMLText& text );


/*=========================================================================*/
/**
 * @brief テキストをint配列型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( Ngl::IXMLText::IntArray& value, const Ngl::IXMLText& text );


/*=========================================================================*/
/**
 * @brief テキストをfloat配列型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( Ngl::IXMLText::FloatArray& value, const Ngl::IXMLText& text );



/*=========================================================================*/
/**
 * @brief テキストをchar型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, char& value );


/*=========================================================================*/
/**
 * @brief テキストをunsigned char型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, unsigned char& value );


/*=========================================================================*/
/**
 * @brief テキストをshort型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, short& value );


/*=========================================================================*/
/**
 * @brief テキストをunsigned short型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, unsigned short& value );


/*=========================================================================*/
/**
 * @brief テキストをint型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, int& value );


/*=========================================================================*/
/**
 * @brief テキストをunsigned int型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, unsigned int& value );


/*=========================================================================*/
/**
 * @brief テキストをlong型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, long& value );


/*=========================================================================*/
/**
 * @brief テキストをunsigned long型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, unsigned long& value );


/*=========================================================================*/
/**
 * @brief テキストをfloat型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, float& value );


/*=========================================================================*/
/**
 * @brief テキストをdouble型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, double& value );


/*=========================================================================*/
/**
 * @brief テキストをstring型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, std::string& value );


/*=========================================================================*/
/**
 * @brief テキストをstring配列型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, Ngl::IXMLText::StringArray& value );


/*=========================================================================*/
/**
 * @brief テキストをint配列型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, Ngl::IXMLText::IntArray& value );


/*=========================================================================*/
/**
 * @brief テキストをfloat配列型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, Ngl::IXMLText::FloatArray& value );


#endif

/*===== EOF ==================================================================*/