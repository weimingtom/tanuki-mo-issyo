/*******************************************************************************/
/**
 * @file XMLDomParserTinyXML.cpp.
 * 
 * @brief TinyXML DOM方式XMLパーサクラスソースファイル.
 *
 * @date 2007/12/03.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/TinyXML/XMLDomParserTinyXML.h"
#include	<TinyXML/tinyxml.h>

using namespace Ngl;
using namespace Ngl::TinyXML;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
XMLDomParserTinyXML::XMLDomParserTinyXML():
	xmlDocument_( new TiXmlDocument() )
{}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
XMLDomParserTinyXML::~XMLDomParserTinyXML()
{
	delete xmlDocument_;
}



/*=========================================================================*/
/**
 * @brief ファイルからデータを読み込む
 * 
 * @param[in] name ファイル名.
 * @param[out] file データを読み込むXMLFileクラス.
 * @return なし.
 */
void XMLDomParserTinyXML::load( const std::string& name, Ngl::XML::XMLFile& file )
{
	// XMLファイルを解析する
	xmlDocument_->LoadFile( name.c_str() );

	// 兄弟要素を取得
	TiXmlElement* element = xmlDocument_->FirstChildElement();
	while( element != 0 ){
		// 要素を作成する
		Ngl::XML::XMLElement* elm = new Ngl::XML::XMLElement( element->Value() );
		createElement( elm, element );

		// 作成した要素を追加
		file.addElement( elm );

		// 次の要素へ
		element = xmlDocument_->NextSiblingElement();
	}
}



/*=========================================================================*/
/**
 * @brief 要素を作成
 * 
 * @param[in] elm 作成した要素を追加する要素( 親要素 ).
 * @param[out] source データを読み込むTinyXML要素クラス.
 * @return なし.
 */
void XMLDomParserTinyXML::createElement( Ngl::XML::XMLElement* elm, TiXmlElement* source )
{
	// 終端のノードに達した
	if( source == 0 ){
		return;
	}

	// 属性を作成
	createAttribute( elm, source );

	// 値が存在していれば設定
	const char* txt = source->GetText();
	if( txt != 0 ){
		elm->setText( txt );
	}

	// 子ノードを作成
	TiXmlElement* childElm = source->FirstChildElement();
	while( childElm != 0 ){
		Ngl::XML::XMLElement* tElm = new Ngl::XML::XMLElement( childElm->Value() );
	
		// 要素を作成する
		createElement( tElm, childElm );

		// 作成した要素を追加
		elm->addChild( tElm );

		// 次の要素へ
		childElm = childElm->NextSiblingElement();
	}
}

	
	
/*=========================================================================*/
/**
 * @brief 属性を作成
 * 
 * @param[in] elm 作成した属性を追加する要素.
 * @param[out] source データを読み込むTinyXML要素クラス.
 * @return なし.
 */
void XMLDomParserTinyXML::createAttribute( Ngl::XML::XMLElement* elm, TiXmlElement* source )
{
	// 属性が存在しているか
	TiXmlAttribute* attb = source->FirstAttribute();
	while( attb != 0 ){
		// 属性を追加
		elm->addAttribute( attb->Name(), attb->Value() );

		// 次の属性へ
		attb = attb->Next();
	}
}

	
	
/*===== EOF ==================================================================*/