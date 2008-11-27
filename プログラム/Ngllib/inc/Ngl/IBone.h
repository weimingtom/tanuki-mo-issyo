/*******************************************************************************/
/**
 * @file IBone.h.
 * 
 * @brief ボーン情報インターフェース定義.
 *
 * @date 2008/07/01.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IBONE_H_
#define _NGL_IBONE_H_

#include	"Ngl/Vector3.h"
#include	"Ngl/Matrix4.h"

namespace Ngl{


/**
 * @interface IBone
 * @brief ボーン情報インターフェース．
 */
class IBone
{
public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IBone() {}


	/*=========================================================================*/
	/**
	 * @brief 親ボーンを設定する
	 * 
	 * @param[in] parent 親ボーンのポインタ.
	 * @return なし.
	 */
	virtual void setParent( IBone* parent ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief 子ボーンを設定する
	 * 
	 * @param[in] child 子ボーンのポインタ.
	 * @return なし.
	 */
	virtual void setChild( IBone* child ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief ボーンの変換行列の計算を行う
	 * 
	 * @param[out] outMatrices 変換後の頂点配列.
	 * @param[in] parentMatrix 親の変換行列へのポインタ.
	 * @param[in] animMatrices アニメーション用変換行列.
	 * @return なし.
	 */
	virtual void calculateTransformMatrices( Matrix4* outMatrices, const Matrix4* parentMatrix, const Matrix4* animMatrices ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief ボーンを座標変換する
	 * 
	 * @param[in] matrix 変換行列.
	 * @return なし.
	 */
	virtual void transform( const Matrix4& matrix ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief ボーンIDを取得する
	 * 
	 * @param[in] なし.
	 * @return ボーンID
	 */
	virtual unsigned int getBoneID() const = 0;


	/*=========================================================================*/
	/**
	 * @brief 親ボーンIDを取得する
	 * 
	 * @param[in] なし.
	 * @return 親ボーンID
	 */
	virtual unsigned int getParentBoneID() const = 0;


	/*=========================================================================*/
	/**
	 * @brief 親ボーンからの相対距離を取得する
	 * 
	 * @param[in] なし.
	 * @return 親ボーンとの相対距離.
	 */
	virtual const Ngl::Vector3& getParentBoneOffset() const = 0;


	/*=========================================================================*/
	/**
	 * @brief ローカル座標変換行列を取得する
	 * 
	 * @param[in] なし.
	 * @return ローカル座標変換行列.
	 */
	virtual const Ngl::Matrix4& getMatBoneOffset() const = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 親ボーンを取得する
	 * 
	 * @param[in] なし.
	 * @return 親ボーン.
	 */
	virtual IBone* parent() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 兄弟ボーンを取得する
	 * 
	 * @param[in] なし.
	 * @return 兄弟ボーン.
	 */
	virtual IBone* sibling() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 子ボーンを取得する
	 * 
	 * @param[in] なし.
	 * @return 子ボーン.
	 */
	virtual IBone* child() = 0;

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/