/*******************************************************************************/
/**
 * @file ITextureFilter.h.
 * 
 * @brief テクスチャフィルタインターフェース定義.
 *
 * @date 2008/08/22.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ITEXTUREFILTER_H_
#define _NGL_ITEXTUREFILTER_H_


namespace Ngl{


/**
 * @interface ITextureFilter．
 * @brief テクスチャフィルタインターフェース.
 */
class ITextureFilter
{

protected:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~ITextureFilter() {}

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
	virtual void operator () ( unsigned char* texel ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/