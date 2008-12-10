/*******************************************************************************/
/**
 * @file Bone.cpp.
 * 
 * @brief ボーン情報クラスソースファイル.
 *
 * @date 2008/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Bone.h"
#include	<cassert>

using namespace Ngl;

/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
Bone::Bone():
	boneID_( 0 ),
	parentBoneID_( 0 ),
	parent_( 0 ),
	sibling_( 0 ),
	child_( 0 )
{
	// ローカルの座標変換行列を単位行列にする
	matBoneOffset_.setIdentitiy();
}



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
void Bone::create( unsigned int ID, unsigned int parentID, const Vector3& parentOffset, const Matrix4& matOffset )
{
	boneID_				= ID;
	parentBoneID_		= parentID;
	parentBoneOffset_	= parentOffset;
	matBoneOffset_		= matOffset;
}


	
/*=========================================================================*/
/**
 * @brief 親ボーンを設定する
 * 
 * @param[in] parent 親ボーンのポインタ.
 * @return なし.
 */
void Bone::setParent( IBone* parent )
{
	parent_ = parent;

	// 兄弟ボーンを設定する
	sibling_ = parent->child();
}


	
/*=========================================================================*/
/**
 * @brief 子ボーンを設定する
 * 
 * @param[in] child 子ボーンのポインタ.
 * @return なし.
 */
void Bone::setChild( IBone* child )
{
	child_ = child;
}
	
	

/*===========================================================================*/
/**
 * @brief ボーンの変換行列の計算を行う
 * 
 * @param[out] outMatrices 変換後の頂点配列.
 * @param[in] parentMatrix 親の変換行列へのポインタ,
 * @param[in] animMatrices アニメーション用変換行列.
 * @return なし.
 */
void Bone::calculateTransformMatrices( Matrix4* outMatrices, const Matrix4* parentMatrix, const Matrix4* animMatrices )
{
	// 変換先の行列を取得する
	Matrix4* outMatrix = &outMatrices[ boneID_ ];
	
	// 行列を初期化する
	outMatrix->setIdentitiy();

	// 親の行列が設定されているか
	if( parentMatrix != 0 ){
		// アニメーション変換行列が設定されているか
		if( animMatrices != 0 ){
			// アニメーション変換行列の取得
			*outMatrix = animMatrices[ boneID_ ];
		}

		// 親からの相対座標をモデリング変換行列に加算する
		outMatrix->m[3][0] += parentBoneOffset_.x;
		outMatrix->m[3][1] += parentBoneOffset_.y;
		outMatrix->m[3][2] += parentBoneOffset_.z;

		// 親の変換行列と合成
		*outMatrix *= *parentMatrix;
	}

	// 兄弟を持っているか
	if( sibling_ != 0 ){
		// 兄弟を計算させる
		sibling_->calculateTransformMatrices( outMatrices, parentMatrix, animMatrices );
	}

	// 子供を持っているか
	if( child_ != 0 ){
		child_->calculateTransformMatrices( outMatrices, outMatrix, animMatrices );
	}
}



/*=========================================================================*/
/**
 * @brief ボーンを座標変換する
 * 
 * @param[in] matrix 変換行列.
 * @return なし.
 */
void Bone::transform(const Matrix4 &matrix)
{
	// 兄弟がいるか
	if( sibling_ != 0 ){
		sibling_->transform( matrix );
	}

	// 子供がいるか
	if( child_ != 0 ){
		child_->transform( matrix );
	}
}



/*=========================================================================*/
/**
 * @brief ボーンIDを取得する
 * 
 * @param[in] なし.
 * @return ボーンID
 */
unsigned int Bone::getBoneID() const
{
	return boneID_;
}


/*=========================================================================*/
/**
 * @brief 親ボーンIDを取得する
 * 
 * @param[in] なし.
 * @return 親ボーンID
 */
unsigned int Bone::getParentBoneID() const
{
	return parentBoneID_;
}


/*=========================================================================*/
/**
 * @brief 親ボーンからの相対距離を取得する
 * 
 * @param[in] なし.
 * @return 親ボーンとの相対距離.
 */
const Ngl::Vector3& Bone::getParentBoneOffset() const
{
	return parentBoneOffset_;
}


/*=========================================================================*/
/**
 * @brief ローカル座標変換行列を取得する
 * 
 * @param[in] なし.
 * @return ローカル座標変換行列.
 */
const Ngl::Matrix4& Bone::getMatBoneOffset() const
{
	return matBoneOffset_;
}


/*=========================================================================*/
/**
 * @brief 兄弟ボーンを取得する
 * 
 * @param[in] なし.
 * @return 兄弟ボーン.
 */
IBone* Bone::sibling()
{
	return sibling_;
}



/*=========================================================================*/
/**
 * @brief 親ボーンを取得する
 * 
 * @param[in] なし.
 * @return 親ボーン.
 */
IBone* Bone::parent()
{
	return parent_;
}



/*=========================================================================*/
/**
 * @brief 子ボーンを取得する
 * 
 * @param[in] なし.
 * @return 子ボーン.
 */
IBone* Bone::child()
{
	return child_;
}

	
	
/*========= EOF =============================================================*/