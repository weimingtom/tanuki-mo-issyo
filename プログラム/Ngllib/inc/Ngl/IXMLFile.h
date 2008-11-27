/*******************************************************************************/
/**
 * @file IXMLFile.h.
 * 
 * @brief XMLファイルインターフェース.
 *
 * @date 2008/07/23.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IXMLFILE_H_
#define _NGL_IXMLFILE_H_

#include	"IXMLElement.h"
#include	<string>

namespace Ngl{


/**
 * @class IXMLFile．
 * @brief XMLファイルインターフェース.
 */
class IXMLFile
{
public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IXMLFile() {}


	/*=========================================================================*/
	/**
	 * @brief 名前から要素を取得
	 * 
	 * @param[in] name 取得する要素名.
	 * @return 取得した要素.
	 */
	virtual IXMLElement* getElementByName( const std::string name ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief インデックス番号から要素を取得
	 * 
	 * @param[in] index 取得する要素のインデックス番号.
	 * @return 取得した要素.
	 */
	virtual IXMLElement* getElementByIndex( unsigned int index ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief 要素数を取得
	 * 
	 * @param[in] なし.
	 * @return 取得した要素数.
	 */
	virtual unsigned int elementCount() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief [] 演算子オーバーロード
	 *
	 * nameで指定した要素を取得する.
	 * 
	 * @param[in] name 取得する要素名.
	 * @return 取得した要素.
	 */
	virtual IXMLElement* operator [] ( const std::string name ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/