/*******************************************************************************/
/**
 * @file EffectTechnique.cpp.
 * 
 * @brief エフェクトテクニッククラスソースファイル.
 *
 * @date 2007/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/EffectTechnique.h"
#include	<cassert>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] effect エフェクトクラスのポインタ.
 * @param[in] techniqueNo テクニック番号.
 */
EffectTechnique::EffectTechnique( IEffect* effect, unsigned int techniqueNo ):
	effect_( effect ),
	techniqueNo_( techniqueNo )
{
	assert( effect_ != NULL );

	// テクニック名を設定
	techniqueName_ = effect_->getTechniqueName( techniqueNo_ );

	// テクニックを設定
	effect_->technique( techniqueName_.c_str() );

	// エフェクトパスを作成
	for( int pass=0; pass<effect_->getNumPass(); ++pass ){
		EffectPass* tPass = new EffectPass( effect_, techniqueName_.c_str(), pass );
		passContainer_.push_back( tPass );
	}
}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
EffectTechnique::~EffectTechnique()
{
	// パスを全削除
	EffectPassContainer::iterator itor = passContainer_.begin();
	while( itor != passContainer_.end() ){
		delete *itor;
		itor = passContainer_.erase( itor );
	}
}



/*=========================================================================*/
/**
 * @brief パス数を取得する
 * 
 * @param[in] なし.
 * @return パス数.
 */
unsigned int EffectTechnique::numPass()
{
	return effect_->getNumPass();
}



/*=========================================================================*/
/**
 * @brief インデックスからパスを取得する
 * 
 * @param[in] index パスインデックス番号.
 * @return パスクラスのポインタ.
 */
IEffectPass* EffectTechnique::getPassByIndex( unsigned int index )
{
	return passContainer_[ index ];
}



/*=========================================================================*/
/**
 * @brief テクニック名を取得する
 * 
 * @param[in] なし.
 * @return テクニック名.
 */
const std::string& EffectTechnique::name() const
{
	return techniqueName_;
}



/*=========================================================================*/
/**
 * @brief テクニックを設定
 * 
 * @param[in] なし.
 * @return なし.
 */
void EffectTechnique::setTechnique()
{
	effect_->technique( name().c_str() );
}


	
/*===== EOF ==================================================================*/