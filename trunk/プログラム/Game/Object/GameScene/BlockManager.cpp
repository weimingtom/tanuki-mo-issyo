/*******************************************************************************/
/*
 * @file BlockManager.cpp.
 * 
 * @brief �u���b�N�}�l�[�W���[�N���X.
 *
 * @date 2008/12/04.
 *
 * @version 1.00.
 *
 * @author Tsubasa Uragami.
 */
/*******************************************************************************/

/*===== �C���N���[�h ==========================================================*/

#include	"BlockManager.h"
#include	"Player.h"

/*=============================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 * @param[in] device �Q�[���f�o�C�X.
 * @param[in] objectManager �I�u�W�F�N�g�}�l�[�W��.
 * @param[in] option �Q�[���I�v�V����.
 * @param[in] gameSceneState �Q�[���V�[���X�e�[�g.
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
 * @brief �f�X�g���N�^.
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
 * @brief ����������.
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
 * @brief �I������.
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
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool BlockManager::IsTerminated()
{
	return m_isTerminated;
}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
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
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
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
 * @brief �t�B�[���h���擾����.
 * 
 * @return �t�B�|���h.
 */
Field& BlockManager::GetField()
{
	return	m_field;
}

/*=============================================================================*/
/**
 * @brief �u���b�N�𐶐�����.
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
 * @brief �t�H�[���u���b�N�����X�g�ɒǉ�����.
 * 
 * @param[in] fallBlock �t�H�[���u���b�N.
 */
void BlockManager::AddFallBlock(FallBlock *fallBlock)
{
	m_fallBlock.push_back(fallBlock);
	fallBlock->Initialize();
}

/*=============================================================================*/
/**
 * @brief �Ǘ����Ă���u���b�N��Ԃ�.
 * 
 * @return �Ǘ����Ă���u���b�N.
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