/*******************************************************************************/
/**
 * @file EffectPass.cpp.
 * 
 * @brief エフェクトパスクラスソースファイル.
 *
 * @date 2008/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/EffectPass.h"
#include	<cassert>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] effect エフェクトクラスのポインタ.
 * @param[in] techniqueName テクニック名.
 * @param[in] passNo パス番号.
 */
EffectPass::EffectPass( IEffect* effect, const std::string& techniqueName, unsigned int passNo ):
	effect_( effect ),
	techniqueName_( techniqueName ),
	passNo_( passNo )
{
	assert( effect_ != NULL );
}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
EffectPass::~EffectPass()
{
	effect_ = 0;
}



/*=========================================================================*/
/**
 * @brief パスを開始する
 * 
 * @param[in] なし.
 * @return なし.
 */
void EffectPass::begin()
{
	// テクニックを設定
	effect_->technique( techniqueName_.c_str() );

	//　パスを開始する
	effect_->begin( passNo_ );
}



/*=========================================================================*/
/**
 * @brief パスを終了する
 * 
 * @param[in] なし.
 * @return なし.
 */
void EffectPass::end()
{
	effect_->end();
}



/*=========================================================================*/
/**
 * @brief 入力シグネチャ記述子を取得する
 * 
 * @param[in] なし.
 * @return 入力シグネチャ記述子.
 */
const InputSignatureDesc EffectPass::inputSignature()
{
	return effect_->inputSigneture( techniqueName_.c_str(), passNo_ );
}



/*===== EOF ==================================================================*/