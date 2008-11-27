/*******************************************************************************/
/**
 * @file KeyFrame.cpp.
 * 
 * @brief アニメーションキーフレーム情報クラスソースファイル.
 *
 * @date 2007/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/KeyFrame.h"
#include	<cmath>
#include	<memory>

using namespace Ngl;

/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
KeyFrame::KeyFrame()
{}



/*===========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
KeyFrame::~KeyFrame()
{
	// キーフレーム情報を開放する
	release();
}



/*=========================================================================*/
/**
 * @brief 拡大縮小キーを追加
 * 
 * @warning 設定されたキーはKeyFrameクラスで削除されます.
 *
 * @param[in] key 設定するキー.
 * @return なし.
 */
void KeyFrame::addKey( ScaleKey* key )
{
	scaleKeys_.push_back( key );
}



/*=========================================================================*/
/**
 * @brief 回転キーを追加
 * 
 * @warning 設定されたキーはKeyFrameクラスで削除されます.
 *
 * @param[in] key 設定するキー.
 * @return なし.
 */
void KeyFrame::addKey( RotateKey* key )
{
	rotateKeys_.push_back( key );
}



/*=========================================================================*/
/**
 * @brief 平行移動キーを追加
 * 
 * @warning 設定されたキーはKeyFrameクラスで削除されます.
 *
 * @param[in] key 設定するキー.
 * @return なし.
 */
void KeyFrame::addKey( PositionKey* key )
{
	positionKeys_.push_back( key );
}

	
	
/*===========================================================================*/
/**
 * @brief キーフレームデータの取得
 * 
 * @param[in] globalTime 取得するキーのタイマ.
 * @param[out] data キーフレームデータ.
 * @return キーフレームデータ.
 */
KeyframeData& KeyFrame::getKey(float globalTime, KeyframeData& data)
{
	// 各キーの値を初期化する
	data.scale.initialize( 1.0f, 1.0f, 1.0f );
	data.rotate.setIdentity();
	data.position.zero();

	// 拡大縮小キーを持っているか
	if( scaleKeys_.empty() == false ){
		// 拡大縮小キーを取得する
		getScaleKeys( globalTime, data.scale );
	}

	// 回転キーを持っているか
	if( rotateKeys_.empty() == false ){
		// 回転キーを取得する
		getRotateKeys( globalTime, data.rotate );

		// 回転キーを正規化する
		data.rotate.normalize();
	}

	// 平行移動キーを持っているか
	if( positionKeys_.empty() == false ){
		// 平行移動キーを取得する
		getPositionKeys( globalTime, data.position );
	}

	return data;
}



/*===========================================================================*/
/**
 * @brief 指定の拡大縮小キーのフレームタイムを取得する
 * 
 * @param[in] no 拡大縮小キー番号.
 * @return フレームタイマ.
 */
unsigned int KeyFrame::getScaleKeyFrameTime( unsigned int no ) const
{
	// 番号がデータ数よりも大きいか
	if( no > scaleKeys_.size() ){
		return 0;
	}

	// フレームタイマを取得して返す
	return scaleKeys_[ no ]->frameTimer;
}



/*===========================================================================*/
/**
 * @brief 指定の回転キーのフレームタイムを取得する
 * 
 * @param[in] no 回転キー番号.
 * @return フレームタイマ.
 */
unsigned int KeyFrame::getRotateKeyFrameTime(unsigned int no) const
{
	// 番号がデータ数よりも大きいか
	if( no > rotateKeys_.size() ){
		return 0;
	}

	// フレームタイマを取得して返す
	return rotateKeys_[ no ]->frameTimer;
}



/*===========================================================================*/
/**
 * @brief 指定の平行移動キーのフレームタイムを取得する
 * 
 * @param[in] no 平行移動キー番号.
 * @return フレームタイマ.
 */
unsigned int KeyFrame::getPositionKeyFrameTime(unsigned int no) const
{
	// 番号がデータ数よりも大きいか
	if( no > positionKeys_.size() ){
		return 0;
	}

	// フレームタイマを取得して返す
	return positionKeys_[ no ]->frameTimer;
}



/*=========================================================================*/
/**
 * @brief 拡大縮小キー数を取得する
 * 
 * @param[in] なし.
 * @return 拡大縮小キー数.
 */
unsigned int KeyFrame::getNumScaleKeys() const
{
	return static_cast< unsigned int >( scaleKeys_.size() );
}



/*=========================================================================*/
/**
 * @brief 回転キー数を取得する
 * 
 * @param[in] なし.
 * @return 回転キー数.
 */
unsigned int KeyFrame::getNumRotateKeys() const
{
	return static_cast< unsigned int >( rotateKeys_.size() );
}



/*=========================================================================*/
/**
 * @brief 平行移動キー数を取得する
 * 
 * @param[in] なし.
 * @return 平行移動キー数.
 */
unsigned int KeyFrame::getNumPositionKeys() const
{
	return static_cast< unsigned int >( positionKeys_.size() );
}


	
/*===========================================================================*/
/**
 * @brief キーフレーム情報を開放する
 * 
 * @param[in] なし.
 * @return なし.
 */
