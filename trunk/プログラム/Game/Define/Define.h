/*******************************************************************************/
/**
 * @file Define.h.<br>
 * 
 * @brief 型定義ファイル.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Sigeru Jinnai, Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _DEFINE_H_
#define _DEFINE_H_

#include	"MeshID.h"
#include	"TextureID.h"
#include	"EffectID.h"
#include	"GameDefine.h"
#include	<Ngl/ViewportDesc.h>
#include	<Ngl/Vector2.h>
#include	<Ngl/Vector3.h>
#include	<Ngl/Color4.h>
#include	<Ngl/Matrix4.h>
#include	<Ngl/Rect.h>
#include	<Ngl/ISoundDevice.h>
#include	<Ngl/ITexture.h>
#include	<Ngl/FileInputC.h>
#include	<Ngl/Random/RandomSFMT.h>

/*--------
  値定義
----------*/
typedef Ngl::SoundPlayType	SoundPlayType;

static const int WINDOW_WIDTH	= 1024;	/**< ウィンドウ幅	*/
static const int WINDOW_HEIGHT	= 640;	/**< ウィンドウ高さ */
static const SoundPlayType PLAYTYPE_DEFAULT	= Ngl::SOUNDPLAYTYPE_NORMAL;
static const SoundPlayType PLAYTYPE_WAIT	= Ngl::SOUNDPLAYTYPE_WAIT;
static const SoundPlayType PLAYTYPE_LOOP	= Ngl::SOUNDPLAYTYPE_LOOP;
static const int SHADOWMAP_WIDTH	= 1024;
static const int SHADOWMAP_HEIGHT	= 1024;


/*------------
  列挙型定義
--------------*/

/**
 * @brief キー列挙型
 */
enum GameKey
{
	GAMEKEY_NONE,		/**<	入力なし	*/
	GAMEKEY_UP,			/**<	上			*/
	GAMEKEY_DOWN,		/**<	下			*/
	GAMEKEY_LEFT,		/**<	左			*/
	GAMEKEY_RIGHT,		/**<	右			*/
	GAMEKEY_LEFTUP,		/**<	左上		*/
	GAMEKEY_RIGHTUP,	/**<	右上		*/
	GAMEKEY_LEFTDOWN,	/**<	左下		*/
	GAMEKEY_RIGHTDOWN,	/**<	右下		*/
	GAMEKEY_CANCEL,		/**<	ボタン１	*/
	GAMEKEY_CIRCLE,		/**<	ボタン２	*/
	GAMEKEY_TRIANGLE,	/**<	ボタン３	*/
	GAMEKEY_QUAD,		/**<	ボタン４	*/
	GAMEKEY_L1,			/**<	ボタン５	*/
	GAMEKEY_L2,			/**<	ボタン６	*/
	GAMEKEY_R1,			/**<	ボタン７	*/
	GAMEKEY_R2,			/**<	ボタン８	*/
	GAMEKEY_START,		/**<	ボタン９	*/
	GAMEKEY_SELECT,		/**<	ボタン１０	*/

	GAMEKEY_COUNT		/**<	キー数		*/
};


/**
 * @brief ブレンド関数列挙型.
 */
enum BlendFunc
{
	BLEND_ALPHA,	/**< アルファブレンド	*/
	BLEND_ADD		/**< 加算ブレンド		*/
};


/**
 * @brief 入力イベント列挙型
 */
enum InputEvent
{
	INPUTEVENT_KEYDOWN = 0,	/**< キーが押された			*/
	INPUTEVENT_KEYTYPE		/**< キーが押して離された	*/
};


/*-----------------------
  プリミティブ構造体定義
-------------------------*/
typedef Ngl::Vector2	Vector2;
typedef Ngl::Vector3	Vector3;
typedef Ngl::Color4		Color4;
typedef Ngl::Matrix4	Matrix4;
typedef Ngl::Rect		Rect;


/*--------------
  構造体型定義
----------------*/
typedef Ngl::ViewportDesc	ViewportDesc;
typedef Ngl::TextureDesc	TextureDesc;


/*--------------
   クラス定義
----------------*/
typedef Ngl::FileInputC	FileInput;
static Ngl::RandomSFMT Random;


#endif

/*========= End of File =====================================================*/