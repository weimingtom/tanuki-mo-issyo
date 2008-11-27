/*******************************************************************************/
/**
 * @file IEffectTechnique.h.
 * 
 * @brief エフェクトテクニックインターフェース定義.
 *
 * @date 2008/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IEFFECTTECHNIQUE_H_
#define _NGL_IEFFECTTECHNIQUE_H_

#include	"IEffectPass.h"
#include	<string>

namespace Ngl{


/**
 * @interface IEffectTechnique．
 * @brief エフェクトテクニックインターフェース.
 */
class IEffectTechnique
{

protected:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IEffectTechnique() {}

public:

	/*=========================================================================*/
	/**
	 * @brief パス数を取得する
	 * 
	 * @param[in] なし.
	 * @return パス数.
	 */
	virtual unsigned int numPass() = 0;


	/*=========================================================================*/
	/**
	 * @brief インデックスからパスを取得する
	 * 
	 * @param[in] index パスインデックス番号.
	 * @return パスクラスのポインタ.
	 */
	virtual IEffectPass* getPassByIndex( unsigned int index ) = 0;


	/*=========================================================================*/
	/**
	 * @brief テクニック名を取得する
	 * 
	 * @param[in] なし.
	 * @return テクニック名.
	 */
	virtual const std::string& name() const = 0;


	/*=========================================================================*/
	/**
	 * @brief テクニックを設定
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void setTechnique() = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/