/*******************************************************************************/
/**
 * @file EffectParameter.cpp.
 * 
 * @brief エフェクトパラメータクラスソースファイル.
 *
 * @date 2008/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/EffectParameter.h"
#include	<cassert>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] effect エフェクトクラスのポインタ.
 * @param[in] parameterName パラメータ名.
 */
EffectParameter::EffectParameter( IEffect* effect, const std::string parameterName  ):
	effect_( effect ),
	parameterName_( parameterName )
{
	assert( effect_ != 0 );
}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
EffectParameter::~EffectParameter()
{
	effect_ = 0;
}



/*=========================================================================*/
/**
 * @brief パラメータ名を取得
 * 
 * @param[in] なし.
 * @return パラメータ名.
 */
const std::string& EffectParameter::name() const
{
	return parameterName_;
}
	
	
/*=========================================================================*/
/**
 * @brief スカラーパラメータインターフェースを取得
 * 
 * @param[in] なし.
 * @return スカラーパラメータインターフェースのポインタ.
 */
IEffectScalarParameter* EffectParameter::asScalar()
{
	return this;
}



/*=========================================================================*/
/**
 * @brief ベクトルパラメータインターフェースを取得
 * 
 * @param[in] なし.
 * @return ベクトルパラメータインターフェースのポインタ.
 */
IEffectVectorParameter* EffectParameter::asVector()
{
	return this;
}

	
	
/*=========================================================================*/
/**
 * @brief 行列パラメータインターフェースを取得
 * 
 * @param[in] なし.
 * @return 行列パラメータインターフェースのポインタ.
 */
IEffectMatrixParameter* EffectParameter::asMatrix()
{
	return this;
}

	
	
/*=========================================================================*/
/**
 * @brief テクスチャパラメータインターフェースを取得
 * 
 * @param[in] なし.
 * @return テクスチャパラメータインターフェースのポインタ.
 */
IEffectTextureParameter* EffectParameter::asTexture()
{
	return this;
}


	
/*=========================================================================*/
/**
 * @brief int型のパラメータを設定
 * 
 * @param[in] v 設定するパラメータ.
 * @return なし.
 */
void EffectParameter::setInt( int v )
{
	effect_->setScalar( name().c_str(), v );
}



/*=========================================================================*/
/**
 * @brief int型配列のパラメータを設定
 * 
 * @param[in] v 設定する配列パラメータの先頭ポインタ.
 * @param[in] count 要素数.
 * @return なし.
 */
void EffectParameter::setIntArray( const int* v, unsigned int count )
{
	effect_->setScalarArray( name().c_str(), const_cast< int* >( v ), count );
}



/*=========================================================================*/
/**
 * @brief float型のパラメータを設定
 * 
 * @param[in] v 設定するパラメータ.
 * @return なし.
 */
void EffectParameter::setFloat( float v )
{
	effect_->setScalar( name().c_str(), v );
}



/*=========================================================================*/
/**
 * @brief float型配列のパラメータを設定
 * 
 * @param[in] v 設定する配列パラメータの先頭ポインタ.
 * @param[in] count 要素数.
 * @return なし.
 */
void EffectParameter::setFloatArray( const float* v, unsigned int count )
{
	effect_->setScalarArray( name().c_str(), const_cast< float* >( v ), count );
}
	
	
	
/*=========================================================================*/
/**
 * @brief RGBAカラー構造体のパラメータを設定
 * 
 * @param[in] color 設定するRGBAカラー構造体パラメータ.
 * @return なし.
 */
void EffectParameter::setColor( const Color4& color )
{
	effect_->setVector( name().c_str(), color.r, color.g, color.b, color.a );
}



/*=========================================================================*/
/**
 * @brief RGBAカラー構造体配列のパラメータを設定
 * 
 * @param[in] color 設定するRGBAカラー配列パラメータの先頭ポインタ.
 * @param[in] count 要素数.
 * @return なし.
 */
void EffectParameter::setColorArray( const Color4* color, unsigned int count )
{
	effect_->setVectorArray( name().c_str(), (float*)color, count );
}

	
	
/*=========================================================================*/
/**
 * @brief 2次元ベクトルを設定する
 * 
 * @param[in] v2 設定する2次元ベクトル構造体.
 * @return なし.
 */
void EffectParameter::setVector2( const Vector2& v2 )
{
	effect_->setScalarArray( name().c_str(), (float*)v2, 2 );
}



/*=========================================================================*/
/**
 * @brief 2次元ベクトルの配列を設定する
 * 
 * @param[in] v2 設定する2次元ベクトル構造体配列の先頭ポインタ.
 * @param[in] count 配列の要素数
 * @return なし.
 */
void EffectParameter::setVector2Array( const Vector2& v2, unsigned int count )
{
	effect_->setVectorArray( name().c_str(), (float*)v2, count );
}



/*=========================================================================*/
/**
 * @brief 3次元ベクトルを設定する
 * 
 * @param[in] v3 設定する3次元ベクトル構造体.
 * @return なし.
 */
void EffectParameter::setVector3( const Vector3& v3 )
{
	effect_->setVector( name().c_str(), v3.x, v3.y, v3.z );
}



/*=========================================================================*/
/**
 * @brief 3次元ベクトルの配列を設定する
 * 
 * @param[in] v3 設定する3次元ベクトル構造体配列の先頭ポインタ.
 * @param[in] count 配列の要素数
 * @return なし.
 */
void EffectParameter::setVector3Array( const Vector3& v3, unsigned int count )
{
	effect_->setVectorArray( name().c_str(), (float*)v3, count );
}



/*=========================================================================*/
/**
 * @brief 4次元ベクトルを設定する
 * 
 * @param[in] v4 設定する4次元ベクトル構造体.
 * @return なし.
 */
void EffectParameter::setVector4( const Vector4& v4 )
{
	effect_->setVector( name().c_str(), v4.x, v4.y, v4.z, v4.w );
}



/*=========================================================================*/
/**
 * @brief 4次元ベクトルの配列を設定する
 * 
 * @param[in] v4 設定する4次元ベクトル構造体配列の先頭ポインタ.
 * @param[in] count 配列の要素数
 * @return なし.
 */
void EffectParameter::setVector4Array( const Vector4& v4, unsigned int count )
{
	effect_->setVectorArray( name().c_str(), (float*)v4, count );
}

	
	
/*=========================================================================*/
/**
 * @brief 4x4行列を設定する
 * 
 * @param[in] matrix 設定する4x4行列構造体.
 * @return なし.
 */
void EffectParameter::setMatrix( const Matrix4& matrix )
{
	effect_->setMatrix( parameterName_.c_str(), (float*)matrix );
}



/*=========================================================================*/
/**
 * @brief 4x4行列の配列を設定する
 * 
 * @param[in] matrix 設定する4x4行列構造体配列の先頭ポインタ.
 * @param[in] count 要素数
 * @return なし.
 */
void EffectParameter::setMatrixArray( const Matrix4* matrix, unsigned int count )
{
	effect_->setMatrixArray( parameterName_.c_str(), (float*)matrix, count );
}

	
	
/*=========================================================================*/
/**
 * @brief テクスチャパラメータを設定
 * 
 * @param[in] texture 設定するテクスチャインターフェースのポインタ.
 * @return なし.
 */
void EffectParameter::setTexture( ITexture* texture )
{
	effect_->setTexture( parameterName_.c_str(), texture );
}

	
	
/*===== EOF ==================================================================*/