/*******************************************************************************/
/**
 * @file XMLElement.cpp.
 * 
 * @brief XML要素クラスソースファイル.
 *
 * @date 2008/11/30.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/XML/XMLElement.h"

using namespace Ngl;
using namespace Ngl::XML;


/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] name エレメント名.
 */
XMLElement::XMLElement( const char* name ):
	elementName_( name )
{}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
XMLElement::~XMLElement()
{
	// 要素を全削除
	ElementContainer::iterator itor = elementContainer_.begin();
	while( itor != elementContainer_.end() ){
		delete *itor;
		itor = elementContainer_.erase( itor );
	}
}



/*=========================================================================*/
/**
 * @brief 子エレメントを追加
 * 
 * @param[in] child 追加する子エレメント.
 * @return なし.
 */
void XMLElement::addChild( XMLElement* child )
{
	elementContainer_.push_back( child );
}



/*=========================================================================*/
/**
 * @brief 属性を追加
 * 
 * @param[in] name 追加する属性名.
 * @param[in] attrib 追加する属性テキスト.
 * @return なし.
 */
void XMLElement::addAttribute( const char* name, const char* attrib )
{
	attribContainer_[ name ] = XMLText( attrib );
}



/*=========================================================================*/
/**
 * @brief テキストを設定
 * 
 * @param[in] text 設定するテキスト.
 * @return なし.
 */
void XMLElement::setText( const char* text )
{
	value_.setText( text );
}


	
/*=========================================================================*/
/**
 * @brief 要素名を取得
 * 
 * @param[in] なし.
 * @return 要素名.
 */
const std::string& XMLElement::getElementName() const
{
	return elementName_;
}
	
	
	
/*=========================================================================*/
/**
 * @brief 名前から要素を取得
 * 
 * @param[in] name 値を取得する要素名.
 * @return 取得した要素.
 */
IXMLElement* XMLElement::getElementByName( const std::string& name )
{
	ElementContainer::iterator itor;
	for( itor=elementContainer_.begin(); itor!=elementContainer_.end(); ++itor ){
		if( (*itor)->getElementName() == name ){
			return *itor;
		}
	}
	return 0;
}



/*=========================================================================*/
/**
 * @brief インデックス番号から要素を取得
 * 
 * @param[in] index 値を取得する要素名.
 * @return 取得した要素(範囲外の場合は0が返ります).
 */
IXMLElement* XMLElement::getElementByIndex( int index )
{
	return elementContainer_[ index ];
}
	
	
	
/*=========================================================================*/
/**
 * @brief 属性名から属性の値を取得
 * 
 * @param[in] name 値を取得する属性名.
 * @return 取得した値 存在しない場合は空文字が返る.
 */
const IXMLText& XMLElement::getAttribByName( const std::string& name )
{
	return attribContainer_[ name ];
}



/*=========================================================================*/
/**
 * @brief 値を取得
 *
 * @param[in] なし.
 * @return 取得した値.
 */
const IXMLText& XMLElement::getValue() const
{
	return value_;
}



/*=========================================================================*/
/**
 * @brief 子要素を持っているか
 * 
 * @param[in] なし.
 * @retval true 子要素が存在する.
 * @retval false 子要素が存在しない.
 */
bool XMLElement::isExistChildElement() const
{
	return elementContainer_.empty();
}



/*=========================================================================*/
/**
 * @brief 属性を持っているか
 * 
 * @param[in] なし.
 * @retval true 属性を持っている.
 * @retval false 属性を持っていない.
 */
bool XMLElement::isExistAttrib() const
{
	return attribContainer_.empty();
}



/*=========================================================================*/
/**
 * @brief 値を持っているか
 * 
 * @param[in] なし.
 * @retval true 値を持っている.
 * @retval false 値を持っていない.
 */
bool XMLElement::isExistValue() const
{
	return value_.hasText();
}



/*=========================================================================*/
/**
 * @brief 子要素数を取得
 * 
 * @param[in] なし.
 * @return 子要素数.
 */
unsigned int XMLElement::childElementCount() const
{
	return static_cast< unsigned int >( elementContainer_.size() );
}



/*=========================================================================*/
/**
 * @brief 属性数を取得
 * 
 * @param[in] なし.
 * @return 属性数.
 */
unsigned int XMLElement::attribCount() const
{
	return static_cast< unsigned int >( attribContainer_.size() );
}



/*=========================================================================*/
/**
 * @brief [] 演算子オーバーロード
 * 
 * nameで指定した子要素を取得する.
 * 
 * @param[in] name 取得する子要素名.
 * @return 取得した子要素クラス.
 */
IXMLElement* XMLElement::operator [] ( const std::string& name )
{
	return getElementByName( name );
}



/*=========================================================================*/
/**
 * @brief [] 演算子オーバーロード
 * 
 * nameで指定した子要素を取得する.
 * 
 * @param[in] index 取得する要素インデックス番号.
 * @return 取得した子要素クラス( 範囲外の場合は0が返ります).
 */
IXMLElement* XMLElement::operator [] ( int index )
{
	return getElementByIndex( index );
}


	
/*===== EOF ==================================================================*/