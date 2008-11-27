/*******************************************************************************/
/**
 * @file KeyFrame.h.
 * 
 * @brief アニメーションキーフレーム情報クラスヘッダファイル.
 *
 * @date 2008/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentaru Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_KEYFRAME_H_
#define _NGL_KEYFRAME_H_

#include	"Ngl/IKeyframe.h"
#include	<vector>

namespace Ngl{


/**
 * @struct ScaleKey.
 * @brief 拡大縮小キー構造体.
 */
struct ScaleKey
{
	/** フレームタイマ */
	unsigned int	frameTimer;

	/** キー値 */
	Vector3			value;
};


/**
 * @struct RotateKey.
 * @brief 回転キー構造体.
 */
struct RotateKey
{
	/** フレームタイマ */
	unsigned int	frameTimer;

	/** キー値 */
	Quaternion		value;
};


/** 
 * @struct PositionKey.
 * @brief 平行移動キー構造体.
 */
struct PositionKey
{
	/** フレームタイマ */
	unsigned int	frameTimer;

	/** キー値 */
	Vector3			value;
};


/**
 * @class KeyFrame
 * @brief アニメーションキーフレームクラス．
 */
class KeyFrame : public IKeyframe
{	

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	KeyFrame();


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~KeyFrame();


	/*=========================================================================*/
	/**
	 * @brief 拡大縮小キーを追加
	 * 
	 * @warning 設定されたキーはKeyFrameクラスで削除されます.
	 *
	 * @param[in] key 設定するキー.
	 * @return なし.
	 */
	void addKey( ScaleKey* key );


	/*=========================================================================*/
	/**
	 * @brief 回転キーを追加
	 * 
	 * @warning 設定されたキーはKeyFrameクラスで削除されます.
	 *
	 * @param[in] key 設定するキー.
	 * @return なし.
	 */
	void addKey( RotateKey* key );


	/*=========================================================================*/
	/**
	 * @brief 平行移動キーを追加
	 * 
	 * @warning 設定されたキーはKeyFrameクラスで削除されます.
	 *
	 * @param[in] key 設定するキー.
	 * @return なし.
	 */
	void addKey( PositionKey* key );
	
public:

	/*=========================================================================*/
	/**
	 * @brief キーフレームデータの取得
	 * 
	 * @param[in] globalTime 取得するキーのタイマ.
	 * @param[out] data キーフレームデータ.
	 * @return キーフレームデータ.
	 */
	virtual KeyframeData& getKey( float globalTime, KeyframeData& data );
	
	
	/*=========================================================================*/
	/**
	 * @brief 指定の拡大縮小キーのフレームタイムを取得する
	 * 
	 * @param[in] no 拡大縮小キー番号.
	 * @return フレームタイマ.
	 */
	virtual unsigned int getScaleKeyFrameTime( unsigned int no ) const;


	/*=========================================================================*/
	/**
	 * @brief 指定の回転キーのフレームタイムを取得する
	 * 
	 * @param[in] no 回転キー番号.
	 * @return フレームタイマ.
	 */
	virtual unsigned int getRotateKeyFrameTime( unsigned int no ) const;


	/*=========================================================================*/
	/**
	 * @brief 指定の平行移動キーのフレームタイムを取得する
	 * 
	 * @param[in] no 平行移動キー番号.
	 * @return フレームタイマ.
	 */
	virtual unsigned int getPositionKeyFrameTime( unsigned int no ) const;
	
	
	/*=========================================================================*/
	/**
	 * @brief 拡大縮小キー数を取得する
	 * 
	 * @param[in] なし.
	 * @return 拡大縮小キー数.
	 */
	virtual unsigned int getNumScaleKeys() const;


	/*=========================================================================*/
	/**
	 * @brief 回転キー数を取得する
	 * 
	 * @param[in] なし.
	 * @return 回転キー数.
	 */
	virtual unsigned int getNumRotateKeys() const;
	

	/*=========================================================================*/
	/**
	 * @brief 平行移動キー数を取得する
	 * 
	 * @param[in] なし.
	 * @return 平行移動キー数.
	 */
	virtual unsigned int getNumPositionKeys() const;

private:

	/*=========================================================================*/
	/**
	 * @brief キーフレーム情報を開放する
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void release();


	/*=========================================================================*/
	/**
	 * @brief 拡大縮小キーを取得する
	 * 
	 * @param[in] globalTime 取得するキーのフレームタイム.
	 * @param[out] ret 取得したキー.
	 * @return 平行移動キー数.
	 */
	void getScaleKeys( float globalTime, Vector3& ret );
	
	
	/*=========================================================================*/
	/**
	 * @brief 回転キーを取得する
	 * 
	 * @param[in] globalTime 取得するキーのフレームタイム.
	 * @param[out] ret 取得したキー.
	 * @return 平行移動キー数.
	 */
	void getRotateKeys( float globalTime, Quaternion& ret );

	
	/*=========================================================================*/
	/**
	 * @brief 平行移動キーを取得する
	 * 
	 * @param[in] globalTime 取得するキーのフレームタイム.
	 * @param[out] ret 取得したキー.
	 * @return 平行移動キー数.
	 */
	void getPositionKeys( float globalTime, Vector3& ret );

private:

	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ(コピー禁止)
	 * 
	 * @param[in] other コピーするオブジェクト.
	 * @return なし.
	 */
	KeyFrame( const KeyFrame& other );


	/*=========================================================================*/
	/**
	 * @brief = 演算子オーバーロード(コピー禁止)
	 * 
	 * @param[in] other 代入するするオブジェクト.
	 * @return 代入結果のオブジェクト.
	 */
	KeyFrame& operator = ( const KeyFrame& other );

private:

	/** 拡大縮小キー配列型 */
	typedef std::vector< ScaleKey* >	ScaleKeyArray;

	/** 回転キー配列型 */
	typedef std::vector< RotateKey* >	RotateKeyArray;

	/** 平行移動キー配列型 */
	typedef std::vector< PositionKey* >	PositionKeyArray;

private:

	/** 拡大縮小キー配列へのポインタ */
	ScaleKeyArray		scaleKeys_;

	/** 回転キー配列へのポインタ */
	RotateKeyArray		rotateKeys_;

	/** 平行移動キー配列へのポインタ */
	PositionKeyArray	positionKeys_;
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/