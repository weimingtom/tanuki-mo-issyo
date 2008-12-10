/*******************************************************************************/
/**
 * @file XMLFile.h.
 * 
 * @brief XMLファイルクラスヘッダファイル.
 *
 * @date 2008/11/30.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_XML_XMLFILE_H_
#define _NGL_XML_XMLFILE_H_

#include	"Ngl/IXMLFile.h"
#include	<vector>

namespace Ngl{


namespace XML{


// XML要素クラス
class XMLElement;

/**
 * @class XMLFile．
 * @brief XMLファイルクラス.
 */
class XMLFile : public IXMLFile
{
public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	XMLFile();

	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~XMLFile();


	/*=========================================================================*/
	/**
	 * @brief 先頭のエレメントを追加
	 * 
	 * @param[in] elm 追加するエレメント.
	 * @return なし.
	 */
	void addElement( XMLElement* elm );
	
	
	/*=========================================================================*/
	/**
	 * @brief 名前から要素を取得
	 * 
	 * @param[in] name 取得する要素名.
	 * @return 取得した要素.
	 */
	virtual IXMLElement* getElementByName( const std::string name );

	
	/*=========================================================================*/
	/**
	 * @brief インデックス番号から要素を取得
	 * 
	 * @param[in] index 取得する要素のインデックス番号.
	 * @return 取得した要素.
	 */
	virtual IXMLElement* getElementByIndex( unsigned int index );

	
	/*=========================================================================*/
	/**
	 * @brief 要素数を取得
	 * 
	 * @param[in] なし.
	 * @return 取得した要素数.
	 */
	virtual unsigned int elementCount();

	
	/*=========================================================================*/
	/**
	 * @brief [] 演算子オーバーロード
	 *
	 * nameで指定した要素を取得する.
	 * 
	 * @param[in] name 取得する要素名.
	 * @return 取得した要素.
	 */
	virtual IXMLElement* operator [] ( const std::string name );

private:

	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ ( コピー禁止 )
	 * 
	 * @param[in] other コピーするオブジェクト.
	 */
	XMLFile( const XMLFile& other );
	
	
	/*=========================================================================*/
	/**
	 * @brief = 演算子オーバーロード ( コピー禁止 )
	 * 
	 * @param[in] other 代入するオブジェクト.
	 * @return 代入結果のオブジェクト.
	 */
	XMLFile& operator = ( const XMLFile& other );

private:

	/** 要素コンテナ型 */
	typedef std::vector< XMLElement* >	ElementContainer;

private:

	/** エレメントコンテナ */
	ElementContainer	elementContainer_;

};

} // namespace XML

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/