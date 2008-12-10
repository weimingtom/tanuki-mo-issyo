/*******************************************************************************/
/**
 * @file EffectParameter.cpp.<br>
 * 
 * @brief エフェクトパラメータクラスソースファイル.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"EffectParameter.h"
#include	"IGraphicDevice.h"
#include	<cassert>


/**
 * @brief コンストラクタ<br>
 * 
 * @param[in] なし.
 */
EffectParameter::EffectParameter():
	mID( 0 ),
	mGraphicDevice( 0 ),
	mEffect( 0 )
{}



/**
 * @brief コンストラクタ<br>
 * 
 * @param[in] id エフェクトID.
 * @param[in] ef エフェクト.
 * @param[in] g グラフィックデバイス.
 */
void EffectParameter::Initialize( unsigned int id, Ngl::IEffectExtension* ef, IGraphicDevice* g )
{
	assert( ef != 0 && g != 0 && id != 0 );

	mID = id;
	mEffect = ef;
	mGraphicDevice = g;
}



/**
 * @brief 浮動小数点パラメータを設定する<br>
 * 
 * @param[in] name パラメータ名.
 * @param[in] f パラメータ.
 * @return なし.
 */
void EffectParameter::SetParameter( const char* name, float f )
{
	mEffect->getParameterByName( name )->asScalar()->setFloat( f );
}



/**
 * @brief 浮動小数点パラメータの配列を設定する<br>
 * 
 * @param[in] name パラメータ名.
 * @param[in] count 要素数.
 * @param[in] f パラメータ配列のポインタ.
 * @return なし.
 */
void EffectParameter::SetParameter( const char* name, int count, float* fv )
{
	mEffect->getParameterByName( name )->asScalar()->setFloatArray( fv, count );
}
	


/**
 * @brief 3次元ベクトル型のパラメータの配列を設定する<br>
 * 
 * @param[in] name パラメータ名.
 * @param[in] v パラメータ.
 * @return なし.
 */
void EffectParameter::SetParameter( const char* name, const Vector3& v )
{
	mEffect->getParameterByName( name )->asVector()->setVector3( v );
}	
	
	

/**
 * @brief カラー型のパラメータの配列を設定する<br>
 * 
 * @param[in] name パラメータ名.
 * @param[in] c パラメータ.
 * @return なし.
 */
void EffectParameter::SetParameter( const char* name, const Color4& c )
{
	mEffect->getParameterByName( name )->asScalar()->setColor( c );
}

	

/**
 * @brief 行列型のパラメータの配列を設定する<br>
 * 
 * @param[in] name パラメータ名.
 * @param[in] m パラメータ.
 * @return なし.
 */
void EffectParameter::SetParameter( const char* name, const Matrix4& m )
{
	mEffect->getParameterByName( name )->asMatrix()->setMatrix( m );
}



/**
 * @brief テクスチャのパラメータを設定する<br>
 * 
 * @param[in] name パラメータ名.
 * @param[in] id テクスチャID.
 * @return なし.
 */
void EffectParameter::SetParameter( const char* name, TextureID id )
{
	mGraphicDevice->SetTextureToEffect( mID, id, name );
}



/**
 * @brief 座標変換行列を設定する<br>
 * 
 * @param[in] model モデリング変換行列.
 * @return なし.
 */
void EffectParameter::SetModelViewProjMatrix( const Matrix4& model )
{
	// モデルビュー変換行列を作成する
	Matrix4 modelViewProj;
	modelViewProj = model * mGraphicDevice->GetTransformMatrix( MAT_VIEW );
	
	// モデルビュープロジェクション変換行列を作成する
	Matrix4 matTransformProj;
	matTransformProj = modelViewProj * mGraphicDevice->GetTransformMatrix( MAT_PROJECTION );
	mEffect->getParameterByName( "g_ModelViewProjectionMatrix" )->asMatrix()->setMatrix( matTransformProj );
}



/**
 * @brief 座標変換行列を設定する<br>
 * 
 * @param[in] model モデリング変換行列
 * @return なし.
 */
void EffectParameter::SetTransform( const Matrix4& model )
{
	// モデルビュー変換行列を作成する
	Matrix4 modelViewProj;
	modelViewProj = model * mGraphicDevice->GetTransformMatrix( MAT_VIEW );
	
	// モデルビュープロジェクション変換行列を作成する
	Matrix4 matTransformProj;
	matTransformProj = modelViewProj * mGraphicDevice->GetTransformMatrix( MAT_PROJECTION );
	mEffect->getParameterByName( "g_ModelViewMatrix" )->asMatrix()->setMatrix( modelViewProj );
	mEffect->getParameterByName( "g_ModelViewProjectionMatrix" )->asMatrix()->setMatrix( matTransformProj );

	// 法線ベクトル変換行列をシェーダー渡す
	Matrix4 matNormal = modelViewProj;
	matNormal.setPosition( Vector3( 0.0f, 0.0f, 0.0f ) );
	mEffect->getParameterByName( "g_NormalMatrix" )->asMatrix()->setMatrix( matNormal );
}



/**
 * @brief 視野変換行列のライト位置を設定<br>
 * 
 * @param[in] lightpos ライト位置.
 * @return なし.
 */
void EffectParameter::SetLightPositionEye( const Vector3& lightpos )
{
	// 視点座標系のライト位置をシェーダーに渡す
	Vector3 lightPositionEye;
	lightPositionEye = lightpos * mGraphicDevice->GetTransformMatrix( MAT_VIEW );
	mEffect->getParameterByName( "g_LightPositionEye" )->asVector()->setVector3( lightPositionEye );
}



/**
 * @brief 環境光カラーを設定<br>
 * 
 * @param[in] color ライト色.
 * @return なし.
 */
void EffectParameter::SetAmbientLightColor( const Color4& color )
{
	mEffect->getParameterByName( "g_AmbientLightColor" )->asScalar()->setColor( color );
}



/**
 * @brief 拡散反射光カラーを設定<br>
 * 
 * @param[in] color ライト色.
 * @return なし.
 */
void EffectParameter::SetDiffuseLightColor( const Color4& color )
{
	mEffect->getParameterByName( "g_DiffuseLightColor" )->asScalar()->setColor( color );
}



/**
 * @brief 鏡面反射光カラーを設定<br>
 * 
 * @param[in] color ライト色.
 * @return なし.
 */
void EffectParameter::SetSpecularLightColor( const Color4& color )
{
	mEffect->getParameterByName( "g_SpecularLightColor" )->asScalar()->setColor( color );
}



/*===== EOF ==================================================================*/