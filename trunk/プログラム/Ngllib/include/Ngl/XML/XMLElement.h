/*******************************************************************************/
/**
 * @file XMLElement.h.
 * 
 * @brief XML要素クラスヘッダファイル.
 *
 * @date 2008/11/30.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_XML_XMLELEMENT_H_
#define _NGL_XML_XMLELEMENT_H_

#include	"XMLText.h"
#include	"Ngl/IXMLElement.h"
#include	<string>
#include	<map>
#include	<vector>

namespace Ngl{


namespace XML{


/**
 * @class XMLElement．
 * @brief XML要素クラス.
 */
class XMLElement : public IXMLElement
{
public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] name エレメント名.
	 */
	XMLElement( const char* name );
	
	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~XMLElement();


	/*=========================================================================*/
	/**
	 * @brief 子エレメントを追加
	 * 
	 * @param[in] child 追加する子エレメント.
	 * @return なし.
	 */
	void addChild( XMLElement* child );
	
	
	/*=========================================================================*/
	/**
	 * @brief 属性を追加
	 * 
	 * @param[in] name 追加する属性名.
	 * @param[in] attrib 追加する属性テキスト.
	 * @return なし.
	 */
	void addAttribute( const char* name, const char* attrib );
	
	
	/*=========================================================================*/
	/**
	 * @brief テキストを設定
	 * 
	 * @param[in] text 設定するテキスト.
	 * @return なし.
	 */
	void setText( const char* text );
	
	
	/*=========================================================================*/
	/**
	 * @brief 要素名を取得
	 * 
	 * @param[in] なし.
	 * @return 要素名.
	 */
	virtual const std::string& getElementName() const;
	
	
	/*=========================================================================*/
	/**
	 * @brief 名前から要素を取得
	 * 
	 * @param[in] name 値を取得する要素名.
	 * @return 取得した要素.
	 */
	virtual IXMLElement* getElementByName( const std::string& name );
	
	
	/*=========================================================================*/
	/**
	 * @brief インデックス番号から要素を取得
	 * 
	 * @param[in] index 値を取得する要素名.
	 * @return 取得した要素(範囲外の場合は0が返ります).
	 */
	virtual IXMLElement* getElementByIndex( int index );
	
	
	/*=========================================================================*/
	/**
	 * @brief 属性名から属性の値を取得
	 * 
	 * @param[in] name 値を取得する属性名.
	 * @return 取得した値 存在しない場合は空文字が返る.
	 */
	virtual const IXMLText& getAttribByName( const std::string& name );

	
	/*=========================================================================*/
	/**
	 * @brief 値を取得
	 *
	 * @param[in] なし.
	 * @return 取得した値.
	 */
	virtual const IXMLText& getValue() const;

	
	/*=========================================================================*/
	/**
	 * @brief 子要素を持っているか
	 * 
	 * @param[in] なし.
	 * @retval true 子要素が存在する.
	 * @retval false 子要素が存在しない.
	 */
	virtual bool isExistChildElement() const;

	
	/*=========================================================================*/
	/**
	 * @brief 属性を持っているか
	 * 
	 * @param[in] なし.
	 * @retval true 属性を持っている.
	 * @retval false 属性を持っていない.
	 */
	virtual bool isExistAttrib() const;

	
	/*=========================================================================*/
	/**
	 * @brief 値を持っているか
	 * 
	 * @param[in] なし.
	 * @retval true 値を持っている.
	 * @retval false 値を持っていない.
	 */
	virtual bool isExistValue() const;

	
	/*=========================================================================*/
	/**
	 * @brief 子要素数を取得
	 * 
	 * @param[in] なし.
	 * @return 子要素数.
	 */
	virtual unsigned int childElementCount() const;
	
	
	/*=========================================================================*/
	/**
	 * @brief 属性数を取得
	 * 
	 * @param[in] なし.
	 * @return 属性数.
	 */
	virtual unsigned int attribCount() const;

	
	/*=========================================================================*/
	/**
	 * @brief [] 演算子オーバーロード
	 * 
	 * nameで指定した子要素を取得する.
	 * 
	 * @param[in] name 取得する子要素名.
	 * @return 取得した子要素クラス.
	 */
	virtual IXMLElement* operator [] ( const std::string& name );


	/*=========================================================================*/
	/**
	 * @brief [] 演算子オーバーロード
	 * 
	 * nameで指定した子要素を取得する.
	 * 
	 * @param[in] index 取得する要素インデックス番号.
	 * @return 取得した子要素クラス( 範囲外の場合は0が返ります).
	 */
	virtual IXMLElement* operator [] ( int index );

private:

	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ ( コピー禁止 )
	 * 
	 * @param[in] other コピーするオブジェクト.
	 */
	XMLElement( const XMLElement& other );
	
	
	/*=========================================================================*/
	/**
	 * @brief = 演算子オーバーロード ( コピー禁止 )
	 * 
	 * @param[in] other 代入するオブジェクト.
	 * @return 代入結果のオブジェクト.
	 */
	XMLElement& operator = ( const XMLElement& other );

private:

	/** 要素コンテナ型 */
	typedef std::vector< XMLElement* >			ElementContainer;

	/** 属性コンテナ型 */
	typedef std::map< std::string, XMLText >	AttribContainer;

private:

	/** 要素コンテナ */
	ElementContainer	elementContainer_;

	/** 属性コンテナ */
	AttribContainer		attribContainer_;

	/** 要素名 */
	std::string			elementName_;

	/** 値 */
	Ngl::XML::XMLText	value_;

};

} // namespace XML

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/