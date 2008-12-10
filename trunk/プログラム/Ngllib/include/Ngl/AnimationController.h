/*******************************************************************************/
/**
 * @file AnimationController.h.
 * 
 * @brief アニメーション操作クラスヘッダファイル.
 *
 * @date 2008/07/02.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ANIMATIONCONTROLLER_H_
#define _NGL_ANIMATIONCONTROLLER_H_

#include	"Ngl/ISkeleton.h"
#include	"Ngl/IAnimation.h"
#include	"Ngl/Matrix4.h"
#include	<map>

namespace Ngl{


/**
 * @struct AnimationBindDesc．
 * @brief アニメーションデータバインド記述子.
 */
struct AnimationBindDesc
{
	/** バインドするアニメーションデータID */
	unsigned int	id;

	/** アニメーション番号 */
	unsigned int	no;

	/** アニメーションの描画フレームタイム */
	float			fTime;
};


/**
 * @class AnimationController.
 * @brief アニメーション操作者クラス．
 */
class AnimationController
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] isDeleteInstance リストからの削除時にインスタンスをdeleteするか.
	 */
	AnimationController( bool isDeleteInstance=true );


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~AnimationController();


	/*=========================================================================*/
	/**
	 * @brief 座標変換行列を取得する
	 * 
	 * @param[in] なし.
	 * @return 変換行列配列.
	 */
	Matrix4* transform();
	
	
	/*=========================================================================*/
	/**
	 * @brief 座標変換行列を取得する
	 * 
	 * @param[in] parentMatrix　親の変換行列.
	 * @return 変換行列配列.
	 */
	Matrix4* transform( const Matrix4& parentMatrix );
	
	
	/*=========================================================================*/
	/**
	 * @brief スケルトンデータを設定する
	 * 
	 * @param[in] id ファイルID.
	 * @param[in] data 設定するスケルトンデータクラス.
	 * @return なし.
	 */
	void addSkeleton( unsigned int id, ISkeleton* data );


	/*=========================================================================*/
	/**
	 * @brief アニメーションデータを設定する
	 * 
	 * @param[in] id ファイルID.
	 * @param[in] data 設定するスケルトンデータクラス.
	 * @return なし.
	 */
	void addAnimation( unsigned int id, IAnimation* data );
	
	
	/*=========================================================================*/
	/**
	 * @brief スケルトンファイルをバインドする
	 * 
	 * @param[in] id ファイルID.
	 * @retval true バインド成功.
	 * @retval false バインド失敗.
	 */
	bool bindSkeleton( unsigned int id );
	
	
	/*=========================================================================*/
	/**
	 * @brief 指定したIDのスケルトンを削除
	 * 
	 * @param[in] ID スケルトンのID.
	 * @return なし.
	 */
	 void removeSkeleton( unsigned int ID );
	 
	 
	/*=========================================================================*/
	/**
	 * @brief すべてのIDのアニメーションを削除
	 * 
	 * @param[in] ID アニメーションのID.
	 * @return なし.
	 */
	 void removeAnimation( unsigned int ID );
	 
	 
	/*=========================================================================*/
	/**
	 * @brief すべてのIDのスケルトンを削除
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	 void clearSkeleton();
	 
	 
	/*=========================================================================*/
	/**
	 * @brief 指定したIDのアニメーションを削除
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	 void clearAnimation();
	 
	 
	/*=========================================================================*/
	/**
	 * @brief アニメーションファイルをバインドする
	 * 
	 * @param[in] id ファイルID.
	 * @param[in] no アニメーションNO.
	 * @param[in] fTime アニメーションタイマ.
	 * @retval true バインド成功.
	 * @retval false バインド失敗.
	 */
	bool bindAnimation( unsigned int id, unsigned int no, float fTime );
	
	
	/*=========================================================================*/
	/**
	 * @brief アニメーションファイルをバインドする
	 * 
	 * @param[in] desc アニメーションデータバインド記述子.
	 * @retval true バインド成功.
	 * @retval false バインド失敗.
	 */
	bool bindAnimation( const AnimationBindDesc& desc );
		
	
	/*=========================================================================*/
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
	bool bindAnimation(
		unsigned int	id,
		unsigned int	no,
		float			fTime,
		unsigned int	otherId,
		unsigned int	otherNo,
		float			otherFTimer,
		float			fLerp
		);
	
	
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
	bool bindAnimation( unsigned int id, unsigned int no, float fTime, unsigned int beginBoneNo, unsigned int endBoneNo );

	
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
	bool bindAnimation( const AnimationBindDesc& desc, const AnimationBindDesc& otherDesc, float fLerp );
	
	
	/*=========================================================================*/
	/**
	 * @brief 指定アニメーションの終了タイマを取得する
	 * 
	 * @param[in] id ファイルID.
	 * @param[in] no アニメーションナンバー.
	 * @return 終了タイマ.
	 */
	unsigned int getEndAnimationTimer( unsigned int id, unsigned int no );
	
	
	/*=========================================================================*/
	/**
	 * @brief スキンメッシュの指定ボーンの位置座標を取得する
	 * 
	 * @param[in] desc 取得するアニメーションデータバインド記述子.
	 * @param[in] skeletonID スケルトンデータ番号.
	 * @param[in] boneNo 取得するボーン番号.
	 * @param[in] trans 座標変換行列.
	 * @return 位置座標.
	 */
	Vector3 getBoneCurrentPosition( const AnimationBindDesc& desc, unsigned int skeletonID, unsigned int boneNo, const Matrix4& trans );
	
	
	/*=========================================================================*/
	/**
	 * @brief スケルトンの姿勢変換行列を取得する
	 * 
	 * @param[in] matrix 親の変換行列.
	 * @return 位置座標.
	 */
	const Matrix4* getSkeletonOrientation( const Matrix4& matrix );

	
	/*=========================================================================*/
	/**
	 * @brief スケルトンの姿勢変換行列を計算する
	 * 
	 * @param[in] desc アニメーションデータバインド記述子.
	 * @param[in] skeletonID スケルトンデータ番号.
	 * @param[in] parentMatrix 親の変換行列.
	 * @param[out] matrix 計算結果を格納する行列配列
	 * @return なし.
	 */
	void calculateOrientation( const AnimationBindDesc& desc, unsigned int skeletonID, const Matrix4& parentMatrix, Matrix4* matrix );
	
	
	/*=========================================================================*/
	/**
	 * @brief 指定スケルトンのボーン数を取得する
	 * 
	 * @param[in] id スケルトンID.
	 * @return ボーン数.
	 */
	unsigned int getSkeletonNumBones( unsigned int id );
	
		
	/*=========================================================================*/
	/**
	 * @brief 操作者を解放する
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void release();


	/*=========================================================================*/
	/**
	 * @brief 管理者に指定のIDが存在するか検索する
	 * 
	 * @param[in] id ID.
	 * @param[in] manager 管理者.
	 * @retval true 存在する.
	 * @retval false 存在しない.
	 */
	 template< typename Manager >
	 bool isIDExist( unsigned int id, Manager& manager ){
		 // IDがすでに設定されているか
		Manager::iterator i = manager.find( id );
		if( i != manager.end() ){
			// ＩＤが設定されていた
			return true;
		}

		// 存在していない
		return false;
	 }
	 
	 
	/*=========================================================================*/
	/**
	 * @brief 管理者から指定IDの要素を削除する
	 * 
	 * @param[in] id ID.
	 * @param[in] manager 管理者.
	 * @return なし.
	 */
	 template< typename Manager >
	 void eraseElement( unsigned int id, Manager& manager )
	 {
		Manager::iterator itor;
		for( itor = manager.begin(); itor!=manager.end(); ++itor ){
			if( itor->first == id ){
				if( isDeleteInstance_ ){
					// リストから削除
					delete (*itor).second;
				}
				manager.erase( itor );

				break;
			}
		}
	 }


	/*=========================================================================*/
	/**
	 * @brief 管理者からすべての要素を削除する
	 * 
	 * @param[in] manager 管理者.
	 * @return なし.
	 */
	 template< typename Manager >
	 void clearElement( Manager& manager )
	 {
		Manager::iterator itor = manager.begin();
		while( itor != manager.end() ){
			if( isDeleteInstance_ ){
				delete (*itor).second;
			}
			itor = manager.erase( itor );
		}
	 }

 private:

	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ（コピー禁止）
	 * 
	 * @param[in] other コピーするオブジェクト.
	 */
	AnimationController( const AnimationController& other );


	/*=========================================================================*/
	/**
	 * @brief = 演算子オーバーロード（コピー禁止）
	 * 
	 * @param[in] other 代入するオブジェクト.
	 * @return 代入結果のオブジェクト.
	 */
	AnimationController& operator = ( const AnimationController& other );

public:

	/** 行列の最大数 */
	static const unsigned int MATRIX_MAX = 1024;

private:

	/** スケルトン管理者の型 */
	typedef std::map< unsigned int, ISkeleton* >		SkeletonManager;

	/** アニメーション管理者型 */
	typedef std::map< unsigned int, IAnimation* >		AnimationManager;

private:

	/** インスタンスを削除するか */
	bool				isDeleteInstance_;

	/** 使用するスケルトンID */
	unsigned int		bindSkeletonID_;

	/** 使用するアニメーションID */
	unsigned int		bindAnimationID_;
	
	/** スケルトン管理者 */
	SkeletonManager		skeletonManager_;
	
	/** アニメーション管理者 */
	AnimationManager	animationManager_;

	/** アニメーション変換行列配列 */
	Matrix4				animationMatrixArray_[ MATRIX_MAX ];

	/** 姿勢変換行列配列 */
	Matrix4				orientMatrixArray_[ MATRIX_MAX ];

	/** 座標変換行列配列 */
	Matrix4				transformMatrixArray_[ MATRIX_MAX ];

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/