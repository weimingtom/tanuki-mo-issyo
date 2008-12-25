#include	"BackGround.h"

BackGround::BackGround(IGameDevice& device, GameSceneState& gameSceneState):
	m_device(device),m_gameSceneState(gameSceneState),m_isTerminated(false)
{
}

BackGround::~BackGround()
{
}

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