/*******************************************************************************/
/*
 * @file GameFrame.cpp.<br>
 * 
 * @brief �Q�[���t���[���N���X�\�[�X�t�@�C��.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"GameFrame.h"
#include	"Define/SceneID.h"

/**
 * �R���X�g���N�^
 */
GameFrame::GameFrame()
{
}


/**
 * ����������<br>
 * 
 * @param[in] device �Q�[���f�o�C�X.
 * @return �Ȃ�.
 */
void GameFrame::Initialize( IGameDevice& device )
{
	// �����̎���쐬
	Random::srand();

	device.GetGraphicDevice().LoadEffect( EFFECTID_COM_SPRITE, "Sprite" );

	m_sceneManager = new SceneManager(device,SCENE_ID_GAME);
	m_sceneManager->Initialize();
}


/**
 * �X�V����<br>
 * 
 * @param[in] device �Q�[���f�o�C�X.
 * @param[in] frameTimer �t���[����������.
 * @return �Ȃ�.
 */
void GameFrame::Update( IGameDevice& device, float frameTimer )
{
	// �Q�[���I���{�^����������Ă��邩
	if( device.GetInputDevice().IsInputEndKey() == true ){
		// �Q�[���I��
		device.Exit();

		return;
	}

	if(m_sceneManager->IsTerminated())
	{
		device.Exit();
		return;
	}
	m_sceneManager->UpdateScene(frameTimer);
}


/**
 * �`�揈��<br>
 * 
 * @param[in] device �Q�[���f�o�C�X.
 * @return �Ȃ�.
 */
void GameFrame::Draw( IGameDevice& device )
{
	device.GetGraphicDevice().Perspective( 50.0f, 800.0f/600.0f, 0.1f, 100.0f );
	device.GetGraphicDevice().LookAt(
		Vector3( 0.0f, 30.0f, 30.0f ),
		Vector3( 0.0f, 0.0f, 0.0f ),
		Vector3( 0.0f, 1.0f, 0.0f )
		);
	
	device.GetGraphicDevice().Clear( Color4( 0.0f, 0.0f, 0.0f, 1.0f ) );

	m_sceneManager->RenderScene();
	
}


/**
 * �I������<br>
 * 
 * @param[in] device �Q�[���f�o�C�X.
 * @return �Ȃ�.
 */
void GameFrame::Finish( IGameDevice& device )
{
	m_sceneManager->Terminate();
	delete m_sceneManager;
}

/*========= EOF =============================================================*/