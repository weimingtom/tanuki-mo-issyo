/*******************************************************************************/
/*
 * @file EffectFactory.cpp.
 * 
 * @brief �Q�[���V�[���̃G�t�F�N�g�����N���X��`.
 *
 * @date 2008/12/26.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/

/*===== �C���N���[�h ==========================================================*/

#include	"Manager/Object/EffectFactory.h"

#include	"Object/GameScene/Player.h"
#include	"Manager/Object/ObjectManager.h"

#include	"Object/GameScene/Effect/BlockDeleteEffect.h"
#include	"Object/GameScene/Effect/CutinEffect.h"


/*=============================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 * @param[in] device �Q�[���f�o�C�X.
 * @param[in] ObjectManager �I�u�W�F�N�g�}�l�[�W�����f�B�G�[�^.
 * @param[in] option �Q�[���I�v�V����.
 * @param[in] State �Q�[���V�[���X�e�[�g.
 */
EffectFactory::EffectFactory(IGameDevice &device, ObjectManager &ObjectManager, Option &option) :
	m_device(device), m_objectManager(ObjectManager), m_option(option)
{

}

/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
EffectFactory::~EffectFactory()
{

}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̐���.
 * 
 * @param[in] objectID ��������I�u�W�F�N�g��ID.
 * @return ���������I�u�W�F�N�g�̃|�C���^.
 */
BlockDeleteEffect* EffectFactory::CreateBlockDeleteEffect(GameSceneState& gameSceneState,Player& player,float x, float y, int blockID)
{
	BlockDeleteEffect* object;
	object = new BlockDeleteEffect(m_device, m_objectManager, m_option, gameSceneState, player, x, y, blockID);
	return object;
}

/*=============================================================================*/
/**
 * @brief �I�u�W�F�N�g�̐���.
 * 
 * @param[in] objectID ��������I�u�W�F�N�g��ID.
 * @return ���������I�u�W�F�N�g�̃|�C���^.
 */
CutinEffect* EffectFactory::CreateCutinEffect(GameSceneState &gameSceneState, int id)
{
	CutinEffect*	object;
	object = new CutinEffect( m_device, gameSceneState , id);
	return object;
}


/*===== EOF ===================================================================*/
