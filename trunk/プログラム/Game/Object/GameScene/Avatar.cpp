/*******************************************************************************/
/**
 * @file Avatar.cpp.
 * 
 * @brief アバタークラス定義.
 *
 * @date 2008/12/11.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/

#include	"Object/GameScene/Avatar.h"
#include	"Object/GameScene/Player.h"


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
	switch( m_player.GetPlayerParameter().GetPlayerID())
	{
	case(0):
		m_x = m_player.GetPosition().x + 300.0f;
		m_y = m_player.GetPosition().y + 300.0f;
		break;
	case(1):
		m_x = m_player.GetPosition().x + 20.0f;
		m_y = m_player.GetPosition().y + 300.0f;
		break;
	}

	anim = 1;
	animtime = 0;
	animState = ANIMATION_STATE_STAND;
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
	SpriteDesc sd;

		sd.rect = Rect(m_x,m_y,m_x+100.0f,m_y+200.0f);
	if(m_player.GetPlayerParameter().GetPlayerID() == 0)
	{
		sd.reverse = false;
	}
	if(m_player.GetPlayerParameter().GetPlayerID() == 1)
	{
		sd.reverse = true;
	}
	
		
	animtime++;

	switch(animState)
	{
	case(ANIMATION_STATE_STAND):

		sd.textureID = TEXTUREID_STAND;
		sd.srcRect = Rect((int)(204.8f * anim),0,(int)(204.8f * anim) + 64.0f,110.0f);

			if(animtime > 6)
			{
				
				animtime = 0;
				anim ++;
				if(anim >= 5)
				{
					anim = 0;
					
				}
			}
			break;
	case(ANIMATION_STATE_ATTACK):

		sd.textureID = TEXTUREID_ATTACK;
		sd.rect = Rect(m_x,m_y,m_x+220.0f,m_y+180.0f);
		sd.srcRect = Rect((int)(204.8f * anim),0,(int)(204.8f * anim) + 128.0f,110.0f);

			if(animtime > 6)
			{
				animtime = 0;
				anim ++;
				if(anim >= 5)
				{
					anim = 0;
					animState = ANIMATION_STATE_STAND;
				}
			}
			break;
		
	case(ANIMATION_STATE_DAMAGE):

		sd.textureID = TEXTUREID_DAMAGE;
		sd.srcRect = Rect((int)(204.8f * anim),0,(int)(204.8f * anim) + 64.0f,110.0f);

			if(animtime > 6)
			{
				animtime = 0;
				anim ++;
				if(anim >= 5)
				{
					anim = 0;
					animState = ANIMATION_STATE_STAND;
				}
			}
			break;
		
	}

	m_device.GetGraphicDevice().Render( sd );
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
