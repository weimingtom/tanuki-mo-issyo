/*******************************************************************************/
/**
 * @file IEffectVectorParameter.h.
 * 
 * @brief エフェクトベクトルパラメータインターフェース定義.
 *
 * @date 2008/07/11.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IEFFECTVECTORVARIABLE_H_
#define _NGL_IEFFECTVECTORVARIABLE_H_

#include	"Ngl/Vector2.h"
#include	"Ngl/Vector3.h"
#include	"Ngl/Vector4.h"

namespace Ngl{


/**
 * @interface IEffectVectorParameter．
 * @brief エフェクトベクトルパラメータインターフェース.
 */
class IEffectVectorParameter
{

protected:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IEffectVectorParameter() {}

public:

	/*=========================================================================*/
	/**
	 * @brief 2次元ベクトルを設定する
	 * 
	 * @param[in] v2 設定する2次元ベクトル構造体.
	 * @return なし.
	 */
	virtual void setVector2( const Vector2& v2 ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 2次元ベクトルの配列を設定する
	 * 
	 * @param[in] v2 設定する2次元ベクトル構造体配列の先頭ポインタ.
	 * @param[in] count 配列の要素数
	 * @return なし.
	 */
	virtual void setVector2Array( const Vector2& v2, unsigned int count ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 3次元ベクトルを設定する
	 * 
	 * @param[in] v3 設定する3次元ベクトル構造体.
	 * @return なし.
	 */
	virtual void setVector3( const Vector3& v3 ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 3次元ベクトルの配列を設定する
	 * 
	 * @param[in] v3 設定する3次元ベクトル構造体配列の先頭ポインタ.
	 * @param[in] count 配列の要素数
	 * @return なし.
	 */
	virtual void setVector3Array( const Vector3& v3, unsigned int count ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 4次元ベクトルを設定する
	 * 
	 * @param[in] v4 設定する4次元ベクトル構造体.
	 * @return なし.
	 */
	virtual void setVector4( const Vector4& v4 ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 4次元ベクトルの配列を設定する
	 * 
	 * @param[in] v4 設定する4次元ベクトル構造体配列の先頭ポインタ.
	 * @param[in] count 配列の要素数
	 * @return なし.
	 */
	virtual void setVector4Array( const Vector4& v4, unsigned int count ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/