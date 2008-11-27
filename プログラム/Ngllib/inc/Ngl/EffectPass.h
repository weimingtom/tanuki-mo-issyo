/*******************************************************************************/
/**
 * @file EffectPass.h.
 * 
 * @brief エフェクトパスクラスヘッダファイル.
 *
 * @date 2008/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_EFFECTPASS_H_
#define _NGL_EFFECTPASS_H_

#include	"IEffectPass.h"
#include	"IEffect.h"
#include	<string>


namespace Ngl{


/**
 * @class EffectPass．
 * @brief エフェクトパスクラス.
 */
class EffectPass : public IEffectPass
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] effect エフェクトクラスのポインタ.
	 * @param[in] techniqueName テクニック名.
	 * @param[in] passNo パス番号.
	 */
	EffectPass( IEffect* effect, const std::string& techniqueName, unsigned int passNo );


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~EffectPass();


	/*=========================================================================*/
	/**
	 * @brief パスを開始する
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void begin();


	/*=========================================================================*/
	/**
	 * @brief パスを終了する
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void end();


	/*=========================================================================*/
	/**
	 * @brief 入力シグネチャ記述子を取得する
	 * 
	 * @param[in] なし.
	 * @return 入力シグネチャ記述子.
	 */
	virtual const InputSignatureDesc inputSignature();

private:

	/** パス番号 */
	unsigned int		passNo_;

	/** テクニック名 */
	std::string			techniqueName_;

	/** エフェクトクラスのポインタ */
	IEffect*			effect_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/