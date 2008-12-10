/*******************************************************************************/
/**
 * @file XMLDomParserTinyXML.h.
 * 
 * @brief TinyXML DOM方式XMLパーサクラスヘッダファイル.
 *
 * @date 2007/12/03.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_TINYXML_XMLDOMPARSERTINYXML_H_
#define _NGL_TINYXML_XMLDOMPARSERTINYXML_H_

#include	"Ngl/XML/XMLFile.h"
#include	"Ngl/XML/XMLElement.h"

// TinyXML ドキュメントクラス
class TiXmlDocument;

// TinyXML エレメントクラス
class TiXmlElement;


namespace Ngl{


namespace TinyXML{


/**
 * @class XMLDomParserTinyXML．
 * @brief TinyXML DOM方式XMLパーサクラス.
 */
class XMLDomParserTinyXML
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	XMLDomParserTinyXML();


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~XMLDomParserTinyXML();


	/*=========================================================================*/
	/**
	 * @brief ファイルからデータを読み込む
	 * 
	 * @param[in] name ファイル名.
	 * @param[out] file データを読み込むXMLFileクラス.
	 * @return なし.
	 */
	void load( const std::string& name, Ngl::XML::XMLFile& file );

private:

	/*=========================================================================*/
	/**
	 * @brief 要素を作成
	 * 
	 * @param[in] elm 作成した要素を追加する要素( 親要素 ).
	 * @param[out] source データを読み込むTinyXML要素クラス.
	 * @return なし.
	 */
	void createElement( Ngl::XML::XMLElement* elm, TiXmlElement* source );

	
	/*=========================================================================*/
	/**
	 * @brief 属性を作成
	 * 
	 * @param[in] elm 作成した属性を追加する要素.
	 * @param[out] source データを読み込むTinyXML要素クラス.
	 * @return なし.
	 */
	void createAttribute( Ngl::XML::XMLElement* elm, TiXmlElement* source );

private:

	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ ( コピー禁止 )
	 * 
	 * @param[in] other コピーするオブジェクト.
	 */
	XMLDomParserTinyXML( const XMLDomParserTinyXML& other );
	
	
	/*=========================================================================*/
	/**
	 * @brief = 演算子オーバーロード ( コピー禁止 )
	 * 
	 * @param[in] other 代入するオブジェクト.
	 * @return 代入結果のオブジェクト.
	 */
	XMLDomParserTinyXML& operator = ( const XMLDomParserTinyXML& other );

private:

	/** XML文書 */
	TiXmlDocument*	xmlDocument_;

};

} // namespace TinyXML

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/