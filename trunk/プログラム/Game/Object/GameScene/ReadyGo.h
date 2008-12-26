/*******************************************************************************/
/**
 * @file ReadyGo.h.
 * 
 * @brief ���f�B�S�[�N���X�w�b�_��`.
 *
 * @date 2008/12/26.
 *
 * @version 1.00.
 *
 * @author Ryoma Kawasue.
 */
/*******************************************************************************/
#ifndef _READYGO_H_
#define _READYGO_H_

#include	"IGameDevice.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"

class ReadyGo : public ObjectBase
{
public:
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^.
	 *
	 */
	ReadyGo(IGameDevice& device, GameSceneState& gameSceneState);

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 *
	 */
	~ReadyGo();

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
	/** �I���t���O */
	bool m_isTerminated;
	/** �Q�[���f�o�C�X */
	IGameDevice& m_device;
	/** �Q�[���V�[���X�e�[�g */
	GameSceneState& m_gameSceneState;

	float m_x;
	float m_y;

	float m_x2;
	float m_y2;

	float timer;

};

#endif