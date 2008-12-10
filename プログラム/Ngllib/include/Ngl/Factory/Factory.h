/*******************************************************************************/
/**
 * @file Factory.h.
 * 
 * @brief 工場テンプレートクラス定義.
 *
 * @date 2008/11/02.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_FACTORY_H_
#define _NGL_FACTORY_H_

#include <map>
#include <string>


namespace Ngl{


/**
 * @class Factory.
 * @brief 工場テンプレートクラス.
 *
 * @tparam T 製品.
 * @tparam ID 製品ＩＤ.
 *
 * @warning 製品として追加するクラスには、"T* clone( void )"関数を持つクローン機能が必要です
 *
 * Ngl::IClonableクラスを使用すると、クローン関数に対応した関数名を強制することができます。<br>
 * Ngl/IClonable.hをインクルードしてください<br>
 */
template
<
	class T,
	class ID = std::string
>
class Factory
{

private:

	//製品コンテナクラス
	typedef std::map< ID, T* >	ProductContainer;

public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~Factory()
	{
		// 保持している製品を全て削除
		ProductContainer::iterator itor=productContainer_.begin();
		while( itor != productContainer_.end() ){
			delete itor->second;
			itor = productContainer_.erase( itor );
		}
	}

	
	/*=========================================================================*/
	/**
	 * @brief 製品の原型を追加
	 * 
	 * @param[in] id 追加する製品のＩＤ.
	 * @param[in] product 追加する製品.
	 * @return なし.
	 */
	void add( const ID& id, T* product )
	{
		productContainer_[ id ] = product;
	}

	
	/*=========================================================================*/
	/**
	 * @brief 製品を作成
	 * 
	 * @param[in] id 作成する製品のＩＤ.
	 * @return 作成した製品.
	 */
	T* create( const ID& id )
	{
		//指定された製品のクローンを作成
		return productContainer_[ id ]->clone();
	}

private:

	/** 製品コンテナ */
	ProductContainer productContainer_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/