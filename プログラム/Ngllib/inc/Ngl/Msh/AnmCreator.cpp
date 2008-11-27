/*******************************************************************************/
/**
 * @file AnmCreator.cpp.
 * 
 * @brief Msh anm形式アニメーションファイル作成クラスソースファイル.
 *
 * @date 2008/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"AnmCreator.h"
#include	"Ngl/Animation.h"
#include	"Ngl/AnimationTake.h"
#include	"Ngl/KeyFrame.h"
#include	"Ngl/FileInputC.h"
#include	"Ngl/Manipulator.h"

using namespace Ngl;
using namespace Ngl::Msh;

/*=========================================================================*/
/**
 * @brief ファイルから作成する
 * 
 * @param[in] fileName ファイル名.
 * @return 作成したアニメーションクラス.
 */
IAnimation* AnmCreator::createFromFile( std::string fileName )
{
	// スケルトンファイルをオープンする
	FileInputC ifStream;
	try{
		ifStream.open( fileName );
	}
	catch( FileOpenException& e ){
		e.add( "AnmCreator", "createFormFile" );
		e.outputConsol();
	}
	
	return createFromStream( ifStream );
}



/*=========================================================================*/
/**
 * @brief 入力ストリームから作成する
 * 
 * @param[in] stream 入力ストリーム.
 * @return 作成したアニメーションクラス.
 */
IAnimation* AnmCreator::createFromStream( IInputStream& stream )
{
	Animation* anm = 0;

	try{
		anm = new Animation;
		
		// アニメーションテイク数を読み込む
		unsigned int animationTakeCount;
		stream >> animationTakeCount;

		// アニメーションテイク情報の読み込み
		for( unsigned int i = 0; i<animationTakeCount; i++ ){
			loadAnimationTake( stream, anm );
		}
	}
	catch( Ngl::InputStreamException& e ){
		delete anm;
		anm = 0;

		e.add( "AnmCreator", "createFromStream" );
		e.outputConsol();
	}

	return anm;
}



/*=========================================================================*/
/**
 * @brief アニメーションテイクを読み込む
 * 
 * @param[in] stream 入力ストリーム.
 * @param[in] animation アニメーション.
 * @return なし.
 */
void AnmCreator::loadAnimationTake( IInputStream& stream, Animation* animation )
{
	AnimationTake* animationTake = new AnimationTake;

	try{
		// キーフレーム数の読み込み
		unsigned int numKeyframes = 0;
		stream >> numKeyframes;
	
		// キーフレーム配列を読み込む
		for( unsigned int i=0; i<numKeyframes; ++i ){
			loadKeyFrame( stream, animationTake );
		}

		// 作成したアニメーションテイクデータを追加する
		animation->addAnimationTake( animationTake );
	}
	catch( InputStreamException& e ){
		delete animationTake;

		e.add( "AnmCreator", "loadAnimationTake" );
		e.outputConsol();
	}
}



/*=========================================================================*/
/**
 * @brief キーフレームを読み込む
 * 
 * @param[in] stream 入力ストリーム.
 * @param[in] animationTake アニメーションテイク.
 * @return なし.
 */
void AnmCreator::loadKeyFrame( IInputStream& stream, AnimationTake* animationTake )
{
	KeyFrame* keyframe = new KeyFrame;

	try{
		// キーフレーム情報を読み取る
		unsigned int keyframeInfo = 0;
		stream >> hex >> keyframeInfo;

		// 拡大縮小キー数を読み取る
		unsigned int numScaleKeys = 0;
		stream >> numScaleKeys;

		// 回転キー数を読み取る
		unsigned int numRotateKeys = 0;
		stream >> numRotateKeys;

		// 平行移動キー数を読み取る
		unsigned int numPositionKeys = 0;
		stream >> numPositionKeys;

		// マトリクスキー数を読み取る
		unsigned int numMatrixKeys = 0;
		stream >> numMatrixKeys;

		// 拡大縮小キーの読み込み
		for( unsigned int i=0; i<numScaleKeys; i++ ){
			ScaleKey* key = new ScaleKey;
			stream >> key->frameTimer;
			stream >> Vector3Input( key->value );
			keyframe->addKey( key );
		}

		// 回転キーの読み込み
		for( unsigned int i=0; i<numRotateKeys; i++ ){
			RotateKey* key = new RotateKey;
			stream >> key->frameTimer;
			stream >> QuaternionInput( key->value );
			keyframe->addKey( key );
		}

		// 平行移動キーの読み込み
		for( unsigned int i=0; i<numPositionKeys; i++ ){
			PositionKey* key = new PositionKey;
			stream >> key->frameTimer;
			stream >> Vector3Input( key->value );
			keyframe->addKey( key );
		}

		// 作成したキーフレームを追加
		animationTake->addKeyFrame( keyframe );
	}
	catch( InputStreamException& e ){
		delete keyframe;

		e += "[AnmCreator] : [loadKeyFrame]";
		e.outputConsol();
	}
}

	
	
/*===== EOF ==================================================================*/