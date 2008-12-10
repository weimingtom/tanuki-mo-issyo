/*******************************************************************************/
/**
 * @file IEffectParameter.h.<br>
 * 
 * @brief エフェクトパラメータインターフェース定義.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _IEFFECTPARAMETER_H_
#define _IEFFECTPARAMETER_H_

#include	"Define/Define.h"

/**
 * @brief エフェクトパラメータインターフェース.
 */
class IEffectParameter
{
protected:

	/**
	 * @brief デストラクタ<br>
	 * 
	 * @param[in] なし.
	 */
	virtual ~IEffectParameter() {}

public:

	/**
	 * @brief 浮動小数点パラメータを設定する<br>
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] f パラメータ.
	 * @return なし.
	 */
	virtual void SetParameter( const char* name, float f ) = 0;
	
	/**
	 * @brief 浮動小数点パラメータの配列を設定する<br>
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] count 要素数.
	 * @param[in] f パラメータ配列のポインタ.
	 * @return なし.
	 */
	virtual void SetParameter( const char* name, int count, float* fv ) = 0;
	
	/**
	 * @brief 3次元ベクトル型のパラメータの配列を設定する<br>
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] v パラメータ.
	 * @return なし.
	 */
	virtual void SetParameter( const char* name, const Vector3& v ) = 0;
	
	/**
	 * @brief カラー型のパラメータの配列を設定する<br>
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] c パラメータ.
	 * @return なし.
	 */
	virtual void SetParameter( const char* name, const Color4& c ) = 0;
	
	/**
	 * @brief 行列型のパラメータの配列を設定する<br>
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] m パラメータ.
	 * @return なし.
	 */
	virtual void SetParameter( const char* name, const Matrix4& m ) = 0;
	
	/**
	 * @brief テクスチャのパラメータを設定する<br>
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] id テクスチャID.
	 * @return なし.
	 */
	virtual void SetParameter( const char* name, TextureID id ) = 0;

	/**
	 * @brief 座標変換行列を設定する<br>
	 * 
	 * @param[in] model モデリング変換行列.
	 * @return なし.
	 */
	virtual void SetModelViewProjMatrix( const Matrix4& model ) = 0;
	
	/**
	 * @brief 座標変換行列を設定する<br>
	 * 
	 * @param[in] model モデリング変換行列
	 * @return なし.
	 */
	virtual void SetTransform( const Matrix4& model ) = 0;

	/**
	 * @brief 視野変換行列のライト位置を設定<br>
	 * 
	 * @param[in] lightpos ライト位置.
	 * @return なし.
	 */
	virtual void SetLightPositionEye( const Vector3& lightpos ) = 0;
	
	/**
	 * @brief 環境光カラーを設定<br>
	 * 
	 * @param[in] color ライト色.
	 * @return なし.
	 */
	virtual void SetAmbientLightColor( const Color4& color ) = 0;

	/**
	 * @brief 拡散反射光カラーを設定<br>
	 * 
	 * @param[in] color ライト色.
	 * @return なし.
	 */
	virtual void SetDiffuseLightColor( const Color4& color ) = 0;

	/**
	 * @brief 鏡面反射光カラーを設定<br>
	 * 
	 * @param[in] color ライト色.
	 * @return なし.
	 */
	virtual void SetSpecularLightColor( const Color4& color ) = 0;

};

#endif

/*===== EOF ==================================================================*/