/*******************************************************************************/
/**
 * @file IBMPPixel.h.
 * 
 * @brief BMP ピクセルデータクラスインターフェース定義.
 *
 * @date 2008/07/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/*******************************************************************************/
#ifndef _NGL_BMP_IBMPPIXEL_H_
#define _NGL_BMP_IBMPPIXEL_H_

#include	"BitMap.h"
#include	"Ngl/IInputStream.h"
#include	<fstream>

namespace Ngl{


namespace BMP{

/**
 * @interface IBMPPixel．
 * @brief BMP ピクセルデータクラスインターフェース.
 */
class IBMPPixel
{

public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IBMPPixel() {}


	/*=========================================================================*/
	/**
	 * @brief () 演算子オーバーロード
	 *
	 * ピクセルデータを読み込む.
	 * 
	 * @param[out] texel データを設定するテクセルデータ.
	 * @param[in] ifStream 入力ストリーム.
	 * @param[in] bmp ビットマップ構造体.
	 * @param[in] x 読み込むピクセルの水平位置.
	 * @param[in] y 読み込むピクセルの垂直位置.
	 * @retval なし.
	 * @throw std::ios::failure 読み込みエラー.
	 */
	virtual void operator () ( BYTE* texel, IInputStream& ifStream, const BitMap& bmp, int x, int y ) = 0;

};

} // namespace BMP

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/