#include	"StatusScreen.h"

StatusScreen::StatusScreen(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player &player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{
}

StatusScreen::~StatusScreen()
{
}

void StatusScreen::Initialize()
{

}

void StatusScreen::Terminate()
{
	m_isTerminated = true;
}

bool StatusScreen::IsTerminated()
{
	return m_isTerminated;
}

void StatusScreen::RenderObject()
{
	float m_x = 300.0f;
	float m_y = 356.0f;

	SpriteDesc sd;
	sd.textureID = TEXTUERID_POWER;

	sd.rect = Rect(m_x, m_y, m_x+256, m_y+256 );
	m_device.GetGraphicDevice().Render( sd );
}

void StatusScreen::UpdateObject(float frameTimer)
{

}


