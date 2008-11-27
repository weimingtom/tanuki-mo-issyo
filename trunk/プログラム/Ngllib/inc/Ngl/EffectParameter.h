/*******************************************************************************/
/**
 * @file EffectParameter.h.
 * 
 * @brief エフェクトパラメータクラスヘッダファイル.
 *
 * @date 2008/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_EFFECTPARAMETER_H_
#define _NGL_EFFECTPARAMETER_H_

#include	"Ngl/IEffectParameter.h"
#include	"Ngl/IEffect.h"

namespace Ngl{


/**
 * @class EffectParameter．
 * @brief エフェクトパラメータクラス.
 */
class EffectParameter :	public IEffectParameter,
						public IEffectScalarParameter,
						public IEffectVectorParameter,
						public IEffectMatrixParameter,
						public IEffectTextureParameter
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] effect エフェクトクラスのポインタ.
	 * @param[in] parameterName パラメータ名.
	 */
	EffectParameter( IEffect* effect, const std::string parameterName );


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~EffectParameter();


	/*=========================================================================*/
	/**
	 * @brief パラメータ名を取得
	 * 
	 * @param[in] なし.
	 * @return パラメータ名.
	 */
	virtual const std::string& name() const;
	
	
	/*=========================================================================*/
	/**
	 * @brief スカラーパラメータインターフェースを取得
	 * 
	 * @param[in] なし.
	 * @return スカラーパラメータインターフェースのポインタ.
	 */
	virtual IEffectScalarParameter* asScalar();


	/*=========================================================================*/
	/**
	 * @brief ベクトルパラメータインターフェースを取得
	 * 
	 * @param[in] なし.
	 * @return ベクトルパラメータインターフェースのポインタ.
	 */
	virtual IEffectVectorParameter* asVector();


	/*=========================================================================*/
	/**
	 * @brief 行列パラメータインターフェースを取得
	 * 
	 * @param[in] なし.
	 * @return 行列パラメータインターフェースのポインタ.
	 */
	virtual IEffectMatrixParameter* asMatrix();


	/*=========================================================================*/
	/**
	 * @brief テクスチャパラメータインターフェースを取得
	 * 
	 * @param[in] なし.
	 * @return テクスチャパラメータインターフェースのポインタ.
	 */
	virtual IEffectTextureParameter* asTexture();

private:

	/*=========================================================================*/
	/**
	 * @brief int型のパラメータを設定
	 * 
	 * @param[in] v 設定するパラメータ.
	 * @return なし.
	 */
	virtual void setInt( int v );


	/*=========================================================================*/
	/**
	 * @brief int型配列のパラメータを設定
	 * 
	 * @param[in] v 設定する配列パラメータの先頭ポインタ.
	 * @param[in] count 要素数.
	 * @return なし.
	 */
	virtual void setIntArray( const int* v, unsigned int count );


	/*=========================================================================*/
	/**
	 * @brief float型のパラメータを設定
	 * 
	 * @param[in] v 設定するパラメータ.
	 * @return なし.
	 */
	virtual void setFloat( float v );


	/*=========================================================================*/
	/**
	 * @brief float型配列のパラメータを設定
	 * 
	 * @param[in] v 設定する配列パラメータの先頭ポインタ.
	 * @param[in] count 要素数.
	 * @return なし.
	 */
	virtual void setFloatArray( const float* v, unsigned int count );


	/*=========================================================================*/
	/**
	 * @brief RGBAカラー構造体のパラメータを設定
	 * 
	 * @param[in] color 設定するRGBAカラー構造体パラメータ.
	 * @return なし.
	 */
	virtual void setColor( const Color4& color );


	/*=========================================================================*/
	/**
	 * @brief RGBAカラー構造体配列のパラメータを設定
	 * 
	 * @param[in] color 設定するRGBAカラー配列パラメータの先頭ポインタ.
	 * @param[in] count 要素数.
	 * @return なし.
	 */
	virtual void setColorArray( const Color4* color, unsigned int count );

	
	/*=========================================================================*/
	/**
	 * @brief 2次元ベクトルを設定する
	 * 
	 * @param[in] v2 設定する2次元ベクトル構造体.
	 * @return なし.
	 */
	virtual void setVector2( const Vector2& v2 );


	/*=========================================================================*/
	/**
	 * @brief 2次元ベクトルの配列を設定する
	 * 
	 * @param[in] v2 設定する2次元ベクトル構造体配列の先頭ポインタ.
	 * @param[in] count 配列の要素数
	 * @return なし.
	 */
	virtual void setVector2Array( const Vector2& v2, unsigned int count );


	/*=========================================================================*/
	/**
	 * @brief 3次元ベクトルを設定する
	 * 
	 * @param[in] v3 設定する3次元ベクトル構造体.
	 * @return なし.
	 */
	virtual void setVector3( const Vector3& v3 );


	/*=========================================================================*/
	/**
	 * @brief 3次元ベクトルの配列を設定する
	 * 
	 * @param[in] v3 設定する3次元ベクトル構造体配列の先頭ポインタ.
	 * @param[in] count 配列の要素数
	 * @return なし.
	 */
	virtual void setVector3Array( const Vector3& v3, unsigned int count );


	/*=========================================================================*/
	/**
	 * @brief 4次元ベクトルを設定する
	 * 
	 * @param[in] v4 設定する4次元ベクトル構造体.
	 * @return なし.
	 */
	virtual void setVector4( const Vector4& v4 );


	/*=========================================================================*/
	/**
	 * @brief 4次元ベクトルの配列を設定する
	 * 
	 * @param[in] v4 設定する4次元ベクトル構造体配列の先頭ポインタ.
	 * @param[in] count 配列の要素数
	 * @return なし.
	 */
	virtual void setVector4Array( const Vector4& v4, unsigned int count );


	/*=========================================================================*/
	/**
	 * @brief 4x4行列を設定する
	 * 
	 * @param[in] matrix 設定する4x4行列構造体.
	 * @return なし.
	 */
	virtual void setMatrix( const Matrix4& matrix );


	/*=========================================================================*/
	/**
	 * @brief 4x4行列の配列を設定する
	 * 
	 * @param[in] matrix 設定する4x4行列構造体配列の先頭ポインタ.
	 * @param[in] count 要素数
	 * @return なし.
	 */
	virtual void setMatrixArray( const Matrix4* matrix, unsigned int count );


	/*=========================================================================*/
	/**
	 * @brief テクスチャパラメータを設定
	 * 
	 * @param[in] texture 設定するテクスチャインターフェースのポインタ.
	 * @return なし.
	 */
	virtual void setTexture( ITexture* texture );

private:

	/** エフェクトクラスのポインタ */
	IEffect*	effect_;

	/** パラメータ名 */
	std::string	parameterName_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/