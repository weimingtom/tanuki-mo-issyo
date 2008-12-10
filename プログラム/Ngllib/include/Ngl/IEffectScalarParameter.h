/*******************************************************************************/
/**
 * @file IEffectScalarParameter.h.
 * 
 * @brief エフェクトスカラーパラメータインターフェース定義.
 *
 * @date 2008/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IEFFECTSCALARPARAMETER_H_
#define _NGL_IEFFECTSCALARPARAMETER_H_

#include	"Ngl/Color4.h"

namespace Ngl{


/**
 * @interface IEffectScalarParameter．
 * @brief エフェクトスカラーパラメータインターフェース.
 */
class IEffectScalarParameter
{
protected:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IEffectScalarParameter() {}

public:

	/*=========================================================================*/
	/**
	 * @brief int型のパラメータを設定
	 * 
	 * @param[in] v 設定するパラメータ.
	 * @return なし.
	 */
	virtual void setInt( int v ) = 0;


	/*=========================================================================*/
	/**
	 * @brief int型配列のパラメータを設定
	 * 
	 * @param[in] v 設定する配列パラメータの先頭ポインタ.
	 * @param[in] count 要素数.
	 * @return なし.
	 */
	virtual void setIntArray( const int* v, unsigned int count ) = 0;


	/*=========================================================================*/
	/**
	 * @brief float型のパラメータを設定
	 * 
	 * @param[in] v 設定するパラメータ.
	 * @return なし.
	 */
	virtual void setFloat( float v ) = 0;


	/*=========================================================================*/
	/**
	 * @brief float型配列のパラメータを設定
	 * 
	 * @param[in] v 設定する配列パラメータの先頭ポインタ.
	 * @param[in] count 要素数.
	 * @return なし.
	 */
	virtual void setFloatArray( const float* v, unsigned int count ) = 0;


	/*=========================================================================*/
	/**
	 * @brief RGBAカラー構造体のパラメータを設定
	 * 
	 * @param[in] color 設定するRGBAカラー構造体パラメータ.
	 * @return なし.
	 */
	virtual void setColor( const Color4& color ) = 0;


	/*=========================================================================*/
	/**
	 * @brief RGBAカラー構造体配列のパラメータを設定
	 * 
	 * @param[in] color 設定するRGBAカラー配列パラメータの先頭ポインタ.
	 * @param[in] count 要素数.
	 * @return なし.
	 */
	virtual void setColorArray( const Color4* color, unsigned int count ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/