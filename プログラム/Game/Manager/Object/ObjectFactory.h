/*******************************************************************************/
/**
 * @file ObjectFactory.h.
 * 
 * @brief �I�u�W�F�N�g�������N���X�̒�`.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _OBJECT_FACTORY_H_
#define _OBJECT_FACTORY_H_

/*===== �C���N���[�h ==========================================================*/
class ObjectManager;

class	IGameDevice;
class	Option;
class	ObjectBase;
class	GameScene;
class	GameSceneState;
class Player;
class Block;


/**
 * @brief ObjectFactory�D
 */
class ObjectFactory
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^.
	 * 
	 * @param[in] device �Q�[���f�o�C�X.
	 * @param[in] ObjectManager �I�u�W�F�N�g�}�l�[�W�����f�B�G�[�^.
	 * @param[in] option �Q�[���I�v�V����.
	 */
	ObjectFactory(IGameDevice& device, ObjectManager& objectManager, Option& option);

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 */
	~ObjectFactory();

	/*=========================================================================*/
	/**
	 * @brief �I�u�W�F�N�g�̐���.
	 * 
	 * @param[in] objectID ��������I�u�W�F�N�g��ID.
	 * @return ���������I�u�W�F�N�g�̃|�C���^.
	 */

	Player* CreatePlayer(GameSceneState& gameSceneState);
	Block* CreateBlock(GameSceneState& gameSceneState);

private:

	/** �Q�[���f�o�C�X */
	IGameDevice& m_device;
	/** �I�u�W�F�N�g�}�l�[�W�����f�B�G�[�^ */
	ObjectManager& m_objectManager;
	/** �Q�[���I�v�V���� */
	Option& m_option;
};

#endif

/*===== EOF ===================================================================*/