/*******************************************************************************/
/**
 * @file InputSignatureDesc.h.
 * 
 * @brief 入力シグネチャ構造体定義.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_INPUT_SIGNATURE_DESC_H_
#define _NGL_INPUT_SIGNATURE_DESC_H_

namespace Ngl{


/**
 * @struct InputSignatureDesc.
 * @brief 入力シグネチャ記述子.
 */
struct InputSignatureDesc
{
	/** シグネチャ */
	void*			signature;

	/** シグネチャサイズ */
	unsigned int	size;
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/