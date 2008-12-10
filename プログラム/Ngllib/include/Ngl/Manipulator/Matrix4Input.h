/*******************************************************************************/
/**
 * @file Matrix4Input.h.
 * 
 * @brief 4x4行列構造体入力マニピュレータクラス定義.
 *
 * @date 2008/07/19.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MATRIX4INPUT_H_
#define _NGL_MATRIX4INPUT_H_

#include	"IInputStream.h"
#include	"Ngl/Matrix4.h"

namespace Ngl{


/**
 * @class Matrix4Input.
 * @brief 4x4行列構造体入力マニピュレータクラス.
 */
class Matrix4Input
{
	/*=========================================================================*/
	/**
	 * @brief >> 演算子オーバーロード ( マニピュレータ操作 )
	 * 
	 * @param[in] stream 入力ストリームの参照.
	 * @param[in] manip マニピュレータ.
	 * @return 入力ストリームの参照.
	 */
	friend IInputStream& operator >> ( IInputStream& stream, Matrix4Input manip )
	{
		return manip( stream );
	}

private:

	/** データを読み込む4x4行列構造体 */
	Matrix4& value_;

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] value データを読み込む4x4行列構造体.
	 */
	Matrix4Input( Matrix4& value ):
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
		for( int i=0; i<4; ++i ){
			for( int j=0; j<4; j++ ){
				stream >> value_.m[ i ][ j ];
			}
		}

		return stream;
	}
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/