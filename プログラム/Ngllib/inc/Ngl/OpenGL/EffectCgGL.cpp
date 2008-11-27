/*******************************************************************************/
/**
 * @file EffectCgGL.cpp.
 * 
 * @brief OpenGL Cgfxエフェクトクラスソースファイル.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"EffectCgGL.h"
#include	"TextureGL.h"
#include	<iostream>
#include	<cassert>

using namespace Ngl;
using namespace Ngl::OpenGL;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] fileName ファイル名.
 */
EffectCgGL::EffectCgGL( const char* fileName ):
	context_( 0 ),
	effect_( 0 ),
	technique_( 0 ),
	pass_( 0 )
{
	// コンテキストを作成
	context_ = cgCreateContext();
	assert( context_ != 0 );

	// コンテキストをOpenGLに設定
	cgGLRegisterStates( context_ );

	// エフェクトを読み込む
	effect_ = cgCreateEffectFromFile( context_, fileName, NULL );
	if( effect_ == 0 ){
		// エラーメッセージを出力する
		const char* listing = cgGetLastListing( context_ );
		if( listing != 0 ){
			std::cout << "Error" << fileName << " : " << listing;
		}
	}
	assert( effect_ != 0 );
}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
EffectCgGL::~EffectCgGL()
{
	// エフェクトを削除
	if( cgIsEffect( effect_ ) == CG_TRUE ){
		cgDestroyEffect( effect_ );
	}

	// コンテキストを削除
	if( cgIsContext( context_ ) == CG_TRUE ){
		cgDestroyContext( context_ );
	}
}



/*=========================================================================*/
/**
 * @brief テクニックを開始
 * 
 * @param[in] techniqueName テクニック名.
 * @return なし.
 */
void EffectCgGL::technique( const char* techniqueName )
{
	// テクニックを取得する
	technique_ = cgGetNamedTechnique( effect_, techniqueName );
}



/*=========================================================================*/
/**
 * @brief パスを開始
 * 
 * @param[in] passNo パス番号.
 * @return なし.
 */
void EffectCgGL::begin( int passNo )
{
	// 最初のパスを取得する
	pass_ = cgGetFirstPass( technique_ );

	// 指定のパスを検索
	for( int n=0; n<passNo; ++n ){
		pass_ = cgGetNextPass( pass_ );
	}

	// パスを有効にする
	cgSetPassState( pass_ );
}



/*=========================================================================*/
/**
 * @brief パスを終了
 * 
 * @param[in] なし.
 * @return なし.
 */
void EffectCgGL::end()
{
	// 現在のパスをリセットする
	cgResetPassState( pass_ );

	// パスを無効にする
	pass_ = 0;
}



/*=========================================================================*/
/**
 * @brief テクニック名を取得
 * 
 * @param[in] techniqueNo 取得するテクニック番号.
 * @return テクニック名.
 */
const char* EffectCgGL::getTechniqueName( int techniqueNo )
{
	CGtechnique t = cgGetFirstTechnique( effect_ );
	for( int n=0; n<techniqueNo; ++n ){
		t = cgGetNextTechnique( t );
	}

	return cgGetTechniqueName( t );
}



/*=========================================================================*/
/**
 * @brief テクニック数を取得
 * 
 * @param[in] なし.
 * @return テクニック数.
 */
int EffectCgGL::getNumTechnique()
{
	// テクニックの総数を調べる
	int numTechnique = 0;
	for( CGtechnique t=cgGetFirstTechnique( effect_ ); cgIsTechnique( t ); t=cgGetNextTechnique( t ) ){
		numTechnique++;
	}
	return numTechnique;
}



/*=========================================================================*/
/**
 * @brief 現在のテクニック名を取得
 * 
 * @param[in] なし.
 * @return テクニック名.
 */
const char* EffectCgGL::getCurrentTechniqueName()
{
	assert( technique_ != 0 );
	return cgGetTechniqueName( technique_ );
}


	
/*=========================================================================*/
/**
 * @brief パラメータ名を取得
 * 
 * @param[in] paramNo 取得するパラメータ番号.
 * @return パラメータ名.
 */
const char* EffectCgGL::getParameterName( int paramNo )
{
	int count = 0;
	CGparameter param = ::cgGetFirstEffectParameter( effect_ );
	while ( param != 0 ){
		if( paramNo == count ){
			const char* name = ::cgGetParameterName( param );
			assert( name != 0 );
			return name;
		}

		count++;

		param = ::cgGetNextParameter( param );
	};


	// 空文字を返す
	return "";
}



/*=========================================================================*/
/**
 * @brief パラメータ数を取得
 * 
 * @param[in] なし.
 * @return パラメータ数.
 */
int EffectCgGL::getNumParameter()
{
	int count = 0;
	CGparameter param = ::cgGetFirstEffectParameter( effect_ );
	while ( param != 0 ) {
		param = ::cgGetNextParameter( param );
		count ++;
	}
	return count;
}

	
	
/*=========================================================================*/
/**
 * @brief パス数を取得
 * 
 * @param[in] なし.
 * @return パス数.
 */
int EffectCgGL::getNumPass()
{
	// パスの総数を調べる
	int numPass = 0;
	for( CGpass p=cgGetFirstPass( technique_ ); cgIsPass( p ); p=cgGetNextPass( p ) ){
		numPass++;
	}
	return numPass;
}



