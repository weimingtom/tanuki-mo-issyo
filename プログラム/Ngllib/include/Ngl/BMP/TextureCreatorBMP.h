/*******************************************************************************/
/**
 * @file TextureCreatorBMP.h.
 * 
 * @brief BMP テクスチャ作成クラスヘッダファイル.
 *
 * @date 2008/07/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_BMP_TEXTURECREATORBMP_H_
#define _NGL_BMP_TEXTURECREATORBMP_H_

#include	"BMPFile.h"
#include	"Ngl/ITextureCreator.h"


namespace Ngl{


namespace BMP{


/**
 * @class TextureCreatorBMP．
 * @brief BMP テクスチャ作成クラス.
 */
class TextureCreatorBMP : public ITextureCreator
{
public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] renderer レンダラークラスのポインタ.
	 */
	TextureCreatorBMP( IRenderer* renderer );


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~TextureCreatorBMP();


	/*=========================================================================*/
	/**
	 * @brief テクスチャを作成
	 * 
	 * @param[in] fileName ファイル名.
	 * @return 作成したテクスチャのポインタ.
	 */
	virtual ITexture* create( const std::string& fileName );


	/*=========================================================================*/
	/**
	 * @brief レンダラーを設定
	 * 
	 * @param[in] renderer レンダラークラスのポインタ.
	 * @return なし.
	 */
	virtual void setRenderer( IRenderer* renderer );


	/*=========================================================================*/
	/**
	 * @brief 作成できるファイル拡張子名を取得
	 * 
	 * @warning "."を含まず、全てアルファベット小文字の拡張子名を返す.
	 * @param[in] なし.
	 * @return 拡張子名.
	 */
	virtual std::string extension();


	/*=========================================================================*/
	/**
	 * @brief テクスチャフィルタを設定する
	 * 
	 * @warning 設定したインスタンスの削除は行いません.
	 *
	 * @param[in] filter 設定するフィルタ.
	 * @return なし.
	 */
	virtual void setFilter( ITextureFilter* filter );
	
	
	/*=========================================================================*/
	/**
	 * @brief ピクセルクラスを設定する
	 * 
	 * bitCountビットのビットマップのピクセルデータ処理クラスを設定します。
	 *
	 * @param[in] pixel 設定するピクセルクラス.
	 * @param[in] bitCount 関数を設定するビットマップ.
	 * @return なし.
	 */
	void setBMPPixel( IBMPPixel* pixel, BitCount bitCount );

private:

	/** テクスチャフィルタ */
	ITextureFilter*	filter_;

	/** レンダラークラス */
	IRenderer*		renderer_;

	/** テクスチャファイル名 */
	std::string		fileName_;

	/** ビットマップファイルクラス */
	BMPFile			bmp_;


};

} // namespace BMP

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/