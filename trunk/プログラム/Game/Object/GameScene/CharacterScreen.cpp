/*******************************************************************************/
/**
 * @file CharacterScreen.cpp.
 * 
 * @brief キャラクタースクリーンソース.
 *
 * @date 2008/12/11.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/

#include	"CharacterScreen.h"

/*=========================================================================*/
/**
 * @brief コンストラクタ.
 */ 
CharacterScreen::CharacterScreen(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player &player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false),
		m_avatar(device, objectManager, option, gameSceneState, player)
{

}

/*=========================================================================*/
/**
 * @brief デストラクタ.
 *
 */
CharacterScreen::~CharacterScreen()
{

}

/*=========================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void CharacterScreen::Initialize()
{
	m_avatar.Initialize();
}

/*=========================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void CharacterScreen::Terminate()
{
	m_avatar.Terminate();
	m_isTerminated = true;
}


/*=========================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool CharacterScreen::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void CharacterScreen::RenderObject()
{
	m_avatar.RenderObject();
}

/*=========================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void CharacterScreen::UpdateObject(float frameTimer)
{
	m_avatar.UpdateObject(frameTimer);
}

Avatar& CharacterScreen::GetAvatar()
{
	return m_avatar;
}


/*===== EOF ===================================================================*/
