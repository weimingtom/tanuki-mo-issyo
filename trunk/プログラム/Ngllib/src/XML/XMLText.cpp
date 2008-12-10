/*******************************************************************************/
/**
 * @file XMLText.cpp.
 * 
 * @brief XMLテキストクラスソースファイル.
 *
 * @date 2008/11/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/XML/XMLText.h"
#include	<sstream>

using namespace Ngl;
using namespace Ngl::XML;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
XMLText::XMLText()
{}

	
	
/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] text XMLのテキスト.
 */
XMLText::XMLText( const char* text ):
	text_( text )
{}



/*=========================================================================*/
/**
 * @brief テキストを設定する
 * 
 * @param[in] text XMLのテキスト.
 */
void XMLText::setText( const char* text )
{
	text_ = text;
}

	
	
/*=========================================================================*/
/**
 * @brief テキストを保持しているか
 * 
 * @param[in] なし.
 * @retval true 保持している.
 * @retval false 保持していない.
 */
bool XMLText::hasText() const
{
	return !text_.empty();
}
	
	
	
/*=========================================================================*/
/**
 * @brief テキストを文字列で取得する
 * 
 * @param[in] なし.
 * @return テキスト.
 */
const std::string& XMLText::getText() const
{
	return text_;
}



/*=========================================================================*/
/**
 * @brief テキストをint型の数値で取得する
 * 
 * @param[in] なし.
 * @return テキスト.
 */
int XMLText::getTextInt() const
{
	return std::atoi( text_.c_str() );
}



/*=========================================================================*/
/**
 * @brief テキストをfloat型の数値で取得する
 * 
 * @param[in] なし.
 * @return テキスト.
 */
float XMLText::getTextFloat() const
{
	return (float)std::atof( text_.c_str() );
}



/*=========================================================================*/
/**
 * @brief テキストを文字列配列で取得する
 * 
 * @param[out] array XML文字列型配列.
 * @return なし.
 */
void XMLText::getArray( StringArray& array ) const
{
	std::stringstream ss( text_ );
	while ( ss.eof() == false ) {
		std::string value;
		ss >> value;
		array.push_back( value );
	}
}



/*=========================================================================*/
/**
 * @brief テキストをint型配列で取得する
 * 
 * @param[out] array XMLint型配列.
 * @return テキスト.
 */
void XMLText::getArray( IntArray& array ) const
{
	std::stringstream ss( text_ );
	while( ss.eof() == false ){
		int value = 0;
		ss >> value;
		array.push_back( value );
	}
}



/*=========================================================================*/
/**
 * @brief テキストをfloat型配列で取得する
 * 
 * @param[out] array XMLFloat型配列.
 * @return テキスト.
 */
void XMLText::getArray( FloatArray& array ) const
{
	std::stringstream ss( text_ );
	while( ss.eof() == false ){
		float value = 0;
		ss >> value;
		array.push_back( value );
	}
}


	
/*===== EOF ==================================================================*/