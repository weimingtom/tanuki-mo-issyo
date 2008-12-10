/*******************************************************************************/
/**
 * @file XMLUtil.cpp.
 * 
 * @brief XMLユーティリティー関数郡ソースファイル.
 *
 * @date 2008/11/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/XML/XMLUtil.h"

/*=========================================================================*/
/**
 * @brief テキストをchar型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( char& value, const Ngl::IXMLText& text )
{
	value = (char)text.getTextInt();
}



/*=========================================================================*/
/**
 * @brief テキストをunsigned char型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( unsigned char& value, const Ngl::IXMLText& text )
{
	value = (unsigned char)text.getTextInt();
}



/*=========================================================================*/
/**
 * @brief テキストをshort型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( short& value, const Ngl::IXMLText& text )
{
	value = (short)text.getTextInt();
}



/*=========================================================================*/
/**
 * @brief テキストをunsigned short型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( unsigned short& value, const Ngl::IXMLText& text )
{
	value = (unsigned short)text.getTextInt();
}



/*=========================================================================*/
/**
 * @brief テキストをint型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( int& value, const Ngl::IXMLText& text )
{
	value = text.getTextInt();
}



/*=========================================================================*/
/**
 * @brief テキストをunsigned int型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( unsigned int& value, const Ngl::IXMLText& text )
{
	value = (unsigned int)text.getTextInt();
}



/*=========================================================================*/
/**
 * @brief テキストをlong型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( long& value, const Ngl::IXMLText& text )
{
	value = (long)text.getTextInt();
}



/*=========================================================================*/
/**
 * @brief テキストをunsigned long型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( unsigned long& value, const Ngl::IXMLText& text )
{
	value = (unsigned long)text.getTextInt();
}



/*=========================================================================*/
/**
 * @brief テキストをfloat型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( float& value, const Ngl::IXMLText& text )
{
	value = text.getTextFloat();
}



/*=========================================================================*/
/**
 * @brief テキストをdouble型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( double& value, const Ngl::IXMLText& text )
{
	value = (double)text.getTextFloat();
}



/*=========================================================================*/
/**
 * @brief テキストをstring型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( std::string& value, const Ngl::IXMLText& text )
{
	value = text.getText();
}



/*=========================================================================*/
/**
 * @brief テキストをstring配列型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( Ngl::IXMLText::StringArray& value, const Ngl::IXMLText& text )
{
	text.getArray( value );
}



/*=========================================================================*/
/**
 * @brief テキストをint配列型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( Ngl::IXMLText::IntArray& value, const Ngl::IXMLText& text )
{
	text.getArray( value );
}



/*=========================================================================*/
/**
 * @brief テキストをfloat配列型で取得する
 * 
 * @param[in] value 取得した値を格納する変数.
 * @param[in] text XMLテキスト.
 * @return なし.
 */
void operator << ( Ngl::IXMLText::FloatArray& value, const Ngl::IXMLText& text )
{
	text.getArray( value );
}



/*=========================================================================*/
/**
 * @brief テキストをchar型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, char& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief テキストをunsigned char型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, unsigned char& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief テキストをshort型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, short& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief テキストをunsigned short型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, unsigned short& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief テキストをint型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, int& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief テキストをunsigned int型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, unsigned int& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief テキストをlong型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, long& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief テキストをunsigned long型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, unsigned long& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief テキストをfloat型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, float& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief テキストをdouble型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, double& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief テキストをstring型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, std::string& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief テキストをstring配列型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, Ngl::IXMLText::StringArray& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief テキストをint配列型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, Ngl::IXMLText::IntArray& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief テキストをfloat配列型で取得する
 * 
 * @param[in] text XMLテキスト.
 * @param[in] value 取得した値を格納する変数.
 * @return なし.
 */
void operator >> ( const Ngl::IXMLText& text, Ngl::IXMLText::FloatArray& value )
{
	value << text;
}



/*===== EOF ==================================================================*/