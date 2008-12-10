/*******************************************************************************/
/**
 * @file Skeleton.h.
 * 
 * @brief スケルトン情報クラスヘッダファイル.
 *
 * @date 2008/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_SKELTON_H_
#define _NGL_SKELTON_H_

#include	"Ngl/ISkeleton.h"
#include	<vector>

namespace Ngl{


/**
 * @class Skeleton.
 * @brief スケルトン情報クラス．
 */
class Skeleton : public ISkeleton
{
public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	Skeleton();


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~Skeleton();
	
	
	/*=========================================================================*/
	/**
	 * @brief ボーンを追加する
	 * 
	 * @warning 追加したボーンはSkeletonクラスで削除されます.
	 *
	 * @param[in] bone 追加するボーン.
	 * @return なし.
	 */
	void addBone( IBone* bone );
	
	
	/*=========================================================================*/
	/**
	 * @brief ボーンのリンクをする
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void linkBone();

	
	/*=========================================================================*/
	/**
	 * @brief スケルトン情報の解放
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void release();

public:

	/*=========================================================================*/
	/**
	 * @brief 姿勢変換行列を求める
	 * 
	 * @param[out] outMatrices 座標変換行列の配列.
	 * @param[in] parentMatrix 親の変換行列へのポインタ.
	 * @param[in] animMatrices アニメーション用変換行列配列.
	 * @return なし.
	 */
	virtual void calculateOrientation( Matrix4* outMatrices, const Matrix4* parentMatrix, const Matrix4* animMatrices );

	
	/*=========================================================================*/
	/**
	 * @brief 座標変換行列の計算を行う
	 * 
	 * @param[out] outMatrices 座標変換行列の配列
	 * @param[in] orientMatrices 姿勢変換行列.
	 * @return なし.
	 */
	virtual void calculateTransform( Matrix4* outMatrices, Matrix4* orientMatrices );


	/*=========================================================================*/
	/**
	 * @brief ボーンを取得する
	 * 
	 * @param[in] no 取得するボーン番号.
	 * @return ボーンのポインタ.
	 */
	virtual IBone* getBones( unsigned int no );
	
	
	/*=========================================================================*/
	/**
	 * @brief ボーンの数を取得する
	 * 
	 * @param[in] なし.
	 * @return ボーン数.
	 */
	virtual unsigned int getNumBones() const;

private:

	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ( コピー禁止 ）
	 * 
	 * @param[in] other コピーするオブジェクト.
	 * @return なし.
	 */
	Skeleton( const Skeleton& other );


	/*=========================================================================*/
	/**
	 * @brief =演算子オーバーロード（ コピー禁止 ）
	 * 
	 * @param[in] other 代入するオブジェクト.
	 * @return 代入結果のオブジェクト.
	 */
	Skeleton& operator = ( const Skeleton& other );
	

	/*=========================================================================*/
	/**
	 * @brief 親ボーンと子ボーンをリンクする
	 * 
	 * @param[in] parent 親ボーン.
	 * @param[in] child 子ボーン.
	 * @return なし.
	 */
	void addChild( IBone* parent, IBone* child );

private:

	/** ボーン情報配列型 */
	typedef std::vector< IBone* >	BoneArray;

private:

	/** ボーン配列へのポインタ */
	BoneArray		bones_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/