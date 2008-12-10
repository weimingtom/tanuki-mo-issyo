/*******************************************************************************/
/**
 * @file IXMLText.h.
 * 
 * @brief XMLテキストインターフェース定義.
 *
 * @date 2008/11/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IXMLTEXT_H_
#define _NGL_IXMLTEXT_H_

#include	<string>
#include	<vector>

namespace Ngl{


/**
 * @interface IXMLText．
 * @brief XMLテキストインターフェース.
 */
class IXMLText
{
public:

	/** XML String値配列型 */
	typedef std::vector< std::string >	StringArray;

	/** XML int値配列型 */
	typedef std::vector< int >			IntArray;

	/** XML float値配列 */
	typedef std::vector< float >		FloatArray;

public:
	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IXMLText() {}

	
	/*=========================================================================*/
	/**
	 * @brief テキストを保持しているか
	 * 
	 * @param[in]なし.
	 * @retval true 保持している.
	 * @retval false 保持していない.
	 */
	virtual bool hasText() const = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief テキストを文字列で取得する
	 * 
	 * @param[in] なし.
	 * @return テキスト.
	 */
	virtual const std::string& getText() const = 0;


	/*=========================================================================*/
	/**
	 * @brief テキストをint型の数値で取得する
	 * 
	 * @param[in] なし.
	 * @return テキスト.
	 */
	virtual int getTextInt() const = 0;


	/*=========================================================================*/
	/**
	 * @brief テキストをfloat型の数値で取得する
	 * 
	 * @param[in] なし.
	 * @return テキスト.
	 */
	virtual float getTextFloat() const = 0;


	/*=========================================================================*/
	/**
	 * @brief テキストを文字列配列で取得する
	 * 
	 * @param[out] array XML文字列型配列.
	 * @return なし.
	 */
	virtual void getArray( StringArray& array ) const = 0;


	/*=========================================================================*/
	/**
	 * @brief テキストをint型配列で取得する
	 * 
	 * @param[out] array XMLint型配列.
	 * @return テキスト.
	 */
	virtual void getArray( IntArray& array ) const = 0;


	/*=========================================================================*/
	/**
	 * @brief テキストをfloat型配列で取得する
	 * 
	 * @param[out] array XMLfloat型配列.
	 * @return テキスト.
	 */
	virtual void getArray( FloatArray& array ) const = 0;

};


} // namespace Ngl

#endif

/*===== EOF ==================================================================*/