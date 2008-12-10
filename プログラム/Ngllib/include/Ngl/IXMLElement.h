/*******************************************************************************/
/**
 * @file IXMLElement.h.
 * 
 * @brief XML要素インターフェース定義.
 *
 * @date 2008/07/23.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IXMLELEMENT_H_
#define _NGL_IXMLELEMENT_H_

#include	"IXMLText.h"
#include	<string>

namespace Ngl{


/**
 * @interface IXMLElement．
 * @brief XML要素インターフェース.
 */
class IXMLElement
{
protected:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IXMLElement() {}

public:

	/*=========================================================================*/
	/**
	 * @brief 名前から子要素を取得
	 * 
	 * @param[in] name 値を取得する要素名.
	 * @return 取得した要素.
	 */
	virtual IXMLElement* getElementByName( const std::string& name ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief インデックス番号から要素を取得
	 * 
	 * @param[in] index 値を取得する要素名.
	 * @return 取得した要素(範囲外の場合は0が返ります).
	 */
	virtual IXMLElement* getElementByIndex( int index ) = 0;
	

	/*=========================================================================*/
	/**
	 * @brief 属性名から属性の値を取得
	 * 
	 * @param[in] name 値を取得する属性名.
	 * @return 取得した値 存在しない場合は空文字が返る.
	 */
	virtual const IXMLText& getAttribByName( const std::string& name ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief 値を取得
	 *
	 * @param[in] なし.
	 * @return 取得した値.
	 */
	virtual const IXMLText& getValue() const = 0;

	
	/*=========================================================================*/
	/**
	 * @brief 子要素を持っているか
	 * 
	 * @param[in] なし.
	 * @retval true 子要素が存在する.
	 * @retval false 子要素が存在しない.
	 */
	virtual bool isExistChildElement() const = 0;

	
	/*=========================================================================*/
	/**
	 * @brief 属性を持っているか
	 * 
	 * @param[in] なし.
	 * @retval true 属性を持っている.
	 * @retval false 属性を持っていない.
	 */
	virtual bool isExistAttrib() const = 0;

	
	/*=========================================================================*/
	/**
	 * @brief 値を持っているか
	 * 
	 * @param[in] なし.
	 * @retval true 値を持っている.
	 * @retval false 値を持っていない.
	 */
	virtual bool isExistValue() const = 0;

	
	/*=========================================================================*/
	/**
	 * @brief 子要素数を取得
	 * 
	 * @param[in] なし.
	 * @return 子要素数.
	 */
	virtual unsigned int childElementCount() const = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 属性数を取得
	 * 
	 * @param[in] なし.
	 * @return 属性数.
	 */
	virtual unsigned int attribCount() const = 0;

	
	/*=========================================================================*/
	/**
	 * @brief [] 演算子オーバーロード
	 * 
	 * nameで指定した子要素を取得する.
	 * 
	 * @param[in] name 取得する子要素名.
	 * @return 取得した子要素クラス.
	 */
	virtual IXMLElement* operator [] ( const std::string& name ) = 0;


	/*=========================================================================*/
	/**
	 * @brief [] 演算子オーバーロード
	 * 
	 * nameで指定した子要素を取得する.
	 * 
	 * @param[in] index 取得する要素インデックス番号.
	 * @return 取得した子要素クラス( 範囲外の場合は0が返ります).
	 */
	virtual IXMLElement* operator [] ( int index ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/