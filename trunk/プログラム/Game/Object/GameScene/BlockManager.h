#ifndef _BLOCKMANAGER_H_
#define _BLOCKMANAGER_H_

#include	"IGameDevice.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"
#include	"Manager/Scene/Option/Option.h"
#include	"Object/GameScene/Block.h"
class		IGameDevice;

class BlockManager : public ObjectBase
{
public:
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^.
	 * 
	 * @param[in] device �Q�[���f�o�C�X.
	 * @param[in] objectManager �I�u�W�F�N�g�}�l�[�W��.
	 * @param[in] option �Q�[���I�v�V����.
	 * @param[in] gameSceneState �Q�[���V�[���X�e�[�g.
	 */
	BlockManager(IGameDevice& device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState);
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 *
	 */
	~BlockManager();
	/*=========================================================================*/
	/**
	 * @brief ����������.
	 * 
	 */
	void Initialize();
	/*=========================================================================*/
	/**
	 * @brief �I������.
	 * 
	 */
	void Terminate();
	/*=========================================================================*/
	/**
	 * @brief �I�����Ă��邩�ǂ���.
	 * 
	 * @return �I���t���O.
	 */
	bool IsTerminated();
	/*=========================================================================*/
	/**
	 * @brief �I�u�W�F�N�g�̕`�揈��.
	 * 
	 */
	void RenderObject();
	/*=========================================================================*/
	/**
	 * @brief �I�u�W�F�N�g�̍X�V����.
	 * 
	 * @param[in] frameTimer �X�V�^�C�}.
	 */
	void UpdateObject(float frameTimer);

private:
	bool			m_isTerminated;
	IGameDevice&	m_device;
	ObjectManager&	m_objectManager;
	Option&			m_option;
	GameSceneState	m_gameSceneState;
};


#endif

/*===== EOF ===================================================================*/