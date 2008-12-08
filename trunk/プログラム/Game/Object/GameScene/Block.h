/*******************************************************************************/
/**
 * @file Block.h.
 * 
 * @brief �u���b�N�N���X��`.
 *
 * @date 2008/12/01.
 *
 * @version 1.00.
 *
 * @author Tsubasa Uragami.
 */
/*******************************************************************************/
#ifndef _BLOCK_H_
#define _BLOCK_H_

/*===== �C���N���[�h ==========================================================*/
#include	"IGameDevice.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"
#include	"Manager/Scene/Option/Option.h"
class		IGameDevice;


/**
 * @brief SPINBLOCK�D
 */
enum SPINBLOCK
{
	SPINBLOCK_RIGHT = 0,
	SPINBLOCK_LEFT,
};

/**
 * @brief Block�D
 */
class  Block : public ObjectBase
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
	 * @param[in] blockCID ���̃u���b�N��ID.
	 * @param[in] blockMID �T�u�̃u���b�N��ID.
	 */
	Block(IGameDevice& device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState, int blockCID, int blockMID);
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 *
	 */
	~Block();

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
	/*=========================================================================*/
	/**
	 * @brief �u���b�N�z��̏�����.
	 * 
	 */
	void InitializeMatrix();
	/*=========================================================================*/
	/**
	 * @brief �u���b�N�̉�].
	 * 
	 * @param[in] direction ��]�����萔.
	 */
	void SpinBlock(int direction);
	Vector2 GetFieldMatrixPosition();

private:

	/** �I���t���O */
	bool m_isTerminated;
	/** �Q�[���f�o�C�X */
	IGameDevice& m_device;
	/** �I�u�W�F�N�g�}�l�[�W�����f�B�G�[�^ */
	ObjectManager& m_objectManager;
	/** �Q�[���I�v�V���� */
	Option& m_option;
	/** �Q�[���V�[���X�e�[�g */
	GameSceneState m_gameSceneState;
	/** �u���b�N�̔z�� */
	int m_blockMatrix[3][3];
	/** �u���b�N��ID */
	int m_blockID[2];
	/** �X�s�[�h */
	float m_speed;

	/** X�ʒu */
	float m_x;
	/** Y�ʒu */
	float m_y;
	/** �u���b�N�̃T�C�Y */
	float m_size;

	/**	�ړI��x���W */
	float m_tx;

	/** �t���[�� */
	int frame[9][16];
};

#endif