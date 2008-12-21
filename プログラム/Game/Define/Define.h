/*******************************************************************************/
/**
 * @file Define.h.<br>
 * 
 * @brief �^��`�t�@�C��.<br>
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
  �l��`
----------*/
typedef Ngl::SoundPlayType	SoundPlayType;

static const int WINDOW_WIDTH	= 1024;	/**< �E�B���h�E��	*/
static const int WINDOW_HEIGHT	= 640;	/**< �E�B���h�E���� */
static const SoundPlayType PLAYTYPE_DEFAULT	= Ngl::SOUNDPLAYTYPE_NORMAL;
static const SoundPlayType PLAYTYPE_WAIT	= Ngl::SOUNDPLAYTYPE_WAIT;
static const SoundPlayType PLAYTYPE_LOOP	= Ngl::SOUNDPLAYTYPE_LOOP;
static const int SHADOWMAP_WIDTH	= 1024;
static const int SHADOWMAP_HEIGHT	= 1024;


/*------------
  �񋓌^��`
--------------*/

/**
 * @brief �L�[�񋓌^
 */
enum GameKey
{
	GAMEKEY_NONE,		/**<	���͂Ȃ�	*/
	GAMEKEY_UP,			/**<	��			*/
	GAMEKEY_DOWN,		/**<	��			*/
	GAMEKEY_LEFT,		/**<	��			*/
	GAMEKEY_RIGHT,		/**<	�E			*/
	GAMEKEY_LEFTUP,		/**<	����		*/
	GAMEKEY_RIGHTUP,	/**<	�E��		*/
	GAMEKEY_LEFTDOWN,	/**<	����		*/
	GAMEKEY_RIGHTDOWN,	/**<	�E��		*/
	GAMEKEY_CANCEL,		/**<	�{�^���P	*/
	GAMEKEY_CIRCLE,		/**<	�{�^���Q	*/
	GAMEKEY_TRIANGLE,	/**<	�{�^���R	*/
	GAMEKEY_QUAD,		/**<	�{�^���S	*/
	GAMEKEY_L1,			/**<	�{�^���T	*/
	GAMEKEY_L2,			/**<	�{�^���U	*/
	GAMEKEY_R1,			/**<	�{�^���V	*/
	GAMEKEY_R2,			/**<	�{�^���W	*/
	GAMEKEY_START,		/**<	�{�^���X	*/
	GAMEKEY_SELECT,		/**<	�{�^���P�O	*/

	GAMEKEY_COUNT		/**<	�L�[��		*/
};


/**
 * @brief �u�����h�֐��񋓌^.
 */
enum BlendFunc
{
	BLEND_ALPHA,	/**< �A���t�@�u�����h	*/
	BLEND_ADD		/**< ���Z�u�����h		*/
};


/**
 * @brief ���̓C�x���g�񋓌^
 */
enum InputEvent
{
	INPUTEVENT_KEYDOWN = 0,	/**< �L�[�������ꂽ			*/
	INPUTEVENT_KEYTYPE		/**< �L�[�������ė����ꂽ	*/
};


/*-----------------------
  �v���~�e�B�u�\���̒�`
-------------------------*/
typedef Ngl::Vector2	Vector2;
typedef Ngl::Vector3	Vector3;
typedef Ngl::Color4		Color4;
typedef Ngl::Matrix4	Matrix4;
typedef Ngl::Rect		Rect;


/*--------------
  �\���̌^��`
----------------*/
typedef Ngl::ViewportDesc	ViewportDesc;
typedef Ngl::TextureDesc	TextureDesc;


/*--------------
   �N���X��`
----------------*/
typedef Ngl::FileInputC	FileInput;
static Ngl::RandomSFMT Random;


#endif

/*========= End of File =====================================================*/