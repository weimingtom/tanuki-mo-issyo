/*******************************************************************************/
/**
 * @file IEffectParameter.h.
 * 
 * @brief エフェクトパラメータインターフェース定義.
 *
 * @date 2008/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IEFFECTPARAMETER_H_
#define _NGL_IEFFECTPARAMETER_H_

#include	"Ngl/IEffectScalarParameter.h"
#include	"Ngl/IEffectVectorParameter.h"
#include	"Ngl/IEffectMatrixParameter.h"
#include	"Ngl/IEffectTextureParameter.h"
#include	<string>

namespace Ngl{


/**
 * @interface IEffectParameter．
 * @brief エフェクトパラメータインターフェース.
 */
class IEffectParameter
{
protected:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IEffectParameter() {}

public:

	/*=========================================================================*/
	/**
	 * @brief パラメータ名を取得
	 * 
	 * @param[in] なし.
	 * @return パラメータ名.
	 */
	virtual const std::string& name() const = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief スカラーパラメータインターフェースを取得
	 * 
	 * @param[in] なし.
	 * @return スカラーパラメータインターフェースのポインタ.
	 */
	virtual IEffectScalarParameter* asScalar() = 0;


	/*=========================================================================*/
	/**
	 * @brief ベクトルパラメータインターフェースを取得
	 * 
	 * @param[in] なし.
	 * @return ベクトルパラメータインターフェースのポインタ.
	 */
	virtual IEffectVectorParameter* asVector() = 0;


	/*=========================================================================*/
	/**
	 * @brief 行列パラメータインターフェースを取得
	 * 
	 * @param[in] なし.
	 * @return 行列パラメータインターフェースのポインタ.
	 */
	virtual IEffectMatrixParameter* asMatrix() = 0;


	/*=========================================================================*/
	/**
	 * @brief テクスチャパラメータインターフェースを取得
	 * 
	 * @param[in] なし.
	 * @return テクスチャパラメータインターフェースのポインタ.
	 */
	virtual IEffectTextureParameter* asTexture() = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/