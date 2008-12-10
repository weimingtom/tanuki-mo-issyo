/*******************************************************************************/
/**
 * @file Color4Input.h.
 * 
 * @brief RGBAカラー構造体入力マニピュレータクラス定義.
 *
 * @date 2008/07/19.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_COLOR4INPUT_H_
#define _NGL_COLOR4INPUT_H_

#include	"IInputStream.h"
#include	"Ngl/Color4.h"

namespace Ngl{


/**
 * @class Color4Input.
 * @brief RGBAカラー構造体入力マニピュレータクラス.
 */
class Color4Input
{
	/*=========================================================================*/
	/**
	 * @brief >> 演算子オーバーロード ( マニピュレータ操作 )
	 * 
	 * @param[in] stream 入力ストリームの参照.
	 * @param[in] manip マニピュレータ.
	 * @return 入力ストリームの参照.
	 */
	friend IInputStream& operator >> ( IInputStream& stream, Color4Input manip )
	{
		return manip( stream );
	}

private:

	/** データを読み込むRGBAカラー構造体 */
	Color4& value_;

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] value データを読み込むRGBAカラー構造体.
	 */
	Color4Input( Color4& value ):
		value_( value )
	{}

private:

	/*=========================================================================*/
	/**
	 * @brief () 演算子オーバーロード
	 * 
	 * @param[in] stream 入力ストリームの参照.
	 * @return 入力ストリームの参照.
	 */
	IInputStream& operator ()( IInputStream& stream )
	{
		stream >> value_.r;
		stream >> value_.g;
		stream >> value_.b;
		stream >> value_.a;

		return stream;
	}
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/