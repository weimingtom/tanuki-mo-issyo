/*******************************************************************************/
/**
 * @file IEffectMatrixParameter.h.
 * 
 * @brief エフェクト行列パラメーターインターフェース定義.
 *
 * @date 2008/07/12.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IEFFECTMATRIXPARAMETER_H_
#define _NGL_IEFFECTMATRIXPARAMETER_H_

#include	"Ngl/Matrix4.h"

namespace Ngl{


/**
 * @interface IEffectMatrixParameter．
 * @brief エフェクト行列パラメーターインターフェース.
 */
class IEffectMatrixParameter
{

protected:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IEffectMatrixParameter() {}

public:

	/*=========================================================================*/
	/**
	 * @brief 4x4行列を設定する
	 * 
	 * @param[in] matrix 設定する4x4行列構造体.
	 * @return なし.
	 */
	virtual void setMatrix( const Matrix4& matrix ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 4x4行列の配列を設定する
	 * 
	 * @param[in] matrix 設定する4x4行列構造体配列の先頭ポインタ.
	 * @param[in] count 要素数
	 * @return なし.
	 */
	virtual void setMatrixArray( const Matrix4* matrix, unsigned int count ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/