/*=========================================================================*/
/**
 * @brief スカラーパラメータを設定
 * 
 * @param[in] name パラメータ名.
 * @param[in] v 設定するスカラー値.
 * @return なし.
 */
void EffectCgGL::setScalar( const char* name, float v )
{
	CGparameter param = cgGetNamedEffectParameter( effect_, name );
	cgSetParameter1f( param, v );
}



/*=========================================================================*/
/**
 * @brief スカラーパラメータを設定
 * 
 * @param[in] name パラメータ名.
 * @param[in] v 設定するスカラー値.
 * @return なし.
 */
void EffectCgGL::setScalar( const char* name, int v )
{
	CGparameter param = cgGetNamedEffectParameter( effect_, name );
	cgSetParameter1i( param, v );
}

	
	

/*=========================================================================*/
/**
 * @brief ベクトルパラメータを設定
 * 
 * @param[in] name パラメータ名.
 * @param[in] x 設定するベクトルのx成分.
 * @param[in] y 設定するベクトルのy成分.
 * @param[in] z 設定するベクトルのz成分.
 + @param[in] w 設定するベクトルのw成分.
 * @return なし.
 */
void EffectCgGL::setVector( const char* name, float x, float y, float z, float w )
{
	CGparameter param = cgGetNamedEffectParameter( effect_, name );
	float v[4] = { x, y, z, w };
	cgSetParameterValuefc( param,cgGetParameterColumns( param ), v );
}



/*=========================================================================*/
/**
 * @brief 行列パラメータを設定
 * 
 * @param[in] name パラメータ名.
 * @param[in] matrix 設定する行列パラメータ
 * @return なし.
 */
void EffectCgGL::setMatrix( const char* name, float* matrix )
{
	CGparameter param = cgGetNamedEffectParameter( effect_, name );
	cgSetMatrixParameterfr( param, matrix );
}



/*=========================================================================*/
/**
 * @brief スカラーの配列パラメータを設定
 * 
 * @param[in] name パラメータ名.
 * @param[in] v 設定する配列パラメータの先頭ポインタ.
 * @param[in] count 配列の要素数.
 * @return なし.
 */
void EffectCgGL::setScalarArray( const char* name, float* v, unsigned int count )
{
	CGparameter param = cgGetNamedEffectParameter( effect_, name );
	cgSetParameterValuefc( param, count, v );
}



/*=========================================================================*/
/**
 * @brief スカラーの配列パラメータを設定
 * 
 * @param[in] name パラメータ名.
 * @param[in] v 設定する配列パラメータの先頭ポインタ.
 * @param[in] count 配列の要素数.
 * @return なし.
 */
void EffectCgGL::setScalarArray( const char* name, int* v, unsigned int count )
{
	CGparameter param = cgGetNamedEffectParameter( effect_, name );
	int elements	= cgGetArrayTotalSize( param );
	int size		= min( elements, (int)count );
	cgSetParameterValueic( param, size, v );
}

	
	
/*=========================================================================*/
/**
 * @brief ベクトルの配列パラメータを設定
 * 
 * @param[in] name パラメータ名.
 * @param[in] array 設定する配列パラメータの先頭ポインタ.
 * @param[in] count 配列の要素数.
 * @return なし.
 */
void EffectCgGL::setVectorArray( const char* name, float* array, unsigned int count )
{
	CGparameter param = cgGetNamedEffectParameter( effect_, name );
	int columns		= cgGetParameterColumns( param );
	int elements	= cgGetArrayTotalSize( param );
	int size		= min( columns * elements, columns * (int)count );
	cgSetParameterValuefc( param, size, array );
}



/*=========================================================================*/
/**
 * @brief 行列の配列パラメータを設定
 * 
 * @param[in] name パラメータ名.
 * @param[in] array 設定する配列パラメータの先頭ポインタ.
 * @param[in] count 配列の要素数.
 * @return なし.
 */
void EffectCgGL::setMatrixArray( const char* name, float* array, unsigned int count )
{
	CGparameter param = cgGetNamedEffectParameter( effect_, name );
	int columns		= cgGetParameterColumns( param );
	int rows		= cgGetParameterRows( param );
	int elements	= cgGetArrayTotalSize( param );
	int size		= min( columns * rows * elements, columns * rows * (int)count );
	cgSetParameterValuefr( param, size, array );
}



/*=========================================================================*/
/**
 * @brief テクスチャのパラメータを設定
 * 
 * @param[in] name パラメータ名.
 * @param[in] texture テクスチャインターフェースクラスのポインタs.
 * @return なし.
 */
void EffectCgGL::setTexture( const char* name, ITexture* texture )
{
	CGparameter param = cgGetNamedEffectParameter( effect_, name );
	cgGLSetupSampler( param, static_cast< TextureGL* >( texture )->texture() );
}



/*=========================================================================*/
/**
 * @brief 入力シグネチャ構造体を取得
 * 
 * @param[in] techeniqueName テクニック名.
 * @param[in] passNo パス番号.
 * @return なし.
 */
const InputSignatureDesc EffectCgGL::inputSigneture( const char* techeniqueName, int passNo ) const
{
	(void)techeniqueName;
	(void)passNo;

	// DirectX10との互換を持たせるためのダミー
	InputSignatureDesc descSignature = { 0, 0 };
	return descSignature;
}



/*===== EOF ==================================================================*/