/*******************************************************************************/
/**
 * @file Avatar.cpp.
 * 
 * @brief アバタークラスソース.
 *
 * @date 2008/12/11.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/

#include	"Avatar.h"


/*=========================================================================*/
/**
 * @brief コンストラクタ.
 * 
 */
Avatar::Avatar(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player& player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{

}

/*=========================================================================*/
/**
 * @brief デストラクタ.
 *
 */
Avatar::~Avatar()
{

}

/*=========================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void Avatar::Initialize()
{

}

/*=========================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void Avatar::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool Avatar::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void Avatar::RenderObject()
{

}

/*=========================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void Avatar::UpdateObject(float frameTimer)
{

}


/*===== EOF ===================================================================*/
