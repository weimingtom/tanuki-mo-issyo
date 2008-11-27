/*******************************************************************************/
/**
 * @file EffectExtension.cpp.
 * 
 * @brief 拡張エフェクトクラスソースファイル.
 *
 * @date 2008/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/EffectExtension.h"
#include	<cassert>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] fileName ファイル名.
 * @param[in] renderer レンダラークラスのポインタ.
 */
EffectExtension::EffectExtension( const char* fileName, IRenderer* renderer ):
	effect_( 0 ),
	isDelete_( true )
{
	// エフェクトを作成
	effect_ = renderer->createEffect( fileName );
	assert( effect_ != 0 );

	// 作成処理を呼ぶ
	create();
}



/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] effect エフェクトクラスのポインタ.
 * @param[in] isDelete 設定したエフェクトクラスを削除するか
 */
EffectExtension::EffectExtension( IEffect* effect, bool isDelete ):
	effect_( effect ),
	isDelete_( isDelete )
{
	assert( effect != 0 );

	// 作成処理を呼ぶ
	create();
}

	
	
/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
EffectExtension::~EffectExtension()
{
	// パラメータコンテナを解放
	ParameterContainer::iterator paramItor = parameterContainer_.begin();
	while( paramItor != parameterContainer_.end() ){
		delete *paramItor;
		paramItor = parameterContainer_.erase( paramItor );
	}

	// テクニックコンテナを解放
	TechniqueContainer::iterator tecItor = techniqueContainer_.begin();
	while( tecItor != techniqueContainer_.end() ){
		delete *tecItor;
		tecItor = techniqueContainer_.erase( tecItor );
	}

	// エフェクトを削除
	if( isDelete_ == true ){
		delete effect_;
	}
	else{
		effect_ = 0;
	}
}



/*=========================================================================*/
/**
 * @brief インデックスからテクニックを取得する
 * 
 * @param[in] index インデックス.
 * @return エフェクトテクニックインターフェースのポインタ.
 */
IEffectTechnique* EffectExtension::getTechniqueByIndex( unsigned int index )
{
	return techniqueContainer_[ index ];
}



/*=========================================================================*/
/**
 * @brief テクニック名からテクニックを取得する
 * 
 * @param[in] name テクニック名.
 * @return エフェクトテクニックインターフェースのポインタ.
 */
IEffectTechnique* EffectExtension::getTechniqueByName( const char* name )
{
	for( int i=0; i<effect_->getNumTechnique(); ++i ){
		if( techniqueContainer_[ i ]->name() == name ){
			return techniqueContainer_[ i ];
		}
	}
	assert( false );
	return 0;
}



/*=========================================================================*/
/**
 * @brief パラメータ名からパラメータを取得する
 * 
 * @param[in] name パラメータ名.
 * @return エフェクトパラメータインターフェースのポインタ.
 */
IEffectParameter* EffectExtension::getParameterByName( const char* name )
{
	for( int i=0; i<effect_->getNumParameter(); ++i ){
		if( parameterContainer_[ i ]->name() == name ){
			return parameterContainer_[ i ];
		}
	}
	assert( false );
	return 0;
}



/*=========================================================================*/
/**
 * @brief エフェクトインターフェースを取得する
 * 
 * @param[in] なし.
 * @return なし.
 */
IEffect* EffectExtension::getEffect()
{
	return effect_;
}
	
	

/*=========================================================================*/
/**
 * @brief 作成処理
 * 
 * @param[in] なし.
 * @return なし.
 */
void EffectExtension::create()
{
	// テクニックを作成
	int tecCount = effect_->getNumTechnique();
	for( int i=0; i<tecCount; ++i ){
		EffectTechnique* tec = new EffectTechnique( effect_, i );
		techniqueContainer_.push_back( tec );
	}

	// パラメータを作成する
	int paramCount =effect_->getNumParameter(); 
	for( int i=0; i<paramCount; ++i ){
		EffectParameter* param = new EffectParameter( effect_, effect_->getParameterName( i ) );
		parameterContainer_.push_back( param );
	}
}
	
	
	
/*===== EOF ==================================================================*/