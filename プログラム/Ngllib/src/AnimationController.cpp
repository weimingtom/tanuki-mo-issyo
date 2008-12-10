/*******************************************************************************/
/**
 * @file AnimationController.cpp.
 * 
 * @brief アニメーション操作者クラスソースファイル.
 *
 * @date 2007/09/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/AnimationController.h"
#include	<cassert>

using namespace Ngl;


/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
  * @param[in] isDeleteInstance リストからの削除時にインスタンスをdeleteするか.
 */
AnimationController::AnimationController( bool isDeleteInstance ):
	bindSkeletonID_( 0 ),					// 使用するスケルトンID
	bindAnimationID_( 0 ),					// 使用するアニメーションID
	isDeleteInstance_( isDeleteInstance )	// インスタンスを削除するか
{
	// 全ての行列を単位行列に設定
	for( int i=0; i<MATRIX_MAX; ++i ){
		transformMatrixArray_[ i ].setIdentitiy();
	}
}



/*===========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
AnimationController::~AnimationController()
{
	// 解放する
	release();
}



/*===========================================================================*/
/**
 * @brief 座標変換行列を取得する
 * 
 * @param[in] なし.
 * @return 変換行列.
 */
Matrix4* AnimationController::transform()
{
	// スケルトンデータが設定されているか
	bool result = isIDExist( bindSkeletonID_, skeletonManager_ );
	assert( result == true );

	// スケルトンの姿勢変換行列を求める
	skeletonManager_[ bindSkeletonID_ ]->calculateOrientation(
		orientMatrixArray_,
		0,
		animationMatrixArray_
	);

	//最終的な座標変換行列を作成する
	skeletonManager_[ bindSkeletonID_ ]->calculateTransform(
		transformMatrixArray_,
		orientMatrixArray_
		);

	return transformMatrixArray_;
}



/*=========================================================================*/
/**
 * @brief 座標変換行列を取得する
 * 
 * @param[in] parentMatrix 親の変換行列.
 * @return 変換行列配列.
 */
Matrix4* AnimationController::transform( const Matrix4& parentMatrix )
{
	// スケルトンデータが設定されているか
	bool result = isIDExist( bindSkeletonID_, skeletonManager_ );
	assert( result == true );

	// スケルトンの姿勢変換行列を求める
	skeletonManager_[ bindSkeletonID_ ]->calculateOrientation(
		orientMatrixArray_,
		&parentMatrix,
		animationMatrixArray_
	);

	//最終的な座標変換行列を作成する
	skeletonManager_[ bindSkeletonID_ ]->calculateTransform(
		transformMatrixArray_,
		orientMatrixArray_
		);

	return transformMatrixArray_;
}



/*=========================================================================*/
/**
 * @brief スケルトンデータを設定する
 * 
 * @param[in] id ファイルID.
 * @param[in] data 設定するスケルトンデータクラス.
 * @return なし.
 */
void AnimationController::addSkeleton( unsigned int id, ISkeleton* data )
{
	assert( data != NULL );

	// IDがすでに存在しているか
	if( isIDExist( id, skeletonManager_ ) == true ){
		// IDを削除
		eraseElement( id, skeletonManager_ );
	}

	// 指定IDに登録
	skeletonManager_[ id ] = data;
}



/*=========================================================================*/
/**
 * @brief アニメーションデータを設定する
 * 
 * @param[in] id ファイルID.
 * @param[in] data 設定するスケルトンデータクラス.
 * @return なし.
 */
void AnimationController::addAnimation( unsigned int id, IAnimation* data )
{
	assert( data != NULL );

	// IDがすでに存在しているか
	if( isIDExist( id, animationManager_ ) == true ){
		// IDを削除
		eraseElement( id, animationManager_ );
	}

	// 指定IDに登録
	animationManager_[ id ] = data;
}


	
/*===========================================================================*/
/**
 * @brief スケルトンファイルをバインドする
 * 
 * @param[in] id ファイルID.
 * @retval true バインド成功.
 * @retval false バインド失敗.
 */
