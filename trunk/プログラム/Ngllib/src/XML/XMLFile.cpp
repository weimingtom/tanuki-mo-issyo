/*******************************************************************************/
/**
 * @file XMLFile.cpp.
 * 
 * @brief XMLファイルクラスソースファイル.
 *
 * @date 2008/11/30.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/XML/XMLFile.h"
#include	"Ngl/XML/XMLElement.h"

using namespace Ngl;
using namespace Ngl::XML;


/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
XMLFile::XMLFile()
{}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
XMLFile::~XMLFile()
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
 * @brief 先頭のエレメントを追加
 * 
 * @param[in] elm 追加するエレメント.
 * @return なし.
 */
void XMLFile::addElement( XMLElement* elm )
{
	elementContainer_.push_back( elm );
}



/*=========================================================================*/
/**
 * @brief 名前から要素を取得
 * 
 * @param[in] name 取得する要素名.
 * @return 取得した要素.
 */
IXMLElement* XMLFile::getElementByName( const std::string name )
{
	ElementContainer::iterator itor;
	for( itor=elementContainer_.begin(); itor!=elementContainer_.end(); ++itor ){
		if( (*itor)->getElementName() == name ){
			return *itor;
		}
	}

	// 見つからなかった
	return 0;
}



/*=========================================================================*/
/**
 * @brief インデックス番号から要素を取得
 * 
 * @param[in] index 取得する要素のインデックス番号.
 * @return 取得した要素.
 */
IXMLElement* XMLFile::getElementByIndex( unsigned int index )
{
	return elementContainer_[ index ];
}



/*=========================================================================*/
/**
 * @brief 要素数を取得
 * 
 * @param[in] なし.
 * @return 取得した要素数.
 */
unsigned int XMLFile::elementCount()
{
	return static_cast<unsigned int>( elementContainer_.size() );
}



/*=========================================================================*/
/**
 * @brief [] 演算子オーバーロード
 *
 * nameで指定した要素を取得する.
 * 
 * @param[in] name 取得する要素名.
 * @return 取得した要素.
 */
IXMLElement* XMLFile::operator [] ( const std::string name )
{
	return getElementByName( name );
}



/*===== EOF ==================================================================*/