void KeyFrame::release()
{
	// 拡大縮小キー配列を解放
	ScaleKeyArray::iterator scaleitor=scaleKeys_.begin();
	while( scaleitor != scaleKeys_.end() ){
		delete *scaleitor;
		scaleitor = scaleKeys_.erase( scaleitor );
	}

	// 回転キー配列を解放
	RotateKeyArray::iterator rotateitor=rotateKeys_.begin();
	while( rotateitor != rotateKeys_.end() ){
		delete *rotateitor;
		rotateitor = rotateKeys_.erase( rotateitor );
	}

	// 平行移動キー配列を解放
	PositionKeyArray::iterator positionitor=positionKeys_.begin();
	while( positionitor != positionKeys_.end() ){
		delete *positionitor;
		positionitor = positionKeys_.erase( positionitor );
	}
}



/*===========================================================================*/
/**
 * @brief 拡大縮小キーを取得する
 * 
 * @param[in] globalTime 取得するキーのフレームタイム.
 * @param[out] ret 取得したキー.
 * @return 平行移動キー数.
 */
void KeyFrame::getScaleKeys( float globalTime, Vector3 &ret )
{
	unsigned int numKeys = (unsigned int)scaleKeys_.size();	// キー数

	// 剰余を求める
	float fTime = (float)fmod( globalTime, static_cast<float>(scaleKeys_[ numKeys-1 ]->frameTimer) );

	// キー値を初期化
	unsigned int iKey1 = 0;
	unsigned int iKey2 = 0;

	for( unsigned int iKey=0; iKey<numKeys; iKey++ ){
		if( (float)scaleKeys_[iKey]->frameTimer > fTime ){
			iKey2 = iKey;

			if( iKey > 0 ){
				iKey1 = iKey - 1;
			}
			else{
				iKey1 = iKey;
			}
			break;
		}
	}

	float fTime1 = (float)scaleKeys_[iKey1]->frameTimer;
	float fTime2 = (float)scaleKeys_[iKey2]->frameTimer;

	float fLerpTime = 0.0f;
	if( ( fTime2 - fTime1 ) == 0 ){
		fLerpTime = 0.0f;
	}
	else{
		fLerpTime = ( fTime - fTime1 ) / ( fTime2 - fTime1 );
	}

	// キーの補間を行う
	ret.lerp( scaleKeys_[iKey1]->value, scaleKeys_[iKey2]->value, fLerpTime );
}



/*===========================================================================*/
/**
 * @brief 回転キーを取得する
 * 
 * @param[in] globalTime 取得するキーのフレームタイム.
 * @param[out] ret 取得したキー.
 * @return 平行移動キー数.
 */
void KeyFrame::getRotateKeys( float globalTime, Quaternion &ret )
{
	unsigned int numKeys = (unsigned int)rotateKeys_.size();	// キー数

	// 剰余を求める
	float fTime = (float)fmod( globalTime, static_cast<float>(rotateKeys_[numKeys-1]->frameTimer) );

	// キー値を初期化
	unsigned int iKey1 = 0;
	unsigned int iKey2 = 0;

	for( unsigned int iKey=0; iKey<numKeys; iKey++ ){
		if( (float)rotateKeys_[iKey]->frameTimer > fTime ){
			iKey2 = iKey;

			if( iKey > 0 ){
				iKey1 = iKey - 1;
			}
			else{
				iKey1 = iKey;
			}
			break;
		}
	}

	float fTime1 = (float)rotateKeys_[iKey1]->frameTimer;
	float fTime2 = (float)rotateKeys_[iKey2]->frameTimer;

	float fLerpTime = 0.0f;
	if( ( fTime2 - fTime1 ) == 0 ){
		fLerpTime = 0.0f;
	}
	else{
		fLerpTime = ( fTime - fTime1 ) / ( fTime2 - fTime1 );
	}

	// キーの補間を行う
	ret.slerp( rotateKeys_[iKey1]->value, rotateKeys_[iKey2]->value, fLerpTime );
}



/*===========================================================================*/
/**
 * @brief 平行移動キーを取得する
 * 
 * @param[in] globalTime 取得するキーのフレームタイム.
 * @param[out] ret 取得したキー.
 * @return 平行移動キー数.
 */
void KeyFrame::getPositionKeys( float globalTime, Vector3 &ret )
{
	unsigned int numKeys = (unsigned int)positionKeys_.size();	// キー数

	// 剰余を求める
	float fTime = (float)fmod( globalTime, static_cast<float>(positionKeys_[numKeys-1]->frameTimer) );

	// キー値を初期化
	unsigned int iKey1 = 0;
	unsigned int iKey2 = 0;

	for( unsigned int iKey=0; iKey<numKeys; iKey++ ){
		if( (float)positionKeys_[iKey]->frameTimer > fTime ){
			iKey2 = iKey;

			if( iKey > 0 ){
				iKey1 = iKey - 1;
			}
			else{
				iKey1 = iKey;
			}
			break;
		}
	}

	float fTime1 = (float)positionKeys_[iKey1]->frameTimer;
	float fTime2 = (float)positionKeys_[iKey2]->frameTimer;

	float fLerpTime = 0.0f;
	if( ( fTime2 - fTime1 ) == 0 ){
		fLerpTime = 0.0f;
	}
	else{
		fLerpTime = ( fTime - fTime1 ) / ( fTime2 - fTime1 );
	}

	// キーの補間を行う
	ret.lerp( positionKeys_[iKey1]->value, positionKeys_[iKey2]->value, fLerpTime );
}



/*========= EOF =============================================================*/