bool AnimationController::bindSkeleton(unsigned int id)
{
	// IDが存在しているか
	if( isIDExist( id, skeletonManager_ ) == true){
		// IDを設定する
		bindSkeletonID_ = id;

		return true;
	}

	return false;
}



/*===========================================================================*/
/**
 * @brief アニメーションファイルをバインドする
 * 
 * @param[in] id ファイルID.
 * @param[in] no アニメーションNO.
 * @param[in] fTime アニメーションタイマ.
 * @retval true バインド成功.
 * @retval false バインド失敗.
 */	
bool AnimationController::bindAnimation(unsigned int id, unsigned int no, float fTime)
{
	// アニメーションデータが存在するか
	if( isIDExist( id, animationManager_ ) == false ){
		// 全てを単位行列に設定する
		for( unsigned int boneNo=0; boneNo<MATRIX_MAX; boneNo++ ){
			animationMatrixArray_[boneNo].setIdentitiy();
		}
		return false;
	}

	// アニメーションオブジェクトを取得する
	IAnimation* tmpAnm = animationManager_[id];

	// ボーンデータ数を取得する
	unsigned int numBones = tmpAnm->getNumBones( no );

	// アニメーションをバインド
	bindAnimation( id, no, fTime, 0, numBones-1 );

	return true;
}



/*=========================================================================*/
/**
 * @brief アニメーションファイルをバインドする
 * 
 * @param[in] desc アニメーションデータバインド記述子.
 * @retval true バインド成功.
 * @retval false バインド失敗.
 */
bool AnimationController::bindAnimation( const AnimationBindDesc& desc )
{
	return bindAnimation( desc.id, desc.no, desc.fTime );
}


	
/*===========================================================================*/
/**
 * @brief アニメーションファイルをバインドする(線形補間)
 * 
 * @param[in] id ファイルID.
 * @param[in] no アニメーションNO.
 * @param[in] fTime アニメーションタイマ.
 * @param[in] otherId 補完する要素のファイルID.
 * @param[in] otherNo 補完する要素のアニメーションNO
 * @param[in] otherFTimer 補完する要素のアニメーションタイマ
 * @param[in] fLerp 補間値
 * @retval true バインド成功.
 * @retval false バインド失敗.
 */
bool AnimationController::bindAnimation
(
	unsigned int	id,
	unsigned int	no,
	float			fTime,
	unsigned int	otherId,
	unsigned int	otherNo,
	float			otherFTimer,
	float			fLerp
)
{
	// 1のアニメーションデータが存在していないか
	if( isIDExist( id, animationManager_ ) == false ){
		return false;
	}

	// 2のアニメーションデータが存在していないか
	if( isIDExist( id, animationManager_ ) == false ){
		// アニメーション1のみバインド
		bindAnimation( id, no, fTime );
		return false;
	}

	// ボーンデータ数を取得する
	unsigned int numBones = animationManager_[id]->getNumBones( no );

	// アニメーション変換行列に設定する
	for( unsigned int BoneNo=0; BoneNo<numBones; BoneNo++ ){
		// アニメーション1のキーフレームデータを取得する
		KeyframeData data1;
		animationManager_[id]->getKeyFrame( no, BoneNo, fTime, data1 );

		// アニメーション2のキーフレームデータを取得する
		KeyframeData data2;
		animationManager_[id]->getKeyFrame( otherNo, BoneNo, otherFTimer, data2 );

		// 各キーを線形補完する
		KeyframeData uni;
		uni.position.lerp( data1.position, data2.position, fLerp );
		uni.rotate.slerp( data1.rotate, data2.rotate, fLerp );
		uni.scale.lerp( data1.scale, data2.scale, fLerp );

		// 各キーを行列に変換する
		Matrix4 matScale;
		matScale.setScale( uni.scale );
		Matrix4 matRotate;
		matRotate.fromQuaternion( uni.rotate );
		animationMatrixArray_[ BoneNo ] = matScale * matRotate;
		animationMatrixArray_[ BoneNo ].setPosition( uni.position );
	}

	return true;
}


	
/*=========================================================================*/
/**
 * @brief 指定ボーン範囲のアニメーションデータをバインドする
 * 
 * @param[in] id ファイルID.
 * @param[in] no アニメーションNO.
 * @param[in] fTime アニメーションタイマ.
 * @param[in] beginBoneNo バインド開始ボーン番号.
 * @param[in] endBoneNo バインド終了ボーン番号.
 * @retval true バインド成功.
 * @retval false バインド失敗.
 */
