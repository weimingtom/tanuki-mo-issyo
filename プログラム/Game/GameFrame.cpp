/*******************************************************************************/
/*
 * @file GameFrame.cpp.<br>
 * 
 * @brief ゲームフレームクラスソースファイル.<br>
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
 * コンストラクタ
 */
GameFrame::GameFrame()
{
}


/**
 * 初期化処理<br>
 * 
 * @param[in] device ゲームデバイス.
 * @return なし.
 */
void GameFrame::Initialize( IGameDevice& device )
{
	// 乱数の種を作成
	Random::srand();

	device.GetGraphicDevice().LoadEffect( EFFECTID_COM_SPRITE, "Sprite" );

	m_sceneManager = new SceneManager(device,SCENE_ID_GAME);
	m_sceneManager->Initialize();
}


/**
 * 更新処理<br>
 * 
 * @param[in] device ゲームデバイス.
 * @param[in] frameTimer フレーム処理時間.
 * @return なし.
 */
void GameFrame::Update( IGameDevice& device, float frameTimer )
{
	// ゲーム終了ボタンが押されているか
	if( device.GetInputDevice().IsInputEndKey() == true ){
		// ゲーム終了
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
 * 描画処理<br>
 * 
 * @param[in] device ゲームデバイス.
 * @return なし.
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
 * 終了処理<br>
 * 
 * @param[in] device ゲームデバイス.
 * @return なし.
 */
void GameFrame::Finish( IGameDevice& device )
{
	m_sceneManager->Terminate();
	delete m_sceneManager;
}

/*========= EOF =============================================================*/