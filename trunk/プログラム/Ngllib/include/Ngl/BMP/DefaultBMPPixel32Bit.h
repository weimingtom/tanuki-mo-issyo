/*******************************************************************************/
/**
 * @file DefaultBMPPixel32Bit.h.
 * 
 * @brief BMP デフォルトの32Bitビットマップピクセルクラス定義.
 *
 * @date 2008/07/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_BMP_DEFAULTBMPPIXEL32BIT_H_
#define _NGL_BMP_DEFAULTBMPPIXEL32BIT_H_

#include	"IBMPPixel.h"
#include	"Ngl/Exception.h"

namespace Ngl{


namespace BMP{


/**
 * @class DefaultBMPPixel32Bit．
 * @brief BMP デフォルトの32Bitビットマップピクセルクラス.
 */
class DefaultBMPPixel32Bit : public IBMPPixel
{

public:

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
	 * @throw Ngl::InputStreamException 読み込みエラー.
	 */
	virtual void operator () ( BYTE* texel, IInputStream& ifStream, const BitMap& bmp, int x, int y )
	{
		try{
			ifStream >> reinterpret_cast< char& >( texel[ 2 ] );
			ifStream >> reinterpret_cast< char& >( texel[ 1 ] );
			ifStream >> reinterpret_cast< char& >( texel[ 0 ] );
			ifStream >> reinterpret_cast< char& >( texel[ 3 ] );
		}
		catch( Ngl::InputStreamException& e ){
			e += "[DefaultBMPPixel32Bit] : [operator()]";
			throw e;
		}
	}

};

} // namespace BMP

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/