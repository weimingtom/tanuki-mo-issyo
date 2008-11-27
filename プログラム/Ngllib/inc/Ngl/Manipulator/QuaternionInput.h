/*******************************************************************************/
/**
 * @file QuaternionInput.h.
 * 
 * @brief クォータニオン構造体入力マニピュレータクラス定義.
 *
 * @date 2008/07/19.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_QUATERNIONINPUT_H_
#define _NGL_QUATERNIONINPUT_H_

#include	"IInputStream.h"
#include	"Ngl/Quaternion.h"

namespace Ngl{


/**
 * @class QuaternionInput
 * @brief クォータニオン構造体入力マニピュレータクラス.
 */
class QuaternionInput
{
	/*=========================================================================*/
	/**
	 * @brief >> 演算子オーバーロード ( マニピュレータ操作 )
	 * 
	 * @param[in] stream 入力ストリームの参照.
	 * @param[in] manip マニピュレータ.
	 * @return 入力ストリームの参照.
	 */
	friend IInputStream& operator >> ( IInputStream& stream, QuaternionInput manip )
	{
		return manip( stream );
	}

private:

	/** データを読み込むクォータニオン構造体 */
	Quaternion& value_;

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] value データを読み込むクォータニオン構造体.
	 */
	QuaternionInput( Quaternion& value ):
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