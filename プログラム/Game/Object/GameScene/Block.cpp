#include	"Object/GameScene/Block.h"
#include	"Define/TextureID.h"
#include	"Define/EffectID.h"

Block::Block(IGameDevice &device, ObjectManagerMediator &objectManagerMediator, Option &option, GameSceneState &gameSceneState) :
	m_device(device), m_objectManagerMediator(objectManagerMediator), m_option(option), m_gameSceneState(gameSceneState), m_isTerminated(false)
{

	x = 0.0f;
	y = 0.0f;
	size = 100.0f;
	device.GetGraphicDevice().LoadTexture(TextureID::TEXTUREID_TEST,"star.dds",COLORKEYFLAG_NONE);
	device.GetGraphicDevice().LoadTexture(TextureID::TEXTUREID_TEST2,"font.dds",COLORKEYFLAG_NONE);
}

Block::~Block()
{

}

void Block::Initialize()
{

}

void Block::Terminate()
{
	m_isTerminated = true;
}

bool Block::IsTerminated()
{
	return m_isTerminated;
}

void Block::RenderObject()
{
	Matrix4 rotate;
	rotate.setTranslate(1.0f,0.5f,0.5f);
	SpriteDesc sd;
	sd.textureID = TextureID::TEXTUREID_TEST;
	sd.rect = Rect(x,y,x+size,y+size);
	m_device.GetGraphicDevice().Render( sd );
}

void Block::UpdateObject(float frameTimer)
{
	if(m_device.GetInputDevice().GetKeyDown(GAMEKEY_LEFT) == true) 
	{
		x += 1.0f;
	}
	if(m_device.GetInputDevice().GetKeyDown(GAMEKEY_RIGHT) == true) 
	{
		x -= 1.0f;
	}
	if(m_device.GetInputDevice().GetKeyDown(GAMEKEY_UP) == true) 
	{
		y -= 1.0f;
	}
	if(m_device.GetInputDevice().GetKeyDown(GAMEKEY_DOWN) == true) 
	{
		y += 1.0f;
	}
}