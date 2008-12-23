/*******************************************************************************/
/**
 * @file Skill.cpp.
 * 
 * @brief スキルクラスソース定義.
 *
 * @date 2008/12/21.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/

#include	"Object/GameScene/Skill.h"
#include	"Object/GameScene/Player.h"

/*=========================================================================*/
/**
 * @brief コンストラクタ.
 * 
 */
Skill::Skill(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player& player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{

}

/*=========================================================================*/
/**
 * @brief デストラクタ.
 *
 */
Skill::~Skill()
{

}

/*=========================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void Skill::Initialize()
{
	switch( m_player.GetPlayerParameter().GetPlayerID() )
	{
	case(0):
		m_x = m_player.GetPosition().x + 300.0f;
		m_y = m_player.GetPosition().y + 240.0f;
		break;
	case(1):
		m_x = m_player.GetPosition().x + 90.0f;
		m_y = m_player.GetPosition().y + 240.0f;
		break;
	}

}

/*=========================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void Skill::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool Skill::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void Skill::RenderObject()
{
	SpriteDesc sd;
	sd.textureID = m_player.GetPlayerParameter().GetCharacterID();
	
	sd.rect = Rect(m_x ,m_y ,m_x+BLOCK_SIZE ,m_y+BLOCK_SIZE);
	m_device.GetGraphicDevice().Render( sd );
}

/*=========================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void Skill::UpdateObject(float frameTimer)
{

}


/*===== EOF ===================================================================*/
