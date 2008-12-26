/*******************************************************************************/
/*
 * @file BackGround.cpp.
 * 
 * @brief 背景.
 *
 * @date 2008/12/26.
 *
 * @version 1.00.
 *
 * @author Ryoma Kawasue.
 */
/*******************************************************************************/

/*===== インクルード ==========================================================*/
#include	"BackGround.h"

/*=============================================================================*/
/**
 * @brief コンストラクタ.
 * 
 * @param[in] 引数名 引数説明.
 */
BackGround::BackGround(IGameDevice& device, GameSceneState& gameSceneState):
	m_device(device),m_gameSceneState(gameSceneState),m_isTerminated(false)
{
}

/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
BackGround::~BackGround()
{
}

/*=============================================================================*/
/**
 * @brief 関数説明.
 * 
 * @param[in] 引数名 引数説明.
 * @return 戻り値説明.
 */

void BackGround::Initialize()
{
}

void BackGround::Terminate()
{
	m_isTerminated = true;
}

bool BackGround::IsTerminated()
{
	return m_isTerminated;
}

void BackGround::RenderObject()
{
	SpriteDesc sd;
	sd.rect = Rect(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);
	sd.textureID = TEXTUREID_BACKGROUND;
	m_device.GetGraphicDevice().Render( sd );
	
}

void BackGround::UpdateObject(float frameTimer)
{
}

/*===== EOF ===================================================================*/