/*******************************************************************************/
/*
 * @file BlockManager.cpp.
 * 
 * @brief ブロックマネージャークラス.
 *
 * @date 2008/12/04.
 *
 * @version 1.00.
 *
 * @author Tsubasa Uragami.
 */
/*******************************************************************************/

/*===== インクルード ==========================================================*/

#include	"BlockManager.h"
#include	"Player.h"

/*=============================================================================*/
/**
 * @brief コンストラクタ.
 * 
 * @param[in] device ゲームデバイス.
 * @param[in] objectManager オブジェクトマネージャ.
 * @param[in] option ゲームオプション.
 * @param[in] gameSceneState ゲームシーンステート.
 */
BlockManager::BlockManager(IGameDevice& device, ObjectManager& objectManager, Option &option, GameSceneState& gameSceneState, Player& player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false),
		m_field(device, objectManager, option, gameSceneState, player)
{
	m_block = NULL;
	//CreateBlock();
	//m_block = new Block(device, objectManager, option, gameSceneState, player,TEXTUERID_SBLOCK1,TEXTUERID_SBLOCK2 );
	//m_fallBlock = new FallBlock(device, objectManager, option, gameSceneState, player, 300.0f, 10.0f,TEXTUERID_SBLOCK3);
}

/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
BlockManager::~BlockManager()
{
	if(m_block){
		delete m_block;
	}
	for(std::vector<FallBlock*>::iterator i = m_fallBlock.begin(); i!=m_fallBlock.end();)
	{
		delete (*i);
		i = m_fallBlock.erase(i);
	}
}

/*=============================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void BlockManager::Initialize()
{
	if(m_block){
		m_block->Initialize();
	}
	for(std::vector<FallBlock*>::iterator i = m_fallBlock.begin(); i!=m_fallBlock.end();i++)
	{
		(*i)->Initialize();
	}
	m_field.Initialize();
}

/*=============================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void BlockManager::Terminate()
{
	m_isTerminated = true;
	if(m_block){
		m_block->Terminate();
	}
	for(std::vector<FallBlock*>::iterator i = m_fallBlock.begin(); i!=m_fallBlock.end();i++)
	{
		(*i)->Terminate();
	}
	m_field.Terminate();
}

/*=============================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool BlockManager::IsTerminated()
{
	return m_isTerminated;
}

/*=============================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void BlockManager::RenderObject()
{
	m_field.RenderObject();
	if(m_block){
		m_block->RenderObject();
	}
	for(std::vector<FallBlock*>::iterator i = m_fallBlock.begin(); i!=m_fallBlock.end();i++)
	{
		(*i)->RenderObject();
	}
}

/*=============================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void BlockManager::UpdateObject(float frameTimer)
{
	if(m_block){
		if(!m_block->IsTerminated())
		{
			m_block->UpdateObject(frameTimer);
		} else
		{
			delete m_block;
			m_block = NULL;
		}
	}

	for(unsigned int i=0; i< m_fallBlock.size(); i++)
	{
		std::vector<FallBlock*>::iterator j = m_fallBlock.begin() += i;

		if(!(*j)->IsTerminated())
		{
			(*j)->UpdateObject(frameTimer);
		} else
		{
			delete (*j);
			m_fallBlock.erase(j);
			i--;
		}
	}
	m_field.UpdateObject(frameTimer);
}

/*=============================================================================*/
/**
 * @brief フィールドを取得する.
 * 
 * @return フィ－ルド.
 */
Field& BlockManager::GetField()
{
	return	m_field;
}

/*=============================================================================*/
/**
 * @brief ブロックを生成する.
 * 
 * 
 */
void BlockManager::CreateBlock()
{
	int cid,mid;
	m_block = new Block(m_device, m_objectManager, m_option, m_gameSceneState, m_player,
						m_player.GetPlayerParameter().GetNextCBlock(), m_player.GetPlayerParameter().GetNextMBlock() );

	cid = Random.randi(TEXTUREID_BLOCK1,TEXTUREID_SBLOCK4);
	mid = Random.randi(TEXTUREID_BLOCK1,TEXTUREID_SBLOCK4);
	m_player.GetPlayerParameter().SetNextBlock(cid, mid);
	m_block->Initialize();
}

/*=============================================================================*/
/**
 * @brief フォールブロックをリストに追加する.
 * 
 * @param[in] fallBlock フォールブロック.
 */
void BlockManager::AddFallBlock(FallBlock *fallBlock)
{
	m_fallBlock.push_back(fallBlock);
	fallBlock->Initialize();
}

/*=============================================================================*/
/**
 * @brief 管理しているブロックを返す.
 * 
 * @return 管理しているブロック.
 */
int BlockManager::GetFallBlockNum()
{
	int t = 0;
	if(m_block)
	{
		t = 1;
	}
	return m_fallBlock.size() + t;
}

/*===== EOF ===================================================================*/