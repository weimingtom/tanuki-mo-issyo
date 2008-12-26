/*******************************************************************************/
/**
 * @file CharacterType.cpp.
 * 
 * @brief キャラクタタイプソース定義.
 *
 * @date 2008/12/21.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/

#include	"Object/GameScene/CharacterType.h"
#include	"Object/GameScene/Player.h"

/*=========================================================================*/
/**
 * @brief コンストラクタ.
 * 
 */
CharacterType::CharacterType(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player& player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{

}

/*=========================================================================*/
/**
 * @brief デストラクタ.
 *
 */
CharacterType::~CharacterType()
{

}

/*=========================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void CharacterType::Initialize()
{
	switch( m_player.GetPlayerParameter().GetPlayerID() )
	{
	case(0):
		m_x = m_player.GetPosition().x + 300.0f;
		m_y = m_player.GetPosition().y + 210.0f;
		break;
	case(1):
		m_x = m_player.GetPosition().x + 90.0f;
		m_y = m_player.GetPosition().y + 210.0f;
		break;
	}
}

/*=========================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void CharacterType::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool CharacterType::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void CharacterType::RenderObject()
{
	/** 属性表記 */
	SpriteDesc sd;
	sd.textureID = m_player.GetPlayerParameter().GetPlayerType();
	
	sd.rect = Rect(m_x ,m_y ,m_x+BLOCK_SIZE ,m_y+BLOCK_SIZE);
	m_device.GetGraphicDevice().Render( sd );

	TextDesc	ct1;
	ct1.code = FONT_CODE_NORMAL;
	ct1.font = "HG創英角ﾎﾟｯﾌﾟ体";
	ct1.position = Vector2(m_x-25,m_y);
	ct1.size = 25;
	ct1.string = "無";
	m_device.GetGraphicDevice().Render( ct1 );
}

/*=========================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void CharacterType::UpdateObject(float frameTimer)
{

}


/*===== EOF ===================================================================*/
