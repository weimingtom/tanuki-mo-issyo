/*******************************************************************************/
/**
 * @file EffectExtension.h.
 * 
 * @brief 拡張エフェクトクラスヘッダファイル.
 *
 * @date 2008/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_EFFECTEXTENSION_H_
#define _NGL_EFFECTEXTENSION_H_

#include	"Ngl/EffectTechnique.h"
#include	"Ngl/EffectParameter.h"
#include	"Ngl/IEffectExtension.h"
#include	"Ngl/IEffect.h"
#include	"Ngl/IRenderer.h"
#include	<string>
#include	<vector>

namespace Ngl{


/**
 * @class EffectExtension．
 * @brief エフェクト拡張クラス.
 */
class EffectExtension : public IEffectExtension
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] fileName ファイル名.
	 * @param[in] renderer レンダラークラスのポインタ.
	 */
	EffectExtension( const char* fileName, IRenderer* renderer );


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] effect エフェクトクラスのポインタ.
	 * @param[in] isDelete 設定したエフェクトクラスを削除するか
	 */
	EffectExtension( IEffect* effect, bool isDelete );
	
	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~EffectExtension();


	/*=========================================================================*/
	/**
	 * @brief インデックスからテクニックを取得する
	 * 
	 * @param[in] index インデックス.
	 * @return エフェクトテクニックインターフェースのポインタ.
	 */
	virtual IEffectTechnique* getTechniqueByIndex( unsigned int index );


	/*=========================================================================*/
	/**
	 * @brief テクニック名からテクニックを取得する
	 * 
	 * @param[in] name テクニック名.
	 * @return エフェクトテクニックインターフェースのポインタ.
	 */
	virtual IEffectTechnique* getTechniqueByName( const char* name );


	/*=========================================================================*/
	/**
	 * @brief パラメータ名からパラメータを取得する
	 * 
	 * @param[in] name パラメータ名.
	 * @return エフェクトパラメータインターフェースのポインタ.
	 */
	virtual IEffectParameter* getParameterByName( const char* name );


	/*=========================================================================*/
	/**
	 * @brief エフェクトインターフェースを取得する
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual IEffect* getEffect();

private:

	/*=========================================================================*/
	/**
	 * @brief 作成処理
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void create();

private:

	/** テクニックコンテナ型 */
	typedef std::vector< EffectTechnique* >	TechniqueContainer;

	/** パラメータコンテナ型 */
	typedef std::vector< EffectParameter* >	ParameterContainer;

private:

	/** エフェクト */
	IEffect*				effect_;

	/** テクニックコンテナ */
	TechniqueContainer		techniqueContainer_;

	/** パラメータコンテナ */
	ParameterContainer		parameterContainer_;

	/** インスタンスを削除するか */
	bool					isDelete_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/