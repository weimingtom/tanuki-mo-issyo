/*******************************************************************************/
/**
 * @file TextureFilterGrayScale.h.
 * 
 * @brief グレースケールテクスチャフィルタクラスヘッダファイル.
 *
 * @date 2008/08/24.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_TEXTUREFILTERGRAYSCALE_H_
#define _NGL_TEXTUREFILTERGRAYSCALE_H_

#include	"ITextureFilter.h"

namespace Ngl{


/**
 * @class TextureFilterGrayScale．
 * @brief グレースケールテクスチャフィルタクラス.
 */
class TextureFilterGrayScale : public ITextureFilter
{

public:

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

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/