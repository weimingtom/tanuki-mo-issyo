/*******************************************************************************/
/**
 * @file IEffectPass.h.
 * 
 * @brief エフェクトパスインターフェース定義.
 *
 * @date 2008/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IEFFECTPASS_H_
#define _NGL_IEFFECTPASS_H_

#include	"Ngl/InputSignatureDesc.h"

namespace Ngl{


/**
 * @interface IEffectPass．
 * @brief エフェクトパスインターフェース.
 */
class IEffectPass
{
protected:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IEffectPass() {}

public:

	/*=========================================================================*/
	/**
	 * @brief パスを開始する
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void begin() = 0;


	/*=========================================================================*/
	/**
	 * @brief パスを終了する
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void end() = 0;


	/*=========================================================================*/
	/**
	 * @brief 入力シグネチャ記述子を取得する
	 * 
	 * @param[in] なし.
	 * @return 入力シグネチャ記述子.
	 */
	virtual const InputSignatureDesc inputSignature() = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/