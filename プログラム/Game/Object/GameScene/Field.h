/*******************************************************************************/
/**
 * @file Field.h.
 * 
 * @brief �t�@�C������.
 *
 * @date 2008/12/08.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _FIELD_H_
#define _FIELD_H_

/*===== �C���N���[�h ==========================================================*/
#include	"IGameDevice.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"
#include	"Manager/Scene/Option/Option.h"
#include	"Define/GameDefine.h"

class		Player;
class		IGameDevice;

/**
 * @brief �N���X���D
 */
class Field : public ObjectBase
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
	Field(IGameDevice& device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState, Player& player);

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 *
	 */
	~Field();

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
	 * @brief �֐�����.
	 * 
	 * @param[in] ������ ��������.
	 * @return �߂�l����.
	 */
	void GetFieldBlockMatrix(FieldMatrix* fieldMatrix);
	
	/*=========================================================================*/
	/**
	 * @brief �֐�����.
	 * 
	 * @param[in] ������ ��������.
	 * @return �߂�l����.
	 */
	void GetFieldStateMatrix(FieldMatrix* fieldMatrix);
	Vector2 GetPosition();

	void SetBlock(int x, int y, int id);

	/*=========================================================================*/
	/**
	 * @brief �֐�����.
	 * 
	 * @param[in] ������ ��������.
	 * @return �߂�l����.
	 */
	void CheckBlock( void );

	/*=========================================================================*/
	/**
	 * @brief �֐�����.
	 * 
	 * @param[in] ������ ��������.
	 * @return �߂�l����.
	 */
	void BlockCount( int x, int y, int id, int &num, CheckMatrix & checkMatrix);
	void BlockDelete( int x, int y);
	void ChangeToFallBlock();


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
	GameSceneState& m_gameSceneState;
	/** �v���[�� */
	Player& m_player;

	/** X�ʒu */
	float m_x;
	/** Y�ʒu */
	float m_y;
	/** �u���b�N�̃T�C�Y */

	int m_fieldBlock[FIELD_WIDTH][FIELD_HEIGHT];
	int m_fieldState[FIELD_WIDTH][FIELD_HEIGHT];

};

#endif

/*===== EOF ===================================================================*/