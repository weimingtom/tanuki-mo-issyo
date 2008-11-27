/*******************************************************************************/
/**
 * @file TextureFilterColorKeyAuto.h.
 * 
 * @brief カラーキーテクスチャフィルタクラスヘッダファイル.
 *
 * @date 2008/08/23.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_TEXTUREFILTERCOLORKEYAUTO_H_
#define _NGL_TEXTUREFILTERCOLORKEYAUTO_H_

#include	"ITextureFilter.h"

namespace Ngl{


/**
 * @class TextureFilterColorKeyAuto．
 * @brief カラーキーテクスチャフィルタクラス.
 *
 * 画像左上のピクセルをカラーキーとして設定します。
 */
class TextureFilterColorKeyAuto : public ITextureFilter
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	TextureFilterColorKeyAuto();


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~TextureFilterColorKeyAuto();


	/*=========================================================================*/
	/**
	 * @brief () 演算子オーバーロード
	 * 
	 * ピクセルを加工する.
	 *
	 * @param[in] texel 加工するピクセル値.
	 * @return なし.
	 */
	virtual void operator () ( unsigned char* texel );

private:

	/** カラーキー赤成分 */
	unsigned char	r_;

	/** カラーキー緑成分 */
	unsigned char	g_;

	/** カラーキー青成分 */
	unsigned char	b_;

	/** カラーキーアルファ成分 */
	unsigned char	a_;

	/** カラーキー設定フラグ */
	bool			setFlag_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/