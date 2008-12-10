/*******************************************************************************/
/**
 * @file Vector4Input.h.
 * 
 * @brief 4次元ベクトル構造体入力マニピュレータクラス定義.
 *
 * @date 2008/08/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_VECTOR4INPUT_H_
#define _NGL_VECTOR4INPUT_H_

#include	"IInputStream.h"
#include	"Ngl/Vector4.h"

namespace Ngl{


/**
 * @class Vector4Input.
 * @brief 4次元ベクトル構造体入力マニピュレータクラス.
 */
class Vector4Input
{
	/*=========================================================================*/
	/**
	 * @brief >> 演算子オーバーロード ( マニピュレータ操作 )
	 * 
	 * @param[in] stream 入力ストリームの参照.
	 * @param[in] manip マニピュレータ.
	 * @return 入力ストリームの参照.
	 */
	friend IInputStream& operator >> ( IInputStream& stream, Vector4Input manip )
	{
		return manip( stream );
	}

private:

	/** データを読み込む4次元構造体 */
	Vector4& value_;

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] value データを読み込む3次元ベクトル構造体.
	 */
	Vector4Input( Vector4& value ):
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
		stream >> value_.z;
		stream >> value_.w;

		return stream;
	}
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/