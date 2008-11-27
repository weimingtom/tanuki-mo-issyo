/*******************************************************************************/
/**
 * @file IBuffer.h.
 * 
 * @brief バッファインターフェース定義.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IBUFFER_H_
#define	_NGL_IBUFFER_H_

#include	"BufferDesc.h"

namespace Ngl{


/**
 * @interface IBuffer．
 * @brief バッファインターフェース.
 */
class IBuffer
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IBuffer(){}

	
	/*=========================================================================*/
	/**
	 * @brief 記述子を取得する
	 * 
	 * @param[in] なし.
	 * @return バッファ記述子.
	 */
	virtual const BufferDesc& desc() const = 0;

	
	/*=========================================================================*/
	/**
	 * @brief バッファデータの設定
	 * 
	 * @param[in] data 設定するデータ.
	 * @return なし.
	 */
	virtual void setData( const void* data ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief バッファデータの取得
	 * 
	 * @param[out] data バッファデータを格納するデータ.
	 * @return なし.
	 */
	virtual void getData( void* data ) const = 0;

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/