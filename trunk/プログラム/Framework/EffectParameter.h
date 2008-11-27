/*******************************************************************************/
/**
 * @file EffectParameter.h.<br>
 * 
 * @brief エフェクトパラメータクラスヘッダファイル.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _EFFECTPARAMETER_H_
#define _EFFECTPARAMETER_H_

#include	"IEffectParameter.h"
#include	<Ngl/IRenderer.h>
#include	<Ngl/IEffectExtension.h>
#include	<string>

// グラフィックデバイスの前方参照
class IGraphicDevice;

/**
 * @brief エフェクトパラメータクラス.
 */
class EffectParameter : public IEffectParameter
{
public:

	/**
	 * @brief コンストラクタ<br>
	 * 
	 * @param[in] なし.
	 */
	EffectParameter();
	
	/**
	 * @brief コンストラクタ<br>
	 * 
	 * @param[in] id エフェクトID.
	 * @param[in] ef エフェクト.
	 * @param[in] g グラフィックデバイス.
	 */
	void Initialize( unsigned int id, Ngl::IEffectExtension* ef, IGraphicDevice* g );
	
	/**
	 * @brief 浮動小数点パラメータを設定する<br>
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] f パラメータ.
	 * @return なし.
	 */
	void SetParameter( const char* name, float f );

	/**
	 * @brief 浮動小数点パラメータの配列を設定する<br>
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] count 要素数.
	 * @param[in] f パラメータ配列のポインタ.
	 * @return なし.
	 */
	void SetParameter( const char* name, int count, float* fv );
	
	/**
	 * @brief 3次元ベクトル型のパラメータの配列を設定する<br>
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] v パラメータ.
	 * @return なし.
	 */
	void SetParameter( const char* name, const Vector3& v );
	
	/**
	 * @brief カラー型のパラメータの配列を設定する<br>
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] c パラメータ.
	 * @return なし.
	 */
	void SetParameter( const char* name, const Color4& c );
	
	/**
	 * @brief 行列型のパラメータの配列を設定する<br>
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] m パラメータ.
	 * @return なし.
	 */
	void SetParameter( const char* name, const Matrix4& m );
	
	/**
	 * @brief テクスチャのパラメータを設定する<br>
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] id テクスチャID.
	 * @return なし.
	 */
	void SetParameter( const char* name, TextureID id );
	
	/**
	 * @brief 座標変換行列を設定する<br>
	 * 
	 * @param[in] model モデリング変換行列.
	 * @return なし.
	 */
	void SetModelViewProjMatrix( const Matrix4& model );
	
	/**
	 * @brief 座標変換行列を設定する<br>
	 * 
	 * @param[in] model モデリング変換行列
	 * @return なし.
	 */
	void SetTransform( const Matrix4& model );
	
	/**
	 * @brief 視野変換行列のライト位置を設定<br>
	 * 
	 * @param[in] lightpos ライト位置.
	 * @return なし.
	 */
	void SetLightPositionEye( const Vector3& lightpos );
	
	/**
	 * @brief 環境光カラーを設定<br>
	 * 
	 * @param[in] color ライト色.
	 * @return なし.
	 */
	void SetAmbientLightColor( const Color4& color );

	/**
	 * @brief 拡散反射光カラーを設定<br>
	 * 
	 * @param[in] color ライト色.
	 * @return なし.
	 */
	void SetDiffuseLightColor( const Color4& color );

	/**
	 * @brief 鏡面反射光カラーを設定<br>
	 * 
	 * @param[in] color ライト色.
	 * @return なし.
	 */
	void SetSpecularLightColor( const Color4& color );

private:

	/** エフェクトID */
	unsigned int			mID;

	/** グラフィックデバイスの参照 */
	IGraphicDevice*			mGraphicDevice;

	/** シェーダーパラメータのポインタ */
	Ngl::IEffectExtension*	mEffect;

};

#endif

/*===== EOF ==================================================================*/