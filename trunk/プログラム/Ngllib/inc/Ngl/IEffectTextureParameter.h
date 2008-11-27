/*******************************************************************************/
/**
 * @file IEffectTextureParameter.h.
 * 
 * @brief エフェクトテクスチャパラメータインターフェース定義.
 *
 * @date 2008/07/12.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IEFFECTTEXTUREPARAMETER_H_
#define _NGL_IEFFECTTEXTUREPARAMETER_H_

#include	"Ngl/ITexture.h"

namespace Ngl{


/**
 * @interface IEffectTextureParameter．
 * @brief エフェクトテクスチャパラメータインターフェース.
 */
class IEffectTextureParameter
{

protected:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IEffectTextureParameter() {}

public:

	/*=========================================================================*/
	/**
	 * @brief テクスチャパラメータを設定
	 * 
	 * @param[in] texture 設定するテクスチャインターフェースのポインタ.
	 * @return なし.
	 */
	virtual void setTexture( ITexture* texture ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/