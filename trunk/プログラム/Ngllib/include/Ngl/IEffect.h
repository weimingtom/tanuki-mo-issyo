/*******************************************************************************/
/**
 * @file IEffect.h.
 * 
 * @brief エフェクトインターフェース定義.
 *
 * @date 2008/07/08.
 * 
 * @version 1.00.
 * 
 * @author 製作者名.
 */
/******************************************************************************/
#ifndef _NGL_IEFFECT_H_
#define _NGL_IEFFECT_H_

#include	"InputSignatureDesc.h"

namespace Ngl{


// テクスチャインターフェース
class ITexture;

/**
 * @interface IEffect．
 * @brief エフェクトインターフェース.
 */
class IEffect
{
public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IEffect(){}

	
	/*=========================================================================*/
	/**
	 * @brief テクニックを開始
	 * 
	 * @param[in] techniqueName テクニック名.
	 * @return なし.
	 */
	virtual void technique( const char* techniqueName ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief パスを開始
	 * 
	 * @param[in] passNo パス番号.
	 * @return なし.
	 */
	virtual void begin( int passNo=0 ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief パスを終了
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void end() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief テクニック名を取得
	 * 
	 * @param[in] techniqueNo 取得するテクニック番号.
	 * @return テクニック名.
	 */
	virtual const char* getTechniqueName( int techniqueNo ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief テクニック数を取得
	 * 
	 * @param[in] なし.
	 * @return テクニック数.
	 */
	virtual int getNumTechnique() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief 現在のテクニック名を取得
	 * 
	 * @param[in] なし.
	 * @return テクニック名.
	 */
	virtual const char* getCurrentTechniqueName() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief パラメータ名を取得
	 * 
	 * @param[in] paramNo 取得するパラメータ番号.
	 * @return パラメータ名.
	 */
	virtual const char* getParameterName( int paramNo ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief パラメータ数を取得
	 * 
	 * @param[in] なし.
	 * @return パラメータ数.
	 */
	virtual int getNumParameter() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief パス数を取得
	 * 
	 * @param[in] なし.
	 * @return パス数.
	 */
	virtual int getNumPass() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief スカラーパラメータを設定
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] v 設定するスカラー値.
	 * @return なし.
	 */
	virtual void setScalar( const char* name, float v ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief スカラーパラメータを設定
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] v 設定するスカラー値.
	 * @return なし.
	 */
	virtual void setScalar( const char* name, int v ) = 0;
	
	
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
	virtual void setVector( const char* name, float x=0, float y=0, float z=0, float w=0 ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief 行列パラメータを設定
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] matrix 設定する行列パラメータ
	 * @return なし.
	 */
	virtual void setMatrix( const char* name, float* matrix ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief スカラーの配列パラメータを設定
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] v 設定する配列パラメータの先頭ポインタ.
	 * @param[in] count 配列の要素数.
	 * @return なし.
	 */
	virtual void setScalarArray( const char* name, float* v, unsigned int count ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief スカラーの配列パラメータを設定
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] v 設定する配列パラメータの先頭ポインタ.
	 * @param[in] count 配列の要素数.
	 * @return なし.
	 */
	virtual void setScalarArray( const char* name, int* v, unsigned int count ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief ベクトルの配列パラメータを設定
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] array 設定する配列パラメータの先頭ポインタ.
	 * @param[in] count 配列の要素数.
	 * @return なし.
	 */
	virtual void setVectorArray( const char* name, float* array, unsigned int count ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief 行列の配列パラメータを設定
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] array 設定する配列パラメータの先頭ポインタ.
	 * @param[in] count 配列の要素数.
	 * @return なし.
	 */
	virtual void setMatrixArray( const char* name, float* array, unsigned int count ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief テクスチャのパラメータを設定
	 * 
	 * @param[in] name パラメータ名.
	 * @param[in] texture テクスチャインターフェースクラスのポインタs.
	 * @return なし.
	 */
	virtual void setTexture( const char* name, ITexture* texture ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief 入力シグネチャ構造体を取得
	 * 
	 * @param[in] techniqueName テクニック名.
	 * @param[in] passNo パス番号.
	 * @return なし.
	 */
	virtual const InputSignatureDesc inputSigneture( const char* techniqueName, int passNo=0 ) const = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/