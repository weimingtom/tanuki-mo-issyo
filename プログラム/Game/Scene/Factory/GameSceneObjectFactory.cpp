/*******************************************************************************/
/*
 * @file GameSceneObjectFactory.cpp.
 * 
 * @brief �Q�[���V�[���̃I�u�W�F�N�g�����N���X��`.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/

/*===== �C���N���[�h ==========================================================*/
#include	"Scene/Factory/GameSceneObjectFactory.h"
#include	"Object/GameScene/Player.h"
#include	"Define/GameSceneObjectID.h"

/*=============================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 * @param[in] device �Q�[���f�o�C�X.
 * @param[in] objectManagerMediator �I�u�W�F�N�g�}�l�[�W�����f�B�G�[�^.
 * @param[in] option �Q�[���I�v�V����.
 * @param[in] gameSceneState �Q�[���V�[���X�e�[�g.
 */
GameSceneObjectFactory::GameSceneObjectFactory(IGameDevice &device, ObjectManagerMediator &objectManagerMediator, Option &option, GameSceneState &gameSceneState) :
	m_device(device), m_objectManagerMediator(objectManagerMediator), m_option(option), m_gameSceneState(gameSceneState)
{

}

/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
GameSceneObjectFactory::~GameSceneObjectFactory()
{

}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̐���.
 * 
 * @param[in] objectID ��������I�u�W�F�N�g��ID.
 * @return ���������I�u�W�F�N�g�̃|�C���^.
 */
ObjectBase* GameSceneObjectFactory::CreateObject(int objectID)
{
	ObjectBase* object = 0;
	switch(objectID)
	{
	case GAME_SCENE_OBJECT_ID_PLAYER:
		object = new Player(m_device, m_objectManagerMediator, m_option, m_gameSceneState);
	}
	return object;
}

/*===== EOF ===================================================================*/