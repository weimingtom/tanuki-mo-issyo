/*******************************************************************************/
/**
 * @file EffectCgGL.h.
 * 
 * @brief OpenGL Cgfxエフェクトクラスヘッダファイル.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_OPENGL_EFFECT_H_
#define _NGL_OPENGL_EFFECT_H_

#include	"Ngl/IEffect.h"
#include	"OpenGL.h"
#include	<Cg/cg.h>
#include	<Cg/cgGL.h>

namespace Ngl{


// テクスチャクラス
class ITexture;


namespace OpenGL{


/**
 * @class EffectCgGL.
 * @brief OpenGL Cgfxエフェクトクラス.
 *
 * cgfx形式エフェクトファイルを処理するためのクラスです。
 */
class EffectCgGL : public IEffect
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] fileName ファイル名.
	 */
	EffectCgGL( const char* fileName );

	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~EffectCgGL();

	
	/*=========================================================================*/
	/**
	 * @brief テクニックを開始
	 * 
	 * @param[in] techniqueName テクニック名.
	 * @return なし.
	 */
	void technique( const char* techniqueName );

	
	/*=========================================================================*/
	/**
	 * @brief パスを開始
	 * 
	 * @param[in] passNo パス番号.
	 * @return なし.
	 */
	void begin( int passNo=0 );

	
	/*=========================================================================*/
	/**
	 * @brief パスを終了
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void end();

	
	/*=========================================================================*/
	/**
	 * @brief テクニック名を取得
	 * 
	 * @param[in] techniqueNo 取得するテクニック番号.
	 * @return テクニック名.
	 */
	const char* getTechniqueName( int techniqueNo );

	
	/*=========================================================================*/
	/**
	 * @brief テクニック数を取得
	 * 
	 * @param[in] なし.
	 * @return テクニック数.
	 */
	int getNumTechnique();

	
	/*=========================================================================*/
	/**
	 * @brief 現在のテクニック名を取得
	 * 
	 * @param[in] なし.
	 * @return テクニック名.
	 */
	virtual const char* getCurrentTechniqueName();
	
	
	/*=========================================================================*/
	/**
	 * @brief パラメータ名を取得
	 * 
	 * @param[in] paramNo 取得するパラメータ番号.
	 * @return パラメータ名.
	 */
	virtual const char* getParameterName( int paramNo );
	
	
	/*=========================================================================*/
	/**
	 * @brief パラメータ数を取得
	 * 
	 * @param[in] なし.
	 * @return パラメータ数.
	 */
	virtual int getNumParameter();
	
	
	/*=========================================================================*/
	/**
	 * @brief パス数を取得
	 * 
	 * @param[in] なし.
	 * @return パス数.
	 */
	int getNumPass();

	
	/*=========================================================================*/
	/**
	 * @brief スカラーパラメータを設定
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] v 設定するスカラー値.
	 * @return なし.
	 */
	virtual void setScalar( const char* name, float v );
	
	
	/*=========================================================================*/
	/**
	 * @brief スカラーパラメータを設定
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] v 設定するスカラー値.
	 * @return なし.
	 */
	virtual void setScalar( const char* name, int v );
	
	
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
	void setVector( const char* name, float x=0, float y=0, float z=0, float w=0 );

	
	/*=========================================================================*/
	/**
	 * @brief 行列パラメータを設定
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] matrix 設定する行列パラメータ
	 * @return なし.
	 */
	void setMatrix( const char* name, float* matrix );

	
	/*=========================================================================*/
	/**
	 * @brief スカラーの配列パラメータを設定
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] v 設定する配列パラメータの先頭ポインタ.
	 * @param[in] count 配列の要素数.
	 * @return なし.
	 */
	virtual void setScalarArray( const char* name, float* v, unsigned int count );
	
	
	/*=========================================================================*/
	/**
	 * @brief スカラーの配列パラメータを設定
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] v 設定する配列パラメータの先頭ポインタ.
	 * @param[in] count 配列の要素数.
	 * @return なし.
	 */
	virtual void setScalarArray( const char* name, int* v, unsigned int count );

	
	/*=========================================================================*/
	/**
	 * @brief ベクトルの配列パラメータを設定
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] array 設定する配列パラメータの先頭ポインタ.
	 * @param[in] count 配列の要素数.
	 * @return なし.
	 */
	void setVectorArray( const char* name, float* array, unsigned int count );

	
	/*=========================================================================*/
	/**
	 * @brief 行列の配列パラメータを設定
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] array 設定する配列パラメータの先頭ポインタ.
	 * @param[in] count 配列の要素数.
	 * @return なし.
	 */
	void setMatrixArray( const char* name, float* array, unsigned int count );

	
	/*=========================================================================*/
	/**
	 * @brief テクスチャのパラメータを設定
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] texture テクスチャインターフェースクラスのポインタs.
	 * @return なし.
	 */
	void setTexture( const char* name, ITexture* texture );

	
	/*=========================================================================*/
	/**
	 * @brief 入力シグネチャ構造体を取得
	 * 
	 * @param[in] techeniqueName テクニック名.
	 * @param[in] passNo パス番号.
	 * @return なし.
	 */
	const InputSignatureDesc inputSigneture( const char* techeniqueName, int passNo=0 ) const;

private:

	/** ＣＧコンテキスト */
	CGcontext	context_;

	/** エフェクト */
	CGeffect	effect_;

	/** テクニック */
	CGtechnique	technique_;

	/** パス */
	CGpass		pass_;

};

} // namespace OpenGL

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/