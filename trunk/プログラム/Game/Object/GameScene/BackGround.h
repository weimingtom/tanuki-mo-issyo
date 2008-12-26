/*******************************************************************************/
/**
 * @file BackGround.h.
 * 
 * @brief �w�i.
 *
 * @date 2008/12/26.
 *
 * @version 1.00.
 *
 * 
 * @author Ryoma Kawasue.
 */
/*******************************************************************************/

#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

/*===== �C���N���[�h ==========================================================*/
#include	"IGameDevice.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"

class BackGround : public ObjectBase
{
public:
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^.
	 * 
	 * @param[in] ������ ��������.
	 */

	BackGround(IGameDevice& device, GameSceneState& gameSceneState);

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 *
	 */
	~BackGround();

	/*=========================================================================*/
	/**
	 * @brief �֐�����.
	 * 
	 * @param[in] ������ ��������.
	 * @return �߂�l����.
	 */
	void Initialize();

	void Terminate();

	bool IsTerminated();

	void RenderObject();

	void UpdateObject(float frameTimer);

private:

	/** �ϐ��̐��� */

	/** �I���t���O */
	bool m_isTerminated;
	/** �Q�[���f�o�C�X */
	IGameDevice& m_device;
	/** �Q�[���V�[���X�e�[�g */
	GameSceneState& m_gameSceneState;


};

#endif


/*===== EOF ===================================================================*/