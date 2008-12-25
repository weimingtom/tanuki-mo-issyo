/*******************************************************************************/
/*
 * @file Player.cpp.
 * 
 * @brief プレーヤークラス定義.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/

/*===== インクルード ==========================================================*/
#include	"Object/GameScene/Player.h"


/*=============================================================================*/
/**
 * @brief コンストラクタ.
 * 
 * @param[in] device ゲームデバイス.
 * @param[in] objectManager オブジェクトマネージャ.
 * @param[in] option ゲームオプション.
 * @param[in] gameSceneState ゲームシーンステート.
 */
Player::Player(IGameDevice& device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState, float x, float y,
			int hp, int skillPoint[], int maxPlayerTime,int playerTime,int characterID, int score, int playerID,int playerLV, int playerAttack,
			int playerDefence,int playerType,int maxHp) :
		m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_isTerminated(false), m_x(x), m_y(y),
		m_puzzleScreen(device,objectManager,option,gameSceneState, *this),
		m_characterScreen(device,objectManager,option,gameSceneState, *this),
		m_statusScreen(device,objectManager,option,gameSceneState, *this),
		m_playerParameter(hp,skillPoint,maxPlayerTime,playerTime,characterID,score,playerID,
						  playerLV,playerAttack,playerDefence, playerType,
						  TEXTUREID_BLOCK1, TEXTUREID_BLOCK2,maxHp),
		m_AI(NULL),
		m_playerAction(device,objectManager,option,gameSceneState,*this),
		m_timer(0)
		
{
	SetAI(new PlayerAI(m_device,*this));
	
}

/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
Player::~Player()
{
	if(m_AI!=NULL)
	{
		delete m_AI;
	}
}

/*=============================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void Player::Initialize()
{
	
	m_gameSceneState.AddPlayer(this);
	m_puzzleScreen.Initialize();
	m_characterScreen.Initialize();
	m_statusScreen.Initialize();
}

/*=============================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void Player::Terminate()
{

	m_puzzleScreen.Terminate();
	m_characterScreen.Terminate();
	m_statusScreen.Terminate();
	m_isTerminated = true;
}

/*=============================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool Player::IsTerminated()
{
	return m_isTerminated;

}

/*=============================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void Player::RenderObject()
{
	m_puzzleScreen.RenderObject();
	m_characterScreen.RenderObject();
	m_statusScreen.RenderObject();
}

/*=============================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void Player::UpdateObject(float frameTimer)
{

	m_puzzleScreen.UpdateObject(frameTimer);
	m_characterScreen.UpdateObject(frameTimer);
	m_statusScreen.UpdateObject(frameTimer);

	m_timer++;
	if(m_timer >= 60)
	{
		m_timer = 0;
		m_playerAction.SubTime(1);
	
	}
	if( m_playerParameter.GetPlayerTime() <= 0)
	{
		Player* target;
		if(m_playerParameter.GetPlayerID() == 0)
		{
			target = m_gameSceneState.GetPlayer(1);
		} else
		{
			target = m_gameSceneState.GetPlayer(0);
		}
		m_playerAction.Attack(target);

		m_playerParameter.SetPlayerTime( m_playerParameter.GetMaxPlayerTime() );
	}

}

/*=============================================================================*/
/**
 * @brief 位置を取得する
 * 
 * @return 位置.
 */
Vector2 Player::GetPosition()
{
	return Vector2(m_x,m_y);
}

/*=============================================================================*/
/**
 * @brief パズルスクリーンの取得.
 * 
 * @return パズルスクリーン.
 */
PuzzleScreen& Player::GetPuzzleScreen()
{
	return m_puzzleScreen;
}

StatusScreen& Player::GetStatusScreen()
{
	return m_statusScreen;
}

CharacterScreen& Player::GetCharacterScreen()
{
	return m_characterScreen;
}

AIBase& Player::GetAI()
{
	return *m_AI;
}

void Player::SetAI(AIBase* ai)
{
	m_AI = ai;
}

PlayerParameter& Player::GetPlayerParameter()
{
	return m_playerParameter;
}

PlayerAction& Player::GetPlayerAction()
{
	return m_playerAction;
}
/*===== EOF ===================================================================*/
