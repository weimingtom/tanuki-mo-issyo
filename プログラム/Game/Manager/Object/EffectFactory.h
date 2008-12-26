/*******************************************************************************/
/**
 * @file EffectFactory.h.
 * 
 * @brief �G�t�F�N�g�������N���X�̒�`.
 *
 * @date 2008/12/27.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _EFFECT_FACTORY_H_
#define _EFFECT_FACTORY_H_

/*===== �C���N���[�h ==========================================================*/
class ObjectManager;

class	IGameDevice;
class	Option;
class	ObjectBase;
class	GameScene;
class	GameSceneState;
class	Player;

class	BlockDeleteEffect;

/**
 * @brief EffectFactory�D
 */
class EffectFactory
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
	EffectFactory(IGameDevice& device, ObjectManager& objectManager, Option& option);

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 */
	~EffectFactory();

	/*=========================================================================*/
	/**
	 * @brief �I�u�W�F�N�g�̐���.
	 * 
	 * @param[in] objectID ��������I�u�W�F�N�g��ID.
	 * @return ���������I�u�W�F�N�g�̃|�C���^.
	 */
	BlockDeleteEffect* CreateBlockDeleteEffect(GameSceneState& gameSceneState,Player& player,float x, float y, int blockID);

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
