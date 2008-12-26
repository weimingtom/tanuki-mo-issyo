/*******************************************************************************/
/**
 * @file Result.cpp.
 * 
 * @brief ���U���g�N���X�\�[�X��`.
 *
 * @date 2008/12/18.
 *
 * @version 1.00.
 *
 * @author Jun Futagawa.
 */
/*******************************************************************************/

#include "Result.h"
#include "Object/GameScene/Player.h"

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 */
Result::Result(IGameDevice &device, GameSceneState &gameSceneState) :
	m_device(device), m_gameSceneState(gameSceneState), m_isTerminated(false)
{
}
/*=========================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
Result::~Result()
{
}

/*=========================================================================*/
/**
 * @brief ����������.
 * 
 */
void Result::Initialize()
{

}

/*=========================================================================*/
/**
 * @brief �I������.
 * 
 */
void Result::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool Result::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
 * 
 */
void Result::RenderObject()
{

/** ���������\�� */

	Vector2 position;
	SpriteDesc sd;

	sd.textureID = TEXTUREID_JUDGE;
	for(int i=0; i<2; i++)
	{
		position = m_gameSceneState.GetPlayer(i)->GetPuzzleScreen().GetBlockManager().GetField().GetPosition();
		sd.rect = Rect(position.x+40.0f,position.y+150.0f,position.x+240.0f,position.y+250.0f);
		if(m_gameSceneState.GetPlayer(i)->GetPlayerParameter().GetPlayerJudge() == PLAYER_JUDGE_LOSE)
		{
			sd.srcRect = Rect(0,0,512.0f,117.0f);
		} else
		{
			sd.srcRect = Rect(0,120.0f,512.0f,256.0f);
		}
		m_device.GetGraphicDevice().Render( sd );
	}
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void Result::UpdateObject(float frameTimer)
{
}

/*===== EOF ===================================================================*/
