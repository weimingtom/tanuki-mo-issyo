/*******************************************************************************/
/**
 * @file GameSceneObjectFactory.h.
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
#ifndef _GAME_SCENE_OBJECT_FACTORY_H_
#define _GAME_SCENE_OBJECT_FACTORY_H_

/*===== �C���N���[�h ==========================================================*/
#include	"IGameDevice.h"
#include	"Manager/Object/ObjectFactoryBase.h"
#include	"Manager/Object/ObjectManagerMediator.h"
#include	"Manager/Scene/Option/Option.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"


/**
 * @brief �N���X���D
 */
class GameSceneObjectFactory : public ObjectFactoryBase
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^.
	 * 
	 * @param[in] device �Q�[���f�o�C�X.
	 * @param[in] objectManagerMediator �I�u�W�F�N�g�}�l�[�W�����f�B�G�[�^.
	 * @param[in] option �Q�[���I�v�V����.
	 * @param[in] gameSceneState �Q�[���V�[���X�e�[�g.
	 */
	GameSceneObjectFactory(IGameDevice& device, ObjectManagerMediator& objectManagerMediator, Option& option, GameSceneState& gameSceneState);
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 *
	 */
	~GameSceneObjectFactory();

	/*=========================================================================*/
	/**
	 * @brief �I�u�W�F�N�g�̐���.
	 * 
	 * @param[in] objectID ��������I�u�W�F�N�g��ID.
	 * @return ���������I�u�W�F�N�g�̃|�C���^.
	 */
	ObjectBase* CreateObject(int objectID);

private:
	
	/** �Q�[���f�o�C�X */
	IGameDevice& m_device;
	/** �I�u�W�F�N�g�}�l�[�W�����f�B�G�[�^ */
	ObjectManagerMediator& m_objectManagerMediator;
	/** �Q�[���V�[���X�e�[�g */
	GameSceneState& m_gameSceneState;
	/** �Q�[���I�v�V���� */
	Option& m_option;
};

#endif

/*===== EOF ===================================================================*/