/*******************************************************************************/
/**
 * @file AnmCreator.h.
 * 
 * @brief Msh anm形式アニメーションファイル読み込みクラスヘッダファイル.
 *
 * @date 2008/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MSH_ANMCREATOR_H_
#define _NGL_MSH_ANMCREATOR_H_

#include	"Ngl/IAnimation.h"
#include	"Ngl/IInputStream.h"
#include	<string>

namespace Ngl{

// アニメーション
class Animation;

// アニメーションテイク
class AnimationTake;


namespace Msh{


/**
 * @class AnmCreator．
 * @brief Msh anm形式アニメーションファイル読み込みクラス.
 */
class AnmCreator
{

public:
	
	/*=========================================================================*/
	/**
	 * @brief ファイルから作成する
	 * 
	 * @param[in] fileName ファイル名.
	 * @return 作成したアニメーションクラス.
	 */
	IAnimation* createFromFile( std::string fileName );


	/*=========================================================================*/
	/**
	 * @brief 入力ストリームから作成する
	 * 
	 * @param[in] stream 入力ストリーム.
	 * @return 作成したアニメーションクラス.
	 */
	IAnimation* createFromStream( IInputStream& stream );

private:

	/*=========================================================================*/
	/**
	 * @brief アニメーションテイクを読み込む
	 * 
	 * @param[in] stream 入力ストリーム.
	 * @param[in] animation アニメーション.
	 * @return なし.
	 */
	void loadAnimationTake( IInputStream& stream, Animation* animation );


	/*=========================================================================*/
	/**
	 * @brief キーフレームを読み込む
	 * 
	 * @param[in] stream 入力ストリーム.
	 * @param[in] animationTake アニメーションテイク.
	 * @return なし.
	 */
	void loadKeyFrame( IInputStream& stream, AnimationTake* animationTake );

};

} // namespace Msh

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/