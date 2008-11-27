/*******************************************************************************/
/**
 * @file Skeleton.cpp.
 * 
 * @brief スケルトン情報クラスソースファイル.
 *
 * @date 2008/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Skeleton.h"
#include	"Ngl/Bone.h"
#include	<cassert>

using namespace Ngl;

/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
Skeleton::Skeleton()
{}



/*===========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
Skeleton::~Skeleton()
{
	// ボーンを解放する
	release();
}

	
	
/*=========================================================================*/
/**
 * @brief ボーンを追加する
 * 
 * @warning 追加したボーンはSkeletonクラスで削除されます.
 *
 * @param[in] bone 追加するボーン.
 * @return なし.
 */
void Skeleton::addBone( IBone* bone )
{
	bones_.push_back( bone );
}

	
	
/*===========================================================================*/
/**
 * @brief ボーンのリンクをする
 * 
 * @param[in] なし.
 * @return なし.
 */
void Skeleton::linkBone()
{
	for( unsigned int i=0; i<bones_.size(); i++ ){
		// 親ボーンを取得する
		IBone* tmpParent = bones_[i];
		for( unsigned int j=1; j<bones_.size(); j++ ){
			// 子ボーンを取得する
			IBone* tmpChild = bones_[j];

			// 親ボーンのIDを持っている子ボーンか
			if( tmpParent->getBoneID() == tmpChild->getParentBoneID() ){
				// 親ボーンに子ボーンをリンクさせる
				addChild( tmpParent, tmpChild );
			}
		}
	}
}



/*===========================================================================*/
/**
 * @brief スケルトン情報の解放
 * 
 * @param[in] なし.
 * @return なし.
 */
void Skeleton::release()
{
	BoneArray::iterator itor = bones_.begin();
	while( itor != bones_.end() ){
		delete *itor;
		itor = bones_.erase( itor );
	}
}



/*===========================================================================*/
/**
 * @brief 姿勢変換行列を求める
 * 
 * @param[out] outMatrices 座標変換行列の配列.
 * @param[in] parentMatrix 親の変換行列へのポインタ.
 * @param[in] animMatrices アニメーション用変換行列配列.
 * @return なし.
 */
void Skeleton::calculateOrientation( Matrix4* outMatrices, const Matrix4* parentMatrix, const Matrix4* animMatrices )
{
	// 各ボーンの座標変換を行う
	bones_[0]->calculateTransformMatrices( outMatrices, parentMatrix, animMatrices );
}



/*===========================================================================*/
/**
 * @brief 座標変換行列の計算を行う
 * 
 * @param[out] outMatrices 座標変換行列の配列
 * @param[in] orientMatrices 姿勢変換行列.
 * @return なし.
 */
void Skeleton::calculateTransform( Matrix4* outMatrices, Matrix4* orientMatrices )
{
	// ローカル座標変換行列と姿勢変換行列を合成する
	for( unsigned int i=0; i<bones_.size(); i++ ){
		outMatrices[i] = bones_[i]->getMatBoneOffset() * orientMatrices[i];
	}
}



/*=========================================================================*/
/**
 * @brief ボーンの数を取得する
 * 
 * @param[in] なし.
 * @return ボーン数.
 */
unsigned int Skeleton::getNumBones() const
{
	return static_cast< unsigned int >( bones_.size() );
}

	

/*===========================================================================*/
/**
 * @brief 親ボーンと子ボーンをリンクする
 * 
 * @param[in] parent 親ボーン.
 * @param[in] child 子ボーン.
 * @return なし.
 */
void Skeleton::addChild(IBone *parent, IBone *child)
{
	// 各ポインタのリンクをする
	child->setParent( parent );
	parent->setChild( child );
}



/*========= EOF =============================================================*/