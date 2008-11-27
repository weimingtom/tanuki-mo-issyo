/*******************************************************************************/
/**
 * @file Vector2Input.h.
 * 
 * @brief 2次元ベクトル構造体入力マニピュレータクラス定義.
 *
 * @date 2008/07/19.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_VECTOR2INPUT_H_
#define _NGL_VECTOR2INPUT_H_

#include	"IInputStream.h"
#include	"Ngl/Vector2.h"

namespace Ngl{


/**
 * @class Vector2Input
 * @brief 2次元ベクトル構造体入力マニピュレータクラス.
 */
class Vector2Input
{
	/*=========================================================================*/
	/**
	 * @brief >> 演算子オーバーロード ( マニピュレータ操作 )
	 * 
	 * @param[in] stream 入力ストリームの参照.
	 * @param[in] manip マニピュレータ.
	 * @return 入力ストリームの参照.
	 */
	friend IInputStream& operator >> ( IInputStream& stream, Vector2Input manip )
	{
		return manip( stream );
	}

private:

	/** データを読み込む2次元構造体 */
	Vector2& value_;

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] value データを読み込む3次元ベクトル構造体.
	 */
	Vector2Input( Vector2& value ):
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
		stream >> value_.x;
		stream >> value_.y;

		return stream;
	}
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/