bool AnimationController::bindAnimation( unsigned int id, unsigned int no, float fTime, unsigned int beginBoneNo, unsigned int endBoneNo )
{
	// アニメーションオブジェクトを取得する
	IAnimation* tmpAnm = animationManager_[id];

	// アニメーション変換行列に設定する
	for( unsigned int boneNo=beginBoneNo; boneNo<=endBoneNo; boneNo++ ){
		// キーフレームデータを取得する
		KeyframeData data;
		tmpAnm->getKeyFrame( no, boneNo, fTime, data );

		// 各キーを行列に変換する
		Matrix4 matScale;
		matScale.setScale( data.scale );
		Matrix4 matRotate;
		matRotate.fromQuaternion( data.rotate );

		// 結果の行列を作成
		Matrix4 tmp;

		// 各キーを乗算する
		tmp = matScale * matRotate;

		// 平行移動キーを設定
		tmp.setPosition( data.position );

		// 配列に設定
		animationMatrixArray_[ boneNo ] = tmp;
	}

	return true;
}
	
	
	
/*=========================================================================*/
/**
 * @brief アニメーションファイルをバインドする(線形補間)
 * 
 * @param[in] desc アニメーションデータバインド記述子.
 * @param[in] otherDesc 補間要素のアニメーションデータバインド記述子.
 * @param[in] fLerp 補間値
 * @retval true バインド成功.
 * @retval false バインド失敗.
 */
bool AnimationController::bindAnimation( const AnimationBindDesc& desc, const AnimationBindDesc& otherDesc, float fLerp )
{
	return bindAnimation(
		desc.id, desc.no, desc.fTime,
		otherDesc.id, otherDesc.no, otherDesc.fTime,
		fLerp
		);
}

	
	
/*===========================================================================*/
/**
 * @brief 指定したIDのスケルトンを削除
 * 
 * @param[in] ID スケルトンのID.
 * @return なし.
 */
void AnimationController::removeSkeleton(unsigned int ID)
{
	eraseElement( ID, skeletonManager_ );
}



/*===========================================================================*/
/**
 * @brief 指定したIDのアニメーションを削除
 * 
 * @param[in] ID アニメーションのID.
 * @return なし.
 */
void AnimationController::removeAnimation(unsigned int ID)
{
	eraseElement( ID, animationManager_ );
}



/*===========================================================================*/
/**
 * @brief すべてのIDのスケルトンを削除
 * 
 * @param[in] なし.
 * @return なし.
 */
void AnimationController::clearSkeleton()
{
	clearElement( skeletonManager_ );
}
 

 
/*===========================================================================*/
/**
 * @brief すべてのIDのアニメーションを削除
 * 
 * @param[in] なし.
 * @return なし.
 */
void AnimationController::clearAnimation()
{
	clearElement( animationManager_ );
}
	 
	 
	 
/*===========================================================================*/
/**
 * @brief 指定アニメーションの終了タイマを取得する
 * 
 * @param[in] id ファイルID.
 * @param[in] no アニメーションナンバー.
 * @return 終了タイマ.
 */
