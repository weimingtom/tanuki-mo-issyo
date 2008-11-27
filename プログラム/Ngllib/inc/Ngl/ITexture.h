/*******************************************************************************/
/**
 * @file ITexture.h.
 * 
 * @brief テクスチャインターフェース定義.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ITEXTURE_H_
#define _NGL_ITEXTURE_H_

#include	"TextureDesc.h"

namespace Ngl{


/**
 * @interface ITexture．
 * @brief テクスチャインターフェース.
 */
class ITexture
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~ITexture(){}

	
	/*=========================================================================*/
	/**
	 * @brief 記述子を取得する
	 * 
	 * @param[in] なし.
	 * @return テクスチャ記述子.
	 */
	virtual const TextureDesc& desc() const = 0;

	
	/*=========================================================================*/
	/**
	 * @brief テクスチャデータの設定
	 * 
	 * @param[in] data 設定するデータ.
	 * @return なし.
	 */
	virtual void setData( const void* data ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief テクスチャデータの取得
	 * 
	 * @param[out] data テクスチャデータを格納するデータ.
	 * @return なし.
	 */
	virtual void getData( void* data ) = 0;


	/*=========================================================================*/
	/**
	 * @brief イメージサイズの取得
	 * 
	 * @param[out] なし.
	 * @return イメージサイズ.
	 */
	virtual unsigned int size() const  = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/