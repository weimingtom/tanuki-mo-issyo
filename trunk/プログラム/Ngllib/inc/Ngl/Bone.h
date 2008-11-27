/*******************************************************************************/
/**
 * @file Bone.h.
 * 
 * @brief ボーン情報クラスヘッダファイル.
 *
 * @date 2008/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_BONE_H_
#define _NGL_BONE_H_

#include	"IBone.h"

namespace Ngl{


/**
 * @class Bone.
 * @brief ボーン情報クラス．
 */
class Bone : public IBone
{
public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	Bone();


	/*=========================================================================*/
	/**
	 * @brief ボーン情報を設定する
	 * 
	 * @param[in] ID ボーンＩＤ.
	 * @param[in] parentID 親ボーンＩＤ.
	 * @param[in] parentOffset 親ボーンからの相対座標.
	 * @param[in] matOffset ローカル座標変換行列.
	 * @return なし.
	 */
	void create( unsigned int ID, unsigned int parentID, const Vector3& parentOffset, const Matrix4& matOffset );
	
public:
	
	/*=========================================================================*/
	/**
	 * @brief 親ボーンを設定する
	 * 
	 * @param[in] parent 親ボーンのポインタ.
	 * @return なし.
	 */
	virtual void setParent( IBone* parent );

	
	/*=========================================================================*/
	/**
	 * @brief 子ボーンを設定する
	 * 
	 * @param[in] child 子ボーンのポインタ.
	 * @return なし.
	 */
	virtual void setChild( IBone* child );


	/*=========================================================================*/
	/**
	 * @brief ボーンの変換行列の計算を行う
	 * 
	 * @param[out] outMatrices 変換後の頂点配列.
	 * @param[in] parentMatrix 親の変換行列へのポインタ.
	 * @param[in] animMatrices アニメーション用変換行列.
	 * @return なし.
	 */
	virtual void calculateTransformMatrices( Matrix4* outMatrices, const Matrix4* parentMatrix, const Matrix4* animMatrices );

	
	/*=========================================================================*/
	/**
	 * @brief ボーンを座標変換する
	 * 
	 * @param[in] matrix 変換行列.
	 * @return なし.
	 */
	virtual void transform( const Matrix4& matrix );
	
	
	/*=========================================================================*/
	/**
	 * @brief ボーンIDを取得する
	 * 
	 * @param[in] なし.
	 * @return ボーンID
	 */
	virtual unsigned int getBoneID() const;


	/*=========================================================================*/
	/**
	 * @brief 親ボーンIDを取得する
	 * 
	 * @param[in] なし.
	 * @return 親ボーンID
	 */
	virtual unsigned int getParentBoneID() const;


	/*=========================================================================*/
	/**
	 * @brief 親ボーンからの相対距離を取得する
	 * 
	 * @param[in] なし.
	 * @return 親ボーンとの相対距離.
	 */
	virtual const Ngl::Vector3& getParentBoneOffset() const;


	/*=========================================================================*/
	/**
	 * @brief ローカル座標変換行列を取得する
	 * 
	 * @param[in] なし.
	 * @return ローカル座標変換行列.
	 */
	virtual const Ngl::Matrix4& getMatBoneOffset() const;
	
	
	/*=========================================================================*/
	/**
	 * @brief 親ボーンを取得する
	 * 
	 * @param[in] なし.
	 * @return 親ボーン.
	 */
	virtual IBone* parent();
	
	
	/*=========================================================================*/
	/**
	 * @brief 兄弟ボーンを取得する
	 * 
	 * @param[in] なし.
	 * @return 兄弟ボーン.
	 */
	virtual IBone* sibling();
	
	
	/*=========================================================================*/
	/**
	 * @brief 子ボーンを取得する
	 * 
	 * @param[in] なし.
	 * @return 子ボーン.
	 */
	virtual IBone* child();

private:

	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ( コピー禁止 ）
	 * 
	 * @param[in] other コピーするオブジェクト.
	 * @return なし.
	 */
	Bone( const Bone& other );


	/*=========================================================================*/
	/**
	 * @brief =演算子オーバーロード（ コピー禁止 ）
	 * 
	 * @param[in] other 代入するオブジェクト.
	 * @return 代入結果のオブジェクト.
	 */
	Bone& operator = ( const Bone& other );

private:

	/** ボーンID */
	unsigned int	boneID_;

	/** 親ボーンID */
	unsigned int	parentBoneID_;

	/** 親ボーンからの相対座標 */
	Ngl::Vector3	parentBoneOffset_;

	/** ローカル座標変換行列 */
	Ngl::Matrix4	matBoneOffset_;

	/** 親ボーンへのポインタ */
	IBone*			parent_;

	/** 兄弟ボーンへのポインタ */
	IBone*			sibling_;

	/** 子ボーンへのポインタ */
	IBone*			child_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/