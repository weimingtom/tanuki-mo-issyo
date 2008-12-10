/*******************************************************************************/
/**
 * @file DefaultBMPPixel8Bit.h.
 * 
 * @brief BMP デフォルトの8Bitビットマップピクセルクラス定義.
 *
 * @date 2008/07/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_BMP_DEFAULTBMPPIXEL8BIT_H_
#define _NGL_BMP_DEFAULTBMPPIXEL8BIT_H_

#include	"IBMPPixel.h"
#include	"Ngl/Exception.h"

namespace Ngl{


namespace BMP{


/**
 * @class DefaultBMPPixel8Bit．
 * @brief BMP デフォルトの8Bitビットマップピクセルクラス.
 */
class DefaultBMPPixel8Bit : public IBMPPixel
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
			// ピクセルの色データを取得
			BYTE pixel = 0;
			ifStream.read( reinterpret_cast< char* >( &pixel ), sizeof( BYTE ) );

			texel[0] = bmp.rgbQuad[ pixel ].rgbRed;		// Red
			texel[1] = bmp.rgbQuad[ pixel ].rgbGreen;	// Green
			texel[2] = bmp.rgbQuad[ pixel ].rgbBlue;	// Blue
			texel[3] = 0xff;							// Alpha
		}
		catch( Ngl::InputStreamException& e ){
			e += "[DefaultBMPPixel8Bit] : [operator()]";
			throw e;
		}
	}

};

} // namespace BMP

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/