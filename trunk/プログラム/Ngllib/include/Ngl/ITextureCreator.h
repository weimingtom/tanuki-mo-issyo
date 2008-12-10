/*******************************************************************************/
/**
 * @file ITextureCreator.h.
 * 
 * @brief テクスチャ作成クラスインターフェース定義.
 *
 * @date 2008/07/12.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ITEXTURECREATOR_H_
#define _NGL_ITEXTURECREATOR_H_

#include	"IRenderer.h"
#include	<string>

namespace Ngl{


// テクスチャフィルタインターフェース
class ITextureFilter;

/**
 * @interface ITextureCreator．
 * @brief テクスチャ作成クラスインターフェース.
 */
class ITextureCreator
{

public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~ITextureCreator() {}


	/*=========================================================================*/
	/**
	 * @brief テクスチャを作成
	 * 
	 * @param[in] name 作成元リソース名.
	 * @return 作成したテクスチャのポインタ.
	 */
	virtual ITexture* create( const std::string& name ) = 0;


	/*=========================================================================*/
	/**
	 * @brief レンダラーを設定
	 * 
	 * @param[in] renderer レンダラークラスのポインタ.
	 * @return なし.
	 */
	virtual void setRenderer( IRenderer* renderer ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 作成できるファイル拡張子名を取得
	 * 
	 * @warning "."を含まず、全てアルファベット小文字の拡張子名を返す.
	 *
	 * @param[in] なし.
	 * @return 拡張子名.
	 */
	virtual std::string extension() = 0;


	/*=========================================================================*/
	/**
	 * @brief テクスチャフィルタを設定する
	 * 
	 * @warning 設定したインスタンスの削除は行いません.
	 *
	 * @param[in] filter 設定するフィルタ.
	 * @return なし.
	 */
	virtual void setFilter( ITextureFilter* filter ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/