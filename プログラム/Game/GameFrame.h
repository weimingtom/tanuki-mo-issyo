/*******************************************************************************/
/*
 * @file GameFrame.h.<br>
 * 
 * @brief �Q�[���t���[���N���X�w�b�_�t�@�C��.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _GAMEFRAME_H_
#define _GAMEFRAME_H_

#include	"IGameDevice.h"
#include	"Manager/Scene/SceneManager.h"

/**
 * @brief �Q�[���t���[���N���X�D
 */
class GameFrame
{
public:

	/**
	 * �R���X�g���N�^
	 */
	GameFrame();

	
	/**
	 * ����������<br>
	 * 
	 * @param[in] device �Q�[���f�o�C�X.
	 * @return �Ȃ�.
	 */
	void Initialize( IGameDevice& device );

	
	/**
	 * �X�V����<br>
	 * 
	 * @param[in] device �Q�[���f�o�C�X.
	 * @param[in] frameTimer �t���[����������.
	 * @return �Ȃ�.
	 */
	void Update( IGameDevice& device, float frameTimer );


	/**
	 * �`�揈��<br>
	 * 
	 * @param[in] device �Q�[���f�o�C�X.
	 * @return �Ȃ�.
	 */
	void Draw( IGameDevice& device );

	
	/**
	 * �I������<br>
	 * 
	 * @param[in] device �Q�[���f�o�C�X.
	 * @return �Ȃ�.
	 */
	void Finish( IGameDevice& device );

private:
	// !< �ϐ��̊ȈՐ���
	SceneManager* m_sceneManager;

};

#endif

/*===== EOF ==================================================================*/