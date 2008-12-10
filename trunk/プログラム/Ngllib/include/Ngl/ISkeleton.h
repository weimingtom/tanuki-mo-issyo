/*******************************************************************************/
/**
 * @file ISkeleton.h.
 * 
 * @brief スケルトン情報インターフェース定義.
 *
 * @date 2008/07/01.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ISKELTON_H_
#define _NGL_ISKELTON_H_

#include	"Ngl/IBone.h"
#include	"Ngl/Matrix4.h"

namespace Ngl{


/**
 * @interface ISkeleton.
 * @brief スケルトン情報インターフェース．
 */
class ISkeleton
{
public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~ISkeleton(){}


	/*=========================================================================*/
	/**
	 * @brief 姿勢変換行列を求める
	 * 
	 * @param[out] outMatrices 座標変換行列の配列.
	 * @param[in] parentMatrix 親の変換行列へのポインタ.
	 * @param[in] animMatrices アニメーション用変換行列配列.
	 * @return なし.
	 */
	virtual void calculateOrientation( Matrix4* outMatrices, const Matrix4* parentMatrix, const Matrix4* animMatrices ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 座標変換行列の計算を行う
	 * 
	 * @param[out] outMatrices 座標変換行列の配列
	 * @param[in] orientMatrices 姿勢変換行列.
	 * @return なし.
	 */
	virtual void calculateTransform( Matrix4* outMatrices, Matrix4* orientMatrices ) = 0;


	/*=========================================================================*/
	/**
	 * @brief ボーンの数を取得する
	 * 
	 * @param[in] なし.
	 * @return ボーン数.
	 */
	virtual unsigned int getNumBones() const = 0;

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/