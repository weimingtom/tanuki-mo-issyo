/*******************************************************************************/
/**
 * @file IEffectExtension.h.
 * 
 * @brief 拡張エフェクトインターフェース.
 *
 * @date 2008/07/11.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IEFFECTEXTENSION_H_
#define _NGL_IEFFECTEXTENSION_H_

#include	"Ngl/IEffectTechnique.h"
#include	"Ngl/IEffectParameter.h"
#include	"Ngl/IEffect.h"
#include	<string>

namespace Ngl{


/**
 * @interface IEffectExtension．
 * @brief エフェクト拡張インターフェース.
 */
class IEffectExtension
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IEffectExtension() {}


	/*=========================================================================*/
	/**
	 * @brief インデックスからテクニックを取得する
	 * 
	 * @param[in] index インデックス.
	 * @return エフェクトテクニックインターフェースのポインタ.
	 */
	virtual IEffectTechnique* getTechniqueByIndex( unsigned int index ) = 0;


	/*=========================================================================*/
	/**
	 * @brief テクニック名からテクニックを取得する
	 * 
	 * @param[in] name テクニック名.
	 * @return エフェクトテクニックインターフェースのポインタ.
	 */
	virtual IEffectTechnique* getTechniqueByName( const char* name ) = 0;


	/*=========================================================================*/
	/**
	 * @brief パラメータ名からパラメータを取得する
	 * 
	 * @param[in] name パラメータ名.
	 * @return エフェクトパラメータインターフェースのポインタ.
	 */
	virtual IEffectParameter* getParameterByName( const char* name ) = 0;


	/*=========================================================================*/
	/**
	 * @brief エフェクトインターフェースを取得する
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual IEffect* getEffect() = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/