unsigned int AnimationController::getEndAnimationTimer(unsigned int id, unsigned int no)
{
	// IDが存在しているか
	bool result = isIDExist( id, animationManager_ );
	assert( result == true );

	// 指定ナンバーの終了タイマーを取得する
	return animationManager_[id]->getEndTimer( no );
}

	

/*===========================================================================*/
/**
 * @brief スキンメッシュの指定ボーンの位置座標を取得する
 * 
 * @param[in] desc 取得するアニメーションデータバインド記述子.
 * @param[in] skeletonID スケルトンデータ番号.
 * @param[in] boneNo 取得するボーン番号.
 * @param[in] trans 座標変換行列.
 * @return 位置座標.
 */
Vector3 AnimationController::getBoneCurrentPosition(const AnimationBindDesc& desc, unsigned int skeletonID, unsigned int boneNo, const Matrix4& trans)
{
	// 位置座標を作成する
	Vector3 position;

	// スケルトンをバインドする
	bindSkeleton( skeletonID );

	// アニメーションをバインドする
	bindAnimation( desc.id, desc.no, desc.fTime );

	// スケルトンの姿勢変換行列を求める
	skeletonManager_[ bindSkeletonID_ ]->calculateOrientation(
			orientMatrixArray_,
			0,
			animationMatrixArray_
	);

	position.transform( orientMatrixArray_[ boneNo ] );

	// モデリング変換する
	position.transform( trans );

	return position;
}



/*===========================================================================*/
/**
 * @brief スケルトンの姿勢変換行列を取得する
 * 
 * @param[in] なし.
 * @return 位置座標.
 */
const Matrix4* AnimationController::getSkeletonOrientation(const Matrix4 &matrix)
{
	// スケルトンデータを設定
	bool result = isIDExist( bindSkeletonID_, skeletonManager_ );
	assert( result == true ); 	

	// スケルトンの姿勢変換行列を求める
	skeletonManager_[ bindSkeletonID_ ]->calculateOrientation(
		orientMatrixArray_,
		&matrix,
		animationMatrixArray_
	);

	return orientMatrixArray_;
}



/*===========================================================================*/
/**
 * @brief スケルトンの姿勢変換行列を計算する
 * 
 * @param[in] desc アニメーションデータバインド記述子.
 * @param[in] skeletonID スケルトンデータ番号.
 * @param[in] parentMatrix 親の変換行列.
 * @param[out] matrix 計算結果を格納する行列配列
 * @return なし.
 */
void AnimationController::calculateOrientation(const AnimationBindDesc &desc, unsigned int skeletonID, const Matrix4 &parentMatrix, Ngl::Matrix4 *matrix)
{
	bool result = true;	// 結果

	// スケルトンをバインドする
	result = bindSkeleton( skeletonID );
	assert( result == true );

	// アニメーションをバインドする
	result = bindAnimation( desc.id, desc.no, desc.fTime );
	assert( result == true );
	
	// 姿勢変換行列を計算する
	skeletonManager_[ bindSkeletonID_ ]->calculateOrientation(
		matrix,
		&parentMatrix,
		animationMatrixArray_
	);
}



/*===========================================================================*/
/**
 * @brief 指定スケルトンのボーン数を取得する
 * 
 * @param[in] id スケルトンID.
 * @return ボーン数.
 */
unsigned int AnimationController::getSkeletonNumBones(unsigned int id)
{
	// IDが存在しているか
	if( isIDExist( id, skeletonManager_ ) == true ){
		return skeletonManager_[id]->getNumBones();
	}

	return 0;
}



/*===========================================================================*/
/**
 * @brief 操作者を解放する
 * 
 * @param[in] なし.
 * @return なし.
 */
void AnimationController::release()
{
	// 全てのスケルトン要素を削除
	clearSkeleton();

	// 全てのアニメーション要素を削除
	clearAnimation();
}



/*========= EOF =============================================================*/