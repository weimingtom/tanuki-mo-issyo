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

	Vector2 position1;
	Vector2 position2;
	SpriteDesc re1;
	SpriteDesc re2;
	position1 = m_gameSceneState.GetPlayer(0)->GetPuzzleScreen().GetBlockManager().GetField().GetPosition();
	position2 = m_gameSceneState.GetPlayer(1)->GetPuzzleScreen().GetBlockManager().GetField().GetPosition();
	re1.rect = Rect(position1.x+40.0f,position1.y+150.0f,position1.x+240.0f,position1.y+250.0f);
	re2.rect = Rect(position2.x+40.0f,position2.y+150.0f,position2.x+240.0f,position2.y+250.0f);
	//if(m_player.GetPlayerParameter().getplayerjudge() == JUDGLE_WIN)
	//{
	//if(m_gameSceneState.GetPlayer(0)->GetPlayerParameter() 
		re1.srcRect = Rect(0,0,512.0f,117.0f);
	//} else
	//{
		re1.srcRect = Rect(0,120.0f,512.0f,256.0f);
	//}

	//if(m_gameSceneState.GetPlayer(1)->GetPlayerParameter() 
		re2.srcRect = Rect(0,0,512.0f,117.0f);
	//} else
	//{
		re2.srcRect = Rect(0,120.0f,512.0f,256.0f);
	//}

	re1.textureID = TEXTUREID_JUDGE;
	re2.textureID = TEXTUREID_JUDGE;

	m_device.GetGraphicDevice().Render( re1 );
	m_device.GetGraphicDevice().Render( re2 );

	
	

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
