/*******************************************************************************/
/**
 * @file EffectTechnique.h.
 * 
 * @brief エフェクトテクニッククラスヘッダファイル.
 *
 * @date 2007/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_EFFECTTECHNIQUE_H_
#define _NGL_EFFECTTECHNIQUE_H_

#include	"Ngl/EffectPass.h"
#include	"Ngl/IEffectTechnique.h"
#include	"Ngl/IEffect.h"
#include	<vector>

namespace Ngl{


/**
 * @class EffectTechnique．
 * @brief エフェクトテクニッククラス.
 */
	class EffectTechnique : public IEffectTechnique
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] effect エフェクトクラスのポインタ.
	 * @param[in] techniqueNo テクニック番号.
	 */
	EffectTechnique( IEffect* effect, unsigned int techniqueNo );


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~EffectTechnique();


	/*=========================================================================*/
	/**
	 * @brief パス数を取得する
	 * 
	 * @param[in] なし.
	 * @return パス数.
	 */
	virtual unsigned int numPass();


	/*=========================================================================*/
	/**
	 * @brief インデックスからパスを取得する
	 * 
	 * @param[in] index パスインデックス番号.
	 * @return パスクラスのポインタ.
	 */
	virtual IEffectPass* getPassByIndex( unsigned int index );


	/*=========================================================================*/
	/**
	 * @brief テクニック名を取得する
	 * 
	 * @param[in] なし.
	 * @return テクニック名.
	 */
	virtual const std::string& name() const;


	/*=========================================================================*/
	/**
	 * @brief テクニックを設定
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void setTechnique();

private:

	/** エフェクトパスコンテナ型 */
	typedef std::vector< EffectPass* >	EffectPassContainer;

private:

	/** エフェクトクラスのポインタ */
	IEffect*			effect_;

	/** テクニック番号 */
	unsigned int		techniqueNo_;

	/** テクニック名 */
	std::string			techniqueName_;

	/** エフェクトパスコンテナ */
	EffectPassContainer	passContainer_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/